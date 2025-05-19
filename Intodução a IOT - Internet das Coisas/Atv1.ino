#define LDR A0
#define LED 2
#define BUTTON 3
#define Limiar 0.5

int Leitura = 0;
float Tensao;
bool buttonPressed = false;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(BUTTON) == HIGH) {
    buttonPressed = true;
  }
  
  if (buttonPressed) {
    digitalWrite(LED, HIGH);
  } else {
    Leitura = analogRead(LDR);
    Tensao = Leitura * (5.0/1024);
    Serial.println(Tensao);
    if ( Tensao >= Limiar ) 
    {
      digitalWrite(LED, HIGH);
    }
    else 
    {
      digitalWrite(LED, LOW);
    }
  }
}