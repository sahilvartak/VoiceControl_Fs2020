#line 1 "D:/PIC Project/digital clock/source/matrix_driver.c"
#line 1 "d:/pic project/digital clock/source/types.h"



typedef unsigned char uint8_t;
typedef signed char sint8_t;
typedef unsigned int uint16_t;
typedef signed int sint16_t;
typedef unsigned long uint32_t;
typedef unsigned long sint32_t;
#line 34 "D:/PIC Project/digital clock/source/matrix_driver.c"
uint8_t VIDEO_MEM_1[8][6];
uint8_t bufferLong[8];


const code uint8_t font5x7[] = {
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,3,
 0x80,0x80,0x80,0x80,0x00,0x00,0x80,2,
 0xA0,0xA0,0xA0,0x00,0x00,0x00,0x00,4,
 0x50,0x50,0xF8,0x50,0xF8,0x50,0x50,6,
 0x20,0x78,0xA0,0x70,0x28,0xF0,0x20,6,
 0xC0,0xC8,0x10,0x20,0x40,0x98,0x18,6,
 0x60,0x90,0xA0,0x40,0xA8,0x90,0x68,6,
 0xC0,0x40,0x80,0x00,0x00,0x00,0x00,3,
 0x20,0x40,0x80,0x80,0x80,0x40,0x20,4,
 0x80,0x40,0x20,0x20,0x20,0x40,0x80,4,
 0x00,0x20,0xA8,0x70,0xA8,0x20,0x00,6,
 0x00,0x20,0x20,0xF8,0x20,0x20,0x00,6,
 0x00,0x00,0x00,0x00,0xC0,0x40,0x80,3,
 0x00,0x00,0x00,0xF8,0x00,0x00,0x00,6,
 0x00,0x00,0x00,0x00,0x00,0xC0,0xC0,3,
 0x00,0x08,0x10,0x20,0x40,0x80,0x00,6,
 0x70,0x88,0x98,0xA8,0xC8,0x88,0x70,6,
 0x40,0xC0,0x40,0x40,0x40,0x40,0xE0,4,
 0x70,0x88,0x08,0x10,0x20,0x40,0xF8,6,
 0xF8,0x10,0x20,0x10,0x08,0x88,0x70,6,
 0x10,0x30,0x50,0x90,0xF8,0x10,0x10,6,
 0xF8,0x80,0xF0,0x08,0x08,0x88,0x70,6,
 0x30,0x40,0x80,0xF0,0x88,0x88,0x70,6,
 0xF8,0x88,0x08,0x10,0x20,0x20,0x20,6,
 0x70,0x88,0x88,0x70,0x88,0x88,0x70,6,
 0x70,0x88,0x88,0x78,0x08,0x10,0x60,6,
 0x00,0xC0,0xC0,0x00,0xC0,0xC0,0x00,3,
 0x00,0xC0,0xC0,0x00,0xC0,0x40,0x80,3,
 0x10,0x20,0x40,0x80,0x40,0x20,0x10,5,
 0x00,0x00,0xF8,0x00,0xF8,0x00,0x00,6,
 0x80,0x40,0x20,0x10,0x20,0x40,0x80,5,
 0x70,0x88,0x08,0x10,0x20,0x00,0x20,6,
 0x70,0x88,0x08,0x68,0xA8,0xA8,0x70,6,
 0x70,0x88,0x88,0x88,0xF8,0x88,0x88,6,
 0xF0,0x88,0x88,0xF0,0x88,0x88,0xF0,6,
 0x70,0x88,0x80,0x80,0x80,0x88,0x70,6,
 0xE0,0x90,0x88,0x88,0x88,0x90,0xE0,6,
 0xF8,0x80,0x80,0xF0,0x80,0x80,0xF8,6,
 0xF8,0x80,0x80,0xF0,0x80,0x80,0x80,6,
 0x70,0x88,0x80,0xB8,0x88,0x88,0x70,6,
 0x88,0x88,0x88,0xF8,0x88,0x88,0x88,6,
 0xE0,0x40,0x40,0x40,0x40,0x40,0xE0,4,
 0x38,0x10,0x10,0x10,0x10,0x90,0x60,6,
 0x88,0x90,0xA0,0xC0,0xA0,0x90,0x88,6,
 0x80,0x80,0x80,0x80,0x80,0x80,0xF8,6,
 0x88,0xD8,0xA8,0xA8,0x88,0x88,0x88,6,
 0x88,0x88,0xC8,0xA8,0x98,0x88,0x88,6,
 0x70,0x88,0x88,0x88,0x88,0x88,0x70,6,
 0xF0,0x88,0x88,0xF0,0x80,0x80,0x80,6,
 0x70,0x88,0x88,0x88,0xA8,0x90,0x68,6,
 0xF0,0x88,0x88,0xF0,0xA0,0x90,0x88,6,
 0x78,0x80,0x80,0x70,0x08,0x08,0xF0,6,
 0xF8,0x20,0x20,0x20,0x20,0x20,0x20,6,
 0x88,0x88,0x88,0x88,0x88,0x88,0x70,6,
 0x88,0x88,0x88,0x88,0x88,0x50,0x20,6,
 0x88,0x88,0x88,0xA8,0xA8,0xA8,0x50,6,
 0x88,0x88,0x50,0x20,0x50,0x88,0x88,6,
 0x88,0x88,0x88,0x50,0x20,0x20,0x20,6,
 0xF8,0x08,0x10,0x20,0x40,0x80,0xF8,6,
 0xE0,0x80,0x80,0x80,0x80,0x80,0xE0,4,
 0x00,0x80,0x40,0x20,0x10,0x08,0x00,6,
 0xE0,0x20,0x20,0x20,0x20,0x20,0xE0,4,
 0x20,0x50,0x88,0x00,0x00,0x00,0x00,6,
 0x00,0x00,0x00,0x00,0x00,0x00,0xF8,6,
 0x80,0x40,0x20,0x00,0x00,0x00,0x00,4,
 0x00,0x00,0x70,0x08,0x78,0x88,0x78,6,
 0x80,0x80,0xB0,0xC8,0x88,0x88,0xF0,6,
 0x00,0x00,0x70,0x88,0x80,0x88,0x70,6,
 0x08,0x08,0x68,0x98,0x88,0x88,0x78,6,
 0x00,0x00,0x70,0x88,0xF8,0x80,0x70,6,
 0x30,0x48,0x40,0xE0,0x40,0x40,0x40,6,
 0x00,0x78,0x88,0x88,0x78,0x08,0x70,6,
 0x80,0x80,0xB0,0xC8,0x88,0x88,0x88,6,
 0x40,0x00,0xC0,0x40,0x40,0x40,0xE0,4,
 0x10,0x00,0x30,0x10,0x10,0x90,0x60,5,
 0x80,0x80,0x90,0xA0,0xC0,0xA0,0x90,5,
 0xC0,0x40,0x40,0x40,0x40,0x40,0xE0,4,
 0x00,0x00,0xD0,0xA8,0xA8,0x88,0x88,6,
 0x00,0x00,0xB0,0xC8,0x88,0x88,0x88,6,
 0x00,0x00,0x70,0x88,0x88,0x88,0x70,6,
 0x00,0x00,0xF0,0x88,0xF0,0x80,0x80,6,
 0x00,0x00,0x68,0x98,0x78,0x08,0x08,6,
 0x00,0x00,0xB0,0xC8,0x80,0x80,0x80,6,
 0x00,0x00,0x70,0x80,0x70,0x08,0xF0,6,
 0x40,0x40,0xE0,0x40,0x40,0x48,0x30,6,
 0x00,0x00,0x88,0x88,0x88,0x98,0x68,6,
 0x00,0x00,0x88,0x88,0x88,0x50,0x20,6,
 0x00,0x00,0x88,0xA8,0xA8,0xA8,0x50,6,
 0x00,0x00,0x88,0x50,0x20,0x50,0x88,6,
 0x00,0x00,0x88,0x88,0x78,0x08,0x70,6,
 0x00,0x00,0xF8,0x10,0x20,0x40,0xF8,6,
 0x20,0x40,0x40,0x80,0x40,0x40,0x20,4,
 0x80,0x80,0x80,0x80,0x80,0x80,0x80,2,
 0x80,0x40,0x40,0x20,0x40,0x40,0x80,4,
 0x00,0x00,0x00,0x68,0x90,0x00,0x00,6,
 0x60,0x90,0x90,0x60,0x00,0x00,0x00,5

};



