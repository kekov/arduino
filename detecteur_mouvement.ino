//the time we give the sensor to calibrate (10-60 secs according to the datasheet)
int calibrationTime = 30;


int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
unsigned long temps;


void setup() {
  pinMode(inputPin, INPUT);     // declare sensor as input
 // Serial.begin(9600);

 // Serial.print("calibrating sensor ");
  for(int i = 0; i < calibrationTime; i++){
   // Serial.print(".");
    delay(1000);
  }
}

void loop(){
  val = digitalRead(inputPin);  // read input value
//  Serial.println(val);  
  if (val == HIGH) { // check if the input is HIGH
//    digitalWrite(ledPin, HIGH);  // turn LED ON
//    delay(150);

    if (pirState == LOW) {  
      // we have just turned on
    //  Serial.println("Motion detected!");
      tone(8, 260 );  // emet un son
      delay(300);
      noTone(8);
      // We only want to print on the output change, not state
      pirState = HIGH;
      temps = millis();
    }
    else {
      if ( ( millis() - temps ) > 1000 ) {
        tone(8, 400 );  // emet un son  
        delay(10);
        noTone(8);
        delay(200);
        temps = millis();
      //  Serial.println("###########");
      }
    }
  } else {
  //    digitalWrite(ledPin, LOW); // turn LED OFF
   // delay(300);
    if (pirState == HIGH){
      // we have just turned of
    // Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;

    }
  }
}
