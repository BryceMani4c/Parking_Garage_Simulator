/*****************************************************************
	Filename:       Linklist
	Date Created:   Oct 18
	Author:         Alek,Tobin,Bryson
******************************************************************/

#ifndef LinkedList_H
#define LinkedList_H
#include <iostream>
using namespace std;


template<typename T>
class Node{
	public:
		T element;
		Node *nextNode;
		Node *prevNode;
		//Not the default constructor however is need when passing a element
		Node(T value){
			this->element = value;
			nextNode = nullptr;
			prevNode = nullptr;
		}
		//default constructors when you are not passing an element 
		Node(){
			nextNode = nullptr;
			prevNode = nullptr;
		};
		//destructor to delete the element to clean memory
		~Node(){};

};

template <typename T>
class List
{
	private:
		//head and tail
		Node<T> *head;	
		Node<T> *tail;	

	public:
		//constructors 
		List(){ 
			head = nullptr; 
			tail = nullptr;
		}
		//destructor
		~List(){
            Node<T>* nextNode;
            while(head != nullptr){ //while the head doesn't equal null
                nextNode = head->nextNode; //get the node in front of head
				cout << "\n*****DELETING node with address:   " << head; //printing out the head
                delete head; //delete the node
                head = nextNode; //set head = to the next node
            }
		};
		void appendNode(T element){
			Node<T>* newNode = new Node(element);//creating node
            newNode->element = element;//setting the newnodes element equal to the element
            newNode->prevNode = tail; //pointing newnode to the tail
            if(head == nullptr){ // if head equals null sets the head and tail to the newNode
                head = newNode;
                tail = newNode; 
            }
            else{
                tail->nextNode = newNode; //tails next is set to point to the new node
                tail = newNode; //setting tail to that new newnode
                tail->nextNode = nullptr;
				
            }
        };
		void deleteNode(int position){
			if(head == nullptr){ //if head equals null that means there is nothing to delete
				cout << "There is no node to delete" << endl;
				return;
			}
			if(position == 0){ //checks if the position is at the head
				Node<T>* tmp = head; 
				head = head->nextNode; //moving head to the address it was pointing to
                tail = tail->prevNode;
				cout << "-----DELETING the node " <<  tmp << endl;
				delete tmp; //deleting tmp aka the start
			}
			else{
				Node<T>* current = head; //creating node
            	Node<T>* previous = nullptr; //previous
				for(int i = 0; i < position&& current != nullptr; i++){ //loops untill it hits the position and til curent doesn't equal null
					previous = current; 
					current = current->nextNode; //moving current to the nextnode
				}
				previous->nextNode = current->nextNode; //connects gap after deleting current
				cout << "-----DELETING the node " << current <<endl; //prints memeory address
				delete current;
			}
		}
        void displayList(){
            if(head == nullptr){ //if head equals null then print nothing is in the list
                cout << "\n\nThere is nothing List";
				return;
            }
            else{
                Node<T>* current = head; //set current to the head
				int i =0; //node counter
                while(current != nullptr){ //while current doesn't equal to null
					i++;
					cout << "\n\n---Node " << i << " with the memory address " << current; //prints memory address
					cout << current->element; //overloaded operator
                    current = current->nextNode; //current is set to the next node which current is point to 
                }
            }
        }
		void clear() {
            Node<T>* current = head;
            while (current != nullptr) {
                Node<T>* nextNode = current->nextNode;
                delete current;
                current = nextNode;
            }
            head = nullptr;
            tail = nullptr;
        }
		
		Node<T>* first(){
			return head; //returns head 
		}

		Node<T>* findNode(T& element){
			Node<T>* p = first(); //gets the head of the list
			while(p != nullptr){ //checks if list is null 
				if(p->element == element){ //
					return p; //means that there is only 1 element
				}
				p= p->next; //moves to the next node to check
			}
			return nullptr;
		}
		//partition function for quicksort
		Node<T>* partition(Node<T>* low, Node<T>* high){
			T pivot = high->element; //Pivot point is chosen to be whatever is the "high" node
			Node<T>* i = low->prevNode; //first index node to compare with second index node

			//for loop that uses a second index to compare the current temp element against pivot
			for(Node<T>* j = low; j != high; j = j->nextNode){
				//If the current element is less than pivot, "increment" index node i
				if(j->element < pivot){
					//If at the start of the partition, set index i to low node
					if(i == nullptr){
						i= low;
					}
					//If not at the null index increment i
					else{
						i= i->nextNode;
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
				i= i->nextNode;
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
		void quickSort(Node<T>* low, Node<T>* high){
			if(high != nullptr && low != high && high != low && low != high->nextNode){
				Node<T>* pivot;
				pivot = partition(low, high);
				quickSort(low, pivot->prevNode);
				quickSort(pivot->nextNode, high);
			}
    	}
		//Wrapper case needed to start with the full linked list
		void quickSortWrapper(){
        	quickSort(head, tail); 
    	}

		//partition function for quicksort
		Node<T>* partitionDescending(Node<T>* low, Node<T>* high){
			T pivot = high->element; //Pivot point is chosen to be whatever is the "high" node
			Node<T>* i = low->prevNode; //first index node to compare with second index node

			//for loop that uses a second index to compare the current temp element against pivot
			for(Node<T>* j = low; j != high; j = j->nextNode){
				//If the current element is greater than pivot, "increment" index node i
				if(j->element > pivot){
					//If at the start of the partition, set index i to low node
					if(i == nullptr){
						i= low;
					}
					//If not at the null index increment i
					else{
						i= i->nextNode;
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
				i= i->nextNode;
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
		void quickSortDescending(Node<T>* low, Node<T>* high){
			if(high != nullptr && low != high && high != low && low != high->nextNode){
				Node<T>* pivot; 
				pivot = partitionDescending(low, high);
				quickSortDescending(low, pivot->prevNode);
				quickSortDescending(pivot->nextNode, high);
			}
    	}
		//Wrapper case needed to start with the full linked list
		void quickSortWrapperDescending(){
        	quickSortDescending(head, tail); 
    	}
};



#endif