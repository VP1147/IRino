int Sensor = A0;
int t = 1000;             // Reading per second
int Size = 500;
int data[500] = {};
int b_record = 5;
int b_reproduce = 6;
int led = 7;

void setup() {
  Serial.begin(9600);
  //pinMode(Sensor, INPUT);
  pinMode(b_record, INPUT);
  pinMode(b_reproduce, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  Serial.println(int(analogRead(Sensor)));
  
  if(digitalRead(b_record) == HIGH) {
    digitalWrite(led, HIGH);
    for(int d = 0; d < Size; d++) {
     data[d] = int(analogRead(Sensor));
     //Serial.println(data[d]);
     delay(int(1000/t));
    }
  }
  
  else if(digitalRead(b_reproduce) == HIGH) {
    for(int d = 0; d < Size; d++) { 
      analogWrite(led, int((data[d])));
      //Serial.println(data[d]);
      delay(1000/t); 
      }
  }
  else {
    digitalWrite(led, LOW);
    }
    
  //for(int p = 0; p <= Size; p++) { Serial.println(data[p]); }
}

