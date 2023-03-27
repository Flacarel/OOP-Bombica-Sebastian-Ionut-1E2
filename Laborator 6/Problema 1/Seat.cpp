#include "Seat.h"

float Seat::GetAverageSpeed(Weather weather) {
	switch (weather) {
	case 0:
		return this->speed * 0.8;
	case 1:
		return this->speed;
	case 2:
		return this->speed * 0.5;
	}
}

float Seat::GetFuelCapacity() {
	return this->capacity;
}

float Seat::GetFuelConsumption(Weather weather) {
	switch (weather) {
	case 0:
		return this->consumtion * 1.2;
	case 1:
		return this->consumtion;
	case 2:
		return this->consumtion * 1.5;
	}
}

float Seat::GetTimeToFinish(Weather weather, int length) {
	return length / GetAverageSpeed(weather);
}

Seat::Seat() {
	this->speed = 50;
	this->capacity = 20;
	this->consumtion = 8;
}

Seat::~Seat() {
}

const char* Seat::GetName() {
	return "Seat";
}