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

#include "Array.hpp"
#include "GetMax.hpp"
#include <iostream>

int main()
{
    /*
        We have already seen classes, member functions, inheritance, virtual functions, etc.
        These classes have fixed data, and are implemented to solve specific problems.

        It's also possible to write generic classes that will work with any data type
        provided by the user of the class.

        Yo use a template class, the user needs to specify the data type at the time
        of use of the template class.

        This is done by using the class name, then the data types within angled brackets.
        e.g.
            Array<int> my_ints;
    */

    Array<int> my_ints;

    // Verify the array is empty.
    std::cout << ((my_ints.GetSize() == 0) ? "my_ints is empty" : "ERROR with my_ints") << std::endl;

    my_ints.Resize(1);

    // Verify the resize created one element.
    std::cout << ((my_ints.GetSize() == 1) ? "my_ints has 1 element" : "ERROR with my_ints") << std::endl;

    my_ints[0] = 1;

    // Verify the first element was set to 1.
    std::cout << ((my_ints[0] == 1) ? "my_ints[0] is 1" : "ERROR with my_ints") << std::endl;

    try
    {
        my_ints[1] = 1;
    }

    catch (std::out_of_range const& ex)
    {
        // Verify the exception was thrown when the index was out of range.
        std::cout << "Expecting my_ints to throw out of range exception: \"" << ex.what() << "\"" << std::endl;
    }

    my_ints.Resize(2);

    // Verify the resize copied existing data.
    std::cout << ((my_ints[0] == 1) ? "my_ints[0] is 1" : "ERROR with my_ints") << std::endl;

    my_ints[1] = 2;

    // Verify the first element was not changed and the second element was set to 2.
    std::cout << ((my_ints[0] == 1) ? "my_ints[0] is 1" : "ERROR with my_ints") << std::endl;
    std::cout << ((my_ints[1] == 2) ? "my_ints[1] is 2" : "ERROR with my_ints") << std::endl;

    // Example of using a template function.
    std::cout << "my_ints max value is " << GetMax(my_ints[0], my_ints[1]) << std::endl;

    return 0;
}
