
#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	if (argc < 6)
	{
		printf("U don't enter enouth files\n");
		return 1;
	}
	float mas[5][16];
	for (int i = 1; i < 6; i++)
	{
		ifstream InputFile(argv[i]);
		for (int j = 0; j < 16; j++)
			InputFile >> mas[i - 1][j];
		InputFile.close();
	}
	/*for (int j = 0; j < 16; j++)
	{
		cout << j << " - " << mas[0][j] << ' ' << mas[1][j] << ' ' << mas[2][j] << ' ' << mas[3][j] << ' ' << mas[4][j] << ' ';
		cout << endl;
	}*/
	float MaxSum = mas[0][0] + mas[1][0] + mas[2][0] + mas[3][0] + mas[4][0], sum, num = 1;
	for (int i = 0; i < 16; i++)
	{
		sum = mas[0][i] + mas[1][i] + mas[2][i] + mas[3][i] + mas[4][i];
		if (MaxSum < sum)
		{
			MaxSum = sum;
			num = i + 1;
		}
		//cout << i << " - " << sum << endl;
	}
	cout << num << endl;
	return 0;
}

