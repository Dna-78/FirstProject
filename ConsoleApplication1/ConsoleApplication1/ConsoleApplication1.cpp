//#include <iostream>
//#include "Massive.h"
//#include "Massive.cpp"
#include "BinaryTree.h"

//#include "Employer.h"
//using namespace std;
//
//int main()
//{
//	Employer** employers = new Employer * [3];
//	employers[0] = new President("John", 52);
//	employers[1] = new Manager("Garry", 46);
//	employers[2] = new Worker("Ted", 38);
//	for (int i = 0; i < 3; i++)
//	{
//		employers[i]->Print();
//	}
//}

//int main()
//{
//	try
//	{
//		ArrayTemp<int> myMass(5);
//		cout << myMass << endl;
//		myMass.Insert(1, 5);
//		cout << myMass << endl;
//		myMass.Remove(3);
//		cout << myMass << endl;
//	}
//	catch (exception& exp)
//	{
//		cout << exp.what() << endl;
//	}
//}

int main()
{
	BinaryTree tree;
	tree.Add(8);
	tree.Add(3);
	tree.Add(10);
	tree.Add(6);
	tree.Add(1);
	tree.PreOder();
	cout << endl;
	tree.InOder();
	cout << endl;
	tree.PostOder();
}
