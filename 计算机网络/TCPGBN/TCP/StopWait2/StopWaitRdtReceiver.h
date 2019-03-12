#ifndef STOP_WAIT_RDT_RECEIVER_H
#define STOP_WAIT_RDT_RECEIVER_H
#include "RdtReceiver.h"
#define MAXWINDOWSIZE 4
#include <vector>
class StopWaitRdtReceiver :public RdtReceiver
{
private:
	int expectSequenceNumberRcvd;	// �ڴ��յ�����һ���������
	Packet lastAckPkt;				//�ϴη��͵�ȷ�ϱ���

public:
	StopWaitRdtReceiver();
	virtual ~StopWaitRdtReceiver();
	int base = 0, nextsequence = 0;
	Packet *windows = new Packet[MAXWINDOWSIZE];//����һ��window
	Message msg[MAXWINDOWSIZE];
	int isbasep2next = 0,have_send[MAXWINDOWSIZE];
public:
	
	void receive(Packet &packet);	//���ձ��ģ�����NetworkService����
};

#endif

