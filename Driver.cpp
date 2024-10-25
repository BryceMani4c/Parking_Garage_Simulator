/*****************************************************************
	Filename:       Driver.cpp
	Date Created:   Oct 18
	Author:         Alek,Tobin,Bryson
******************************************************************/

#include "LinkedList.h"
#include "ParkingGarage.h"
#include "Vehicle.h"
#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>
using namespace std;

void GenerateCar();

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

// Will generate a completely custom car
template <typename T>
T GenerateCar(){
    srand(time(0));
    string color, make, model, plate = "";
    bool fancyOwner = false;
    int year, randomNumber;

    // Generates a random color for Car
    randomNumber = rand() % 10 + 1;
    switch(randomNumber){
        case 1:
            color = "Silver";
        break;
        case 2:
            color = "Navy";
        break;
        case 3:
            color = "Maroon";
        break;
        case 4:
            color = "Orange";
        break;
        case 5:
            color = "White";
        break;
        case 6:
            color = "Yellow";
        break;
        case 7:
            color = "Green";
        break;
        case 8:
            color = "Cyan";
        break;
        case 9:
            color = "Black";
        break;
        case 10:
            color = "Red";
        break;
        default:
            cout << "error" << endl;
    }

    // Generates A random Number for make of the car
    randomNumber = rand() % 10 + 1;
    switch(randomNumber){
        case 1:
            make = "Kia";
        break;
        case 2:
            make = "Chevrolet";
        break;
        case 3:
            make = "Nissan";
        break;
        case 4:
            make = "Mercedes-Benz";
        break;
        case 5:
            make = "BMW";
        break;
        case 6:
            make = "Mazda";
        break;
        case 7:
            make = "Volvo";
        break;
        case 8:
            make = "Audi";
        break;
        case 9:
            make = "Subaru";
        break;
        case 10:
            make = "Porshe";
        break;
        default:
            cout << "error" << endl;
    }

    // Generates a random model for the car
    randomNumber = rand() % 10 + 1;
    switch(randomNumber){
        case 1:
            model = "Ranger";
        break;
        case 2:
            model = "Falcon";
        break;
        case 3:
            model = "Vortex";
        break;
        case 4:
            model = "Nova";
        break;
        case 5:
            model = "Striker";
        break;
        case 6:
            model = "Promtus";
        break;
        case 7:
            model = "Storm";
        break;
        case 8:
            model = "Delorian";
        break;
        case 9:
            model = "Subaru";
        break;
        case 10:
            model = "Porshe";
        break;
        default:
            cout << "error" << endl;
    }

    // Generates a random 6 digit ascii number
    for (int i = 0; i < 6; i++) {
        char randomChar = 32 + rand() % (126 - 32 + 1);
        plate += randomChar;
    }

    // gives a 5% chance to be a fancy Owner
    randomNumber = rand() % 20 + 1;
    if(randomNumber == 1){
        fancyOwner = true;
    }

    // Randomly generates a car that can be up to 100 years old.
    year = rand() % 100 + 1924;

    // Calls Vehicle constructor with randomly generated values
    return Vehicle(color, make, model, plate, fancyOwner, year);

}