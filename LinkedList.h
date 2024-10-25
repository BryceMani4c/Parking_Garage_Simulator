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
				cout << "\n*****DELETING node with address:   " << head; //printing out the head
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
				cout << "There is no node to delete" << endl;
				return;
			}
			if(position == 0){ //checks if the position is at the head
				Node *tmp = head; 
				head = head->nextNode; //moving head to the address it was pointing to
                tail = tail->prevNode;
				cout << "-----DELETING the node " << endl;
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
				cout << "-----DELETING the node " << endl; //prints memeory address
				delete current;
			}
		}
        void displayList(){
            if(head == NULL){ //if head equals null then print nothing is in the list
                cout << "\n\nThere is nothing List";
				return;
            }
            else{
                Node* current = head; //set current to the head
				int i =0; //node counter
                while(current != NULL){ //while current doesn't equal to null
					i++;
					cout << "\n\n----Node " << i << " with the memory address " << current; //prints memory address
					cout << current->element; //overloaded operator
                    current = current->nextNode; //current is set to the next node which current is point to 
                }
            }
        }
		Node* first(){
			return head; //returns head 
		}

		Node* findNode(T& element){
			Node* p = first(); //gets the head of the list
			while(p != NULL){ //checks if list is null 
				if(p->element == element){ //
					return p; //means that there is only 1 element
				}
				p= p->next; //moves to the next node to check
			}
			return NULL;
		}
		//partition function for quicksort
		Node* partition(Node* low, Node* high){
			T pivot = high->element; //Pivot point is chosen to be whatever is the "high" node
			Node* i = low->prev; //first index node to compare with second index node

			//for loop that uses a second index to compare the current temp element against pivot
			for(Node* j = low; j != high; j = j->next){
				//If the current element is less than pivot, "increment" index node i
				if(j->element < pivot){
					//If at the start of the partition, set index i to low node
					if(i == nullptr){
						i= low;
					}
					//If not at the null index increment i
					else{
						i= i->next;
					}
					/*
						Swaps elements i and j.
						Does a redundant swap if i = j, i.e. the partition was already sorted.
						If i is less than pivot and j is greater than pivot,
							will swap them to make sure i is always less than pivot
					*/
					swap(i->element, j->element);
				}
			}
			//Case if pivot was greater than all the values in the partition
			if(i == nullptr){
				i= low;
			}
			//If pivot was less than or equal to pivot, 
			//increment pivot from the last lesser value to the next greater value in prep for the swap 
			else{
				i= i->next;
			}
			/*
				Swaps pivot with whatever was i just got incremented to.
				If all entries were less than the pivot, does a redundant swap at the "high" node
				If all entries were greater than the pivot, swaps high with low
				If I was somewhere in the middle, properly sets pivot in between
			*/
			swap(i->element, high->element);
			return i;
    	}
		//recursive quick sort
		void quickSort(Node* low, Node* high){
			if (high != nullptr && low != high && low != high->next) {
				Node* pivot = partition(low, high);
				quickSort(low, pivot->prev);
				quickSortU(pivot->next, high);
			}
    	}
		//Wrapper case needed to start with the full linked list
		void quickSortWrapper(){
        	quickSort(head, tail); 
    	}
};



#endif