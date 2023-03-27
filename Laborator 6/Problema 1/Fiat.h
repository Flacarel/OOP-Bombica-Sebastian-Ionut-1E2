#pragma once
#include "Car.h"
#include "Weather.h"
class Fiat :public Car {

public:
	Fiat();
	~Fiat();
	virtual float GetFuelConsumption(Weather weather);
	virtual float GetFuelCapacity();
	virtual float GetAverageSpeed(Weather weather);
	virtual float GetTimeToFinish(Weather weather, int length);
	virtual const char* GetName();
};