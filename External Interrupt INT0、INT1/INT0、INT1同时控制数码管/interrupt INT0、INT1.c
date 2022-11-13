// INT0  ���Ƶ�1λ���������ʾ����0
// INT1  ���Ƶ�3λ���������ʾ����2
// ���������Ƶ�7λ�͵�8λ���������ʾ����6��5 

# include <reg52.h>
# include <intrins.h>
# define uchar unsigned char
# define uint unsigned int
# define dig P0 

	sbit key=P3^2;    //�����ⲿ�жϸ���������
  sbit key1=P3^3;
  sbit LSA=P2^2;      //74LS138 ����3�����Ŷ�����ܽ���λѡ
  sbit LSB=P2^3;
  sbit LSC=P2^4;
 
//��������� ��ѡ0-F
uchar code table[]={0x3f  , 0x06 , 0x5b , 0x4f , 0x66 , 0x6d ,0x7d , 0x07 , 0x7f  , 0x6f , 0x77 , 0x7c ,0x39 , 0x5e , 0x79 , 0x71};
 
//��ʱ1s����
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

//��ʱ100ms����
void Delay100ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 180;
	j = 73;
	do
	{
		while (--j);
	} while (--i);
}

void init() 
{ 
  EA = 1;	      //�����ж�����λ
  EX0 = 1;	    //���ⲿ�ж�0����λ
  IT0 = 1;	    //�趨�ⲿ�ж�0Ϊ�����䴥��
  EX1 = 1;      //���ⲿ�ж�1����λ
  IT1 = 1;      //�趨�ⲿ�ж�1Ϊ�����䴥��
	PX1=1;        //�����ⲿ�ж�1 ���ȼ����� �ⲿ�ж�0
}
 
void main()
{
  init();
  while(1)
	{
		LSA=1,LSB=1,LSC=1;     //��8λ�����
		dig=table[5];         //�����������ʾ����5
		Delay100ms();    
		dig=0x00;            //����     

		LSA=0,LSB=1,LSC=1;     //��7λ�����
		dig=table[6];         //�����������ʾ����6
		Delay100ms();    
		dig=0x00;            //����   		
	}
}
 
void ex0_intr() interrupt 0 
{ 
	  Delay100ms();     //����
	  if(key==0)
		{
			LSA=0,LSB=0,LSC=0;     //��1λ�����
			dig=table[0];         //�����������ʾ����0
			Delay1000ms(); 
			dig=0x00;       //���� 
		}
}
 
void ex1_intr() interrupt 2 
{ 
	  Delay100ms();     //����
		if(key1==0)
		{
			LSA=0,LSB=1,LSC=0;  //��3λ�����
			dig=table[2];      //�����������ʾ����2
			Delay1000ms();
			dig=0x00;       //���� 
		}
}