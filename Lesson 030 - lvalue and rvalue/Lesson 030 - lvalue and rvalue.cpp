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

int global_value = 0;

// func1 cannot be used as an lvalue, because it returns an int
// that will only exist for a temporary lifetime.
int func1()
{
    return 1;
}

// func2 can be used as an lvalue, because it returns something
// that  exists in a memory location.
int& func2()
{
    return global_value;
}

int main()
{
    /*
        Traditionally C++ would categorize all expressions as being either lvalue or rvalue.
        lvalues were considered to be the thing on the left side of the assignment operator,
        and rvalues on the right side, although in reality this is a simplistic view.

        In reality rvalues have a limited or temporary lifetime and so won't live longer than
        the than is required to complete the statement.
        lvalues have some sort of existence, even if only while within a function as an example.

        This lesson only covers the basics of lvalue and rvalue, but this topic has complex
        elements that are covered in a later lesson.
    */

    // i and f are lvalues, as they reside in memory.
    // 2 and 1.0 constants are rvalues, because they are temporary and
    // don't have an identifiable memory address (it makes no sense to do &2).
    int i = 2;
    float f = 1.0;

    // As can be seen, it would not be possible to assign the return of func1 to a value
    // as it returns a temporary integer, that won't exist in memory.
    // func1() = 0;

    // global_value is 0.
    std::cout << "global_value = " << global_value << std::endl;

    // func2 can be used as a lvalue as it returns a reference to an int,
    // which has a real memory address.
    func2() = 1;

    // Notice that global_value is now 1.
    std::cout << "global_value = " << global_value << std::endl;

    int a = 1;
    int b = 2;

    // Here a and b are lvalues, but they will produce an implicit rvalue,
    // which is the result of a + b, before c is assigned that resulting value.
    // Note that a + b = 0 would fail as the product of a + b is a rvalue.
    // Then it's simple matter of assigning the lvalue c to the rvalue from a + b.
    int c = a + b;

    std::cout << "c = " << c << std::endl;

    // In some cases its possible to generate a lvalue from a rvalue.
    // An example of this is when using pointers.
    int arr[2] = {0, 1};

    // output arr[] = {0, 1)
    std::cout << "arr[] = {" << arr[0] << ", " << arr[1] << "}" << std::endl;

    int* p = &arr[0];

    // Here the result of p + 1 will be a rvalue, but the * operator (dereference)
    // is allowed to take a rvalue and and treat it as a lvalue, therefor
    // being able to assign the value 2 to the second element in arr.
    *(p + 1) = 2;

    // output arr[] = {0, 2)
    std::cout << "arr[] = {" << arr[0] << ", " << arr[1] << "}" << std::endl;

    return 0;
}
