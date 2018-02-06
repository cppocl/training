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

/*
    C++ allows for files to be included, and the code within these files
    is imported into the file that uses the #include.
    (it's like the code was in the same file)
    Although we won't be covering std::cout or std::endl for now, it's important
    to know that this works because iostream is included, and the
    code for std::cout and std::endl exists within this file.
*/
#include <iostream>

/*
    This is a typical example of a basic C++ program.
    
    The program can be compiled to an executable that can be run
    within a command prompt, terminal or shell.

    When the program is run, it will output the line "Hello World" into
    the command prompt, terminal or shell.

    The main function is the entry point where a program will start.
    Function main knows how many arguments are passed into the program,
    the values of those arguments, and can return a status for the
    command prompt, terminal or shell (via the int return).
*/

/*
C++ comprises of at least once source code file, usually with the file extension of .cpp,
which is the implementation file for private data, functions, etc.

C++ also uses header files, usually with a .hpp file extension for providing definitions of
functions, shared variables, etc.
With some exceptions, header files don't usually implement the code, which will be covered
in later lessons.

For most of the early lessons, only a .cpp file is provided for the example code,
and more .cpp or .hpp files will be introduced in later lessons.

This training uses Visual Studio 2017 Community Edition solution/projects files
as the IDE and compiler is free for personal use.

If C++ is being used on non-Windows platforms, then it's possible to use gcc and make,
but this training material does not cover these topics.
*/

int main()
{
    /*
        This line outputs "Hello World" to the command prompt, terminal or shell.
        Don't concern yourself for now about how this works,
        it will be covered in later lessons.

        It's important to appreciate that programming languages read tokens,
        then identify the purpose of the tokens, which might be a keyword, data type,
        variable name, etc.
        So from the following line of code, these are treated as individual tokens:
            std   ::   cout   <<   "Hello World"   <<   std   ::   endl   ;

        Compilers or interpreters understand tokens and their meaning,
        and things like white space are ignored.
        (although some languages like Python use white space to decide how the code behaves).

        Understanding the existence of tokens will be useful for future lessons.
    */
    std::cout << "Hello World" << std::endl;

    /*
        When function main returns 0, this indicates no error conditions.
        Any non-zero return would indicate an error code.
    */
    return 0;
}
