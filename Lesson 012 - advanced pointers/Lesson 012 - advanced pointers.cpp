/*
Copyright 2017 Colin Girling

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
        In the lesson demonstrating how to dynamically allocate memory, we could
        create a sequence of values, which behaves very much like an array.

        It's also possible to create multi-dimension arrays with dynamic memory allocation,
        and this is done by using a pointer to a pointer.
        The following code demonstrates how to create a two dimensional array of
        integers dynamically.

        There is also a diagram added in the same folder, which will help to explain
        how these pointers work for the two dimensional array.
        See file: "Pointer to pointer example.png"
    */

    // This line creates 4 rows of integer pointers.
    // each row will store a pointer to some column data (which will each be two integers).
    int** two_dim_ints = new int*[4];

    // Once the rows are allocated, we can allocate columns per row.
    for (int row = 0; row < 4; ++row)
    {
        // Create each row with 2 dynamically allocated integers (i.e. 2 columns).
        two_dim_ints[row] = new int[2];
    }

        two_dim_ints[0] = new int[2];
        two_dim_ints[1] = new int[2];
        two_dim_ints[2] = new int[2];
        two_dim_ints[3] = new int[2];

    // Now we can set values for the rows and columns.
    // After the loops are finished, the rows and columns will be:
    // 0, 1
    // 10, 11
    // 20, 21
    // 30, 31
    for (int row = 0; row < 4; ++row)
        for (int column = 0; column < 2; ++column)
            two_dim_ints[row][column] = (row * 10) + column;

    // Output the values of the rows and columns to the screen;
    for (int row = 0; row < 4; ++row)
    {
        for (int column = 0; column < 2; ++column)
        {
            std::cout << two_dim_ints[row][column];

            // Check the current integer is the first in the row.
            if (column == 0)
                std::cout << ", ";
        }
        std::cout << std::endl;
    }

    // Output the message ready to output the row and colum values in a different way.
    std::cout << std::endl;
    std::cout << "now output the same data using pointer arithmetic." << std::endl;

    // It's also possible to access the rows and pointers,
    // by moving the address of of the pointers along,
    // causing the pointer to point to each of the individual integer values.
    // We only want to change the address of a temporary pointer, so that
    // we don't loose the original memory location, as we need this address
    // later to free the memory once it's been used.
    int** tmp_two_dim_ints = two_dim_ints;

    // We know that there are 4 integer pointers stored, so we can loop
    // up until the last integer pointer.
    int** two_dim_ints_end = two_dim_ints + 4;
    while (tmp_two_dim_ints < two_dim_ints_end)
    {
        // We know each row stores the address of an integer pointer,
        // which stores two integer values.
        int* the_row = *tmp_two_dim_ints;

        // Each row contains two columns, so mark the end.
        int* the_row_end = the_row + 2;

        // Now we have the start of each row, we can loop through each integer.
        while (the_row < the_row_end)
        {
            std::cout << *the_row;

            // Check the current integer pointer is the first in the row.
            if (the_row == *tmp_two_dim_ints)
                std::cout << ", ";

            // Increment the pointer, moving the address to the next integer.
            // Note that the address will move by the size of the integer,
            // which will most likely be 4 bytes, as integers are usually 32-bits in size.
            ++the_row;
        }
        std::cout << std::endl;

        // Now that the integers for the current row are output to screen,
        // we can move onto the next row. Incrementing this pointer will cause
        // the address to be increased by the amount of memory required to store
        // an integer address.
        // Any address would be 8 bytes or 64-bits on a 64-bit operating system.
        ++tmp_two_dim_ints;
    }

    // Now the columns need to be freed from memory, before freeing the rows.
    for (int row = 0; row < 4; ++row)
        delete[] two_dim_ints[row]; // Free each row containing two integers.

    // Finally free the rows, which were storing integer pointers.
    delete[] two_dim_ints;

    return 0;
}
