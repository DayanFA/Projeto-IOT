int redPin=0;
int bluePin =10;
int greenPin=2;
int red_led = 4;
int green_led = 5;
#define ledgreen 7
#define ledred 6
#define buttom 3
int yellow_led = 9;
int red2_led = 8;
int green2_led = 11;
int led2green= 12;
int led2red= 1;
int Leitura = 0;

void setup() {

pinMode(redPin,OUTPUT);
pinMode(greenPin,OUTPUT);
pinMode(bluePin,OUTPUT);
pinMode(red_led,OUTPUT);
pinMode(green_led,OUTPUT);
pinMode(ledgreen,OUTPUT);
pinMode(ledred,OUTPUT);
pinMode(yellow_led,OUTPUT);
pinMode(red2_led,OUTPUT);
pinMode(green2_led,OUTPUT);
pinMode(led2green,OUTPUT);
pinMode(led2red,OUTPUT);
pinMode(buttom,INPUT);

}
void loop() {
Leitura= digitalRead(buttom);
if(Leitura == HIGH) {
digitalWrite(red_led,HIGH );
digitalWrite(ledgreen,HIGH );
digitalWrite(red2_led,HIGH );
digitalWrite(green2_led,LOW );
digitalWrite(led2green,HIGH );
digitalWrite(led2red,LOW );

delay(10000);
}

else {
digitalWrite(red_led,LOW);
digitalWrite(green_led,HIGH);
digitalWrite(ledred,HIGH );
digitalWrite(ledgreen,LOW );
digitalWrite(redPin,LOW);
digitalWrite(greenPin,LOW);
digitalWrite(bluePin,LOW);
digitalWrite(red2_led,HIGH);
digitalWrite(green2_led,LOW);
digitalWrite(led2red,LOW );
digitalWrite(led2green,HIGH );
digitalWrite(yellow_led,LOW);
delay(4000);
digitalWrite(red_led,LOW);
digitalWrite(green_led,LOW);
digitalWrite(ledred,HIGH );
digitalWrite(ledgreen,LOW );
digitalWrite(redPin,255);
digitalWrite(greenPin,255);
digitalWrite(bluePin,0);
digitalWrite(red2_led,LOW);

digitalWrite(green2_led,LOW);
digitalWrite(led2red,HIGH );
digitalWrite(led2green,LOW );
digitalWrite(yellow_led,HIGH);
delay(2000);
digitalWrite(red_led,HIGH );
digitalWrite(green_led,LOW);
digitalWrite(ledred,LOW );
digitalWrite(ledgreen,HIGH );
digitalWrite(redPin,LOW);
digitalWrite(greenPin,LOW);
digitalWrite(bluePin,LOW);
digitalWrite(red2_led,LOW );
digitalWrite(green2_led,HIGH);
digitalWrite(led2red,HIGH );
digitalWrite(led2green,LOW );
digitalWrite(yellow_led,LOW);
delay(4000);
}
}