// ApplicationDop.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	
	// Ввод m
	int m, maxM = 100;
	do {
		cout << "Введите M: ";
		cin >> m;
	} while (m < 1);
	// Обьявление массивов
	int** A = new int*[m];
	for (int i = 0; i < m; i++)
		A[i] = new int[m];
	int * X;
	X = new int[m];
	// Заполнение и вывод массивов
	cout << "Матрица A:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			A[i][j] = rand() % maxM;
			cout << setw(3) << A[i][j];
		}
		cout << endl;
	}
	cout << "Массив X:" << endl;
	for (int i = 0; i < m; i++) {
		X[i] = rand() % maxM;
		cout << setw(3) << X[i];
	}
	cout << endl;
	system("pause");
	// Замена нечетных строк
	for (int i = 0; i < m; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < m; j++) {
				A[i][j] = X[j];
			}
		}
	}
	// Вывод результата
	cout << "Матрица A после замены строк:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(3) << A[i][j];
		}
		cout << endl;
	}
	system("pause");

	// Замена четных столбцов
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (j % 2 == 1) {
				A[i][j] = X[i];
			}
		}
	}
	// Вывод результата
	cout << "Матрица A после замены столбцов:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(3) << A[i][j];
		}
		cout << endl;
	}
	system("pause");

	// Очистка памяти
	for (int i = 0; i < m; i++)
		delete[] A[i];
	delete[] A;
	delete[] X;

	
	// -------------------------------------------------
	//Вторая часть

	int n, maxN = 200;
	do {
		cout << "Введите N: ";
		cin >> n;
	} while (n < 1);

	// Обьявление массивов
	int** arr = new int*[n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[n];
	// Заполнение и вывод массивов
	cout << "Матрица:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = rand() % maxN - 100;
			cout << setw(4) << arr[i][j];
		}
		cout << endl;
	}
	// Сортировка и вывод матрицы
	for (int k = 0; k < n; k++) {
		if (arr[k][0] < 0) {
			for (int i = 0; i < n-1; i++) {
				for (int j = n - 1; j > i; j--) {
					if (arr[k][j] > arr[k][j-1]) {
						int tmp = arr[k][j];
						arr[k][j] = arr[k][j-1];
						arr[k][j-1] = tmp;
					}
				}
			}
		}
	}
	cout << "Измененая матрица:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(4) << arr[i][j];
		}
		cout << endl;
	}

	// Очистка памяти
	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;

	system("pause");
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
