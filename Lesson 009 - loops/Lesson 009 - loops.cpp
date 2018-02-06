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

#include <cstddef>
#include <iostream>
#include <string>
#include <cctype>

int main()
{
    /*
        There are 3 types of loops, the for loop, while loop and do while loop,
        and each loop provides similar, but subtly different features that can be useful.

        The for loop allows for initialization, conditional checking per iteration,
        and an expression after each iteration.

        The while loop loops while a condition is true, and only executes the code
        within the loop while the condition is true.

        The do while loop will always do at least one iteration before checking the
        condition for exiting the loop.
    */

    std::string message = "Hello World!";

    unsigned int uppercase_count = 0;


    /*
        Example of a for loop that looks at  each character and increments uppercase_count
        when an upper case character is identified.
    */
    for (std::size_t pos = 0; pos < message.length(); ++pos)
    {
        if (isupper(message[pos]) != 0)
            ++uppercase_count;
    }

    // Output the number of found upper case characters to the screen, which will be 2.
    std::cout << "Number of upper case characters: " << uppercase_count << std::endl;

    // The for loop can also be done a different way,
    // by assigning a value for each element in the array or string.
    // Here the variable c is set for every position in the string.
    uppercase_count = 0;
    for (char c : message)
    {
        if (isupper(c) != 0)
            ++uppercase_count;
    }

    // Output the number of found upper case characters to the screen, which will be 2.
    std::cout << "Number of upper case characters: " << uppercase_count << std::endl;

    /*
        Example of a while loop, which keeps looping until a non-alphabetic character
        is found.
    */

    std::string::size_type pos = 0;
    while (pos < message.length())
    {
        if (isalpha(message[pos]) == 0)
            break; // Any loop can exit early with the break statement.
        ++pos;
    }

    // Output the position of the first non-alphabetic character to the screen.
    if (pos < message.length())
        std::cout << "Non-alphabetic character found at position " << pos << std::endl;
    else
        std::cout << "Non-alphabetic not found" << std::endl;


    /*
        Example of a do while loop, which will always do at least one iteration before
        checking to exit the loop.
        The example will reverse the characters in the message string.
    */

    std::string reversed_message;
    do
    {
        reversed_message.append(1U, message[message.length() - 1]);
        message.pop_back();
    }
    while (!message.empty());

    // Output the reversed message to the screen.
    std::cout << "The message reversed is " << reversed_message << std::endl;

    return 0;
}
