
#include <Servo.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(10,11,A10,A11,12,13);
Servo braco;
Servo coto;
Servo base;
Servo garra;
Servo pulso;



char valor;
int angbase;
int angbraco;
int angcoto;
int anggarra;
int angpulso;
int x;
int t=500;
int d=20;
byte seletor;

void setup()
{
 base.attach(A0);
 braco.attach(A1);
 coto.attach(A2);
 
 garra.attach(A4);
 pinMode(8,OUTPUT); 
 pinMode(7,OUTPUT);
 pinMode(6,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(4,INPUT_PULLUP); 
 pinMode(3,INPUT_PULLUP);
 pinMode(2,INPUT_PULLUP);
 pinMode(1,INPUT_PULLUP); 
 lcd.begin(16,2); 
 base.write(70);
 braco.write(60); 
 coto.write(40);
 garra.write(80); 
 
  profile();  
}
void loop()
{
 teclado();
 select();
 
}  
void profile()
{
 lcd.clear();
 lcd.setCursor(4,0);
 lcd.print("CENTRO");
 lcd.setCursor(1,1);
 lcd.print("UNIVERSITARIO");
 delay(2000);
 lcd.clear();
 lcd.setCursor(5,0);
 lcd.print("ENIAC");
 delay(3000);
 lcd.clear();
 lcd.setCursor(3,0);
 lcd.print("CONTROLE DE");
 lcd.setCursor(3,1);
 lcd.print("PROCESSOS");
 delay(3000);
 lcd.clear();
 lcd.setCursor(5,0);
 lcd.print("BRACO");
 lcd.setCursor(2,1);
 lcd.print("MANIPULADOR");
 delay(3000);
 lcd.clear();
 lcd.print("Alfredo Ferreira");
 lcd.setCursor(0,1);
 lcd.print("RA:215342018");
 delay(3000);
 lcd.clear();
 lcd.print("Jose Luiz");
 lcd.setCursor(0,1);
 lcd.print("RA:517822018");
 delay(3000);
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Luiz Augusto");
 lcd.setCursor(0,1);
 lcd.print("RA:123892013");
 delay(3000);
 lcd.clear(); 
}
void teclado()
{ valor='a';
  digitalWrite(8,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(5,HIGH);
   if(digitalRead(4)==LOW){valor='1';}//1
   if(digitalRead(3)==LOW){valor='2';}//2
   if(digitalRead(2)==LOW){valor='3';}//3
   if(digitalRead(1)==LOW){valor='A';}//A

  digitalWrite(8,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(5,HIGH);
   if(digitalRead(4)==LOW){valor='4';}//4
   if(digitalRead(3)==LOW){valor='5';}//5
   if(digitalRead(2)==LOW){valor='6';}//6
   if(digitalRead(1)==LOW){valor='B';}//B
    
  digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(5,HIGH);
   if(digitalRead(4)==LOW){valor='7';}//7
   if(digitalRead(3)==LOW){valor='8';}//8
   if(digitalRead(2)==LOW){valor='9';}//9
   if(digitalRead(1)==LOW){valor='C';}//C

  digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
   if(digitalRead(4)==LOW){valor='*';}//*
   if(digitalRead(3)==LOW){valor='0';}//0
   if(digitalRead(2)==LOW){valor='#';}//#
   if(digitalRead(1)==LOW){valor='D';}//D  
}

void select()
{
 switch(valor)
 {
//*******************AUTOMÁTICO************************
   case 'A':
   lcd.clear();
   seletor=0;
   while(seletor==0)
    {
     lcd.setCursor(0,0);lcd.print("1-AUTO.1");
     lcd.setCursor(0,1);lcd.print("2-AUTO.2  B-BACK");
     teclado();
     if(valor=='B'){lcd.clear();seletor=1;}
     if(valor=='1'){aut1();}
     if(valor=='2'){aut2();}
    }
   break;
//*********************FIM AUTOMÁTICO**********************
//************************MANUAL***************************   
   case 'C':
   lcd.clear();
   seletor=1; 
   while(seletor==1)
    {
     teclado();
switch(valor)
      {default:
       lcd.setCursor(0,0);
       lcd.print("1-BASE   2-BRAÇO");
       lcd.setCursor(0,1);
       lcd.print("3- COTO  4-GARRA");
       break;
       case '1':
       lcd.clear();
       seletor=0;
        while(seletor==0)
         {
          lcd.setCursor(0,0);
          lcd.print("*:+ANG    D-SET");
          lcd.setCursor(0,1);
          lcd.print("#:-ANG     B-BACK");
          lcd.setCursor(7,0);
          lcd.print(angbase);
          teclado();
          if(valor=='*' && angbase<180)
          {base.write(angbase);
           angbase++;
           delay(40);}
          if(valor=='#' && angbase>0)
          {base.write(angbase);
           angbase--;
           delay(40);}        
          if(valor=='B'){lcd.clear();return;}
          if(valor=='D'){seletor=2;lcd.clear();
          while(seletor==2)
            {
             lcd.setCursor(0,0);
             lcd.print("#:+DELAY");
             lcd.setCursor(0,1);
             lcd.print("*:-DELAY  B-BACK");
             lcd.setCursor(12,0);
             lcd.print(d);
             delay(200);          
             teclado();
             if(valor=='#'){d=d+10;delay(250);}
             if(valor=='*' && d>=0){d=d-10;delay(250);}
             if(valor=='B'){seletor=0;lcd.clear();} 
            }  
           }
        }
       break;       
  
        case'2':
       lcd.clear();
    seletor=0;
    while(seletor==0)
      {
      lcd.setCursor(0,0);
      lcd.print("*:+ANG    D-SET");
      lcd.setCursor(0,1);
      lcd.print("#:-ANG    B-BACK");
       lcd.setCursor(7,0);
       lcd.print(angbraco);
      teclado();
      if(valor=='*' && angbraco<120)
      {braco.write(angbraco);
         angbraco++;
         delay(60);}
      if(valor=='#' && angbraco>0)
      {braco.write(angbraco);
         angbraco--;
          delay(60);}        
        if(valor=='B'){lcd.clear();return;}
            if(valor=='D')
          {seletor=2;
           lcd.clear();
           teclado();
           while(seletor==2)
           {
            lcd.setCursor(0,0);
            lcd.print("#:+DELAY");
            lcd.setCursor(0,1);
            lcd.print("*:-DELAY  B-BACK");
            lcd.setCursor(12,0);
            lcd.print(d);
            delay(200);
            
            teclado();
            if(valor=='#'){d=d+10;delay(250);}
            if(valor=='*'){d=d-10;delay(250);}
            if(valor=='B'){seletor=0;lcd.clear();} 
           }  
          }}
    break;
    case'3':
    lcd.clear();
       seletor=0;
    while(seletor==0)
      {
      lcd.setCursor(0,0);
      lcd.print("*:+ANG    D-SET");
      lcd.setCursor(0,1);
      lcd.print("#:-ANG    B-BACK");
      lcd.setCursor(7,0);
      lcd.print(angcoto); 
      teclado();
      if(valor=='*' && angcoto<120)
      {coto.write(angcoto);
         angcoto++;
         delay(60);}
      if(valor=='#' && angcoto>0)
      {coto.write(angcoto);
         angcoto--;
         delay(60);}        
       if(valor=='B'){lcd.clear();return;}
        if(valor=='D')
          {seletor=3;
           lcd.clear();
           teclado();
           while(seletor==3)
           {
            lcd.setCursor(0,0);
            lcd.print("#:+DELAY");
            lcd.setCursor(0,1);
            lcd.print("*:-DELAY  B-BACK");
            lcd.setCursor(12,0);
            lcd.print(d);
            delay(200);
            
            teclado();
            if(valor=='#'){d=d+10;delay(250);}
            if(valor=='*'){d=d-10;delay(250);}
            if(valor=='B'){seletor=0;lcd.clear();} 
           }  }}
  
         break; 
       case'4':
       lcd.clear();
       seletor=0;
    while(seletor==0)
      {
      lcd.setCursor(0,0);
      lcd.print("*+ANG     D-SET");
      lcd.setCursor(0,1);
      lcd.print("#-ANG     B-BACK");
      lcd.setCursor(7,0);
      lcd.print(anggarra);
          teclado();
      if(valor=='*' && anggarra<100)
      {garra.write(anggarra);
         anggarra++;
         delay(40);}
      if(valor=='#' && anggarra>0)
      {garra.write(anggarra);
         anggarra--;
         delay(40);}        
       if(valor=='B'){lcd.clear();return;}
         if(valor=='D')
          {seletor=3;
           lcd.clear();
           teclado();
           while(seletor==3)
           {
            lcd.setCursor(0,0);
            lcd.print("#:+DELAY");
            lcd.setCursor(0,1);
            lcd.print("*:-DELAY  B-BACK");
            lcd.setCursor(12,0);
            lcd.print(d);
            delay(200);
            
            teclado();
            if(valor=='#'){d=d+10;delay(50);}
            if(valor=='*'){d=d-10;delay(50);}
            if(valor=='B'){seletor=0;lcd.clear();} 
           }  }}
    break; 

   
    

   
    }
//**********************FIM MANUAL**********************
  }
  break;
   return;{
  default:
  lcd.setCursor(0,0);
  lcd.print("A-AUTOMATICO");
  lcd.setCursor(0,1);
  lcd.print("C-MANUAL");
  break; 
  lcd.setCursor(0,0);
  lcd.print("A-AUTOMATICO");
  lcd.setCursor(0,1);
  lcd.print("C-MANUAL");
  break; 
   }
 
 }
}
void BASE(int b)
{
   while(angbase<b)
    {angbase++;
     base.write(angbase);
     delay(50);}
   while(angbase>b)
    {angbase--;
     base.write(angbase);
     delay(50);} 
}
void BRACO(int a)
{
    while(angbraco<a)
    {angbraco++;
     braco.write(angbraco);
     delay(100);}
   while(angbraco>a)
    {angbraco--;
     braco.write(angbraco);
     delay(100);} 
}
void COTO(int c)
{
   while(angcoto<c)
    {angcoto++;
     coto.write(angcoto);
     delay(100);}
   while(angcoto>c)
     coto.write(angcoto);
     delay(100);}  

void PULSO(int g)
{
   while(angpulso<g)
    {angpulso++;
     pulso.write(angpulso);
     delay(100);}
   while(angpulso>g)
    {angpulso--;
     pulso.write(angpulso);
     delay(100);
    } }
   
  void GARRA(int h) 
 {
   while(anggarra<h)
    {anggarra++;
     garra.write(anggarra);
     delay(20);}
   while(anggarra>h)
    {anggarra--;
     garra.write(anggarra);
     delay(20);} 
 
}
void aut1()
{
COTO(80);GARRA(55);GARRA(95);//PRIMEIRO QUADRANTE//
BASE(40);COTO(60);GARRA(55);GARRA(95);//PRIMEIRO QUADRANTE//
BASE(80);GARRA(55);GARRA(95);//PRIMEIRO QUADRANTE//
BASE(100);GARRA(45);GARRA(95);//SEGUNDO QUADRANTE//
BRACO(90);COTO(40);GARRA(45);GARRA(95);//SEGUNDO QUADRANTE//

}
 void aut2()
{BASE(60);BRACO(48);COTO(53);GARRA(30);//PEGAR PEÇA//
BASE(100);GARRA(78);//SOLTAR PEÇA E PEGAR A PEÇA//
GARRA(30);BASE(69);BRACO(40);COTO(40);BRACO(26);GARRA(40);//SOLTAR E FIM//
}
  
