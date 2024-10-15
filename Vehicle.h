/*
File: Vehicle.h
Purpose: Header file to hold characteristics of each vehicle
*/
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
        string ownerName;
        bool isFancyOwner;
        int year;
        double value;
    public:
        //constructor and deconstructor function prototypes
        Vehicle(string,string,string,string,string);
        ~Vehicle();
        //Comparative Overloaders

        //getter prototypes
        string getColor();
        string getMake();
        string getModel();
        string getPlateID();
        string getOwnerName();
        bool getIsFancyOwner();
        int getYear();
        bool getValue();
        //setter prototypes
        void setColor(string);
        void setMake(string);
        void setModel(string);
        void setPlateID(string);
        void setOwnerName(string);
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
    string Vehicle::getOwnerName(){
        return this->ownerName;
    };
    bool Vehicle::getIsFancyOwner(){
        return this->isFancyOwner;
    };
    int Vehicle::getYear(){
        return this->year;
    };
    bool Vehicle::getValue(){
        return this->value;
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
    void Vehicle::setOwnerName(string newOwnerName){
        ownerName = newOwnerName;
    };
    void Vehicle::setIsFancyOwner(bool newIsFancyOwner){
        isFancyOwner = newIsFancyOwner;
    };
    void Vehicle::setYear(int newYear){
        year = newYear;
    };
    void Vehicle::setValue(double newValue){
        value = newValue;
    };
    
#endif