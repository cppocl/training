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

#ifndef OCL_GUARD_TRAINING_LESSON_022_CLASSES_PERSON_HPP
#define OCL_GUARD_TRAINING_LESSON_022_CLASSES_PERSON_HPP

#include <string>
#include <cstddef>

/*
    A class can also have a constructor and destructor.
    The constructor is automatically called when the object for the class is created in memory,
    and the constructor can be overloaded.
    (you can have multiple constructors with different arguments) 

    The destructor is automatically called when the object is going out of memory,
    and this can be used for clean-up, such as closing a file.

    To define a constructor, you specify a function name that is exactly the
    same as the class name, and for a destructor it's almost the same,
    but the destructor name starts with ~ and then the class name.
*/
class Person
{
public:
    /// This is known as a default constructor, and does not have any parameters.
    /// When an object is created with a default constructor, the variable won't
    /// have any arguments specified with the variable name.
    /// There is no need to specify a default constructor, if you don't need to
    /// set any values, and the compiler will generate a default one for you,
    /// which will call any default constructors for you on any variables in your class.
    Person();

    /// It's also possible to create a class object with arguments specified
    /// at the time the object is created in memory.
    /// This is important as this allows the variables in the class to be
    /// created and set to the correct values at the same time the class object
    /// is also created.
    Person(std::string const& first_name,
           std::string const& last_name,
           std::uint8_t day,
           std::uint8_t month,
           std::uint16_t year);

    /// When a class object is going out of memory, the destructor is first called
    /// to perform any clean-up that might be required.
    /// You don't need to specify a destructor for a class,
    // if you don't have any clean-up to do.
    ~Person();

    /// Get the first name of the person, noting that the function is const,
    /// so we know it won't accidentally change the value of the name.
    std::string const& GetFirstName() const;

    /// Change the first name of the person.
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

#endif // OCL_GUARD_TRAINING_LESSON_022_CLASSES_PERSON_HPP
