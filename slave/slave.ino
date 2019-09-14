#define BAUD 9600

int pwm_a = 6;  //PWM control 
int pwm_b = 9;  
int pwm_c = 5;
int pwm_d = 3;

int dir_a = 7;  //Motore posteriore destro
int dir_b = 8;  //Motore anteriore destro
int dir_c = 11; //Motore posteriore sinistro
int dir_d = 10; //Motore anteriore sinistro




void setup(){

  Serial.begin(BAUD);
  while(!Serial);
  
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(pwm_a, OUTPUT);  //Set control pins to be outputs
  pinMode(pwm_b, OUTPUT);
  pinMode(pwm_c, OUTPUT);
  pinMode(pwm_d, OUTPUT);
  
  pinMode(dir_a, OUTPUT);
  pinMode(dir_b, OUTPUT);
  pinMode(dir_c, OUTPUT);
  pinMode(dir_d, OUTPUT);

  setVelocity(0);

}

void loop(){
  
  String data = "";
 

  while(Serial.available() > 0){
    data = Serial.readString();
  
    if(data == "dritto"){
        digitalWrite(dir_a, HIGH);
        digitalWrite(dir_b, HIGH);
        digitalWrite(dir_c, HIGH); 
        digitalWrite(dir_d, HIGH);
        Serial.println("Vado dritto");
    }
    
    else if(data == "destra"){
        digitalWrite(dir_a, LOW);   //ruote di destra
        digitalWrite(dir_b, LOW);
        digitalWrite(dir_c, HIGH); 
        digitalWrite(dir_d, HIGH);
        Serial.println("Svolto a destra");

    }
    
    else if(data == "sinistra"){
        digitalWrite(dir_a, HIGH);
        digitalWrite(dir_b, HIGH);
        digitalWrite(dir_c, LOW); //ruote di sinistra  
        digitalWrite(dir_d, LOW);  
        Serial.println("Svolto a sinistra");
    }

    else if(data == "retro"){
        digitalWrite(dir_a, LOW);
        digitalWrite(dir_b, LOW);
        digitalWrite(dir_c, LOW); //ruote di sinistra  
        digitalWrite(dir_d, LOW);  
        Serial.println("Torno indietro");
    }
    
    else if(data.toInt() >= 90 && data.toInt() <= 255){
        setVelocity(data.toInt());
        Serial.println("cambiata velocità a: " + data);
    }
    
    else if(data == "spegni"){
        setVelocity(0);
        Serial.println("Spengo i motori");
    }
    
    else if(data == "accendi"){
        setVelocity(230);
        Serial.println("Accendo i motori");
    } 
    
    else {
      Serial.println("Comando non riconosciuto: " + data);
    }
  }
}


//inserire solo velocità tra 190 e 255, altrimenti la funzione non cambierà lo stato del motore
void setVelocity(int v){

  if((v < 90 && v != 0) || v > 255)
    return;

  analogWrite(pwm_a, v);  
  analogWrite(pwm_b, v);  //minimo 190 o non partono wewo
  analogWrite(pwm_c, v);
  analogWrite(pwm_d, v);

  return;
}
