// T1 ��ʱ���� �����������ʾ0-F
 
#include<reg52.h>		 
#define dig P0
typedef unsigned int u16;	  
typedef unsigned char u8;
unsigned char T1RH,T1RL;

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;
 
u8 code smgduan[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
					0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};//??0~F??
u8 n=0;

void Timer1Init(u8 ms)  
{
	unsigned long tmp;
	tmp=11059200/12;
	tmp=(tmp*ms)/1000;
	tmp=65536-tmp;                 //��ֵ
	T1RH=(unsigned char)(tmp>>8);
	T1RL=(unsigned char)(tmp);
	
	TMOD &=0x0f;       //��ֹӰ�춨ʱ��T0�ĵ���λ
	TMOD |=0x10;
	TH1=T1RH;           //���ö�ʱʱ��
	TL1=T1RL;                   
 
	ET1=1;       //��T1�ж�����λ
	EA=1;        //�����ж�����λ����
	TR1=1;       //������ʱ��1
}
 

void main()
{	
	Timer1Init(1);
	while(1);		
}
 

void Timer1() interrupt 3
{
	static u16 i;
	TH1=T1RH;           //���¸�ֵ��ʱʱ��
	TL1=T1RL; 
	i++;
	if(i==1000)        //1ms x 1000 =1s
	{
		i=0;
		LSA=0;LSB=0;LSC=0;
		dig=smgduan[n++];
		if(n==16)n=0;	
	}	
}