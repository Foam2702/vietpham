#include<iostream>
#include<string>

using namespace std;


int LENGTH(string s)
{
	
	int i = 0;
	while (s[i] != '\0')
	{
		i++;
		
	}
	return i;
}
string Chuanhoa_Chuoi(string s)
{
	int i = 0;//index chuoi ban dau
	int j = 0;//index chuoi ket qua
	string rs;
	while (s[i] == ' ')
	{
		i++;

	}
	rs.push_back(s[i++]);
	j++;
	if (rs[0] >= 'a' && rs[0] <= 'z')
	{
		rs[0] -= 32;
	}
	while (s[i] != '\0')
	{
		if (s[i] != ' ')
		{
			if (s[i - 1] == ' ')
			{	
				rs.push_back(' ');
				j++;
				rs.push_back(s[i]);
				
				if (rs[j] >= 'a' &&rs[j] <= 'z')
				{
					rs[j] -= 32;
				}
				j++;

			}
			else
			{
				rs.push_back(s[i]);
				
				if (rs[j] >= 'A' && rs[j] <= 'Z')
				{
					rs[j] += 32;
				}
				j++;
			}
		}
		i++;
	}
	return rs;
}


int main()
{
	string s = "      viEt  pHaM     ";
	string schuanhoa = Chuanhoa_Chuoi(s);
	
	cout << s << endl;
	cout << schuanhoa;
	
}