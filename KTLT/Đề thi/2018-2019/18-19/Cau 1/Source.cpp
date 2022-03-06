#include<iostream>
#include<string>
using namespace std;

int tongSoNguyen(const char* s)
{	
	int sum=0,num=0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')//gộp các chữ số gần nhau thành 1 số
		{
			num = num * 10 + (s[i]-'0');
			
		}
		
		else
		{
			sum += num;
			num = 0;
		}

	}
	return sum + num;//tổng các số trc đó và số cuối cùng
}

int main()
{
	char s[100];
	cout << "Nhap chuoi:";
	cin.getline(s, 100);
	int sum = tongSoNguyen(s);
	cout << sum;

}