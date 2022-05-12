//Arduino code for force sensors salad:
const int FORCE_SENSOR_PIN1 = A3; // the FSR and 10K pulldown are connected to A0
const int FORCE_SENSOR_PIN2= A4;
const int FORCE_SENSOR_PIN3 = A5;
const int FORCE_SENSOR_PIN4 = A6;
const int notPot = A7;
const int POT = A8;
const int one = 1;
const int button = 2;
int lastButtonState = LOW;


int xpin = A0;                
 int ypin = A1;                
 int zpin = A2; 
// const int FORCE_SENSOR_PIN1 = A3;
 int xvalue;
 int yvalue;
 int zvalue;

int buttonState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
}

void loop() {
//  xvalue = analogRead(xpin);                              //reads values from x-pin & measures acceleration in X direction 
//
//  int x = map(xvalue, 96, 435, -100, 100);               //maps the extreme ends analog values from -100 to 100 for our understanding
////; you need to replace the 267 & 400 value with your values from calibration
//  float xg = (float)x/(-100.00)+0.40;                          //converts the mapped value into acceleration in terms of "g"
//  Serial.print(xg);                                       //prints value of acceleration in X direction
//  Serial.print(", ");                                   //prints "g"
//   
//  yvalue = analogRead(ypin);
//  int y = map(yvalue, 80, 416, -100, 100);
//  float yg = (float)y/(-100.00)+0.52;
//  Serial.print("\t");
//  Serial.print(yg);
//  Serial.print(", "); 
// 
//  zvalue = analogRead(zpin);
//  int z = map(zvalue, 142, 442, -100, 100);
//  float zg = (float)z/(100.00)-0.87;
//  Serial.print("\t"); 
//  Serial.print(zg);
//  Serial.print(", ");
//  delay(100);

  
  int analogReading1 = analogRead(FORCE_SENSOR_PIN1);
//  Serial.print("Force sensor 1: ");
  Serial.print(analogReading1); // print the raw analog reading
  Serial.print(", "); 
//  delay(1000);  
  
  int analogReading2 = analogRead(FORCE_SENSOR_PIN2);
//  Serial.print(" /  Force sensor 2: ");
  Serial.print(analogReading2); // print the raw analog reading
  Serial.print(", ");
//  delay(1000);

    int analogReading3 = analogRead(FORCE_SENSOR_PIN3);
//  Serial.print(" /  Force sensor 3: ");  
  Serial.print(analogReading3); // print the raw analog reading
  Serial.print(", "); 
  
  
  int reading = digitalRead(button);

  if (reading != lastButtonState) {
    // reset the debouncing timer
//    lastDebounceTime = millis();
  Serial.print(one);
  
  } else{
    Serial.print(0);
  }
Serial.print(", ");
     int analogReading4 = analogRead(FORCE_SENSOR_PIN4);
     Serial.print(analogReading4);

     Serial.print(", ");


     int analogReading5 = analogRead(notPot);
     Serial.print(analogReading5);

     Serial.print(", ");

     int analogReading6 = analogRead(POT);
     Serial.println(analogReading6);

     delay(1000);


       lastButtonState = reading;
//      
}
