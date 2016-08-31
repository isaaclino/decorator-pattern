#ifndef __SELECTIONSORT_H__
#define __SELECTIONSORT_H__

#include "Container.h"
#include "Sort.h"

class SelectionSort : public Sort {
	private: 
	public:
           /* Constructors */
		SelectionSort(): Sort() {}
 
           /* Pure Virtual Functions */
	    void sort(Container* container) {
			int index; 
			int temp;
	    	for (int i = 0; i < container->size() - 1; i++) {
	            index = i;
	            temp = i;
	            for (int j = i + 1; j < container->size(); j++) {
	                if (container->at(j)->evaluate() < container->at(index)->evaluate())
	
	                    index = j;
	          
	           }
	            
	            if (index != temp) {
	            	container->swap(temp, index);
	            }
	    	}
	    }
	    
};
#endif