// Lcd module connections 
sbit LCD_RS at P2_0_bit; 
sbit LCD_EN at P2_1_bit; 
sbit LCD_D4 at P2_2_bit; 
sbit LCD_D5 at P2_3_bit; 
sbit LCD_D6 at P2_4_bit; 
sbit LCD_D7 at P2_5_bit; 
//Setting of input to determine which lift is operating 
sbit OpA at P0_1_bit; 
sbit OpB at P0_2_bit; 
//End Lcd module connections 
//global variable 
  char Aselect = 0x31, BSelect = 0x38; 
  char ACurrent=0x31, BCurrent=0x38; 
//Button check sequence (runs about every 5ms) 
void button_check(void) org 0x001B 
{ 
       //floor call A 
   if(OpA==0){ 
        if(P1==0x7F){P1 = 0x7F;ACurrent = 0x31;P0.B1=1;}//Floor1 
        if(P1==0xBF){P1 = 0xBF;ACurrent = 0x32;P0.B1=1;}//Floor2 
        if(P1==0xDF){P1 = 0xDF;ACurrent = 0x33;P0.B1=1;}//Floor3 
        if(P1==0xEF){P1 = 0xEF;ACurrent = 0x34;P0.B1=1;}//Floor4 
        if(P1==0xF7){P1 = 0xF7;ACurrent = 0x35;P0.B1=1;}//Floor5 
        if(P1==0xFB){P1 = 0xFB;ACurrent = 0x36;P0.B1=1;}//Floor6 
        if(P1==0xFD){P1 = 0xFD;ACurrent = 0x37;P0.B1=1;}//Floor7 
        if(P1==0xFE){P1 = 0xFE;ACurrent = 0x38;P0.B1=1;}//Floor8 
       } 
       //floor call B 
   if(OpB==0){ 
        if(P3==0x7F){P3 = 0x7F;BCurrent = 0x31;P0.B2=1;}//Floor1 
        if(P3==0xBF){P3 = 0xBF;BCurrent = 0x32;P0.B2=1;}//Floor2 
        if(P3==0xDF){P3 = 0xDF;BCurrent = 0x33;P0.B2=1;}//Floor3 
        if(P3==0xEF){P3 = 0xEF;BCurrent = 0x34;P0.B2=1;}//Floor4 
        if(P3==0xF7){P3 = 0xF7;BCurrent = 0x35;P0.B2=1;}//Floor5 
        if(P3==0xFB){P3 = 0xFB;BCurrent = 0x36;P0.B2=1;}//Floor6 
        if(P3==0xFD){P3 = 0xFD;BCurrent = 0x37;P0.B2=1;}//Floor7 
        if(P3==0xFE){P3 = 0xFE;BCurrent = 0x38;P0.B2=1;}//Floor8 
       } 
 
   TR1_bit = 0;//timer reset 
   TF1_bit = 0; 
   TH1 = 0xEF; 
   TL1 = 0xB9; 
   TR1_bit = 1;//timer rerun 
} 
void main() { 
     //LCD setup 
     Lcd_Init(); 
     Lcd_Cmd(_LCD_CLEAR); 
     Lcd_Cmd(_LCD_CURSOR_OFF); 
     LCD_Out( 1, 2,"Lift A"); 
     LCD_Out( 1, 10,"Lift B"); 
     Lcd_Chr( 2, 4,'0') ; 
     Lcd_Chr( 2, 5,Aselect) ; 
     Lcd_Chr( 2, 12,'0') ; 
     Lcd_Chr( 2, 13,BSelect) ; 
 
     //timer and interrupt setup 
     //interrupt 
     EA_bit = 1; //enable interrupt 
     ET1_bit= 1; //enable timer 1 overflow interrupt 
     //timer 
     TMOD = 0x10; 
 
     TH1 = 0xEF; 
     TH2 = 0xB9; 
     TF1_bit = 0; 
     TR1_bit = 1; 
 
     //P0. B1 = 1, Lift A is moving. 0 means it is not moving. P0.B2 = 1, Lift B is moving. 0 means not moving
     P0.B1 = 0; 
     P0.B2 = 0; 
     while(1){  //move logic 
       if(OpA==1){//lift A operation, display of up/down arrow based on floor selected corresponding to current floor
        if(Aselect<ACurrent){Lcd_Chr(2,3,197);Lcd_Chr(2,6,197);delay_ms(200);Aselect++;} 
        if(Aselect>ACurrent){Lcd_Chr(2,3,198);Lcd_Chr(2,6,198);delay_ms(200);Aselect--;} 
        if(Aselect==ACurrent){P0.B1 = 0;P1=0xFF;Lcd_Chr(2,3,32);Lcd_Chr(2,6,32);if(Aselect!=0x31){ACurrent=0x31;P0.B1=1;}Lcd_Chr( 2, 5,Aselect);delay_ms(1500);} 
        } 
       if(OpB==1){//lift B operation, display of up/down arrow based on floor selected corresponding to current floor
        if(BSelect<BCurrent){Lcd_Chr(2,11,197);Lcd_Chr(2,14,197);delay_ms(200);BSelect++;} 
        if(BSelect>BCurrent){Lcd_Chr(2,11,198);Lcd_Chr(2,14,198);delay_ms(200); BSelect--;} 
        if(BSelect==BCurrent){P0.B2 = 0;P3=0xFF;Lcd_Chr(2,11,32);Lcd_Chr(2,14,32);if(BSelect!=0x31){BCurrent=0x31;P0.B2=1;}Lcd_Chr( 2, 13,BSelect);delay_ms(1500);} 
        } 
 
       Lcd_Chr( 2, 5,Aselect); 
       Lcd_Chr( 2, 13,BSelect); 
       delay_ms(800); 
     }//end while 
}//end main 

