#include "config.h"



char kp;
char usuario[6]=" ";
char fija[7]=" ",fija1[7]=" ", fija2[7]=" ", fija3[7]=" ", fija4[7]=" ", fija5[7]=" ", fija6[7]=" ", fija7[7]=" ", fija8[7]=" ", fija9[7]=" ";
short int ocupado [9]={0,0,0,0,0,0,0,0,0} ;

short int flag1, flag2, flag3, flag4, flag5, flag6, flag7, flag8, flag9;
short int good=0;

short int i=0, error=0;
int tecla,tecla1;//para el menu
char corroborar(char*); //prototipo de la funcion corroborar



int corroborar(char *fija){
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
                         delay_ms(50);
                   }
                   if(error==0){
                         Lcd_cmd(1);
                         Lcd_out(1,1,"Password OK");
                         delay_ms(500);
                         good=1;
                         return 1;
                   }
                   else{
                         Lcd_cmd(1);
                         Lcd_out(1,1,"Bad Password");
                         good=0;

                   }
                   delay_ms(50);
                    lcd_cmd(1);
                    Lcd_out(1,1,"Intente de nuevo");
                   delay_ms(300);
                    i=0;
                    error=0;
                       return 0;
            }
}while(i!=5);
}


void interrupt(){

   INTCON.INT0IF = 0; // Limpiar bandera de INT0
     if (ocupado[0]==0)
       {
         ocupado[0]=1;
         flag1=1;
         return;
       }
      else if (ocupado[1]==0 )
         {
         ocupado[1]=1;
         flag2=1;
         return;
         }

      else if (ocupado[2]==0 )
         {
         ocupado[2]=1;
         flag3=1;
         return;
         }

       else if (ocupado[3]==0 )
         {
         ocupado[3]=1;
         flag4=1;
         return;
         }

      else if (ocupado[4]==0)
       {
         ocupado[4]=1;
         flag5=1;
         return;
       }

      else if (ocupado[5]==0)
         {
         ocupado[5]=1;
         flag6=1;
         return;
         }

      else if (ocupado[6]==0  )
         {
         ocupado[6]=1;
         flag7=1;
         return;
         }

       else if (ocupado[7]==0 )
         {
         ocupado[7]=1;
         flag8=1;
         return;
         }

       else if (ocupado[8]==0 )
         {
         ocupado[8]=1;
         flag9=1;
         return;
         }

}

    void solicitar(){

    if (ocupado[0]==1 && flag1==1 && S1==1)
       {
           Lcd_Cmd(_LCD_CLEAR);
           M1=0;
                while(S1==1)
                {
                  Lcd_out(1,1,"waiting door 1...");
                  rebote();
                }
          Lcd_Cmd(_LCD_CLEAR);
          Lcd_out(1,1,"Pass Locker 1:");
          Lcd_out(2,1,fija1);
          delay2();
          flag1=0;
          M1=1;
       }
       else if (ocupado[1]==1 && flag2==1 && S2==1)
       {
        Lcd_Cmd(_LCD_CLEAR);
        M2=0;
                while(S2==0)
                {
                  Lcd_out(1,1,"waiting door 2...");
                }
        Lcd_Cmd(_LCD_CLEAR);
        Lcd_out(1,1,"Pass Locker 2:");
        Lcd_out(2,1,fija2);
        delay2();
        flag2=0;
        M2=1;
       }
       else if (ocupado[2]==1 && flag3==1 && S3==1)
       {
        Lcd_Cmd(_LCD_CLEAR);
        M3=0;
        while(S3==1)
                {
                  Lcd_out(1,1,"waiting door 3...");
                }
        Lcd_Cmd(_LCD_CLEAR);
        Lcd_out(1,1,"Pass Locker 3:");
        Lcd_out(2,1,fija3);
        delay2();
        flag3=0;
        M3=1;
       }

       else if (ocupado[3]==1 && flag4==1 && S4==1)
       {
        Lcd_Cmd(_LCD_CLEAR);
        M4=0;
        Lcd_out(1,1,"waiting door 4...");
        while(PORTC.F4==1)
                {

                }
        Lcd_Cmd(_LCD_CLEAR);
        Lcd_out(1,1,"Pass Locker 4:");
        Lcd_out(2,1,fija4);
        delay2();
        flag4=0;
        M4=1;
       }

       else if (ocupado[4]==1 && flag5==1 && S5==1)
       {
        Lcd_Cmd(_LCD_CLEAR);
        M5=0;
        Lcd_out(1,1,"waiting door 5...");
        while(S5==1)
                {

                }
        Lcd_Cmd(_LCD_CLEAR);
        Lcd_out(1,1,"Pass Locker 5:");
        Lcd_out(2,1,fija5);
        delay2();
        flag5=0;
        M5=1;
       }

       else if (ocupado[5]==1 && flag6==1 && S6==1)
       {
        Lcd_Cmd(_LCD_CLEAR);
        M6=0;
        while(S6==0)
                {
                  Lcd_out(1,1,"waiting door 6...");
                }
        Lcd_Cmd(_LCD_CLEAR);
        Lcd_out(1,1,"Pass Locker 6:");
        Lcd_out(2,1,fija6);
        delay2();
        flag6=0;
        M6=1;
       }

       else if (ocupado[6]==1 && flag7==1 && S7==1)
       {
        Lcd_Cmd(_LCD_CLEAR);
        M7=0;
        while(S7==1)
                {
                  Lcd_out(1,1,"waiting door 7...");
                }
        Lcd_Cmd(_LCD_CLEAR);
        Lcd_out(1,1,"Pass Locker 7:");
        Lcd_out(2,1,fija7);
        delay2();
        flag7=0;
        M7=1;
       }

       else if (ocupado[7]==1 && flag8==1 && S8==1)
       {
        Lcd_Cmd(_LCD_CLEAR);
        M8=0;
        while(S8==1)
                {
                  Lcd_out(1,1,"waiting door 8...");
                }
        Lcd_Cmd(_LCD_CLEAR);
        Lcd_out(1,1,"Pass Locker 8:");
        Lcd_out(2,1,fija8);
        delay2();
        flag8=0;
        M8=1;
       }

       else if (ocupado[8]==1 && flag9==1 && S9==1)
       {
        Lcd_Cmd(_LCD_CLEAR);
        M9=0;
        while(S9==1)
                {
                  Lcd_out(1,1,"waiting door 9...");
                }
        Lcd_Cmd(_LCD_CLEAR);
        Lcd_out(1,1,"Pass Locker 9:");
        Lcd_out(2,1,fija9);
        delay2();
        flag9=0;
        M9=1;
       }
       else
       {
        Lcd_Cmd(_LCD_CLEAR);
        Lcd_out(1,1,"ERROR Press");
        Lcd_out(2,1,"Button 1 and *");
        delay_ms(1000);
       }


    }
