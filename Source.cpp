#include <iostream>
#include <math.h>
#include <vector>

#include "BinarySearchTree.h"
//#include "AvlTree.h"
#include "BallsInBins.h"

using namespace std;

int main()
{
	
	BinarySearchTree b1;
	b1.insert(7);
	b1.insert(9);
	b1.insert(1);
	b1.insert(10);
	b1.insert(0);
	b1.insert(8);
	b1.insert(3);
	b1.insert(5);
	b1.insert(2);
	b1.insert(6);
	b1.insert(4);

	cout << endl;
	cout << " Binary Search Tree: " << endl;
	cout << "------------------------------" << endl;
	cout << endl;
	cout << " Number of leaves: " << b1.pubLeafCount() << "\n";
	cout << " Number of nodes: " << b1.pubNodeCount() << "\n";
	cout << " Number of full nodes: " << b1.pubFullNodeCount() << "\n";
	cout << " Internal Path Length: " << b1.pubInternalPathLength() << "\n";
	cout << endl;

	b1.printTree();

	cout << "Level Traversal Order = Breath First: "<< endl;
	b1.pubTraverseTreeLevel();
	cout << endl;
	
	BallsInBins b;

	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "			Calculating ballsInBins with 10,007 balls & bins. " << "\n";
	cout << "			Please be patient. " << endl;
	cout << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << endl;
	b.ballsInBins();
	cout << endl;

	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "			Calculating ballsInBins with 32,768 balls & bins. " << "\n";
	cout << "			Please be patient. " << endl;

	cout << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << endl;
	b.ballsInBinsMore();
	cout << endl;

	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "			Calculating ballsInBins with 10,007 balls & bins and two choices. " << "\n";
	cout << "			Please be patient. " << endl;

	cout << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << endl;

	b.powerOfTwoChoices();
	cout << endl;

	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "			Calculating ballsInBins with 32,768 balls & bins and two choices. " << "\n";
	cout << "			Please be patient. " << endl;

	cout << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << endl;
	b.powerOfTwoChoicesmore();

	int a;
	cin >> a;
}

