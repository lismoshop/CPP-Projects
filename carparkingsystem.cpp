#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Parking {
    private:
    string carnum_ = "";
    string cartype_ = "";
    int entrytime_ = 0;
    int exittime_ = 0;
    int charge_ = 0;

    public:
        void carType(string typeofcar) {cartype_ = typeofcar;}
        void carNum(string numofcar) {carnum_ = numofcar;}
        void entryTime(int timeofentry) {entrytime_ = timeofentry;}
        void exitTime(int timeofexit) {exittime_ = timeofexit;}
        int charges(){
            int totaltime = exittime_ - entrytime_;
            if(totaltime <= 100) {
                charge_ = 50;
            } else if(totaltime > 100 && totaltime < 300) {
                charge_ = 100;
            } else if(totaltime > 300 && totaltime < 1000) {
                charge_ = 500;
            } else if (totaltime< 1000) {
                charge_ = 1000;
            }
            return charge_;
        }
        void generateBill() {
            cout << "\n\n************ PARKING CHARGES ************" << endl;
            cout << " Type Of Vehicle: " << cartype_ << endl;
            cout << " Number of Car: " << carnum_ << endl;
            cout << " Time of Entry: " << entrytime_/100 << ":" << entrytime_%100<< endl;
            cout << " Time of Exit: " << exittime_/100 << ":" << exittime_%100<< endl;
            cout << "******************************************" << endl << endl;
            cout << "\tTotal cost: " << charge_ << endl << endl;
            cout << "******************************************" << endl;
            cout << "\tThanks for parking here." << endl;
            cout << "\tWe wish you visit again :)" <<endl;
            cout << "******************************************" << endl;
        }
};  

int main() {
    int methodinput;
    bool state = 1;
    Parking v;

    while(state) {
        cout << "****************Welcome to INDEX SOFTWARE(Car Parking)*************" << endl;
        cout << "Press 0 to open help menu." << endl;
        cout << "Press 1 to enter vehiclenum" << endl;
        cout << "Press 2 to enter vehicletype." << endl;
        cout << "Press 3 to enter time of entry." << endl;
        cout << "Enter 4 to enter time of exit." << endl;
        cout << "Enter 5 to generate bill." << endl;

        cin >> methodinput;

        if(methodinput == 0) {
            cout << "--------------------Welcome to help menu.--------------------" << endl;
            cout << "Vehicle type list is as follows: " << endl;
            cout << "\t2-Wheelers: 1\n\tCars: 2\n\tTrucks: 3" <<endl;
            cout << "Entry and exit time must be in 24 hour clock system i.e., 2300 , 1400, 2231, etc." << endl;
            cout << "--------------------------------------------------------------" << endl;
            continue;
        } else if(methodinput == 1) {
            string vehiclenuminp;
            cout << "Enter the Number of Vehicle: ";
            cin >> vehiclenuminp;
            v.carNum(vehiclenuminp);
            continue;
        } else if(methodinput == 2) {
            int vehicletypeinp;
            cout << "Enter the type of vehicle(in num): ";
            cin >> vehicletypeinp;
            if(vehicletypeinp == 1) {
                v.carType("2-Wheeler");
            } else if(vehicletypeinp == 2) {
                v.carType("Car");
            } else if(vehicletypeinp == 3) {
                v.carType("Heavy Load Vehicle");
            } else {
                cout << "Invalid Input";
                break;
            }
            continue;
        } else if(methodinput == 3) {
            int entrytimeinp;
            cout << "Enter the time of entry: ";
            cin >> entrytimeinp;
            if(entrytimeinp > 2359 || entrytimeinp < 0 || (entrytimeinp %100) > 59) {
                cout << "Not a valid time entered.";
                break;
            }
            v.entryTime(entrytimeinp);
            continue;

        } else if(methodinput == 4) {
            int exittimeinp;
            cout << "Enter the time of exit: ";
            cin >> exittimeinp;
            if(exittimeinp > 2359 || exittimeinp < 0 || (exittimeinp %100) > 59) {
                cout << "Not a valid time entered.";
                break;
            }
            v.exitTime(exittimeinp);
            continue;
        } else if(methodinput == 5) {
            state = 0;
        } else {
            cout << "Entered value is not valid.";
            break;
        }
    }
    if(state == 0) {
        v.generateBill();
    }
    return 0;
}