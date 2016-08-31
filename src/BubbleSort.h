#ifndef __BUBBLESORT_H__
#define __BUBBLESORT_H__

#include "Container.h"

class BubbleSort : public Sort {
	public:
           /* Constructors */
		BubbleSort() : Sort() {}  
 
           /* Pure Virtual Functions */
		void sort(Container* container) {
		   
	       for (int i = 0; i < (container->size()); i++) {
	            for (int j = 0; j < container->size() - i - 1; j++) {
	                if ( (container->at(j))->evaluate() > (container->at(j + 1))->evaluate() )
	                {
	                    container->swap(j, j+1);
	                }
	            }    
	       }
	    }
};

#endif