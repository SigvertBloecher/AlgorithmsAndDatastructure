#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <iostream>
#include <algorithm>
#include <queue> 
#include <vector>
using namespace std;

class BinaryNode
{
public:
	int element;
	BinaryNode *left;
	BinaryNode *right;

	BinaryNode(const int & theElement, BinaryNode *lt, BinaryNode *rt)
		: element{ theElement }, left{ lt }, right{ rt } { }

	BinaryNode(int && theElement, BinaryNode *lt, BinaryNode *rt)
		: element{ std::move(theElement) }, left{ lt }, right{ rt } { }
};


class BinarySearchTree
{
public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree & rhs);
	BinarySearchTree(BinarySearchTree && rhs);
	~BinarySearchTree();

	const int & findMin() const;
	const int & findMax() const;
	bool contains(const int & x) const;
	bool isEmpty() const;
	void printTree() const;
	void pubTraverseTreeLevel();
	void makeEmpty();
	void insert(const int & x);
	void insert(int && x);
	void remove(const int & x);
	int pubFullNodeCount();
	int pubLeafCount();
	int pubNodeCount();
	int pubInternalPathLength();


protected:
	BinaryNode *root;
	int internalPathLength(BinaryNode *t, int hight);
	void TraverseTreeLevel(BinaryNode *t);
	void insert(const int & x, BinaryNode * & t);
	void insert(int && x, BinaryNode * & t);
	void remove(const int & x, BinaryNode * & t);
	BinaryNode * findMin(BinaryNode *t) const;
	BinaryNode * findMax(BinaryNode *t) const;
	int LeafCount(BinaryNode *t);
	int NodeCount(BinaryNode *t);
	int FullNodeCount(BinaryNode *t);
	bool contains(const int & x, BinaryNode *t) const;
	void makeEmpty(BinaryNode * & t);
	void printTree(BinaryNode *t) const;
	void printTreeIn(BinaryNode *t) const;
	void printTreePre(BinaryNode * t) const;
	void printTreePost(BinaryNode * t) const;
	BinaryNode * clone(BinaryNode *t) const;
	vector<BinaryNode *> q;
	int Index;

};

#endif
