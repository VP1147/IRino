int Sensor = A0;
int speaker = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(speaker, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(int(analogRead(Sensor)));
  tone(speaker, analogRead(Sensor)*10, 10);
}
