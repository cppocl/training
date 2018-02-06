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
struct MyStruct1
{
    int i;
    char c;
    char d;
};

/*
    Notice that although MyStruct2 has the same variables as MyStruct1,
    the order is different, and so the amount of memory used
    by my MyStruct1 and MyStruct2 is also different.
    Different platforms will align variables in different ways,
    but one common way of aligning variables is to align them
    for the biggest data type, which is the int type in this example.

    Note that larger data structures can waste more memory with poorly ordered variables,
    which once stored in large arrays will only compound the problem.
*/
struct MyStruct2
{
    char c;
    int i;
    char d;
};

int main()
{
    // Set values for the structure variables.
    MyStruct1 st1;

    /*
        Notice the use of . before i within st.i.
        THere are many operators in C++, such as =, +, etc. and this one
        is known as a member selection or structure reference operator.
        The member selection operator gives access to the variables within the structure.
    */
    st1.i = 1;
    st1.c = 'A';
    st1.c = 'B';

    // Set the values at time of constructing the MyStruct2 variable.
    MyStruct2 st2 = { 'A', 1, 'B' };

    // Output the different sizes of the two data structures.
    std::cout << "size of MyStruct1=" << sizeof(st1) << std::endl;
    std::cout << "size of MyStruct2=" << sizeof(st2) << std::endl;

    return 0;
}
