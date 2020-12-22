#line 1 "D:/PIC Project/digital clock/source/I2C.c"
#line 1 "d:/pic project/digital clock/source/types.h"



typedef unsigned char uint8_t;
typedef signed char sint8_t;
typedef unsigned int uint16_t;
typedef signed int sint16_t;
typedef unsigned long uint32_t;
typedef unsigned long sint32_t;
#line 3 "D:/PIC Project/digital clock/source/I2C.c"
sbit Soft_I2C_Scl at RC1_bit;
sbit Soft_I2C_Sda at RC2_bit;
sbit Soft_I2C_Scl_Direction at TRISC1_bit;
sbit Soft_I2C_Sda_Direction at TRISC2_bit;

extern uint8_t sec,p_sec,mins,p_mins,hrs,p_hrs,day,date,p_date,month,p_month,year,p_year;


void write_I2C(uint8_t sa_addr,uint16_t buf_addr,uint8_t dat)
{
 Soft_I2C_Start();
 Soft_I2C_Write(sa_addr | ((buf_addr>>7)&0x0E));
 Soft_I2C_Write((uint8_t)buf_addr&0xFF);
 Soft_I2C_Write(dat);
 Soft_I2C_Stop();
 Delay_ms(10);
}
uint8_t read_I2C(uint8_t sa_addr,uint16_t buf_addr)
{
 uint8_t buf=0;
 Soft_I2C_Start();
 Soft_I2C_Write(sa_addr | ((buf_addr>>7)&0x0E));
 Soft_I2C_Write((uint8_t)buf_addr&0xFF);
 Soft_I2C_Start();
 Soft_I2C_write(sa_addr|1);
 buf=Soft_I2C_Read(0);
 Soft_I2C_Stop();
 return buf;
}


void Check_date(void)
{
 p_date=date,p_month=month,p_year=year;
 date=read_I2C(0XD0,0x04);
 delay_ms(10);
 month=read_I2C(0XD0,0x05);
 delay_ms(10);
 year=read_I2C(0XD0,0x06);
 delay_ms(10);
#line 49 "D:/PIC Project/digital clock/source/I2C.c"
}
void Check_time(void)
{

 sec=read_I2C(0xD0,0x00); delay_ms(10);
 mins=read_I2C(0xD0,0x01); delay_ms(10);
 hrs=read_I2C(0XD0,0x02); delay_ms(10);
#line 62 "D:/PIC Project/digital clock/source/I2C.c"
}