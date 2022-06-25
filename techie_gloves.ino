/*
A0-A2 : FLEX SENSOR
D4&D5 : FOR BLUETOOTH RX AND TX
A4&A5 : XPIN AND YPIN FOR ACCELROMETER
*/

#include <SoftwareSerial.h>

SoftwareSerial mySerial(0,1);

char temp = '0';

//variable initializtion
int xpin = A4;
int xadc = 0;
int xmax = 0;
int xmin = 1023;

int ypin = A5;
int yadc = 0;
int ymax = 0;
int ymin = 1023;

int LED=13;

int FLEX_PIN1 = A0; 
int flexADC1 = 0; 
int sensorMin1 = 1023; 
int sensorMax1 = 0;

int FLEX_PIN2 = A1; 
int flexADC2 = 0; 
int sensorMin2 = 1023; 
int sensorMax2 = 0;

int FLEX_PIN3 = A2; 
int flexADC3 = 0; 
int sensorMin3 = 1023; 
int sensorMax3 = 0;

void setup() 
{
mySerial.begin(9600);
pinMode(LED, OUTPUT);//led output
while (!Serial) 
{
; // wait for serial port to connect. Needed for native USB port only
}
// callibrating the sensors for adaptivity with different bends
while(millis()<15000)
{
if(digitalRead(7)==HIGH)
{
float flexADC1 = analogRead(FLEX_PIN1);
float flexADC2 = analogRead(FLEX_PIN2);
float flexADC3 = analogRead(FLEX_PIN3);

if(flexADC1<sensorMin1)
{
sensorMin1=flexADC1;
}
if(flexADC1>sensorMax1)
{
sensorMax1=flexADC1;
}

if(flexADC2<sensorMin2)
{
sensorMin2=flexADC2;
}
if(flexADC2>sensorMax2)
{
sensorMax2=flexADC2;
}

if(flexADC3<sensorMin3)
{
sensorMin3=flexADC3;
}
if(flexADC3>sensorMax3)
{
sensorMax3=flexADC3;
}
}
}
}


void printfun(char cp) //puna puna barbardu antha letters na 

{
if(cp!=temp)
{
mySerial.print(cp);
temp=cp;
}
}

