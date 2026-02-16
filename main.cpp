#include <iostream>

#include "c/2424.c"

int main(int argc, char const *argv[])
{

    auto obj = lUPrefixCreate(4);

    lUPrefixUpload(obj, 3);
    std::cout << lUPrefixLongest(obj) << std::endl;

    lUPrefixUpload(obj, 1);
    std::cout << lUPrefixLongest(obj) << std::endl;

    lUPrefixUpload(obj, 2);
    std::cout << lUPrefixLongest(obj) << std::endl;

    delete obj;

    return 0;
}
