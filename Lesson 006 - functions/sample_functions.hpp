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

#ifndef HEADER_GUARD
#define HEADER_GUARD

/*
    The header file is used to define the function name, parameters and return
    type.
    The implementation of these functions can be found in sample_functions.cpp.

    Defining the functions in a header file allows the header file to be included
    in multiple .cpp files, which allows these functions to be used, as the code
    in the .cpp files understands the function names, parameters and return types.
*/

/*
    Simple example of how to define a function that works with different
    data types and different numbers of arguments.
    The first two examples return the value as a returning type
    (the returning type is before the function name).
    Within sample_functions.cpp file the keyword return is used to set the returning value
    within the implementation of these first two functions.
*/
long Square(long value);
float Square(float value);

/*
    When the return type is specified as a void type, the function does not
    return the value.
    This example of the Square function returns the values as parameters of the function,
    instead of the examples above that returned the values using the return keyword.

    The reference variable ret in the Square functions below will store the squared value.
*/
void Square(long value, long& ret);
void Square(float value, float& ret);

#endif
