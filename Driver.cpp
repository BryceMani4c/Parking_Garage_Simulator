//File Name:    Driver.cpp
//Author(s):    Bryson Bargas,

#include "LinkedList.h"
#include "ParkingLotManager.h"
#include "Vehicle.h"
#include <iostream>
using namespace std;

int main(){
    int day = 1;
    double Balance = 200.00;
    int choice;
    cout << " _ _ _     _                     " << endl;
    cout << "| | | |___| |___ ___ _____ ___   " << endl;
    cout << "| | | | -_| |  _| . |     | -_|  " << endl;
    cout << "|_____|___|_|___|___|_|_|_|___|  " << endl;
    cout << "                                 " << endl;

    cout << "to Parking Garage Simulator, where you can build up your Parking Garage Empire!";
    cout << "\nPress Enter to start!";
    cin.ignore();
    cout << "You will be starting on Day 1 with a total of $200.00, when you start the day ";

    while(choice != 5){
        do{
            cout << "\n\n\n>>>> Day " << day << " <<<<\n";
            cout << "Balance: $" << Balance;
            cout << "\nWhat Would you like to do?";
            cout << "\n1. Purchase/Build a lot";
            cout << "\n2. Destroy lot";
            cout << "\n3. Edit/Upgrade lot";
            cout << "\n4. End the Day";
            cout << "\n5. End the Program";
            cout << "\nCHOOSE 1-5:  ";
            cin >> choice;

            switch(choice){
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    cout << "\nCongratulations on finishing Day " << day << "!!";
                    cout << "\nYou ended the day with a balance of $";
                    cout << Balance;
                    cout << "\nPress Enter to start the next day!\n";
                    cin.ignore();
                    cin.get();
                    day++;
                    break;
                case 5:
                    break;
                
            }

        } while(choice != 5 && choice != 4);
    }

    cout << "\n\nThank you for playing our Garage Simulator! You finished on day ";
    cout << day;
    cout << " with a balance of $";
    cout << Balance;
    cout << "\n\nPress Enter to exit the program...";
    
    cin.ignore();
    cin.get();

    return 0;
}