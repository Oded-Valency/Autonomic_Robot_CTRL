/*
//החיבורים של מנוע שמאל
int enA = 6;
int in1 = 4;
int in2 = 5;
//החיבורים של מנוע ימין
int enB = 10;
int in3 = 9;
int in4 = 8;

void setup() {
	// Set all the motors pins to outputs
	pinMode(enA, OUTPUT);
	pinMode(enB, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
	
	// Turn off motors - מצב התחלתי
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
  	
  Serial.begin(9600);

}

void loop() {
  float heading = analogRead(A0);//לקרוא ערכים מהפוטנציומטר
  float speed = analogRead(A1);////לקרוא ערכים מהפוטנציומטר
  turn(heading, speed);//קריאה לפרוצדורה
  delay(100);
}


int turn(float heading, float speed)
{
  	//Serial.println(speed);
    //Serial.println(heading);
  	heading = map (heading, 0, 1023, -100, 100);//שינוי הטווח
    //Serial.println(heading);
    heading = heading*0.01;//מאה אחוז זה 1 אפס זה אפס
  	//Serial.println(heading);
  	speed = map (speed, 0, 1023, 0, 100);
    speed = speed*0.01;

  	float Mspeed = 255 * heading * speed;//מהירות המנוע החדשה
  	float Theading = 0;


  	if (heading >= 0.5)
    {
      	heading = heading *100;//הגדלת הטווח
      	Theading = map (heading, 50, 100, 0, 100);//יצרית משתנה כדי לא לפגוע בהמשך התוכנית
      	Theading = Theading * 0.01;//להביא את הפרמטר למספר עשרוני
      	heading = heading *0.01;//החזרת המשתנה כדי לא לפגוע בהמשך התוכנית
      	//קביעת כיוון סיבוב הגלגלים
      	digitalWrite(in1, LOW);
		    digitalWrite(in2, HIGH);
      	digitalWrite(in3, HIGH);
		    digitalWrite(in4, LOW);
      	float Mspeed = 255 * Theading * speed;//מהירות סיבוב הגלגל
    	  analogWrite(enB, Mspeed);
      	analogWrite(enA, 255 * speed);
    }

  	if ((heading > 0) && (heading < 0.5))
    {	
      	heading = heading *100;
      	Theading = map (heading, 0, 50, 100, 0);
      	Theading = Theading * 0.01;
      	heading = heading *0.01;
    	digitalWrite(in1, LOW);
		digitalWrite(in2, HIGH);
    	digitalWrite(in3, LOW);
		digitalWrite(in4, HIGH);
      	float Mspeed = 255 * Theading * speed;
    	analogWrite(enB, Mspeed);//קביעת מהירות המנועה
      	analogWrite(enA, 255 * speed);//שינוי מהירות המונעה לפי דרישה
    }
  	if (heading == 0)//במידה והמשתנה יהיה שווה לאפס שני הגלגלים הסתובבו באותה המהירות
    {	
    	digitalWrite(in1, LOW);
		digitalWrite(in2, HIGH);
    	digitalWrite(in3, LOW);
		digitalWrite(in4, HIGH);
     	analogWrite(enA, 255 * speed);
        analogWrite(enB, 255 * speed);
    }
  	if (heading < 0 && heading > -0.5) 
    {
      	heading = heading *-100;
      	Theading = map (heading, 0, 50, 100, 0);
      	Theading = Theading * 0.01;
      	heading = heading *-0.01;
      	digitalWrite(in1, LOW);
		digitalWrite(in2, HIGH);
    	digitalWrite(in3, LOW);
		digitalWrite(in4, HIGH);
      	float Mspeed = 255 * Theading * speed;
  		analogWrite(enA, Mspeed);
      	analogWrite(enB, 255 * speed);
	}
  	if (heading <= -0.5)
  	{
      	heading = heading *100;
      	Theading = map (heading, -50, -100, 0, 100);
      	Theading = Theading * 0.01;
      	heading = heading *0.01;
      	digitalWrite(in1, HIGH);
		digitalWrite(in2, LOW);
      	digitalWrite(in3, LOW);
		digitalWrite(in4, HIGH);
  		float Mspeed = 255 * Theading * speed;
  		analogWrite(enA, Mspeed);
      	analogWrite(enB, 255 * speed);
 	}
  	delay(1000);
}*/