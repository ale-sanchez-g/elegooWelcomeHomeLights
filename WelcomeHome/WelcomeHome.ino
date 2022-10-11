const int bluePin = 7;
const int redPin = 12;
const int yellowPin = 8;

const int inputPin = 2;

void setup()
{
  pinMode(bluePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);

  pinMode(inputPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int value = digitalRead(inputPin);
  Serial.println("Motion Sensor value: " + String(value));

  if (value == HIGH)
  {

    // Light show sequence
    const int SIZE = 12;
    int prices[SIZE] = {1, 3, 3, 2, 1, 1, 1, 3, 3, 2, 1, 1};
    int color[SIZE] = {bluePin, redPin, redPin, yellowPin, bluePin, bluePin, bluePin, redPin, redPin, yellowPin, bluePin, bluePin};

    // Repease the light show 3 times
    for (int j = 0; j < 3; j++)
    {      
      Serial.println("Round : " + String(j));

      // Light show
      for (int i = 0; i < SIZE; i++)
      {

        digitalWrite(color[i], HIGH);
        delay(prices[i] * 100);

        digitalWrite(color[i], LOW);
        Serial.println("delay time " + String(prices[i]));
      }
      
    }
    // Alert to the user about exit loop 
    for (int j = 0; j < 3; j++)
    {
      Serial.println("Exiting Now ------ bye");

      digitalWrite(bluePin, HIGH);
      digitalWrite(redPin, HIGH);
      digitalWrite(yellowPin, HIGH);
      delay(1000);
      digitalWrite(bluePin, LOW);
      digitalWrite(redPin, LOW);
      digitalWrite(yellowPin, LOW);
      delay(1000);

    }
  }

  delay(500);
}