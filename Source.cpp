#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PY_Code");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PY_Code");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PY_Code");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}

// Displays menu options
void mainMenu() {
	cout << "*******GROCER CORNER PRODUCE PROGRAM*******" << endl;
	cout << "Please select from the following options:" << endl;
	cout << "1. List of items purchased" << endl;
	cout << "2. Single item purchase frequency" << endl;
	cout << "3. Graph of items purchased" << endl;
	cout << "4. Exit program" << endl;
}


int main() {
	int userChoice = 0;
	string userSearch;
	string itemName;
	int itemFreq;

	while (userChoice != 4) {
		// Output menu options
		mainMenu();
		cin >> userChoice;
		if (userChoice == 1) {
			// Calls Python to create frequency list
			CallProcedure("frequencyList");
		}
		else if (userChoice == 2) {
			// Promps user for item to search for
			cout << "Please enter the item you wish to search for: " << endl;
			cin >> userSearch;
			// Calls Python to search for that item in the frequency list
			callIntFunc("itemSearch", userSearch);
		}
		else if (userChoice == 3) {
			// Calls Python to create the .dat file
			CallProcedure("createFile");

			// Creates input stream for the file
			ifstream FileReader("C:\\Users\\Lexi\\Documents\\School\\Programming Languages\\Project_Three\\Project_Three\\frequency.dat");

			// Checks if file was successfully opened
			if (!FileReader.is_open()) {
				cout << "File could not be read" << endl;
				return 1;
			}

			// Reads file and outputs histogram
			else {
				while (1) {
					FileReader >> itemName;
					FileReader >> itemFreq;
					if (FileReader.eof()) {
						break;
					}
					cout << setw(12) << left << itemName;
					for (int i = 1; i <= itemFreq; ++i) {
						cout << "*";
					}
					cout << endl;
				}
			}
			FileReader.close();

			cout << endl;
		}

		// Checks for exit choice
		else if (userChoice == 4) {
			cout << "Exiting" << endl;
			continue;
		}

		// Checks for any other choice
		else {
			cout << "Invalid choice" << endl << endl;
		}
	}


}