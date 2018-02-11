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

#include "Motorcycle.hpp"
#include <iostream>

Motorcycle::Motorcycle(const std::string& manufacturer,
                       const std::string& model,
                       std::size_t number_of_wheels,
                       bool is_two_stroke)
    : Vehicle(manufacturer, model, number_of_wheels)
    , m_is_two_stroke(is_two_stroke)
{
    // See comments within Car constructor to see explanation of how this works.
    std::cout << "Motorcycle constructor for " << GetManufacturer() << " " << GetModel() << std::endl;
}

Motorcycle::~Motorcycle()
{
    // See comments within Car destructor to see explanation of how this works.
    std::cout << "Motorcycle destructor for " << GetManufacturer() << " " << GetModel() << std::endl;
}

bool Motorcycle::IsTwoStroke() const
{
    return m_is_two_stroke;
}

std::string Motorcycle::GetDescription() const
{
    // We can first set the description from the base class by explicitly
    // calling GetDescription on the Vehicle base class, then appending
    // information relevant to the Motorcycle class.
    std::string description = Vehicle::GetDescription();
    description += IsTwoStroke() ? ", 2 stroke" : ", 4 stroke";
    return description;
}
