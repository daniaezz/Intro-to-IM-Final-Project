//Arduino code for force sensors salad:
const int FORCE_SENSOR_PIN1 = A1; // the FSR and 10K pulldown are connected to A0
const int FORCE_SENSOR_PIN2= A2;
const int FORCE_SENSOR_PIN3 = A3;
const int FORCE_SENSOR_PIN4 = A4;
const int POT = A5;

const int button = 2;


int buttonState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
}

void loop() {
  int analogReading1 = analogRead(FORCE_SENSOR_PIN1);
//  Serial.print("Force sensor 1: ");
  Serial.print(analogReading1); // print the raw analog reading
  Serial.print(","); 
//  delay(1000);  
  
  int analogReading2 = analogRead(FORCE_SENSOR_PIN2);
//  Serial.print(" /  Force sensor 2: ");
  Serial.print(analogReading2); // print the raw analog reading
  Serial.print(",");
//  delay(1000);

    int analogReading3 = analogRead(FORCE_SENSOR_PIN3);
//  Serial.print(" /  Force sensor 3: ");
  Serial.print(analogReading3); // print the raw analog reading
  Serial.print(","); 
  
  
    buttonState = digitalRead(button);
    Serial.print(buttonState);
    Serial.print(","); 

     int analogReading4 = analogRead(FORCE_SENSOR_PIN4);
     Serial.print(analogReading4);

     Serial.print(",");


     int analogReading5 = analogRead(POT);
     Serial.println(analogReading5);
      
}
