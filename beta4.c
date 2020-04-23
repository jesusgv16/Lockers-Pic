#include "config.h"
char kp;
char usuario[6]=" ";
char fija[7]=" ",fija1[7]=" ", fija2[7]=" ", fija3[7]=" ", fija4[7]=" ", fija5[7]=" ", fija6[7]=" ", fija7[7]=" ", fija8[7]=" ", fija9[7]=" ";


int i=0, error=0;
int tecla,tecla1;//para el menu
char corroborar(char*); //prototipo de la funcion corroborar



void corroborar(char *fija){
i=0;
do{
       Lcd_Cmd(_LCD_CLEAR);
       Lcd_out(1,1,"Pass:");
             usuario[i]= teclados();
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
                         delay_ms(500);
                         break;
                   }
                   else{
                         Lcd_cmd(1);
                         Lcd_out(1,1,"Bad Password");
                   }
                   delay_ms(200);
                    lcd_cmd(1);
                    Lcd_out(1,1,"Intente de nuevo");
                   delay_ms(200);
                    i=0;
                    error=0;
            }
}while(i!=5);
}




void main() {
       ADCON1 = 0x0F;
       TRISC = 0x00;
       TRISD0_bit=1;
       Lcd_init();
       Lcd_Cmd(_LCD_CURSOR_OFF);
       Keypad_init();
       contras();



       while(1){
          menu_p();
         tecla1=teclado();
            switch(tecla1){
               case '1':
                    corroborar(fija1);

                               break;
               case '2':
                    corroborar(fija2);
                               break;
              case '3':
                    corroborar(fija3);
                               break;
               case '4':
                    corroborar(fija4);
                               break;
               case '5':
                    corroborar(fija5);
                               break;
               case '6':
                    corroborar(fija6);
                               break;
               case '7':
                    corroborar(fija7);
                               break;
               case '8':
                    corroborar(fija8);
                               break;
               case '9':
                    corroborar(fija9);
                               break;
         }
       }
}

