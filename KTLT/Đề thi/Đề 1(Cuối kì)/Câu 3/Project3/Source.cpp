#include<iostream>
#include<string>
#include<fstream>
using namespace std;


struct Element {
	int key=0;
	int priority=0;
};

struct Node {
	Element data;
	Node* pNext=NULL;
};

struct Queue {
	Node* pFront=NULL;
	Node* pRear=NULL;
};

Node* InitNode(Element value)
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
void InitQueue(Queue& q, Element value)
{
	if (q.pFront ==NULL)
	{
		Node* p = InitNode(value);
		q.pFront = q.pRear = p;
	}
	else
	{	
		Node* p = InitNode(value);
		q.pRear->pNext = p;
		q.pRear = p;

	}
}
void ExportQueue(Queue &q)
{
	for (Node* g = q.pFront; g->pNext; g = g->pNext)
	{
		for (Node* k = q.pFront->pNext; k ; k = k->pNext)
		{
			if (g->data.priority > k->data.priority)
			{
				swap(g->data.key, k->data.key);
				swap(g->data.priority, k->data.priority);
			}
		}
	}
	for (Node* g = q.pFront; g; g = g->pNext)
	{
		cout << g->data.key <<"->";
	}
	cout << "NULL";
		
}
void DestroyQueue(Queue& q)
{
	Node* p = new Node;
	while (q.pFront)
	{
		 p = q.pFront;
		 q.pFront = q.pFront->pNext;
		 delete p;
	}
}

void fWriteFile(string FileName,Queue q)
{
	ofstream out;
	out.open(FileName, ios_base::out);
	if (!out.is_open())
	{
		cout << "ERROR";
	}

	for (Node* g = q.pFront; g; g = g->pNext)
	{
		out << g->data.key << "->";
	}
	out << "NULL";
	out.close();
	
}
void fReadfile(string FileName)
{
	ifstream in;
	
	in.open(FileName, ios_base::in);
	if (!in.is_open())
	{
		cout << "ERROR";
	}
	

	Element value;
	string str;
	
	while (!in.eof())
	{
		in >> value.key;
		in >> str;
		cout << value.key << str;
	}
	in.close();

}
void Pop(Queue& q,int value)
{	
	Node* h = new Node;
	Node* k = new Node;
	for (Node* g = q.pFront; g ; g = g->pNext)
	{
		if (g->data.key== value)
		{	
			k = g;
			cout << k->data.key;
			h->pNext = g->pNext;
			g = g->pNext;
			delete k;
			
		}
		h = g;
	}
	
}
int main()
{
	Queue q;
	Element ele;
	string FileNameOut = "OUTPUT.txt";
	string FileNameIn = "INPUT.txt";
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ele.key; cin >> ele.priority;
		InitQueue(q, ele);
	}
	//ExportQueue(q);
	/*cout << endl;
	fWriteFile(FileNameOut,q);
	fReadfile(FileNameOut);*/
	int value; cin >> value;
	Pop(q, value);
	
	
	DestroyQueue(q);
	return 0;
}