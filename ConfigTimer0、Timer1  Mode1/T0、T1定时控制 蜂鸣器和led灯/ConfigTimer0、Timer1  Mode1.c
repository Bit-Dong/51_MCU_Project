// ��ʱ��0���� ��������������
// ��ʱ��1���� led������

#include<reg52.h>
#include<intrins.h>

sbit led=P2^0;
sbit beep=P1^5;

unsigned char T0RH,T0RL;
unsigned char T1RH,T1RL;

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



void ConfigTimer0(unsigned char ms)     //1<=ms<=71
{
	unsigned long tmp;
	tmp=11059200/12;                    //����Ƶ��
	tmp=(tmp*ms)/1000;
	tmp=65536-tmp;                 //��ֵ
	
	T0RH=(unsigned char)(tmp>>8);
	T0RL=(unsigned char)(tmp);
	TMOD &=0xf0;       //��ֹӰ�춨ʱ��T1�ĸ���λ
	TMOD |=0x01;
	TH0=T0RH;              //���ö�ʱʱ��
	TL0=T0RL;  
	TR0=1;                 //������ʱ��0
}

void ConfigTimer1(unsigned char ms)
{
	unsigned long tmp;
	tmp=11059200/12;
	tmp=(tmp*ms)/1000;
	tmp=65536-tmp;
	
	T1RH=(unsigned char)(tmp>>8);
	T1RL=(unsigned char)(tmp);
	TMOD &=0x0f;
	TMOD |=0x10;
	TH1=T1RH;
	TL1=T1RL;
	TR1=1;
}

void main()
{
	unsigned int cnt;
	ConfigTimer0(2);          //�趨2ms
	ConfigTimer1(4);          //�趨4ms
	while(1)
	{                     //��ѯģʽ
		if(TF0==1)
		{
			TF0=0;               //�������
			TH0=T0RH;             //���¸�ֵ
	    TL0=T0RL;
			
			cnt=60000;
			while(cnt--)
			{
				beep=~beep;     //��������ת״̬
        Delay1ms();	    //����100msʱ ���εΡ� ��������1msʱ ����~ ~�� ������
			}
		}
		if(TF1==1)
		{
			TF1=0;
	    TH1=T1RH;
	    TL1=T1RL;	
      led=~led;            //led�Ʒ�ת״̬
		}
	}
}	
	