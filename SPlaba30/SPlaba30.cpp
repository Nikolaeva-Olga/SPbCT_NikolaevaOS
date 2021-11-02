#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	char ch;
	float a, b, c;
	bool done = false;
	while (!done)
	{
		cout << "1) Запустить" << endl;
		cout << "2) Выход" << endl;
		cout << "Выберите функцию ";
		cin >> ch;
		switch (ch)
		{
		case '1':
		{
			cout << "\na = ";
			cin >> a;
			cout << "b = ";
			cin >> b;
			cout << "c = ";
			cin >> c;
			if (a >= 0 || b >= 0  || c >= 0)
			{
				if ((a + b + c) == 180)
				{
					if (a == 90 || b == 90 || c == 90) // (2)
						cout << "Прямоугольный треугольник" << endl << endl; //(3)
					else cout << "Не прямоугольный треугольник" << endl << endl; //(4)
				}
				else cout << "Некорректно введённые данные" << endl << endl;
			}
			else cout << "Некорректно введённые данные" << endl << endl;
			break;
		}
		case '2':
		{
			done = true; break;
			return 0;
		}
		}
	}
}
