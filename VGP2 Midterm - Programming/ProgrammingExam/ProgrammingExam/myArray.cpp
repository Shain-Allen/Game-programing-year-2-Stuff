#include "MyArray.h"

myArray::myArray()
{
    size = 0;
    capacity = 1;
    numbers = new int[1];
}

int myArray::get_capacity(void) const
{
    return capacity;
}

int myArray::get_size(void) const
{
    return size;
}

void myArray::Push(int value_)
{
}

void myArray::pop()
{
}

myArray myArray::operator+(myArray array_)
{
	return myArray();
}

myArray myArray::operator+=(myArray array_)
{
	return myArray();
}
