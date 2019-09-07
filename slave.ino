int pwm_a = 6;  //PWM control for motor outputs 1 and 2
int pwm_b = 9;  //PWM control for motor outputs 3 and 4
int pwm_c = 5;
int pwm_d = 3;

int dir_a = 7;  //direction control for motor outputs 1 and 2
int dir_b = 8;  //direction control for motor outputs 3 and 4
int dir_c = 11;
int dir_d = 10;




void setup(){

  Serial.begin(9600);
  while(!Serial);
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(pwm_a, OUTPUT);  //Set control pins to be outputs
  pinMode(pwm_b, OUTPUT);
  pinMode(dir_a, OUTPUT);
  pinMode(dir_b, OUTPUT);
  pinMode(pwm_c, OUTPUT);
  pinMode(pwm_d, OUTPUT);
  pinMode(dir_c, OUTPUT);
  pinMode(dir_d, OUTPUT);

  setVelocity(200);

}

void loop()
{
  digitalWrite(dir_a, HIGH);
  digitalWrite(dir_b, HIGH);
  digitalWrite(dir_c, LOW); //cavo invertito (mannaggia a te)
  digitalWrite(dir_d, HIGH);

  String data = Serial.readString();

  if(data == "destra"){
      digitalWrite(dir_a, LOW);   //ruote di destra
      digitalWrite(dir_b, LOW);
      digitalWrite(dir_c, LOW); //cavo invertito (mannaggia a te)
      digitalWrite(dir_d, HIGH);
  } else if (data == "sinistra"){
      digitalWrite(dir_a, HIGH);
      digitalWrite(dir_b, HIGH);
      digitalWrite(dir_c, HIGH); //ruote di sinistra  //cavo invertito (mannaggia a te)
      digitalWrite(dir_d, LOW);
  } else if( toInt(data) >= 190 && toInt(data) <= 255){
      setVelocity(toInt(s));
  } else if(data == "spegni"){
      setVelocity(0);
  } else if(data == "accendi"){
      setVelocity(190);
  }
}

//inserire solo velocità tra 190 e 255, altrimenti la funzione non cambierà lo stato del motore
void setVelocity(int v){

  if((v < 190 && v != 0) || v > 255)
    return;

  analogWrite(pwm_a, v);  //set both motors to run at (100/255 = 39)% duty cycle (slow)
  analogWrite(pwm_b, v);  //minimo 190 o non partono wewo
  analogWrite(pwm_c, v);
  analogWrite(pwm_d, v);

  return;
}
