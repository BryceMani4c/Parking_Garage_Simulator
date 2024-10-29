/*****************************************************************
	Filename:       Driver.cpp
	Date Created:   Oct 18
	Author:         Alek,Tobin,Bryson
******************************************************************/

#include "LinkedList.h"
#include "ParkingGarage.h"
#include "Vehicle.h"
#include "Storage.h"
#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <Vector>
#include <random>
using namespace std;

Vehicle GenerateCar();
void CreateParkingLot();
void DeleteLot();
void NewDay();
void EndGame();
ParkingGarage garage;
double balance = 200.00;
int day = 0;
random_device rd;
mt19937 gen(rd());
int lower, upper;
uniform_int_distribution<> distrib(lower, upper);

int main(){
    int choice;
    cout << " _ _ _     _                     " << endl;
    cout << "| | | |___| |___ ___ _____ ___   " << endl;
    cout << "| | | | -_| |  _| . |     | -_|  " << endl;
    cout << "|_____|___|_|___|___|_|_|_|___|  " << endl;
    cout << "                                 " << endl;

    cout << "to Parking Garage Simulator, where you can build up your Parking Garage Empire!";
    cout << "\nPress Enter to start!";
    cin.ignore();
    cout << "\nYou will be starting on Day 0 with a total of $200.00 to start your empire off!\nOnce you have build your first lot, start the next day!";

    while(choice != 5){
        do{
            cout << "\n\n>>>> Day " << day << " <<<<\n";
            cout << "Balance: $" << balance;
            cout << "\nWhat Would you like to do?";
            cout << "\n1. Purchase/Build a lot";
            cout << "\n2. Destroy lot";
            cout << "\n3. View Lot(s)";
            cout << "\n4. Start the next Day";
            cout << "\n5. End the Program";
            cout << "\nCHOOSE 1-5:  ";
            cin >> choice;

            switch(choice){
                case 1:
                    CreateParkingLot();
                    break;
                case 2:
                    DeleteLot();
                    break;
                case 3:
                    break;
                case 4:
                    NewDay();
                    break;
                case 5:
                    cout << "\n\nThank you for playing our Garage Simulator! You finished on day ";
                    cout << day;
                    cout << " with a balance of $";
                    cout << balance;
                    cout << "\n\nPress Enter to exit the program...";
                    cin.ignore();
                    cin.get();
                    break;  
        }} while(choice != 5);
    } return 0;
}

Vehicle GenerateCar(){
    string color, make, model, plate = "";
    bool fancyOwner = false;
    int year, randomNumber;
    lower = 1;
    upper = 10;

    // Generates a random color for Car
    srand(time(NULL));
    randomNumber = distrib(gen);
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
    srand(time(NULL));
    randomNumber = distrib(gen);
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
    srand (time(NULL));
    randomNumber = distrib(gen);
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
    char randomChar;
    lower = 1;
    upper = 95;
    for (int i = 0; i < 6; i++) {
        srand (time(NULL));
        randomNumber = distrib(gen);
        plate += randomChar;
    }

    // gives a 5% chance to be a fancy Owner
    lower = 1;
    upper = 95;
    srand(time(NULL));
    randomNumber = distrib(gen);
    if(randomNumber == 1){
        fancyOwner = true;
    }

    // Randomly generates a car that can be up to 100 years old.
    lower = 1980;
    upper = 2025;
    uniform_int_distribution<> distrib(lower, upper);
    srand(time(NULL));
    year = distrib(gen);

    // Calls Vehicle constructor with randomly generated values
    return Vehicle(color, make, model, plate, fancyOwner, year);
};

void CreateParkingLot(){
    string name;
    int space, pspace = 0;
    bool flag;

    cout << "Insert the name of your new parking lot: ";
    cin >> name;

    flag = false;
    do{
        if(flag == true){
            cout << "You do not have the funds to purchase that many spaces please try again...\n";
        };
        cout << "How many normal parking spaces would you like to construct ($5 each): ";
        cin >> space;
        if(balance - space*5 < 0){
            flag = true;
        }
    }while(balance - space*5 < 0);

    flag = false;
    do{
        if(flag == true){
            cout << "You do not have the funds to purchase that many premium spaces please try again...\n";
        };
        cout << "How many Premium Spaces would you like to buy? ($10 each): ";
        cin >> pspace;
        if(balance - space*10 < 0){
            flag = true;
        }
    }while(balance - space*10 < 0);

    balance = (balance - (space*5) - (pspace*10));

    parkingLot<Vehicle> newLot(name, space, pspace);
    garage.addParkingLot(newLot);

    cout << "\nParking lot '" << name << "' created with " << space << " spaces and " << pspace << " premium spaces.\n";
}

void DeleteLot(){
    if(garage.isEmpty()){
        "\nThere are no Parking Lots to demolish, please select a different choice...\n\n";
        return;
    } else{
        int i = 0;
        int lots = garage.numberOfLots();
        while(i <= 0 || i > lots){
            cout << "Please select which lots you would like to destroy..\n";
            garage.displayParkingLots();
            cout << "\n\nlots you wish to destroy: ";
            cin >> i;
            if(i <= 0 || i > lots){
                cout << "Invalid Choice, pleasse try again\n";
            }
        }
        garage.deleteParkingLot(i);
        cout << "You have sucessfully deleted Parking Garage number " << i << "\n";
        }
    }

void NewDay(){
    cout << "\nCongratulations on finishing Day " << day << "!!";
    cout << "\nYou ended the day with a balance of $";
    cout << balance;
    cout << "\nPress Enter to start the next day!\n";
    cin.ignore();
    cin.get();
    day++;

    
    random_device rd;
    mt19937 gen(rd());
    int randomNumber;
    int lower = 1;
    int upper = 15;
    srand(time(NULL));
    randomNumber = distrib(gen);

    int j, i;
    parkingLot<Vehicle>* targetLot = nullptr;
    lower = 1;
    upper = garage.numberOfLots();
    while(i != 0){
        srand(time(NULL));
        j = distrib(gen);
        Vehicle newVehicle = GenerateCar();
        parkingLot<Vehicle>* selectedLot = garage.getParkingLot(j);
        selectedLot->append(newVehicle);
        cout << "\nadded cars to index " << j;
    }}

void EndGame(){
    cout << "\n\nThank you for playing our Garage Simulator! You finished on day ";
    cout << day;
    cout << " with a balance of $";
    cout << balance;
    cout << "\n\nPress Enter to exit the program...";
    cin.ignore();
    cin.get();
    }