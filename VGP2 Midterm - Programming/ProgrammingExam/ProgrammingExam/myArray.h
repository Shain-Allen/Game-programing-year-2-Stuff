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

	//This method removes an the last integer in the array.Removing an integer is done by simply decreasing the size value of the array.
	void pop();

	myArray operator+(myArray array_);

	myArray operator+=(myArray array_);

private:
    int *numbers;
    int size;
    int capacity;
};
