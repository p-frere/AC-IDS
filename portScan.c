/*
    Packet sniffer using libpcap library
    Taught from Silver Moon's 'C Packet Sniffer Code with libpcap and linux sockets' blog post
    on BinaryTides 2018-08-28

    P FRERE
*/
#include "portScan.h"
 
void process_packet(u_char *, const struct pcap_pkthdr *, const u_char *);
void process_ip_packet(const u_char * , int);
void print_ip_packet(const u_char * , int);
void print_tcp_packet(const u_char *  , int );
void print_udp_packet(const u_char * , int);
void print_icmp_packet(const u_char * , int );
void PrintData (const u_char * , int);


struct sockaddr_in source,dest;
int tcp=0,udp=0,icmp=0,others=0,igmp=0,total=0,i,j;
 
int portScan()
{
    //declares item in list of interfaces, has stuff like name and description
    pcap_if_t *alldevsp , *device;
    //Handle(ptr to a structure) of the device that shall be sniffed
    pcap_t *handle;

    //find devices
    printf("Looking for Devices:\n");
    char errbuf[100] , *devname , devs[100][100];
    int count = 1 , n;

    if( pcap_findalldevs( &alldevsp , errbuf) )
    {
        printf("Error finding devices : %s" , errbuf);
        exit(1);
    }
    //display devices
    for(device = alldevsp ; device != NULL ; device = device->next)
    {
        printf("%d. %s - %s\n" , count , device->name , device->description);
        if(device->name != NULL)
        {
            strcpy(devs[count] , device->name);
        }
        count++;
    }
    //User selecting device
    printf("which device do you want to sniff? \nenter the number : ");
    scanf("%d" , &n);
    devname = devs[n];
     
    //Open the device for sniffing
    printf("Opening device %s for sniffing ... " , devname);
    handle = pcap_open_live(devname , 65536 , 1 , 0 , errbuf);
     
    if (handle == NULL) 
    {
        fprintf(stderr, "Couldn't open device %s : %s\n" , devname , errbuf);
        exit(1);
    }
    printf("Done\n");

    //Begin stiffing
    pcap_loop(handle , -1 , process_packet , NULL); //process_packet returns the adress of the function
     
    return 0;   
}

//Called every time a packet is sniffed and passed the packets data
void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer)
{
    int size = header->len;
     
    //Get the IP Header part of this packet , excluding the ethernet header
    struct iphdr *iph = (struct iphdr*)(buffer + sizeof(struct ethhdr));
    ++total;
    print_ethernet_header(buffer , size);
    switch (iph->protocol) //Check the Protocol and do accordingly...
    {
        case 1:  //ICMP
            ++icmp;
            print_icmp_packet( buffer , size);
            break;
         
        case 2:  //IGMP
            ++igmp;
            print_igmp_packet(buffer, size);
            break;
         
        case 6:  //TCP
            ++tcp;
            print_tcp_packet(buffer , size);
            break;
         
        case 17: //UDP
            ++udp;
            print_udp_packet(buffer , size);
            break;
         
        default: //Others
            ++others;
            break;
    }
}

void print_ethernet_header(const u_char *Buffer, int Size)
{
    struct ethhdr *eth = (struct ethhdr *)Buffer;

    printf("%sSrc: %.2X-%.2X-%.2X-%.2X-%.2X-%.2X  Des: %.2X-%.2X-%.2X-%.2X-%.2X-%.2X Protocol: %x \n", KWHT,
           eth->h_source[0] , eth->h_source[1] , eth->h_source[2] , eth->h_source[3] , eth->h_source[4] , eth->h_source[5],
           eth->h_dest[0] , eth->h_dest[1] , eth->h_dest[2] , eth->h_dest[3] , eth->h_dest[4] , eth->h_dest[5],
           (unsigned short)eth->h_proto);

}


void print_ip_header(const u_char * Buffer, int Size, char* colour)
{

    unsigned short iphdrlen;
    struct iphdr *iph = (struct iphdr *)(Buffer  + sizeof(struct ethhdr) );
    iphdrlen =iph->ihl*4;
     
    memset(&source, 0, sizeof(source));
    source.sin_addr.s_addr = iph->saddr;
     
    memset(&dest, 0, sizeof(dest));
    dest.sin_addr.s_addr = iph->daddr;

    printf("%sIP Version: %d    Src: %s    Des: %s    Protocol %d\n", colour,
           (unsigned int)iph->version,
           inet_ntoa(source.sin_addr),
           inet_ntoa(dest.sin_addr),
           (unsigned int)iph->protocol);
}
 
void print_tcp_packet(const u_char * Buffer, int Size)
{
    unsigned short iphdrlen;
    struct iphdr *iph = (struct iphdr *)( Buffer  + sizeof(struct ethhdr) );
    iphdrlen = iph->ihl*4;
    struct tcphdr *tcph=(struct tcphdr*)(Buffer + iphdrlen + sizeof(struct ethhdr));
    int header_size =  sizeof(struct ethhdr) + iphdrlen + tcph->doff*4;
         
    print_ip_header(Buffer,Size, KRED);
}
 
void print_udp_packet(const u_char *Buffer , int Size)
{
     
    unsigned short iphdrlen;
     
    struct iphdr *iph = (struct iphdr *)(Buffer +  sizeof(struct ethhdr));
    iphdrlen = iph->ihl*4;
    struct udphdr *udph = (struct udphdr*)(Buffer + iphdrlen  + sizeof(struct ethhdr));
     
    int header_size =  sizeof(struct ethhdr) + iphdrlen + sizeof udph;
     
    print_ip_header(Buffer,Size, KGRN);

}
 
void print_icmp_packet(const u_char * Buffer , int Size)
{

    unsigned short iphdrlen;
    struct iphdr *iph = (struct iphdr *)(Buffer  + sizeof(struct ethhdr));
    //In the header there is the IHL (Internet Header Length) field which is 4 bits long and specifies the header length in 32 bit words
    iphdrlen = iph->ihl * 4;

    struct icmphdr *icmph = (struct icmphdr *)(Buffer + iphdrlen  + sizeof(struct ethhdr));
    int header_size =  sizeof(struct ethhdr) + iphdrlen + sizeof icmph;

    print_ip_header(Buffer , Size, KYEL);

}


void print_igmp_packet(const u_char * Buffer , int Size)
{

    unsigned short iphdrlen;
    struct iphdr *iph = (struct iphdr *)(Buffer  + sizeof(struct ethhdr));
    //In the header there is the IHL (Internet Header Length) field which is 4 bits long and specifies the header length in 32 bit words
    iphdrlen = iph->ihl * 4;

    print_ip_header(Buffer , Size, KCYN);

}
