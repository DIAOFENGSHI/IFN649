#define LEDREDPIN 12
#define LEDGREENPIN 13
#define LEDYELLOWPIN 14

char r[]="LED_RED_ON";
char y[]="LED_YELLOW_ON";

void setup() { 
// Setup serial for monitor and Setup Serial1 for BlueTooth 
  Serial.begin(9600); 
  Serial1.begin(9600); 
  pinMode(LEDREDPIN, OUTPUT); 
  pinMode(LEDGREENPIN, OUTPUT); 
  pinMode(LEDYELLOWPIN, OUTPUT); 
}

void green(){
  Serial.println("g");
  digitalWrite(LEDGREENPIN, HIGH);
  digitalWrite(LEDYELLOWPIN, LOW);
  digitalWrite(LEDREDPIN, LOW);
  }
  void red(){
  digitalWrite(LEDGREENPIN, LOW);
  Serial.println("red");
  digitalWrite(LEDREDPIN, HIGH);
  }
  void yellow(){
    Serial.println("ye");
  digitalWrite(LEDGREENPIN, LOW);
  digitalWrite(LEDYELLOWPIN, HIGH);
 
  }

  void turnoff(){
    digitalWrite(LEDGREENPIN, LOW);
    digitalWrite(LEDYELLOWPIN, LOW);
    digitalWrite(LEDREDPIN, LOW);
  }
void loop() { 
  // Process commands from bluetooth first.
   turnoff();
   
  if(Serial1.available() > 0){ 
//    String str = Serial1.readString().substring(0); 
    String str = Serial1.readString();
    Serial.println(str);
 if(str == "LED_RED_ON"){
    red();
    delay(5000);
    Serial.println(str);
  }
 if(str == "LED_GREEN_ON"){
  Serial.println(str);
    green();
    delay(5000);
  }
 
 if(str == "LED_YELLOW_ON"){
  Serial.println(str);
    yellow();
    delay(5000);
  }


  
  
} 

}
