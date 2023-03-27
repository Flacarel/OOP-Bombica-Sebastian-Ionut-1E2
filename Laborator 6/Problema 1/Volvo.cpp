#include "Volvo.h"

float Volvo::GetAverageSpeed(Weather weather) {
	/*switch (weather) {
	case 0:
		return this->speed * 0.8;
	case 1:
		return this->speed;
	case 2:
		return this->speed * 0.5;
	}
	*/
	if (weather == 0)
		return this->speed * 0.8;
	else if (weather == 1)
		return this->speed;
	else if (weather == 2)
		return this->speed * 0.5;

}

float Volvo::GetFuelCapacity() {
	return this->capacity;
}

float Volvo::GetFuelConsumption(Weather weather) {
	switch (weather) {
	case 0:
		return this->consumtion * 1.2;
	case 1:
		return this->consumtion;
	case 2:
		return this->consumtion * 1.5;
	}
}

float Volvo::GetTimeToFinish(Weather weather, int length) {
	return length / GetAverageSpeed(weather);
}

Volvo::Volvo() {
	this->speed = 90;
	this->capacity = 40;
	this->consumtion = 0.3;
}

Volvo::~Volvo() {
}

const char* Volvo::GetName() {
	return "Volvo";
}