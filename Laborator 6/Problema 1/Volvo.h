#pragma once
#include "Car.h"
#include "Weather.h"
class Volvo :public Car {

public:
	Volvo();
	~Volvo();
	 float GetFuelConsumption(Weather weather);
	 float GetFuelCapacity();
	 float GetAverageSpeed(Weather weather);
	 float GetTimeToFinish(Weather weather, int length);
	 const char* GetName();
};