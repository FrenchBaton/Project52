#pragma once
#include"Base.h"

class Vehicle
{
protected:
	double tankVolum;
	double petrolVolume;
	int people;
	int maxPeople;
	double load;
	double maxLoad;
	string name;
public:
	Vehicle():
		tankVolum(5), 
		petrolVolume(0), 
		people(1), 
		maxPeople(1), 
		load(0), 
		maxLoad(0),
		name("VEHICLE") { }
	Vehicle(double petrol_amount, double tank_volume,string n, int p = 1, int maxp = 1, double l = 0, double maxl = 0) :
		tankVolum(tank_volume),
		petrolVolume(petrol_amount),
		people(p),
		maxPeople(maxp),
		load(l),
		maxLoad(maxl),
		name(n) { }
	void FillTank() {
		petrolVolume = tankVolum;
	}

	double getTankVolume() { return tankVolum; }
	double getPetrolAmount() { return petrolVolume; }
	void arrive(Base& b) {
		b.ArriveToBase(people, load);
		people = 0;
		load = 0;
		cout << name <<" Arrive" << endl;

	}
	bool leave(Base& b) {
		if (b.FillVehiclesTank(tankVolum - petrolVolume) && b.GetVehicle() != 0) {
			FillTank();
			people = b.TakePeople(maxPeople);
			if(people != 0) 
			{
				cout << name << " leave TRUE" << endl;
				return true;
			}
		}
		cout << name << " leave FALSE" << endl;
		return false;
	}
};



class Bus:public Vehicle
{
public:
	Bus()
		: Vehicle(0, 10,"BUS", 1, 10) {}
	Bus(double petrol_amount, double tank_volume,string n, int p, int maxp) 
		: Vehicle(petrol_amount, tank_volume,n, p, maxp) {}
};


class Truck : public Vehicle
{
public:
	Truck()
		: Vehicle(0, 10, "TRUCK", 1, 10, 0, 5) {}

	Truck(double petrol_amount, double tank_volume, string n, int p, int maxp, double l, double maxl)
		: Vehicle(petrol_amount, tank_volume, n, p, maxp, l, maxl) {}
};

