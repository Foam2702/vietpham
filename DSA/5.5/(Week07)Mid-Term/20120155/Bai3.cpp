#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
#define MAX 1000

struct Node
{
	int data;
	int index;
	Node* pNext;
};

struct List
{
	Node* pHead = NULL;

};
void InitList(List &l)
{
	l.pHead = NULL;
}
Node* InitNode(int value,int index)
{
	Node* p = new Node;
	if (p == NULL)
	{
		cout << "NOT ENOUGH MEMORY";
		return 0;
	}
	p->data = value;
	p->index = index;
	p->pNext = NULL;
	return p;
}

void AddLast(List& l, int value,int index)
{
	Node* p = InitNode(value,index);
	if (l.pHead == NULL)
	{
		l.pHead = p;
	}
	else
	{
		Node* g = l.pHead;
		while (g->pNext)
		{
			g = g->pNext;
		}
		g->pNext = p;
	}

}

int Count_O_n2(vector<int> arr) {

	int count = 0;
	
	for (int i = 0; i < arr.size() - 1; i++) 
	{
		for (int j = i + 1; j < arr.size(); j++) 
		{	
			int condition = (floor(pow(i + 1, 1.5)) + ceil(sqrt(j + 1)));
			if (arr[j] - arr[i] == condition) 
			{
				count++;
			}
		}
	}
	return count;
}

int CountList(List &l, int data, int index) 
{
	int count = 0;
	while (l.pHead ) {
		if (l.pHead->data == data && l.pHead->index < index) {
			count++;
		}
		l.pHead = l.pHead->pNext;
	}
	return count;
}

int Count_O_n(vector<int> arr) 
{	
	int count = 0;
	int n = arr.size();
	vector<int> Ai(arr);
	vector<int> Aj(arr);
	List* table = new List[MAX];
	for (int i = 0; i < MAX; i++) 
	{
		InitList(table[i]);
	}
	
	for (int i = 0; i < n; i++) 
	{
		Ai[i] = Ai[i]+ floor ( pow ( i + 1, 1.5));
		AddLast(table[Ai[i]% MAX ], Ai[i], i);
		Aj[i] = Aj[i]- ceil( sqrt(i + 1));
	}
	
	for (int i = 0; i < Aj.size(); i++) 
	{
		if (Aj[i] > 0) 
		{
			count = count+ CountList(table[Aj[i] % MAX], Aj[i], i);
		}
	}
	return count;
}

int main() {
	vector<int> arr;
	int n;
	int value;
	do
	{
		cin >> n;
		if (n < 1 || n > 100000)
		{
			cout << "n phai thuoc doan[1;100000]" << endl;
			
		}
	} while (n < 1 || n > 100000);
	for (int i = 0; i < n; i++) 
	{
		
		do 
		{
			cin >> value;
			if (value < 1 || value>1000000)
			{
				cout << "gia tri value phai thuoc doan[1;1000000]" << endl;
			}
		} while (value < 1 || value>1000000);
		arr.push_back(value);
	}
	cout << Count_O_n(arr);
}