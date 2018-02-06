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

// To make use of the Person class, we need to include the header file
// so the compiler knows the class is being used correctly.
// The compiler knows if you try to use a function from the class that doesn't
// exist and it will give you an error.

#include "Person.hpp"

#include <iostream>

int main()
{
    // Create a variable that is of a Person type.
    // This is similar to the struct example in an earlier lesson,
    // but with the addition of having functions on the object we can use.
    Person person;

    // We can call the various set functions on the person object to
    // give the person a name and date of birth.
    person.SetFirstName("John");
    person.SetLastName("Smith");
    person.SetDateOfBirth(17, 04, 1991);

    std::uint8_t day;
    std::uint8_t month;
    std::uint16_t year;
    person.GetDateOfBirth(day, month, year);

    // std::cout displays uint8_t types as characters, but we want to see them as integers.
    // converting them to a uint16_t ensures that std::cout treats them as integer types.
    std::uint16_t out_day = static_cast<std::uint16_t>(day);
    std::uint16_t out_month = static_cast<std::uint16_t>(month);

    // To prove that we can extract the information about a person, it is displayed to screen.
    std::cout << person.GetFirstName() << " " << person.GetLastName();
    std::cout << " was born on " << out_day << "/" << out_month << "/" << year << std::endl;

    return 0;
}
