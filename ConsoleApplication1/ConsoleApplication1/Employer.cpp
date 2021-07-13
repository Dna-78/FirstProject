#include "Employer.h"

Employer::Employer(string _name, int _age)
{
	this->name = _name;
	this->age = _age;
}

void Employer::Print()
{
	cout << this->name << " " << this->age << endl;
}


President::President(string _name, int _age) :
	Employer(_name, _age)
{
}

void President::Print()
{
	Employer::Print();
	cout << "President" << endl;
}

Manager::Manager(string _name, int _age) :
	Employer(_name, _age)
{
}

void Manager::Print()
{
	Employer::Print();
	cout << "Manager" << endl;
}

Worker::Worker(string _name, int _age) :
	Employer(_name, _age)
{
}

void Worker::Print()
{
	Employer::Print();
	cout << "Worker" << endl;
}
