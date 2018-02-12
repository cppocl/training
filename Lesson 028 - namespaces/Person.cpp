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

namespace ocl
{

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

} // namespace ocl
