#include "stdafx.h"
#include "Global.h"
#include "StopWaitRdtReceiver.h"


StopWaitRdtReceiver::StopWaitRdtReceiver():expectSequenceNumberRcvd(0)
{
	lastAckPkt.acknum = -1; //初始状态下，上次发送的确认包的确认序号为-1，使得当第一个接受的数据包出错时该确认报文的确认号为-1
	lastAckPkt.checksum = 0;
	lastAckPkt.seqnum = -1;	//忽略该字段
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
	//检查校验和是否正确
	int checkSum = pUtils->calculateCheckSum(packet);

	//如果校验和正确，同时收到报文的序号等于接收方期待收到的报文序号一致
  	if (checkSum == packet.checksum && this->base <= packet.seqnum) {
		pUtils->printPacket("接收方正确收到发送方的报文", packet);

		//取出Message，缓存
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
				base = nextsequence;  //base应该指向下一个要发送的报文序列，for循环向右寻找最初为0的have_send标识
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
		lastAckPkt.acknum = base; //确认序号等于收到的报文序号
		expectSequenceNumberRcvd = base ;
		lastAckPkt.checksum = pUtils->calculateCheckSum(lastAckPkt);
		pUtils->printPacket("接收方发送确认报文", lastAckPkt);
		pns->sendToNetworkLayer(SENDER, lastAckPkt);	//调用模拟网络环境的sendToNetworkLayer，通过网络层发送确认报文到对方

	}
	else {
		if (checkSum != packet.checksum) {
			pUtils->printPacket("接收方没有正确收到发送方的报文,数据校验错误", packet);
		}
		else {
			pUtils->printPacket("接收方没有正确收到发送方的报文,报文序号不对", packet);
		}
		pUtils->printPacket("接收方重新发送上次的确认报文", lastAckPkt);
		pns->sendToNetworkLayer(SENDER, lastAckPkt);	//调用模拟网络环境的sendToNetworkLayer，通过网络层发送上次的确认报文

	}
}