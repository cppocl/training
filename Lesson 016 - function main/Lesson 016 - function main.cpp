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
#include <cstddef>
#include <string>

int main(int argc, char *argv[])
// It's also valid to define: int main(int argc, char **argv)
{
    /*
        All the examples until now have defined main without parameters: int main()
        If you want to have access to the argements passed to a program at a command line,
        while is common in a Windows prompt or Linux terminal, then main can access
        these values using argc and argv.
        argc is the count for the number of arguments stored in argv.

        argv[0] will be the name of the executable including the path, so for this lesson argv[0]
        would be "C:\...\training\...\Lesson 016 - function main.exe".
        All other strings in argv would the the values passed to your program
        on the command line of the command prompt or terminal.

        e.g.
        C:\> "Lesson 016 - function main.exe" hello goodbye
        Running that line would mean argv[1] would be "hello" and argv[2] would be "goodbye".
    */

    // Display each argv value on it's own line on the screen.
    for (int pos = 0; pos < argc; ++pos)
        std::cout << "argv[" << pos << "] is \"" << argv[pos] << "\"" << std::endl;

    // Unlike other C++ functions, function main is not required to return a value,
    // but if it does not then the return will automatically be 0, meaning no error.
    return 0;
}
