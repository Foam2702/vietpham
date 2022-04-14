#include<iostream>
#include<string>
using namespace std;


struct Node
{
	string data="";
	Node* pNext=NULL;
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
bool Operator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}
string convertPrefixtoPostfix(string prefix)
{	
	int size = prefix.length();
	
	string postfix = "";
	Stack s;
	for (int i = size; i >= 0; i--)
	{	
		if (prefix[i] != '\0')
		{
			if (isdigit(prefix[i]))
			{
				push(s, string(1, prefix[i]));
			}
			else
			{
				string str1 = Top(s); Pop(s);
				string str2 = Top(s); Pop(s);
				string str = str1 + str2 + prefix[i];
				push(s, str);
			}

		}
	}
	postfix = Top(s);
	return postfix;
}
int main()
{
	string prefix = "";
	getline(cin, prefix);
	string postfix = convertPrefixtoPostfix(prefix);
	cout << postfix;
}