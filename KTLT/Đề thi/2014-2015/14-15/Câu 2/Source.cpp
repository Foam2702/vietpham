#include<iostream>
#include<vector>
using namespace std;


typedef struct 
{
	vector<int> data;
}IntStack;

void push(IntStack &q,int x)
{		
	while (cin >> x)
	{
		if (x == '.') break;
		q.data.push_back(x);
	}
	
}
bool isempty(IntStack& q)
{
	if (q.data.empty())
		return true;
	return false;
}
int pop(IntStack& q)
{	
	if (isempty(q) == true)
	{
		return 0;
	}
	q.data.pop_back();
	q.data.resize(q.data.size());
	return 1;
}
	
int main()
{
	
	int x=0;
	IntStack nganxep;
	push(nganxep, x);
	for (int i = 0; i < nganxep.data.size(); i++)
	{
		cout << nganxep.data[i] << " ";
	}
	cout << endl;
	pop(nganxep);
	for (int i = 0; i < nganxep.data.size(); i++)
	{
		cout << nganxep.data[i] << " ";
	}
	
	
	return 0;


}