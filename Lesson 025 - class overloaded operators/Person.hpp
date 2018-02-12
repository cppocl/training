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

#ifndef OCL_GUARD_TRAINING_LESSON_025_CLASS_OVERLOADED_OPERATORS_PERSON_HPP
#define OCL_GUARD_TRAINING_LESSON_025_CLASS_OVERLOADED_OPERATORS_PERSON_HPP

#include <string>
#include <cstddef>

/*
    Overloaded operators on a class can allow you objects to look like
    they behave in a similar way to primitive like the int or float.

    Although you might not have been aware, you have already seen
    the use overloaded operators with std::cout <<
    The left shift operator has been overloaded to allow strings or
    primitive types to be output to the screen.

    The person class will give an example of how to implement the
    assignment operator =.
*/
class Person
{
public:
    Person();

    Person(std::string const& first_name,
           std::string const& last_name,
           std::uint8_t day,
           std::uint8_t month,
           std::uint16_t year);

    ~Person();

    /// Copy the contents of the other person to this object.
    Person& operator =(const Person& other);

    // We can compare two people to see if it#s the same person.
    bool operator==(const Person& other) const;
    bool operator!=(const Person& other) const;

    std::string const& GetFirstName() const;

    void SetFirstName(const std::string& first_name);

    std::string const& GetLastName() const;
    void SetLastName(const std::string& last_name);

    void GetDateOfBirth(std::uint8_t& day, std::uint8_t& month, std::uint16_t& year) const;
    void SetDateOfBirth(std::uint8_t day, std::uint8_t month, std::uint16_t year);

private:
    std::string m_first_name;
    std::string m_last_name;
    std::uint8_t m_day;
    std::uint8_t m_month;
    std::uint16_t m_year;
};

#endif // OCL_GUARD_TRAINING_LESSON_025_CLASS_OVERLOADED_OPERATORS_PERSON_HPP
