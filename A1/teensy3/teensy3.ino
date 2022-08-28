#define LEDGREENPIN 18
#define LEDREDPIN 19
#define LEDYELLOWPIN 20
#define BUZZER 21
#define G 17
#define F 16
#define A 15
#define B 14
#define E 0
#define D 1
#define C 2
#define DP 3

void toOne(){
  digitalWrite(A, LOW);
  digitalWrite(G, LOW);
  digitalWrite(E, LOW);
  digitalWrite(D, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}
void toTwo(){
  digitalWrite(C, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(D, HIGH);
}

void setup() {
  Serial.begin(9600); 
  Serial1.begin(9600); 
  pinMode(LEDREDPIN, OUTPUT); 
  pinMode(LEDGREENPIN, OUTPUT); 
  pinMode(LEDYELLOWPIN, OUTPUT); 
  pinMode(BUZZER, OUTPUT); 
}

void loop() {
//  while(initial){
//    waitOrder();
//    if(Serial.available()>0 or Serial1.available()>0){
//      break;
//    }
//  }
  
  if(Serial.available()>0 or Serial1.available()>0){
    
    String order = Serial.readString();
    String order1 = Serial1.readString();
    Serial.println(order);
    Serial.println(order1);

    if(order1 == "DANGER1"){
      toOne();
      digitalWrite(LEDGREENPIN, LOW);
      digitalWrite(LEDYELLOWPIN, LOW);
      digitalWrite(LEDREDPIN, HIGH);
      digitalWrite(BUZZER, HIGH);
      }
    if(order1 == "WARNING1"){
      toOne();
      digitalWrite(LEDGREENPIN, LOW);
      digitalWrite(LEDREDPIN, LOW);
      digitalWrite(LEDYELLOWPIN, HIGH);
    }
    if(order1 == "SAFE1"){
      toOne();
      digitalWrite(LEDGREENPIN, HIGH);
      digitalWrite(LEDYELLOWPIN, LOW);
      digitalWrite(LEDREDPIN, LOW);
      digitalWrite(BUZZER, LOW);
    }
    if(order1 == "DANGER2"){
      toTwo();
      digitalWrite(LEDGREENPIN, LOW);
      digitalWrite(LEDYELLOWPIN, LOW);
      digitalWrite(LEDREDPIN, HIGH);
      digitalWrite(BUZZER, HIGH);
      }
    if(order1 == "WARNING2"){
      toTwo();
      digitalWrite(LEDGREENPIN, LOW);
      digitalWrite(LEDREDPIN, LOW);
      digitalWrite(LEDYELLOWPIN, HIGH);
    }
    if(order1 == "SAFE2"){
      toTwo();
      digitalWrite(LEDGREENPIN, HIGH);
      digitalWrite(LEDYELLOWPIN, LOW);
      digitalWrite(LEDREDPIN, LOW);
      digitalWrite(BUZZER, LOW);
    }
  }
}


void waitOrder(){
  digitalWrite(LEDGREENPIN, HIGH);
  delay(500);
  digitalWrite(LEDGREENPIN, LOW);
  digitalWrite(LEDREDPIN, HIGH);
  delay(500);
  digitalWrite(LEDREDPIN, LOW);
  digitalWrite(LEDYELLOWPIN, HIGH);
  delay(500);
  digitalWrite(LEDYELLOWPIN, LOW);
}
