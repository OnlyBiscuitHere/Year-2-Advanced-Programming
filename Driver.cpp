/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for assignment
Fall 2019

Written by Ayse Kucukyilmaz

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure
you follow that guideline. Also make sure that you don't
change the main body provided to you here.
Otherwise, your code may not pass the test cases...

GOOD LUCK!

------------------------------------------------------ */

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Movable.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstring>

#define MAX_LEN_PERIMETERS 32

using namespace std;

int main()
{
	string userCommand;
	vector <Shape*> shapes;     // this one will hold your shapes
	vector <string> parameters; // this one will hold parameters for the commands

	while (userCommand.compare("exit") != 0)
	{
		parameters.clear();
		cout << "Enter the command: ";

		getline(cin, userCommand);

		char* cstr = new char[userCommand.length() + 1];

		strcpy_s(cstr, userCommand.length() + 1, userCommand.c_str());
		char* next_token;
		char* token = strtok_s(cstr, " ", &next_token);
		while (token)
		{
			parameters.push_back(std::string(token));
			token = strtok_s(NULL, " ", &next_token);
		}

		string command = parameters[0];
		if (command.compare("addR") == 0 && parameters.size() >= 5) {
			//Getting the parameters
			int x = strtol(parameters[1].c_str(), NULL, 10);
			int y = strtol(parameters[2].c_str(), NULL, 10);
			int h = strtol(parameters[3].c_str(), NULL, 10);
			int w = strtol(parameters[4].c_str(), NULL, 10);
			//Instaniating the object
			Rectangle* r = new Rectangle(x, y, w, h);
			shapes.push_back(r);
			//Operator overloaded object
			cout << r;
		}
		else if (command.compare("addS") == 0 && parameters.size() >= 4) {
			int x = strtol(parameters[1].c_str(), NULL, 10);
			int y = strtol(parameters[2].c_str(), NULL, 10);
			int e = strtol(parameters[3].c_str(), NULL, 10);

			Square* s = new Square(x, y, e);
			shapes.push_back(s);
			cout << s;
		}

		if (command.compare("addC") == 0 && parameters.size() >= 4) {
			int x = strtol(parameters[1].c_str(), NULL, 10);
			int y = strtol(parameters[2].c_str(), NULL, 10);
			int r = strtol(parameters[3].c_str(), NULL, 10);

			Circle* c = new Circle(x, y, r);
			shapes.push_back(c);
			cout << c;
		}
		else if (command.compare("scale") == 0 && parameters.size() >= 4) {
			int shapeNo = strtol(parameters[1].c_str(), NULL, 10);
			int scaleX = strtol(parameters[2].c_str(), NULL, 10);
			int scaleY = strtol(parameters[3].c_str(), NULL, 10);
			//Exception handling for any errors
			try
			{
				Movable* m = dynamic_cast<Movable*>(shapes.at(shapeNo - 1));
				m->scale(scaleX, scaleY);

				Rectangle* r = dynamic_cast<Rectangle*>(shapes.at(shapeNo - 1));
				if (r != nullptr)
				{
					cout << r;
				}

				Square* s = dynamic_cast<Square*>(shapes.at(shapeNo - 1));
				if (s != nullptr)
				{
					cout << s;
				}

				Circle* c = dynamic_cast<Circle*>(shapes.at(shapeNo - 1));
				if (c != nullptr)
				{
					cout << c;
				}
			}
			//If there are any objects out of range
			catch (const std::out_of_range&)
			{
				cout << "Array out of range" << "\n";
			}
			//If a runtime error occurs
			catch (const std::runtime_error& e)
			{
				cout << e.what() << "\n";
			}
		}
		else if (command.compare("move") == 0 && parameters.size() >= 4) {
			int shapeNo = strtol(parameters[1].c_str(), NULL, 10);
			int moveX = strtol(parameters[2].c_str(), NULL, 10);
			int moveY = strtol(parameters[3].c_str(), NULL, 10);

			try
			{
				Movable* m = dynamic_cast<Movable*>(shapes.at(shapeNo - 1));
				m->move(moveX, moveY);

				Rectangle* r = dynamic_cast<Rectangle*>(shapes.at(shapeNo - 1));
				if (r != nullptr)
				{
					cout << r;
				}

				Square* s = dynamic_cast<Square*>(shapes.at(shapeNo - 1));
				if (s != nullptr)
				{
					cout << s;
				}

				Circle* c = dynamic_cast<Circle*>(shapes.at(shapeNo - 1));
				if (c != nullptr)
				{
					cout << c;
				}
			}
			catch (const std::out_of_range&)
			{
				cout << "Array out of range" << "\n";
			}
			catch (const std::runtime_error& e)
			{
				cout << e.what() << "\n";
			}
		}
		else if (command.compare("display") == 0) {
			for (Shape* sh : shapes)
			{
				Rectangle* r = dynamic_cast<Rectangle*>(sh);
				if (r != nullptr)
				{
					cout << r;
				}

				Square* s = dynamic_cast<Square*>(sh);
				if (s != nullptr)
				{
					cout << s;
				}

				Circle* c = dynamic_cast<Circle*>(sh);
				if (c != nullptr)
				{
					cout << c;
				}
			}
		}

		cout << endl;
	}

	cout << "Press any key to continue...";
	std::getchar();

	return 0;
}
