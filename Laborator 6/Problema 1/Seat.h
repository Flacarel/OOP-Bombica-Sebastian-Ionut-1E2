#pragma once
#include "Car.h"
#include "Weather.h"
class Seat :public Car {

public:
	Seat();
	~Seat();
	 float GetFuelConsumption(Weather weather);
	 float GetFuelCapacity();
	 float GetAverageSpeed(Weather weather);
	 float GetTimeToFinish(Weather weather, int length);
	 const char* GetName();
};