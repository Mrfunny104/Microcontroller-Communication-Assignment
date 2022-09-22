//this is slave
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11);


int leftForward = 6; 
int leftBackward = 2; 
int rightForward = 8; 
int rightBackward = 13;

int led1 = 7;
int led2 = 4;

void setup()
{
  //initlize the mode of the pins
    pinMode(leftForward , OUTPUT);
    pinMode(leftBackward , OUTPUT);
    pinMode(rightForward , OUTPUT);
    pinMode(rightBackward , OUTPUT);
    pinMode(12,OUTPUT);//buzzer
    pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
  
    //begin serial communication
    Serial.begin(9600);
    BTSerial.begin(38400);
}

void loop()
{
   if(BTSerial.available() > 0)
 { 
    // Checks whether data is comming from the serial port
    char val = BTSerial.read(); // Reads the data from the serial port
    Serial.print(val);
  
    /*********For Forward motion*********/
    if (val == 'F')
    {
    Serial.println("FORWARD");
    digitalWrite(leftForward,0);
    digitalWrite(leftBackward,255);
    digitalWrite(rightForward,255);
    digitalWrite(rightBackward,0);
    }
  
    else if (val == 'Q')
    {
    Serial.println("SLOW FORWARD");
    digitalWrite(leftForward,0);
    digitalWrite(leftBackward,50);
    digitalWrite(rightForward,50);
    digitalWrite(rightBackward,0);
    }
  
    /*********For Backward Motion*********/
    else if(val == 'B')
    {
    Serial.println("BACK");
    digitalWrite(leftForward,255);
    digitalWrite(leftBackward,0);
    digitalWrite(rightForward,0);
    digitalWrite(rightBackward,255);
    }

    else if(val == 'W')
    {
    Serial.println("SLOW BACK");
    digitalWrite(leftForward,50);
    digitalWrite(leftBackward,0);
    digitalWrite(rightForward,0);
    digitalWrite(rightBackward,50);
    }
  
    /*********Right*********/
    else if(val == 'R')
    {
    Serial.println("RIGHT");
    digitalWrite(leftForward,255);
    digitalWrite(leftBackward,0);
    digitalWrite(rightForward,255);
    digitalWrite(rightBackward,0);
    }

    else if(val == 'T')
    {
    Serial.println("SLOW RIGHT");
    digitalWrite(leftForward,50);
    digitalWrite(leftBackward,0);
    digitalWrite(rightForward,50);
    digitalWrite(rightBackward,0);
    }
  
    /*********Left*********/
    else if(val == 'L')
    {
    Serial.println("LEFT");
    digitalWrite(leftForward,0);
    digitalWrite(leftBackward,255);
    digitalWrite(rightForward,0);
    digitalWrite(rightBackward,255);
    }

    else if(val == 'E')
    {
    Serial.println("SLOW LEFT");
    digitalWrite(leftForward,0);
    digitalWrite(leftBackward,50);
    digitalWrite(rightForward,0);
    digitalWrite(rightBackward,50);
    }

    /********Horn**********/
    else if(val == 'H')
    {
    Serial.println("HONK");
    digitalWrite(12,HIGH);
    delay(1000);
    digitalWrite(12,LOW);
    }

    else if(val=='G')
    {
    Serial.println("Lights On");
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    }
    
    else if(val=='M')
    {
    Serial.println("Lights Out");
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    }

    else if(val=='J')
    {
    Serial.println("Look mummy no hands!");
    digitalWrite(leftForward,255);
    digitalWrite(leftBackward,0);
    digitalWrite(rightForward,255);
    digitalWrite(rightBackward,0);
    delay(3000);
    digitalWrite(leftForward,0);
    digitalWrite(leftBackward,255);
    digitalWrite(rightForward,0);
    digitalWrite(rightBackward,255);
    delay(3000);
    digitalWrite(leftForward,0);
    digitalWrite(leftBackward,0);
    digitalWrite(rightForward,0);
    digitalWrite(rightBackward,0);
    }
    
    /*********STOP*********/
    else
    {
    Serial.println("No data or Invalid!!!");
    digitalWrite(leftForward,0);
    digitalWrite(leftBackward,0);
    digitalWrite(rightForward,0);
    digitalWrite(rightBackward,0);
    digitalWrite(12,LOW);
    }
  }
}
