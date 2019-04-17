int PIRSensor =D0;
int state = 0;
char buff [16];
int motion = 0;

void setup() {
  
    pinMode(D7,OUTPUT);
    pinMode(PIRSensor,INPUT);
    
}

void loop() {
  
    motion = digitalRead(PIRSensor);
    
    if (motion == HIGH) {
      
        digitalWrite(D7,HIGH);
        sprintf(buff,"%d",motion);
        const char* motion = buff;
        Particle.publish("motion-detected",motion,PRIVATE);
        delay(30000);
        
    }
    else if (motion == LOW) {
        digitalWrite(D7,LOW);
    }
}
