#include "stdafx.h"
#include "Global.h"
#include "StopWaitRdtReceiver.h"


StopWaitRdtReceiver::StopWaitRdtReceiver():expectSequenceNumberRcvd(0)
{
	lastAckPkt.acknum = -1; //��ʼ״̬�£��ϴη��͵�ȷ�ϰ���ȷ�����Ϊ-1��ʹ�õ���һ�����ܵ����ݰ�����ʱ��ȷ�ϱ��ĵ�ȷ�Ϻ�Ϊ-1
	lastAckPkt.checksum = 0;
	lastAckPkt.seqnum = -1;	//���Ը��ֶ�
	for(int i = 0; i < Configuration::PAYLOAD_SIZE;i++){
		lastAckPkt.payload[i] = '.';
	}
	lastAckPkt.checksum = pUtils->calculateCheckSum(lastAckPkt);
	for (int i = 0; i < MAXWINDOWSIZE; i++)
	{
		have_send[i] = 0;
	}
}


StopWaitRdtReceiver::~StopWaitRdtReceiver()
{
}

void StopWaitRdtReceiver::receive(Packet &packet) {
	//���У����Ƿ���ȷ
	int checkSum = pUtils->calculateCheckSum(packet);

	//���У�����ȷ��ͬʱ�յ����ĵ���ŵ��ڽ��շ��ڴ��յ��ı������һ��
  	if (checkSum == packet.checksum && this->base <= packet.seqnum) {
		pUtils->printPacket("���շ���ȷ�յ����ͷ��ı���", packet);

		//ȡ��Message������
		memcpy(msg[(packet.seqnum)%MAXWINDOWSIZE].data, packet.payload, sizeof(packet.payload));
		if (packet.seqnum >= nextsequence)
			nextsequence = packet.seqnum;
		have_send[packet.seqnum%MAXWINDOWSIZE] = 1;
 		if (packet.seqnum == base) {
			for (int i = base ; i <= nextsequence; i++) {
				if (have_send[(base%MAXWINDOWSIZE + (i - base)) % MAXWINDOWSIZE] == 1) {
					pns->delivertoAppLayer(RECEIVER, msg[(base%MAXWINDOWSIZE+(i-base))%MAXWINDOWSIZE]);
					have_send[(base%MAXWINDOWSIZE + (i - base)) % MAXWINDOWSIZE] = 0;
				}
				else {
					nextsequence = i;
					isbasep2next = 1;
					break;
				}
					
			}
			if (isbasep2next == 1) {
				base = nextsequence;
				isbasep2next = 0;
			}
			else
			{
				base = nextsequence;  //baseӦ��ָ����һ��Ҫ���͵ı������У�forѭ������Ѱ�����Ϊ0��have_send��ʶ
				base++;
			}
			
		}
		/*
		

		if (packet.seqnum == base) {
			if(isfull==0)
				pns->delivertoAppLayer(RECEIVER, msg[base%MAXWINDOWSIZE]);
			if (isfull==1) 
			{
				for (int i = base%MAXWINDOWSIZE; i < nextsequence%MAXWINDOWSIZE; i++) {
					pns->delivertoAppLayer(RECEIVER, msg[i]);
				}
				base = nextsequence;
				isfull = 0;
			}
			base++;
		}
		else if (packet.seqnum != base) {
			//pns->delivertoAppLayer(RECEIVER, msg[(packet.seqnum)%MAXWINDOWSIZE]);
			isfull = 1;

		}
		*/
		lastAckPkt.acknum = base; //ȷ����ŵ����յ��ı������
		expectSequenceNumberRcvd = base ;
		lastAckPkt.checksum = pUtils->calculateCheckSum(lastAckPkt);
		pUtils->printPacket("���շ�����ȷ�ϱ���", lastAckPkt);
		pns->sendToNetworkLayer(SENDER, lastAckPkt);	//����ģ�����绷����sendToNetworkLayer��ͨ������㷢��ȷ�ϱ��ĵ��Է�

	}
	else {
		if (checkSum != packet.checksum) {
			pUtils->printPacket("���շ�û����ȷ�յ����ͷ��ı���,����У�����", packet);
		}
		else {
			pUtils->printPacket("���շ�û����ȷ�յ����ͷ��ı���,������Ų���", packet);
		}
		pUtils->printPacket("���շ����·����ϴε�ȷ�ϱ���", lastAckPkt);
		pns->sendToNetworkLayer(SENDER, lastAckPkt);	//����ģ�����绷����sendToNetworkLayer��ͨ������㷢���ϴε�ȷ�ϱ���

	}
}