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
	if (argc == 1)
	{
		printf("U don't enter file\n");
		return 1;
	}
	
	//printf("%d",argc);
	vector <int> vect;
	int buf, sum = 0;
	ifstream InputFile(argv[1]);
	if (!InputFile.is_open())
	{
		printf("Can't open file");
	}
	while (!InputFile.eof())
	{
		InputFile >> buf;
		sum += buf;
		vect.push_back(buf);

	}
	/*for (vector<int>::iterator it = vect.begin(); it != vect.end(); ++it)
		cout << ' ' << *it;
	cout << endl;*/
	sort(vect.rbegin(), vect.rend(), greater<int>());

	//printf("%d \n",vect.size());

	for (vector<int>::iterator it = vect.begin(); it != vect.end(); ++it)
		cout << ' ' << *it;
	cout << endl;
	buf = vect.size() * 0.9 - 1; //так как массив начинается с 0 элемента
	printf("%.2f\n",(float)vect[buf]); // 90 перцентиль
	//медиана
	float buff;
	if (vect.size() % 2 == 0)
	{
		buf = vect.size() / 2;
		buff = (float)(vect[buf] + vect[buf + 1]) / 2;
		printf("%.2f\n", buff);
	}
	printf("%.2f\n", (float)vect[vect.size()-1]); // max
	printf("%.2f\n", (float)vect[1]); //min
	buff = (float) sum / vect.size();
	printf("%.2f\n", buff); //среднее значение
	InputFile.close();
	return 0;
}

