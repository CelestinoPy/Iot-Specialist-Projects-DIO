
#define LED 5
#define buzzer 6
#define sensor A0
#define motor 8
int x = 0;
int temp = 0;


void setup()
  
{
  Serial.begin(9600); 
  
  pinMode(LED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(motor, OUTPUT);
  pinMode(sensor, INPUT);
  
  digitalWrite(LED, LOW);
  digitalWrite(buzzer, LOW);
  digitalWrite(motor, LOW);
	
}

void loop()
{
  
  
  x = analogRead(sensor);
  temp = map(((x-20)*3.04),0,1023,-40,125);
  
  Serial.println(temp);
  
  if(temp<30){
    digitalWrite(LED, LOW);
  	digitalWrite(buzzer, LOW);
    digitalWrite(motor, LOW);}
  
  if (temp >= 30){
    digitalWrite(motor, HIGH);
    delay(1000);
  }if(temp >= 50){
    digitalWrite(motor, HIGH);
    digitalWrite(LED, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(1000);}
  
}