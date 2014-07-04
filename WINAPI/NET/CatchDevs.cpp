//API函数获得机器的所有网络设备列表
#include <pcap.h>
int main()
{
	pcap_if_t *allDevs;
	pcap_if_t *d;
	int i = 0;
	char errbuf[PCAP_ERRBUF_SIZE];

	//BEGIN
	if (pcap_findalldevs(&allDevs, errbuf) == -1){
		printf("没找到设备\n");
		exit(1);
	}
	for (d = allDevs; d != NULL; d = d->next){
		printf("%d.%s", ++i, d->name);
		if (d->description)
			printf("(%s)\n", d->description);
		else
			printf("(No description available)\n");
	}
	if (i == 0){
		printf("\nNo interfaces found! Make sure WinPcap is installed.\n");
		return 0;
	}
	//释放
	pcap_freealldevs(allDevs);

	return 0;
}