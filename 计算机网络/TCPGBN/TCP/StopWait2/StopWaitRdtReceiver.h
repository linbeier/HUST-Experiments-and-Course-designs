#ifndef STOP_WAIT_RDT_RECEIVER_H
#define STOP_WAIT_RDT_RECEIVER_H
#include "RdtReceiver.h"
#define MAXWINDOWSIZE 4
#include <vector>
class StopWaitRdtReceiver :public RdtReceiver
{
private:
	int expectSequenceNumberRcvd;	// 期待收到的下一个报文序号
	Packet lastAckPkt;				//上次发送的确认报文

public:
	StopWaitRdtReceiver();
	virtual ~StopWaitRdtReceiver();
	int base = 0, nextsequence = 0;
	Packet *windows = new Packet[MAXWINDOWSIZE];//定义一个window
	Message msg[MAXWINDOWSIZE];
	int isbasep2next = 0,have_send[MAXWINDOWSIZE];
public:
	
	void receive(Packet &packet);	//接收报文，将被NetworkService调用
};

#endif

