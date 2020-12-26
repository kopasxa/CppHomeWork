// 	4. � ����� prog.cpp ����� :
// �) � ������� main ������� ��� ������� ����� �������������( ���������� ) ����� �� �����
// function.h( show() )
// �) ���������� ���������, ������� ��������� ����� ��� ������ ����� �������������� .
// �������� INTEGER - ����� ������, CHAR - ���������� DOUBLE - ���������. (# define
// 																		 INTEGER)

#include <iostream>
#define sizeArr 10

#define INTEGER
#include "function.h"
#include "function.cpp"


int main() {
	int arrI[sizeArr];
	setlocale( LC_ALL, "ru" );
	initInt( arrI, sizeArr );
	outputInt( arrI, sizeArr );
	editInt( arrI, sizeArr );
	outputInt( arrI, sizeArr );
	sortInt( arrI, sizeArr );
	outputInt( arrI, sizeArr );
	std::cout << "������������ �������� � �������: " << maxElInt( arrI, sizeArr ) << std::endl;
	std::cout << "����������� �������� � �������: " << minElInt( arrI, sizeArr ) << std::endl;
	
#undef INTEGER

#define DOUBLE
#include "function.h"

	double arrD[sizeArr];
	setlocale( LC_ALL, "ru" );
	initDouble( arrD, sizeArr );
	outputDouble( arrD, sizeArr );
	editDouble( arrD, sizeArr );
	outputDouble( arrD, sizeArr );
	sortDouble( arrD, sizeArr );
	outputDouble( arrD, sizeArr );
	std::cout << "������������ �������� � �������: " << maxElDouble( arrD, sizeArr ) << std::endl;
	std::cout << "����������� �������� � �������: " << minElDouble( arrD, sizeArr ) << std::endl;

#undef DOUBLE

#define CHAR
#include "function.h"

	char arrC[sizeArr];
	setlocale( LC_ALL, "ru" );
	initChar( arrC, sizeArr );
	outputChar( arrC, sizeArr );
	editChar( arrC, sizeArr );
	outputChar( arrC, sizeArr );
	sortChar( arrC, sizeArr );
	outputChar( arrC, sizeArr );
	std::cout << "������������ �������� � �������: " << maxElChar( arrC, sizeArr ) << std::endl;
	std::cout << "����������� �������� � �������: " << minElChar( arrC, sizeArr ) << std::endl;

#undef CHAR

}