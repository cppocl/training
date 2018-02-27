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
#include <vector>

int main()
{
    /*
        The standard library provides a class that contains values of a specified data type.
        The container covered in this lesson, known as a vector is similar to the array lesson
        earlier, but the vector can change size dynamically.
        Because the vector is a class, it provides functions to manipulate the data contained.

        The standard library allows access to the data for any type of container, via the use
        of an iterator.
        The iterator is much like a position, but it also allows the user to gain access to
        the value within the container.
    */

    // We can initialize a vector with some values
    std::vector<int> ints = {10, 3, 7, 8, 2};

    // The iterator can be set to point to the first item in the vector.
    std::vector<int>::iterator pos = ints.begin();

    /*
        Loop through the elements in the vector until we find 8.
        C++ containers work similar to pointers, in that you can dereference the iterator
        to get hold of the value at the position.
        We should always test that the iterator is not equal to the end of the vector,
        as dereferencing an iterator past the end will cause the software to fail.
    */
    while ((pos != ints.end()) && (*pos != 8))
    {
        // Incrementing the iterator moves the position to the next item in the vector.
        ++pos;
    }

    // By changing (*pos != 8) to some other value, you can see different results.
    if (pos != ints.end())
        std::cout << "Found value " << *pos << std::endl;
    else
        std::cout << "Value not found!" << std::endl;

    // We can insert a value before the iterator position (which will before 8).
    //
    // NOTE: It's important to be aware that whenever an insert, push_back, etc. happens,
    // the vector will re-allocate a new sequence of values, copy the existing values across,
    // free the original copy, then insert, append, etc. after the copy.
    // The vector is very good at being created at a fixed size, indexing, but is
    // slow at having elements added or removed, and sequential searching can be slow.
    ints.insert(pos, 1);

    // Values can be added to the end of the vector.
    ints.push_back(33);

    // Loop through all value in vector and output each one.
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
