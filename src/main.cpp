#include <iostream>
#include "Composite.h"
#include "VectorContainer.h"
#include "ListContainer.h"
#include "Sort.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "Ceil.h"
#include "Floor.h"
#include "Abs.h"

using namespace std;

int main() {
    // Testing the composite pattern
    Op* op1 = new Op(7.1);
    Op* op2 = new Op(4.3);
    Op* op3 = new Op(3.2);
    Op* op4 = new Op(2.7);
    //cout << "op4: " <<  op4->evaluate() << endl;
    Mult* A = new Mult(op1, op2);
    //cout << "A: "<< A->evaluate() << endl; 
    Add* B = new Add(op3, op4);
    //cout << "B: " << B->evaluate() << endl; 
    Sub* C = new Sub(A, B);
    cout << "C: " << C->evaluate() << endl; 
    Sqr* D = new Sqr(C);
    
    cout << "final result: " << D->evaluate() << endl;
     //cout << "final result: " << C->evaluate() << endl; 
     
    Ceil* ceil1 = new Ceil(D);
    cout << "Ceil: " << ceil1->evaluate(); 
    
    // Floor* floor1 = new Floor(D); 
    // cout << "Floor: " << floor1->evaluate() << endl; 
    
    // Abs* abs1 = new Abs(C); 
    // cout << "Abs: " << abs1->evaluate(); 
     
     
    // Testing the strategy pattern
    VectorContainer* container = new VectorContainer();
    container->add_element(A);
    //cout << "A: " << A->evaluate() << endl; 
    container->add_element(B); 
    container->add_element(C);
    container->add_element(D);
    
    cout << endl << "TESTING VECTORCONTAINER: " << endl;
    cout << "Container Before Selection Sort: " << endl;
    container->print();
    
    cout << "Using SelectionSort: " << endl; 
    container->set_sort_function(new SelectionSort());
    container->sort(); 
    
    // cout << "Using BubbleSort: " << endl;
    // container->set_sort_function(new BubbleSort());
    // container->sort();
    
    cout << "Container after SelectionSort: " << endl; 
    container->print();
    
    //***TESTING WITH LIST****// 
    cout << "\nTESTING LISTCONTAINER: " << endl; 
    ListContainer* containerOne = new ListContainer(); 
    containerOne->add_element(A); 
    containerOne->add_element(B); 
    containerOne->add_element(C); 
    containerOne->add_element(D); 
    
    cout << "ContainerOne before BubbleSort: " << endl;
    containerOne->print(); 
    
    // cout << "Container's size: " << containerOne->size() << endl; 
    
    cout << "Using SelectionSort: " << endl; 
    containerOne->set_sort_function(new SelectionSort());
    containerOne->sort(); 
    
    // cout << "Using BubbleSort: " << endl;
    // containerOne->set_sort_function(new BubbleSort());
    // containerOne->sort();
    
    cout << "ContainerOne after BubbleSort: " << endl;
    containerOne->print(); 
    
   
};
