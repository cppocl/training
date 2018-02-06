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

/*
    Include the function definitions, so the compiler knows how to use the functions.
    The main function doesn't need to know the implementation for the functions,
    only how the functuons are defined.

    The .cpp files are compiled into object files, and the linker will combine these
    object files into te executable, and handle resolving the function calls, etc.
*/
#include "sample_functions.hpp"
#include <iostream>

int main()
{
    // Example of using overloaded int and float versions of Square,
    // that return the squared values.
    long sq1 = Square(2L);
    std::cout << "The square of 2 is " << sq1 << std::endl;

    float sq2 = Square(3.0f);
    std::cout << "The square of 3.0 is " << sq2 << std::endl;

    long sq3 = 0;
    Square(sq1, sq3); // Set sq3 to the square of sq1 (4 * 4)
    std::cout << "The square of " << sq1 << " is " << sq1 << std::endl;

    float sq4 = 0.0f;
    Square(sq2, sq4); // Set sq4 to the square of sq2 (9.0 * 9.0);
    std::cout << "The square of " << sq2 << " is " << sq4 << std::endl;

    return 0;
}
