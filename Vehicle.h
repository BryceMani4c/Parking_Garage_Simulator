/*****************************************************************
	Filename:       Vehicle.h
	Date Created:   Oct 18
	Author:         Alek,Tobin,Bryson
******************************************************************/

#include <iostream>
using namespace std;

#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle
{
    //Vehicle attributes
    private:
        string color;
        string make;
        string model;
        string plateID;
        bool isFancyOwner;
        int year;
    public:
        //constructor and deconstructor function
        Vehicle(){
            color = "";
            make = "";
            model = "";
            plateID = "";
            isFancyOwner = false;
            year = 0;
        }
        Vehicle(string inColor, string inMake ,string inModel,string inPlateID, bool inIsFancyOwner, int inYear){
            color = inColor;
            make = inMake;
            model = inModel;
            plateID = inPlateID;
            isFancyOwner = inIsFancyOwner;
            year = inYear;
        }
        ~Vehicle(){};
        //Comparative Overloaders

        //getter prototypes
        string getColor();
        string getMake();
        string getModel();
        string getPlateID();
        bool getIsFancyOwner();
        int getYear();
        bool getValue();
        //setter prototypes
        void setColor(string);
        void setMake(string);
        void setModel(string);
        void setPlateID(string);
        void setIsFancyOwner(bool);
        void setYear(int);
        void setValue(double);        
};

    string Vehicle::getColor(){
        return this->color;
    };
    string Vehicle::getMake(){
        return this->make;
    };
    string Vehicle::getModel(){
        return this->model;
    };
    string Vehicle::getPlateID(){
        return this->plateID;
    };
    bool Vehicle::getIsFancyOwner(){
        return this->isFancyOwner;
    };
    int Vehicle::getYear(){
        return this->year;
    };

        //setters
    void Vehicle::setColor(string newColor){
        color = newColor;
    };
    void Vehicle::setMake(string newMake){
        make = newMake;
    };
    void Vehicle::setModel(string newModel){
        model = newModel;
    };
    void Vehicle::setPlateID(string newPlateID){
        plateID = newPlateID;
    };
    void Vehicle::setIsFancyOwner(bool newIsFancyOwner){
        isFancyOwner = newIsFancyOwner;
    };
    void Vehicle::setYear(int newYear){
        year = newYear;
    };
    bool operator<<(Vehicle& lhs, Vehicle& rhs) {
    return lhs.getPlateID() < rhs.getPlateID();
    };
    
#endif