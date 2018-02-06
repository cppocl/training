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

/*
    When implementing a function for a class in a separate file,
    the class name needs to be specified, as well as the rest of the
    function details.

    Any return types will be before the class name and :: and then
    the function name follows the :: with it's parameters, and finally anything
    after those close brackets like const.
*/
std::string const& Person::GetFirstName() const
{
    // Notice that variables defined within the class can be seen inside the
    // implementation of the member functions.

    return m_first_name;
}

void Person::SetFirstName(const std::string& first_name)
{
    m_first_name = first_name;
}

std::string const& Person::GetLastName() const
{
    return m_last_name;
}

void Person::SetLastName(const std::string& last_name)
{
    m_last_name = last_name;
}

void Person::GetDateOfBirth(std::uint8_t& day, std::uint8_t& month, std::uint16_t& year) const
{
    // Notice that we return all these values together as references, to ensure the elements
    // that create the date of birth remain together and consistent.
    // Bugs can often occur when trying to either inspect or set related variables,
    // and restricting how the date of birth is inspected or changed can help to limit these
    // types of problems.

    day = m_day;
    month = m_month;
    year = m_year;
}

void Person::SetDateOfBirth(std::uint8_t day, std::uint8_t month, std::uint16_t year)
{
    // Providing a single way to set the date of birth will ensure the values remain
    // consistently updated together.
    m_day = day;
    m_month = month;
    m_year = year;
}
