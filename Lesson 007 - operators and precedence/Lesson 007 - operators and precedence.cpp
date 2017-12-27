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

#include <cstddef>
#include <iostream>

int main()
{
    /*
        C++ has operators buit into the language that allow us to assign values,
        compare values, do mathematcs such as addition or subtracton, etc.

        Operators also a precedence (priority order) in how they are handled.
        They also have an associativity with the variables or objects, all of
        which will be explained in the examples.
    */

    /*
        Ths is a simple example of using two operators (assignment and addition)
        in a single statement.
        Note the statement is complete when the semi-colon is reached.

        Because the + operator has higher precedence than the = operator,
        the addition happens first, then the assignment will happen after the addition.

        The + operator can be unary (e.g. +1) or binary (1 + 2), although this does not
        apply to all operators.

        Because the + operator has higher priority it evaluates 1 + 2 first,
        then the = opeartor is evaluated.

        The statement is broken into expressions, each of which are evaluated based
        on the precedence rules, so 1 + 2 will be evaluated as a separate expression
        from a = 3, which will be the first expression after 1 + 2 is evaluates to 3.
    */
    int a = 1 + 2;
    std::cout << "a = " << a << std::endl;

    /*
        Operators * and / have the same precedence, so they follow from left to right,
        so 3 * 4 will be evaulated first, then 12 / 2 will then be evaluated.
    */
    int b = 3 * 4 / 2;
    std::cout << "b = " << b << std::endl;

    /*
        Brackets can also be used to override the operator ordering.
        The following example will ensure 4 / 2 is evaluated first,
        then 3 * 2 will be the next evailation, finally setting c to 6.
    */
    int c = 3 * (4 / 2);
    std::cout << "c = " << c << std::endl;

    /*
        The operators are ordered in precedence groups, with eacH group having either
        left to right or right to left associativity.

        The following table provides the groups, associativity, operators and description of operators.

        operator   description   (Group 1 - left to right)
        ========   ===========
        ::         scope resolution

        operator   description   (Group 2 - left to right)
        ========   ===========
        ++         postfix increment
        --         postfix decrement
        type()     functional cast
        type{}     functional cast
        f()        function call
        a[]        subscript
        .          member access
        ->         pointer member access

        operator   description   (Group 3 - right to left)
        ========   ===========
        ++         prefix increment
        --         prefix decrement
        +          unary plus
        -          unary minus
        !          logical not
        ~          bitwise not
        (type)     C-style cast
        *          indirection (dereference pointer)
        &          address of
        sizeof     size of type or expression
        new        dynamic allocation of memory
        delete     dynamc memory deallocation

        operator   description   (Group 4 - left to right)
        ========   ===========
        .*         pointer to member (object)
        ->*        pointer to member (pointer)

        operator   description   (Group 5 - left to right)
        ========   ===========
        *          binary muliply
        /          binary divide
        %          binary modulus (remainder)

        operator   description   (Group 6 - left to right)
        ========   ===========
        +          binary plus
        -          binary minus

        operator   description   (Group 7 - left to right)
        ========   ===========
        <<         bitwise left shift
        >>         bitwise right shift

        operator   description   (Group 8 - left to right)
        ========   ===========
        <=>        three way comparison

        operator   description   (Group 9 - left to right)
        ========   ===========
        <          less than comparison
        <=         less than or equal comparison
        >          greater than comparison
        >=         greater than or equal comparison

        operator   description   (Group 10 - left to right)
        ========   ===========
        ==         is equal comparison
        !=         is not equal comparison

        operator   description   (Group 11 - left to right)
        ========   ===========
        &          bitwise and

        operator   description   (Group 12 - left to right)
        ========   ===========
        ^          bitwise xor

        operator   description   (Group 13 - left to right)
        ========   ===========
        |          bitwise or

        operator   description   (Group 14 - left to right)
        ========   ===========
        &&         logical and

        operator   description   (Group 15 - left to right)
        ========   ===========
        ||         logical and

        operator   description   (Group 16 - right to left)
        ========   ===========
        ?:         ternary conditional
        =          assignment
        +=         compound assignment (add to self)
        -=         compound assignment (subtract from self)
        *=         compound assignment (multiply with self)
        /=         compound assignment (divide with self)
        %=         compound assignment (modulus with self)
        <<=        compound assignment (bitwise left shift self)
        >>=        compound assignment (bitwise right shift self)
        &=         compound assignment (bitwise and with self)
        ^=         compound assignment (bitwise xor with self)
        |=         compound assignment (bitwise or with self)
        throw      throw operator (Microsoft has throw as group between 16 and 17)

        operator   description   (Group 17 - left to right)
        ========   ===========
        ,          comma
    */

    return 0;
}
