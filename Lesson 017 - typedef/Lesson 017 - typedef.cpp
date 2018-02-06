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
#include <cstddef>

int main()
{
    /*
        Using the typedef keyword provides the ability to alias a type name as another name.
        This is very useful if you are developing a lot of code and some of your decisions
        about what types to use need to change at a later stage.
        In some languages there is no option to alias a type, and if you were to want to
        change the type used for storing a value, then all code that wants to use the same
        type would also need to change.
    */

    // The user is inputting numbers, but int might not be big enough in future.
    // We can start with int, and change it later.
    typedef int numeric_type;

    numeric_type number = 0;
    numeric_type total = 0;
    bool error = false;

    while (!error)
    {
        std::cout << "enter a number: ";

        // if the input is not compatible with the int type, the result is false.
        error = !(std::cin >> number);

        if (error)
            std::cout << "Invalid number!" << std::endl;
        else
            total += number;
    }

    // Output the total entered to the screen.
    std::cout << "total entered is " << total << std::endl;

    return 0;
}
