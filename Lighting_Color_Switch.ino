const int buttonPin = 2;
const int redPin = 3;
const int grePin = 4;
const int bluPin = 5;

int switchNum = 0;

void setup() 
{ 

    pinMode(buttonPin, INPUT); 

    pinMode(redPin, OUTPUT); 
    pinMode(grePin, OUTPUT); 
    pinMode(bluPin, OUTPUT); 
} 

void loop() 
{ 
    int buttonState = digitalRead(buttonPin); 


    if(buttonState == HIGH)
    {
        if(switchNum < 8)
            switchNum ++;
        else
            switchNum = 0;

        delay(100);
    }

    if(switchNum == 0)
    {
        digitalWrite(redPin, HIGH); 
        digitalWrite(grePin, HIGH); 
        digitalWrite(bluPin, HIGH); 
    }

    if(switchNum == 1) // Red
    {
        digitalWrite(redPin, LOW);
        digitalWrite(bluPin, HIGH); 
        digitalWrite(redPin, HIGH); 
    } 

    if(switchNum == 2) // Green
    {
        digitalWrite(redPin, HIGH);
        digitalWrite(bluPin, LOW); 
        digitalWrite(redPin, HIGH); 
    }

    if(switchNum == 3) // Blue
    {
        digitalWrite(redPin, HIGH);
        digitalWrite(bluPin, HIGH); 
        digitalWrite(redPin, LOW); 
    }

    if(switchNum == 4)
    {
        digitalWrite(redPin, LOW); 
        digitalWrite(grePin, LOW);
        digitalWrite(bluPin, HIGH); 
    }

    if(switchNum == 5) // Purple
    {
        digitalWrite(redPin, LOW); 
        digitalWrite(bluPin, LOW); 
        digitalWrite(grePin, HIGH); 
    }

    if(switchNum == 6) // Cyan
    {
        digitalWrite(grePin, LOW); 
        digitalWrite(bluPin, LOW); 
        digitalWrite(redPin, HIGH); 
    }

    if(switchNum == 7) // White
    {
        digitalWrite(redPin, LOW); 
        digitalWrite(grePin, LOW); 
        digitalWrite(bluPin, LOW); 
    }
    
    /*if(buttonState == HIGH) 
    { 
        digitalWrite(redPin, LOW); 
        digitalWrite(grePin, LOW); 
        digitalWrite(bluPin, LOW); 
    } 
    else 
    { 
        digitalWrite(redPin, HIGH); 
        digitalWrite(grePin, HIGH); 
        digitalWrite(bluPin, HIGH); 
    } */
}