
#define LEDBACK 7
#define LEDFW 8
#define LEDPWR 9
#define LOGIC A0
#define PWR A1
#define STP_ADC A6
#define PWRBTN A7
#define DIR_BTN1 2
#define DIR_BTN2 3
#define EN 4
#define STP 5
#define DIR 6

int stepval=1;


void setup() {
  // put your setup code here, to run once:
pinMode(EN, OUTPUT);
pinMode(STP, OUTPUT);
pinMode(DIR, OUTPUT);
pinMode(PWR, OUTPUT);
pinMode(LEDBACK, OUTPUT);
pinMode(LEDFW, OUTPUT);
pinMode(LEDPWR, OUTPUT);
pinMode(LOGIC, OUTPUT);

pinMode(DIR_BTN1, INPUT);
pinMode(DIR_BTN2, INPUT);


digitalWrite(LOGIC, HIGH);
digitalWrite(DIR, HIGH);
digitalWrite(EN, HIGH);
digitalWrite(STP, HIGH);
digitalWrite(PWR, HIGH);
digitalWrite(LEDPWR,HIGH);


//Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//power();
if(analogRead(PWRBTN)>500)
{
  digitalWrite(PWR, HIGH);
  digitalWrite(LEDPWR,HIGH);  
}
else
{
  digitalWrite(PWR, LOW);
  digitalWrite(LEDPWR, LOW);
}
if(digitalRead(DIR_BTN2)&&!digitalRead(DIR_BTN1))
  {
    digitalWrite(EN, LOW);
    digitalWrite(DIR,LOW);
    digitalWrite(LEDFW, HIGH);
    digitalWrite(LEDBACK, LOW);
    stepval=analogRead(STP_ADC);
    stepfun();
    
  }
   else if(digitalRead(DIR_BTN1)&&!digitalRead(DIR_BTN2))
  {
    digitalWrite(EN, LOW);
    digitalWrite(DIR,HIGH);
    digitalWrite(LEDBACK, HIGH);
    digitalWrite(LEDFW, LOW);
    stepval=analogRead(STP_ADC);
    stepfun();
    
  }
  else if(digitalRead(DIR_BTN2)&&digitalRead(DIR_BTN1))
  {
    digitalWrite(EN, HIGH);
    digitalWrite(LEDBACK, LOW);
    digitalWrite(LEDFW, LOW);
    
  }
  else if(!digitalRead(DIR_BTN2)&&!digitalRead(DIR_BTN1))
  {
    digitalWrite(EN, HIGH);
    digitalWrite(LEDBACK, LOW);
    digitalWrite(LEDFW, LOW);
    
  }          



}

void power()
{
  if(digitalRead(PWRBTN))
{
  digitalWrite(PWR, HIGH);
  digitalWrite(LEDPWR,HIGH);  
}
else
{
  digitalWrite(PWR, LOW);
  digitalWrite(LEDPWR, LOW);
}


}

void motordrive()
{
  if(digitalRead(DIR_BTN2)&&!digitalRead(DIR_BTN1))
  {
    digitalWrite(EN, LOW);
    digitalWrite(DIR,LOW);
    digitalWrite(LEDFW, HIGH);
    digitalWrite(LEDBACK, LOW);
    //stepval=analogRead(STP_ADC);
   // stepfun();
    
  }
   else if(digitalRead(DIR_BTN1)&&!digitalRead(DIR_BTN2))
  {
    digitalWrite(EN, LOW);
    digitalWrite(DIR,HIGH);
    digitalWrite(LEDBACK, HIGH);
    digitalWrite(LEDFW, LOW);
    //stepval=analogRead(STP_ADC);
   // stepfun();
    
  }
  else if(digitalRead(DIR_BTN2)&&digitalRead(DIR_BTN1))
  {
    digitalWrite(EN, HIGH);
    digitalWrite(LEDBACK, LOW);
    digitalWrite(LEDFW, LOW);
    
  }
  else if(!digitalRead(DIR_BTN2)&&!digitalRead(DIR_BTN1))
  {
    digitalWrite(EN, HIGH);
    digitalWrite(LEDBACK, LOW);
    digitalWrite(LEDFW, LOW);
    
  }
}

void stepfun()
{
  int stepuse=stepval+1; //avoid divide by 0
  
  digitalWrite(STP, HIGH);      //Pulse signal output high level
  delayMicroseconds(stepuse);           //delay 100μs
  digitalWrite(STP, LOW);       //Pulse signal output low level
 delayMicroseconds(stepuse);           //delay 100μs
}
