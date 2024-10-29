/*****************************************************************
	Filename:       Storage.h
	Date Created:   Oct 18
	Author:         Alek,Tobin,Bryson
    Purpose:        Template class array Storage<Vehicle>
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
        parkingLot(){
            lotName = "";
            spaces = 0;
            premiumSpaces = 0;
        }

        parkingLot(string inLotName, int inSpaces, int inPremiumSpaces){
            lotName = inLotName;
            spaces = inSpaces;
            premiumSpaces = inPremiumSpaces;
        };
        
        void append(T vehicle){
            theParkingLot.appendNode(vehicle);
        };
        void display(){
            cout << *this;
            theParkingLot.displayList();
        }

        friend ostream& operator<<(ostream& os, const parkingLot<T>& lot) {
        os << "Parking Lot Name: " << lot.lotName << "\nSpaces: " << lot.spaces << "\nPremium Spaces: " << lot.premiumSpaces;
        return os;
        }   
        
        ~parkingLot(){
        }
};

#endif