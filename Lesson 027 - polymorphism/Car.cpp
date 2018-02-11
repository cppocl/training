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

#include "Car.hpp"
#include <iostream>

Car::Car(const std::string& manufacturer,
         const std::string& model,
         std::size_t number_of_wheels,
         bool is_left_hand_drive)
    : Vehicle(manufacturer, model, number_of_wheels)
    , m_is_left_hand_drive(is_left_hand_drive)
{
    /*
        Notice the we have called the constructor for the base class Vehicle.
        Before we can create a Car object we need to create the base class object,
        then the variables in the Car class can be initialised,
        which in this case m_is_left_hand_drive is initialised.
    */

    std::cout << "Car constructor for " << GetManufacturer() << " " << GetModel() << std::endl;
}

Car::~Car()
{
    /*
        You will see that the destructor for Car is called to perform
        any cleanup, but then the base class destructor for Vehicle is also
        automatically called to ensure base class objects are also cleaned up.
    */
    std::cout << "Car destructor for " << GetManufacturer() << " " << GetModel() << std::endl;
}

bool Car::IsLeftHandDrive() const
{
    return m_is_left_hand_drive;
}

std::string Car::GetDescription() const
{
    // We can first set the description from the base class by explicitly
    // calling GetDescription on the Vehicle base class, then appending
    // information relevant to the Car class.
    std::string description = Vehicle::GetDescription();
    description += IsLeftHandDrive() ? ", left hand drive" : ", right hand drive";
    return description;
}
