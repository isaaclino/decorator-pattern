#ifndef _ABS_H_
#define _ABS_H_

#include <math.h> 
#include <cmath> 
#include "Composite.h"
#include "Decorator.h"

class Abs : public Decorator { 
    private:
        
    public: 
        Abs(Base *v) {
            value = v;    
        }
        
        double evaluate() {
            return static_cast<double>(abs(value->evaluate()));
        }
        
    
}; 
#endif 

