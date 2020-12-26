// 	4. в файле prog.cpp нужно :
// а) в функции main вызвать все функции через переозначеные( обобщенные ) имена из файла
// function.h( show() )
// б) определить константу, которая указывает какой тип данных будет использоваться .
// Например INTEGER - целые данные, CHAR - символьные DOUBLE - настоящие. (# define
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
	std::cout << "Максимальное значение в массиве: " << maxElInt( arrI, sizeArr ) << std::endl;
	std::cout << "Минимальное значение в массиве: " << minElInt( arrI, sizeArr ) << std::endl;
	
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
	std::cout << "Максимальное значение в массиве: " << maxElDouble( arrD, sizeArr ) << std::endl;
	std::cout << "Минимальное значение в массиве: " << minElDouble( arrD, sizeArr ) << std::endl;

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
	std::cout << "Максимальное значение в массиве: " << maxElChar( arrC, sizeArr ) << std::endl;
	std::cout << "Минимальное значение в массиве: " << minElChar( arrC, sizeArr ) << std::endl;

#undef CHAR

}