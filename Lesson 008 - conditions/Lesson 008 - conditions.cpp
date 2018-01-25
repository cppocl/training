/*
Copyright 2017 Colin Girling

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

#include <cstddef>
#include <iostream>

int main()
{
    /*
        Don't worry about how "std::cin >> age" works for now,
        this will be covered in later lessons.
        Also don't worry about "std::cout <<" as this will also be covered in later lessons.

        All we need to appreciate is std::cin reads the key presses
        and stores the answer in the variable.

        sd::cout reads whatever string we have in the quotes and outputs it to the screen.
    */

    // Read the age from the user input.
    int age = 0;
    std::cout << "Enter your age (in years): ";
    std::cin >> age;

    /*
        This simplest form of conditional checking is the use of if and else.
        It is possible to just use the if statement, or combine if with one of more
        if else statements and and single else statement at the end.

        It is possible to compare if a value is less than another by using <,
        less than or equal too by using <=, greater than a value with >,
        greater or equal with >=, if two values are the same with ==
        and if they are not equal by using !=
    */

    if (age >= 60)
        std::cout << "No comment!" << std::endl;
    else if (age >= 50)
        std::cout << "50's is the new 40!" << std::endl;
    else if (age >= 40)
        std::cout << "40's is the new 30!" << std::endl;
    else
        std::cout << "Spring chicken!" << std::endl;

    // Here are some fun examples of < <= > >= == and !=
    if (age < 16)
    {
        if (age != 0)
            std::cout << "Not working yet!" << std::endl;
        else
            std::cout << "Welcome to the World!" << std::endl;
    }
    else if (age > 77)
    {
        std::cout << "You might have made retirement!" << std::endl;
        if (age == 100)
            std::cout << "Where's my royal letter?" << std::endl;
    }


    /*
        The switch statement is generated more efficient executable code than using if else,
        but might not be as flexible.
        When the range is not extreme, such as having a limited set of values then a
        switch statement might be better.
    */

    // Read the number of vehicles from the user input.
    int vehicles = 0;
    std::cout << "Enter number of vehicles: ";
    std::cin >> vehicles;

    switch (vehicles)
    {
    case 0:
        std::cout << "Well that's very environmentally considerate." << std::endl;
        break;
    case 1:
        std::cout << "That's reasonable." << std::endl;
        break;
    case 2:
        std::cout << "Whoa!" << std::endl;
        break;
    case 3:
        std::cout << "No comment!" << std::endl;
        break;
    default: // Anything larger is beyond our comprehension.
        std::cout << "I can't count that high!" << std::endl;
        break;
    }

    return 0;
}
