
#ifndef LinkListOverload_h
#define LinkListOverload_h

#include <iostream>
using namespace std;
#include <string>


class details
{   
	private:
		string color;
        string make;
        string model;
        int plateID;
        int year;
		
		
	public:
		//CONSTRUCTORS
		details(){} 
		details(string c,string m,string mo, int p, int y)
		{
			this->color = c;
			this->make = m;
			this->model = mo;
            this->plateID = p;
            this->year = y;
		}
		
		//OVERLOADED << OPERATOR to display the pickle with cout <<
		friend ostream & operator << (ostream & os, details& d)
		{
			os << "\nCar color:" << d.color;
			os << "\nCar Make:" << d.make;
            os << "\nCar model:" << d.model;
            os << "\nCar plateID:" << d.plateID;
            os << "\nCar year:" << d.year;
			return os;
		}
		
		//OVERLOADED relational operators to be able to search for a specific pickle object by type
		bool operator !=(const details& d)
		{
			if(this->year != d.year)
				return true;
			else
				return false;
		}
				
		//OVERLOADED == OPERATOR to be able to search for a specific pickle object by type
		bool operator ==(const details& d)
		{
			if(this->year == d.year)
				return true;
			else
				return false;
		}
};

#endif