void shift_out_byte(uint8_t byte_to_send)
{
 SPI1_Write(byte_to_Send);

}

void shift_out_data_to_unit(uint8_t num_of_unit, uint8_t ADDR, uint8_t DATA)
{
 uint8_t i = 0;
  RC0_bit=0; 
 if(num_of_unit <  5 )
 {
 for (i = num_of_unit; i < ( 5 ); i++)
 {
 shift_out_byte( 0x00 );
 shift_out_byte( 0x00 );
 }
 }


 shift_out_byte(ADDR);
 shift_out_byte(DATA);

 for (i=0;i<num_of_unit;i++)
 {
 shift_out_byte( 0x00 );
 shift_out_byte( 0x00 );
 }

  RC0_bit=1; 
  RC0_bit=0; 
}


void clear_videoMem_1()
{
 uint8_t seg=0,row=0;
 for (row=0;row<8;row++)
 {
 for (seg=0;seg<6;seg++)
 VIDEO_MEM_1[row][seg]=0x00;
 }
}


void loadBufferLong(uint8_t ascii)
{
 uint8_t dat=0,i=0;
 for(i=0;i<8;i++) { bufferLong[i]=0x00;}

 if (ascii>=0x20 && ascii<=0x7f)
 {
 for (i=0;i<8;i++)
 {
 dat = font5x7[((ascii-0x20)*8)+i];
 bufferLong[i] = dat;

 }
 }
}

