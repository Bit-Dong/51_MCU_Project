//ʵ�ְ������� ��/��led��
//�ⲿ�ж�0 ��Ӧ��������ΪP3^2
//�ⲿ�ж�1 ��Ӧ��������ΪP3^3

#include <reg52.h>

typedef unsigned char u8;
typedef unsigned int u16; 
						   

sbit key = P3^2; //�����ⲿ�жϰ�������
sbit LED = P2^2; 

//�����ⲿ�в��ж�0
void initInterrupt0()
{
	//IE0 = 1;      //IE1��IE0Ϊ״̬λ������ʾCPU�Ե�ǰ���ж�ִ��״̬��һ�������ֶ����á�
	              //��Ҫ���õ��ǼĴ���λ��IT0����ѡ��͵�ƽ�źŴ������Ǹ������źŴ���
	EX0 = 1;
	IT0 = 1;
	EA  = 1;
}

//�ӳٺ���
void delay(u16 i)
{
	while(i--);
}

void main()
{
	while(1)
	{
		initInterrupt0();	//�����ж�
	}
}

//�����ж�ִ�к���
void interruptHandler() interrupt 0
{
	delay(1000);  //��������
	if(key==0)	//
	{
		LED = ~LED;	   //����/�ص�
	}
}
