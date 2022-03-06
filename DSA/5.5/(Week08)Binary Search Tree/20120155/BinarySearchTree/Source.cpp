#include<iostream>
using namespace std;

struct Node
{
	int key = 0;
	Node* left = NULL;
	Node* right = NULL;
};
typedef Node* Tree;
Node* CreateNode(int data)
{
	Node* p = new Node;
	if (p == NULL)
	{
		cout << "NOT ENOUGH MEMORY";
	}
	else
	{
		p->key = data;
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}
void CreateTree(Tree& root)
{
	root = NULL;
}
void Insert(Tree& root, int value)
{	
	if (root == NULL)
	{
		Node* p = CreateNode(value);
		root = p;

	}
	else
	{

		if (root->key == value)
		{
			return;
		}
		if (root->key > value)
		{
			Insert(root->left, value);
		}
		else
		{
			Insert(root->right, value);
		}
	}
	
	
}
void NLR(Tree root)
{
	if (root != NULL)
	{
		cout << root->key<<" ";
		NLR(root->left);
		NLR(root->right);
	}
}
void LNR(Tree root)
{
	if (root != NULL)
	{
		LNR(root->left);
		cout << root->key<< " ";
		LNR(root->right);
	}
}
void LRN(Tree root)
{
	if (root != NULL)
	{
		LRN(root->left);
		LRN(root->right);
		cout << root->key<< " " ;
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
		cout << root->key<< " ";
	else if (level > 1) {
		CurrentLevel(root->left, level - 1);
		CurrentLevel(root->right, level - 1);
	}
}
void LevelOrder(Tree root)
{
	int h = height(root);
	for (int i = 1; i <= h; i++)
	{
		CurrentLevel(root, i);
	}
}

int CountNode(Tree tree) 
{
	if (tree == NULL)
		return 0;
	else
		return 1 + CountNode(tree->left) + CountNode(tree->right);
}
Node* search(Tree root,int x)
{
	if (root!=NULL)
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
void remove_rightTree(Tree& root, Tree& righttree)
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
void remove_leftTree(Tree& root, Tree& lefttree)
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
void remove(Tree root, int x)
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
void removeTree(Tree& root)
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
int find_Hight_Node(Tree root, int x,int& height)
{
	
	if (root == NULL) 
{
		return -1;
	}

	int leftHeight = find_Hight_Node(root->left, x, height);

	int rightHeight= find_Hight_Node(root->right, x, height);

	int temp = max(leftHeight, rightHeight) + 1;
	if (root->key == x)
		height = temp;
	
	return temp;
}


int HeightNode(Node* root, int x)
{
	
	int h = -1;
	int maxHeight = find_Hight_Node(root, x, h);
	return h;
}

bool isBST(Tree root)
{
	if (root == NULL)
		return true;


	if (root->left != NULL && root->left->key >= root->key)
		return false;

	
	if (root->right != NULL && root->right->key <= root->key)
		return false;

	
	if (!isBST(root->left) || !isBST(root->right))
		return false;

	
	return true;
}

int main()
{	
	int luachon = 0;
	Tree tree;
	CreateTree(tree);
	while (true)
	{
		cout << "-------------MENU-------------" << endl;
		cout << "1:Them 1 node vao cay" << endl;
		cout << "2:Duyet cay theo NLR" << endl;
		cout << "3:Duyet cay theo LNR" << endl;
		cout << "4:Duyet cay theo LRN" << endl;
		cout << "5:Duyet cay theo level" << endl;
		cout << "6:Tim chieu cao cua cay" << endl;
		cout << "7:Dem so nut trong cay" << endl;
		cout << "8:Tim 1 node trong cay" << endl;
		cout << "9:Xoa 1 node trong cay" << endl;
		cout << "10:Xoa toan bo cay" << endl;
		cout << "11:Tinh chieu cao cua 1 node" << endl;
		cout << "12:Kiem tra xem co phai cay nhi phan" << endl;
		cout << "0:Thoat" << endl;
		cout << "Nhap lua chon:"; cin >> luachon;
		switch (luachon)
		{
			case 1:
			{	
				int value,n;
				cout << "Nhap so luong node can them vao cay:"; cin >> n;
				for (int i = 0; i < n; i++)
				{
					cout << "Nhap Node :"; cin >> value;
					Insert(tree, value);
				}
				
				break;
			}
			case 2:
			{
				NLR(tree);
				system("pause");
				break;
			}
			case 3:
			{
				LNR(tree);
				system("pause");
				break;
			}
			case 4:
			{
				LRN(tree);
				system("pause");
				break;
			}
			case 5:
			{
				LevelOrder(tree);
				system("pause");
				break;
			}
			case 6:
			{
				cout<< height(tree);
				system("pause");
				break;
				
			}
			case 7:
			{
				cout << CountNode(tree);
				system("pause");
				break;
			}
			case 8:
			{
				int x = 0;
				cout << "Nhap Node can tim:"; cin >> x;
				Node* Search = search(tree, x);
				cout << Search->key;
				system("pause");
				break;
			}
			case 9:
			{
				int x = 0;
				cout << "Nhap Node can xoa:"; cin >> x;
				remove(tree, x);
				break;
			}
			case 10:
			{
				removeTree(tree);
				break;
			}
			case 11:
			{	
				int x;
				cout << "Nhap Node can tinh chieu cao:"; cin >> x;
				cout << HeightNode(tree, x);
				system("pause");
				break;
			}
			case 12:
			{
				if (isBST(tree))
					cout << "La cay nhi phan tim kiem";
				else
				{
					cout << "Khong la cay nhi phan tim kiem";
				}
				system("pause");
				break;
			}
			case 0:
				exit(0);

		
		}
	}
}