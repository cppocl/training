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

#include "GetMax.hpp"
#include <iostream>

int main()
{
    int a = 1;
    int b = 2;

    float c = 2.5;
    float d = 1.5;

    // The function is generated for each type, so GetMax will be generated for
    // two ints in this example.
    std::cout << "max of a and b is " << GetMax(a, b) << std::endl;

    // In this example GetMax will be generated for two floats.
    std::cout << "max of c and d is " << GetMax(c, d) << std::endl;

    // To specify a type for a function template, put the type
    // between angled brackets, after the function name but before the brackets.
    std::cout << "PI rounded to an integer is " << PI<int>() << std::endl;

    // To specify a type for a function template, put the type
    // between angled brackets, after the function name but before the brackets.
    std::cout << "PI is " << PI<float>() << std::endl;

    return 0;
}
