#ifndef SELECT_H
#define SELECT_H

#include "sort.h"

class SelectSort : public Sort {       
    public:
        SelectSort(int *elements, size_t size) : Sort(elements, size) {}
    void swap(int *xp, int *yp)
    {
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
    }
    void execute() {
            int i, j, min_idx;

            for (i = 0; i < size-1; i++)
            {
                min_idx = i;
                for (j = i+1; j < size; j++)
                    if (elements[j] < elements[min_idx])
                        min_idx = j;

                swap(&elements[min_idx], &elements[i]);
            }
        }

        inline string name() { return "SelectSort"; }
};

#endif