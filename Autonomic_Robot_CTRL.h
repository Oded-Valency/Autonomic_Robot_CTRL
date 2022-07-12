#ifndef Autonomic_Robot_CTR_h
#define Autonomic_Robot_CTR_h


class Autonomic_Robot_CTRL {
public:
  Autonomic_Robot_CTRL (int in1pin, int in2pin ,int in3pin, int in4pin , int ENApin, int ENBpin, int heading, int power);
  void begin();
  void steering (int heading, int power);


private:
  int _in1LeftPin;
  int _in2LeftPin;
  int _in3RightPin;
  int _in4RightPin;
  int _ENLeftPin;
  int _ENRightPin;

 // bool _in1;
 // bool _in2;
 // bool _in3;
 // bool _in4;
  int _enA_power;
  int _enB_power;

  int _heading;
  int _power;
};
#endif 