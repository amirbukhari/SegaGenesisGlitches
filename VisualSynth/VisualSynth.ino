/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald

  modified 2 Sep 2016
  by Arturo Guadalupi

  modified 8 Sep 2016
  by Colby Newman
*/
boolean btnPressed = false;
int amirsVal;
int tempAvgCount = 0;
int tempPrntCount = 0;
unsigned long kickPatchChangeCount = 0;
int reading;
float tempC;
float referenceVoltage = 5.0; //Set to 5, 3.3, 2.56 or 1.1 depending on analogReference Setting
unsigned long Timer;


int amirsPin = 10;
int amirsCount = 0;
int amirsNoiseTempamirsVal = 0;
int amirsNoiseCount = 0;
int amirsNoise = 0;

int pin = 2;
// the loop function runs over and over again forever
float greatestReading = 0 ;
int greatestamirsValue =0;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  delay(3000);

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(13, INPUT);


  digitalWrite(2, LOW);

  digitalWrite(3, LOW);

  digitalWrite(4, LOW);


  //analogReference(INTERNAL);


}

//float greatestVal = 0;

void loop() {

  //if(tempC < 50)
  //{
//float jordansVal = analogRead(4);



  //Read amirsValue from amirs guitar
   float amirsVal = analogRead(2); // read the input pin
  

   //find noise for amirs guitar
   if(amirsNoiseTempamirsVal > amirsVal - 3 ||amirsNoiseTempamirsVal < amirsVal + 3){
      amirsCount = amirsCount  + 1;
   }
   else
   {
    amirsNoiseTempamirsVal = amirsVal;
    amirsCount = 0;
   }

   if(amirsCount > 20)
   {
    amirsNoise = amirsVal;
   }
   
   //amirsVal = amirsVal - 199;
  // amirsVal = (amirsVal - 200)*3;
   
   //Serial.println ( amirsPin);
   if (amirsVal > amirsNoise + 20){//0 || amirsVal < 270){
    amirsVal = amirsVal *3;
     Serial.print(amirsVal);
      Serial.println(amirsPin);
     analogWrite(amirsPin, amirsVal/4);
     
   // digitalWrite(8,HIGH);
    delay(amirsVal/51);
    analogWrite(amirsPin, 0);
   // digitalWrite(8,LOW);
   }
amirsCount = amirsCount + 1;
  if(amirsCount > 100)
  {
    amirsPin = amirsPin + 1;
    if(amirsPin == 11)
    {
      amirsPin = 9;
    }
    amirsCount =0;
  }
   
   
  //}
  //delay(sample/75);
   // int sample = analogRead(A0);
      //delay(sample/75);
   //Serial.println(sample);
  
//    if(sample > greatestamirsValue)
//    {
//      greatestamirsValue = sample;
//      Serial.println(greatestamirsValue);
//    }
//    int sample = amirsVal - 250;
//   // Serial.println(sample);
//    if(sample > (215 - 26))
//    {
//      binaryWrite(1,1,1);
//    }else if(sample > (215 - (26*2)))
//    {
//      binaryWrite(1,1,0);
//  
//    }
//    else if(sample > (215 - (26*3)))
//    {
//       binaryWrite(1,0,1);
//    }
//    else if(sample > (215 - (26*4)))
//    {
//       binaryWrite(1,0,0);
//    }
//    else if(sample > (215 - (26*5)))
//    {
//       binaryWrite(0,1,1);
//    }
//    else if(sample > (215 - (26*6)))
//    {
//       binaryWrite(0,1,0);
//    }
//     else if(sample > (215 - (26*7)))
//    {
//       binaryWrite(0,0,1);
//    }
//     //else if(sample > (215 - (26*8)))
//     else
//    {
//       binaryWrite(0,0,0);
//    }
  // int sample2 = analogRead(A0);




//  unsigned long currentMillis = millis();
//
//  if (currentMillis - kickPatchChangeCount >= 1000) {
//    // save the last time you the kick was hit
//    kickPatchChangeCount = currentMillis;
//    if (digitalRead(13) == HIGH && btnPressed == false)
//    {
//
//      int list[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
//      for (int a = 0; a < 11; a++)
//      {
//        int r = random(a, 11); // dont remember syntax just now, random from a to 8 included.
//        int temp = list[a];
//        list[a] = list[r];
//        list[r] = temp;
//      }
//
//      Serial.print("Jordan ");
//      Serial.print(list[0] + String(" ") + list[1] + String(" ") + list[2] + String(" ") + list[3]);
//      Serial.print(", Julian ");
//      Serial.print(list[4] + String(" ") + list[5] + String(" ") + list[6]);
//      Serial.print(", Jordin ");
//      Serial.print(list[7] + String(" ") + list[8]);
//      Serial.print(", Amir ");
//      Serial.println(list[9] + String(" ") + list[10]);
//
//
//
//
//      //digitalWrite(3,HIGH);
//      // digitalWrite(2,LOW);
//      //    pin = pin + 1;
//      //    if(pin == 4)
//      //    {
//      //      pin =2;
//      //    }
//      //    digitalWrite(pin, HIGH);
//      btnPressed = true;
//    }
//  }
//  if (digitalRead(13) == LOW)
//  {
//    btnPressed = false;
//    //kickPatchChangeCount = 0;
//    //digitalWrite(3,LOW);
//    //digitalWrite(2,HIGH);
//  }
//  tempAvgCount = tempAvgCount + 1;
//  tempPrntCount = tempPrntCount + 1;
//  if (tempAvgCount == 50)
//  {
//    tempAvgCount = 0;
//    reading = 0;
//    for (int i = 0; i < 10; i++) { // Average 10 readings for accurate reading
//      reading += analogRead(1);
//    }
//  }
//
//  if (tempPrntCount = 1000)
//  {
//    tempPrntCount = 0;
//    tempC =  (referenceVoltage * reading * 10) / 1023;
//
//    if(tempC>greatestReading){
//        Serial.print(tempC, 1); //Print one decimal, it's not accurate enough for two
//        Serial.println(" C");
//        Serial.println(" ");
//        greatestReading = tempC;
//    }
//
//  
//  }
}




void binaryWrite(int i, int x , int y)
{
  Serial.print("BINARY WRITE");

  if (i == 1)
  {
     for (int z = 0; z < 1000; z++) { // Average 10 readings for accurate reading
        digitalWrite(8, HIGH);
    delay(1);
    }
  
  } else
  {
    digitalWrite(8, LOW);
    delay(1);
  }
  // delay(2);
  if (x == 1)
  {
    digitalWrite(8, HIGH);
    delay(1);
  } else
  {
    digitalWrite(8, LOW);
    delay(1);
  }
  // delay(2);
  if (y == 1)
  {
    digitalWrite(8, HIGH);
    delay(2);
  } else
  {
    digitalWrite(8, LOW);
    delay(1);
  }
  // delay(2);
}


















