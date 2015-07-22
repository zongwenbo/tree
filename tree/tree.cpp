#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
public:
	Node(string str, Node *l = 0, Node *r = 0) : name(str), left(l), right(r) {}
	string getName() {
		return name;
	}

	string name;
	Node *left;
	Node *right;
};

void visit(Node *node)
{
	cout << "  Visit " << node->name << endl;
}

void preorder_traverse(Node *root)
{
	vector<Node*> queue;
	queue.push_back(root);

	while (!queue.empty()) {
		Node *node = queue.back();
		queue.pop_back();
		
		visit(node);

		if (node->right)
			queue.push_back(node->right);

		if (node->left)
			queue.push_back(node->left);
	}
}

void inorder_traverse(Node *root)
{
	vector<Node*> queue;
	Node *node = root;

	while (!queue.empty() || node) {		 
		if (node) {
			queue.push_back(node);
			node = node->left;
		}
		else {
			node = queue.back();
			queue.pop_back();
			visit(node);
			node = node->right;
		}
	}
}

void postorder_traverse(Node *root)
{
	vector<Node*> queue;
	
	Node *node = root;
	Node *lastVisited = 0;

	while (!queue.empty() || node) {		
		if (node) {
			queue.push_back(node);
			node = node->left;
		}
		else {
			node = queue.back();
			if (node->right && node->right != lastVisited) {
				node = node->right;
			}
			else {
				visit(node);
				queue.pop_back();
				lastVisited = node;
				node = 0;
			}
		}

	}
	
}

int main()
{
	Node Bill("Bill");
	Node Bob("Bob");
	Node Tom("Tom");
	Node Harry("Harry");
	Node Dylan("Dylan");
	Node Ray("Ray");
	Node Mary("Mary");
	Node Jim("Jim");
	Node Tim("Tim");
	
	Bill.left = &Harry;
	Bill.right = &Dylan;

	Harry.left = &Tom;
	Harry.right = &Ray;

	Dylan.left = &Bob;
	Dylan.right = &Mary;

	Ray.left = &Jim;
	Ray.right = &Tim;

	cout << "========= Pre-order Traversal =========" << endl;
	preorder_traverse(&Bill);
	cout << "========= In-order Traversal =========" << endl;
	inorder_traverse(&Bill);
	cout << "========= Post-order Traversal =========" << endl;
	postorder_traverse(&Bill);
	for (;;);
}