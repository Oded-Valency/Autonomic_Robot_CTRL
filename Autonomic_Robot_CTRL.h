#ifndef Autonomic_Robot_CTR_h
#define Autonomic_Robot_CTR_h

/*  Copyright Valency Oded All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA */

class Autonomic_Robot_CTRL {
public:
  Autonomic_Robot_CTRL (int in1pin, int in2pin ,int in3pin, int in4pin , int ENApin, int ENBpin, int heading, int power);
  void begin();
  void steering (int heading, int power);
  void printMotors(String  MotorsDiraction);


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

  int _RightPower ;
  int _LeftPower ;
};
#endif 