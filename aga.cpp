#include <iostream>
using namespace std;

void pole(char** field, int size);
	
void p_pole(char** field, int size);

bool pobeda(char** field, int size, char sign);
void pl_turn(char** field, int size);

bool nicha(char** field, int size);

int main() {
	setlocale(LC_ALL, "rus");
	int size = 3;
	char** field = new char* [size];
	for (int i = 0; i < size; i++) {
		field[i] = new char[size];
	}
	pole(field, size);
	//p_pole(field,size);
	while (true) {
		pl_turn(field, size);
		p_pole(field, size);
		if (pobeda(field, size, 'x')) {
			cout << "победа крестиков\n";
			break;
		}
		if (pobeda(field, size, 'o')) {
			cout << "победа ноликов\n";
			break;
		}
		if (nicha(field, size)) {
			cout << "ничья\n";
			break;
		}
	}
	
}
//=======ФУНКЦИИИИИИИИИИИИИИИИИИИИИИИИИ========
void pole(char** field, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			field[i][j] = ' ';
		}
	}
}

void p_pole(char** field, int size) {
	for (int i = 0; i < size; i++) {
		cout << "|---|---|---|" << endl;
		for (int j = 0; j < size; j++) {
			cout << "| " << field[i][j] << ' ';
		}
		cout << '|' << endl;
	}
	cout << "|---|---|---|" << endl;
}

void pl_turn(char** field, int size) {
	int row, col;
	char sign;
	do {
		do{
			cout << "Введите номер сроки ";
			cin >> row;
		} while (row<0 || row > size - 1);
		do{
			cout << "Введите номер столбца ";
			cin >> col;
		} while (col<0 || col > size - 1);
	} while (field[row][col] != ' ');
	do {
	cout << "Введите значек ";
	cin >> sign;
	} while (sign != 'x' && sign != 'o' || sign != 'х' && sign != 'о');
	field[row][col] = sign;

}

bool pobeda(char** field, int size, char sign) {
	if (field[0][0] == sign && field[0][1] == sign && field[0][2] == sign) {
		return true;
	}
	if (field[1][0] == sign && field[1][1] == sign && field[1][2] == sign) {
		return true;
	}
	if (field[2][0] == sign && field[2][1] == sign && field[2][2] == sign) {
		return true;
	}
	
	//stolbi krestiki
	if (field[0][2] == sign && field[1][2] == sign && field[2][2] == sign) {
		return true;
	}
	if (field[0][1] == sign && field[1][1] == sign && field[2][1] == sign) {
		return true;
	}
	if (field[0][0] == sign && field[0][1] == sign && field[0][2] == sign) {
		return true;
	}
	// poperek
	if (field[0][0] == sign && field[1][1] == sign && field[2][2] == sign) {
		return true;
	}
	if (field[0][2] == sign && field[1][1] == sign && field[2][0] == sign) {
		return true;
	}
	return false;
}

bool nicha(char** field, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (field[i][j] = ' ') return false;
		}
	}
	return true;
}
