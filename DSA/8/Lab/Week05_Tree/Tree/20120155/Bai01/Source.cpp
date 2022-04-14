#include<iostream>
#include<time.h>
#include<queue>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

typedef Node* Tree;

void createTree(Tree& root) {
	root = NULL;
}

Node* createNode(int value) {
	Node* p = new Node;
	if (p == NULL) {
		cout << "NOT ENOUGH MEMORY" << endl;
	}
	else {
		p->data = value;
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}

//void NLR(Tree root) {
//	if (root) {
//		cout << root->data;
//		NLR(root->left);
//		NLR(root->right);
//	}
//}
void LNR(Tree root) {
	if (root) {
		LNR(root->left);
		cout << root->data<<" ";
		LNR(root->right);
	}
}
//void LRN(Tree root) {
//	if (root) {
//		LRN(root->left);
//		LRN(root->right);
//		cout << root->data;
//	}
//}
void DestroyTree(Tree root) {
	if (root) {
		DestroyTree(root->left);
		DestroyTree(root->right);
		delete root;
	}
}

void AddNode(Tree& root, Node* node) {
	if (root) {
		if (root->data == node->data)
			return;
		else if (node->data < root->data) {
			AddNode(root->left, node);
		}
		else if (node->data > root->data) {
			AddNode(root->right, node);
		}
	}
	else {
		root = node;
	}
}

void levelOrder_Queue(Tree root) {
	queue<Node*> _queue;
	if (root == NULL) {
		return;
	}
	_queue.push(root);
	while (!_queue.empty()) {
		Node* current = _queue.front();
		_queue.pop();
		cout << current->data << " ";
		if (current->left != NULL) {
			_queue.push(current->left);

		}
		if (current->right != NULL) {
			_queue.push(current->right);
		}
	}
}
int height(Tree root)
{
	if (root == NULL)
		return 0;
	else
	{

		int leftheight = height(root->left);
		int rightheight = height(root->right);


		if (leftheight > rightheight)
		{
			return (leftheight + 1);
		}
		else
		{
			return (rightheight + 1);
		}
	}
}
void CurrentLevel(Tree root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		cout << root->data << " ";
	else if (level > 1) {
		CurrentLevel(root->left, level - 1);
		CurrentLevel(root->right, level - 1);
	}
}
void LevelOrder_Recursion(Tree root)
{
	int h = height(root);
	for (int i = 1; i <= h; i++)
	{
		CurrentLevel(root, i);
	}
}
int count_Leaf(Tree Tree)
{
	if (Tree == NULL) return 0;
	else
		if (Tree->left == NULL && Tree->right == NULL) return 1;
		else return count_Leaf(Tree->left) + count_Leaf(Tree->right);
}
int find_Max(Tree root)
{
	if (root->right == NULL)
	{
		return root->data;
	}
	return find_Max(root->right);
}
int find_Min(Tree root)
{
	
	if (root->left == NULL)
	{
		return root->data;
	}
	return find_Min(root->left); 
}
int sum_Equal_or_moreThanx(Tree root, int x) {
	if (root == NULL) {
		return 0;
	}
	
	if (root) {
		int a = sum_Equal_or_moreThanx(root->left, x);
		int b = sum_Equal_or_moreThanx(root->right, x);
		if (root->data>=x) {
			return root->data + a + b;

		}
		return a + b;
		
	}

	
}
int main() {
	int choose,value,chooseTree;
	Node* node;
	Tree root;

	createTree(root);
	do {
		
		cout << "1:Cay tu nhap" << endl;
		cout << "2:Cay co san (Hinh 1.1)" << endl;
		cout << "Nhap lua chon:"; cin >> chooseTree;
		if (chooseTree < 1 || chooseTree>2) {
			cout << "Nhap lai" << endl;

		}
	} while (chooseTree < 1 || chooseTree>2);
	
	if (chooseTree == 2) {
		node = createNode(70);
		AddNode(root, node);
		node = createNode(31);
		AddNode(root, node);
		node = createNode(93);
		AddNode(root, node);
		node = createNode(14);
		AddNode(root, node);
		node = createNode(73);
		AddNode(root, node);
		node = createNode(94);
		AddNode(root, node);
		node = createNode(23);
		AddNode(root, node);
	}
	while (true) {
		system("cls");
		if (chooseTree == 1) {
			cout << "1:Them 1 node vao cay BST" << endl;
		}
		cout << "2:Duyet cay theo LNR" << endl;
		cout << "3:Duyet cay theo muc (Hang doi)" << endl;
		cout << "4:Duyet cay theo muc (De quy)" << endl;
		cout << "5:Dem so node la cua cay" << endl;
		cout << "6:Tim node co khoa nho nhat" << endl;
		cout << "7:Tim node co khoa lon nhat" << endl;
		cout << "8:Tinh tong cac node co khoa lon hon hoac bang x" << endl;
		cout << "9:Tim chieu cao cua cay" << endl;
		cout << "0:Thoat" << endl;
		if (chooseTree == 1) {
			do {
				cout << "Nhap lua chon:"; cin >> choose;
				if (choose < 0 || choose > 9) {
					cout << "Nhap lai:" << endl;
				}

			} while (choose < 0 || choose>9);
		}
		else {
			do {
				cout << "Nhap lua chon:"; cin >> choose;
				if (choose == 1 ||choose<0|| choose > 9) {
					cout << "Nhap lai:" << endl;
				}

			} while (choose == 1 || choose < 0 || choose > 9);
		}
		if (choose == 1) {
			cout << "Nhap gia tri:"; cin >> value;
			node = createNode(value);
			AddNode(root, node);
		}
		else if (choose == 2) {
			cout << "Duyet cay theo Inorder-LNR" << endl;
			LNR(root);
			system("pause");
		}
		else if (choose == 3) {
			cout << "Duyet theo muc su dung hang doi" << endl;
			levelOrder_Queue(root);
			system("pause");
		}
		else if (choose == 4) {
			cout << "Duyet theo muc su dung de quy:" << endl;
			LevelOrder_Recursion(root);
			system("pause");
		}
		else if (choose == 5) {
			cout << "So node la cua cay" << endl;
			cout << count_Leaf(root)<<endl;
			system("pause");
		}
		else if (choose == 6) {
			cout << "Node co khoa nho nhat" << endl;
			cout << find_Min(root)<<endl;
			system("pause");
		}
		else if (choose == 7) {
			cout << "Node co khoa lon nhat" << endl;
			cout << find_Max(root)<<endl;
			system("pause");
		}
		else if (choose == 8) {
			int x = 0;
			cout << "Nhap x:"; cin >> x;
			cout << "Tong cac node co khoa lon hon hoang bang x" << endl;
			cout << sum_Equal_or_moreThanx(root, x)<<endl;
			system("pause");
		}
		else if (choose == 9) {
			cout << "Chieu cao cua cay" << endl;
			cout << height(root)<<endl;
			system("pause");
		}
		else if (choose == 0) {
			break;
		}

	}
	

	
	


}