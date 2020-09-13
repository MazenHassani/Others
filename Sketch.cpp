/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

String inputString = "";
boolean stringComplete = false;
const N=10;
int SpeedAV[N];
int AngleAV[N];

void serialEvent() {
	while (Serial.available())
	{
		char inChar = (char)Serial.read();
		inputString += inChar;
		if (inChar == '\n') 
		{
			stringComplete = true;
		}
	}
}

void sendToRobot()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void setup() {
  Serial.begin(9600);
  inputString.reserve(200);
}
float Filter (int test[], N)
{
	int sum=0;
	for(int i=0; sum+=test[i] && i<N ; i++);
	return sum/N;
}
void loop()
{
	int t1=0,t2=0;
  if (stringComplete) 
  {
    Serial.println(inputString);
	if (inputString [0] == 'S')
	{
		inputString.substring(1);
		int Speed = inputString.toInt();
		SpeedAV[t1++]=Speed;
		sendToRobot( Filter(SpeedAV[]) );
	}
	else if (inputString [0] == 'A')
	{
		inputString.substring(1)
		int Angle = inputString.toInt();
		AngleAV[t2++]=Angle;
		sendToRobot( Filter(AngleAV[]) );
	}
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}

/*
S100
A90
*/