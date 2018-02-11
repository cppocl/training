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

#include "Vehicle.hpp"
#include <iostream>

Vehicle::Vehicle(const std::string& manufacturer,
                 const std::string& model,
                 std::size_t number_of_wheels)
    : m_manufacturer(manufacturer)
    , m_model(model)
    , m_number_of_wheels(number_of_wheels)
{
    std::cout << "Vehicle constructor" << std::endl;
}

Vehicle::~Vehicle()
{
    std::cout << "Vehicle destructor" << std::endl;
}

const std::string& Vehicle::GetManufacturer() const
{
    return m_manufacturer;
}

const std::string& Vehicle::GetModel() const
{
    return m_model;
}

std::size_t Vehicle::GetNumberOfWheels() const
{
    return m_number_of_wheels;
}
