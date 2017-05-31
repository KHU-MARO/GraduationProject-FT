
+#include <SoftwareSerial.h>

SoftwareSerial btSerial(2, 3);
int relay1 = 8; //릴레이1 핀설정
int relay2 = 9; //릴레이2 핀설정
int relay3 = 10; //릴레이3 핀설정
int relay4 = 11;

void setup() {
  pinMode (relay1, OUTPUT); // relay1를 output으로 설정한다.
  pinMode (relay2, OUTPUT); // relay2를 output으로 설정한다.
  pinMode (relay3, OUTPUT); // relay3를 output으로 설정한다.
  pinMode (relay4, OUTPUT); // relay4를 output으로 설정한다.
  
  
  //시작시 릴레이를 OFF 로 설정
  digitalWrite (relay1, HIGH);
  digitalWrite (relay2, HIGH);
  digitalWrite (relay3, HIGH);
  digitalWrite (relay4, HIGH);
  Serial.begin(9600);
  
  btSerial.begin(9600);// set the data rate for the BT port
}

void TurnOff()
{
  digitalWrite (relay1, HIGH);
  digitalWrite (relay2, HIGH);
  digitalWrite (relay3, HIGH);
  digitalWrite (relay4, HIGH);  
}

void TurnOn(char data)
{
 
  if(data < '4')
  {
    if(data<'2')
    {
      TurnOff();
       digitalWrite(relay_l1, LOW);   // set the LED on
      Serial.println("1");      
    }
    else if(data>'2')
    {
      TurnOff();
      digitalWrite(relay_l3, LOW);    // set the LED off
      Serial.println("3");
    }
    else
    {
      TurnOff();
      digitalWrite(relay_l2, LOW);    // set the LED off
      Serial.println("2");
    } 
 
  }
  else if(data >'4')
  {
    if(data<'6')
    {
      TurnOff();
      digitalWrite(relay_r1, LOW);   // set the LED on
      Serial.println("5");     
    }
    else if(data>'6')
    {
      if(data>'7')
      {
        TurnOff();
        digitalWrite(relay_r4, LOW);    // set the LED off
        Serial.println("8");
      }
      else
      {
        TurnOff();
        digitalWrite(relay_r3, LOW);    // set the LED off
        Serial.println("7");
      }
 
    }
    else
    {
      TurnOff();
      digitalWrite(relay_r2, LOW);    // set the LED off
      Serial.println("6"); 
    }
  }  
  else
  {
    TurnOff();
    digitalWrite(relay_l4, LOW);    // set the LED off
     Serial.println("4"); 
  }
}


void loop() 
{
    byte data;
    data = btSerial.read();
    if( data = 'off')
    {
      TurnOff();
    }
    else
    {
      TurnOn(data);
    }
}
