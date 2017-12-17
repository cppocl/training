/*
Copyright 2017 Colin Girling

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
    // Set values for the structure and int variables.
    int i = 55;

    /*
        Set the pointer variable ptr_i to have the same memory address as the variable i.
        int* is defining a data type of a pointer to an int.
        The & operator gets the address of the variable stored in memory.
        If the memory can address 64 bits of address space, then the pointer will
        be 64 bits in size.
        The following line defines a pointer to an int variable called ptr_i and assigns
        the pointer the same value as the address of the i variable.
    */
    int* ptr_i = &i;

    /*
        To gain access to the value stored within the variable i via the ptr_i pointer variable,
        the pointer needs to be dereferenced.
        What this means is that the value at the memory location where i exists, stores the value 55.
        The pointer stores a value which is the address of the i variable, but it can also look at
        the location of memory and get the values stored at the address, which is 55.

        If we assume that the variable i is stored at memory address 4, then ptr_i would equal 4.
        To get to the value 55 stored in the variable i via the ptr_i pointer, we can dereference
        the ptr_i pointer variable, and then get the value stored at the address.
        so ptr_i == 4, and *ptr_i == 55 in the example described.
        The pointer could actually be any memory address that the current program or process can access.
    */
    int value_of_i_via_pi = *ptr_i;

    // Output the memory address of i and ptr_i, which will show the same value.
    std::cout << "address of i = " << &i << std::endl;
    std::cout << "pointer ptr_i = " << ptr_i << std::endl;

    // Output value of i and the dereferenced pointer ptr_i, which will show the same value.
    std::cout << "value of i=" << i << std::endl;
    std::cout << "dereferenced value of ptr_i = " << *ptr_i << std::endl;
    std::cout << "value of value_of_i_via_pi = " << value_of_i_via_pi << std::endl;

    /*
        When a pointer is not pointing to a valid memory address,
        it can be set to a not used value, which is know as a null pointer.
        A null pointer should never be dereferenced, as this won't point to a valid memory address,
        and will cause your software to fail.
        It's simple just to compare a pointer variable to null before using the pointer variable.
    */
    ptr_i = nullptr;
    if (ptr_i != nullptr)
        std::cout << "dereferenced value of ptr_i = " << *ptr_i << std::endl;
    else
        std::cout << "ptr_i is null" << std::endl;

    /*
        The memory address for the struct variable will same as the
        first variable within the structure, which is the variable i.
        As seen in the previous lesson for structures, the addresses
        of the variables within the structure will be aligned,
        so it can't be assumed the variables in the structure will
        be continuous within memory.
    */
    MyStruct st = { 1, 'A', 'B' };
    MyStruct* ptr_st = &st;

    // All of these output addresses will be the same.
    std::cout << "address of st = " << &st << std::endl;
    std::cout << "pointer ptr_st = " << ptr_st << std::endl;
    std::cout << "address of st.i = " << &st.i << std::endl;

    /*
        To access the variables within the structure pointer, the -> operator
        is used, as can be seen in the line of code below.
        Above we could see that ptr_i was dereferenced by doing *ptr_i to get
        access to the value stored within the i variable.
        *ptr_st would also dereference the pointer to gain access to the values
        within the structure.
        The -> operator combines the * dereference operator with the . member access
        operator into a single operator that does both together.
        We could also dereference ptr_st and then access the i variable,
        but operator -> provides an alternative shortcut for accessing the variables
        within a structure.
     */
    std::cout << "address of ptr_st->i = " << &ptr_st->i << std::endl;

    /*
        The alternative to using -> operator, is using dereference * operator and
        then member access . operator together.
        Notice that the derefernce of ptr_st is inside brackets (*ptr_st).
        This is required because of operator precedence rules which are explained
        in a later lesson.
    */
    std::cout << "address of (*ptr_st).i = " << &(*ptr_st).i << std::endl;

    return 0;
}
