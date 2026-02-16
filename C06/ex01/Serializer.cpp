#include "Serializer.hpp"

Serializer::Serializer() {}

 Serializer::Serializer(const Serializer & ) {}

Serializer& Serializer::operator=(const Serializer &) 
{
	return *this;
}

Serializer::~Serializer() {}

/*
uintptr_t serialize(Data* ptr);
It takes a pointer and converts it to the unsigned integer type uintptr_t.
Data* deserialize(uintptr_t raw);
It takes an unsigned integer parameter and converts it to a pointer to Data.
*/

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}