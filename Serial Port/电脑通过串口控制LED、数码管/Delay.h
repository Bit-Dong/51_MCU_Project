#ifndef __DELAY_H__
#define __DELAY_H__

  sbit LSA=P2^2;      //74LS138 ����3�����Ŷ�����ܽ���λѡ
  sbit LSB=P2^3;
  sbit LSC=P2^4;

void Delay(unsigned int xms);

#endif
