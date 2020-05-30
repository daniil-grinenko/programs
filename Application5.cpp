#include <iostream>

using namespace std;

class ComplNumb {
private:
	float whole, imagin;
public:
	//float whole, imagin;
	ComplNumb(float wh = 1, float im = 1)
	{
		whole = wh;
		imagin = im;
	}
	void set();
	void print();

	ComplNumb Add(ComplNumb &, ComplNumb &);
	ComplNumb Sub(ComplNumb &, ComplNumb &);
	ComplNumb Multi(ComplNumb &, ComplNumb &);
};
void ComplNumb::set() {
	cout << "Введите целую часть: ";
	cin >> whole;
	cout << "Введите мнимую часть: ";
	cin >> imagin;
};
void ComplNumb::print() {
	if (whole == 0)
		cout << "";
	else
		cout << whole;
	if (imagin > 0)
		cout << "+" << imagin << "i" << endl;
	else if (imagin == 0)
		cout << "";
	else
		cout << imagin << "i" << endl;
	if (whole == 0 && imagin == 0)
		cout << "0" << endl;
};
ComplNumb ComplNumb::Add(ComplNumb & first, ComplNumb & second) {
	ComplNumb res;
	res.whole = first.whole + second.whole;
	res.imagin = first.imagin + second.imagin;
	return res;
};
ComplNumb ComplNumb::Sub(ComplNumb & first, ComplNumb & second) {
	ComplNumb res;
	res.whole = first.whole - second.whole;
	res.imagin = first.imagin - second.imagin;
	return res;
};
ComplNumb ComplNumb::Multi(ComplNumb & first, ComplNumb & second) {
	ComplNumb res;
	res.whole = first.whole * second.whole - first.imagin * second.imagin;
	res.imagin = first.imagin * second.whole + first.whole * second.imagin;
	return res;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	ComplNumb num1, num2, Add, Sub, Multi;
	num1.set();
	num1.print();
	num2.set();
	num2.print();
	cout << "Результат сложения: ";
	Add = Add.Add(num1, num2);
	Add.print();
	cout << "Результат вычитания: ";
	Sub = Sub.Sub(num1, num2);
	Sub.print();
	cout << "Результат умножения: ";
	Multi = Multi.Multi(num1, num2);
	Multi.print();

	system("pause");
	return 0;
}
