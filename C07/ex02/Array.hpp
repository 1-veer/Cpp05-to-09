#pragma once 
#include <iostream>


template <typename T>
class Array
{
    private:
        T* elements; 
        unsigned int LeSize;

     public:
        Array() : elements(NULL) , LeSize(0) {} 
        Array(unsigned int n) : elements(new T[n]()), LeSize(n) {}    
        Array(const Array &other) : elements(new T[other.LeSize]()), LeSize(other.LeSize) 
        {
            for (unsigned int i = 0; i < LeSize; i++)
                elements[i] = other.elements[i];
        }
        Array& operator=(const Array &other)
        {
            if (this != &other)
            {
                delete[] elements;
                LeSize = other.LeSize;
                elements = new T[LeSize]();
                for (unsigned int i = 0; i < LeSize; i++)
                    elements[i] = other.elements[i];
            }
            return *this;       
        }
       
        ~Array() { delete []elements; }
        

        T& operator[](unsigned int index)
        {
            if (index >= LeSize)
                throw std::out_of_range("Index out of range");
            return elements[index];
        }

        const T& operator[](unsigned int index) const
        {
            if (index >= LeSize)
                throw std::out_of_range("Index out of range");
            return elements[index];
        }
        unsigned int size() const
        {
            return LeSize;
        }
};

