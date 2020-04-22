#include "config.h"
char kp;
char usuario[6]=" ";
char fija[7]=" ",fija1[7]=" ", fija2[7]=" ", fija3[7]=" ", fija4[7]=" ", fija5[7]=" ", fija6[7]=" ", fija7[7]=" ", fija8[7]=" ", fija9[7]=" ";

int i=0, error=0;
int temp; //variable temporal que almacena la contraseña
int  n_aleatorio;
int tecla;//para el menu
int password(){ //funcion para generacion de la contraseña
    n_aleatorio = rand()%(90000)+10000;//Numero aleatorio entre 99999 y 10000
      if (n_aleatorio<0) //se asegura de que no alla numeros negativos
      {
       n_aleatorio=n_aleatorio*(-1);
      }
  }

void contras(){

temp=password();
    intToStr(temp,fija1);
    Lcd_out(1,1,"Pass1:");
    Lcd_out(2,1,fija1);
    delay_ms(200);
temp=password();
    intToStr(temp,fija2);
    Lcd_out(1,1,"Pass2:");
    Lcd_out(2,1,fija2);
    delay_ms(200);
temp=password();
    intToStr(temp,fija3);
    Lcd_out(1,1,"Pass3:");
    Lcd_out(2,1,fija3);
    delay_ms(200);
temp=password();
    intToStr(temp,fija4);
    Lcd_out(1,1,"Pass4:");
    Lcd_out(2,1,fija4);
    delay_ms(200);
temp=password();
    intToStr(temp,fija5);
    Lcd_out(1,1,"Pass5:");
    Lcd_out(2,1,fija5);
    delay_ms(200);
temp=password();
    intToStr(temp,fija6);
    Lcd_out(1,1,"Pass6:");
    Lcd_out(2,1,fija6);
    delay_ms(200);
temp=password();
    intToStr(temp,fija7);
    Lcd_out(1,1,"Pass7:");
    Lcd_out(2,1,fija7);
  delay_ms(200);
temp=password();
    intToStr(temp,fija8);
    Lcd_out(1,1,"Pass8:");
    Lcd_out(2,1,fija8);
    delay_ms(200);
temp=password();
    intToStr(temp,fija9);
    Lcd_out(1,1,"Pass9:");
    Lcd_out(2,1,fija9);
    delay_ms(200);



}

void corroborar(fija){
             usuario[i]= teclado();
            Lcd_chr_cp(usuario[i]);
            i++;
            if(i==5){
                   Lcd_cmd(1);
                   Lcd_out(1,1,usuario);

                   for(i=0; i<=5; i++){
                         if(fija[i+1] != usuario[i]){
                            error++;
                         }
                         Lcd_chr(2,i+1,'*');
                         delay_ms(20);
                   }
                   if(error==0){

                         Lcd_cmd(1);
                         Lcd_out(1,1,"Password OK");
                   }

                   else{

                         Lcd_cmd(1);
                         Lcd_out(1,1,"Bad Password");
                   }
                   delay_ms(200);
                    lcd_cmd(1);
                    Lcd_out(1,1,"DIGITE CONTRASENA");
                    Lcd_out(2,1,"CONTRA: ");
                    i=0;
                    error=0;
            }
}
void main() {
       ADCON1 = 0x0F;
       TRISC = 0x00;
       Lcd_init();
       Lcd_Cmd(_LCD_CURSOR_OFF);
       Keypad_init();
       contras();

       Lcd_out(1,1,"Introduce");
       Lcd_out(2,1,"CONTRA: ");


       while(1){
         menu_p();
         tecla=teclado();
            switch(tecla){
               case '1':
                    corroborar();
                               break;
               case '2':
                    corroborar();
                               break;
               case '3':
                    corroborar();
                               break;
               case '4':
                    corroborar();
                               break;
               case '5':
                    corroborar();
                               break;
               case '6':
                    corroborar();
                               break;
               case '7':
                    corroborar();
                               break;
               case '8':
                    corroborar();
                               break;
               case '9':
                    corroborar();
                               break;
         }
         
         /*--------------*/
       
         corroborar();

       }
}
