#pragma once
#include "Car.h"
#include "Weather.h"
class RangeRover :public Car {

public:
	RangeRover();
	~RangeRover();
	 float GetFuelConsumption(Weather weather);
	 float GetFuelCapacity();
	 float GetAverageSpeed(Weather weather);
	 float GetTimeToFinish(Weather weather, int length);
	 const char* GetName();
};