//T0�жϿ���led�ƶ�ʱ��ת
 
#include <reg52.h>		 
 
typedef unsigned int u16;	  
typedef unsigned char u8;
unsigned char T0RH,T0RL;
sbit led=P2^0;	 

void Timer0Init(u8 ms)
{
	unsigned long tmp;
	tmp=11059200/12;
	tmp=(tmp*ms)/1000;
	tmp=65536-tmp;                 //��ֵ
	T0RH=(unsigned char)(tmp>>8);
	T0RL=(unsigned char)(tmp);
	
	TMOD &=0xf0;       //��ֹӰ�춨ʱ��T1�ĸ���λ
	TMOD |=0x01;
	TH0=T0RH;           //���ö�ʱʱ��
	TL0=T0RL;                   
 
	ET0=1;       //��T0�ж�����λ
	EA=1;        //�����ж�����λ����
	TR0=1;       //������ʱ��0
}
 
void main()
{	
	Timer0Init(1);  
	while(1);		
}

void Timer0() interrupt 1
{
	static u16 i;
	TH0=T0RH;           //���¸�ֵ��ʱʱ��
	TL0=T0RL;  
	i++;
	if(i==100)
	{
		i=0;
		led=~led;	
	}	
}