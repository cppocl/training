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

#ifndef OCL_GUARD_TRAINING_LESSON_024_STATIC_MEMBER_FUNCTIONS_PERSON_HPP
#define OCL_GUARD_TRAINING_LESSON_024_STATIC_MEMBER_FUNCTIONS_PERSON_HPP

#include <string>
#include <cstddef>

/*
    A class can have static member functions, that can be used on an instance of a class,
    or used by using the class name, then :: and then the function name.

    So it's possible to call the static member function FindOldestPerson like this:

    Person person;
    Person* found_person = person.FindOldestPerson(people, 3);

    or can be called like this:
    Person* found_person = Person::FindOldestPerson(people, 3);

    The second variation is possible because there is no need for an
    object as a static member function won't change any data within an object.
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

    std::string const& GetFirstName() const;

    void SetFirstName(const std::string& first_name);

    std::string const& GetLastName() const;
    void SetLastName(const std::string& last_name);

    void GetDateOfBirth(std::uint8_t& day, std::uint8_t& month, std::uint16_t& year) const;
    void SetDateOfBirth(std::uint8_t day, std::uint8_t month, std::uint16_t year);

    bool IsOlder(const Person& other_person) const;

    /// FindOldestPerson looks through an array of people to find the person born first.
    /// Because this is a static function, we know it won't modify any member variables of
    /// any Person object it is called on.
    /// This will also return the first match if two people have the same earliest birth date.
    /// If number of people is 0 then a null pointer would be returned.
    static const Person* FindOldestPerson(const Person* people, std::size_t number_of_people);

private:
    std::string m_first_name;
    std::string m_last_name;
    std::uint8_t m_day;
    std::uint8_t m_month;
    std::uint16_t m_year;
};

#endif // OCL_GUARD_TRAINING_LESSON_024_STATIC_MEMBER_FUNCTIONS_PERSON_HPP
