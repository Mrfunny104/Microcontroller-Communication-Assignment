int button1 = 2;//Forward
int button2 = 3;//Backward
int button3 = 4;//Left
int button4 = 5;//Right
int button5 = 6;//STOP

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;

void setup()
{
  //begin serial communication
    Serial.begin(9600);
    
    pinMode(button1,INPUT);
    pinMode(button2,INPUT);
    pinMode(button3,INPUT);
    pinMode(button4,INPUT);
    pinMode(button5,INPUT);
  
    delay(3000);

}

void loop()
{
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);
  buttonState3 = digitalRead(button3);
  buttonState4 = digitalRead(button4);
  buttonState5 = digitalRead(button5);
  
  if (buttonState1 == HIGH)
  {
    Serial.write('F');
  }
  
  if (buttonState2 == HIGH)
  {
    Serial.write('B');
  }
  
  if (buttonState3 == HIGH)
  {
    Serial.write('L');
  }
  
  if (buttonState4 == HIGH)
  {
    Serial.write('R');
  }
  
  if (buttonState5 == HIGH)
  {
    Serial.write('STOP');
  }
}
