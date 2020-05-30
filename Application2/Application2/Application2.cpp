#include <iostream>
#include <iomanip>
using namespace std;

//Стректура
struct studinfo {
	char surname[30], name[30];
	int * balls;
	float srball;
};
float srball(int * balls, int countEx) {
	int allballs = 0;
	int i = 0;
	while (i < countEx) {
		allballs += balls[i];
		i++;
	}
	float srballs = (float)allballs / countEx;
	return srballs;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int N;
	float studBall = 0;
	do {
		cout << "Введите количество студентов: ";
		cin >> N;
	} while (N <= 0);
	studinfo * student;
	student = new studinfo[N];
	//cout << fixed << setprecision(2);
	int countEx;
	do {
		cout << "Введите количество экзаменов (3-5): ";
		cin >> countEx;
	} while (countEx < 3 || countEx > 5);

	for (int i = 0; i < N; i++) {
		cout << "Введите информацио о " << i + 1 << " студенте: " << endl;
		cout << "Введите Фамилию: ";
		cin >> student[i].surname;
		cout << "Введите Имя: ";
		cin >> student[i].name;
		student[i].balls = new int [countEx];
		cout << "Введите Оценки по " << countEx << " экзаменам: " << endl;
		float allballs = 0;
		for (int j = 0; j < countEx; j++) {
			cin >> student[i].balls[j];
		}
		student[i].srball = srball(student[i].balls, countEx);
		studBall += student[i].srball;

	}
	studBall /= N;
	// Вывод информации в табличном виде
	cout << "Информация о студентах:" << endl;
	cout << setw(16) << "Фамилия" << setw(16) << "Имя:" << setw(16) << "Средний балл: " << setw(24) << "Оценки за экзамены:" << endl;
	for (int i = 0; i < N; i++) {
		cout << setw(16) << student[i].surname << setw(16) << student[i].name << setw(14) << student[i].srball << setw(6) << " ";
		for (int j = 0; j < countEx; j++) {
			cout << setw(2) << student[i].balls[j];
		}
		cout << endl;
	}

	/* Сортировка
	for (int i = 0; i < N - 1; i++)
		for (int j = i + 1; j < N; j++)
			if (student[i].srball < student[j].srball)
			{
				studinfo tmp = student[i];
				student[i] = student[j];
				student[j] = tmp;
			}
	*/
	bool one = 0;
	cout << endl << "Информация о студентах чей средний балл > среднего по группе ("<< studBall <<"):" << endl;
	
	for (int i = 0; i < N; i++) {
		if (student[i].srball > studBall) {
			one++;
			if (one == 1) {
				cout << setw(16) << "Фамилия" << setw(16) << "Имя:" << setw(16) << "Средний балл: " << setw(24) << "Оценки за экзамены:" << endl;
			}
			cout << setw(16) << student[i].surname << setw(16) << student[i].name << setw(14) << student[i].srball << setw(6) << " ";
			for (int j = 0; j < countEx; j++) {
				cout << setw(2) << student[i].balls[j];
			}
			cout << endl;
		}
	}
	if (one == 0) {
		cout << "Таких студентов нет" << endl;
	}
	system("pause");
	return 0;
}
