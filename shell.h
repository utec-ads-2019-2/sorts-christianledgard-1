#ifndef SHELL_H
#define SHELL_H

#include "sort.h"

class ShellSort : public Sort {       
    public:
        ShellSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            int i, j, k, temp;

            for(i = size/2; i > 0; i = i/2)
            {
                for(j = i; j < size; j++)
                {
                    for(k = j-i; k >= 0; k = k-i)
                    {
                        if(elements[k+i] >= elements[k])
                            break;
                        else
                        {
                            temp = elements[k];
                            elements[k] = elements[k+i];
                            elements[k+i] = temp;
                        }
                    }
                }
            }
        }

        inline string name() { return "ShellSort"; }
};

#endif