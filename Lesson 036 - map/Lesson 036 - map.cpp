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
#include <map>

int main()
{
    /*
        The standard library provides the map class that can look up values,
        and the two types can be the same or different.

        The first type is defined for the key, and the second type is defined for the value
        associated to the key.
        The key must be unique within the map, so there will only ever be one key/value pair
        for each unique key.

        This lookup will generally perform considerably faster than sequentially searching
        a vector or list, unless the map has only a few items.

        The map will be sorted by the key, so a compare function would need to be provided,
        if you are using a custom type for the key.

        Primitive types such as int or long, library types like std::string can be used
        as a key without providing your own compare function.

        Writing your own compare function is not coveered in this lesson.
    */

    std::map<int, std::string> int_to_string_lookup;

    int_to_string_lookup.insert(std::pair<int, std::string>(1, "One"));
    int_to_string_lookup.insert(std::pair<int, std::string>(2, "Two"));
    int_to_string_lookup.insert(std::pair<int, std::string>(3, "Three"));
    int_to_string_lookup.insert(std::pair<int, std::string>(4, "Four"));
    int_to_string_lookup.insert(std::pair<int, std::string>(5, "Five"));

    // Find the associated string for the integer value.
    // The iterator for a map contains the members, first and second.
    // The variable first contains the key value, and the variable second contains
    // the value for the key.
    int value_to_find = 1;
    std::map<int, std::string>::iterator pos = int_to_string_lookup.find(value_to_find);

    // The lookup will find the string "One" for the integer value 1.
    if (pos != int_to_string_lookup.end())
        std::cout << "Value found for " << pos->first << " is " << pos->second << std::endl;
    else
        std::cout << "Value not found for " << value_to_find << "!" << std::endl;

    // The lookup will find the not find a string for the integer value 6. 
    value_to_find = 6;
    pos = int_to_string_lookup.find(value_to_find);
    if (pos != int_to_string_lookup.end())
        std::cout << "Value found for " << pos->first << " is " << pos->second << std::endl;
    else
        std::cout << "Value not found for " << value_to_find << "!" << std::endl;

    // It is still possible to loop through all the values in a map, and we can display all
    // the key/value pairs.
    for (pos = int_to_string_lookup.begin(); pos != int_to_string_lookup.end(); ++pos)
        std::cout << "Value found for " << pos->first << " is " << pos->second << std::endl;

    return 0;
}
