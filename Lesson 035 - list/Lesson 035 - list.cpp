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
#include <list>

int main()
{
    /*
        The standard library provides a class that contains values of a specified data type.
        The container covered in this lesson, known as a list is similar to the vector lesson
        earlier, but the list can change size dynamically.
        Because the list is a class, it provides functions to manipulate the data contained.

        The standard library allows access to the data for any type of container, via the use
        of an iterator.
        The iterator is much like a position, but it also allows the user to gain access to
        the value within the container.

        Notice the code is almost identical to the vector example.
        The C++ libraries are designed to be similar in how they can be used, but unlike a
        vector that is a sequence of values in continuous memory, a list stores elements
        that cannot be assumed to be continuous in memory, hence they cannot be indexed
        efficiently by an numerical position.
        To get to a numerical position, an iterator would need to be incremented
        from the start, while being counted to get to a numerical position.
    */

    // We can initialize a list with some values
    std::list<int> ints = {10, 3, 7, 8, 2};

    // The iterator can be set to point to the first item in the list.
    std::list<int>::iterator pos = ints.begin();

    /*
        Loop through the elements in the list until we find 8.
        C++ containers work similar to pointers, in that you can dereference the iterator
        to get hold of the value at the position.
        We should always test that the iterator is not equal to the end of the list,
        as dereferencing an iterator past the end will cause the software to fail.
    */
    while ((pos != ints.end()) && (*pos != 8))
    {
        // Incrementing the iterator moves the position to the next item in the list.
        ++pos;
    }

    // By changing (*pos != 8) to some other value, you can see different results.
    if (pos != ints.end())
        std::cout << "Found value " << *pos << std::endl;
    else
        std::cout << "Value not found!" << std::endl;

    // We can insert a value before the iterator position (which will before 8).
    //
    // NOTE: It's important to be aware that lists are very quick for inserts,
    // adding or removing elements from the front and the back of a list,
    // but very slow at indexing.
    ints.insert(pos, 1);

    // Values can be added to the end of the list.
    ints.push_back(33);

    // Loop through all value in list and output each one.
    for (auto i : ints)
    {
        // We know 33 is the last value, so no need for another comma.
        if (i != 33)
            std::cout << i << ", ";
        else
            std::cout << i << std::endl;
    }

    return 0;
}
