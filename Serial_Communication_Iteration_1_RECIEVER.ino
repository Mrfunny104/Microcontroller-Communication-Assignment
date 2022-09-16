int leftForward = 8; 
int leftBackward = 9; 
int rightForward = 10; 
int rightBackward = 11;

void setup()
{
  //initlize the mode of the pins
    pinMode(leftForward , OUTPUT);
  pinMode(leftBackward , OUTPUT);
  pinMode(rightForward , OUTPUT);
  pinMode(rightBackward , OUTPUT);
  
    //begin serial communication
    Serial.begin(9600);
}

void loop()
{
    //check whether arduino is reciving signal or not 
   while(Serial.available() == 0);
   char val = Serial.read() ;//reads the signal
   Serial.print(val);
  
    /*********For Forward motion*********/
  if (val == 'F')
    {
    Serial.println("FORWARD");
    digitalWrite(leftForward,HIGH);
    digitalWrite(leftBackward,LOW);
    digitalWrite(rightForward,LOW);
    digitalWrite(rightBackward,HIGH);
  }
    
    /*********For Backward Motion*********/
    else if(val == 'B')
    {
  Serial.println("BACK");
    digitalWrite(leftForward,LOW);
    digitalWrite(leftBackward,HIGH);
    digitalWrite(rightForward,HIGH);
    digitalWrite(rightBackward,LOW);
    }
  
    /*********Right*********/
    else if(val == 'R')
    {
    Serial.println("RIGHT");
    digitalWrite(leftForward,LOW);
    digitalWrite(leftBackward,HIGH);
    digitalWrite(rightForward,LOW);
    digitalWrite(rightBackward,HIGH);
    }
  
    /*********Left*********/
    else if(val == 'L')
    {
    Serial.println("LEFT");
    digitalWrite(leftForward,HIGH);
    digitalWrite(leftBackward,LOW);
    digitalWrite(rightForward,HIGH);
    digitalWrite(rightBackward,LOW);
    }
  
    /*********STOP*********/
    else
    {
    Serial.println("No data or Invalid!!!");
    digitalWrite(leftForward,LOW);
    digitalWrite(leftBackward,LOW);
    digitalWrite(rightForward,LOW);
    digitalWrite(rightBackward,LOW);
    }
  
}
