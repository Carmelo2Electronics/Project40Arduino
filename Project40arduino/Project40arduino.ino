

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup() {
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
    inputString.trim();
    Serial.print(inputString);

    if(inputString=="0 LOW"){
      digitalWrite(2, LOW);
    }
    
    if(inputString=="0 HIGH"){
      digitalWrite(2, HIGH);
    }

    if(inputString=="1 LOW"){
      digitalWrite(3, LOW);
    }
    
    if(inputString=="1 HIGH"){
      digitalWrite(3, HIGH);
    }

    if(inputString=="2 LOW"){
      digitalWrite(4, LOW);
    }
    if(inputString=="2 HIGH"){
      digitalWrite(4, HIGH);
    }

    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}


void serialEvent() {
  while (Serial.available()) {          //received from java
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
      break;
    }
  }
}
