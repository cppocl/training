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

#ifndef OCL_GUARD_TRAINING_LESSON_031_FUNCTION_AND_CLASS_TEMPLATES_ARRAY_HPP
#define OCL_GUARD_TRAINING_LESSON_031_FUNCTION_AND_CLASS_TEMPLATES_ARRAY_HPP

#include <cstddef>
#include <stdexcept>

/*
    It's possible to write a class that will take any type of data,
    and the user of the class can specify the type at the time the
    class is required to be used,

    Unlike a standard class that might be splt into a .hpp and .cpp file,
    template classes cannot be put into .cpp files, as the compiler won't
    know how to generate any of the code in a .cpp file until the class
    is used at the time of specifying the type.

    C++ compilers will generate some of the code into object files from .cpp
    files and then link those together into a final executable, library, etc.

    C++ doesn't know how to generate this object file for template classes,
    because each class is generated with the type provided by the user,
    guaranteeing type safety as part of the template class.

    To guarantee this type safety, the template class is built each time
    there is a new type used with the template class.

    So using the Array class with an int and a float will generate two
    versions of Array for these types.
*/
template<typename T>
class Array
{
public:
    Array()
        : m_array(nullptr)
        , m_size(0)
    {
    }

    ~Array()
    {
        delete[] m_array;
    }

    const T& operator[](std::size_t index) const
    {
        if (index >= m_size)
            throw std::out_of_range("operator[](std::size_t index) const");
        return m_array[index];
    }

    T& operator[](std::size_t index)
    {
        if (index >= m_size)
            throw std::out_of_range("operator[](std::size_t index)");
        return m_array[index];
    }

    std::size_t GetSize() const noexcept
    {
        return m_size;
    }

    void Resize(std::size_t size)
    {
        T* old_arr = m_array;
        std::size_t old_size = m_size;
        T* new_arr;

        if (size > 0)
        {
            // Temporarily store m_array for copying and clear current array data.
            m_array = nullptr;
            m_size = 0;

            // Allocate newly resized array.
            new_arr = new T[size];

            // Copy as many elements as the new array can fit,
            // without going past the end of the old array.
            Copy(new_arr, old_arr, old_size < size ? old_size : size);
        }
        else
            new_arr = nullptr;

        delete[] old_arr;
        m_array = new_arr;
        m_size = size;
    }

    // Helper function for copying elements between two arrays.
    static void Copy(T* dest, const T* src, std::size_t count)
    {
        for (std::size_t pos = 0; pos < count; ++pos)
            dest[pos] = src[pos];
    }

private:
    T* m_array;
    std::size_t m_size;
};

#endif // OCL_GUARD_TRAINING_LESSON_031_FUNCTION_AND_CLASS_TEMPLATES_ARRAY_HPP
