#include "config.h"
char kp;
char usuario[6]=" ";
char fija1[7]=" ", fija2[7]=" ", fija3[7]=" ", fija4[7]=" ", fija5[7]=" ", fija6[7]=" ", fija7[7]=" ", fija8[7]=" ", fija9[7]=" ";

int i=0, error=0,temp;
int  n_aleatorio;
int password(){ //funcion para generacion de la contraseña
    n_aleatorio = rand()%(90000)+10000;//Numero aleatorio entre 99999 y 10000
      if (n_aleatorio<0) //se asegura de que no alla numeros negativos
      {
       n_aleatorio=n_aleatorio*(-1);
      }
  }

void main() {
       ADCON1 = 0x0F;
       TRISC = 0x00;
       Lcd_init();
       Lcd_Cmd(_LCD_CURSOR_OFF);
       Keypad_init();
       temp=password();
       intToStr(temp,fija);
       Lcd_out(1,1,fija);
       Lcd_out(2,1,"CONTRA: ");


       while(1){
            usuario[i]= teclado();
            Lcd_chr_cp(usuario[i]);
            i++;
            if(i==5){
                   Lcd_cmd(1);
                   Lcd_out(1,1,usuario);
                   
                   for(i=0; i<=5; i++){
                         if(fija1[i+1] != usuario[i]){
                            error++;
                         }
                         Lcd_chr(2,i+1,'*');
                         delay_ms(20);
                   }
                   if(error==0){

                         Lcd_cmd(1);
                         Lcd_out(1,1,"CONTRASENA VALIDA");
                   }
                   
                   else{

                         Lcd_cmd(1);
                         Lcd_out(1,1,"ERROR CONTRASENA");
                   }
                   delay_ms(200);
                    lcd_cmd(1);
                    Lcd_out(1,1,"DIGITE CONTRASENA");
                    Lcd_out(2,1,"CONTRA: ");
                    i=0;
                    error=0;
            }

       }
}
