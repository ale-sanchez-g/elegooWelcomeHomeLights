const int bluePin = 13;
const int redPin = 12;
const int yellowPin = 9;

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
  int r = rand();
  digitalWrite(bluePin, LOW);

  int value = digitalRead(inputPin);
  Serial.println("Motion Sensor value: " + String(value));

  if (value == HIGH)
  {

    const int SIZE = 12;
    int prices[SIZE] = {1, 3, 3, 0, 1, 1, 1, 3, 3, 0, 1, 1};
    int color[SIZE] = {'bluePin', 'redPin', 'redPin', 'yellowPin', 'bluePin', 'bluePin', 'bluePin', 'redPin', 'redPin', 'yellowPin', 'bluePin', 'bluePin'};


    for (int i = 0; i < SIZE; i++)
    {

      digitalWrite(color[i], HIGH);
      delay(prices[i] * 100);

      digitalWrite(color[i], LOW);
      delay(1000);
      Serial.println("delay time " + String(prices[i]));
    }
  }

  digitalWrite(bluePin, LOW);
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);

}