//����������ʾ76543210

#include<reg52.h>

typedef unsigned char u8;
typedef unsigned int u16;

sbit LSA=P2^2; //74LS138 ����λѡ ����������
sbit LSB=P2^3;
sbit LSC=P2^4;

u8 code smg[]={0x3f  , 0x06 , 0x5b , 0x4f , 0x66 , 0x6d ,0x7d , 0x07 , 0x7f  , 0x6f , 0x77 , 0x7c ,0x39 , 0x5e , 0x79 , 0x71};
//��ѡ0-F

void delay(u16 i)
{
   while(i--);
}

//�����λѡ
void choice(u8 i)
{
	switch(i)
	{
		case(0):LSA=0;LSB=0;LSC=0;break;   
		case(1):LSA=1;LSB=0;LSC=0;break;
		case(2):LSA=0;LSB=1;LSC=0;break;
		case(3):LSA=1;LSB=1;LSC=0;break;
		case(4):LSA=0;LSB=0;LSC=1;break;
		case(5):LSA=1;LSB=0;LSC=1;break;
		case(6):LSA=0;LSB=1;LSC=1;break;
		case(7):LSA=1;LSB=1;LSC=1;break;

	}
}

void main()
{
      u8 i;
	 while(1)
	{
	  	for(i=0;i<8;i++)
		{
			choice(i);
			P0=smg[i];        //���ն�ѡ����
			delay(60000);       //�ӳ� �����Ӿ�����ЧӦ
			P0=0x00;          //���� ������һ�ε����ݲ���
	  }
	}
}

