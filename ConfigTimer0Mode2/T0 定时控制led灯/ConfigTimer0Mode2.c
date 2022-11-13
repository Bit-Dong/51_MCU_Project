// T0 ��ʱ����led��״̬��ת

#include<reg52.h>       
                         //Mode2 �Զ���װ��  TL0 8bit
sbit led=P2^0;

void ConfigTime0Mode2(unsigned char us)     //1<=us<=268us ΢��
{
	unsigned long tmp;
	if(us>267)
		us=267;
	tmp=11059200/12;
	tmp=(tmp*us)/1000000;
	tmp=256-tmp;
	TL0=tmp;          //TL0����0xff����� TH0�Զ�����
	TH0=tmp;
	
	TMOD &=0xf0;       //��ֹ����ʱӰ�춨ʱ��T1�ĸ���λ
	TMOD |=0x02;
	TR0=1;            //������ʱ��T0
}

void main()
{
	unsigned int cnt;
	ConfigTime0Mode2(200);      //�趨200us ΢��
	while(1)
	{
		if(TF0==1)        //���
		{
			cnt++;
			if(cnt>=5000)           //5000*200=1000000us=1s  
			{
				cnt=0;
				led=~led; 
			}
			TF0=0;                   //�������
		}
	}
}
