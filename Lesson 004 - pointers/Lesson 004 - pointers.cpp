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
    /*
        Variables are stored in memory, and have use a certain amount of space.
        The long variable num will be at least 32-bits, but could be larger on some systems.
    */
    long num = 55;

    /*
        A pointer variable is similar to an integer variable, in that is stores a numeric value,
        but the value will always be the size required to store an address of a variable.
        The use of the asterisk (*) after long defines a pointer variable, but it also says the data
        stored at the memory location is a value of type long.
        Pointer variables store the address, but they can also access the value at the memory location.
        To set a pointer variable to the address of another variable, you can see the ampersand (&) is
        used to set ptr_num to the memory location of num.
    */
    long* ptr_num = &num;

    /*
        Now that ptr_num knows the address of the variable num, it can also gain access to the value
        stored in num.
        To gain access, we can use the pointer variable and get the value at the memory location by
        using the asterisk (*) on the pointer variable.
        This is also known as dereferencing the pointer.
        (i.e look at value at memory location for variable type)
    */
    long value_of_num_via_ptr_num = *ptr_num;

    // Output the memory address of i and ptr_i, which will show the same value.
    std::cout << "address of num = " << &num << std::endl;
    std::cout << "pointer ptr_num = " << ptr_num << std::endl;

    // Output value of i and the dereferenced pointer ptr_i, which will show the same value.
    std::cout << "value of num=" << num << std::endl;
    std::cout << "dereferenced value of ptr_num = " << *ptr_num << std::endl;
    std::cout << "value of value_of_num_via_ptr_num = " << value_of_num_via_ptr_num << std::endl;

    /*
        When a pointer is not pointing to a valid memory address,
        it can be set to a not used value, which is know as a null pointer.
        A null pointer should never be dereferenced, as this won't point to a valid memory address,
        and will cause your software to fail.
        It's simple just to compare a pointer variable to null before using the pointer variable.
    */
    ptr_num = nullptr;
    if (ptr_num != nullptr)
        std::cout << "dereferenced value of ptr_num = " << *ptr_num << std::endl;
    else
        std::cout << "ptr_num is null" << std::endl;

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
