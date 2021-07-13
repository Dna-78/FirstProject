#include <iostream>
#include "Employer.h"
using namespace std;

int main()
{
	Employer** employers = new Employer * [3];
	employers[0] = new President("John", 52);
	employers[1] = new Manager("Garry", 46);
	employers[2] = new Worker("Ted", 38);
	for (int i = 0; i < 3; i++)
	{
		employers[i]->Print();
	}
}