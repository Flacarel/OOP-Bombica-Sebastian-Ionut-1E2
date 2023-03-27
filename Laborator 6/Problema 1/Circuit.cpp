#include "Circuit.h"
#include "iostream"
using namespace std;

void Circuit::SetLength(int length) {
	this->length = length;
}

void Circuit::SetWeather(Weather weather) {
	this->weather = weather;
}

void Circuit::AddCar(Car* masina) {
    this->carCount++;
    Car** newCar = new Car* [this->carCount];  
    for (int i = 0; i < this->carCount - 1; i++) {
        newCar[i] = this->car[i];
    }
    newCar[this->carCount - 1] = masina;
    delete[] this->car;
    this->car = newCar;
}

void Circuit::Race() {
    for(int i=0;i<this->carCount-1;i++)
        for(int j=i+1;j<this->carCount;j++)
            if (this->car[i]->GetTimeToFinish(this->weather, this->length) > this->car[j]->GetTimeToFinish(this->weather, this->length)) 
                swap(this->car[i], this->car[j]);
}

void Circuit::ShowFinalRanks() {
    for (int i = 0;i < this->carCount;i++){ 
        float finishtime = this->car[i]->GetTimeToFinish(this->weather, this->length);
        float travelDistance = this->car[i]->GetFuelCapacity() / this->car[i]->GetFuelConsumption(this->weather);
        if (travelDistance >= this->length)
        cout <<i+1<<". "<< this->car[i]->GetName() << " in "<<finishtime <<" ore"<< endl;
    }  
}

void Circuit::ShowWhoDidNotFinish() {
    for (int i = 0;i < this->carCount;i++) {
        float travelDistance = this->car[i]->GetFuelCapacity() / this->car[i]->GetFuelConsumption(this->weather);
        if (travelDistance < this->length)
            cout << this->car[i]->GetName() << " nu a terminat cursa" << endl;
    }
       
}

Circuit::~Circuit() {
    delete[] this->car;
}

Circuit::Circuit(){
    this->carCount = 0;
    this->length = 0;
    this->weather = Weather::Rain;
    this->car = new Car * [1];

}