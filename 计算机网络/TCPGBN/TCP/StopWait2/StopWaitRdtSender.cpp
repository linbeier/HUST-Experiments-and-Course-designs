#include "stdafx.h"
#include "Global.h"
#include "StopWaitRdtSender.h"


StopWaitRdtSender::StopWaitRdtSender():expectSequenceNumberSend(0),waitingState(false)
{
	for (int i = 0; i < MAXWINDOWSIZE; i++)
	{
		dupACK[i] = 0;
	}
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
			pns->startTimer(SENDER, Configuration::TIME_OUT, base);			//�������ͷ���ʱ��
			
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
		if (checkSum == ackPkt.checksum ) {
			//this->expectSequenceNumberSend = ((this->expectSequenceNumberSend + 1) % MAXWINDOWSIZE);			//��һ�����������0-1֮���л�
			
			
			if (base ==ackPkt.acknum) { 
				dack++;
				if (dack == 3)
				{
					pUtils->printPacket("���ͷ������ش����ط��ϴη��͵ı���", this->packetWaitingAck);
					pns->sendToNetworkLayer(RECEIVER, windows[(base) % MAXWINDOWSIZE]);
					//dupACK[i] = 0;

					pns->stopTimer(SENDER, base);
					//base = ackPkt.acknum;//���ȹرն�ʱ��
					pns->startTimer(SENDER, Configuration::TIME_OUT, base+1);			//�����������ͷ���ʱ��
					dack = 0;
					return;
				}
				
				//pns->stopTimer(SENDER,base);
				//base = ackPkt.acknum;//�رն�ʱ��
			}
			else
			{
				dack = 0;
				
			}
			if (base == nextsequnum)
			{
				pUtils->printPacket("���ͷ���ȷ�յ�ȷ��", ackPkt);
				pns->stopTimer(SENDER, base);
			}
			else
			{
				base = ackPkt.acknum ;
				pns->stopTimer(SENDER, base);
				pns->startTimer(SENDER, Configuration::TIME_OUT, base+1);			//�����������ͷ���ʱ��
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
	
	pns->sendToNetworkLayer(RECEIVER, windows[(base)%MAXWINDOWSIZE]);
	
}
