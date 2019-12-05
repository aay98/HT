
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	if (argc <2)
	{
		printf("U don't enter file\n");
		return 1;
	}
	//8*60 = 480 MINUTE - MIN TIME ||||||||||| 20*60 = 1200 MINUTE - MAX TIME ||||||||| 1200-240 = 960 (it is all about magic numbers)

	int mas[960] = {0}, buf = 0;
	string temp;
	int EnterTime = 0, ExitTime= 0, minute;
	ifstream InputFile(argv[1]);
	while (!InputFile.eof())
	{
		getline(InputFile,temp);
		for (int i = 0; i < temp.length(); i++)
		{
			if ((temp[i] >= '0') && (temp[i] <= '9'))
			{
				buf *= 10;
				buf += (int)temp[i] - 48;
			}
			else if (temp[i] == ':')
			{
				minute = buf * 60;
				buf = 0;
			}
			else if (temp[i] == ' ')
			{
				EnterTime = minute + buf;
				buf = 0;
			}
		}
		ExitTime = minute + buf;
		if ((EnterTime >= 480) && (ExitTime >= 480))
		{
			EnterTime -= 480;
			ExitTime -= 480;
			for (int i = EnterTime; i < ExitTime; i++)
				mas[i]++;
		}
		buf = 0;

	}
	//массив минут заполнен - ищем максимум
	int max = mas[0]; 
	EnterTime = 0;
	ExitTime = 0;
	for (int i = 0; i < 960; i++)
		if (mas[i]>max)
			max = mas[i];
		/*for (int i = 0; i < 960; i++)
			cout << mas[i] << endl;
		cout << "max - " << max << endl;*/


	//поиск и вывод интервалов
		for (int i = 1; i < 960; i++)
		{
			if (mas[i] == max)
			{
				if (EnterTime == 0)
				{
					EnterTime = i;
					ExitTime = i;
				}
				else
					ExitTime = i;
			}
			else if ((ExitTime != 0) || (mas[0]==max))
			{
				cout << (EnterTime + 480) / 60 << ":" << (EnterTime + 480) % 60 << " " << (ExitTime + 480) / 60 << ":" << (ExitTime + 480) % 60 << endl;
				EnterTime = 0;
				ExitTime = 0;
			}
		}
	InputFile.close();
	return 0;
}

