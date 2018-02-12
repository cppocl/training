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

#include <iostream>
#include "Person.hpp"

int main()
{
    /*
        When handling exceptions, don't try to use try and catch of every call,
        but instead just try the entire block of code being tested for exceptions.
        A catch block at the end can handle all exceptions.
    */

    ocl::Person person;

    try
    {
        // The file won't exist, so an exception will be thrown.
        ocl::Person person2("C:\\person.bin");

        // Because loading the file will fail and throw an exception, we won't see anything here.
        std::cout << person2.GetFirstName() << " " << person2.GetLastName() << std::endl;

        // If the line above did not exist, this would also throw an exception.
        person.LoadFromFile("C:\\person.bin");

        // Because loading the file will fail and throw an exception, we won't see anything here.
        std::cout << person.GetFirstName() << " " << person.GetLastName() << std::endl;
    }

    // Errors thrown from classes within the std namespace will either be std::exception
    // or inherited from class std::exception, so the base class can be used to catch
    // all exceptions of type std::exception.
    catch (const std::exception& except)
    {
        // Display the description of the exception that has been caught.
        std::cout << "exception \"" << except.what() << "\" thrown!" << std::endl;
    }

    return 0;
}
