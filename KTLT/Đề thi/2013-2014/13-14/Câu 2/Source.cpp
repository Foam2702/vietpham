#include<iostream>
using namespace std;

struct Nguoi
{
	char* hoten;
	int tuoi;
	Nguoi* cha;
	Nguoi* me;
};

int TimtuoiLonNhat(Nguoi* nguoi,int n)
{	
	if (n == 0)
	{
		return nguoi[0].tuoi;
	}
	else if(nguoi[n - 1].tuoi > TimtuoiLonNhat(nguoi, n - 1))
	{
		return nguoi[n - 1].tuoi;
	}
	
	return TimtuoiLonNhat(nguoi, n - 1);
	
	
}


int main()
{	
	int n; cin >> n;
	Nguoi* nguoi = new Nguoi[n];
	for (int i = 0; i < n; i++)
	{
		cin >> nguoi[i].tuoi;
	}
	
	int max=TimtuoiLonNhat(nguoi, n);
	cout << max;
	return 0;

}