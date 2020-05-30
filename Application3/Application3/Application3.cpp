#include <iostream>
#include <iomanip>
using namespace std;
int SunDay(int ** arr, int years,int i) {
	int sumDay = 0;
	for (int j = 0; j < years; j++) {
		sumDay += arr[i][j];
	}
	return sumDay;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	const int cCount = 5; //Кол-во курортов
	const int years = 10; //Кол-во лет
	int range = 9000; //Растояние
	int dayInYear = 365; //Максимальное кол-во солнечных дней
	//int arr[cCount][years + 2];
	int** arr = new int*[cCount];
	for (int i = 0; i < cCount; i++)
		arr[i] = new int[years+2];	//years - для суммарного количества, years + 1 - расстояние

	//Заполнение массивов
	for (int i = 0; i < cCount; i++) {
		arr[i][years] = 0;
		for (int j = 0; j < years; j++) {
			arr[i][j] = rand() % dayInYear;
		}
		arr[i][years] = SunDay(arr, years, i);
		arr[i][years+1] = rand() % range;
	}
	//Вывод информации
	cout << "Информация о курортах" << endl;
	cout << setw(3) << "№ |";
	for (int i = 0; i < years; i++) {
		cout << setw(4) << i + 1;
	}
	cout << " | Всего солнечных дней | Расстояние" << endl;
	for (int i = 0; i < cCount; i++) {
		cout << setw(2) << i+1 << " ";
		for (int j = 0; j < years; j++) {
			cout << setw(4) << arr[i][j];
		}
		cout << setw(15) << arr[i][years] << setw(18) << arr[i][years+1];
		cout << endl;
	}
	int maxI = 0;
	//Поиск лучшего курорта
	for (int i = 1; i < cCount; i++) {
		if (arr[i][years] > arr[maxI][years]) {
			if (arr[i][years + 1] > arr[maxI][years + 1]) {
				continue;
			}
			maxI = i;
		}
	}
	cout << "Лучший курорт под номером " << maxI + 1 << endl;

	system("pause");
	return 0;
}
