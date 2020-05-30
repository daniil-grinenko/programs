// Application1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	int rows, columns, maxN = 100;
	do {
		cout << "Введите кол-во рядов: ";
		cin >> rows;
	} while (rows < 1);
	do {
		cout << "Введите кол-во столбцов: ";
		cin >> columns;
	} while (columns < 1);
	int** arr = new int*[rows];
	for (int i = 0; i < rows; i++)
		arr[i] = new int[columns];
	int * max;
	max = new int[rows];
	// Заполнение и вывод массива
	for (int i = 0; i < rows; i++) {
		max[i] = 0;
		for (int j = 0; j < columns; j++) {
			arr[i][j] = rand() % maxN;
			cout << setw(3) << arr[i][j];
			//Зполнение массива максимальных в строке
			if (arr[i][j] > max[i])
				max[i] = arr[i][j];
		}
		cout << endl;
	}
	//Вывод массива максимальных
	int sum = 0;
	cout << "Максимальные значения:" << endl;
	for (int i = 0; i < rows; i++) {
		cout << i + 1 << ") " << max[i] << " ";
		sum += max[i];
	}
	cout << endl << "Сумма максимальных значений: " << sum << endl;
	system("pause");
	return 0;
}
