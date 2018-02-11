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

#ifndef OCL_GUARD_TRAINING_LESSON_026_CLASS_INHERITANCE_VEHICLE_HPP
#define OCL_GUARD_TRAINING_LESSON_026_CLASS_INHERITANCE_VEHICLE_HPP

#include <string>
#include <cstddef>

/*
    Inheritance provides the ability to create a class with common behavior to be
    shared later by other classes, by inheriting the class as a base class.
    A base class are also known as a superclass and a class that inherits the
    base class is also known as a subclass or derived class.

    We have already seen that public data or functions can be accessed by the
    outside users of the class, and private data or functions is only available
    internally for the class defining the private parts.

    With inheritance we can also defined protected code, that is only available
    to the base class or derived class, but not available to the user of the
    base or derived class (so not through an object or instance of the class).

    The decision on whether to inherit a class or have the class as a variable
    of the class should be based on the question "is a" or "has a".
    So if a car is a vehicle then we look to inherit, as this is an extension
    of something related.
    If a car has wheels, then this is a property of the class, so would be
    stored as a variable of the class.

    Although this example only keeps track of the number of wheels, it would
    also be possible to define a Wheel class and store an array of wheels
    as an example of how to improve on a design.
    Why might you care to store an array of wheels? Well you might want to track
    the types of the tyres on the wheels, if there is a puncture, etc.
*/

class Vehicle
{
public:
    /// Notice there is no default constructor (one with no parameters),
    /// as we want to mimic real life, and all cars have a manufacturer,
    /// model and number of wheels.
    Vehicle(const std::string& manufacturer,
            const std::string& model,
            std::size_t number_of_wheels);

    /// Because a constructor was already defined above, we would not get
    /// an automatically generated copy constructor unless we specify we
    /// want a default one.
    /// We don't need to implement this default copy constructor,
    /// the compiler will do this for us.
    ///
    /// Also notice we did not specify a variable name for the parameter.
    /// There isn't actually a requirement to provide variables names for
    /// functions in the header files, but we do this for readability.
    /// We know this function isn't manually implemented so the variable
    /// name was left out.
    Vehicle(const Vehicle&) = default;

    ~Vehicle();

    /// Because we are modelling something that is physical and exists
    /// in real life, we have not provided set functions,
    /// as a vehicle wouldn't change it's manufacturer or model once created.
    /// It is expected that after the vehicle is created, these will remain
    /// the same throughout the lifetime of the object.
    const std::string& GetManufacturer() const;
    const std::string& GetModel() const;
    std::size_t GetNumberOfWheels() const;

private:
    std::string m_manufacturer;
    std::string m_model;
    std::size_t m_number_of_wheels;
};

#endif // OCL_GUARD_TRAINING_LESSON_026_CLASS_INHERITANCE_VEHICLE_HPP
