/*****************************************************************
	Filename:       Storage.h
	Date Created:   Oct 18
	Author:         Alek,Tobin,Bryson
    Purpose:        Template class array Storage<Vehicle>
                    Defines a lot, equivalent to a floor in the garage.
                    File holds:
                        attributes - lotName, regular spaces, premium spaces, and a linked list of objects named theParkingLot
                        functions - constructors, deconstructor, Linked List Wrappers, outstream overload, comparative operator overloads for lotname, and accessors.
******************************************************************/
#ifndef Storage_h
#define Storage_h
#include "Vehicle.h"
#include "LinkedList.h"
/*
    Class: parkingLot
    purpose: class that hold the atributes to the parkinglot along with getters and setters for the parkinglot.
    and comparative operator overloads for lotname, and accessors.

*/
template <typename T>
class parkingLot{
    private:
        string lotName;
        int maxNormalSpaces;
        int maxPremiumSpaces;
        int normalSpaces;
        int premiumSpaces;
        List<T> theParkingLot;

    public:
        /*
            Constructors and deconstructor
        */
        parkingLot(){}
        parkingLot(string inLotName, int inSpaces, int inPremiumSpaces){ //constructor
            lotName = inLotName;
            normalSpaces = inSpaces;
            premiumSpaces = inPremiumSpaces;
            maxNormalSpaces = inSpaces;
            maxPremiumSpaces = inPremiumSpaces;
        }
        ~parkingLot(){
        }
        //Linked List Wrapper to append a vehicle to the storage class linked list
        void append(T vehicle){
            theParkingLot.appendNode(vehicle);
        }
        //Displays Current lot details. Calls os overload. Also calls the display list function from linked list, which uses the os overload in the vehicle object.
        void display(){
            cout << endl << endl<< "LotName: " << lotName;
            theParkingLot.displayList();
        }
        //Getters and setters
        string getLotname(){
            return this->lotName;
        }
        void setLotName(string inName){
            lotName = inName;
            return;
        }
        int getSpaces(){
            return normalSpaces;
        }
        void setSpaces(int inSpace){
            normalSpaces = inSpace;
            return;
        }
        int getPremiumSpaces(){
            return premiumSpaces;
        }
        void setPremiumSpaces(int inPremiumSpaces){
            premiumSpaces = inPremiumSpaces;
            return;
        }
        int getMaxPremiumSpaces(){
            return maxPremiumSpaces;
        }
        void setMaxPremiumSpaces(int inMaxPremiumSpaces){
            maxPremiumSpaces = inMaxPremiumSpaces;
        }
        int getMaxSpaces(){
            return maxNormalSpaces;
        }
        void setMaxSpaces(int inMaxSpaces){
            maxNormalSpaces = inMaxSpaces;
        }

        // Clears and resets values
        void clear(){
            normalSpaces = maxNormalSpaces;
            premiumSpaces = maxPremiumSpaces;
            theParkingLot.clear();
        }



        //ostream overload that prints the lot details when the object is attempted to be printed as a node.
        friend ostream& operator<<(ostream& os, const parkingLot<T>& lot){
            os << "\nParking Lot Name: " << lot.lotName << "\nSpaces: " << lot.maxNormalSpaces << "\nPremium Spaces: " << lot.maxPremiumSpaces;
            return os;
        }   

        //Comparative operator overloads that compare the lot by name.
        bool operator<(parkingLot& temp){ 
            if(this->lotName < temp.lotName){
                return true;
            };
            return false;
        }

        bool operator>(parkingLot& temp){ 
            if(this->lotName > temp.lotName){
                return true;
            };
            return false;
        }
        bool operator!=(parkingLot& temp){ 
            if(this->lotName != temp.lotName){
                return true;
            };
            return false;
        }
};

#endif