// task1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm> 
#include <functional>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	if (argc < 3 )
	{
		printf("U don't enter enouth files\n");
		return 1;
	}
	
	float mas[4][2]; //4 точки х и y
	ifstream InputFileVertex(argv[1]);
	if (!InputFileVertex.is_open())
	{
		printf("Can't open 1 file");
		return 1;
	}
	for (int i = 0; i < 4; i++)
	{
		InputFileVertex >> mas[i][0] >> mas[i][1]; //считывание х и у каждой точки прямоугольника
	}

	ifstream InputFilePoints(argv[2]);
	if (!InputFilePoints.is_open())
	{
		printf("Can't open 2 file");
		return 2;
	}
	float Maxx = mas[1][0], Maxy = mas[1][1], Minx = mas[2][0], Miny = mas[2][1];
	for (int i = 0; i < 4; i++)
	{
		if (mas[i][1] >Maxx)
			Maxx = mas[i][0];
		else if	(mas[i][1] < Minx)
			Minx = mas[i][0];
		if (mas[i][2] >Maxy)
			Maxy = mas[i][1];
		else if (mas[i][2] < Miny)
			Miny = mas[i][1];

	}

	float x, y;
	while (!InputFilePoints.eof())
	{
		InputFilePoints >> x >> y; //считывание х и у точки
		if ((x < Maxx) && (x > Minx) && (y > Miny) && (y < Maxy))
			cout << '2' << endl;
		else if ((x > Maxx) || (x < Minx) || (y < Miny) || (y > Maxy))
			cout << '3' << endl;
		else if ((x == Maxx) || (x == Minx) && ( (y == Miny) || (y == Maxy)))
			cout << '0' << endl;
		else if ((x == Maxx) || (x == Minx) || ((y == Miny) || (y == Maxy)))
			cout << '1' << endl;
	}
	
	InputFileVertex.close();
	InputFilePoints.close();
	return 0;
}

