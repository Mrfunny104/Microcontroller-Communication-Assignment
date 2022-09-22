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

    /******HORN********/
    if (horn == LOW)
    { 
      Serial.write('H');
    }

    /******FORWARDS********/
    if (X_val > 850 )
    {
      Serial.write('F');
    }
    //slow
    if (X_val > 600 && X_val < 850)
    {
      Serial.write('Q');
    }

    /******BACKWARDS********/
    if (X_val < 250)
    {
      Serial.write('B');
    }
    //slow
    if (X_val < 400 && X_val > 250)
    {
      Serial.write('W');
    }

    /******LEFT********/
    if (Y_val < 250)
    {
      Serial.write('L');
    }
    //slow
    if (Y_val < 400 && Y_val > 250)
    {
      Serial.write('E');
    }
    
    /******RIGHT********/
    if (Y_val > 850)
    {
      Serial.write('R');
    }
    //slow
    if (Y_val > 600 && Y_val < 850)
    {
      Serial.write('T');
    }
    
    /******STOP********/
    if (X_val < 600 && X_val >400 and Y_val < 600 && Y_val >400 )
    {
      Serial.write('STOP');
    }


  /**************************
   *     Button Commands    *
   *************************/
   
   if (buttonState1 == HIGH)
    {
      Serial.write('G');
    }
    
    if (buttonState2 == HIGH)
    {
      Serial.write('M');
    }
    
    if (buttonState3 == HIGH)
    {
      Serial.write('J');
    }
}
