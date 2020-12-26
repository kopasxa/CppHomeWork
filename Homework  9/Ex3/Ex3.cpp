#include <iostream>

using namespace std;

struct bits {
	unsigned Monitor: 1;
	unsigned Video: 1;
	unsigned Processor: 1;
};

void print( bits comp );

int main() {
   setlocale(LC_ALL, "ru");

   bits comp;

   int Monitor;
   cout << "Выберите монитор (1 - 60 ггц, 0 - 144 ггц): ";
   cin >> Monitor;
   comp.Monitor = Monitor;

   int Processor;
   cout << "Выберите процессор (1 - AMD, 0 - INTEL): ";
   cin >> Processor;
   comp.Processor = Processor;

   int Video;
   cout << "Выберите графику (1 - Интегрированая, 0 - Не интегрированая): ";
   cin >> Video;
   comp.Video = Video;

   print(comp);
}

void print(bits comp) {
	cout << "Конфигурация компа: " << endl;
	cout << "Монитор: ";
	if (comp.Monitor == 1)
		cout << "60 Ггц";
	else 
		cout << "144 Ггц";
	cout << endl;
	cout << "Графика: ";
	if (comp.Monitor == 1)
		cout << "Интегрированая";
	else
		cout << "Не интегрированая";
	cout << endl;
	cout << "Процессор: ";
	if (comp.Monitor == 1)
		cout << "AMD";
	else
		cout << "INTEL";
	cout << endl;
}
