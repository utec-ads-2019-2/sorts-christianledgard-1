#ifndef COUNTING_H
#define COUNTING_H

#include "sort.h"
#include <algorithm>

class CountingSort : public Sort {       
    public:
        CountingSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            int max = 0;

            for (int j = 0; j < size; ++j)
                if (elements[j] > max)
                    max = elements[j];

            int i,j;
            int B[size], C[max+1];

            for (i = 0; i <= max; ++i)
                C[i] = 0;

            for (j = 0; j < size; ++j)
                C[elements[j]] += 1;

            for (i = 1; i < max+1; ++i)
                C[i] += C[i-1];


            for (j = size - 1; j >= 0 ; j--){
                B[C[elements[j]]-1 ] = elements[j];
                C[elements[j]] = C[elements[j]] - 1;
            }

            for(int l = 0; l<size;l++)
                elements[l] = B[l];


        }

        inline string name() { return "CountingSort"; }
};

#endif