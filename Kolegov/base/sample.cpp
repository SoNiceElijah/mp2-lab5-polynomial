﻿#include "polynom.h"
#include <string>

using namespace std;


int main()
{
	//Надеюсь что пользователь будет вводить корректные данные


	Polynom p1;
	p1.GetPolynomFromConsole();

	Polynom p2;
	p2.GetPolynomFromConsole();

	Polynom res = p1 + p2;
	res.Calculate();

	system("pause");

	return 0;
}
