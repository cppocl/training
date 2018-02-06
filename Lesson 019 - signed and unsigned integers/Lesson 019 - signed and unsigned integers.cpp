/*
Copyright 2018 Colin Girling

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <iostream>
#include <cstddef>

int main()
{
    /*
        Care needs to be taken when working with signed and unsigned integer values together.
        When the warning settings are set high enough for the compiler, you should see
        signed/unsigned mismatch warnings, if trying to add, subtract, multiply, etc. the values.

        Values can easily overflow or underflow when performing mathematics on integer variables,
        and checking should be performed where overflows or underflows can occur.
    */

    const std::int16_t max_int16   = (std::int16_t)0x7fff;   // 32767
    const std::uint16_t max_uint16 = (std::uint16_t)0xffffu; // 65535

    std::int16_t a;
    std::int16_t b;

    // Example of how to check for an overflow.
    // You can change these numbers to see how they effect the overflow checking.
    a = 1000;
    b = 31767;

    bool overflow = false;
    if (a < b)
    {
        if (a > max_int16 - b)
            overflow = true;
    }
    else if (b > max_int16 - a)
        overflow = true;

    // Either output an error if there will be an overflow, or output the addition to the screen.
    if (overflow)
        std::cerr << "a is " << a << " and b is " << b << " which cannot be added!" << std::endl;
    else
        std::cout << "a + b = " << (a + b) << std::endl;

    /*
        Often there are times when signed and unsigned variables become mixed,
        causing a signed/unsigned mismatch compiler warning.
        Either the types should be changed to match, or one of the types should be
        cast to the other type to prevent the warning.
        When casting the type, first make sure that
        an overflow or underflow condition cannot happen.
    */
    unsigned int total = 3;
    for (int i = 0; i < (int)total; ++i)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
