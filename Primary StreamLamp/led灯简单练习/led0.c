#include<reg52.h>
#include"led0.h"
#include"delay.h"

//led����
void chuanlian()
{

  led=0x7e;
	delay(500);
	led=0x3c;
	delay(500);
	led=0x18;
	delay(500);
	led=0x00;
	delay(500);
	
	led=0x00;
	delay(500);
	led=0x18;
	delay(500);
	led=0x3c;
	delay(500);
	led=0x7e;
	delay(500);
}

//�ĸ�����˸
void shanshuo()
{
		
	led=0xaa;
	delay(500);
	led=0xff;
	delay(500);

}

//1357����
void danhshudengliang()
{
		
	led=0xaa;
	 
}

//��ˮ��
void liushuideng()
{
	int i;
	led=0xfe;
	for(i=0;i<7;i++)
	{
		delay(1000);
		led=(led<<1)|(led>>7);
	}
	for(i=0;i<8;i++)
	{
		delay(1000);
		led=(led>>1)|(led<<7);
	}
	led=0xff;
	delay(2000);

}

//��������key2��key3ʵ������ת���
void zhuanxiang()
{
	int i,j;
	    led=0xff;
			if(key2==0)
			{
					led1=1;
					led2=1;
				  for(j=0;j<20;j++)
				{	
					delay(10);
					led1=~led1;
					led2=~led2;
					delay(100);
				}
			}
				if(key3==0)
			{
					led7=1;
					led8=1;
				 for(j=0;j<20;j++)
				{	
					delay(10);
					led7=~led7;
					led8=~led8;
					delay(100);
				}
			}
}

//�����Ƽӷ�
void jiafa()
{
	 unsigned int i;
   unsigned char N=0;
	 for(i=0;i<100;i++ )
	{
		N++;
		led=~N;
		delay(300);
	}		 
}