#include "Fiat.h"

float Fiat::GetAverageSpeed(Weather weather) {
	switch (weather) {
	case 0:
		return this->speed * 0.8;
	case 1:
		return this->speed;
	case 2:
		return this->speed * 0.5;
	}
}

float Fiat::GetFuelCapacity() {
	return this->capacity;
}

float Fiat::GetFuelConsumption(Weather weather) {
	switch (weather) {
	case 0:
		return this->consumtion * 1.2;
	case 1:
		return this->consumtion;
	case 2:
		return this->consumtion * 1.5;
	}
}

float Fiat::GetTimeToFinish(Weather weather, int length) {
	return length / GetAverageSpeed(weather);
}

Fiat::Fiat() {
	this->speed = 40;
	this->capacity = 20;
	this->consumtion = 6;
}

Fiat::~Fiat() {
}

const char* Fiat::GetName() {
	return "Fiat";
}