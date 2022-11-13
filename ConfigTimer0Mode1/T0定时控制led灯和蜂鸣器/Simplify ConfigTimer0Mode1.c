// T0��ʱ���� led������ �� ��������������

#include<reg52.h>
#include<intrins.h>

sbit led=P2^0;
sbit beep=P1^5;

unsigned char T0RH,T0RL;

void Delay1ms()		//@11.0592MHz
{
	unsigned char i, j;

	_nop_();
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}

void Delay1000ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 8;
	j = 1;
	k = 243;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void ConfigTimer0(unsigned char ms)      //1<=ms<=71
{
	unsigned long tmp;
	tmp=11059200/12;             //����Ƶ��
	tmp=(tmp*ms)/1000;
	tmp=65536-tmp;
	T0RH=(unsigned char)(tmp>>8);
	T0RL=(unsigned char)(tmp);
	
	TMOD &=0xf0;  //���ù���ģʽ 
	TMOD |=0x01;
	TH0=T0RH;       //���ö�ʱ��ʱ��
	TL0=T0RL;      
	TR0=1;         //������ʱ��
}

void main()
{
	unsigned int cnt=0;
	ConfigTimer0(1);
	while(1)
	{
		if(TF0==1)       //����0xffff��� 
		{
			cnt++;
			TF0=0;            //�������
			TH0=T0RH;
	    TL0=T0RL;       //���¸�ֵ
			led=~led;
			if(cnt>=100)
			{
			cnt=0;
			beep=~beep; 
			//Delay1ms();     //���벻���������ʱ1ms ���������εΡ� �� �о������  led�Ӿ���һֱ��
			Delay1000ms();    //������ʱ1000ms ���������ε�" �����Ա��� ��led�� һ��һ�� 
			}
			
		}
	}
}