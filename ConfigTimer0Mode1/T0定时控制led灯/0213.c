#include<reg52.h>
sbit led0=P2^0;
void main()
{
	unsigned int cnt=0;
	TMOD &=0xf0;
	TMOD |=0x01;  //�������⹦�ܼĴ���TMOD�����úù���ģʽ
	TH0=0xfc;    //���ö�ʱʱ��
	TL0=0x6e;
	TR0=1;        //�����򿪶�ʱ��
	
	while(1)
	{
		if(TF0==1)
		{
			TF0=0;      //�������
			TH0=0xfc;   //���¸�ֵ
	    TL0=0x6e;
			cnt++;
			if(cnt>=500)
			{
				cnt=0;
				led0=~led0;
			}
		}
	}
}