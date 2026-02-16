#pragma once

#include <iostream>
#include "data.hpp"

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer&);
        Serializer& operator=(const Serializer &);

    public:
        ~Serializer();
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

