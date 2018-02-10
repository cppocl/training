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

Person::Person()
    : m_day(0)
    , m_month(0)
    , m_year(0)
{
}

Person::Person(std::string const& first_name,
               std::string const& last_name,
               std::uint8_t day,
               std::uint8_t month,
               std::uint16_t year)
    : m_first_name(first_name)
    , m_last_name(last_name)
    , m_day(day)
    , m_month(month)
    , m_year(year)
{
}

Person::~Person()
{
}

Person& Person::operator =(const Person& other)
{
    // Copy all the values from other to myself.
    m_first_name = other.m_first_name;
    m_last_name = other.m_last_name;
    m_day = other.m_day;
    m_month = other.m_month;
    m_year = other.m_year;

    /*
        The first thing we can notice is the keyword this.
        The this keyword gives you a pointer to yourself (so the address of class object).
        There is a need occasionally to have access to your own address within a class,
        so that it can be used such as here for returning ourselves from the = operator.

        This return of ourselves allows the following code to work:

            Person p1("Fred", "Jones", 1, 1, 1980);
            Person p2;
            Person p3;
            p3 = p2 = p1;

        If the = operator was a void return then
        you could only do p2 = p3 or p1 = p3

        Because operator = returns it's self that return
        is then passing into the next assignment.
    */
    return *this;
}

bool Person::operator==(const Person& other) const
{
    // Implementing operators that do comparisons will return a boolean.
    // We can add comparison operators that are meaningful and can make
    // it easier to use a class.

    return (m_first_name == other.m_first_name) &&
           (m_last_name == other.m_last_name) &&
           (m_day == other.m_day) &&
           (m_month == other.m_month) &&
           (m_year == other.m_year);
}

bool Person::operator!=(const Person& other) const
{
    // We can call our own operator == and then just use the not operator to
    // reverse the results of == will give the not equals answer.
    return !operator==(other);
}

std::string const& Person::GetFirstName() const
{
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
    day = m_day;
    month = m_month;
    year = m_year;
}

void Person::SetDateOfBirth(std::uint8_t day, std::uint8_t month, std::uint16_t year)
{
    m_day = day;
    m_month = month;
    m_year = year;
}
