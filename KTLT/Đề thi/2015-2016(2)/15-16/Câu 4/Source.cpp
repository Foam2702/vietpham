#include<iostream>
#include<vector>
using namespace std;

int CountWordLongerthanN(string s,int n)
{	
	unsigned int i = 0;
	int j = 0;
	vector<char> arr;
	while (s[i] == ' ')
	{
		i++;
	}
	arr.push_back(s[i++]);
	j++;
	while (s[i] != '\0')
	{	
		if (s[i] != ' ')
		{
			if (s[i - 1] == ' ') 
			{	
				arr.push_back(' ');
				j++;
				arr.push_back(s[i++]);
				j++;
			}
			else
			{
				arr.push_back(s[i++]);
				j++;
			}
		}
		else
		{
			i++;
		}
	}
	
	int count = 0;
	int longer = 0;
	i = 0;
	
	while (i<arr.size())
	{
		while (arr[i] != ' ')
		{
			count++;
			i++;
			if (i == (arr.size() - 1)) break;
			
		}
		if (count > n)
		{	
			
			longer++;
			count = 0;
			i++;
		}

		else if (count < n)
		{
			count = 0;
			i++;
		}
		else i++;
		
	}
	cout << endl;
	return longer;
}

int main()
{
	string s= "ky Thuat Lap Trinh";
	int n; cout << "Nhap n: "; cin >> n;
	cout<<CountWordLongerthanN(s, n);
	return 0;
}