#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
struct  TNode
{
	int key;
	TNode* pLeft;
	TNode* pRight;
};
typedef struct TNode *TREE;
 
void CreateTREE(TREE &T)
{
	T = NULL;
}
TNode* CreateTNode(int x)
{
	TNode *p;
	p = new TNode;
	if (p == NULL)
		exit(1);
	else
	{
		p->key = x;
		p->pLeft = NULL;
		p->pRight = NULL;
	}
	return p;
}
void InsertTNode(TREE &T, int x)
{
	if (T)
	{
		if (T->key == x)
			return;
		if (T->key > x)
			return InsertTNode(T->pLeft, x);
		else
			return InsertTNode(T->pRight, x);
	}
		T = new TNode;
		if (T == NULL)
			exit(1);
		T->key = x;
		T->pLeft = T->pRight = NULL;
}

void InputTREE(TREE &T)
{
	int n = 11;
	int A[11] = { 50,30,87,23,41,75,93,81,91,11,25 };
	for (int i = 0; i < n; i++)
	{  
		//TNode *p = CreateTNode(A[i]);
		InsertTNode(T, A[i]); 
	}
}
void NLR(TREE Root)
{
	if (Root != NULL)
	{
		cout << Root->key << " ";
		NLR(Root->pLeft);
		NLR(Root->pRight);
	}
}
void LNR(TREE Root)
{
	if (Root != NULL)
	{
		LNR(Root->pLeft);
		cout << Root->key << " ";
		LNR(Root->pRight);
	}
}
void LRN(TREE Root)
{
	if (Root != NULL)
	{
		LRN(Root->pLeft);
		LRN(Root->pRight);
		cout << Root->key << " ";
	}
}
TNode*  SearchTNode(TREE Root, int x)
{
	
	TNode* p = Root;
	while (p != NULL)
	{
		if (x == p->key)
			return p;
		else
		{
			if (x < p->key)
				p = p->pLeft;
			else
				p = p->pRight;
		}
	}
	return NULL;
}
void Replace(TREE &T, TREE &p)
{
	if (T->pLeft != NULL)
		{
			Replace(p, T->pLeft);
		}
	else
		{
			p->key = T->key;
			p = T;
			T = T->pRight;
		}
}
void DeleteTNode(TREE &T, int x)
{
	if (T != NULL)
	{
		if (T->key < x)
			DeleteTNode(T->pRight, x);
		else
		{
			if (T->key > x)
				DeleteTNode(T->pLeft, x);
			else
			{
				TNode* p;
				p = T;
				if (T->pLeft == NULL)
					T = T->pRight;
				else
				{
					if (T->pRight == NULL)
						T = T->pLeft;
					else
						Replace(T->pRight, p);
				}
				delete p;
			}
		}
	}
	else
		cout << "Khong tim thay phan tu can xoa" << "\n";
}
int ChieuCao(TREE T)
{
	if (!T)
		return 0;
	int a = ChieuCao(T->pLeft);
	int b = ChieuCao(T->pRight);
	if (a>b)
		return (a + 1);
		return (b + 1);
}

void DieuKienNode(TREE T, int &Dem, int &S)
{
	if (T)
	{
		if (T->pLeft==NULL && T->pRight==NULL)  							 
		{
			cout << T->key << " ";  
			Dem++; 		 
			S += T->key; 		  
		}
		DieuKienNode(T->pLeft, Dem, S);
		DieuKienNode(T->pRight, Dem, S);
	}
}

void XuatTangK(TREE T, int tang, int &Dem, int &S)
{
	if (T)
	{
		tang--;
		if (tang==0)
		{
			cout << T->key << " ";
			Dem++;
			S += T->key;
		}

		XuatTangK(T->pLeft, tang, Dem, S);
		XuatTangK(T->pRight, tang, Dem, S);
	}
}

 


int main()
{
	TREE a;
	int k;
	CreateTREE(a);
	InputTREE(a);
	cout << "\nDuyet truoc:";
	NLR(a);
	int ccao = ChieuCao(a);
	//DieuKienNode(a, dem, S);
	//int *dem = new int[ccao];
	//int *tong = new int[ccao];
	int dem[10] = { 0 };
	int tong[10] = { 0 };
	cout << "\nLiet ke cac node o moi tang:" << endl;
	for (int i = 1; i <= ccao; i++)
	{
		cout << "---------------------------"<<endl;
		cout << "Tang " << i - 1 << ":";
		XuatTangK(a, i, dem[i-1], tong[i-1]);
		cout << endl;
		cout << "So luong :" << dem[i - 1] << endl;
		cout << "Tong :" << tong[i - 1] << endl;
	}

	do { 
		cout << "\n\nNhap tang K = ";
		cin >> k;

		int dem_k = 0, tong_k = 0;
		cout << "----------------------------- " << endl;
		cout << "\nLiet ke cac node tang " << k << ":" << endl;
		XuatTangK(a, k + 1, dem_k, tong_k);
		cout << endl;
		cout << "So luong :" << dem_k << endl;
		cout << "Tong :" << tong_k << endl;


		cout << "----------------------------- " << endl;
		int dem_thap_k[10] = { 0 };
		int tong_thap_k[10] = { 0 };
		cout << "\nLiet ke cac node tang thap hon " << k << ":" << endl;
		for (int i = k+1; i < ccao; i++)
		{
			cout << "\nTang " << i << ":";
			XuatTangK(a, i + 1, dem_thap_k[i - 1], tong_thap_k[i - 1]);
			cout << endl;
			cout << "So luong :" << dem_thap_k[i - 1] << endl;
			cout << "Tong :" << tong_thap_k[i - 1] << endl;
		}

		cout << "----------------------------- " << endl;
		int dem_cao_k[10] = { 0 };
		int tong_cao_k[10] = { 0 };
		int j = 0;
		cout << "\nLiet ke cac node tang cao hon  " << k << ":" << endl;
		for (int i = k-1; i > -1; i--)
		{
			cout << "\nTang " << i << ":";
			XuatTangK(a, i + 1, dem_cao_k[j], tong_cao_k[j]);
			cout << endl;
			cout << "So luong :" << dem_cao_k[j] << endl;
			cout << "Tong :" << tong_cao_k[j] << endl;
			j++;
		}


	} while (k != -1);
	system("Pause");
}