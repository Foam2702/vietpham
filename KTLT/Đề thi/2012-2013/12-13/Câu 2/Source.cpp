#include<iostream>
#include<vector>
using namespace std;

typedef struct {
	vector<int>data;
}IntQueue;

void enqueue(IntQueue& q, int x)
{
	while (cin >> x)
	{
		if (x == '.') break;
		q.data.push_back(x);
	}
}
int dequeue(IntQueue& q)
{
	q.data.erase(q.data.begin());
	q.data.resize(q.data.size());
	return 1;
}

int first(IntQueue &q)
{	
	return q.data.front();
}
int main()
{
	IntQueue q;
	int x = 0;
	enqueue(q, x);
	dequeue(q);
	for (int i = 0; i < q.data.size(); i++)
	{
		cout << q.data[i] << " ";
	}
	cout << endl;
	/*int value = first(q);
	cout << value;*/
	return 0;
}