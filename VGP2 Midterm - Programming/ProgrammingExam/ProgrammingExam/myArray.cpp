#include "MyArray.h"

myArray::myArray()
{
    size = 0;
    capacity = 1;
    numbers = new int[1];
}

myArray::~myArray(void)
{
    delete[] numbers;
}

myArray::myArray(const myArray& array_)
    :capacity(array_.size), size(array_.size)
{
    numbers = new int[size];

    for (int i = 0; i < size; i++)
    {
        numbers[i] = array_.numbers[i];
    }
}

int myArray::get_capacity(void) const
{
    return capacity;
}

int myArray::get_size(void) const
{
    return size;
}

void myArray::push(int value_)
{
    if (size < capacity)
    {
        numbers[size++] = value_;
    }
    else
    {
        capacity *= 2;
        int *newnumbers = new int[capacity];
        
        for (int i = 0; i < size; i++)
        {
            newnumbers[i] = numbers[i];
        }

        newnumbers[size++] = value_;
        delete[] numbers;
        numbers = newnumbers;
    }
}

void myArray::pop()
{
    if (size != 0)
    {
        size--;
    }
}

myArray myArray::operator+(const myArray& array_) const
{
    myArray c;

    if (capacity >= array_.capacity)
    {
        c.capacity = capacity;
        c.numbers = new int[capacity];
    }
    else
    {
        c.capacity = array_.capacity;
        c.numbers = new int[array_.capacity];
    }

    if (size >= array_.size)
    {
        c.size = size;
    }
    else
    {
        c.size = array_.size;
    }

    for (int i = 0; i < c.size; i++)
    {
        c.numbers[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        c.numbers[i] += numbers[i];
    }

    for (int i = 0; i < array_.size; i++)
    {
        c.numbers[i] += array_.numbers[i];
    }

	return c;
}

myArray& myArray::operator+=(const myArray& array_)
{
    if (capacity < array_.size)
    {
        int* newNumbers = new int[array_.size];

        for (int i = 0; i < size; i++)
        {
            newNumbers[i] = numbers[i];
        }

        delete[] numbers;
        numbers = newNumbers;

        for (int i = size; i < array_.capacity; i++)
        {
            numbers[i] = 0;
        }

        for (int i = 0; i < array_.size; i++)
        {
            numbers[i] += array_.numbers[i];
        }

        if (size < array_.size)
        {
            size = array_.size;
        }

        return *this;
    }
    else
    {

        for (int i = size; i < capacity; i++)
        {
            numbers[i] = 0;
        }

        for (int i = 0; i < array_.size; i++)
        {
            numbers[i] += array_.numbers[i];
        }

        if (size < array_.size)
        {
            size = array_.size;
        }

        return *this;
    }
}

myArray& myArray::operator=(const myArray& array_)
{
    if (capacity < array_.size)
    {
        delete[] numbers;
        numbers = new int[array_.size];
        capacity = array_.size;
    }

    for (int i = 0; i < array_.size; i++)
    {
        numbers[i] = array_.numbers[i];
    }

    size = array_.size;

    return *this;
}

std::ostream& operator<<(std::ostream& stream, const myArray& array_)
{
    for (int i = 0; i < array_.size; i++)
    {
        stream << array_.numbers[i] << " ";
    }

    return stream;
}
