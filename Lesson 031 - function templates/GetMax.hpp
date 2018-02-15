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

#ifndef OCL_GUARD_TRAINING_LESSON_031_FUNCTION_AND_CLASS_TEMPLATES_GETMAX_HPP
#define OCL_GUARD_TRAINING_LESSON_031_FUNCTION_AND_CLASS_TEMPLATES_GETMAX_HPP

/*
    It's also possible to create functions that take user specified types.
    The compiler can work out the types for a template function,
    so there is not need to specify the type when using the GetMax function.
*/
template<typename T>
T GetMax(T value1, T value2)
{
    return value1 > value2 ? value1 : value2;
}

/*
    When a function template only returns a value, the type will need to
    be specified to use the function.
*/
template<typename T>
T PI()
{
    return static_cast<T>(3.14);
}

#endif // OCL_GUARD_TRAINING_LESSON_031_FUNCTION_AND_CLASS_TEMPLATES_GETMAX_HPP
