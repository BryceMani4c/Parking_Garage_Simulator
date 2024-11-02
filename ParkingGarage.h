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

class ParkingGarage{
    private:
        List<parkingLot<Vehicle> > parkingLots;

    public:
        //adds a new lot to the parking garage linked list
        void addParkingLot(parkingLot<Vehicle>& newLot){
            parkingLots.appendNode(newLot);
        }
        //displays the linked lists contents using the linkedlist's function
        void displayParkingLots(){
            parkingLots.displayList();
        }
        //quick sort ascending using LinkedList's function
        void quickSortParking(){
            parkingLots.quickSortWrapper();
        }
        //quick sort descending using linkedList's function
        void quickSortParkingDescending(){
            parkingLots.quickSortWrapperDescending();
        }
        //delete a particular lot using an index and passing it through to the
        void deleteParkingLot(int position){
            parkingLots.deleteNode(position);
        }
        //checks ig the garage is empty
        bool isEmpty(){
            return parkingLots.first() == nullptr;
        }

        /*
            Function: NumberOfLots
            Purpose: counts the lot nodes and returns an int for the count
        */
        int numberOfLots(){
            int count = 0;
            Node<parkingLot<Vehicle> >* current;
            current = parkingLots.first();

            while(current != nullptr){
                count++;
                current = current->nextNode;
            } 
            return count;
        }

        /*
            Function: getParkingLot
            Purpose: Finds a parkinglot node using an index and returns it
            Used for accessors
        */
        parkingLot<Vehicle>* getParkingLot(int index){
            Node<parkingLot<Vehicle> >* current;
            current = parkingLots.first();
            int currentIndex = 0;

            while(current != nullptr){
                if(currentIndex == index){
                    return &current->element;
                }
                current = current->nextNode;
                currentIndex++;
            }
            return nullptr;
            }
    };

#endif