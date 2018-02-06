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
        Set the reference variable ref_i to have the same memory address as the variable i.
        int& is defining a data type of a reference to an int.
        The reference is similar to the previous pointer example,
        except it must always reference another variable of a compatible type.
        References are used like any other non-pointer variable type,
        they don't need to be dereferences as this is automatic.
        The following line defines a reference to an int variable called ref_i and assigns
        the pointer the same value as the address of the i variable.
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
