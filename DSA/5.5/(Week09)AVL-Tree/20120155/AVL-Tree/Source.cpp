#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct Node {
	int key=0;
	int height=0;
	Node* left=NULL;
	Node* right=NULL;
};

Node* CreateNode(int data) 
{
	
	Node* p = new Node;
	if (p == NULL)
	{
		cout << "NOT ENOUGH MEMORY";
	}
	p->key = data;
	p->left = p->right = NULL;
	p->height = 1;
	return p;
}
int GetHeight(Node* node) 
{
	if (node == NULL) {
		return 0;
	}
	else return node->height;
}
Node* RotateRight(Node* y) 
{
	Node* x = y->left;
	Node* t2 = x->right;
	x->right = y;
	y->left = t2;
	y->height = max(GetHeight(y->left), GetHeight(y->right)) + 1;
	x->height = max(GetHeight(x->left), GetHeight(x->right)) + 1;
	return x;
}
Node* RotateLeft(Node* x) 
{
	Node* y = x->right;
	Node* t2 = y->left;
	y->left = x;
	x->right = t2;
	x->height = max(GetHeight(x->left), GetHeight(x->right)) + 1;
	y->height = max(GetHeight(y->left), GetHeight(y->right)) + 1;
	return y;
}

int getBalance(Node* node) 
{	
	if (node == NULL)
		return 0;
	return GetHeight(node->left) - GetHeight(node->right);
}
Node* Insert(Node* root, int data) 
{
	if (root==NULL) 
	{
		return CreateNode(data);
	}
	else 
	{
		if (data < root->key) 
		{
			root->left = Insert(root->left, data);
		}
		else if (data > root->key) 
		{
			root->right = Insert(root->right, data);
		}
		else 
		{
			cout << "Co gia tri trung" << endl;
			return NULL;
		}
	}
	root->height = max(GetHeight(root->left), GetHeight(root->right)) + 1;
	int balance = getBalance(root);
	if (balance > 1) 
	{	
		
		if (getBalance(root->left) < 0) 
		{
			root->left = RotateLeft(root->left);
		}
		root = RotateRight(root);

	}
	else if (balance < -1) 
	{
		if (getBalance(root->right) > 0) 
		{
			root->right = RotateRight(root);
		}
		root = RotateLeft(root);
	}
	return root;
}
bool isAVL(Node* root) 
{
	if (!root) 
	{
		return true;
	}
	int balance = getBalance(root);
	if (balance > 1 || balance < -1) 
		return false;
	else 
		return isAVL(root->left) && isAVL(root->right);
}
void LNR(Node* root) 
{
	if (root==NULL) return;
	LNR(root->left);
	cout << root->key << "-" << GetHeight(root) << " ";
	LNR(root->right);
	return;
}
void NLR(Node* root) 
{
	if (!root) return;
	cout << root->key << "-" << GetHeight(root) << " ";
	LNR(root->left);
	LNR(root->right);
	return;
}
void LRN(Node* root) 
{
	if (!root) return;
	LNR(root->left);
	LNR(root->right);
	cout << root->key << "-" << GetHeight(root) << " ";
	return;
}
void levelOrder(Node* root) 

{
	queue<Node*>queue;
	if (root!=NULL) 
	{
		queue.push(root);
	}
	while (queue.size() > 0)
	{
		int size = queue.size();
		for (int i = 0; i < size; i++)
		{
			Node* temp = queue.front();
			queue.pop();
			cout << temp->key << "-" << GetHeight(temp) << " ";
			if (temp->left!=NULL) 
			{
				queue.push(temp->left);
			}
			if (temp->right!=NULL) 
			{
				queue.push(temp->right);
			}
		}
	}
}
int countLeaves(Node* root) 
{
	if (!root) 
	{
		return 0;
	}
	else 
	{
		return  countLeaves(root->left) + countLeaves(root->right) + 1 ;
	}
}
int countLesser(Node* root, int x) {
	if (!root) 
	{
		return 0;
	}
	else 
	{
		if (root->key < x) 
			return  countLesser(root->left, x) + countLesser(root->right, x) + 1;
		else if (root->key == x) 
			return countLeaves(root->left);
		else 
			return countLesser(root->left, x);
	}
}
Node* minNode(Node* node)
{
	Node* current = node;
	while (current->left != NULL) 
	{
		current = current->left;
	}
	return current;
}
Node* deleteNode(Node* root, int x) 
{
	
	if (root == NULL)
	{	
		
		return root;
	}
	else if (root->key < x) 
	{
		root->right = deleteNode(root->right, x);
	}
	else if (root->key > x) 
	{
		root->left = deleteNode(root->left, x);
	}
	else 
	{
		if (root->left && root->right) 
		{
			Node* temp = minNode(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right, temp->key);
		}
		else if (root->right) 
		{
			Node* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->left) 
		{
			Node* temp = root->left;
			delete root;
			return temp;
		}
		else 
		{
			delete root;
			return NULL;
		}
	}
	root->height = max(GetHeight(root->left), GetHeight(root->right)) + 1;
	int balance = getBalance(root);
	if (balance > 1)
	{
		if (getBalance(root->left) < 0) 
		{
			root->left = RotateLeft(root->left);
		}
		root = RotateRight(root);

	}
	else if (balance < -1) 
	{
		if (getBalance(root->right) > 0) 
		{
			root->right = RotateRight(root);
		}
		root = RotateLeft(root);
	}
	return root;
}
Node* search(Node* root, int x) {
	
	if (root != NULL)
	{
		if (root->key == x)
		{
			return root;
		}
		if (root->key > x)
		{
			return search(root->left, x);
		}
		else
		{
			return search(root->right, x);
		}
	}
	return NULL;
}



