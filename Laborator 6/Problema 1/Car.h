#pragma once
#include <stdio.h>
#include "Weather.h"
class Car {
protected:
	float speed;
	float consumtion;
	float capacity;
public:
	virtual float GetFuelConsumption(Weather weather) = 0;
	virtual float GetFuelCapacity() = 0;
	virtual float GetAverageSpeed(Weather weather) = 0;
	virtual float GetTimeToFinish(Weather weather,int length) = 0;
	virtual const char* GetName() = 0;
};