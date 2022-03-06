#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* pNext;
};

struct List
{
	Node* pHead = NULL;
	
};
Node* InitNode(int value)
{
	Node* p = new Node;
	if (p == NULL)
	{
		cout << "NOT ENOUGH MEMORY";
		return 0;
	}
	p->data = value;
	p->pNext = NULL;
	return p;
}

void AddLast(List& l, int value)
{	
	Node* p = InitNode(value);
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
 void reverse(List&l)
{
	Node* prev = NULL;
	Node* current = l.pHead;
	Node* next = NULL;
	while (current != NULL) {
		next = current->pNext;
		current->pNext = prev; 
		prev = current;
		current = next;
	}
	l.pHead = prev;
}
 void MergeSort(List& l, List& l2)
 {
	 Node* pHead1 = l.pHead;
	 Node* pHead2 = l2.pHead;
	 while (pHead1 && pHead2 )
	 {
		 Node* next1 = pHead1->pNext;
		 Node* next2 = pHead2->pNext;
		 pHead1->pNext = pHead2;
		 pHead2->pNext = next1;
		 pHead1 = next1;
		 pHead2 = next2;
	 }

 }
 void SplitList(List& l,int n)
{		
	 List l2;
	 Node* list2 = l.pHead->pNext;
	 Node* cut = l.pHead;
	 int count = 0;
	 
	 while (count != n / 2)
	 {	
		 list2 = list2->pNext;
		 cut = cut->pNext;
		 count++;
	 }
	 cut->pNext = NULL;
	 
	 l2.pHead = list2;
	 reverse(l2);
	 MergeSort(l, l2);

}
 

void ExportList(List l)
{
	for (Node* g = l.pHead; g; g = g->pNext)
	{
		cout << g->data << " ";
	}
	cout << endl;
}
int main()
{
	List l;
	int value = 0 , n = 0;
	do
	{
		cin >> n;
		if (n < 1 || n>1000)
		{
			cout << "n phai thuoc doan [1;1000]" << endl;
		}
	} while (n < 1 || n>1000);
	for (int i = 0; i < n; i++)
	{
		do
		{
			cin >> value;
			if (value < 1 || value>1000000)
			{
				cout << "n phai nam trong khoang [1;1000000]";
			}
		} while (value < 1 || value > 1000000);
		
		AddLast(l, value);
	}
	
	SplitList(l, n);
	ExportList(l);

}