void main() {
      ADCON1 = 0x0F;
      CMCON |= 7;



      INTCON.INT0IE = 1; // Interrupción externa INT0 habilitada
      INTCON.GIE = 1; // Habilita todas las interrupciones
      INTCON2.INTEDG0 = 1; // INT0 en flanco de subida

      TRISB=0X01;    // ALL PORTB AS OUTPUT EXCEPT FROM INT0(RB0)


      LATE=0b1100;
      LATB=0xFF;
      TRISC=0XFF;//PUERTO C ENTRADAS PARA SENSORES
      UCON.USBEN=0;
      UCFG.UTRDIS=1;


      TRISE=0X03;//RE0&RE1 INPUT AND RE2&RE3 OUTPUT

       Lcd_init();
       Lcd_Cmd(_LCD_CURSOR_OFF);
       Keypad_init();
       contras();




       while(1){

       solicitar();
       menu_p();
         tecla1=teclado();
          /*------------------------opciones del teclado------------------------------*/
         if (tecla1=='1')
           {
                if(ocupado[0]==1)
                {
                 good=corroborar(fija1);
                      if (good==1)
                       {
                         Lcd_Cmd(_LCD_CLEAR);
                         Lcd_out(1,1,"Opening Locker 1");
                         M1=0;
                         delay2();
                         M1=1;
                       }
                }
                 else
                  {
                     vacio();
                  }
           }
         else if(tecla1=='2')
           {
                 if(ocupado[1]==1)
                {
                 good=corroborar(fija2);
                      if (good==1)
                       {
                         Lcd_Cmd(_LCD_CLEAR);
                         Lcd_out(1,1,"Opening Locker 2");
                         M2=0;
                         delay2();
                         M2=1;
                       }
                }
                 else
                  {
                   vacio();
                  }
           }
         else if(tecla1=='3')
           {
                 if(ocupado[2]==1)
                {
                 good=corroborar(fija3);
                      if (good==1)
                       {
                         Lcd_Cmd(_LCD_CLEAR);
                         Lcd_out(1,1,"Opening Locker 3");
                         M3=0;
                         delay2();
                         M3=1;
                       }
                }
                 else
                  {
                   vacio();
                  }
           }

         else if(tecla1=='4')
           {
                 if(ocupado[3]==1)
                {
                 good=corroborar(fija4);
                      if (good==1)
                       {
                         Lcd_Cmd(_LCD_CLEAR);
                         Lcd_out(1,1,"Opening Locker 4");
                         M4=0;
                         delay2();
                         M4=1;
                       }
                }
                 else
                  {
                   vacio();
                  }
           }

         else if(tecla1=='5')
           {
                 if(ocupado[4]==1)
                {
                 good=corroborar(fija5);
                      if (good==1)
                       {
                         Lcd_Cmd(_LCD_CLEAR);
                         Lcd_out(1,1,"Opening Locker 5");
                         M5=0;
                         delay2();
                         M5=1;
                       }
                }
                 else
                  {
                   vacio();
                  }
           }

         else if(tecla1=='6')
           {
                 if(ocupado[5]==1)
                {
                 good=corroborar(fija6);
                      if (good==1)
                       {
                         Lcd_Cmd(_LCD_CLEAR);
                         Lcd_out(1,1,"Opening Locker 6");
                         M6=0;
                         delay2();
                         M6=1;
                       }
                }
                 else
                  {
                   vacio();
                  }
           }

         else if(tecla1=='7')
           {
                 if(ocupado[6]==1)
                {
                 good=corroborar(fija7);
                      if (good==1)
                       {
                         Lcd_Cmd(_LCD_CLEAR);
                         Lcd_out(1,1,"Opening Locker 7");
                         M7=0;
                         delay2();
                         M7=1;
                       }
                }
                 else
                  {
                   vacio();
                  }
           }

         else if(tecla1=='8')
           {
                 if(ocupado[7]==1)
                {
                 good=corroborar(fija8);
                      if (good==1)
                       {
                         Lcd_Cmd(_LCD_CLEAR);
                         Lcd_out(1,1,"Opening Locker 8");
                         M8=0;
                         delay2();
                         M8=1;
                       }
                }
                 else
                  {
                   vacio();
                  }
           }

         else if(tecla1=='9')
           {
                 if(ocupado[8]==1)
                {
                 good=corroborar(fija9);
                      if (good==1)
                       {
                         Lcd_Cmd(_LCD_CLEAR);
                         Lcd_out(1,1,"Opening Locker 9");
                         M9=0;
                         delay2();
                         M9=1;
                       }
                }
                 else
                  {
                   vacio();
                  }
           }

         else if(tecla1=='*')
           {
           Lcd_Cmd(_LCD_CLEAR);
           Lcd_out(1,1,"Espere...");
           delay_ms(700);
           }
         else if(tecla1=='#')
           {
           Lcd_Cmd(_LCD_CLEAR);
           Lcd_out(1,1,"no valido.");
           delay_ms(500);
           }
         /*---------------------end opciones teclado-------------------------------*/


       }
}
