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

#include <iostream>
#include <cstddef>
#include <string>

void OutputPerson(const std::string& name, unsigned int age)
{
    std::cout << name << " is " << age << " years old" << std::endl;
}

int main()
{
    /*
        Going back to the lesson on references, you can see that a
        variable that is a reference is exactly the same as the variable
        it is associated too.
        (i.e. the reference has the same location in memory as the associated variable)
    */

    const std::size_t PEOPLE_COUNT = 4;
    std::string names[PEOPLE_COUNT] = {"James", "Sarah", "Tony", "Angela"};
    unsigned int ages[PEOPLE_COUNT] = {33, 27, 44, 38};

    // Output the information about the people to the screen.
    for (std::size_t pos = 0; pos < PEOPLE_COUNT; ++pos)
    {
        /*
            When the name is passed into the function, because the function parameter
            is a constant reference for a string, this means that the function OutputPerson
            is looking at exactly the same variable as names[pos] in memory,
            but because it is constant we know that function OutputPerson will not
            be able to change the value of names[pos].
            (it's just reading the name to output to the screen)
        */
        OutputPerson(names[pos], ages[pos]);
    }

    /*
        It's also important to know that the const keyword applies to the token to the left.
        The only exception to this rule is when the const keyword is the first token,
        then it will apply to the token immediately following the const keyword.
    */

    // These two lines have an identical meaning:
    const std::string& name0_a = names[0];
    std::string const& name0_b = names[0];

    // Output the two constant references ro the screen, so it can be seen they are the same.
    std::cout << "These refer to the same name: " << name0_a << " and " << name0_b << std::endl;

    return 0;
}
