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
#include <cstddef>
#include <string>

const std::size_t PEOPLE_COUNT = 4;

const std::string first_names[PEOPLE_COUNT] =
{
    "Anna",
    "James",
    "Paul",
    "Jessica",
};

const std::string last_names[PEOPLE_COUNT] =
{
    "Smith",
    "Baker",
    "Jones",
    "Burns",
};

// Create an extra address for any non-matching searches.
const std::string addresses[PEOPLE_COUNT + 1] =
{
    "10 High Street, London",
    "33 Side Street, Birmingham",
    "18 Portland Close, Manchester",
    "6 Average Road, Bristol",
    "Unknown address"
};

std::string GetFullName(const std::string& first_name, const std::string& last_name)
{
    return first_name + " " + last_name;
}

const std::string& GetAddress(const std::string& first_name, const std::string& last_name)
{
    std::size_t pos = 0;
    for (; pos < PEOPLE_COUNT; ++pos)
        if (first_name == first_names[pos] && last_name == last_names[pos])
            break;
    return addresses[pos];
}

int main()
{
    /*
        The auto keyword allows a variable to be created without
        needing to know what data type is required.

        This can reduce the amount that needs typing, but will also hide
        details about the type of data being used.

        The auto keyword will deduce the type from the variable or
        returning value from a function, and be defined automatically.
    */

    // auto will actually be defined as a std::string type.
    auto full_name = GetFullName(first_names[0], last_names[0]);

    // The name "Anna Smith" will be output to the screen.
    std::cout << " full name is " << full_name << std::endl;

    // Although GetAddress returns a constant reference string,
    // auto will actually be a std::string (the constant and reference are removed).
    auto address0 = GetAddress(first_names[0], last_names[0]);

    // If you want to make use of the constant reference return to avoid
    // copying the string into another part of memory, you can add
    // the constant and reference to auto.
    const auto& address1 = GetAddress(first_names[1], last_names[1]);

    // Outputting address0 and address1 and comparing addresses to the addresses
    // array demonstrates where auto creates a std::string or a const std::string&.

    std::cout << "address0 is \"" << address0 <<
                 "\" and addresses[0] is \"" << addresses[0] << "\"" << std::endl;

    // You will see that the memory location for address0 and addresses[0] are different.
    std::cout << "memory location for address0 is \"" << &address0 << "\" and " <<
                 "memory location for addresses[0] is \"" << &addresses[0] << "\"" << std::endl;

    std::cout << "address1 is \"" << address1 << "\" and " <<
                 "addresses[1] is \"" << addresses[1] << "\"" << std::endl;

    // You will see that the memory location for address1 and addresses[1] are the same.
    std::cout << "memory location for address1 is \"" << &address1 << "\" and " <<
                 "memory location for addresses[1] is \"" << &addresses[1] << "\"" << std::endl;

    // Note this is the same as const auto&
    auto const& not_found = GetAddress("Bob", "Brown");

    // You will see the address was not found, so will output Unknown address.
    std::cout << "address for Bob Brown is " << not_found << std::endl;

    // Notice that auto will define a const std::string* data type for ptr_address2.
    // This is because we have taken then returning reference from GetAddress and
    // asked for the address using & operator (look back to earlier pointer training).
    auto ptr_address2 = &GetAddress(first_names[2], last_names[2]);
    std::cout << "ptr_address2 is \"" << *ptr_address2 <<
                 "\" and addresses[2] is \"" << addresses[2] << "\"" << std::endl;

    // We can prove ptr_address2 is constant because we cannot compile the following line.
    // *ptr_address2 = "";

    // Because the type is a const std::string* only the string is constant, not the pointer.
    // So we can provide again the type of ptr_address2 is const std::string* because we
    // can set the address to null.
    // We also know it's a pointer because we had to // dereference
    // ptr_address2 is the std::cout line above.
    ptr_address2 = nullptr;

    return 0;
}
