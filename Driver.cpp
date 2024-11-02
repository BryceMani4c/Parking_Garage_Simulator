/*****************************************************************
	Filename:       Driver.cpp
	Date Created:   Oct 18
	Author:         Alek,Tobin,Bryson
    Purpose:        Driver file that houses the main menu and functions relating to game logic
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
void ModifyLot();
ParkingGarage garage;
double balance = 2000;
int day = 1;

/*
    Random Number Generator was sourced because srand didn't create unique cars fast enough.
    Different generator was found here:
    https://stackoverflow.com/questions/19665818/generate-random-numbers-using-c11-random-library
*/
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
    cout << "\n\n\tTutorial:\n";
    cout << "\nYou will be starting on Day 1 with a total of $2000.00 to start your empire off!\nOnce you have built your first lot, start the next day!";
    cout << "\nThere are regular and premium spaces.\nOnly fancy drivers will park in premium spaces.";
    cout << "\nYou have 10 days to make 10k!! Good luck trying to figure out the strategy!";
    cout << "\nPress Enter to continue.";
    cin.ignore();

    while(choice != 7 && day < 11){
        do{
            cout << "\n\n>>>> Day " << day << " <<<<\n";
            cout << "Balance: $" << balance;
            cout << "\nWhat Would you like to do?";
            cout << "\n1. Purchase/Build a lot";
            cout << "\n2. Upgrade/Modify a lot";
            cout << "\n3. Destroy a lot";
            cout << "\n4. View Lot(s)";
            cout << "\n5. Sort Parking Garage by lot name";
            cout << "\n6. Run the Day";
            cout << "\n7. End the Program";
            cout << "\nCHOOSE 1-7:  ";
            cin >> choice;

            switch(choice){
                case 1:
                    CreateParkingLot();
                    break;
                case 2:
                    ModifyLot();
                    break;
                case 3:
                    DeleteLot();
                    break;
                case 4:
                    cout << "Displaying your lots:\n";
                    garage.displayParkingLots();
                    break;
                case 5:
                    do{
                    cout << "\nChoose whether to sort ascending(1), descending by Lot name(2), or exit this menu (0).\t";
                    cin >> choice;
                    
                    if(choice == 1)
                        garage.quickSortParking();
                    if(choice == 2)
                        garage.quickSortParkingDescending();
                    
                    }while(choice <0 || choice > 2);
                    break;
                case 6:
                    NewDay();
                    break;
                case 7:
                    cout << "\n\nThank you for playing our Garage Simulator! You finished on day ";
                    cout << day;
                    cout << " with a balance of $";
                    cout << balance;
                    cout << "\n\nPress Enter to exit the program...";
                    cin.ignore();
                    cin.get();
                    break;  
            }
        }while(choice != 7 && day < 11);
        EndGame();
    }
    return 0;
}
/*
    Function: Generate Car
    Purpose: Randomly generates a vehicle with attributes (color, make, model, plate(6 character ascii string from ascii))
    Returns it as a vehicle object.
*/
Vehicle GenerateCar(){
    string color, make, model, plate = "";
    bool fancyOwner = false;
    int year, randomNumber;

    // Generates a random color for Car
    lower = 1;
    upper = 10;
    uniform_int_distribution<> colordistrib(lower, upper);
    randomNumber = colordistrib(gen);
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
            cout << randomNumber << endl;
    }

    // Generates A random Number for make of the car
    lower = 1;
    upper = 10;
    uniform_int_distribution<> makedistrib(lower, upper);
    randomNumber = makedistrib(gen);
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
            cout << randomNumber << endl;
    }

    // Generates a random model for the car
    lower = 1;
    upper = 10;
    uniform_int_distribution<> modeldistrib(lower, upper);
    randomNumber = modeldistrib(gen);
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
            cout << randomNumber << endl;
    }

    // Generates a random 6 digit ascii string, made of numbers, capital letters, and some symbols
    char randomChar;
    lower = 48; //lower bound of numbers in ascii
    upper = 90; //upper bound of capital letters in ascii
    for(int i = 0; i < 6; i++){
        uniform_int_distribution<> platedistrib(lower, upper);
        randomChar = static_cast<char>(platedistrib(gen));
        plate += randomChar;
    }

    // gives a 5% chance to be a fancy Owner
    lower = 1;
    upper = 20;
    uniform_int_distribution<> fancydistrib(lower, upper);
    randomNumber = fancydistrib(gen);
    if(randomNumber == 1){
        fancyOwner = true;
    }

    // Randomly generates year for the car that can be between 1980 and 2025.
    lower = 1980;
    upper = 2025;
    uniform_int_distribution<> yeardistrib(lower, upper);
    year = yeardistrib(gen);

    //Calls Vehicle constructor with the randomly generated values.
    return Vehicle(color, make, model, plate, fancyOwner, year);
};
/*
    Create Parkin Lot function
    Function to create a lot, define attributes, and create it as an object
*/
void CreateParkingLot(){
    string name;
    int space = 0, pSpace = 0;
    bool balanceFlag;
    bool capFlag;
    char choice;
    int lotCapacity = 100;

    //checks if balance is enough to build another lot. Return from func if not enough
    if(balance < 1000){
        cout << "\nSorry, you need at least $1000 to buy another lot\n";
        return;
    }
    cout << "\nA new lot will cost you $1000. (And can be sold for $800 later)\n";
    cout << "Are you sure you want to buy a lot? (enter Y/N): ";
    cin >> choice;

    //input validation for input
    while(choice != 'y' && choice != 'Y' ){
        if(choice == 'n'|| choice == 'N'){
            return;
        }
        else{
            cout << "\nInvalid input Enter (Y or N)";
            cin >> choice;
        };
    };
    //reduce balance for the lot
    balance -= 1000;
    cout << "Insert the name of your new parking lot: \n";
    cin.ignore();
    getline(cin, name);
    cout << "Lots can hold up to 100 cars.\nYou can have a combination of normal spaces and premium spaces that total up to 100\n";
    //possibly redundant flag reset
    balanceFlag = false;
    capFlag = false;
    //do-while loop that uses a flag for capacity and a flag for balance
    do{
        if(capFlag == true){
            cout << "\nYour lot cannot hold that many spaces. Please try again\n";
        }
        if(balanceFlag == true){
            cout << "\nYou do not have the funds to purchase that many spaces please try again...\n";
        };
        do{
            cout << "How many normal parking spaces would you like to construct ($5 each): ";
            cin >> space;
        }while(space < 0);
        if(balance - space*5 < 0){
            balanceFlag = true;
        }
        if(space > lotCapacity){
            capFlag = true;
        }
    }while(balance - space*5 < 0 || space > lotCapacity);
    
    //reset flags for premium spaces
    balanceFlag = false;
    capFlag = false;
    do{
        if(capFlag == true){
            cout << "\nYour lot cannot hold that many spaces. Please try again";
        }
        if(balanceFlag == true){
            if(balance - space*5 < 10){
                cout << "\nYou do not have enough balance to buy any premium spaces\n";
                pSpace = 0;
                break;
            }
            cout << "\nYou do not have the funds to purchase that many premium spaces please try again...\n";
        };
        do{
            cout << "\nHow many Premium Spaces would you like to buy? ($10 each): ";
            cin >> pSpace;
        }while(pSpace < 0);
        if((balance - (space*5 + pSpace*10)) < 0){
            balanceFlag = true;
        }
        if(space + pSpace > lotCapacity){
            capFlag = true;
        }
    }while((balance - (space*5 + pSpace*10)) < 0 || (space + pSpace > lotCapacity));//while statement considers both regular spaces and premium

    balance = (balance - (space*5) - (pSpace*10)); //correctly lower overall balance

    parkingLot<Vehicle> newLot(name, space, pSpace); //create a new lot with the temp name and spaces that were logically correct
    garage.addParkingLot(newLot); //adds the lot to the parking garage

    cout << "\nParking lot '" << name << "' created with " << space << " spaces and " << pSpace << " premium spaces.\n";
}

