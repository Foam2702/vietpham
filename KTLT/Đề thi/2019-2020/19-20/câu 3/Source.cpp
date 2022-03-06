#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};
struct List {
	Node* head = NULL;
};

Node* CreateNode(int data)
{
	Node* p = new Node;
	if (p == NULL)
	{
		cout << "NOT ENOUGH MEMORY";
	}
	else
	{
		p->data = data;
		p->next = NULL;
	}
	return p;
}

void push_back(List& l, int value)
{

	if (l.head == NULL)
	{
		Node* p = CreateNode(value);
		l.head = p;
	}
	else
	{
		Node* g = l.head;
		while (g->next)
		{
			g = g->next;
		}
		g->next = CreateNode(value);
	}
}
void push_front(List& l, int value)
{
	if (l.head == NULL)
	{
		Node* p = CreateNode(value);
		l.head = p;
	}
	else
	{
		Node* p = CreateNode(value);
		p->next = l.head;
		l.head = p;
	}
	
}

Node* findMin(Node *start)//câu a
{
	if (start->next == NULL)
	{
		return start;
	}
	Node* temp = findMin(start->next);
	
	if (start->data < temp->data)
		return start;
	else
		return findMin(start->next);
	
}


void selectionSort(Node* head)//câu b
{
	if (head->next == NULL)
	{
		return;
	}
	else
	{
		Node* temp = findMin(head->next);
		if (head->data < temp->data) 
		{
			return selectionSort(head->next);
		}
		else
		{
			swap(head->data, temp->data);
			return selectionSort(head->next);
		}
		
		
	}

}

int main()
{
	List l;
	int arr[] = { 9,8,5,3,2,1,0 };
	for (int i = 0; i < 7; i++)
	{
		push_back(l, arr[i]);
	}
	Node* p = l.head;
	/*Node* min = findMin(p);
	cout << min->data;*/
	selectionSort(p);
	for (Node* g = p; g; g = g->next)
	{
		cout << g->data << endl;
	}
	
}