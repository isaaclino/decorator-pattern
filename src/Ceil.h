#ifndef _CEIL_H_
#define _CEIL_H_

#include <math.h> 
#include "Composite.h"
#include "Decorator.h"

class Ceil : public Decorator { 
    private:

    public: 
        Ceil(Base *v) {
            value = v;    
        }
        
        double evaluate() {
            return ceil(value->evaluate()); 
        }
        
    
}; 
#endif 