/*
    Function: ModifyLot
    Purpose: Menu Logic to modify and upgrade a lot
    uses accessors to modify the selected lot
*/

void ModifyLot(){
    int index;
    int choice;
    bool capFlag;
    bool balanceFlag;
    string tempName;
    int tempNum;
    //checks if garage is empty
    if(garage.isEmpty()){
        cout << "\nThere is no lot to modify!\n";
        return;
    }
    garage.displayParkingLots();
    cout << "\nChose lot to modify using the index (or enter 0 to quit): ";
    cin >> index;
    //quit case
    if(index == 0){
        return;
    }
    //looping menu that displays details and options
    do{
        cout << "\n\nModifying: "<< garage.getParkingLot(index-1)->getLotname() << endl;
        cout << "Current Normal Spaces: " << garage.getParkingLot(index-1)->getMaxSpaces() << endl;
        cout << "Current Premium Spaces: " << garage.getParkingLot(index-1)->getMaxPremiumSpaces() << endl;
        cout << 100 - garage.getParkingLot(index-1)->getMaxPremiumSpaces() - garage.getParkingLot(index-1)->getMaxSpaces() << " of 100 spaces free.\n";
        cout << "\n1: Change the name of the lot.";
        cout << "\n2: Build more normal parking spaces.";
        cout << "\n3: Upgrade normal spaces to premium spaces.";
        cout << "\n4: Build more premium spaces";
        cout << "\n5: Downgrade premium parking spaces to normal.";
        cout << "\n6. Exit modify/upgrade.";
        cout << "\nSelect menu options using (1-6): ";
        cin >> choice;
        capFlag =  false;
        balanceFlag = false;

        //switch case that holds all of the logic
        switch(choice){
            case 1: 
                //Case to change lot name. Simple enough
                cout << "\n1: What would you change the name of the lot to? : ";
                cin.ignore();
                getline(cin,tempName);
                garage.getParkingLot(index-1)->setLotName(tempName);
                cout << "\nYou have changed the lot's name\n";
                break;
            case 2:
                //build more normal spaces. Reuses logic from original logic for lot creation, but has to consider the premium spots in it's first pass
                if(balance < 5 || (garage.getParkingLot(index-1)->getMaxPremiumSpaces() + garage.getParkingLot(index-1)->getMaxSpaces()) == 100){
                    cout << "\nCannot add more normal spaces.\n";
                    break;
                };
                do{
                    if(capFlag == true){
                        cout << "\nYour lot cannot hold that many spaces. Please try again\n";
                    };
                    if(balanceFlag == true){
                        cout << "\nYou do not have the funds to purchase that many spaces please try again...\n";
                    };
                    do{
                        cout << "\n2: How many more normal spaces would you like to buy?: ";
                        cin >> tempNum;
                    }while(tempNum < 0);
                    if((balance - (tempNum*5)) < 0){
                        balanceFlag = true;
                    }
                    else{
                        balanceFlag = false;
                    }
                    if(tempNum + garage.getParkingLot(index-1)->getMaxPremiumSpaces() + garage.getParkingLot(index-1)->getMaxSpaces() > 100){
                        capFlag = true;
                    }
                    else{
                        capFlag = false;
                    }
                }while(100 < (tempNum + (garage.getParkingLot(index-1)->getMaxPremiumSpaces() + garage.getParkingLot(index-1)->getMaxSpaces())) || (balance - (tempNum*5)) < 0);
                garage.getParkingLot(index-1)->setMaxSpaces(tempNum + garage.getParkingLot(index-1)->getMaxSpaces());
                balance = balance - tempNum*5;
                break;
                
            case 3:{
                    int limit = 0;
                    //upgrade regular to premium logic.
                    cout << "\nThis lot has " << garage.getParkingLot(index-1)->getMaxSpaces() << " normal spaces\n";
                    cout << "\nEach upgrade costs $6, this lot has "; 
                    //if else that tells the user how many spaces can be upgraded, whether the limit is balance or capacity
                    if(balance/6 > garage.getParkingLot(index-1)->getMaxSpaces()){
                        cout << garage.getParkingLot(index-1)->getMaxSpaces() << " spaces that can be upgraded.\n";
                        limit = garage.getParkingLot(index-1)->getMaxSpaces();
                    }
                    else{
                        cout << static_cast<int>(balance)/6 << " spaces that can be upgraded.\n";
                        limit = static_cast<int>(balance)/6;
                    }
                        cout << "\nHow many spaces do you want to upgrade? : ";
                        cin >> tempNum;
                    while(tempNum > limit || tempNum < 0){
                        cout << "\nInvalid choice, try again: ";
                        cin >> tempNum;
                    }
                    //update lot attributes
                    balance = balance - (tempNum*6);
                    garage.getParkingLot(index-1)->setMaxSpaces(garage.getParkingLot(index-1)->getMaxSpaces()-tempNum);
                    garage.getParkingLot(index-1)->setMaxPremiumSpaces(garage.getParkingLot(index-1)->getMaxPremiumSpaces()+tempNum);
                 break;
            }
            case 4:
                //same as case 2
                if(balance < 10 || (garage.getParkingLot(index-1)->getMaxPremiumSpaces() + garage.getParkingLot(index-1)->getMaxSpaces()) == 100){
                    cout << "\nCannot add more normal spaces.\n";
                    break;
                };
                do{
                    if(capFlag == true){
                        cout << "\nYour lot cannot hold that many spaces. Please try again\n";
                    };
                    if(balanceFlag == true){
                        cout << "\nYou do not have the funds to purchase that many spaces please try again...\n";
                    };
                    do{
                        cout << "\n2: How many more premium spaces would you like to buy?: ";
                        cin >> tempNum;
                    }while(tempNum < 0);
                    if((balance - (tempNum*10)) < 0){
                        balanceFlag = true;
                    }
                    else{
                        balanceFlag = false;
                    }
                    if(tempNum + garage.getParkingLot(index-1)->getMaxPremiumSpaces() + garage.getParkingLot(index-1)->getMaxSpaces() > 100){
                        capFlag = true;
                    }
                    else{
                        capFlag = false;
                    }
                }while(100 < (tempNum + (garage.getParkingLot(index-1)->getMaxPremiumSpaces() + garage.getParkingLot(index-1)->getMaxSpaces())) || (balance - (tempNum*10)) < 0);
                garage.getParkingLot(index-1)->setMaxPremiumSpaces(tempNum + garage.getParkingLot(index-1)->getMaxPremiumSpaces());
                balance = balance - tempNum*10;
                break;
            
            case 5:
                //same as case 3
                {
                    int limit = 0;
                    cout << "\nThis lot has " << garage.getParkingLot(index-1)->getMaxPremiumSpaces() << " premium spaces\n";
                    cout << "\nEach downgrade refunds $3";
                    limit = garage.getParkingLot(index-1)->getMaxPremiumSpaces();
                    
                
                    cout << "\nHow many premium spaces do you want to downgrade? : ";
                    cin >> tempNum;
                    while(tempNum > limit || tempNum < 0){
                        cout << "\nInvalid choice, try again: ";
                        cin >> tempNum;
                    }
                    balance = balance + (tempNum*3);
                    garage.getParkingLot(index-1)->setMaxSpaces(garage.getParkingLot(index-1)->getMaxSpaces()+tempNum);
                    garage.getParkingLot(index-1)->setMaxPremiumSpaces(garage.getParkingLot(index-1)->getMaxPremiumSpaces()-tempNum);
                 break;
                }
            case 6:
                cout <<"\nYou've finished Modifying your ParkingLot"; 
                
                break;
        }
    }while(choice != 6);
}
/*
    Function: Delete lot
    Purpose: Displays lots, and asks the user to input an idex to delete the specific lot.
*/
void DeleteLot(){
    if(garage.isEmpty()){
        cout << "\nThere are no Parking Lots to demolish, please select a different choice...\n\n";
        return;
    }
    else{
        int i = 0;
        int lots = garage.numberOfLots();
        while(i <= 0 || i > lots){
            cout << "Please select which lots you would like to destroy..(Using the node index)\n";
            garage.displayParkingLots();
            cout << "\n\nEnter the index of the lot you wish to destroy(Or enter 0 to cancel operation): ";
            cin >> i;
            if(i < 0 || i > lots){
                cout << "Invalid Choice, please try again\n";
            }
            if(i==0){
                return;
            }
        }
        //calls the delete and refunds 800
        garage.deleteParkingLot(i-1);
        cout << "You have sucessfully deleted Parking Lot number " << i << "\n";
        cout << "You have been refunded $800\n";
        balance += 800;
        }
}
/*
    Function: New Day
    Purpose: Per day logic that decides how many spots to fill and calls the car generator to add the vehicle objects to the lot's linked list
*/
void NewDay(){
    char choice;
    int numLots = garage.numberOfLots();
    int totalSpaces = 0;
    //resets lots. usually redundant but necessary to sync changes if a lot was modified
    for(int i = 0; i < numLots; i++){
        parkingLot<Vehicle>* lot;
        lot = garage.getParkingLot(i);
        if (lot != nullptr){
            lot->clear();
        }
    }
    // calculates the total number of spaces across all garages
    for(int i = 0; i < numLots; i++){
        parkingLot<Vehicle>* lot;
        lot = garage.getParkingLot(i);
        if(lot != nullptr){
            totalSpaces += lot->getSpaces() + lot->getPremiumSpaces();
        }
    }

    if(totalSpaces == 0){
        cout << "You have no lots! Please buy a lot before running the day. Or exit the if you can't afford one\n";
        return;
    }

    //Dictates how many cars will use the parking garages today
    int minCars = static_cast<int>(totalSpaces * 0.7); //int representing 70% of total spaces
    int maxCars = static_cast<int>(totalSpaces * 0.95); //int representing 95% of total spaces
    int numberOfCars = rand() % (maxCars - minCars + 1) + minCars;
    int numNormal = 0, numPremium = 0;

    //Calls the generate car func and assignes it to a parking spot in a random garage
    for(int i = 0; i < numberOfCars; i++){
        Vehicle newCar = GenerateCar();
        bool carAssigned = false;
        int attempts = 0;
        //while loop that attempts to place the genereated car in a garage
        while(!carAssigned && attempts < numLots){
            //Randomly decided which lot to insert car into
            int randomLotIndex = rand() % numLots;
            parkingLot<Vehicle>* randomLot = garage.getParkingLot(randomLotIndex);
            if(randomLot != nullptr){
                //Checks if fancy owner and if there is a space for premium owner
                if(newCar.getIsFancyOwner() && randomLot->getPremiumSpaces() > 0){
                    randomLot->append(newCar);
                    randomLot->setPremiumSpaces(randomLot->getPremiumSpaces() - 1);//reduce empty premium spaces in that lot for later passes
                    balance += 50; //gain $50 from the fancy car owner
                    numPremium++;
                    carAssigned = true;
                //If car isn't fancy owner (normal owner) and there is enough space for car owne
                }else if(!newCar.getIsFancyOwner() && randomLot->getSpaces() > 0){
                    randomLot->append(newCar);
                    randomLot->setSpaces(randomLot->getSpaces() - 1);//reduce normal emtpy spaces in that lot for later passes
                    balance += 5; //gain 5 from the car owner
                    numNormal++;
                    carAssigned = true;
                }
            }
            attempts++;
        }
    }

    cout << "The day has ended with " << numNormal << " normal and " << numPremium << " premium parking pass purchases.\n";
    day++;

    //Ask the user if they would like to see the cars that parked in all of their lots that day
    cout << "\nWould you like to see details of the cars that chose to park? (Y/N):";
    cin >> choice;
    if(choice == 'y'|| choice == 'Y'){
        for(int i = 0; i < numLots; i++){
            cout << endl;
            garage.getParkingLot(i)->display();
        }
    }
    // emptys all the garages at the end of the day
    for(int i = 0; i < numLots; i++){
        parkingLot<Vehicle>* lot = garage.getParkingLot(i);
        if (lot){
            lot->clear();
        }
    }
}
/*
    Function: End Game
    Purpse: called at the end of Day 10 to see if the player won or lost
*/
void EndGame(){
    if(day > 10 && balance > 10000.00){                                              
        cout << endl;                                                         
        cout <<"\n                         _       _     _   _             ";
        cout <<"\n ___ ___ ___ ___ ___ ___| |_ _ _| |___| |_|_|___ ___ ___ ";
        cout <<"\n|  _| . |   | . |  _| .'|  _| | | | .'|  _| | . |   |_ -|";
        cout <<"\n|___|___|_|_|_  |_| |__,|_| |___|_|__,|_| |_|___|_|_|___|";
        cout <<"\n            |___|                                        "; 
        cout << endl;                               
        cout <<"\n __ __ _____ _____    _ _ _ _____ _____ ";
        cout <<"\n|  |  |     |  |  |  | | | |     |   | |";
        cout <<"\n|_   _|  |  |  |  |  | | | |  |  | | | |";
        cout <<"\n  |_| |_____|_____|  |_____|_____|_|___|";   
        cout << "\n\nThank you for playing our Garage Simulator! You finished on day 10";
        cout << " with a balance of $";
        cout << balance;
        cout << "\n\nPress Enter to exit the program...";
        cin.ignore();
        cin.get();
    }
    else if(day > 10){
    cout <<"\n                                              "; 
    cout <<"\n __ __ _____ _____    __    _____ _____ _____ ";
    cout <<"\n|  |  |     |  |  |  |  |  |     |   __|   __|";
    cout <<"\n|_   _|  |  |  |  |  |  |__|  |  |__   |   __|";
    cout <<"\n  |_| |_____|_____|  |_____|_____|_____|_____|";
    cout <<"\n                                              ";
    cout << "\n\nThank you for playing our Garage Simulator! You finished on day 10";
    cout << " with a balance of $";
    cout << balance;
    cout << "\n\nPress Enter to exit the program...";
    cin.ignore();
    cin.get();
    
    
    }
}
