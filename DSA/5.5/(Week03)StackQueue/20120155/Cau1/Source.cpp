#include<iostream>
#include<string>
using namespace std;


struct Node
{
	char data;
	Node* pNext;
};
struct Stack
{
	Node* pHead = NULL;
	
};

Node* InitNode(char value)
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
void push(Stack& s, char value)
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
int Top(Stack s)
{
	if (isEmpty(s))
	{
		cout << "Stack is empty";
		return 0;
	}
	return s.pHead->data;
	
}
void Pop(Stack& s)
{
	if (!isEmpty(s))
	{
		int data = s.pHead->data;
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

int precedence(char c)
{
	if (c == '(')
		return 0;
	else if (c == '+' || c == '-')
		return 1;
	else if (c == '*' || c == '/')
		return 2;
	return 3;

}
string convertInfixtoPostfix(string infix)
{	
	string postfix = "";
	Stack s;
	char x,token;
	int j = 0;
	for (int i = 0; infix[i]!='\0'; i++)
	{	
		if (infix[i] != ' ')
		{
			token = infix[i];
			if (isdigit(token))
			{
				postfix+= token;
				j++;
			}
			else
			{
				if (token == '(')
					push(s, token);
				else if (token == ')')
				{

					x = Top(s);
					while (x != '(')
					{
						postfix+= x;
						j++;
						Pop(s);
						x = Top(s);
					}
					Pop(s);
				}
				else
				{
					if (isEmpty(s))
					{
						push(s, token);
					}
					else
					{
						while (!isEmpty(s) && precedence(s.pHead->data) >= precedence(token))
						{

							postfix+= Top(s);
							Pop(s);
							j++;
							

						}
						push(s, token);

					}
				}
			}
		}
	}
	
	while (!isEmpty(s))
	{
		postfix+= Top(s);
		Pop(s);
		j++;
	}
	return postfix;
}
int main()
{	
	
	string infix="";
	string postfix = "";
	getline(cin, infix);
	postfix=convertInfixtoPostfix(infix);
	cout << postfix;
	
	
}