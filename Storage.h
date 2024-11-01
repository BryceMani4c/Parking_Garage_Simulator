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

template <typename T>

class parkingLot{
    private:
        string lotName;
        int spaces;
        int premiumSpaces;
        List<T> theParkingLot;

    public:
        parkingLot(){ //default constructor
            lotName = "";
            spaces = 0;
            premiumSpaces = 0;
        }

        parkingLot(string inLotName, int inSpaces, int inPremiumSpaces){ //constructor
            lotName = inLotName;
            spaces = inSpaces;
            premiumSpaces = inPremiumSpaces;
        };
        //Linked List Wrapper to append a vehicle to the storage class linked list
        void append(T vehicle){
            theParkingLot.appendNode(vehicle);
        };
        //******redundant? - TM
        void display(){
            cout << *this;
            theParkingLot.displayList();
        };
        //Getters and setters
        string getLotname(){
            return this->lotName;
        };
        void setLotName(string inName){
            lotName = inName;
            return;
        }
        int getSpaces(){
            return spaces;
        };
        void setSpaces(int inSpace){
            spaces = inSpace;
            return;
        };
        int getPremiumSpaces(){
            return premiumSpaces;
        };
        void setPremiumSpaces(int inPremiumSpaces){
            premiumSpaces = inPremiumSpaces;
            return;
        };
        //******What does this do? -TM
        void clear(){
            theParkingLot = List<Vehicle>();
        }

        //ostream overload that prints the lot details when the object is attempted to be printed as a node.
        friend ostream& operator<<(ostream& os, const parkingLot<T>& lot){
            os << "\nParking Lot Name: " << lot.lotName << "\nSpaces: " << lot.spaces << "\nPremium Spaces: " << lot.premiumSpaces;
            return os;
        }   

        //Comparative operator overloads that compare the lot by name.
        bool operator<(parkingLot& temp){ 
            if(this->lotName < temp.lotName){
                return true;
            };
            return false;
        };

        bool operator>(parkingLot& temp){ 
            if(this->lotName > temp.lotName){
                return true;
            };
            return false;
        };
        bool operator!=(parkingLot& temp){ 
            if(this->lotName != temp.lotName){
                return true;
            };
            return false;
        };
        ~parkingLot(){
        }
};

#endif