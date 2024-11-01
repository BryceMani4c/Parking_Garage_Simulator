#Makefile for parkinglot program
 
all                 :   Driver
 
Driver            :   Driver.o 
                        g++ -std=c++11 -o Driver.exe Driver.o 
 
Driver.o          :   Driver.cpp
                        g++ -std=c++11 -I ./ -c Driver.cpp
