#include<iostream>
#include<string>
using namespace std;


struct Node
{
	string data = "";
	Node* pNext = NULL;
};
struct Stack
{
	Node* pHead = NULL;

};

Node* InitNode(string value)
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
bool isEmpty(Stack s)
{
	return (s.pHead == NULL);
}
void push(Stack& s, string value)
{
	Node* p = InitNode(value);
	if (isEmpty(s))
	{
		s.pHead = p;
	}
	else
	{
		p->pNext = s.pHead;
		s.pHead = p;
	}
}
string Top(Stack s)
{
	if (isEmpty(s))
	{
		cout << "Stack is empty";

	}
	return s.pHead->data;

}
void Pop(Stack& s)
{
	if (!isEmpty(s))
	{
		string data = s.pHead->data;
		Node* p = s.pHead;
		s.pHead = s.pHead->pNext;
		delete p;

	}
	else
	{
		cout << "Stack is empty";

	}
}

void ExportStack(Stack s)
{
	for (Node* g = s.pHead; g; g = g->pNext)
	{
		cout << g->data << " ";
	}
	cout << endl;
}

string convertPostfixtoPrefix(string postfix)
{
	int size = postfix.length();

	string prefix = "";
	Stack s;
	for (int i = 0; i < size; i++)
	{

		if (isdigit(postfix[i]))
		{
			push(s, string(1, postfix[i]));
		}
		else
		{
			string str1 = Top(s); Pop(s);
			string str2 = Top(s); Pop(s);
			string str = postfix[i] + str2 + str1;
			push(s, str);
		}

	}

	prefix = Top(s);
	return prefix;
}
int main()
{
	string postfix = "";
	getline(cin, postfix);
	string prefix = convertPostfixtoPrefix(postfix);
	cout << prefix;
}