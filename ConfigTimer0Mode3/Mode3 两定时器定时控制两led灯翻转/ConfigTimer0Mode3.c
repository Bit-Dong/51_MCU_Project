// Mode3��������ʱ���ֱ�ʱ���� ��led��״̬��ת

#include<reg52.h>
                      //Mode3 ֻ�����ڶ�ʱ��T0  ˫8bit��ʱ�� �ֳ���������ʱ��TL0��TH0
sbit led0=P2^0;
sbit led1=P2^1;
unsigned char T0RH,T0RL;

void ConfigTimer0Mode3(unsigned int usL,unsigned int usH)      //1<=us<=268us  ΢��
{
	unsigned long tmp;
	if(usL>267)
		usL=267;
	if(usH>267)
		usH=267;
//���õ�һ����ʱ��
	tmp=11059200/12;
	tmp=(tmp*usL)/1000000;
	tmp=256-tmp;             //��ֵ
	T0RL=tmp;
//���õڶ�����ʱ��
	tmp=11059200/12;
	tmp=(tmp*usH)/1000000;
	tmp=256-tmp;
	T0RH=tmp;
	
	TMOD &=0xf0;         //��ֹӰ�춨ʱ��T1�ĸ���λ
	TMOD |=0x03;
	TL0=T0RL;           //�趨��ʱʱ��
	TH0=T0RH;
	TR0=1;             //������һ����ʱ��
	TR1=1;              //�����ڶ�����ʱ��
}

void main()
{
	unsigned int cntL,cntH;
	ConfigTimer0Mode3(200,100);        //���趨200us��100us
	while(1)
	{
		if(TF0==1)
		{
			cntL++;
			if(cntL>=5000)               //5000*200=1000000us=1s
			{
				cntL=0;
				led0=~led0;
			}
			TF0=0;
			TL0=T0RL;
		}
		if(TF1==1)
		{
			cntH++;
			if(cntH>=5000)            //5000*100=500000us=0.5s
			{
				cntH=0;
				led1=~led1;
			}
			TF1=0;
			TH0=T0RH;
		}
	}
}
