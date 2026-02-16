#include "Serializer.hpp"

int main()
{
    Data data1;
    data1.value = 67;

    uintptr_t v = Serializer::serialize(&data1);
    Data *data2 = Serializer::deserialize(v);

    std::cout << "data1 value: " << data1.value << "\n";
    std::cout << "data2 value: " << data2->value << "\n";


    return 0;
}