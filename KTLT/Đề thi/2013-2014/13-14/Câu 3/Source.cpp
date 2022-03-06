#include<iostream>
using namespace std;

struct Node
{
	int data=0;
	Node* pNext=NULL;
};

struct Queue
{
	Node* pHead = NULL;
};

Node* CreateNode(int x)
{
	Node* p = new Node;
	if (p == NULL)
	{
		cout << "NOT ENOUGH MEMORY";
	}
	else
	{
		p->data = x;
		p->pNext = NULL;
	}
	return p;
}

bool isEmpty(Queue queue)
{
	if (queue.pHead == NULL)
		return true;
	return false;

}
void Enqueue(Queue &queue,int x)
{
	if (isEmpty(queue)==true)
	{
		Node* p = CreateNode(x);
		queue.pHead = p;
	}
	else
	{
		Node* g = queue.pHead;
		while (g->pNext)
			g = g->pNext;
		g->pNext = CreateNode(x);
	}
}

int Dequeue(Queue& queue)
{
	if (isEmpty(queue) == true)
	{
		cout << "QUEUE IS EMPTY !";
		system("pause");
		return 0;
	}
	
	Node* p = queue.pHead;
	queue.pHead = queue.pHead->pNext;
	return p->data;
	delete p;
	
}

int first(Queue queue)
{
	if (isEmpty(queue) == true)
	{
		cout << "QUEUE IS EMPTY !";
		system("pause");
		return 0;

	}
	
	return queue.pHead->data;
	
}


void DeleteQueue(Queue& queue)
{
	
	while (queue.pHead)
	{
		Node* p = queue.pHead;
		queue.pHead = queue.pHead->pNext;
		delete p;
	}
}
void PrintQueue(Queue queue)
{
	for (Node* g = queue.pHead; g; g = g->pNext)
	{
		cout << g->data<< " ";
	}
}

int main()
{
	Queue queue;
	int n; cin >> n;
	int x,f;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		Enqueue(queue, x);
	}
	PrintQueue(queue);
	//Dequeue(queue);
	/*f = first(queue);
	cout << f;*/
	DeleteQueue(queue);
	return 0;
}