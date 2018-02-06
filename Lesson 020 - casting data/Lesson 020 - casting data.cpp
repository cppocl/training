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
#include <string>

std::string FullName(const std::string& first_name, const std::string& last_name)
{
    return first_name + " " + last_name;
}

int main()
{
    /*
        C++ provides various ways to covert data from different types.
        These options are in the language to help make the software safer
        and also to help anyone reading the code to understand the intent
        of the data conversion.

        These are the casting operators supported by C and C++
        (type)
        static_cast
        reinterpret_cast
        const_cast
        dynamic_cast

        const_cast and dynamic_cast will not be covered here, as they will
        be better understood once C++ classes have been explained.
    */

    int i = 255;
    int* p = &i;
    double d = 77.5;
    std::uintptr_t int_address;

    // This is an example of a C style cast, which is in the form of (type)
    // The example on the line below demonstrates the dangers of a C style cast
    // when not used safely, and would set the pointer address to 255,
    // which we don't know anything about, is 255 a valid address? how would we know?
    // It's important to appreciate compilers can also generate warnings for this,
    // and warnings should never be ignored, as they often indicate an error in your code.
    p = (int*)i;

    // this line is actually valid, but because the C style cast does not give you
    // any protection from mistakes like the line above, there is no need to use a
    // C style cast in C++.
    // Because C++ also supports C, the C style cast is in the language
    // for backwards compatibility, so should only be used for compiling C code.
    p = (int*)&i;

    // In reality there is no need for any cast,
    // p can point to the address of an integer, they are already compatible.
    p = &i;

    // When we knowingly want to convert types, knowing we might loose some accuracy,
    // this can be done with static_cast.
    // This is an example where the double will be converted to the integer,
    // knowing we will loose the .5 part of the fraction.
    i = static_cast<int>(d);

    // We can output the integer to see the results of the conversion on the screen.
    std::cout << "i is " << i << std::endl;

    // The uintptr_t data type is guaranteed to be big enough to store a memory address,
    // so it's possible to covert the address of a variable and store it in uint_address.
    // The reinterpret_cast operator allows us to tell the compiler we know what we are doing,
    // and the conversion will be safe, but if we used it wrong there could be problems.
    int_address = reinterpret_cast<std::uintptr_t>(&i);

    // Output the address of i to the screen.
    std::cout << "the address of i is " << int_address << std::endl;

    return 0;
}
