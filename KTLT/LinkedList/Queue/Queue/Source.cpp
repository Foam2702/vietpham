#include<iostream>
using namespace std;

struct Node
{
	int data = 0;
	Node* pNext = NULL;
};
struct Queue
{
	Node* Head = NULL;
};

Node* InitNode(int value)
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

bool IsEmpty(Queue q)
{
	return (q.Head == NULL);
}
void enQueue(Queue& q, int value)
{
	Node* p = InitNode(value);
	if (IsEmpty(q))
	{
		q.Head = p;
	}
	else
	{
		//Queue nên phải thêm vào sau
		Node* g = q.Head;
		while (g->pNext)
		{
			g = g->pNext;
		}
		g->pNext = p;
	}
}

int Peek(Queue q)//lấy phần tử đầu tiên nhưng không xóa
{
	if(!IsEmpty(q))
	{
		return q.Head->data;
	}
	else
	{
		cout << "QUEUE IS EMPTY";
	}
}

int deQueue(Queue& q)
{
	if (!IsEmpty(q))
	{
		int data = q.Head->data;
		Node* p = q.Head;
		q.Head = q.Head->pNext;
		delete p;
		return data;
		
		
	}
	else
	{
		cout << "QUEUE IS EMPTY";
	}
}
void ExportQueue(Queue q)
{
	for (Node* g = q.Head; g; g = g->pNext)
	{
		cout << g->data << "<--";
	}
	cout << endl;
}
int main()
{
	int n;
	int value;
	Queue q;
	cout << "Nhap so luong phan tu:"; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		enQueue(q, value);
	}
	ExportQueue(q);
	cout << Peek(q) << endl;
	deQueue(q);
	while (!IsEmpty(q))//giải phóng
	{
		int data = Peek(q);
		deQueue(q);
		cout << data << "<--";
	}
}