int leftForward = 6; 
int leftBackward = 9; 
int rightForward = 10; 
int rightBackward = 11;

int led1 = 5;
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
    digitalWrite(leftForward,255);
    digitalWrite(leftBackward,0);
    digitalWrite(rightForward,0);
    digitalWrite(rightBackward,255);
    }
  
    else if (val == 'Q')
    {
    Serial.println("SLOW FORWARD");
    digitalWrite(leftForward,50);
    digitalWrite(leftBackward,0);
    digitalWrite(rightForward,0);
    digitalWrite(rightBackward,50);
    }
  
    /*********For Backward Motion*********/
    else if(val == 'B')
    {
    Serial.println("BACK");
    digitalWrite(leftForward,0);
    digitalWrite(leftBackward,255);
    digitalWrite(rightForward,255);
    digitalWrite(rightBackward,0);
    }

    else if(val == 'W')
    {
    Serial.println("SLOW BACK");
    digitalWrite(leftForward,0);
    digitalWrite(leftBackward,50);
    digitalWrite(rightForward,50);
    digitalWrite(rightBackward,0);
    }
  
    /*********Right*********/
    else if(val == 'R')
    {
    Serial.println("RIGHT");
    digitalWrite(leftForward,0);
    digitalWrite(leftBackward,255);
    digitalWrite(rightForward,0);
    digitalWrite(rightBackward,255);
    }

    else if(val == 'T')
    {
    Serial.println("SLOW RIGHT");
    digitalWrite(leftForward,0);
    digitalWrite(leftBackward,50);
    digitalWrite(rightForward,0);
    digitalWrite(rightBackward,50);
    }
  
    /*********Left*********/
    else if(val == 'L')
    {
    Serial.println("LEFT");
    digitalWrite(leftForward,255);
    digitalWrite(leftBackward,0);
    digitalWrite(rightForward,255);
    digitalWrite(rightBackward,0);
    }

    else if(val == 'E')
    {
    Serial.println("SLOW LEFT");
    digitalWrite(leftForward,50);
    digitalWrite(leftBackward,0);
    digitalWrite(rightForward,50);
    digitalWrite(rightBackward,0);
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
