#ifndef _Decorator_H_
#define _Decorator_H_

#include <math.h> 
#include <cmath> 
#include "Composite.h"

class Decorator : public Base { 
    protected :
        Base *value; 
        
    public: 
        Decorator() { };
        virtual double evaluate() = 0;
        
    
}; 
#endif 

