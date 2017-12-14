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

int main(int argc, char** argv)
{
    // Prevent the compiler warning about argc and argv not being used.
    (void)argc;
    (void)argv;

    // This line outputs "Hello World" to the command prompt, terminal or shell.
    std::cout << "Hello World" << std::endl;

    // When function main returns 0, this indicates no error conditions.
    // Any non-zero return would indicate an error code.
    return 0;
}
