/*****************************************************************
	Filename:       ParkingGarage.h
	Date Created:   Oct 18
	Author:         Alek,Tobin,Bryson
    Purpose:        Is a linked list of Parking Lots, 
                    LinkedList< Storage< Vehicle > >
******************************************************************/
#ifndef parkingGarage_h
#define parkingGarage_h

#include "LinkedList.h"
#include "Storage.h"
#include "Vehicle.h"
#include <iostream>

class ParkingGarage {
private:
	List<parkingLot<Vehicle>> parkingLots;

public:
    ParkingGarage() = default;

    void addParkingLot(const parkingLot<Vehicle>& newLot) {
        parkingLots.appendNode(newLot);
    }

    void displayParkingLots() const {
        parkingLots.displayList();
    }

    void deleteParkingLot(int position) {
        parkingLots.deleteNode(position);
    }

    bool isEmpty() const {
        return (parkingLots.first() == nullptr);
    }
};

#endif