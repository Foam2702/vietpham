#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct ngaybay {
	unsigned int ngay=0;
	unsigned int thang=0;
	unsigned int nam=0;
};

struct CB {
	string maso;
	string hoten;
	ngaybay nb;
	unsigned int succhua=0;
};

struct Node
{
	CB data;
	Node* pNext=NULL;
};
struct List {
	Node* pHead = NULL;
};

Node* InitNode(CB chuyenbay)
{
	Node* p = new Node;
	if (p == NULL)
	{
		cout << "NOT ENOUGH MEMORY";
		return 0;
	}
	p->data = chuyenbay;
	p->pNext = NULL;
	return p;
}

void AddTail(List &l, CB chuyenbay)
{
	if (l.pHead == NULL)
	{
		Node* p = InitNode(chuyenbay);
		l.pHead = p;
	}
	else
	{
		Node* g = l.pHead;
		while (g->pNext)
		{
			g = g->pNext;
		}
		g->pNext = InitNode(chuyenbay);
		
	}
}

int Tongsucchua(List l)
{
	int sum = 0;
	for (Node* g = l.pHead; g; g = g->pNext)
	{
		if(g->data.nb.thang==1|| g->data.nb.thang == 2|| g->data.nb.thang == 3)
		{
			sum+=g->data.succhua;
		}
	}
	return sum;
}
void SucchuaMax(List l)
{
	unsigned max = l.pHead->data.succhua;
	Node* p = new Node;
	for (Node* g = l.pHead; g; g = g->pNext)
	{
		if (g->data.succhua > max)
		{
			max = g->data.succhua;
			p = g;
		}
	}
	cout << p->data.hoten << endl;
	cout << p->data.maso ;
	
}

void ExportList(List l)
{
	for (Node* g = l.pHead; g; g = g->pNext)
	{
		cout << g->data.hoten << endl;
		cout << g->data.maso << endl;
		cout << g->data.nb.ngay << "/" << g->data.nb.thang << "/" << g->data.nb.nam << endl;
		cout << g->data.succhua<<endl<<endl;
	}
}

int main()
{
	List l;
	int n; cin >> n;
	CB chuyenbay;

	for (int i = 0; i < n; i++)
	{	
		cin.ignore();
		getline(cin, chuyenbay.hoten);
		getline(cin, chuyenbay.maso);
		cin >> chuyenbay.nb.ngay; 
		cin >> chuyenbay.nb.thang; 
		cin >> chuyenbay.nb.nam; 
		cin >> chuyenbay.succhua;
		AddTail(l, chuyenbay);
		
	}
	ExportList(l);
	cout << endl;
	int sum = Tongsucchua(l);
	cout << sum << endl;
	SucchuaMax(l);
	cout << endl;
	return 0;

}
