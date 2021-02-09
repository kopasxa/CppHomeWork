#include "btree.h"
#include <iostream> 

using namespace std;

btree::btree() {
	root = nullptr;
}

Tree* btree::newNode( int data ) {
	Tree* node = new Tree;
	node->data = data;
	node->left = nullptr;
	node->right = nullptr;
	node->parent = nullptr;

	return node;
}

Tree* btree::Insert( Tree* node, int data ) {
	static Tree* p;
	Tree* retNode;

	
	if (node == NULL) {
		retNode = newNode( data );
		retNode->parent = p;
		if (root == nullptr) {
			root = retNode;
		}
		return retNode;
	}
	if (data <= node->data) {
		p = node;
		node->left = Insert( node->left, data );
	}
	else {
		p = node;
		node->right = Insert( node->right, data );
	}

	return node;
}

void btree::PrintSort( Tree* node ) {
	if (node != nullptr) {
		PrintSort( node->left );
		cout << node->data << " ";
		PrintSort( node->right );
	}
}

void btree::Print( Tree* node, int level ) {
	if (node != nullptr) {
		Print( node->left, level + 1 );
		for (int i = 0; i < level; i++) cout << "   ";
		cout << node->data<< endl;
		Print( node->right, level + 1 );
	}
}

void btree::minHelp( Tree* node, int& minEl ) {
	if (node->left != nullptr && minEl > node->left->data) {
		minEl = node->left->data;
		minHelp( node->left, minEl );
	}
}

int btree::min( Tree* node ) {
	int minEl = node->data;
	minHelp( node, minEl );
	return minEl;
}

void btree::maxHelp( Tree* node, int& maxEl ) {
	if (node->right != nullptr && maxEl < node->right->data) {
		maxEl = node->right->data;
		maxHelp( node->right, maxEl );
	}
}

int btree::max( Tree* node ) {
	int maxEl = node->data;
	maxHelp( node, maxEl );
	return maxEl;
}

void btree::findByKey( Tree* node, int key ) {
	if (node != nullptr) {
		if (node->data == key) {
			cout << node->data;
			return;
		}
		findByKey( node->left, key );
		findByKey( node->right, key );
	}
}

void btree::printLeaf( Tree* node ) {
	if (node != nullptr) {
		printLeaf( node->left );
		if (!node->left && !node->right)
			cout << node->data << " ";
		printLeaf( node->right );
	}
}

Tree* btree::GetRoot() {
	return root;
}