uint8_t bit_read(uint8_t variable, uint8_t bit_num)
{
 if(variable & (1<<bit_num)) return 1;
 else return 0;
}


void set_char_5x7_on_XY(sint8_t col_offset, sint8_t row_offset, uint8_t character)
{

 uint8_t font_lenght;
 sint8_t pixel_to_start_draw = col_offset;
 sint8_t pixel_to_end_draw;
 uint8_t bit_to_read=0;

 sint8_t start_row = row_offset;
 sint8_t end_row = row_offset + 7;
 sint8_t act_row=0,row=0;
 sint8_t col_pos=0;

 loadBufferLong(character);
 font_lenght = bufferLong[7];
 pixel_to_end_draw = (col_offset-1) + font_lenght;




 for(row=start_row; row<end_row;row++)
 {
 if(row>=0&&row<9)
 {
 bit_to_read = 7;
 for(col_pos = col_offset; col_pos < 48; col_pos++)
 {
 if (col_pos<(0)){ bit_to_read--; }
 if((col_pos>-1)&&(col_pos<8))
 {
 if((col_pos > (pixel_to_start_draw - 1)) && (col_pos<pixel_to_end_draw))
 {
 if ((bit_read(bufferLong[act_row],bit_to_read)))
 VIDEO_MEM_1[row][0] |= (1<<(7 - col_pos));
 else
 VIDEO_MEM_1[row][0] &= ~(1<<(7 - col_pos));
 bit_to_read--;
 }
 }

 if((col_pos>7)&&(col_pos<16))
 {
 if((col_pos > (pixel_to_start_draw - 1)) && (col_pos<pixel_to_end_draw))
 {
 if ((bit_read(bufferLong[act_row],bit_to_read)))
 VIDEO_MEM_1[row][1] |= (1<<(7 - (col_pos-8)));


 bit_to_read--;
 }
 }

 if((col_pos>15)&&(col_pos<24))
 {
 if((col_pos > (pixel_to_start_draw - 1)) && (col_pos<pixel_to_end_draw))
 {
 if ((bit_read(bufferLong[act_row],bit_to_read)))
 VIDEO_MEM_1[row][2] |= (1<<(7 - (col_pos-16)));


 bit_to_read--;
 }
 }

 if((col_pos>23)&&(col_pos<32))
 {
 if((col_pos > (pixel_to_start_draw - 1)) && (col_pos<pixel_to_end_draw))
 {
 if ((bit_read(bufferLong[act_row],bit_to_read)))
 VIDEO_MEM_1[row][3] |= (1<<(7 - (col_pos-24)));


 bit_to_read--;
 }
 }

 if((col_pos>31)&&(col_pos<40))
 {
 if((col_pos > (pixel_to_start_draw - 1)) && (col_pos<pixel_to_end_draw))
 {
 if ((bit_read(bufferLong[act_row],bit_to_read)))
 VIDEO_MEM_1[row][4] |= (1<<(7 - (col_pos-32)));


 bit_to_read--;
 }
 }

 if((col_pos>39)&&(col_pos<48))
 {
 if((col_pos > (pixel_to_start_draw - 1)) && (col_pos<pixel_to_end_draw))
 {
 if ((bit_read(bufferLong[act_row],bit_to_read)))
 VIDEO_MEM_1[row][5] |= (1<<(7 - (col_pos-40)));


 bit_to_read--;
 }
 }
 }
 }
 act_row++;

 }

}

