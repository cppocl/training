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
    // To initialize variables in a class at creation time,
    // this needs to be done in the initialiser list for the class.
    // The initialisation is done by specifying a colon and then the
    // variable name with the default value in brackets.
    // additional variables to be initialised need to be done in the
    // same way, but separated by a comma.
    // We don't need to initialise first_name or last_name, as a
    // string object in C++ is always set as empty be default.
    : m_day(0)
    , m_month(0)
    , m_year(0)
{
    // So we can see when a Person object is created, we can output something to screen.
    std::cout << "<default constructor called>" << std::endl;
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
    // So we can see when a Person object is created using the overloaded constructor,
    // we can output something to screen.
    //
    // Note that it is a bad idea to output to screen inside classes generally,
    // as this can limit the usefulness of re-using classes.
    // We rarely want messages coming out on screen without our control, when trying
    // to share classes to re-use functionality.
    std::cout << "<overloaded constructor called>" << std::endl;
}

Person::Person(const Person& other)
    : m_first_name(other.m_first_name)
    , m_last_name(other.m_last_name)
    , m_day(other.m_day)
    , m_month(other.m_month)
    , m_year(other.m_year)
{
    // The data from the other object is copied while constructing the data
    // for this class.
    std::cout << "<copy constructor called>" << std::endl;
}

Person::~Person()
{
    // So we can see when a Person object is destroyed, we can output something to screen.
    // Note that until we leave the destructor, the variables for the class are still valid.
    std::cout << "<destructor called for " << m_first_name << " " << m_last_name << ">" << std::endl;
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
