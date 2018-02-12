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
    When there is a critical problem which is not reasonably possible to recover from,
    it's possible to throw an exception, and then catch this exception later.
    Once an exception has been caught, you can decide how you wish to handle the exception,
    such as notifying a user with a message, logging an error to a file, etc.

    Also if you know a function will never be able to throw an exception, it's possible
    to mark a function with the noexcept specifier.
*/
namespace ocl
{

class Person
{
public:
    Person();

    /// Constructor that can load a file to set the name and date.
    Person(const std::string& filename);

    Person(std::string const& first_name,
           std::string const& last_name,
           std::uint8_t day,
           std::uint8_t month,
           std::uint16_t year);

    ~Person();

    std::string const& GetFirstName() const noexcept;

    void SetFirstName(const std::string& first_name);

    std::string const& GetLastName() const noexcept;
    void SetLastName(const std::string& last_name);

    void GetDateOfBirth(std::uint8_t& day, std::uint8_t& month, std::uint16_t& year) const noexcept;
    void SetDateOfBirth(std::uint8_t day, std::uint8_t month, std::uint16_t year) noexcept;

    void SetFromBuffer(const char* buffer, std::size_t size);

    /// If the file does not exist, an exception will br thrown.
    void LoadFromFile(const std::string& filename);

private:
    std::string m_first_name;
    std::string m_last_name;
    std::uint8_t m_day;
    std::uint8_t m_month;
    std::uint16_t m_year;
};

} // namespace ocl

#endif // OCL_GUARD_TRAINING_LESSON_022_CLASSES_PERSON_HPP
