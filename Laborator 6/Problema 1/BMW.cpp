#include "BMW.h"

float BMW::GetAverageSpeed(Weather weather) {
	switch (weather) {
	case 0:
		return this->speed * 0.8;
	case 1:
		return this->speed;
	case 2:
		return this->speed * 0.5;
	}
}

float BMW::GetFuelCapacity() {
	return this->capacity;
}

float BMW::GetFuelConsumption(Weather weather) {
	switch (weather) {
	case 0:
		return this->consumtion * 1.2;
	case 1:
		return this->consumtion;
	case 2:
		return this->consumtion * 1.5;
	}
}

float BMW::GetTimeToFinish(Weather weather, int length) {
	return length / GetAverageSpeed(weather);
}

BMW::BMW() {
	this->speed = 150;
	this->capacity = 80;
	this->consumtion = 0.5;
}

BMW::~BMW() {
}

const char* BMW::GetName() {
	return "BMW";
}