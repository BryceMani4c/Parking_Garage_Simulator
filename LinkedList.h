/*****************************************************************
	Filename:       Linklist
	Date Created:   Oct 18
	Author:         Alek,Tobin,Bryson
******************************************************************/

#ifndef LinkedList_H
#define LinkedList_H

#include <iostream>
using namespace std;
template <typename T>
class List
{
	private:
	//struct to hold the template element and the address to the next node
		struct Node 
		{
			T element;
			Node *nextNode;
			Node *prevNode;
		}; 

		Node *head;	
		Node *tail;		

	public:
		List()
		{ 
			head = NULL; 
			tail = NULL;
		}
		~List(){
            Node* nextNode;
            while(head != NULL){ //while the head doesn't equal null
                nextNode = head->nextNode; //get the node in front of head
				cout << "\n*****DELETING the parking slot with address:   " << head; //printing out the head
                delete head; //delete the node
                head = nextNode; //set head = to the next node
            }
		};
		void appendNode(T element){
			Node* newNode = new Node;//creating node
            newNode->element = element;//setting the newnodes element equal to the element
            newNode->prevNode = tail; //pointing newnode to the tail
            if(head == NULL){ // if head equals null sets the head and tail to the newNode
                head = newNode;
                tail = newNode; 
            }
            else{
                tail->nextNode = newNode; //tails next is set to point to the new node
                tail = newNode; //setting tail to that new newnode
                tail->nextNode = NULL;
            }
        };
		void deleteNode(int position){
			if(head == NULL){ //if head equals Null that means there is nothing to delete
				cout << "There is no parking slot to delete" << endl;
				return;
			}
			if(position == 0){ //checks if the position is at the head
				Node *tmp = head; 
				head = head->nextNode; //moving head to the address it was pointing to
                tail = tail->prevNode;
				cout << "-----DELETING the parking slot " << endl;
				delete tmp; //deleting tmp aka the start
			}
			else{
				Node* current = head; //creating node
            	Node* previous = NULL; //previous
				for(int i = 0; i < position&& current != NULL; i++){ //loops untill it hits the position and til curent doesn't equal null
					previous = current; 
					current = current->nextNode; //moving current to the nextnode
				}
				previous->nextNode = current->nextNode; //connects gap after deleting current
				cout << "-----DELETING the parking slot " << endl; //prints memeory address
				delete current;
			}
		}
        void displayList(){
            if(head == NULL){ //if head equals null then print nothing is in the list
                cout << "\n\nThere is nothing in the parking lot";
				return;
            }
            else{
                Node* current = head; //set current to the head
				int i =0; //node counter
                while(current != NULL){ //while current doesn't equal to null
					i++;
					cout << "\n\n----Parking slot " << i << " with the memory address " << current; //prints memory address
					cout << current->element; //overloaded operator
                    current = current->nextNode; //current is set to the next node which current is point to 
                }
            }
        }
};



#endif