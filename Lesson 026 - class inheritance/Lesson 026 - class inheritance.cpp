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

    std::cout << "My fast car is a " << fast_car.GetManufacturer() << " " << fast_car.GetModel() << std::endl;
    std::cout << "My fast bike is a " << fast_bike.GetManufacturer() << " " << fast_bike.GetModel() << std::endl;

    /*
        When fast_car and fast_bike are cleaned up, which happens when function main returns,
        the destructor's for both objects are automatically called.
        Because fast_car was defined first, it is constructed first and then destroyed last.
        Object creation and destruction is in the order of first in last out.
    */

    return 0;
}
