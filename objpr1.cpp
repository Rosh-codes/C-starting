#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string brand;
    string model;
    int year;
    bool engineRunning;
    bool wipersOn;
    int kilometersDriven;
    double fuel;
    double fuelCapacity;
    int speed;
    bool crash; 

public:
    Car(string b, string m, int y) : brand(b), model(m), year(y), engineRunning(false), wipersOn(false), kilometersDriven(0), fuel(50), fuelCapacity(50), speed(0), crash(false) {}

    void startEngine() {
        if (!engineRunning) {
            if (fuel > 0) {
                engineRunning = true;
                cout << "The engine of " << brand << " " << model << " is now running." << endl;
            } else {
                cout << "No fuel! Please refuel before starting the engine." << endl;
            }
        } else {
            cout << "The engine is already running!" << endl;
        }
    }

    void stopEngine() {
        if (engineRunning) {
            engineRunning = false;
            cout << "The engine of " << brand << " " << model << " is now stopped." << endl;
        } else {
            cout << "The engine is already off!" << endl;
        }
    }

    void toggleWipers() {
        wipersOn = !wipersOn;
        cout << "The wipers of " << brand << " " << model << " are now " << (wipersOn ? "on" : "off") << "." << endl;
    }

    void drive(int km) {
        if (engineRunning) {
            double fuelNeeded = km * 0.1; 
            if (fuel >= fuelNeeded) {
                kilometersDriven += km;
                fuel -= fuelNeeded;
                cout << "The car has been driven for " << km << " km. Total kilometers driven: " << kilometersDriven << " km." << endl;
            } else {
                cout << "Not enough fuel to drive " << km << " km. Please refuel!" << endl;
            }
        } else {
            cout << "Start the engine first before driving!" << endl;
        }
    }

    void refuel(double amount) {
        if (amount > 0) {
            fuel += amount;
            cout << "Refueled " << amount << " Liters. Total fuel now: " << fuel << " Liters" << endl;
        } else {
            cout << "Invalid refuel amount!" << endl;
        }
    }

    void speedLimit(int currentSpeed) {
        if (currentSpeed <= 200) {
            speed = currentSpeed;
            cout << "You are driving at a safe speed of " << speed << " kmph." << endl;
        } else {
            speed = 0;
            cout << "You are overspeeding and the engine is stalled for safety. Speed reset to " << speed << " kmph.😭" << endl;
        }
    }

    void triggerCrash(int crashSpeed) {
        
        crash = true;
        speed= crashSpeed;
        cout << "Crash occurred at " << crashSpeed << " kmph" << endl;
    }

    void Airbag() {
        if (crash ) { 
            if (speed > 30) {
                cout << "The safety Airbag Activated to save you from the crash♥️" << endl;
            } else {
                cout << "Drive carefully ... At least you were not speeding and hope everything is fine😭" << endl;
            }
        } else {
            cout << "You are a great driver .. safety before anything 😄" << endl;
        }
    }
    void resetCrash() {
        crash = false; // Reset crash flag for future checks
    }

    void displayInfo() const {
        cout << "Car: " << brand << " " << model << " (" << year << ")" << endl;
        cout << "Total kilometers driven: " << kilometersDriven << " km." << endl;
        cout << "Remaining fuel in the car: " << fuel << " Liters" << endl;
        if (fuel < 5) {
            cout << "WARNING: Fuel level is low! Please refuel soon." << endl;
        }
    }
};

int main() {
    Car myCar("Toyota", "Corolla", 2020);
    myCar.displayInfo();
    myCar.startEngine();
    myCar.drive(50);
    myCar.displayInfo();
    myCar.toggleWipers();
    myCar.toggleWipers();
    myCar.stopEngine();

    // Test low fuel warning
    cout << "\nLow fuel condition" << endl;
    myCar.startEngine();
    myCar.drive(401); 
    myCar.displayInfo();
    
    // Test refueling
    cout << "\nAfter refueling" << endl;
    myCar.refuel(20);
    myCar.displayInfo();

    // Test speed limit
    cout << "\nUnder speed limit" << endl;
    myCar.speedLimit(100);
    
    cout << "\nOver speed limit" << endl;
    myCar.speedLimit(205);

    // Test crash 
    cout << "-----In case of crash with speed of 100 kmph---- " << endl;
    myCar.triggerCrash(100); 
    myCar.Airbag();

    cout << "-----In case of crash with speed of 15 kmph----- " << endl;
    myCar.triggerCrash(15);  
    myCar.Airbag();   

    // No crash
    cout << "----- NO crash )--------" << endl;
    myCar.resetCrash();
    myCar.Airbag();

    return 0;
}
