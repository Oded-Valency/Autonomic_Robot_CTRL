#include  "Autonomic_Robot_CTRL.h"
//Left Motor
int enAmotorLeft = 6;  // Power 0..255
int in1motorLeft = 4;  
int in2motorLeft = 5;
//Right motor
int enBmotorRight = 10;  // Power 0..255
int in3motorRight = 8;
int in4motorRight = 9;
// initialise values
int heading = 0;
int power   = 80;
int steps = 5;
Autonomic_Robot_CTRL Robo (in1motorLeft,  in2motorLeft , in3motorRight,  in4motorRight , enAmotorLeft , enBmotorRight ,heading,  power);



  void setup() {  Robo.begin();     }

void  PotentiometerCTRL(){
    heading = map (analogRead(A0), 0, 1023, -100, 100);   //1 לקרוא ערכים לכיוון מהפוטנציומטר
    power   = map (analogRead(A1), 0, 1023, -100, 100);   //2 לקרוא ערכים לעוצמה מהפוטנציומטר
    Robo.steering (heading, power);//קריאה לפרוצדורה
    delay(100);     }

void testMotors (int wait){
      if (heading >=100) { steps = -10;}
      if (heading <= -100) { steps = +10;}
        heading = heading + steps ;

        Robo.steering (heading , power);   // go straight, power 80
/*        Serial.print ("power = " );
        Serial.print (power );  
        Serial.print (" , heading = " );  
        Serial.println (heading );*/
        delay(wait);             // for 400 mili seconds
  }

  void loop () {
  //  PotentiometerCTRL(); 
  testMotors(500);
  
    }
