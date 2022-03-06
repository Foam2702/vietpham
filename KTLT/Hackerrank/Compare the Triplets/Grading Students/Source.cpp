#include<iostream>
#include<vector>
using namespace std;

vector<int>gradingStudents(vector<int>grades)
{
	int n,data;
	cin >> n;

	vector<int>newgrades;
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		grades.push_back(data);
	}
	for (int i = 0; i < grades.size(); i++)
	{
		if (grades[i] >= 38)
		{
			if (grades[i] % 5 == 3)
			{
				grades[i] += 2;
				newgrades.push_back(grades[i]);
			}
			else if (grades[i] % 5 == 4)
			{
				grades[i] += 1;
				newgrades.push_back(grades[i]);
			}
			else
			{
				newgrades.push_back(grades[i]);
			}
			
		}
		else
		{
			newgrades.push_back(grades[i]);
		}
	}
	return newgrades;
}

int main()
{	
	vector<int>grades;
	
	vector<int>newgrades = gradingStudents(grades);
	for (int i = 0; i < newgrades.size(); i++)
	{
		cout << newgrades[i] << endl;
	}
	return 0;
}

