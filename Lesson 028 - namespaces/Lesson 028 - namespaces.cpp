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
#include "Person.hpp"

int main()
{
    /*
        It's also possible to use the using keyword so you don't need
        typing ocl:: continuously to use something in the namespace.

        You should avoid the keyword using in header files, as this
        often negates the purpose of having a namespace, by making it
        visible to everyone, and therefor re-introducing the possibility
        of name clashes.
    */
    using ocl::Person;

    Person person1("John", "Smith", 4, 8, 1967);
    Person person2("Sarah", "Smith", 14, 3, 1997);

    // Here we are using the string class from within the std namespace.
    std::string person1_str = person1.GetFirstName() + " " + person1.GetLastName();
    std::string person2_str = person2.GetFirstName() + " " + person2.GetLastName();

    // Here we are using the cout object from within the std namespace.
    // cout is actually an object of class type ostream.
    std::cout << "person1 is " << person1_str << std::endl;
    std::cout << "person2 is " << person2_str << std::endl;

    return 0;
}
