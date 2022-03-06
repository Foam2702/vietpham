#include<iostream>
#include<vector>
using namespace std;

int TinhFn_KhongDeQuy(int a)
{
	int F0 = a, F1 = 2 * a,Fn = 0;
	if (a == 0)
		return F0;
	else if(a == 1)
		return F1;
	else {
		for (int i = 2; i <= a; i++)
		{
			Fn = 2 * F1 + 3 * F0;
			F0 = F1;
			F1 = Fn;
		}
		return Fn;
	}
	
}

int TimChiso(int M)
{
	int i = 0;
	vector<int>arr;
	while (TinhFn_KhongDeQuy(i) > M||TinhFn_KhongDeQuy(i)==M) {
		i++;
	}
	return i;
}
int main()
{
	int a; cin >> a;
	int value=TinhFn_KhongDeQuy(a);
	cout << value;
	return 0;

}