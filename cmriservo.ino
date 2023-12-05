#include <CMRI.h>
#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

CMRI cmri(0); // defaults to a SMINI with address 0. SMINI = 24 inputs, 48 outputs

void setup()
  {
  Serial.begin(9600, SERIAL_8N2); // make sure this matches your speed set in JMRI

  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  }

int oldTO[4] = {1,1,1,1};

void loop()
  {

  cmri.process();

  if (cmri.get_bit(0) == 1 && oldTO[0] == 0)
    {
    motor1.run(FORWARD);
    motor1.setSpeed(255);  
    delay(500);
    motor1.setSpeed(0);
    }

 if (cmri.get_bit(0) == 0 && oldTO[0] == 1)
    {
    motor1.run(BACKWARD);
    motor1.setSpeed(255);  
    delay(500);
    motor1.setSpeed(0);
    }
  oldTO[0] = cmri.get_bit(0);


  if (cmri.get_bit(1) == 1 && oldTO[1] == 0)
    {
    motor2.run(FORWARD);
    motor2.setSpeed(255);  
    delay(500);
    motor2.setSpeed(1);
    }

 if (cmri.get_bit(1) == 0 && oldTO[1] == 1)
    {
    motor2.run(BACKWARD);
    motor2.setSpeed(255);  
    delay(500);
    motor2.setSpeed(0);
    }
  oldTO[1] = cmri.get_bit(1);


  if (cmri.get_bit(2) == 1 && oldTO[2] == 0)
    {
    motor3.run(FORWARD);
    motor3.setSpeed(255);  
    delay(500);
    motor3.setSpeed(2);
    }

 if (cmri.get_bit(2) == 0 && oldTO[2] == 1)
    {
    motor3.run(BACKWARD);
    motor3.setSpeed(255);  
    delay(500);
    motor3.setSpeed(2);
    }
  oldTO[2] = cmri.get_bit(2);


  if (cmri.get_bit(3) == 1 && oldTO[3] == 0)
    {
    motor4.run(FORWARD);
    motor4.setSpeed(255);  
    delay(500);
    motor4.setSpeed(3);
    }

 if (cmri.get_bit(3) == 0 && oldTO[3] == 1)
    {
    motor4.run(BACKWARD);
    motor4.setSpeed(255);  
    delay(500);
    motor4.setSpeed(3);
    }
  oldTO[3] = cmri.get_bit(3);  

  cmri.set_bit(0, oldTO[0]);
  cmri.set_bit(1, oldTO[1]);
  cmri.set_bit(2, oldTO[2]);
  cmri.set_bit(3, oldTO[3]);
}

