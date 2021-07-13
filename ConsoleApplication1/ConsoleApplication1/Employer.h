#pragma once
#include <iostream>
#include <string>
using namespace std;

class Employer
{
protected:
	string name;
	int age;
public:
	Employer(string _name, int _age);
	void virtual Print();
};

class President :public virtual Employer
{
public:
	President(string, int);
	void Print() override;
};

class Manager :public virtual Employer
{
public:
	Manager(string, int);
	void Print() override;
};

class Worker :public virtual Employer
{
public:
	Worker(string, int);
	void Print() override;
};