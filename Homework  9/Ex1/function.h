// 3. в файле function.h нужно :
// а) описать прототипы всех функций;
// б) сделать проверку определена ли константа, указывающая на тип данных( #ifdef INTEGER )
// в ) создать обобщающие имена функции, которым будет определена функция
// соответствующего типа в зависимости от константы, указанной в файле prog.cpp . (# define
// 																				 show ShowInt)
// 	Имя функциям нужно давать так, чтобы они отвечали своей сути.Например функция для
// 	вывода значений массива целых чисел на консоль - ShowArrayInt().А, когда переопределяем
// 	функцию с помощью # define то нужно давать общее имя.Например # define ShowArray
// 	ShowArrayInt

#ifndef INTEGER 

// **** INTEGER ****

void initInt( int arr[], int size ),
editInt( int arr[], int size ),
sortInt( int arr[], int size ),
outputInt( int arr[], int size );

int maxElInt( int arr[], int size ),
minElInt( int arr[], int size );

#define init initInt
#define edit editInt
#define sort sortInt
#define maxEl maxElInt
#define minEl minElInt
#define output outputInt

#elif DOUBLE

// **** DOUBLE ****

void initDouble( double arr[], int size ),
editDouble( double arr[], int size ),
sortDouble( double arr[], int size ),
outputDouble( double arr[], int size );

double maxElDouble( double arr[], int size ),
minElDouble( double arr[], int size );

#define init initDouble;
#define edit editDouble;
#define sort sortDouble;
#define maxEl maxElDouble;
#define minEl minElDouble;
#define output outputDouble;

#else CHAR 

// **** CHAR ****

void initChar( char arr[], int size ),
editChar( char arr[], int size ),
sortChar( char arr[], int size ),
outputChar( char arr[], int size );

char maxElChar( char arr[], int size ),
minElChar( char arr[], int size );

#define init initChar;
#define edit editChar;
#define sort sortChar;
#define maxEl maxElChar;
#define minEl minElChar;
#define output outputChar;

#endif
