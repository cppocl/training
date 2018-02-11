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
#include "Motorcycle.hpp"
#include <iostream>

int main()
{
    Car fast_car("Porche", "911", 4, false);
    Motorcycle fast_bike("Yamaha", "YZF R1", 2, false);

    // Although the class being used is a Vehicle, the objects are assigned
    // to a Car and Motorcycle types.
    // The constructors for Car and Motorcycle are called when created dynamically,
    // but once assigned to a base class object, only functions on the base class
    // can be called (unless using workarounds covered later).
    //
    // By making the GetDescription function virtual, this allows the function
    // to be looked up at run time, and the correct GetDescription call is made
    // for the type of the object created.
    //
    // The virtual destructor is required, otherwise it would not be possible to
    // execute the destructor's for Car and Motorcycle, when using a base class pointer.
    Vehicle* standard_car = new Car("Ford", "Focus", 4, true);
    Vehicle* standard_bike = new Motorcycle("Honda", "CB500X", 4, false);

    std::cout << "My fast car is a " << fast_car.GetDescription() << std::endl;
    std::cout << "My fast bike is a " << fast_bike.GetDescription() << std::endl;
    std::cout << "My standard car is a " << standard_car->GetDescription() << std::endl;
    std::cout << "My standard bike is a " << standard_bike->GetDescription() << std::endl;

    delete standard_car;
    delete standard_bike;

    return 0;
}
