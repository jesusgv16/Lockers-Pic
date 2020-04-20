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

int  n_aleatorio;
char txt[7];
int ocupado[8];


  void config(){
  
   TRISC7_bit = 1;             // Make RC7 as input;

  }
  void password(){ //generacion de la contraseña
n_aleatorio = rand()%(90000)+10000;//Numero aleatorio entre 99999 y 10000
      if (n_aleatorio<0) //se asegura de que no alla numeros negativos
      {
       n_aleatorio=n_aleatorio*(-1);
      }
      intToStr(n_aleatorio,txt); // make it a string
      lcd_out(1,1,"Password");
      lcd_out(2,1,txt);
      delay_ms(200);

  }

void main(){

  Lcd_Init();                        // Initialize LCD
  Lcd_Cmd(_LCD_CLEAR);               // Clear display
  Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off





  while(1) { 
      if(PORTC.F7==1){
      Lcd_Cmd(_LCD_CLEAR);
      lcd_out(1,1,"solicitaste");
      delay_ms(200);
      }

      
      if(ocupado[0]==0 ){
            ocupado[0]=1;
             password();
        }
     else if(ocupado[1]==0){
          ocupado[1]=1;
          password();
      }
      else if(ocupado[2]==0){
          ocupado[2]=1;
          password();
      }
      else if(ocupado[3]==0){
          ocupado[3]=1;
          password();
      }
      else if(ocupado[4]==0){
          ocupado[4]=1;
          password();
      }
      else if(ocupado[5]==0){
          ocupado[5]=1;
          password();
      }
      else if(ocupado[6]==0){
          ocupado[6]=1;
          password();
      }
      else if(ocupado[7]==0){
          ocupado[7]=1;
          password();
      }
      else if(ocupado[8]==0){
          ocupado[8]=1;
          password();
      }
      else if(ocupado[9]==0){
          ocupado[9]=1;
          password();
      }
      
      


      
      


  }
  }
