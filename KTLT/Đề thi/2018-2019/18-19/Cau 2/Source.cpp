#include<iostream>
using namespace std;


struct Donthuc
{
	int heso;
	int muso;
};
struct Node
{	
	Donthuc data;
	Node* pNext = NULL;

};
struct List
{
	Node* Head=NULL;
};

Node* InitNode(Donthuc value)
{
	Node* p = new Node;
	if (p == NULL)
	{
		cout << "NOT ENOUGH MEMORY";
	}
	else
	{
		p->data = value;
		p->pNext = NULL;
	}
	return p;
}

void push_back(Node* &head,Donthuc value)
{
	if (head == NULL)
	{
		Node* p = InitNode(value);
		head = p;
	}
	else
	{
		Node* g = head;
		while (g->pNext)
		{
			g = g->pNext;
		}
		g->pNext = InitNode(value);
	}
}

double tinhGiaTri(Node* head, double x)
{	
	double sum=0;
	for (Node* g = head; g; g = g->pNext)
	{
		sum += g->data.heso * pow(x, g->data.muso);
	}
	return sum;
}
int main()
{
	int n,x; 
	double sum = 0;
	Donthuc value;
	Node* head = NULL;

	cout << "Nhap so luong don thuc:";
	cin >> n;
	for (int i = 0; i < n; i++)
	{	
		cout << "Nhap he so:";
		cin >> value.heso;
		cout << "Nhap mu so:";
		cin >> value.muso;
		push_back(head,value);
	}

	cout << "Nhap gia tri cua x:";
	cin >> x;

	sum = tinhGiaTri(head, x);
	cout << sum;
	return 0;
	
}

