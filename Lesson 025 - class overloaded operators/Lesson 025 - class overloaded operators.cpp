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

#include "Person.hpp"
#include <iostream>

int main()
{
    Person person("John", "Smith", 21, 1, 1990);
    Person person2, person3, person4;

    // This demonstrates why operator = on the Person class needs
    // to return a reference to itself.
    person2 = person3 = person;

    // Because an operator is just a function is a different format,
    // it can still be called like other functions by specifying
    // the keyword operator, then the operator (e.g. =),
    // then the arguments in brackets like any other function.
    person4.operator=(person);

    // All of these first and last names output to the screen will be the same.
    std::cout << person.GetFirstName() << " " << person.GetLastName() << std::endl;
    std::cout << person2.GetFirstName() << " " << person2.GetLastName() << std::endl;
    std::cout << person3.GetFirstName() << " " << person3.GetLastName() << std::endl;
    std::cout << person4.GetFirstName() << " " << person4.GetLastName() << std::endl;

    // We can also use operator == to confirm they are the same.
    if (person == person2)
        std::cout << "person and person2 are the same" << std::endl;
    else
        std::cout << "person and person2 are not the same" << std::endl;

    // By changing the first name for person, we know person and person 2 will
    // now be different, so we can use the != operator to confirm they are different.
    person.SetFirstName("Bob");
    if (person != person2)
        std::cout << "person and person2 are not the same" << std::endl;
    else
        std::cout << "person and person2 are the same" << std::endl;

    return 0;
}
