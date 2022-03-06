#include<iostream>
using namespace std;

struct Node
{
	int data=0;
	Node* pNext=NULL;
};
struct Stack
{
	Node* Head=NULL;
};

Node* InitNode(int data)
{
	Node* p = new Node;
	if (p == NULL)
	{
		cout << "NOT ENOUGH MEMORY";
	}
	else
	{
		p->data = data;
		p->pNext = NULL;
	}
	return p;
}

bool IsEmpty(Stack s)
{
	return (s.Head == NULL);
}

void Push(Stack& s, int value)
{
	Node* p = InitNode(value);
	if (IsEmpty(s))
	{
		s.Head = p;
	}
	else
	{
		//Stack nên phải thêm vào đầu
		p->pNext = s.Head;
		s.Head = p;
	}
}
int Top(Stack s)
{
	if (!IsEmpty(s))
	{
		return s.Head->data;
	}
	else
	{
		cout << "STACK IS EMPTY";
	}
}

int Pop(Stack& s)
{
	if (!IsEmpty(s))
	{
		int data = s.Head->data;
		Node* p = s.Head;
		s.Head = s.Head->pNext;
		delete p;
		return data;
	}
	else
	{
		cout << "STACK IS EMPTY";
	}
}

void ExportStack(Stack s)
{
	for (Node* g = s.Head; g ; g = g->pNext)
	{
		cout << g->data << "-->";
	}
	cout << endl;
}
int main()
{
	int n;
	int value;
	Stack s;
	cout << "Nhap so luong phan tu:"; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		Push(s, value);
		
	}
	ExportStack(s);
	cout << Top(s) << endl;
	Pop(s);
	while (!IsEmpty(s))//giải phóng 
	{
		int data = Top(s);
		Pop(s);
		cout << data<<"-->";
	}

		
}