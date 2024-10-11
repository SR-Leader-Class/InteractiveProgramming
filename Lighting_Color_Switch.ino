const int buttonPin = 2;
const int redPin = 3;
const int grePin = 4;
const int bluPin = 5;
const long interval = 1000;

int ledState = LOW, switchNum = 0;
unsigned long previousMillis = 0;
bool buttonPressed = false;
String currentColor = "None";

void setup() 
{ 
    Serial.begin(9600);

    pinMode(buttonPin, INPUT); // Button pin setup
    pinMode(redPin, OUTPUT); // LED pin setuup
    pinMode(grePin, OUTPUT); // LED pin setuup
    pinMode(bluPin, OUTPUT); // LED pin setuup
} 

void loop() 
{ 
    int buttonState = digitalRead(buttonPin); 
    Serial.print("Current color : ");
    Serial.println(currentColor);

    // --------------------------------------------------------
    if(buttonState == HIGH && buttonPressed == false)
    {
        switchNum ++;

        buttonPressed = true;
    }

    if(buttonState == LOW && buttonPressed == true)
        buttonPressed = false;

    // --------------------------------------------------------

    unsigned long currentMillis = millis();

    if(currentMillis - previousMillis >= interval) // Check if button pressed over 1s 
    {
        previousMillis = currentMillis;

        if(ledState == LOW) // Switch state
            ledState = true;
        else
            ledState = false;
    }

    if(switchNum == 0) // LED None
    {
        currentColor = "None";
        digitalWrite(redPin, HIGH); 
        digitalWrite(grePin, HIGH); 
        digitalWrite(bluPin, HIGH); 
    }

    if(switchNum == 1) // Red
    {
        currentColor = "Red";
        if(ledState == LOW)
        {
            digitalWrite(redPin, LOW);
            digitalWrite(bluPin, HIGH); 
            digitalWrite(redPin, HIGH);
        }
        else
        {
            digitalWrite(redPin, HIGH); 
            digitalWrite(grePin, HIGH); 
            digitalWrite(bluPin, HIGH);     
        }
    } 

    if(switchNum == 2) // Green
    {
        if(ledState == LOW)
        {
            currentColor = "Green";
            digitalWrite(redPin, HIGH);
            digitalWrite(bluPin, LOW); 
            digitalWrite(redPin, HIGH);
        }
        else
        {
            digitalWrite(redPin, HIGH); 
            digitalWrite(grePin, HIGH); 
            digitalWrite(bluPin, HIGH); 
        }
    }

    if(switchNum == 3) // Blue
    {
        if(ledState == LOW)
        {
          currentColor = "Blue";
          digitalWrite(redPin, HIGH);
          digitalWrite(bluPin, HIGH); 
          digitalWrite(redPin, LOW);
        }
        else
        {
            digitalWrite(redPin, HIGH); 
            digitalWrite(grePin, HIGH); 
            digitalWrite(bluPin, HIGH); 
        }
    }

    if(switchNum == 4)
    {
        if(ledState == LOW)
        {
            currentColor = "Yello";
            digitalWrite(redPin, LOW); 
            digitalWrite(grePin, LOW);
            digitalWrite(bluPin, HIGH);
        }
        else
        {
            digitalWrite(redPin, HIGH); 
            digitalWrite(grePin, HIGH); 
            digitalWrite(bluPin, HIGH); 
        }
    }

    if(switchNum == 5) // Purple
    {
        if(ledState == LOW)
        {
            currentColor = "Purple";
            digitalWrite(redPin, LOW); 
            digitalWrite(bluPin, LOW); 
            digitalWrite(grePin, HIGH); 
        }
        else
        {
            digitalWrite(redPin, HIGH); 
            digitalWrite(grePin, HIGH); 
            digitalWrite(bluPin, HIGH); 
        }
    }

    if(switchNum == 6) // Cyan
    {
        if(ledState == LOW)
        {
            currentColor = "Cyan";
            digitalWrite(grePin, LOW); 
            digitalWrite(bluPin, LOW); 
            digitalWrite(redPin, HIGH); 
        }
        else
        {
            digitalWrite(redPin, HIGH); 
            digitalWrite(grePin, HIGH); 
            digitalWrite(bluPin, HIGH); 
        }
    }

    if(switchNum == 7) // White
    {
       if(ledState == LOW)
        {
            currentColor = "White";
            digitalWrite(redPin, LOW); 
            digitalWrite(grePin, LOW); 
            digitalWrite(bluPin, LOW); 
        }
        else
        { 
            digitalWrite(redPin, HIGH); 
            digitalWrite(grePin, HIGH); 
            digitalWrite(bluPin, HIGH); 
        }
    }

    if(switchNum == 8)
        switchNum = 0;
}
