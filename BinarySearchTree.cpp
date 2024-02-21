#include "BinarySearchTree.h"
// t = root and element is just data. When inserting with function insert, you insert a node. 

BinarySearchTree::BinarySearchTree() : root{ nullptr }
{
}


BinarySearchTree::BinarySearchTree(const BinarySearchTree & rhs) : root{ nullptr }
{
	root = clone(rhs.root);
}


BinarySearchTree::BinarySearchTree(BinarySearchTree && rhs) : root{ rhs.root }
{
	rhs.root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
	makeEmpty();
}

const int & BinarySearchTree::findMin() const
{
	if (isEmpty())
		return -1;
	return findMin(root)->element;
}


const int & BinarySearchTree::findMax() const
{
	if (isEmpty())
		return -1;
	return findMax(root)->element;
}

bool BinarySearchTree::contains(const int & x) const
{
	return contains(x, root);
}

bool BinarySearchTree::isEmpty() const
{
	return root == nullptr;
}

void BinarySearchTree::printTree() const
{
	if (isEmpty())
		cout << "Empty tree" << endl;
	else

		cout << "Pre-order: " << endl;
	printTreePre(root);
	cout << endl;

	cout << "In-order: " << endl;
	printTreeIn(root);
	cout << endl;

	cout << "Post-order: " << endl;
	printTreePost(root);
	cout << endl;
}

void BinarySearchTree::pubTraverseTreeLevel()
{
	q.push_back(root);
	Index = 0;
	TraverseTreeLevel(q[Index]);
	q.clear();
	q.resize(0);

}

void BinarySearchTree::TraverseTreeLevel(BinaryNode *t)
{
	cout << t->element << endl;
	if (t->left != nullptr)
	{
		q.push_back(t->left);
	}
	if (t->right != nullptr)
	{
		q.push_back(t->right);
	}
	if (Index != q.size() - 1)
	{
		Index = Index + 1;
		TraverseTreeLevel(q[Index]);
	}
}

void BinarySearchTree::makeEmpty()
{
	makeEmpty(root);
}


void BinarySearchTree::insert(const int & x)
{
	insert(x, root);
}

void BinarySearchTree::insert(int && x)
{
	insert(std::move(x), root);
}

void BinarySearchTree::remove(const int & x)
{
	remove(x, root);
}


void BinarySearchTree::insert(const int & x, BinaryNode * & t)
{
	if (t == nullptr)
		t = new BinaryNode{ x, nullptr, nullptr };
	else if (x < t->element)
		insert(x, t->left);
	else if (t->element < x)
		insert(x, t->right);
	else
		;  // Duplicate; do nothing
}


void BinarySearchTree::insert(int && x, BinaryNode * & t)
{
	if (t == nullptr)
		t = new BinaryNode{ std::move(x), nullptr, nullptr };
	else if (x < t->element)
		insert(std::move(x), t->left);
	else if (t->element < x)
		insert(std::move(x), t->right);
	else
		;  // Duplicate; do nothing
}

void BinarySearchTree::remove(const int & x, BinaryNode * & t)
{
	if (t == nullptr)
		return;   // Item not found; do nothing
	if (x < t->element)
		remove(x, t->left);
	else if (t->element < x)
		remove(x, t->right);
	else if (t->left != nullptr && t->right != nullptr) // Two children
	{
		t->element = findMin(t->right)->element;
		remove(t->element, t->right);
	}
	else
	{
		BinaryNode *oldNode = t;
		t = (t->left != nullptr) ? t->left : t->right;
		delete oldNode;
	}
}

BinaryNode * BinarySearchTree::findMin(BinaryNode *t) const
{
	if (t == nullptr)
		return nullptr;
	if (t->left == nullptr)
		return t;
	return findMin(t->left);
}

BinaryNode * BinarySearchTree::findMax(BinaryNode *t) const
{
	if (t != nullptr)
		while (t->right != nullptr)
			t = t->right;
	return t;
}

bool BinarySearchTree::contains(const int & x, BinaryNode *t) const
{
	if (t == nullptr)
		return false;
	else if (x < t->element)
		return contains(x, t->left);
	else if (t->element < x)
		return contains(x, t->right);
	else
		return true;    // Match
}

void BinarySearchTree::makeEmpty(BinaryNode * & t)
{
	if (t != nullptr)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = nullptr;
}





void BinarySearchTree::printTree(BinaryNode *t) const
{
	if (t != nullptr)
	{
		printTree(t->left);
		cout << t->element << endl;
		printTree(t->right);
	}
}

void BinarySearchTree::printTreeIn(BinaryNode *t) const //in-order
{
	if (t != nullptr)
	{
		printTreeIn(t->left);
		cout << t->element << endl;
		printTreeIn(t->right);
	}
}

void BinarySearchTree::printTreePre(BinaryNode *t) const //pre-order
{
	if (t != nullptr)
	{

		cout << t->element << endl;
		printTreePre(t->left);
		printTreePre(t->right);
	}
}

void BinarySearchTree::printTreePost(BinaryNode *t) const //post-order
{
	if (t != nullptr)
	{
		printTreePost(t->left);
		printTreePost(t->right);
		cout << t->element << endl;

	}
}

int BinarySearchTree::pubLeafCount()
{
	return LeafCount(root);
}

int BinarySearchTree::LeafCount(BinaryNode *t)
{
	if (t != nullptr)
	{
		if (t->left == nullptr && t->right == nullptr)
		{
			return 1;
		}
		else
		{
			return LeafCount(t->left) + LeafCount(t->right);
		}
	}
	return 0;
}

int BinarySearchTree::pubNodeCount()
{
	return NodeCount(root);
}

int BinarySearchTree::NodeCount(BinaryNode *t)
{
	if (t == nullptr)
		return NULL;
	else
	{
		int count = 1;
		count += NodeCount(t->left);
		count += NodeCount(t->right);
		return count;
	}
}

int BinarySearchTree::pubFullNodeCount()
{
	return FullNodeCount(root);
}

int BinarySearchTree::FullNodeCount(BinaryNode *t)
{
	if (t == nullptr)
		return NULL;
	if (t->left == NULL && t->right == NULL)
		return NULL;
	if (t->left != NULL && t->right != NULL)
	{
		return 1 + FullNodeCount(t->left) + FullNodeCount(t->right);
	}
	if (t->left == NULL && t->right != NULL)
	{
		return FullNodeCount(t->right);
	}
	if (t->left != NULL && t->right == NULL)
	{
		return FullNodeCount(t->left);
	}
}

int BinarySearchTree::pubInternalPathLength()
{
	return internalPathLength(root, 0);
}

int BinarySearchTree::internalPathLength(BinaryNode *t, int height)
{
	if (t == nullptr)
		return 0;
	else
	{
		return height + internalPathLength(t->left, height + 1) + internalPathLength(t->right, height + 1);
	}
	return 0;
}

BinaryNode * BinarySearchTree::clone(BinaryNode *t) const
{
	if (t == nullptr)
		return nullptr;
	else
		return new BinaryNode{ t->element, clone(t->left), clone(t->right) };
}