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

#include <cstdint> // Required for std::int32_t, std::uint32_t, etc.
#include <climits> // Required for CHAR_BIT.
#include <cstddef> // Required for std::size_t.
#include <iostream>

int main()
{
    //
    // The following lines of code show primitive data types built into the C++ language.
    // Data types describe the properties of a variable, including the amount of memory used
    // and what type of information is stored, i.e. integer, floating point number, etc.
    //
    // It's important to remember that when naming a variable, you should avoid starting a
    // variable with the underscore character, as some combinations starting with underscore
    // are reserved for the C++ language.
    // so avoid things like this: int _my_count

    // Boolean values are built in and can have values true or false.
    bool state = false;

    // Character types within C++ to store ASCII characters or a wider range
    // of characters for extended character sets.
    char a_letter = 'A';

    // Note the use of L tells the compiler the character literal is a wide character.
    wchar_t a_wide_letter = L'A';


    // Integer types will store whole numbers, which can be signed types (store negative values),
    // or unsigned types (positive only values).

    // The signed and unsigned char is guaranteed to store at least 8 bits,
    // and is the smallest of the integer types.
    signed char   a = -128;
    unsigned char b =  255;

    // The signed and unsigned short integer is guaranteed to be the same or bigger
    // than the signed and unsigned char types, and will be at least 16-bits.
    signed short int   c = -32768;
    unsigned short int d =  65535;

    // The signed and unsigned integer is guaranteed to be the same or bigger
    // than the signed and unsigned short integer types, and will be at least 16-bits.
    signed int   e = -32768;
    unsigned int f =  65535;

    // The signed and unsigned long integer is guaranteed to be the same or bigger
    // than the signed and unsigned integer types, and will be at least 32-bits.
    signed long int   g = -2147483647L - 1;
    unsigned long int h =  4294967295UL;

    // The signed and unsigned long integer is guaranteed to be the same or bigger
    // than the signed and unsigned integer types, and will be at least 32-bits.
    signed long long int   i = -9223372036854775808LL;
    unsigned long long int j =  18446744073709551615ULL;

    // Floating point (fractions) support negative and positive values.
    float k = -99.5;

    // double type will have the same or better precision than a float.
    double l = 569.335;

    // long double type will have the same or better precision than a double.
    long double m = -7569.138;


    //
    // The following lines of code show data types with fixed sizes from .
    //

    // These types specify the number of bits stored within the type name,
    // and are signed, unless the typename begins with the letter u (for unsigned).
    // Extra C++ types are within the std namespace, and accessing these types is done
    // by placing std:: before the use of the type.  Namespaces are explained later.
    std::int8_t  n  = -128; // signed 8-bit values.
    std::uint8_t o  =  255; // unsigned 8-bit values.
    std::int16_t  p = -32768; // signed 16-bit values.
    std::uint16_t q =  65535; // unsigned 16-bit values.
    std::int32_t  r = -2147483647L - 1;  // signed 32-bit values.
    std::uint32_t s =  4294967295UL; // unsigned 32-bit values.
    std::int64_t  t = -9223372036854775808LL;   // signed 64-bit values.
    std::uint64_t u =  18446744073709551615ULL; // unsigned 64-bit values.

    // sizeof always returns the size of a char, signed char or unsigned char as 1.
    // CHAR_BIT is defined as the number of bits in a char, which is commonly 8 bits.
    // The type returned by sizeof is a std::size_t.
    std::size_t size_of_char_in_bits = sizeof(char) * CHAR_BIT;

    // Remove compiler warnings for unused sample variables outputting the values to screen.
    // Notice the use of (int) is to solve a problem with std::cout not handling those types.
    // The use of (int) is explained in a later lesson regarding type casting.
    std::cout << "state=" << state << std::endl;
    std::cout << "a_letter=" << a_letter << std::endl;
    std::cout << "a_wide_letter=" << a_wide_letter << std::endl;
    std::cout << "a=" << (int)a << std::endl;
    std::cout << "b=" << (int)b << std::endl;
    std::cout << "c=" << c << std::endl;
    std::cout << "d=" << d << std::endl;
    std::cout << "e=" << e << std::endl;
    std::cout << "f=" << f << std::endl;
    std::cout << "g=" << g << std::endl;
    std::cout << "h=" << h << std::endl;
    std::cout << "i=" << i << std::endl;
    std::cout << "j=" << j << std::endl;
    std::cout << "k=" << k << std::endl;
    std::cout << "l=" << l << std::endl;
    std::cout << "m=" << m << std::endl;
    std::cout << "n=" << (int)n << std::endl;
    std::cout << "o=" << (int)o << std::endl;
    std::cout << "p=" << p << std::endl;
    std::cout << "q=" << q << std::endl;
    std::cout << "r=" << r << std::endl;
    std::cout << "s=" << s << std::endl;
    std::cout << "t=" << t << std::endl;
    std::cout << "u=" << u << std::endl;
    std::cout << "size_of_char_in_bits=" << size_of_char_in_bits << std::endl;

    return 0;
}
