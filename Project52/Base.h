#pragma once
#include<iostream>
using namespace std;
class Base
{
	static int people_on_base;
	static int vehicles_on_base;
	static double petrol_on_base;
	static double goods_on_base;
public:
	void PrintInfo() {
		cout << "INFO\npeople_on_base: " << people_on_base << "\nvehicles_on_base: " << vehicles_on_base
			<< "\npetrol_on_base: " << petrol_on_base << "\ngoods_on_base: " << goods_on_base << endl;
	}
	void ArriveToBase(int p, double g) {
		people_on_base += p;
		vehicles_on_base++;
		goods_on_base += g;
		cout << "AddToBase\nNewInfo: " << endl;
		PrintInfo();

	}

	bool FillVehiclesTank(double need) {
		if (need == 0) return true;
		if (need > petrol_on_base) {
			if(!TryConvertToPetrol(need-petrol_on_base)) return false;
		}

		petrol_on_base -= need;
		return true;
	}

	int TakePeople(int p) {
		int ret = p;
		if (people_on_base < p ) {
			people_on_base = 0;
			ret = people_on_base;
		}
		else{ people_on_base -= p; }
		cout << "TakePeople: " << ret << endl;
		return ret;
	}
	bool TryConvertToPetrol(double c = 10) {
		if (goods_on_base >= c) {
			goods_on_base -= c;
			vehicles_on_base += c;
			cout << "ConvertToPetrol TRUE" << endl;
			return true;
		}
		else cout << "ConvertToPetrol FALSE" << endl;
		return false;
	}

	int GetVehicle() { return vehicles_on_base; }
	
};
int Base::people_on_base = 50;
int Base::vehicles_on_base = 10;
double Base::petrol_on_base = 1000;
double Base::goods_on_base = 10;


//-static int people_on_base
//- static int vehicles_on_base
//- static double petrol_on_base
//- static double goods_on_base
