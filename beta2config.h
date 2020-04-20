extern char kp;

// LCD module connections
sbit LCD_RS at RD2_bit;
sbit LCD_EN at RD3_bit;
sbit LCD_D4 at RD4_bit;
sbit LCD_D5 at RD5_bit;
sbit LCD_D6 at RD6_bit;
sbit LCD_D7 at RD7_bit;

sbit LCD_RS_Direction at TRISD2_bit;
sbit LCD_EN_Direction at TRISD3_bit;
sbit LCD_D4_Direction at TRISD4_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D7_Direction at TRISD7_bit;
// End LCD module connections


char  keypadPort at PORTB;

int teclado(){
    kp = 0;
    do{
      // kp = Keypad_Key_Press();
      kp = Keypad_Key_Click();
    }while (!kp);

    switch (kp) {
      case  1: kp = '1'; break; // 1
      case  2: kp = '2'; break; // 2
      case  3: kp = '3'; break; // 3
      case  4: kp = 'A'; break; // A
      case  5: kp = '4'; break; // 4
      case  6: kp = '5'; break; // 5
      case  7: kp = '6'; break; // 6
      case  8: kp = 'B'; break; // B
      case  9: kp = '7'; break; // 7
      case 10: kp = '8'; break; // 8
      case 11: kp = '9'; break; // 9
      case 12: kp = 'C'; break; // C
      case 13: kp = '*'; break; // *
      case 14: kp = '0'; break; // 0
      case 15: kp = '#'; break; // #
      case 16: kp = 'D'; break; // D
    }
    return kp;
}
