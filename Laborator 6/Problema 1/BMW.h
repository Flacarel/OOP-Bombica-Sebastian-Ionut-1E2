#pragma once
#include "Car.h"
#include "Weather.h"
class BMW :public Car {

public:
	BMW();
	~BMW();
	 float GetFuelConsumption(Weather weather);
	 float GetFuelCapacity();
	 float GetAverageSpeed(Weather weather);
	 float GetTimeToFinish(Weather weather, int length);
	 const char* GetName();
};