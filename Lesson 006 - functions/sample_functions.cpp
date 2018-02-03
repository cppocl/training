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

/*
*/
#include "sample_functions.hpp"

/*
    Functions are in the form of:
        return type, space, function name, open bracket, arguments and clos bracket.

    Function overloading can differ in the types of data and the number of arguments,
    and this file demonstrates 4 overloaded functions named Square.

    A return type of void means the function does the return a value using the return keyword.
    Values can still be returned to the caller of the function by
    using either pointer(s) or reference(s) as parameter(s).
*/
long Square(long value)
{
    // Standard way for a function to return a value.
    return value * value;
}

float Square(float value)
{
    return value * value;
}

void Square(long value, long& ret)
{
    // The squared result is returned as an argument of the function.
    // Just like the previous references lesson, you can see that
    //
    // any variables passed into this function from outside the function
    // will be updated after this function completes.
    // This is because the reference variable ret is looking at the same
    // variable in memory as the variable passed into this function.
    ret = value * value;
}

void Square(float value, float& ret)
{
    ret = value * value;
}
