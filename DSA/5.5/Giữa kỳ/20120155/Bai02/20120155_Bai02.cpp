#include<vector>
#include<iostream>
#include<algorithm>
#include<time.h>
#include<queue>
using namespace std;
struct Node {
	int key = 0;
	int height = 0;
	Node* left = NULL;
	Node* right = NULL;
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
Node* Insert(Node* &root, int data)
{
	if (root == NULL)
	{
		return CreateNode(data);
	}
	
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
	
	root->height = 1+ max(GetHeight(root->left), GetHeight(root->right));
	int balance = getBalance(root);
	if (balance > 1 && data < root->left->key)
		return RotateRight(root);
	if (balance < -1 && data > root->right->key)
		return RotateLeft(root);
	if (balance > 1 && data > root->left->key)
	{
		root->left = RotateLeft(root->left);
		return RotateRight(root);
	}
	if (balance < -1 && data < root->right->key)
	{
		root->right = RotateRight(root->right);
		return RotateLeft(root);
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
	if (root == NULL) return;
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


int xuLyYeuCau(Node* root, int x) 
{	
	int min = abs(x - root->key), mintemp = 0,result = -1;
	if (root != NULL)
	{
		if (root->key == x)
		{
			return root->key;
		}
		if (root->key > x)
		{	
			
			mintemp = abs(x - root->key);
			if (mintemp > min)
			{	
				result = mintemp;
			}
			min = mintemp;
			return xuLyYeuCau(root->left, x);
			
		}
		else
		{
			mintemp = abs(x - root->key);
			if (mintemp > min)
			{
				result = mintemp;
			}
			min = mintemp;
			return xuLyYeuCau(root->right, x);
			
		}
	}
	return -1;
	

}
int main()
{//Bo cmt cac dong duoi day neu ban muon giao tiep chuong trinh thong qua file

    // if (fopen("./input1.txt", "r")) {
    //     freopen("./input1.txt", "r", stdin);
    //     //freopen("./output1.txt", "w", stdout);
    // }

	clock_t start, end;
	double cpu_time_used;

	

	start = clock();

	/* Design your algorithm here */
	int N, value, K;
	Node* root = NULL;
	vector<int> arr;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> value;
		arr.push_back(value);
	}
	for (int i = 0; i < arr.size(); i++)
	{
		root=Insert(root, arr[i]);
	}
	cin >> K;
	cout << xuLyYeuCau(root, K);
	
	end = clock();

	//Luu y rang ban se phai cmt dong duoi day lai khi nop bai, neu khong se bi sai output.
	//cerr << "Execution time: " << ((double) (end - start)) / CLOCKS_PER_SEC << "s";

	return 0;

}