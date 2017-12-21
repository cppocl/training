/*
Copyright 2017 Colin Girling

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

#ifndef HEADER_GUARD
#define HEADER_GUARD

/*
    Simple example of how to define a function that works with different
    data types and different numbert of arguments.
*/
long Square(long value);
float Square(float value);

/*
    When the return type is specified as a void type, the function does not
    return the value as a returning function, but instead as another argument
    of the function.
    The reference variable ret will store the sqaured value.
*/
void Square(long value, long& ret);
void Square(float value, float& ret);

#endif
