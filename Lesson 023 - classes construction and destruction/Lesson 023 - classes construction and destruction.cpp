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
    // Create two people, and see the output for construction of them.
    Person person1;
    Person person2("Sarah", "Smith", 29, 01, 1991);

    // Create a third person, which is a copy of the person2 object.
    Person person3(person2);

    // We can call the various set functions on the person object to
    // give the person a name and date of birth.
    person1.SetFirstName("John");
    person1.SetLastName("Smith");
    person1.SetDateOfBirth(17, 04, 1991);

    std::uint8_t day1, day2, day3;
    std::uint8_t month1, month2, month3;
    std::uint16_t year1, year2, year3;
    person1.GetDateOfBirth(day1, month1, year1);
    person2.GetDateOfBirth(day2, month2, year2);
    person2.GetDateOfBirth(day3, month3, year3);

    // std::cout displays uint8_t types as characters, but we want to see them as integers.
    // converting them to a uint16_t ensures that std::cout treats them as integer types.
    std::uint16_t out_day1 = static_cast<std::uint16_t>(day1);
    std::uint16_t out_month1 = static_cast<std::uint16_t>(month1);
    std::uint16_t out_day2 = static_cast<std::uint16_t>(day2);
    std::uint16_t out_month2 = static_cast<std::uint16_t>(month2);
    std::uint16_t out_day3 = static_cast<std::uint16_t>(day3);
    std::uint16_t out_month3 = static_cast<std::uint16_t>(month3);

    // To prove that we can extract the information about a person, it is displayed to screen.
    std::cout << person1.GetFirstName() << " " << person1.GetLastName();
    std::cout << " was born on " << out_day1 << "/" << out_month1 << "/" << year1 << std::endl;
    std::cout << person2.GetFirstName() << " " << person2.GetLastName();
    std::cout << " was born on " << out_day2 << "/" << out_month2 << "/" << year2 << std::endl;
    std::cout << person3.GetFirstName() << " " << person3.GetLastName();
    std::cout << " was born on " << out_day3 << "/" << out_month3 << "/" << year3 << std::endl;

    return 0;
}
