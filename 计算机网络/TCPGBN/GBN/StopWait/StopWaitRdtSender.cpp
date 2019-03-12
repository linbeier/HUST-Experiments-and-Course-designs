#include "stdafx.h"
#include "Global.h"
#include "StopWaitRdtSender.h"
#include <iostream>


StopWaitRdtSender::StopWaitRdtSender():expectSequenceNumberSend(0),waitingState(false)
{
}


StopWaitRdtSender::~StopWaitRdtSender()
{
	delete[]windows;
}



bool StopWaitRdtSender::getWaitingState() {
	if (nextsequnum >= base + MAXWINDOWSIZE) {
		this->waitingState = true;
	}
	else
		this->waitingState = false;
	return waitingState;
}




bool StopWaitRdtSender::send(Message &message) {
	//if (this->waitingState) { //���ͷ����ڵȴ�ȷ��״̬
	//	return false;
	//}
	if (nextsequnum >= base + MAXWINDOWSIZE) {
		return false;
	}
	else
	{
		
		this->packetWaitingAck.acknum = -1; //���Ը��ֶ�
		this->packetWaitingAck.seqnum = this->expectSequenceNumberSend;
		this->packetWaitingAck.checksum = 0;
		memcpy(this->packetWaitingAck.payload, message.data, sizeof(message.data));
		this->packetWaitingAck.checksum = pUtils->calculateCheckSum(this->packetWaitingAck);
		pUtils->printPacket("���ͷ����ͱ���", this->packetWaitingAck);
		
		if (base == nextsequnum) {
			pns->startTimer(SENDER, Configuration::TIME_OUT, 0);			//�������ͷ���ʱ��
			
		}
		pns->sendToNetworkLayer(RECEIVER, this->packetWaitingAck);//����ģ�����绷����sendToNetworkLayer��ͨ������㷢�͵��Է�
		nextsequnum = (nextsequnum + 1);
		this->windows[(nextsequnum-1)%MAXWINDOWSIZE] = packetWaitingAck;//maybe some problems
		
		this->expectSequenceNumberSend = ((this->expectSequenceNumberSend + 1) );
		
	}
	

	//this->waitingState = true;																					//����ȴ�״̬
	return true;
}

void StopWaitRdtSender::receive(Packet &ackPkt) {
	//if (this->waitingState == true) {//������ͷ����ڵȴ�ack��״̬�������´�������ʲô������
		//���У����Ƿ���ȷ
		int checkSum = pUtils->calculateCheckSum(ackPkt);

		//���У�����ȷ������ȷ�����=���ͷ��ѷ��Ͳ��ȴ�ȷ�ϵ����ݰ����
		if (checkSum == ackPkt.checksum && ackPkt.acknum >= this->windows[(base)%MAXWINDOWSIZE].seqnum) {
			
			
			
			cout << "��ʱ���ͷ��������ڵ�baseֵΪ:" << base << endl << "�������л��б���:" << endl;
			int i = base;
			while (i != nextsequnum)
			{
				pUtils->printPacket("    ", windows[i%MAXWINDOWSIZE]);
				i = (i + 1);
			}
			this->base = (ackPkt.acknum + 1);
			pUtils->printPacket("���ͷ���ȷ�յ�ȷ��", ackPkt);
			if (base == nextsequnum) { 
				pns->stopTimer(SENDER,0);		//�رն�ʱ��
			}
			else
			{
				pns->stopTimer(SENDER, 0);									//���ȹرն�ʱ��
				pns->startTimer(SENDER, Configuration::TIME_OUT, 0);			//�����������ͷ���ʱ��
			}
		}
		

		//else {
		//	pUtils->printPacket("���ͷ�û����ȷ�յ�ȷ�ϣ��ط��ϴη��͵ı���", this->packetWaitingAck);
		//	pns->stopTimer(SENDER, this->packetWaitingAck.seqnum);									//���ȹرն�ʱ��
		//	pns->startTimer(SENDER, Configuration::TIME_OUT, this->packetWaitingAck.seqnum);			//�����������ͷ���ʱ��
		//	pns->sendToNetworkLayer(RECEIVER, this->packetWaitingAck);								//���·������ݰ�

		//}
	//}	
}

void StopWaitRdtSender::timeoutHandler(int seqNum) {
	//Ψһһ����ʱ��,���迼��seqNum 
	pUtils->printPacket("���ͷ���ʱ��ʱ�䵽���ط��ϴη��͵ı���", this->packetWaitingAck);
	pns->stopTimer(SENDER,seqNum);										//���ȹرն�ʱ��
	pns->startTimer(SENDER, Configuration::TIME_OUT,seqNum);			//�����������ͷ���ʱ��
	//pns->sendToNetworkLayer(RECEIVER, this->packetWaitingAck);			//���·������ݰ�
	for (int i = (base); i < (nextsequnum) ; i++) {
		pns->sendToNetworkLayer(RECEIVER, windows[((base)%MAXWINDOWSIZE+i-base)%MAXWINDOWSIZE]);
	}
}
