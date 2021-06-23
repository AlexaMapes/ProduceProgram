ProduceProgram is a school assignment for a fictional grocery store. Part of the C++ code (the CallProcedure, and CallIntFunc functions) was provided for the assignment, as well as the contents of InputFile.txt.

The program consists of Source.cpp, the C++ file, PY_Code.py, the Python file, and InputFile.txt, the input file.

The program displays a menu via C++, where the user can select one of three options: display a list of purchased items and the amount of times they were purchased, search for a single item and display how manu times it was purchased, or create a histogram of purchased items and how many times they were purchased.

All three options pass a command to the Python code which performs the selected task.

One aspect of the code I feel I handled particularly well was creating the dictionary of each produce item through the use of Python's Counter function.

An enhancement I could make is changing the path of the file created for option three, as right now it creates the file to a specific location on my PC. This was a particularly challenging part of writing this program, as I could not figure out where Python would default write the file to, so I wasn't sure where to then open it from.

An important skill I'm taking away from this project is aiding my ability to work with multiple programming languages at once.

The simplicity of main() in Source.cpp makes this program maintainable and adaptable. My comments within the program help to make it readable.
