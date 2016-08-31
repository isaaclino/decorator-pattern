#ifndef _Floor_H_
#define _Floor_H_

#include <math.h> 
#include "Composite.h"
#include "Decorator.h"

class Floor : public Decorator { 
   
        
    public: 
        Floor(Base *v) {
            value = v;    
        }
        
        double evaluate() {
            return floor(value->evaluate()); 
        }
        
    
}; 
#endif 

