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
#ifndef OCL_GUARD_TRAINING_LESSON_028_NAMESPACES_PERSON_HPP
#define OCL_GUARD_TRAINING_LESSON_028_NAMESPACES_PERSON_HPP

#include <string>
#include <cstddef>

/*
    Putting functions or classes into a namespace allows
    code with duplicate names to be separated.

    When a namespace is defined around a function or class,
    this prevents the use of that function or class without
    specifying the namespace.

    When a function or class is not in a namespace, then it
    is in the global namespace, meaning you don't need to
    specify the name of a namespace to use those functions
    or classes.

    To use a class like the Person class below, you will also
    need to specify the namespace name as well, e.g.

    ocl::Person my_person;

    The :: operator is known as a scope resolution operator,
    and if a function or class is not in a namespace, then it
    is considered to have a global scope.

    If the function or class is within a namespace, then it's
    scope is considered to be within that namespace.

    The namespace was introduced to the language to help reduce
    name conflicts when using large amounts of code, or trying
    to use many 3rd party libraries, where in was becoming
    common to have classes or functions with the same names.

    You might not be aware, but you will have already seen the
    use of a namespace in the previous lessons, which was std.
    So std::string or std::cout are classes that exist in the
    std namespace.
*/
namespace ocl
{

class Person
{
public:
    Person(std::string const& first_name,
           std::string const& last_name,
           std::uint8_t day,
           std::uint8_t month,
           std::uint16_t year);

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

} // namespace ocl

#endif // OCL_GUARD_TRAINING_LESSON_028_NAMESPACES_PERSON_HPP
