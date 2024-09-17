#pragma once

#include <iostream>

namespace example_header_only_lib
{
class Hello
{
public:
    void say_hello()
    {
        std::cout << "Hello, World!" << std::endl;
    }
};
} // namespace example_header_only_lib
