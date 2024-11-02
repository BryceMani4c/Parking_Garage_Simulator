# program #2
READ.ME
Project 2 for CSC 1310
Group Members Tobin McGee, Alek Presley, Bryson Bargas

****important*****
Random Number Generator was sourced because srand didn't create unique cars fast enough!!!!!
https://stackoverflow.com/questions/19665818/generate-random-numbers-using-c11-random-library

Program: ParkingLot Garage Manager

Details: A video game where the player builds and upgrades parking  lots to make money.

Classes: Linked List, Node, Storage, Parking Garage, Vehicle
Structure: 
    Driver - Menu Logic and Day sim logic
    LinkedList - linked list and node classes and functions to manipulate and sort. Uses template objects.
    Parking Garage - A linked List of Parking lots. Functions to manipulate each lot
    Storage - The parking lot objects, linked list of vehicles. Holds overloads to be usuable in template nodes.
    Vehicle - object that holds the attributes of each vehicle. Holds overloads to be usuable in template nodes.

How to Play:
    You buy a lot on day one and buid a combination of regular spaces and premium spaces. 
    Then you run the day where a random num of cars tries to park in your lot(s).
    With the revenue you can edit your lot. By adding more of either kind (if you have room) or change a regular spot to a premium for a fee, or vise versa for a small refund.
    You must devise a strategy of how many lots to buy before locking in to win with profit, choosing to sell lots in the last day, and the ratio of normal to premium slots.
    Good Luck!