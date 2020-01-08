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
    :capacity(array_.capacity), size(array_.size)
{
    numbers = new int[capacity];

    for (int i = 0; i <= size; i++)
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
    }
    else
    {
        c.capacity = array_.capacity;
    }

    if (size >= array_.size)
    {
        c.size = size;
    }
    else
    {
        c.size = array_.size;
    }

    for (int i = 0; i <= size; i++)
    {
        c.numbers[i] += numbers[i];
    }

    for (int i = 0; i <= array_.size; i++)
    {
        c.numbers[i] += array_.numbers[i];
    }

	return c;
}

myArray myArray::operator+=(const myArray& array_)
{
    int* newNumbers;
    if (capacity < array_.capacity)
    {
        newNumbers = new int[array_.capacity];

        for (int i = 0; i <= size; i++)
        {
            newNumbers[i] += numbers[i];
        }

        for (int i = 0; i <= array_.size; i++)
        {
            newNumbers[i] += array_.numbers[i];
        }

        delete[] numbers;
        numbers = newNumbers;

        if (size < array_.size)
        {
            size = array_.size;
        }

        return *this;
    }
    else
    {
        for (int i = 0; i <= array_.size; i++)
        {
            numbers[i] += array_.numbers[i];
        }

        return *this;
    }
}

std::ostream& operator<<(std::ostream& stream, const myArray& array_)
{
    for (int i = 0; i < array_.size; i++)
    {
        stream << array_.numbers[i] << " ";
    }

    return stream;
}
