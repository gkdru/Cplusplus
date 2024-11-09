#include "Person.h"
#include <iostream>
using namespace std;

Person::Person(const char* name)
{
	this->name = new char[strlen(name) + 1];
	for(size_t i = 0; i < strlen(name) + 1; i++)
	{
		this->name[i] = name[i];
	}
}

Person::Person() : name{new char[strlen("empty")]} 
{
	strcpy_s(name, strlen("empty")+1, "empty");
}

Person::Person(const Person &other)
{
		name = new char[strlen(other.name) + 1];
		strcpy_s(name, strlen(other.name)+1, other.name);
}


Person::~Person()
{
	delete[] name;
}
char* Person::info() const
{
	return this->name;
}