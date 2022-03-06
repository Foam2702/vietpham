#include<iostream>
#include<string>
#include<vector>
using namespace std;

void convertime(string s)
{
	string hour, minute, second,nature;
	hour = s.substr(0, 2);
	minute = s.substr(3, 2);
	second = s.substr(6, 2);
	nature = s.substr(8);
	if (nature == "PM" && hour!="12")
	{
		int num_hour = stoi(hour); //hàm chuyển string sang int
		num_hour += 12;
		cout << hour << ":" << minute << ":" << second;
			
	}
	else if(nature=="AM"&&hour=="12")
	{
		hour[0] = '0';
		hour[1] = '0';
		cout << hour << ":" << minute << ":" << second;
	}
	else {
		cout << hour << ":" << minute << ":" << second;
	}
}
int main()
{	
	string s;
	getline(cin, s);
	convertime(s);

}