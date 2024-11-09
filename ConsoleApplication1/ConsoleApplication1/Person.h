#pragma once
#include <iostream>
using namespace std;

class Person
{
	char* name;
public:
	Person(const char* name);
	Person();
	Person(const Person& other);
	~Person();

	char* info() const;
};
