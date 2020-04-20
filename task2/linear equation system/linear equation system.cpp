#include"Class1.h"
#include"Class2.h"
#include <iostream>
#include<vector>
#include<ctime>
#include <clocale>
using namespace std;

int main()
{
	setlocale(0, "");
	srand(time(NULL));
	int n = 3;
	SystemLinearEquation s(n);
	LinearEquation a1(3);
	LinearEquation a2(3);
	LinearEquation a3(3);
	a1.random_initialization();
	a2.random_initialization();
	a3.random_initialization();
	s.add(a1);
	s.add(a2);
	s.add(a3);
	cout << "Система 1: " << endl;
	cout << (string)s << endl;
	s.steppingUp();
	cout << "Система 2: " << endl;
	cout << (string)s << endl;
	vector<double> solve = s.solveSystem();
	cout << "Ответ: ";
	for (int i = 0; i < solve.size(); i++)
		cout << solve[i] << "   ";
}

