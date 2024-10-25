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

    public:
        parkingLot(string inLotName, int inSpaces, int inPremiumSpaces){
            lotName = inLotName;
            spaces = inSpaces;
            premiumSpaces = inPremiumSpaces;
            LinkedList<T> theParkingLot;
        };
        
        void append(T){
            theParkingLot.appendnode(T);
        };
        void display(){

        };

    ~LinkedList(){
    }

};

#endif