int countGreater(Node* root, int x) {
	if (!root) {
		return 0;
	}
	else 
	{
		if (root->key > x)
		{
			return 1 + countGreater(root->left, x) + countGreater(root->right, x);
		}
		else if (root->key == x)
		{
			return countLeaves(root->right);
		}
		else
		{
			return  countGreater(root->right, x);
		}
	}
}
void remove_rightTree(Node*& root, Node*& righttree)
{
	if (root->left != NULL)
	{
		remove_rightTree(righttree, root->left);
	}
	else
	{
		righttree->key = root->key;
		righttree = root;
		root = root->right;
	}
}
void remove_leftTree(Node*& root, Node*& lefttree)
{
	if (root->right != NULL)
	{
		remove_leftTree(lefttree, root->right);
	}
	else
	{
		lefttree->key = root->key;
		lefttree = root;
		root = root->left;
	}
}
void remove(Node*& root, int x)
{
	if (root != NULL)
	{
		if (root->key > x)
		{
			remove(root->left, x);
		}
		else if (root->key < x)
		{
			remove(root->right, x);
		}
		else
		{
			Node* p = root;
			if (!root->left)
			{
				root = root->right;
			}
			else if (!root->right)
			{
				root = root->left;
			}
			else
			{
				remove_leftTree(p, root->right);
				remove_rightTree(p, root->left);
			}
			delete p;
		}
	}
	else
	{
		cout << "Khong tim thay nut can xoa";
	}
}
void removeTree(Node*& root)
{
	if (root != NULL)
	{
		if (root->left == NULL && root->right == NULL)
			root = NULL;
		else
		{
			removeTree(root->left);
			removeTree(root->right);
		}
	}
}
int main() 
{
	Node* root = NULL;
	int n = 0, value = 0, luachon = 0;

	while (true)
	{
		cout << "-------------MENU-------------" << endl;
		cout << "1:Them 1 node vao cay" << endl;
		cout << "2:Duyet cay theo NLR" << endl;
		cout << "3:Duyet cay theo LNR" << endl;
		cout << "4:Duyet cay theo LRN" << endl;
		cout << "5:Duyet cay theo level" << endl;
		cout << "6:Dem so luong nut trong cay nho hon 1 gia tri" << endl;
		cout << "7:Dem so luong nut trong caylon hon 1 gia tri" << endl;
		cout << "8:Dem la trong cay" << endl;
		cout << "9:Xoa 1 node trong cay" << endl;
		cout << "10:Xoa toan bo cay" << endl;
		cout << "11:Kiem tra xem co phai cay AVL" << endl;
		cout << "12:Tim 1 node trong cay" << endl;
		cout << "0:Thoat" << endl;
		cout << "Nhap lua chon:"; cin >> luachon;
		switch (luachon)
		{
		case 1:
		{
			int value, n;
			cout << "Nhap so luong node can them vao cay:"; cin >> n;
			for (int i = 0; i < n; i++)
			{
				cout << "Nhap Node :"; cin >> value;
				Insert(root, value);
			}

			break;
		}
		case 2:
		{
			NLR(root);
			system("pause");
			break;
		}
		case 3:
		{
			LNR(root);
			system("pause");
			break;
		}
		case 4:
		{
			LRN(root);
			system("pause");
			break;
		}
		case 5:
		{
			levelOrder(root);
			system("pause");
			break;
		}
		case 6:
		{
			int x;
			cin >> x;
			cout << countLesser(root, x) << endl;
			system("pause");
			break;

		}
		case 7:
		{
			int x;
			cin >> x;
			cout << countGreater(root, x) << endl;
			system("pause");
			break;
		}
		case 8:
		{
			cout << countLeaves << endl;
			system("pause");
			break;
		}
		case 9:
		{

			int x = 0;
			cout << "Nhap Node can xoa:"; cin >> x;
			remove(root, x);
			break;
		}
		case 10:
		{
			removeTree(root);
			break;
		}
		case 11:
		{
			if (isAVL(root))
				cout << "La cay AVL";
			else
			{
				cout << "Khong la cay AVL";
			}
			system("pause");
			break;
		}
		case 12:
		{
			int x = 0;
			cout << "Nhap Node can tim:"; cin >> x;
			Node* Search = search(root, x);
			cout << Search->key;
			system("pause");
			break;
		}

		}
	}
	
}