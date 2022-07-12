/* cpp code for Autonomic_Robot_CTRL.h library
this library has been written to eazy control on a 2 DC motor vehicle govern by a H-Bridge motor controller.
power   : int (-100..+100), where  -100 stand for Full Power Back  , 0 stand for Stop , +100 stand for Full Power Forward
heading : int (-100..+100), where  
  -100 stand for "Tank Left"  (left motor Back, right motor Forward)
   -50 stand for "Pivot Left" (left motor stop, right motor Forward)
     0 stand for "Stop"       (left motor stop, right motor stop)  
   -50 stand for "Pivot Right"(left motor Forward, right motor stop )
  -100 stand for "Tank Right" (left motor Forward, right motor Back )
  https://sites.google.com/site/ev3devpython/learn_ev3_python/using-motors
 
tested on L298D module via Arduino UNO R3
by: Valency Oded
last rev 1.2 at 29-Jul-2022   compilation error debud 1
rev 1.x predefine Arduino pin allocation,  
rev 2.x will get the arduino pin num from the user
*/
    //#include <Wire.h>
    //#include <Arduino.h>
#include "Arduino.h"
#include <Servo.h> // Servo function library
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Autonomic_Robot_CTRL.h"

//static int pos = 0;    // stores the servo position


// *****   Main class declaration   *****
Autonomic_Robot_CTRL::Autonomic_Robot_CTRL (int in1pin, int in2pin ,int in3pin, int in4pin , int ENApin, int ENBpin , int heading, int power )
  {
  pinMode(in1pin  , OUTPUT);	   
	pinMode(in2pin  , OUTPUT);	 
	pinMode(in3pin  , OUTPUT);	 
  pinMode(in4pin  , OUTPUT);	   
  pinMode(ENApin  , OUTPUT);	   
	pinMode(ENBpin  , OUTPUT);	
  
  _in1LeftPin   = in1pin ;
  _in2LeftPin   = in2pin ;
  _in3RightPin  = in3pin ;
  _in4RightPin  = in4pin ;
  _ENLeftPin    = ENApin ;  // left engine
  _ENRightPin   = ENBpin ;  // right engine
  _heading = heading;
  _power   = power;

  }

  void Autonomic_Robot_CTRL::begin ( )
  {
// ***** General librery Objects Constractors  ***** 
  LiquidCrystal_I2C lcd (0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display
  Serial.begin(115200); 
 //   Autonomic_Robot_CTRL robo (int in1pin, int in2pin ,int in3pin, int in4pin , int ENApin, int ENBpin)  ;
}

 void Autonomic_Robot_CTRL::steering  ( int heading, int power)
    {
      int Theading ;
      int _RightPower ;
      int _LeftPower ;
      if ( heading >= 50 ) {      // Turn Tank Right
          Theading = map (heading, 50, 100, 0, 255) ;
          digitalWrite(_in1LeftPin , LOW);
          digitalWrite(_in2LeftPin , HIGH);
          digitalWrite(_in3RightPin, HIGH);
          digitalWrite(_in3RightPin, LOW);

          _RightPower = abs(Theading * power / 100 );
          _LeftPower  = abs(power * 255 / 100) ;
          analogWrite(_ENLeftPin, _RightPower);
          analogWrite(_ENRightPin, _LeftPower);    
            Serial.print ("heading = " );Serial.print (heading );  Serial.print (" || Motors 1 0 ||") ;
            Serial.print (" , _ENLeftPin = " ); Serial.print (_RightPower );  
            Serial.print ("  _ENRightPin = " );   Serial.println (_LeftPower );
        }
      if ( heading >= 0 && heading < 50 ) {      // Turn Pivot Right
          Theading = map (heading, 0, 50, 255, 0) ;
          digitalWrite(_in1LeftPin, LOW);
          digitalWrite(_in2LeftPin, HIGH);
          digitalWrite(_in3RightPin, LOW);
          digitalWrite(_in4RightPin, HIGH);

          _RightPower = abs(Theading * power / 100 );
          _LeftPower  = abs(power * 255 / 100) ;
          analogWrite(_ENLeftPin, _RightPower);
          analogWrite(_ENRightPin, _LeftPower);    

            Serial.print ("heading = " );Serial.print (heading );  Serial.print (" || Motors 1 1 ||") ;
            Serial.print (" , _ENLeftPin = " ); Serial.print (_RightPower );  
            Serial.print ("  _ENRightPin = " );   Serial.println (_LeftPower );
                    }
 
      if ( heading < 0 && heading > - 50 ) {      // Turn Pivot Left
          Theading = map (heading, -50, 0, 0, 255) ;
          digitalWrite(_in1LeftPin, LOW);
          digitalWrite(_in2LeftPin, HIGH);
          digitalWrite(_in3RightPin, LOW);
          digitalWrite(_in4RightPin, HIGH);

          _RightPower = abs(power * 255 / 100 );
          _LeftPower  = abs( Theading * power / 100) ;
          analogWrite(_ENLeftPin, _RightPower);
          analogWrite(_ENRightPin, _LeftPower);    

            Serial.print ("heading = " );Serial.print (heading );  Serial.print (" || Motors 1 1 ||") ;
            Serial.print (" , _ENLeftPin = " ); Serial.print (_RightPower );  
            Serial.print ("  _ENRightPin = " );   Serial.println (_LeftPower );
            }

      if ( heading <= -50  ) {      // Turn Pivot Left
          Theading = map (heading, -50, -100, 0, 255) ;
          digitalWrite(_in1LeftPin,  HIGH);
          digitalWrite(_in2LeftPin,  LOW);
          digitalWrite(_in3RightPin, LOW);
          digitalWrite(_in4RightPin, HIGH);

           _RightPower = abs(power * 255 / 100 );
          _LeftPower  = abs( Theading * power / 100) ;
          analogWrite(_ENLeftPin, _RightPower);
          analogWrite(_ENRightPin, _LeftPower);    

            Serial.print ("heading = " );Serial.print (heading );  Serial.print (" || Motors 0 1 ||") ;
            Serial.print (" , _ENLeftPin = " ); Serial.print (_RightPower );  
            Serial.print ("  _ENRightPin = " );   Serial.println (_LeftPower );
            }


//          delay (500);
    }


