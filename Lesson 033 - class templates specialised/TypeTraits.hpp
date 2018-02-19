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

#ifndef OCL_GUARD_TRAINING_LESSON_033_CLASS_TEMPLATES_SPECIALISED_TYPETRAITS_HPP
#define OCL_GUARD_TRAINING_LESSON_033_CLASS_TEMPLATES_SPECIALISED_TYPETRAITS_HPP

/*
    It's possible to define a template class, and specialise certain types to do
    something different.
    This example allows the user to identify the traits of a type to see if it's
    a character type.
*/
template<typename T>
class TypeTraits
{
public:
    static bool IsCharacter() { return false; }
};

template<>
class TypeTraits<char>
{
public:
    static bool IsCharacter() { return true; }
};

template<>
class TypeTraits<wchar_t>
{
public:
    static bool IsCharacter() { return true; }
};

#endif // OCL_GUARD_TRAINING_LESSON_033_CLASS_TEMPLATES_SPECIALISED_TYPETRAITS_HPP
