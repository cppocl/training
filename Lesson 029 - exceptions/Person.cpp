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
#include <fstream>
#include <cstddef>

namespace ocl
{

Person::Person()
    : m_day(0)
    , m_month(0)
    , m_year(0)
{
}

Person::Person(const std::string& filename)
    : m_day(0)
    , m_month(0)
    , m_year(0)
{
    // Note that throwing from a constructor means the destructor won't be called.
    // You should be careful to avoid using raw pointers (e.g. char*) in classes
    // that can throw exceptions from a constructor.
    // It is possible to use a smart pointer instead of a raw pointer, which will
    // be covered in later lessons.
    LoadFromFile(filename);
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
    /*
        You should never throw from a destructor, or call functions that can throw,
        unless you catch all exceptions in the destructor and handle them.
    */
}

std::string const& Person::GetFirstName() const noexcept
{
    return m_first_name;
}

void Person::SetFirstName(const std::string& first_name)
{
    m_first_name = first_name;
}

std::string const& Person::GetLastName() const noexcept
{
    return m_last_name;
}

void Person::SetLastName(const std::string& last_name)
{
    m_last_name = last_name;
}

void Person::GetDateOfBirth(std::uint8_t& day, std::uint8_t& month, std::uint16_t& year) const noexcept
{
    day = m_day;
    month = m_month;
    year = m_year;
}

void Person::SetDateOfBirth(std::uint8_t day, std::uint8_t month, std::uint16_t year) noexcept
{
    m_day = day;
    m_month = month;
    m_year = year;
}

void Person::SetFromBuffer(const char* buffer, std::size_t size)
{
    // As an example of what we might do, lets put some code together
    // that only extras the first and last name, which is comma separated.
    std::string str(buffer, size);
    std::string first_name(str.substr(0, str.find(',')));
    std::string last_name(str.substr(first_name.length() + 1));
    m_day = 0;
    m_month = 0;
    m_year = 0;
}

void Person::LoadFromFile(const std::string& filename)
{
    using std::ios;

    std::fstream f;

    // Register f to throw an exception when failing to open a file.
    f.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    // Open, get the file size and read the file and close the file.
    f.open(filename, ios::out | ios::in | ios::binary);
    f.seekg(0, ios::beg);
    std::streampos start = f.tellg();
    f.seekg(0, ios::end);
    std::size_t size = f.tellg() - start;
    char* buffer = new char[size];
    f.read(buffer, size);
    f.close();
    SetFromBuffer(buffer, size);
    delete[] buffer;
}

} // namespace ocl
