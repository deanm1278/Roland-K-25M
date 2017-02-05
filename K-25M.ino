/*
 * This example shows how to use Roland K-25M with Arduino.
 */

#define COL0B 5
#define COL0A 2
#define COL1B 6
#define COL1A 3
#define COL2B 7
#define COL2A 4
#define COL3B 8
#define COL3A A1

#define ROW0 A5
#define ROW1 12
#define ROW2 A4
#define ROW3 11
#define ROW4 A3
#define ROW5 10
#define ROW6 A2
#define ROW7 9

#define numCols  4
#define numRows  8

//col A is the first switch to get hit, note triggers once B gets hit.
//Timediff between A and B trigger is mapped to velocity

int colA[] = {COL0A, COL1A, COL2A, COL3A};
int colB[] = {COL0B, COL1B, COL2B, COL3B};

int rows[] = {ROW0, ROW1, ROW2, ROW3, ROW4, ROW5, ROW6, ROW7};

struct event {
  unsigned long aPressed = 0;
  unsigned long bPressed = 0;
  bool active = false;
  int key;
};

struct event events[numCols][numRows];

void setup() {
  //set inputs and outputs
  for(int i=0; i < numCols; i++){
    pinMode(colA[i], OUTPUT);
    digitalWrite(colA[i], LOW);

    pinMode(colB[i], OUTPUT);
    digitalWrite(colB[i], LOW);

    for(int j=0; j<numRows; j++){
      struct event *e = &events[i][j];

      e->key = (i * numRows) + j;
    }
  }

  for(int i=0; i<numRows; i++){
    pinMode(rows[i], INPUT);
  }
  Serial.begin(9600);
  while(!Serial);

  Serial.println("Roland K25-M Example");
}

void loop() {
  //loop through columns, set high and check rows
  for(int i=0; i<numCols; i++){
    digitalWrite(colA[i], HIGH);

    //check each row for a signal
    for(int j=0; j<numRows; j++){
      struct event *e = &events[i][j];
      bool trig = digitalRead(rows[j]);
      
      if(trig && !e->aPressed){
        e->aPressed = millis();
      }
      else if(!trig)  e->aPressed = 0;
    }
    
    digitalWrite(colA[i], LOW);
  }

  //now do the same for column B
  for(int i=0; i<numCols; i++){
    digitalWrite(colB[i], HIGH);
    
    //check each row for a signal
    for(int j=0; j<numRows; j++){
      struct event *e = &events[i][j];
      bool trig = digitalRead(rows[j]);
      
      if(trig && !e->bPressed){
        e->bPressed = millis();
      }
      else if(!trig)  e->bPressed = 0;
    }
    digitalWrite(colB[i], LOW);
  }


  
  //check if we need to send any new events
  for(int i=0; i<numCols; i++){
    for(int j=0; j<numRows; j++){
      struct event *e = &events[i][j];
      
      if(e->aPressed && e->bPressed && !e->active){
        //record event
        e->active = true;
        Serial.print(e->key);
        Serial.print(" triggered! ");

        //velocity can be found by interval in between col a and b
        int vel = constrain(map(e->bPressed - e->aPressed, 0, 150, 127, 1), 1, 127);
        Serial.println(vel);
      }

      //if the note is active and the key gets released that is note off
      else if(!e->aPressed && e->active){
        e->active = false;
        Serial.print(e->key);
        Serial.println(" released");
      }
    }
  }
  
}
