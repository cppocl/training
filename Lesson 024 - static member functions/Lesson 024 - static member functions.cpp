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
    // Create 3 people that can be compared for the oldest.
    // You can change the date of births to see the results change.
    const std::size_t MAX_PEOPLE = 3;
    Person people[MAX_PEOPLE] =
    {
        Person("Sarah", "Smith", 29, 01, 1991),
        Person("John", "Walker", 17, 04, 1989),
        Person("Adam", "Jones", 26, 03, 1989)
    };

    // You could also try replacing people with nullptr or replace MAX_PEOPLE with 0
    // in the following line to see how FindOldestPerson handles errors.
    const Person* oldest_person = Person::FindOldestPerson(people, MAX_PEOPLE);

    // oldest_person won't be null in this example,
    // so we will see the oldest person on the screen.
    if (oldest_person != nullptr)
    {
        std::cout << "Oldest person is " << oldest_person->GetFirstName() << " ";
        std::cout << oldest_person->GetLastName() << std::endl;
    }
    else
        std::cerr << "Person not found!" << std::endl; // Output to stderr (should never happen).

    return 0;
}
