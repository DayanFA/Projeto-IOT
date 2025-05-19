#define TEMP_SENSOR A0
#define SOIL_MOISTURE_SENSOR A1
#define LED1 4
#define LED2 2
#define BUTTON 5

bool systemArmed = true;
int lastButtonState = LOW;

void setup()
{
  pinMode(TEMP_SENSOR, INPUT);
  pinMode(SOIL_MOISTURE_SENSOR, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP); 
  Serial.begin(9600);
}

void loop()
{
  int buttonState = digitalRead(BUTTON);
  
  if (buttonState == HIGH && lastButtonState == LOW) {
    delay(50); 
    if (digitalRead(BUTTON) == HIGH) {
      systemArmed = !systemArmed; 
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
    }
  }
  
  lastButtonState = buttonState;
  
  if (systemArmed) {
    int moist = analogRead(SOIL_MOISTURE_SENSOR);
    float moistp = ((moist/1023.00)*100);
    Serial.print("Umidade = ");
    Serial.print(moistp);
    Serial.print("%\n");

    if (moistp > 35.0) 
    {
      digitalWrite(LED2, HIGH);
    }
    else
    {
      digitalWrite(LED2, LOW);
    }

    int temp = analogRead(TEMP_SENSOR);
    float celsius = map(((temp - 20) * 3.04), 0, 1023, -40, 125);
    float fahrenheit = ((celsius * 9) / 5 + 32);
    Serial.print(celsius);
    Serial.print(" C, ");
    Serial.print(fahrenheit);
    Serial.println(" F");

    if (celsius >= 35 ) 
    {
      digitalWrite(LED1, HIGH);
    }
    else
    {
      digitalWrite(LED1, LOW);
    }
  }
  
  delay(1000);
}