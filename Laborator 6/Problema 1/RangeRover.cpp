#include "RangeRover.h"
float RangeRover::GetAverageSpeed(Weather weather) {
	switch (weather) {
	case Weather::Rain:
		return this->speed * 0.8;
	case Weather::Sunny:
		return this->speed;
	case Weather::Snow:
		return this->speed * 0.5;
	}
}

float RangeRover::GetFuelCapacity() {
	return this->capacity;
}

float RangeRover::GetFuelConsumption(Weather weather) {
	switch (weather) {
	case 0:
		return this->consumtion * 1.2;
	case 1:
		return this->consumtion;
	case 2:
		return this->consumtion * 1.5;
	}
}

float RangeRover::GetTimeToFinish(Weather weather, int length) {
	return length / GetAverageSpeed(weather);
}

RangeRover::RangeRover() {
	this->speed = 100;
	this->capacity = 70;
	this->consumtion = 0.2;
}

RangeRover::~RangeRover() {
}

const char* RangeRover::GetName() {
	return "RangeRover";
}