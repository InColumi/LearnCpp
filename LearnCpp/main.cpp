#include <iostream>
#include <time.h>

using namespace std;

class BinaryTree
{
	private:
	struct Node
	{
		public:
		Node* Right;
		Node* Left;
		int value;

		Node():Left(NULL), Right(NULL), value() {}
		Node(int newValue):Left(NULL), Right(NULL), value(newValue) {}

		friend ostream& operator <<(ostream& out, const Node& node)
		{
			out << node.value;
			return out;
		}
	};

	Node* _root;
	long _countNodes;
	public:
	BinaryTree(): _root(NULL), _countNodes(0) {}

	void Add(int value)
	{
		_root = AddNode(value, _root);
		++_countNodes;
	}

	void Show()
	{
		ShowNode(_root);
	}

	bool Contains(int value)
	{
		return (_root == NULL) ? false : IsContains(value, _root);
	}

	private:

	bool IsContains(int value, Node*& node)
	{
		if(node)
		{
			return (value >= node->value) ? IsContains(value, node->Right) : IsContains(value, node->Left);
		}
		return false;
	}

	Node* AddNode(int value, Node* node)
	{
		if(node == NULL)
		{
			node  = new Node(value);
		}
		else
		{
			if(value >= node->value)
			{
				node->Right = AddNode(value, node->Right);
			}
			else
			{
				node->Left = AddNode(value, node->Left);
			}
		}
		return node;
	}

	void ShowNode(Node* node, size_t whitespace = 0)
	{
		if(node)
		{
			ShowNode(node->Left, ++whitespace);
			for(size_t i = 0; i < whitespace; i++)
			{
				cout << "\t";
			}
			cout << *node << '\n';
			ShowNode(node->Right, ++whitespace);
		}
	}
};



int main(int argc, char* argv[])
{
	BinaryTree tree;
	srand(time(0));

	unsigned int start_time = clock(); // начальное время
	for(int i = 0; i < 9999999; i++)
	{
		tree.Add(1 + rand() % 999999);
	}
	unsigned int end_time = clock(); // конечное время
	cout << "Create tree: " << (end_time - start_time) / 1000.0 << endl;;


	start_time = clock();
	tree.Contains(999998);
	end_time = clock(); // конечное время
	cout << "Search: " << (end_time - start_time) / 1000.0 << endl;;
	return 0;
}