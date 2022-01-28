// Multi Serial to VarSpeedServo --> Vije Miller
// https://github.com/netlabtoolkit/VarSpeedServo

/*
  Type: Servo No. + Position + . + Speed
  Keypad Friendly Position and Speed Testing
  Example: 290.120 (Servo 2 Position 90 Speed 120)
  10 to 1180 + .0 to .255 Speed for Servo 1
*/

#include 

// Name Servos
VarSpeedServo one;
VarSpeedServo two;
VarSpeedServo three;
VarSpeedServo four;
VarSpeedServo five;

// Set Values
String input;
String also;
String then;
int also_int;
int then_pos;
int then_int;

// Default Position and Speed
const int start = 90;
const int set_speed = 50;

void setup() {
  Serial.begin(9600);

  // Assign Pins
  one.attach(2);
  two.attach(3);
  three.attach(4);
  four.attach(5);
  five.attach(6);

  // Default Position and Speed
  one.write(start, set_speed, true);
  two.write(start, set_speed, true);
  three.write(start, set_speed, true);
  four.write(start, set_speed, true);
  five.write(start, set_speed, true);
}

void loop() {
  if (Serial.available() > 0)
  {
    // Assign Strings
    input = Serial.readString();
    also = input;
    then = also;

    // Get Servo Number
    input.remove(1);

    // Get Position
    also.remove(0, 1);
    also_int = also.toInt();

    // Get Speed
    then_pos = then.indexOf('.');
    then_pos = then_pos + 1;
    then = then.substring(then_pos);
    then_int = then.toInt();

    // Print Results
    Serial.print(input);
    Serial.print(" ");
    Serial.print(also_int);
    Serial.print(" ");
    Serial.println(then_int);

    // Run Results
    if (input == "1") {
      one.write(also_int, then_int, true);
    } else if (input == "2") {
      two.write(also_int, then_int, true);
    } else if (input == "3") {
      three.write(also_int, then_int, true);
    } else if (input == "4") {
      four.write(also_int, then_int, true);
    } else if (input == "5") {
      five.write(also_int, then_int, true);
    }
    delay(10);
  }
}
