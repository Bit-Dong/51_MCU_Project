//������INT0�������������°��������ⲿ�ж�
//ÿ����һ���ⲿ�жϼ�����1������������ʾ��������� 
// 100��һ��ѭ�� 100ʱ����


#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int
#define dig P0
	sbit key=P3^2;    //�����ⲿ�ж�0 ����������
  sbit LSA=P2^2;      //74LS138 ����3�����Ŷ�����ܽ���λѡ
  sbit LSB=P2^3;
  sbit LSC=P2^4;
 
//��������� ��ѡ0-F
uchar code smg[]={0x3f  , 0x06 , 0x5b , 0x4f , 0x66 , 0x6d ,0x7d , 0x07 , 0x7f  , 0x6f , 0x77 , 0x7c ,0x39 , 0x5e , 0x79 , 0x71};

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


//��ʼ���ⲿ�ж�0
void initEx0()
{
  EA  = 1;	 //�����жϿ���
  EX0 = 1;	 //�ⲿ�ж�0����λ
  IT0 = 1;	 //�ⲿ�ж�0�����䴥��
}
 
 
uchar  count1=0,count = 0;    //��������
 
void main()
{
	
  initEx0();
  while(1)
		{
			if(count<10)
			{
				if((count1!=0)&&(count1!=10))
				{
					LSA=1,LSB=1,LSC=0;
					dig=smg[count];        //�����������ʾ�жϴ���
					Delay1ms(); dig=0x00;
					
					LSA=0,LSB=0,LSC=1;
					dig=smg[count1];       //�����������ʾ�жϴ���
					Delay1ms(); dig=0x00;
				}
				else
				{					
					LSA=1,LSB=1,LSC=0;
					dig=smg[count];   //�����������ʾ�жϴ���
					Delay1ms(); dig=0x00;
				}
			}
			if((count>9)&&(count<100))
			{
				count1=count1+count/10;
				count  %=10;
				LSA=1,LSB=1,LSC=0;
        dig=smg[count];        //�����������ʾ�жϴ���
				Delay1ms(); dig=0x00;
				
				LSA=0,LSB=0,LSC=1;
        dig=smg[count1];       //�����������ʾ�жϴ���
				Delay1ms(); dig=0x00;
			}
		}
}
 
	 void ex0_intr() interrupt 0 
	{ 
		Delay1ms();   //����
		if(key==0)
		{
			count=count+1;   //ÿ����һ���ж� ����+1
	  }
		if((count1==10)|(count==100))
		{
			count1=0;
			count=0;
		}
	}