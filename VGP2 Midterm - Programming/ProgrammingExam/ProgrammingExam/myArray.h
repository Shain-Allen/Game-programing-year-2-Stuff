#pragma once
#include <iostream>

class myArray
{
public:
    myArray(void);

    int get_capacity(void) const;
    int get_size(void) const;

    //This methods adds an integer, represented by the value_ parameter, to the end of the array.
    void Push(int value_);


private:
    int *numbers;
    int size;
    int capacity;
};
