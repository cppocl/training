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

bool Person::IsOlder(const Person& other_person) const
{
    // Here we use bit shifting to store the day, month and year into an unsigned 32=bit integer.
    std::uint32_t dob = m_day + (m_month << 8U) + (m_year << 16U);
    std::uint32_t other_dob = other_person.m_day +
                  (other_person.m_month << 8U) +
                  (other_person.m_year << 16U);
    return dob < other_dob;
}

const Person* Person::FindOldestPerson(const Person* people, std::size_t number_of_people)
{
    // Although we know the use of this function always has an array of people,
    // it's always important to handle unexpected situations like null pointers or empty arrays.

    const Person* oldest_person = nullptr;

    if (people != nullptr)
    {
        for (std::size_t pos = 0; pos < number_of_people; ++pos)
        {
            const Person& curr_person = people[pos];
            if (oldest_person == nullptr)
                oldest_person = &people[pos];
            else if (curr_person.IsOlder(*oldest_person))
                oldest_person = &curr_person;
        }
    }

    return oldest_person;
}
