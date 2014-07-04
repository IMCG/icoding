#include <iostream>
#include <fstream>
#include <stdio.h>
#include <pcap.h>
#include <time.h>
#include <WS2tcpip.h>

#include <tchar.h>
#include "strsafe.h"
#include <iomanip>
#pragma warning(disable:4996)
using namespace std;

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "wpcap.lib")

//ARP消息头格式
struct ARPPKT
{
	unsigned short		hdType;			//硬件类型,0001位ethernet
	unsigned short		protocolType;	//协议类型,0800表示上层协议为ip
	unsigned char		hdSize;			//硬件地址长度,值为6
	unsigned char		protocolSize;	//协议地址长度,值为4
	unsigned short		op;				//操作值, 0001/0002 分别表示arp请求/应答
	unsigned char		srcMAC[6];		//源mac地址
	unsigned char		srcIP[4];		//源ip地址
	unsigned char		dstMAC[6];		//目标mac地址
	unsigned char		dstIP[4];		//目标ip地址
};

pcap_if_t *				allDevs;
pcap_if_t *				pt;
pcap_t *				fp;
char					errMsgBuffer[PCAP_ERRBUF_SIZE];
unsigned int			netMask;
char					packetFilter[] = "arp";
bpf_program				fcode;
pcap_pkthdr *			header;
const unsigned char *	pktData;

void packetHandler(const pcap_pkthdr * hdr, const unsigned char * pkt_data, ostream & out);
//void InitAdapter();

int main(int agrc, char ** agrv)
{
	//获取网络设备列表
	if (pcap_findalldevs(&allDevs, errMsgBuffer) == -1)
	{
		cout << "未找到设备\n" << endl;

		return 0;
	}

	pt = allDevs;
	//以混杂模式打开网卡,以接受所有的帧---fp
	fp = pcap_open_live(pt->name, 1000, 1, 3 * 1000, errMsgBuffer); //打开连接,超时为1秒
	if (fp == NULL)
	{
		pcap_freealldevs(allDevs);
		cout << "打开连接失败...%s\n" << errMsgBuffer << endl;

		return 0;
	}

	//检测设备是否为以太网类型
	if (pcap_datalink(fp) != DLT_EN10MB || pt->addresses == NULL)
	{
		cout << "该设备连接类型不支持\n" << endl;
	
		return 0;
	}

	netMask = ((sockaddr_in *)(pt->addresses->netmask))->sin_addr.S_un.S_addr;


	//编译过滤程序 只获取ARP数据包
	if (pcap_compile(fp, &fcode, packetFilter, 1, netMask) < 0)
	{
		cout << "不能编译过滤包程序\n" << endl;
		pcap_freealldevs(allDevs);

		return 0;
	}

	//设置过滤包程序
	if (pcap_setfilter(fp, &fcode) < 0)
	{
		cout << "不能设置过滤包程序\n" << endl;
		pcap_freealldevs(allDevs);

		return 0;
	}

	//输出
	cout << "\t\tListening on " << pt->description << "......" << endl << endl;

	//ofstream fout(agrv[0], ios::app);
	//if ((int)fout.tellp() != 0)
		//fout << endl;

	time_t t;
	time(&t);
	//fout.seekp(0, ios::end);
	//fout << "\t\tARP request(1)/reply(2) on" << ctime(&t);
	cout << "SrcIP Addr    SrcMAC Address     DstIP Addr    DstMAC Addr     OP   Time" << endl;
	//fout << "SrcIP Addr    SrcMAC Address     DstIP Addr    DstMAC Addr     OP   Time" << endl;

	pcap_freealldevs(allDevs);

	//循环捕获ARP包，并进行解析
	int res;
	while ((res = pcap_next_ex(fp, &header, &pktData)) >= 0)
	{
		if (res == 0)//超时的话就继续
			continue;
		packetHandler(header, pktData, cout);
		//packetHandler(header, pktData, fout);
	}

	return 0;
}
void packetHandler(const pcap_pkthdr * hdr, const unsigned char * pkt_data, ostream & out)
{
	ARPPKT * arph = (ARPPKT *)(pkt_data + 14);

	//输出源ip地址
	for (int i = 0; i < 3; i++)
	{
		out << int(arph->srcIP[i]) << '.';
	}
	out.setf(ios::left);
	out << setw(3) << int(arph->srcIP[3]) << " ";
	out.unsetf(ios::left);

	//输出源mac地址 
	char oldfillchar = out.fill('0');
	out.setf(ios::uppercase);
	for (int i = 0; i < 5; i++)
		out << hex << setw(2) << int(arph->srcMAC[i]) << '-';
	out << hex << setw(2) << int(arph->srcMAC[5]) << " ";
	out.fill(oldfillchar);

	//输出目的ip地址
	out.unsetf(ios::hex | ios::uppercase);
	for (int i = 0; i < 3; i++)
		out << int(arph->dstIP[i]) << '.';
	out.setf(ios::left);
	out << setw(3) << int(arph->dstIP[3]) << " ";
	out.unsetf(ios::left);

	//输入目的mac地址
	out.fill('0');
	out.setf(ios::uppercase);
	for (int i = 0; i < 5; i++)
		out << hex << setw(2) << int(arph->dstMAC[i]) << '-';
	out << setw(2) << int(arph->dstMAC[5]) << " ";
	out.fill(oldfillchar);
	out.unsetf(ios::hex | ios::uppercase);
	out << ntohs(arph->op) << " ";

	tm * ltime;
	time_t ttemp(header->ts.tv_sec);
	ltime = localtime(&ttemp);
	out << ltime->tm_hour << ':' << setw(2) << ltime->tm_min << ':' << setw(2) << ltime->tm_sec;
	out.fill(oldfillchar);

	out << endl;

}