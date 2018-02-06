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

void OutputPerson(const std::string* name, unsigned int age)
{
    std::cout << *name << " is " << age << " years old" << std::endl;
}

int main()
{
    /*
        Going back to the lesson on pointers, you can see that a
        pointer variable set to the address of another variable,
        shared the same memory address and can access the same value in memory.
    */

    const std::size_t PEOPLE_COUNT = 4;
    std::string names[PEOPLE_COUNT] = {"James", "Sarah", "Tony", "Angela"};
    unsigned int ages[PEOPLE_COUNT] = {33, 27, 44, 38};

    // Output the information about the people to the screen.
    for (std::size_t pos = 0; pos < PEOPLE_COUNT; ++pos)
    {
        /*
            When the name is passed into the function, because the function parameter
            is a constant pointer for a string, this means that the function OutputPerson
            is looking at exactly the same variable as names[pos] in memory,
            but because it is constant we know that function OutputPerson will not
            be able to change the value of names[pos].
            (it's just reading the name to output to the screen)
        */
        OutputPerson(&names[pos], ages[pos]);
    }

    /*
        It's also important to know that the const keyword applies to the token to the left.
        The only exception to this rule is when the const keyword is the first token,
        then it will apply to the token immediately following the const keyword.
    */

    // These two lines have an identical meaning:
    const std::string* name_a = &names[0];
    std::string const* name_b = &names[0];

    /*
        Note it's also possible to make he pointer constant as well as the data
        the pointer is pointing too.
        So this is a constant pointer to a constant string.
        (The string and the pointer cannot be changed)
    */
    std::string const* const name_c = &names[0];

    /*
        Note it's also possible to make he pointer constant but still be able to
        change the string.
        So this is a constant pointer to a string.
        (The string can be changed but not the pointer)
    */
    std::string* const name_d = &names[0];

    // Output the two constant pointers to the screen, so it can be seen they are the same.
    std::cout << "These refer to the same name: "
              << *name_a << " and "
              << *name_b << " and "
              << *name_c << " and "
              << *name_d << std::endl;

    return 0;
}
