#include "Base.h"
#include "Vehicle.h"

int main() {
    Base base;
    base.PrintInfo();
    cout << endl;

    Bus bus;
    Truck truck;
    bus.arrive(base);
    cout << endl;

    bus.leave(base);

    cout << endl;
    base.PrintInfo();
    cout << endl;

    truck.arrive(base);
    cout << endl;

    truck.leave(base);
    cout << endl;
    base.PrintInfo();
    cout << endl;
    return 0;
}