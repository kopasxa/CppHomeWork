//З використанням розробленого класу, написати програму демонстрації всіх операцій у вигляді діалогу з користувачем.

#pragma once

struct Tree {
	int data;
	Tree* left,
		* right,
		* parent;
};

class btree {
	Tree* root;

	void minHelp( Tree* node, int& minEl );
	void maxHelp( Tree* node, int& maxEl );
	Tree* newNode( int data );
public:
	btree();
	Tree* Insert( Tree* node, int data );
	void PrintSort( Tree* node );
	void Print( Tree* node, int level );
	int min( Tree* node );
	int max( Tree* node );
	
	void findByKey( Tree* node, int key );
	void printLeaf( Tree* node );
	Tree* GetRoot();
};

