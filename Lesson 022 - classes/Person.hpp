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

// Notice we have used #ifndef and #define to protect the file from
// being included multiple times.
// The #ifndef will only be true the first time the header file is included,
// and any other includes of this header file would be ignored when included
// in the same file, because #define will only be called once.
#ifndef OCL_GUARD_TRAINING_LESSON_022_CLASSES_PERSON_HPP
#define OCL_GUARD_TRAINING_LESSON_022_CLASSES_PERSON_HPP

#include <string>
#include <cstddef>

/*
    A class provides the ability to connect data and functions into a single entity.
    This provides the ability to hide data or functions, by using the private keyword.
    The public parts of the class are available to users of the class, so GetFirstName
    could be used by other code outside of the Person class (as well as inside).
    Brining data and functions in a class is also known as encapsulation,
    and allows us to manage the state of the data safely, always keeping the data consistent.

    The Person class has been defined in a header file (the .hpp file), but the
    implementation for the functions is in the source file (.cpp).
    This is a common practice to make it easier to read how to use a class,
    without seeing all the implementation of the definition of the class.

    A standard technique for either inspecting or changing the data, is to add
    get and set functions to your class.

    It is also possible to see that the get functions end with the const specifier,
    which tells the compiler that data within the class will not change when calling
    those functions.
    This is important when trying to produce robust code, as historically languages
    that allowed all functions to change any data, often made it hard to find the cause
    of a bug.

    If you were to define a function like GetFirstName without specifying it as constant,
    there might be a change of modifying the first name by accident, so const provides
    a safeguard against this type of bug happening.
    Also to protect against these types of bugs, C++ prevents a constant function from
    calling a function that is not constant, so care must be taken to consider your design
    and how this will affect your users.

    Note functions that are not constant can call constant functions.

    Functions within a class are also called member functions.
    This helps to differentiate between a function within a class or one
    defined outside the class.
*/
class Person
{
public:
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
    // The data is hidden from the user, so that we can prevent direct access,
    // and reduce the possibility of bugs.
    // For example a user could accidentally change the day and month and forget to set the year.
    // Providing a set function for changing the date of birth that expects day, month and year
    // ensures this type of mistake cannot happen.

    std::string m_first_name;
    std::string m_last_name;
    std::uint8_t m_day;
    std::uint8_t m_month;
    std::uint16_t m_year;
};

#endif // OCL_GUARD_TRAINING_LESSON_022_CLASSES_PERSON_HPP
