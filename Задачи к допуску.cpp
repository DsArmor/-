#include <cmath>
#include<ctime>
#include <iostream>
#include <random>
#include <iomanip>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


void num1() {
	int a,f=2,c;
	cout << "Введите границу поиска: ";
	cin >> a;
	vector<int>check;
	for (int i = 0; i < a+1; i++) {
		check.push_back(i);
	}
	
	for (int i = 2; i < a+1; i++) {
		for (int j = i*f; j < a+1; j=f*i) {
			check[j] = 0;
			f++;
		}
		f = 2;
	}
	for (int i = 0; i < a; i++) {
		if (check[i] != 0)
			cout << check[i] << " ";
		/*cout << check[i];*/
	}
}


void num2() {
	int a, b,c;
	cout << "Введите два числа: ";
	cin >> a >> b;
	while (a % b!=0) {
		a = a % b;
		if (a < b) {
			c = a;
			a = b;
			b = c;
		}
	}
	cout << b;

}

int factorial(int a) {
	int k = 1;
	for (int i = 2; i < a+1; i++) {
		k *= i;
	}
	return k;
}


int balls(int step, bool* a) {
	int sum = 0;
	if (step <= 10) {
		for (int i = 0; i < 10; i++)
		{
			if (a[i]) continue;
			a[i] = true;
			if (i + 1 == step) {
				sum += factorial(10 - step);
			}
			else {
				sum += balls(step + 1, a);
			}
			a[i] = false;
		}
	}
	return sum;
}

int num4(){
	string check;
	cin >> check;
	srand(time(nullptr));
	char request[30] = {'a', 'b', 'c', 'd', 'e', 'k','l', ' ', 'r', 'f', 'g', 'h','i','j','k','m','n',' ',' ' };
	ofstream fout("cppstudio.txt"); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt
	for (int i = 0; i < 100; i++) {
		fout << request[rand()%9];
	}

	cout << "файл создан" << endl;;
	fout.close(); // закрываем файл
	string path = "cppstudio.txt", temp, finish;
	ifstream file;
	file.open(path);
	int k = 0, size_of_search;
	if (!file.is_open()) {
		cout << "Ошибка открытия файла\n";
	}
	else {
		cout << "Файл открыт\n";
		cout << endl;
		while (file >> temp) {
			cout << temp<< ' ';
			
			for (int i = 0; i < temp.size() - check.size()+1; i++) {
				if (temp[i] == check[0]) {
					for (int j = 0; j < check.size(); j++) {
						if (temp[i + j] == check[j])
							k++;
					}
					if (k == check.size()) {
						temp.erase(i, check.size());
						i -= check.size();
					}
						
					k = 0;
					
				}
			}
			finish+=temp+' ';
		}
		cout << endl;
		cout<< finish << endl;
		
		
	}
	return 0;

	
}


void rog()
{
	srand(time(nullptr));
	int i, k;
	int a[4];
	a[0] = -5;
	a[1] = -5;
	a[2] = -5;
	a[3] = -5;
	i = 0;
	int check = 0;

	while (i < 4) {
		k = rand() % 10;
		for (int j = 0; j < 4; j++) {
			if (k != a[j])
				check++;
			if (check == 4) {
				a[i] = k;
				i++;
			}
		}
		check = 0;
	}
	if (a[0] == 0) {
		k = rand() % 3 + 1;
		int f = a[0];
		a[0] = a[k];
		a[k] = f;
	}
	
	int temp=0, finish = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3],l=0;
	cout << "Введите число: ";
	while (temp!=finish && l<30){
		
		int rog = 0, cow = 0;
		cin >> temp;
		int b[4];
		b[0] = temp / 1000; 
		b[1] = temp / 100 % 10;
		b[2] = temp / 10 % 10; 
		b[3] = temp % 10; 
		for (int i = 0; i < 4; i++) {
			if (b[i] == a[i]) {
				rog++;
			}
		}
			
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (a[i] == b[j] && a[i]!=b[i]) {
					cow++;
					break;
				}
			}
		}
		if (temp != finish)
			cout << "Try again" << endl;
		cout << "Быки: " << rog << " Коровы: " << cow << endl;
		l++;
	}
	cout << "GG " << l;

}
int teachers[600], students[600][3];
//поиск учителей монаха
int search_teachers(int monk, int monk1=0) {
	for (int i = 0; i < 600; i++) {
		if (teachers[i]) {
			for (int j = 0; j < 3; j++) {
				if (students[teachers[i]][j] == monk) {
					if (teachers[i] != 1) {
						cout << teachers[i] << " ";
					}
					search_teachers(teachers[i]);
					return 1;
				}	
			}
		}
	}
}
//проверка на наличие монаха в списке
int verification(int monk) {
	for (int i = 0; i < 600; i++) {
		if (teachers[i]) {
			for (int j = 0; j < 3; j++) {
				if (students[teachers[i]][j] == monk) {
					return 1;
				}
					
			}
		}
	}
	return 0;
}

void monks() {
	int n;
	cout << "Введите количество монахов: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Монах: ";
		cin >> teachers[i];
		cout << " Его ученики: ";
		for (int j = 0; j < 3; j++) {
			cin >> students[teachers[i]][j];
		}
	}
	cout << "Введите количество запросов к базе данных: ";
	cin >> n;
	int number,temp, temp1;
	for (int i = 0; i < n; i++) {
		cout << "Количество монашеских номеров в запросе: ";
		cin >> number;
		if (number == 2) {
			cout << "Номера монахов: ";
			cin >> temp >> temp1;
			if (verification(temp)) {
				if (verification(temp)) {
					search_teachers(temp, temp1);
				}
				else
					cout << temp << " - не монах";
			}
			else
				cout << temp << " - не монах";
		}
			
		else {
			cout << "Номер монаха: ";
			cin >> temp;
			if (verification(temp)) {
				cout << temp << "-монах, его учителя: ";
				search_teachers(temp);
			}
			else
				cout << temp << " - не монах";
		}
			
		
	}
}

int main()
{
	int n;
	
	setlocale(LC_ALL, "");
	cout << "Решето Эратосфена - 1" << endl;
	cout << "Алгоритм Евклида - 2" << endl;
	cout << "Задача про шарики - 3" << endl;
	cout << "Обработка текстовых файлов - 4" << endl;
	cout << "Быки и коровы - 5" << endl;
	cout << "Монахи - 6" << endl;
	cout << "Введите номер задания: ";
	bool a[10] = { false };
	cin >> n;
	switch (n) {
	case(1):
		num1();
		break;
	case(2):
		num2();
		break;
	case(3):
		cout << balls(1, a);
		break;
	case(4):
		num4();
		break;
	case(5):
		rog();
		break;
	case(6):
		monks();
		break;
	}
}