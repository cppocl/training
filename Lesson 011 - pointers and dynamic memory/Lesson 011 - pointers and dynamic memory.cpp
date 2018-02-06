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
#include <string>

int main()
{
    /*
        A pointer can store the address of something dynamically allocated in memory.
        This dynamic memory can be used temporarily for any purpose, and the freed
        after it's usefulness has ended.

        This has the advantage of not needing to have a program using a lot of memory
        while the program is running, and allowing the program to free memory when it
        no longer requires the memory.

        Dynamic memory is very similar to the example of arrays,
        except for it's dynamic nature.
    */

    // The new keyword dynamically allocated memory, which can then be used until
    // it is no longer needed.
    // In this example some memory has been allocated that is sequential,
    // big enough to store 4 int values.
    int* ages = new int[4];

    // You can see that the pointer that has reserved the 4 int values can be
    // accessed exactly like the arrays training in the previous lesson.
    ages[0] = 21;
    ages[1] = 35;
    ages[2] = 70;
    ages[3] = 6;

    int total_age = 0;
    for (int pos = 0; pos < 4; ++pos)
        total_age += ages[pos];

    // Output the total and average age of all 4 ages in the array to the screen.
    std::cout << "Total age is " << total_age << std::endl;
    std::cout << "Average age is " << (total_age / 4) << std::endl;

    // It's also possible to have arrays of other types, not just numeric types,
    // and also set the values at the time of defining the array.
    std::string* names = new std::string[4] { "James", "Peter", "Sarah", "Pauline" };

    // This is an example of how you can loop through an array,
    // handling each value with a variable indexing the position in the array.
    std::cout << "The names are ";
    for (int pos = 0; pos < 4; ++pos)
    {
        std::cout << names[pos];
        if (pos < 3)
            std::cout << ", ";
    }
    std::cout << std::endl;

    // Just like in the earlier training for using a pointer, we can place
    // the * operator before the pointer variable, to change the value at
    // the first location in memory. (which is the same as ages[0] and names[0])
    *ages = 50;
    *names = "David";

    // By adding 1 to the ages pointer, this moves the address by the size of an integer
    // to the next element (which is next the first element that the ages pointer looks at).
    // The same rule also applies to any pointer, including the names pointer.
    *(ages + 1) = 26;
    *(names + 1) = "Julia";

    // Output the names and ages to the screen.
    for (int pos = 0; pos < 4; ++pos)
    {
        std::cout << names[pos];
        std::cout << " is ";
        std::cout << ages[pos];
        std::cout << " years old " << std::endl;
    }

    // Now that the dynamic memory is no longer required, we can return the memory
    // back to the operating system that is running our program.
    // Notice that we used new int[4] which allocates an array, so we need to
    // use delete[] to tell the program we are freeing an array.
    delete[] ages;
    delete[] names;

    // Note that it would also be possible to allocate a single value dynamically,
    // and then there is no need to treat this as an array.
    // In the following example, a string is created in memory dynamically and set
    // the value "hello", and then immediately freed on the following line.
    std::string* a_single_string = new std::string("hello");
    delete a_single_string;

    return 0;
}
