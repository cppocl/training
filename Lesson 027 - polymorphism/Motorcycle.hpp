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

#ifndef OCL_GUARD_TRAINING_LESSON_027_POLYMORPHISM_MOTORCYCLE_HPP
#define OCL_GUARD_TRAINING_LESSON_027_POLYMORPHISM_MOTORCYCLE_HPP

#include "Vehicle.hpp"

class Motorcycle : public Vehicle
{
public:
    Motorcycle(const std::string& manufacturer,
               const std::string& model,
               std::size_t number_of_wheels,
               bool is_two_stroke);

    Motorcycle(const Motorcycle&) = default;

    /// Although we have not specifically said this is virtual, because the
    /// base class is a virtual destructor, this will automatically be virtual.
    ~Motorcycle();

    bool IsTwoStroke() const;

    /// The override specifier is there to help reduce mistakes, by ensuring
    /// any base class functions are defined with the same number of parameters
    /// and are const or not const, depending on the definition.
    /// If the base virtual function did not match how the function was defined,
    /// the compiler will generate an error.
    std::string GetDescription() const override;

private:
    bool m_is_two_stroke;
};

#endif // OCL_GUARD_TRAINING_LESSON_027_POLYMORPHISM_MOTORCYCLE_HPP
