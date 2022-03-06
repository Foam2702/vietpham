#include<iostream>
#include<string>
#include<vector>
using namespace std;


void getParagraph(char *&s)
{	
	vector<string> parag;
	while (cin>>s)
	{	
		if (*s == '.' || *s == '\n') break;
		cout << *s << endl;
		cout << s << endl;
		parag.push_back(s);
		
	}
	int size = parag.size();
	for (int i = 0; i < size; i++)
	{
		cout << parag[i] <<" ";
	}
}
int main()
{
	char* s=new char;
	getParagraph(s);
	
	return 0;
}