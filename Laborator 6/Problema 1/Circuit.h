#pragma once
#include "Car.h"
#include "Weather.h"

class Circuit {
private:
	int length;
	Car** car;
	Weather weather;
	int carCount;
public:
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
	void Race();
	void AddCar(Car* masina);
	void SetWeather(Weather weather);
	void SetLength(int length);
	Circuit();
	~Circuit();
};