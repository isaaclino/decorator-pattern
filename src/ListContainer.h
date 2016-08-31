#ifndef _LISTCONTAINER_H_
#define _LISTCONTAINER_H_

#include <iostream> 
#include <algorithm>
#include <list> //std for list 

#include "Container.h"
#include "Sort.h"
#include "BubbleSort.h"
#include "SelectionSort.h"


class ListContainer : public Container {
    private: 
         std::list<Base*> SortList; 
    public:
	   /* Constructors */
        ListContainer() {
            sort_function = NULL; 
        }
        
	   // push the top pointer of the tree into container
        void add_element(Base* element) {
            SortList.push_back(element); 
        }
        
        // iterate through trees and output values
        void print() {
            for (list<Base*>::iterator i = SortList.begin(); i != SortList.end(); ++i)
            {
                std::cout << (*i)->evaluate() << " "; 
            }
            cout << endl; 
        }
        
        // calls on the previously set sorting-algorithm. 
            //Checks if sort_function is not null, throw exception if otherwise
        void sort() {
            if (sort_function == NULL) {
              cout << "ERROR: did not pick sort function\n"; 
          }
            else {
                sort_function->sort(this);
            }
        }

        /* Essentially the only functions needed to sort */
        //switch tree locations
        
        void swap(int i, int j) {
            //if i and j are bigger than size, cannot perform operation 
            if (i >= size() || j >= size()) {
                cout << "ERROR: invalid position passed in\n"; 
            }
            
            //sets curr1 and curr2 to the beginning of the list 
            list<Base*>::iterator curr1 = SortList.begin();
            list<Base*>::iterator curr2 = SortList.begin();
            
            //sets curr1 and curr2 to pos i and j 
            
            for (int a = 0; a < i; ++a) {
                curr1++;
            }
            
            for (int b = 0; b < j; ++b) {
                curr2++;
            }
            // cout << "Before test swap:" << endl;
            // cout << (*curr1)-> value << endl;
            // cout << (*curr2)-> value << endl;
            //swaps i and j values 
            Base* temp = *curr1;
            *curr1 = *curr2;
            *curr2 = temp;
            //  cout << "After test swap:" << endl;
            // cout << (*curr1)-> value << endl;
            // cout << (*curr2)-> value << endl;
        } 
        
        // get top ptr of tree at index i
        Base* at(int i) {
            if (SortList.size()>i)
            {
                list<Base*>::iterator pos = SortList.begin();
                for (int a = 0; a < i; a++) {
                    ++pos;
                }
            
                return *pos;
            }
            
            else
            {
                cout << "not valid\n";
                return 0;
            }

        }
        // return container size
        int size() {
            return SortList.size(); 
        }
};

#endif