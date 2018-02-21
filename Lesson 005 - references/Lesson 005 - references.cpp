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

#include <cstdint> // Required for std::int32_t, std::uint32_t, etc.
#include <iostream>

// Example of a structure with some variables.
struct MyStruct
{
    int i;
    char c;
    char d;
};

int main()
{
    int i = 55;

    /*
        References are similar to pointers, in that they refer to the
        memory location of another variable, but unlike a pointer
        they must always reference a valid memory location, so they cannot
        be null.

        When the reference is defined, it must also be assigned to the other
        variable at the same time, as can be seen by the line of code below.

        There is no need to manually dereference a reference variable, as this
        is automatic, so the asterisk (*) has no meaning here.

        By using the ampersand (&) on a reference variable, you will get the
        address of the variable being referenced after it has been defined,
        as can be seen in the second std::cout line of code.
    */
    int& ref_i = i;

    // Output the memory address of i and ref_i, which will show the same value.
    std::cout << "address of i = " << &i << std::endl;
    std::cout << "address of ref_i = " << &ref_i << std::endl;

    // Output value of i and ref_i, which will show the same value.
    std::cout << "value of i=" << i << std::endl;
    std::cout << "value of ref_i = " << ref_i << std::endl;

    /*
        The memory address for the struct variable will same as the
        first variable within the structure, which is the variable i.
        As seen in the previous lesson for structures, the addresses
        of the variables within the structure will be aligned,
        so it can't be assumed the variables in the structure will
        be continuous within memory.
    */
    MyStruct st = { 1, 'A', 'B' };
    MyStruct& ref_st = st;

    // All of these output addresses will be the same.
    std::cout << "address of st = " << &st << std::endl;
    std::cout << "address of ref_st = " << &ref_st << std::endl;
    std::cout << "address of st.i = " << &st.i << std::endl;
    std::cout << "address of ref_st.i = " << &ref_st.i << std::endl;

    return 0;
}
