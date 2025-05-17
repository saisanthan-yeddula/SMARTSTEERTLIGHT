int IR1 = 8;
int IR2 = 12;
int IR3 = 9;
int IR4 = 10;

int LDR = 7;

int led1 = 11;
int led2 = 5;
int led3 = 6;
int led4 = 3;

int val1;
int val2;
int val3;
int val4;

char command;
boolean autoMode = true;
boolean manualMode1 = true;
boolean manualMode2 = true;

void setup(){
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);
  pinMode(LDR, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);  
  Serial.begin(9600); 
}

void loop() {
  val1 = digitalRead(IR1);
  val2 = digitalRead(IR2);
  val3 = digitalRead(IR3);
  val4 = digitalRead(IR4);
  int ldrVal = digitalRead(LDR);
  if (autoMode)
  {
    if (val1 == 1 && ldrVal == 0 && val2 == 1 && val3 == 1 && val4 == 1)
   {
     digitalWrite(led1, LOW);
     digitalWrite(led2, LOW);
     digitalWrite(led3, LOW);
     digitalWrite(led4, LOW);
   }
   else if (val1 == 1 && ldrVal == 1 && val2 == 1 && val3 == 1 && val4 == 1)
   {
     analogWrite(led1, 20);
     analogWrite(led2, 20);
     analogWrite(led3, 20);
     analogWrite(led4, 20);
   }
   else if (val1 == 0 && ldrVal == 1 && val2 == 1 && val3 == 1 && val4 == 1)
   {
     analogWrite(led1, 500);
     analogWrite(led2, 20);
     analogWrite(led3, 20);
     analogWrite(led4, 20);
   }
   else if (val1 == 1 && ldrVal == 1 && val2 == 0 && val3 == 1 && val4 == 1)
   {
     analogWrite(led1, 20);
     analogWrite(led2, 500);
     analogWrite(led3, 20);
     analogWrite(led4, 20);
   }
   else if (val1 == 1 && ldrVal == 1 && val2 == 1 && val3 == 0 && val4 == 1)
   {
     analogWrite(led1, 20);
     analogWrite(led2, 20);
     analogWrite(led3, 500);
     analogWrite(led4, 20);
   }
   else if (val1 == 1 && ldrVal == 1 && val2 == 1 && val3 == 1 && val4 == 0)
   {
     analogWrite(led1, 20);
     analogWrite(led2, 20);
     analogWrite(led3, 20);
     analogWrite(led4, 500);
   }
  }
  else if (manualMode1){
    if (val1 == 1 && ldrVal == 0 && val2 == 1 && val3 == 1 && val4 == 1)
   {
     digitalWrite(led1, LOW);
     digitalWrite(led2, LOW);
     digitalWrite(led3, LOW);
     digitalWrite(led4, LOW);
   }
   else if (val1 == 1 && ldrVal == 1 && val2 == 1 && val3 == 1 && val4 == 1)
   {
     analogWrite(led1, 20);
     analogWrite(led2, 0);
     analogWrite(led3, 20);
     analogWrite(led4, 0);
   }
   else if (val1 == 0 && ldrVal == 1 && val2 == 1 && val3 == 1 && val4 == 1)
   {
     analogWrite(led1, 500);
     analogWrite(led2, 0);
     analogWrite(led3, 20);
     analogWrite(led4, 0);
   }
   else if (val1 == 1 && ldrVal == 1 && val2 == 0 && val3 == 1 && val4 == 1)
   {
     analogWrite(led1, 20);
     analogWrite(led2, 500);
     analogWrite(led3, 20);
     analogWrite(led4, 0);
   }
   else if (val1 == 1 && ldrVal == 1 && val2 == 1 && val3 == 0 && val4 == 1)
   {
     analogWrite(led1, 20);
     analogWrite(led2, 0);
     analogWrite(led3, 500);
     analogWrite(led4, 0);
   }
   else if (val1 == 1 && ldrVal == 1 && val2 == 1 && val3 == 1 && val4 == 0)
   {
     analogWrite(led1, 20);
     analogWrite(led2, 0);
     analogWrite(led3, 20);
     analogWrite(led4, 500);
   }
  }
  else if (manualMode2){
    if (val1 == 1 && ldrVal == 0 && val2 == 1 && val3 == 1 && val4 == 1)
   {
     digitalWrite(led1, LOW);
     digitalWrite(led2, LOW);
     digitalWrite(led3, LOW);
     digitalWrite(led4, LOW);
   }
   else if (val1 == 1 && ldrVal == 1 && val2 == 1 && val3 == 1 && val4 == 1)
   {
     analogWrite(led1, 0);
     analogWrite(led2, 20);
     analogWrite(led3, 0);
     analogWrite(led4, 20);
   }
   else if (val1 == 0 && ldrVal == 1 && val2 == 1 && val3 == 1 && val4 == 1)
   {
     analogWrite(led1, 500);
     analogWrite(led2, 20);
     analogWrite(led3, 0);
     analogWrite(led4, 20);
   }
   else if (val1 == 1 && ldrVal == 1 && val2 == 0 && val3 == 1 && val4 == 1)
   {
     analogWrite(led1, 0);
     analogWrite(led2, 500);
     analogWrite(led3, 0);
     analogWrite(led4, 20);
   }
   else if (val1 == 1 && ldrVal == 1 && val2 == 1 && val3 == 0 && val4 == 1)
   {
     analogWrite(led1, 0);
     analogWrite(led2, 20);
     analogWrite(led3, 500);
     analogWrite(led4, 20);
   }
   else if (val1 == 1 && ldrVal == 1 && val2 == 1 && val3 == 1 && val4 == 0)
   {
     analogWrite(led1, 0);
     analogWrite(led2, 20);
     analogWrite(led3, 0);
     analogWrite(led4, 500);
   }
  }
  if (Serial.available() > 0) {
    command = Serial.read();
    executeCommand(command);
  }
}
void executeCommand(char command) {
  if (command == '1') {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    Serial.println("LEDs turned ON");
    autoMode = false; 
    manualMode1 = false;
    manualMode2 = false;
  } else if (command == '2') {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    Serial.println("LEDs turned OFF");
    autoMode = false; 
    manualMode1 = false;
    manualMode2 = false;
  } else if (command == '3') {
    Serial.println("Custom Command 3 executed");
    autoMode = true;
    manualMode1 = false;
    manualMode2 = false;
  }else if (command == '4'){
    Serial.println("Custom Command 4 executed");
    autoMode = false;
    manualMode1 = true;
    manualMode2 = false;     
  }
  else if (command == '5'){
    Serial.println("Custom Command 5 executed");
    autoMode = false;
    manualMode1 = false;
    manualMode2 = true;
  }
}
