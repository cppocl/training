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

#ifndef OCL_GUARD_TRAINING_LESSON_026_CLASS_INHERITANCE_MOTORCYCLE_HPP
#define OCL_GUARD_TRAINING_LESSON_026_CLASS_INHERITANCE_MOTORCYCLE_HPP

#include "Vehicle.hpp"

class Motorcycle : public Vehicle
{
public:
    Motorcycle(const std::string& manufacturer,
               const std::string& model,
               std::size_t number_of_wheels,
               bool is_two_stroke);

    Motorcycle(const Motorcycle&) = default;

    ~Motorcycle();

    bool IsTwoStroke() const;

private:
    bool m_is_two_stroke;
};

#endif // OCL_GUARD_TRAINING_LESSON_026_CLASS_INHERITANCE_MOTORCYCLE_HPP
