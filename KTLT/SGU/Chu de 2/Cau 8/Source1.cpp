//#include<iostream>
//#include<string>
//using namespace std;
//
//void xoa(char *a)
//{
//	int l, p;
//	cout << "l=";
//	cin >> l;
//	cout << "p=";
//	cin >> p;
//
//	int n = strlen(a);
//	for (int j = 0; j < l; j++)
//	{
//		for (int i = p; i < n; i++)
//		{
//			a[i] = a[i + 1];
//			
//		}
//	}
//	
//	a[strlen(a)] = '\0';
//}
//
//int main()
//{	
//	char a[100];
//	cout << "Nhap chuoi:";
//	cin.getline(a,100);
//	int n = strlen(a);
//	char* str = new char[n];
//	str = a;
//	xoa(str);
//	cout << str << endl;
//	system("pause");
//}

#include<iostream>
#include<string>
using namespace std;

int main()
{
	int l,p;
	string c1 = "0123456789";
	char* c2 = new char[10];
	for (int i = 0; i < 10; i++)
	{
		c2[i] = '0' + i;
	}
	cout << c1 << endl;
	cout << "Nhap l:";
	cin >> l;
	cout << "Nhap p:";
	cin >> p;
	
	// Dùng string
	//cout << "C1:" << c1.erase(p,l) << endl;
	
	
	// Dùng new của C++
	char* newC2 = new char[10 - l];
	for (int i = 0, i1 = 0; i < 10 ; i++)
	{
		if (i != p)
		{
			newC2[i1] = c2[i];
			i1++;
		}
	}
	delete[]c2;
	c2 = newC2; 
	cout << "C2:";
	for (int i = 0; i < 10-l; i++)
	{
		cout << c2[i];
	}
	cout << endl;
}