void loop() 
{
  //bluetooth code
  if(Serial.available())
  {
    int value=Serial.read();
    if(value=='1')digitalWrite(LED, HIGH);
    else if(value='0')digitalWrite(LED,LOW);
  }//bluetooth code 
// reading sensor value
float flexADC1 = analogRead(FLEX_PIN1);
float flexADC2 = analogRead(FLEX_PIN2);
float flexADC3 = analogRead(FLEX_PIN3);


flexADC1 = constrain(flexADC1,sensorMin1, sensorMax1);
flexADC2 = constrain(flexADC2,sensorMin2, sensorMax2);
flexADC3 = constrain(flexADC3,sensorMin3, sensorMax3);



float angle1= map(flexADC1, sensorMin1, sensorMax1, 0, 90);
float angle2= map(flexADC2, sensorMin2, sensorMax2, 0, 90);
float angle3= map(flexADC3, sensorMin3, sensorMax3, 0, 90);

xadc = analogRead(xpin);
yadc = analogRead(ypin);

if(((angle1>=90)&&(angle1<=0)))
printfun("H");
if(((angle1>=0)&&(angle1<=80))&&((angle2>=0)&&(angle2<=80))&&((angle3>=0)&&(angle3<=80)))
printfun('H');
if(((angle1>=40)&&(angle1<=72))&&((angle2>=50)&&(angle2<=90))&&((angle3>=51)&&(angle3<=75)))
printfun('C');
if(((angle1>=50)&&(angle1<=72))&&((angle2>=45)&&(angle2<=90))&&((angle3>=35)&&(angle3<=75))&&!(((xadc>=412)&&(xadc<=418))&&((yadc>=340)&&(yadc<=360))))
printfun('D');
if(((angle1>=68)&&(angle1<=88))&&((angle2>=68)&&(angle2<=90))&&((angle3>=50)&&(angle3<=80)))
printfun('E');
if(((angle1>=0)&&(angle1<=90))&&((angle2>=0)&&(angle2<=90))&&((angle3>=0)&&(angle3<=90)))
printfun('I');
if(((angle1>=75)&&(angle1<=90))&&((angle2>=75)&&(angle2<=90))&&((angle3>=65)&&(angle3<=90))&&((xadc>=400)&&(xadc<=420))&&((yadc>=340)&&(yadc<=360)))
printfun('G');
if(((angle1>=70)&&(angle1<=85))&&((angle2>=75)&&(angle2<=90))&&((angle3>=0)&&(angle3<=10))&&!((xadc>=410)&&(xadc<=420))&&((yadc>=368)&&(yadc<=380)))
printfun('H');
if(((angle1>=0)&&(angle1<=10))&&((angle2>=50)&&(angle2<=70))&&((angle3>=50)&&(angle3<=70))&&((xadc>=410)&&(xadc<=420))&&((yadc>=330)&&(yadc<=370)))
printfun('I');
if(((angle1>=0)&&(angle1<=10))&&((angle2>=50)&&(angle2<=70))&&((angle3>=50)&&(angle3<=70))&&(!((xadc>=410)&&(xadc<=420))&&((yadc>=355)&&(yadc<=370))))
printfun('J');
if(((angle1>=60)&&(angle1<=75))&&((angle2>=60)&&(angle2<=85))&&((angle3>=0)&&(angle3<=10))&&((xadc>=404)&&(xadc<=415))&&((yadc>=368)&&(yadc<=380)))
printfun('K');
if(((angle1>=75)&&(angle1<=90))&&((angle2>=75)&&(angle2<=90))&&((angle3>=70)&&(angle3<=90))&&(((xadc>=390)&&(xadc<=405))&&((yadc>=360)&&(yadc<=380)))&&!((xadc>=270)&&(xadc<=300))&&((yadc>=360)&&(yadc<=390)))
printfun('L');
if(((angle1>=40)&&(angle1<=61))&&((angle2>=72)&&(angle2<=84))&&((angle3>=45)&&(angle3<=65)))
printfun('M');
if(((angle1>=54)&&(angle1<=70))&&((angle2>=50)&&(angle2<=61))&&((angle3>=48)&&(angle3<=66))&&(((xadc>=400)&&(xadc<=435))&&((yadc>=350)&&(yadc<=390))))
printfun('N');
if(((angle1>=68)&&(angle1<=88))&&((angle2>=68)&&(angle2<=90))&&((angle3>=50)&&(angle3<=80)))
printfun('O');
if(((angle1>=60)&&(angle1<=75))&&((angle2>=60)&&(angle2<=85))&&((angle3>=0)&&(angle3<=10))&&(((xadc>=270  )&&(xadc<=290))&&((yadc>=360)&&(yadc<=380))))
printfun('P');
if(((angle1>=75)&&(angle1<=90))&&((angle2>=75)&&(angle2<=90))&&((angle3>=65)&&(angle3<=90))&&(((xadc>=270)&&(xadc<=300))&&((yadc>=360)&&(yadc<=390))))
printfun('Q');
if(((angle1>=40)&&(angle1<=72))&&((angle2>=45)&&(angle2<=90))&&((angle3>=20)&&(angle3<=45))&&(((xadc>=412)&&(xadc<=418))&&((yadc>=340)&&(yadc<=360))))
printfun('R');
if(((angle1>=70)&&(angle1<=90))&&((angle2>=80)&&(angle2<=90))&&((angle3>=80)&&(angle3<=90)))
printfun('S');
if(((angle1>=40)&&(angle1<=61))&&((angle2>=72)&&(angle2<=84))&&((angle3>=45)&&(angle3<=65))&&(digitalRead(6)==HIGH))
printfun('T');
if(((angle1>=70)&&(angle1<=90))&&((angle2>=80)&&(angle2<=90))&&((angle3>=0)&&(angle3<=10)))
printfun('U');
if(((angle1>=70)&&(angle1<=90))&&((angle2>=80)&&(angle2<=90))&&((angle3>=0)&&(angle3<=10))&&(digitalRead(6)==HIGH)) 
printfun('V');
if(((angle1>=70)&&(angle1<=90))&&((angle2>=0)&&(angle2<=10))&&((angle3>=0)&&(angle3<=10)))
printfun('W');
if(((angle1>=50)&&(angle1<=72))&&((angle2>=45)&&(angle2<=90))&&((angle3>=35)&&(angle3<=75)))//&&!(((xadc>=412)&&(xadc<=418))&&((yadc>=340)&&(yadc<=360))))
printfun('X');
if(((angle1>=0)&&(angle1<=10))&&((angle2>=70)&&(angle2<=90))&&((angle3>=60)&&(angle3<=80)))
printfun('Y');
if(((angle1>=50)&&(angle1<=72))&&((angle2>=45)&&(angle2<=90))&&((angle3>=35)&&(angle3<=75))&&(((xadc>=412)&&(xadc<=418))&&((yadc>=340)&&(yadc<=360))))
printfun('Z');


delay(1000);
 
}
