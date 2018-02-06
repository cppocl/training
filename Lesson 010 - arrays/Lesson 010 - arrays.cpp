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
        Arrays of data types allows a sequence of values to be stored, changed or indexed.
        This is useful for many purposes, from reading a file, storing text messages,
        having a sequence of numbers for adding, calculating averages, etc.
        Arrays are also useful for iterating through with loops, making it easier to
        perform algorithms on data sets.
    */

    // Define an array of 4 integers, that will be stored sequentially in memory.
    int ages[4];

    ages[0] = 21;
    ages[1] = 35;
    ages[2] = 70;
    ages[3] = 16;

    int total_age = 0;
    for (int pos = 0; pos < 4; ++pos)
        total_age += ages[pos];

    // Output the total and average age of all 4 ages in the array to the screen.
    std::cout << "Total age is " << total_age << std::endl;
    std::cout << "Average age is " << (total_age / 4) << std::endl;

    // It's also possible to have arrays of other types, not just numeric types,
    // and also set the values at the time of defining the array.
    std::string names[4] = {"James", "Peter", "Sarah", "Michelle"};

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

    // It is also possible to change the values in the array.
    ages[0] = 50;
    names[0] = "David";

    // It's also possible to have multi-dimension arrays.
    int height_cm_and_weight_kg[4][2] = // 4 rows and 2 columns.
    {
        {178, 80},
        {182, 90},
        {165, 65},
        {152, 48}
    };

    // Output the names and ages to the screen, with height and weight to the screen.
    for (int pos = 0; pos < 4; ++pos)
    {
        std::cout << names[pos];
        std::cout << " is ";
        std::cout << ages[pos] << " years old, ";
        std::cout << height_cm_and_weight_kg[pos][0] << "cm tall, ";
        std::cout << "weighing " << height_cm_and_weight_kg[pos][1] << "kg";
        std::cout << std::endl;
    }

    return 0;
}
