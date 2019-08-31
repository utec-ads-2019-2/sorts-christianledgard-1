#ifndef MERGE_H
#define MERGE_H

#include "sort.h"

class MergeSort : public Sort {       
    public:
        MergeSort(int *elements, size_t size) : Sort(elements, size) {}

    //Algorithm adapted from https://www.tutorialspoint.com/cplusplus-program-to-implement-merge-sort

    void merge(int *array, int l, int m, int r) {
        int i, j, k, nl, nr;
        nl = m-l+1; nr = r-m;
        int larr[nl], rarr[nr];
        for(i = 0; i<nl; i++)
            larr[i] = array[l+i];
        for(j = 0; j<nr; j++)
            rarr[j] = array[m+1+j];
        i = 0; j = 0; k = l;
        while(i < nl && j<nr) {
            if(larr[i] <= rarr[j]) {
                array[k] = larr[i];
                i++;
            }else{
                array[k] = rarr[j];
                j++;
            }
            k++;
        }
        while(i<nl) {
            array[k] = larr[i];
            i++; k++;
        }
        while(j<nr) {
            array[k] = rarr[j];
            j++; k++;
        }
    }
    void mergeSort(int *array, int l, int r) {
        int m;
        if(l < r) {
            int m = l+(r-l)/2;
            mergeSort(array, l, m);
            mergeSort(array, m+1, r);
            merge(array, l, m, r);
        }
    }

        void execute() {
            mergeSort(elements, 0, size-1);
        }

        inline string name() { return "MergeSort"; }
};

#endif