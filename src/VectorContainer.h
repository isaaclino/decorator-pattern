#ifndef __VECTORCONTAINER_H__
#define __VECTORCONTAINER_H__

#include "Sort.h"
#include "BubbleSort.h"
#include "SelectionSort.h"

#include <iostream>
#include <algorithm>
#include <vector> //std for vector 

class VectorContainer : public Container {
    private: 
        std::vector<Base*> SortVector; 
    public: 
	   /*Constructors */
        VectorContainer() { 
            sort_function = NULL; 
        }
     
        //push the top pointer of the tree into container
        void add_element(Base* element) 
        {
            SortVector.push_back(element);
        } 
        
        // iterate through trees and output values
        void print() {
            for (int i = 0; i < SortVector.size(); ++i) {
                cout << SortVector.at(i)->evaluate() << " ";
            }
            cout << endl; 
        } 
        
        // calls on the previously set sorting-algorithm
        // Checks if sort_function is not null, throw exception if otherwise
        void sort() {
            // if sort function is NULL, throw exception 
            //cout << "this is the sort function: " << sort_function << endl;
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
            //if i or j is greater than size, cannot perform swap() 
            if (i >= size() || j >= size())
            {
                cout << "ERROR: invalid position passed in\n"; 
            }
            
            else 
            {
                //temp needs to be type Base since vector is type Base
                Base* temp = SortVector.at(i);
                SortVector.at(i) = SortVector.at(j);
                SortVector.at(j) = temp;
            }
          
            
        } 
        
        // get top ptr of tree at index i
        Base* at(int i) {
            return SortVector.at(i);
        }; 
        
        // return container size
        int size() {
            return SortVector.size();
        };
};

#endif