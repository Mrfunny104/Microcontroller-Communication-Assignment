//this is master
#include <SoftwareSerial.h>
int state = 0;
SoftwareSerial BTSerial(10, 11);

int button1 = 2;//Lights On
int button2 = 3;//Lights Off
int button3 = 4;//Trick 
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;

const int SW_pin = 7; // digital pin connected to switch output
const int X_pin = A2; // analog pin connected to X output
const int Y_pin = A3; // analog pin connected to Y output

void setup()
{
  //begin serial communication
    Serial.begin(9600);
    BTSerial.begin(38400);
    
    pinMode(button1,INPUT);
    pinMode(button2,INPUT);
    pinMode(button3,INPUT);
    pinMode(SW_pin, INPUT);
    digitalWrite(SW_pin, HIGH);
    
    delay(3000);
}

void loop()
{
    buttonState1 = digitalRead(button1);
    buttonState2 = digitalRead(button2);
    buttonState3 = digitalRead(button3);
    
    int X_val = analogRead(X_pin);
    int Y_val = analogRead(Y_pin);
    int horn = digitalRead(SW_pin);

    if(BTSerial.available() > 0)
    { 
    // Checks whether data is comming from the serial port
    state = BTSerial.read(); // Reads the data from the serial port
    } 

    /******HORN********/
    if (horn == LOW)
    { 
      BTSerial.write('H');
    }

    /******FORWARDS********/
    if (X_val > 850 )
    {
      BTSerial.write('F');
    }
    //slow
    if (X_val > 600 && X_val < 850)
    {
      BTSerial.write('Q');
    }

    /******BACKWARDS********/
    if (X_val < 250)
    {
      BTSerial.write('B');
    }
    //slow
    if (X_val < 400 && X_val > 250)
    {
      BTSerial.write('W');
    }

    /******LEFT********/
    if (Y_val < 250)
    {
      BTSerial.write('L');
    }
    //slow
    if (Y_val < 400 && Y_val > 250)
    {
      BTSerial.write('E');
    }
    
    /******RIGHT********/
    if (Y_val > 850)
    {
      BTSerial.write('R');
    }
    //slow
    if (Y_val > 600 && Y_val < 850)
    {
      BTSerial.write('T');
    }
    
    /******STOP********/
    if (X_val < 600 && X_val >400 and Y_val < 600 && Y_val >400 )
    {
      BTSerial.write('STOP');
    }


  /**************************
   *     Button Commands    *
   *************************/
   
    if (buttonState1 == HIGH)
    {
      BTSerial.write('G');
    }
    
    if (buttonState2 == HIGH)
    {
      BTSerial.write('M');
    }
    
    if (buttonState3 == HIGH)
    {
      BTSerial.write('J');
    }
}
