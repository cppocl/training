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

#include "TypeTraits.hpp"
#include <iostream>

int main()
{
    // We can see the specialisation in action here for character types,
    // and not character types.

    int i = 1;
    char ch = 'C';
    wchar_t wch = L'W';
    signed char schar = 67;

    std::cout << "i is " << i << " and is a char? " << TypeTraits<int>::IsCharacter() << std::endl;

    // char and wchar_t are identified by our TypeTraits class as character types.
    std::cout << "ch is " << ch << " and is a char? " << TypeTraits<char>::IsCharacter() << std::endl;
    std::cout << "wch is " << wch << " and is a char? " << TypeTraits<wchar_t>::IsCharacter() << std::endl;

    // Note that cout treats a signed char as a character, although it is actually an integer type.
    // We cast this to an int so we can see the numerical value.
    std::cout << "schar is " << static_cast<int>(schar) << " and is a char? " << TypeTraits<signed char>::IsCharacter() << std::endl;

    return 0;
}
