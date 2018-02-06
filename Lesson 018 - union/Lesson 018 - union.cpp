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

union u_type
{
    std::int16_t  a;
    std::uint16_t b;
    std::uint32_t c;
};

int main()
{
    /*
        Unions are defined in a similar way to structures, but unlike structures where
        each variable is stored within it's own space in memory, variables within a
        union share the same space in memory.
        The size of the union will be the size of the largest data type within the union.
        Looking at the example of the defined union u, this will store 32-bits of memory.
    */

    u_type u;

    // The size of the union will be 4 bytes (32-bits).
    std::cout << "size of the union u is " << sizeof(u) << std::endl;

    // Set all the bits for the largest value in the union.
    u.c = ~0U;

    // All the bits will be set for all a, b and c.
    // When all the bits are set, a signed integer will have the value -1, including u.a.
    // The values for u.b and u.c will be the maximum possible value for the variables.
    std::cout << "a is " << u.a << ", b is " << u.b << " and c is " << u.c << std::endl;

    // Setting the 16 bits to 255 for u.b will set the first 8 bits, and clear the next 8 bits.
    u.b = 255;

    // The values for u.a and u.b will now be 255, but u.c will be 0xffff00ff (4294902015).
    std::cout << "a is " << u.a << ", b is " << u.b << " and c is " << u.c << std::endl;

    // Two convert a positive number into a negative number, two's compliment can be used.
    // Integers that are signed have their bits set following the rules of two's compliment.
    // The formula for two's compliment is: -a = ~a + 1
    //
    // Note that the ~ operator inverts all the bits,
    // so if a binary value was 10010001 it would become 01101110.
    std::uint16_t twos_compliment_b = (std::uint16_t)(~255) + 1;
    u.b = twos_compliment_b;

    // The values for u.a will be -255 u.b will now be oxff01 (65281), but u.c will be 0xffffff01 (4294967041).
    std::cout << "a is " << u.a << ", b is " << u.b << " and c is " << u.c << std::endl;

    return 0;
}
