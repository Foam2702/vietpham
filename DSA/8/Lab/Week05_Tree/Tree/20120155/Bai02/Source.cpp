#include<iostream>
#include<stack>
#include<string>
#include<sstream>
using namespace std;

struct Node {
	int key;
	Node* left;
	Node* right;

};

Node* createNode(int key) {
	Node* node = new Node;
	node->key = key;
	node-> left = node -> right = NULL;
	return node;
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
	string postfix = "",real="";
	stack<char> s;
	char x, token;
	int j = 0;
	for (int i = 0; infix[i] != '\0'; i++)
	{
		if (infix[i] != ' ')
		{
			token = infix[i];
			if (isdigit(token))
			{
				postfix += token;
				j++;
			}
			else
			{
				if (token == '(')
					s.push(token);
				else if (token == ')')
				{

					x = s.top();
					while (x != '(')
					{
						postfix += " ";
						postfix += x;
						
						j++;
						s.pop();
						x = s.top();
						
					}
					s.pop();
				}
				else
				{
					if (s.empty())
					{
						s.push(token);
					}
					else
					{
						while (!s.empty() && precedence(s.top()) >= precedence(token))
						{
							postfix += " ";
							postfix += s.top();
							
							s.pop();
							j++;


						}
						s.push(token);

					}
				}
				postfix += " ";
				
			}
		}
	}

	while (!s.empty())
	{
		postfix += s.top();
		postfix += " ";
		s.pop();
		
		j++;
	}
	return postfix;
}
bool checkprecedence(char c)
{
	
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}
int chuyen_char_sang_int(char c)
{
	return c - 48;
}
char chuyen_int_sang_char(int x) {
	char b = x + 48;
	return b;
}
int Evaluate(string postfix) {
	char p ;
	int t = 0;
	string number;
	stack<char> s;
	stack<char*>r;
	
	for(int i =0; i<postfix.length(); i++) {
		p = postfix[i];
		while (p == ' ') {
			i++;
			p = postfix[i];
		}
		
		if (checkprecedence(postfix[i])==true) {
			int b = chuyen_char_sang_int(s.top());
			s.pop();
			int a = chuyen_char_sang_int(s.top());
			s.pop();
			if (postfix[i] == '+')
				t = a + b;
			else if (postfix[i] == '-') {
				t = a - b;
			}
			else if (postfix[i] == '*') {
				t = a * b;
			}
			else if (postfix[i] == '/') {
				t = a / b;
			}
			
			
			
			stringstream strs;
			strs << t;
			string temp_str = strs.str();
			char* char_type = (char*)temp_str.c_str();
			
			r.push(char_type);
			
			
	
		}
		else {
			s.push(postfix[i]);
		}
	}
	
	return t;
}
int main()
{

	string infix = "";
	string postfix = "";
	getline(cin, infix);
	postfix=convertInfixtoPostfix(infix);
	cout << postfix << endl;
	cout << Evaluate(postfix);


}