void print_disp_memory_1()
{
 uint8_t a=0,i=0;
  RC0_bit=0; 
 for(a=0; a<8 ; a++)
 {
 for(i=0;i<6;i++)
 {
 if(a==0)
 {
 shift_out_byte( 0x01 );
 shift_out_byte(VIDEO_MEM_1[a][5-i]);
 }
 if(a==1)
 {
 shift_out_byte( 0x02 );
 shift_out_byte(VIDEO_MEM_1[a][5-i]);
 }
 if(a==2)
 {
 shift_out_byte( 0x03 );
 shift_out_byte(VIDEO_MEM_1[a][5-i]);
 }
 if(a==3)
 {
 shift_out_byte( 0x04 );
 shift_out_byte(VIDEO_MEM_1[a][5-i]);
 }
 if(a==4)
 {
 shift_out_byte( 0x05 );
 shift_out_byte(VIDEO_MEM_1[a][5-i]);
 }
 if(a==5)
 {
 shift_out_byte( 0x06 );
 shift_out_byte(VIDEO_MEM_1[a][5-i]);
 }
 if(a==6)
 {
 shift_out_byte( 0x07 );
 shift_out_byte(VIDEO_MEM_1[a][5-i]);
 }
 if(a==7)
 {
 shift_out_byte( 0x08 );
 shift_out_byte(VIDEO_MEM_1[a][5-i]);
 }
 }


  RC0_bit=1; 
  RC0_bit=0; 
 }
}


void print_string(sint8_t clean_video_mem, sint8_t col_offset, sint8_t row_offset,uint8_t *string)
{
 sint8_t seg=0,act_char_position=0;
 uint8_t font_lenght=0;

 if(clean_video_mem==1){ clear_videoMem_1(); }
 act_char_position = col_offset;
 while(*string)
 {

 loadBufferLong(*string);
 font_lenght = bufferLong[7];
 if((act_char_position+font_lenght)>(-1))
 set_char_5x7_on_XY(act_char_position,row_offset,*string);
 if (act_char_position > 47)
 break;
 *string++;
 act_char_position = act_char_position + font_lenght;

 }

 print_disp_memory_1();
}

void set_bode_to_videoMem(uint8_t x, uint8_t y)
{
 if(x<9)
 {
 VIDEO_MEM_1[y-1][0] |= (1<<(7-(x-1)));
 }

 if((x>8) && (x<17))
 {
 VIDEO_MEM_1[y-1][1] |= (1<<(7-(x-9)));
 }

 if((x>16) && (x<25))
 {
 VIDEO_MEM_1[y-1][2] |= (1<<(7-(x-17)));
 }

 if((x>24) && (x<33))
 {
 VIDEO_MEM_1[y-1][3] |= (1<<(7-(x-25)));
 }

 if((x>32) && (x<41))
 {
 VIDEO_MEM_1[y-1][4] |= (1<<(7-(x-33)));
 }
 if((x>40) && (x<49))
 {
 VIDEO_MEM_1[y-1][5] |= (1<<(7-(x-41)));
 }
}


uint16_t check_string_lenght(uint8_t *string)
#line 440 "D:/PIC Project/digital clock/source/matrix_driver.c"
{
 uint16_t string_on_display_lenght = 0;
 while (*string)
 {
 loadBufferLong(*string);
 string_on_display_lenght = string_on_display_lenght + bufferLong[7];
 *string++;
 }

 return string_on_display_lenght;
}


void RUNNING_TEXT(sint8_t disp_points,sint16_t step_delay_time,uint8_t *text)
{
 uint8_t i,string_lenght;
 string_lenght = check_string_lenght(text);




 for (i = (disp_points + 1);i>(disp_points - string_lenght-disp_points);i--)
 {
  RB0_bit  = 1;
 print_string(1,i,0,text);

  RB0_bit  = 1;
 for(i=0;i<step_delay_time;i++)
 {
 delay_ms(10);
 }

 }

}
