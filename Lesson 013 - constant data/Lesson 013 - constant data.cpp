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

int main()
{
    /*
        There are various ways to define constant values,
        either by defining a constant variable or
        by defining an enumeration.
    */

    // Defining a constant can help make code easier to read.
    const int NUMBER_OF_DAYS_IN_WEEK = 7;

    // It's also possible to have an array of constant values.
    const std::string days_of_week[NUMBER_OF_DAYS_IN_WEEK] =
    {
        "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
    };

    // Output all the days of the week to the screen.
    for (int day_of_week = 0; day_of_week < NUMBER_OF_DAYS_IN_WEEK; ++day_of_week)
        std::cout << days_of_week[day_of_week] << std::endl;

    // Enumerations can be defined, and the data type can also be specified.
    // Specifying the data type is optional, and can be omitted by removing the colon and type.
    enum class DaysInMonth : unsigned int
    {
        January = 31,
        February = 28,
        March = 31,
        April = 30,
        May = 31,
        June = 30,
        July = 31,
        August = 31,
        September = 30,
        October = 31,
        November = 30,
        December = 31
    };

    // Notice that const strings are used instead of enumeration,
    // because enumeration only works with integer types.
    const int MONTHS_PER_YEAR = 12;
    const std::string months[MONTHS_PER_YEAR] =
    {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };

    // To convert from an enumeration to an integer, you need to
    // explicitly convert the value using something known as type casting.
    // One way to cast a type is to place the type you wish to convert too inside brackets.
    // The subject of casting data will be covered in more detail in a later training example.
    const unsigned int days_in_months[MONTHS_PER_YEAR] =
    {
        (unsigned int)DaysInMonth::January,
        (unsigned int)DaysInMonth::February,
        (unsigned int)DaysInMonth::March,
        (unsigned int)DaysInMonth::April,
        (unsigned int)DaysInMonth::May,
        (unsigned int)DaysInMonth::June,
        (unsigned int)DaysInMonth::July,
        (unsigned int)DaysInMonth::August,
        (unsigned int)DaysInMonth::September,
        (unsigned int)DaysInMonth::October,
        (unsigned int)DaysInMonth::November,
        (unsigned int)DaysInMonth::December
    };

    // Output the month names with days in a month to the screen.
    for (std::size_t pos = 0; pos < MONTHS_PER_YEAR; ++pos)
        std::cout << months[pos] << " has " << days_in_months[pos] << " in the month." << std::endl;

    return 0;
}
