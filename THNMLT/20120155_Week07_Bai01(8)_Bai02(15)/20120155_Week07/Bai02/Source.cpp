#include"Header.h"


void Input(int arr[], int& n)
{
	do
	{
		cout << "Nhap so luong phan tu:"; cin >> n;
		if (n <= 0)
		{
			cout << "So luong phan tu phai lon hon 0" << endl;
		}
	} while (n <= 0 );
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

void Output(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void XoaViTri(int arr[], int& n, int k)
{
	for (int i = k ; i < n; i++)
	{
		arr[i] = arr[i + 1];
	}
	n--;
}

void XoakPhantu(int arr[], int& n, int k, int i)
{
	for (int l = 0; l < k; l++)
	{
		for (int j = i; j < n; j++)
		{
			arr[j] = arr[j + 1];
		}
	}
	n -= k;
}

void Dem_In_phanTuKhacnhau(int arr[], int n)
{
	int brr[100], x = 1;
	brr[0] = arr[0];

	for (int i = 1; i < n; i++) 
	{
		int count = 0;
		for (int j = 0; j < x; j++) 
		{
			if (arr[i] == brr[j])
			{
				count++;
			}
		}
		if (count == 0) 
		{
			brr[x] = arr[i];
			x++;
		}
	}
	cout << "So phan tu khac nhau: " << x << endl;
	cout << "Nhung phan tu khac nhau: " << endl;
	Output(brr, x);
	cout << endl;
}

void Dem_In_phanTuKhacnhauTrongDoan(int a[], int n, int x, int y)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		bool check = true;
		for (int j = 0; j < i; j++)
		{
			if (a[i] == a[j])
			{
				check = false;
				break;
			}
		}
		if (check == true && a[i] >= x && a[i] <= y)
		{
			count++;
		}
	}

	cout << "So phan tu khac nhau trong doan: " << count << endl;

}

int phanTu_Lonthu2(int arr[], int n)
{
	int max1 = arr[0], max2 = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (max1 < arr[i])
		{
			max1 = arr[i];
		}
	}

	for (int i = 1; i < n; i++)
	{
		if (arr[i] < max1 && arr[i] > max2 )
		{
			max2 = arr[i];
		}
	}
	return max2;
}

int CountMax(int a[], int n, int x)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			count++;
		}
	}
	return count;
}

int Xuathien_Max(int arr[], int n)
{
	int max = 0,pos = 0;
	int submax = CountMax(arr, n, arr[0]);
	for (int i = 1; i < n; i++)
	{
		max = CountMax(arr, n, arr[i]);
		if (submax < max)
		{
			submax = max;
			pos = i;
		}
	}
	return arr[pos];
}

int timMin_trongDoan(int arr[], int n, int x, int y)
{
	int min = arr[0];
	for (int i = 1; i < n; i++)
	{	
		if (arr[i] >= x && arr[i] <= y)
		{
			if (arr[i] < min)
			{
				min = arr[i];
			}
		}
	}
	return min;
}


int kPhantuLientiep_Max(int arr[], int n, int k)
{
	int max = arr[0], sum = 0, count = 0, submax = 0;
	for (int i = 0; i < n; i++)
	{
		count = k;
		submax = i;
		sum = 0;
		while (count > 0)
		{
			sum += arr[submax];
			submax++;
			count--;
		}
		if (sum > max)
		{
			max = sum;
		}
	}
	return max;
}

void daoNguoc_Mang(int arr[], int n)
{
	for (int i = 0; i < n / 2; i++)
	{
		int temp = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i - 1] = temp;
	}
}

void sapXep_chanle(int a[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if ((a[i] % 2 != 0 && a[j] % 2 == 0) || (a[i] % 2 == 0 && a[j] % 2 == 0 && a[i] > a[j]) || (a[i] % 2 != 0 && a[j] % 2 != 0 && a[i] < a[j]))
				swap(a[i], a[j]);
		}
	}
}

bool check_soChinhphuong(int x)
{
	int sqr = sqrt(x);
	if (sqr * sqr == x)
		return true;
	return false;
}
void sapXep_chinhPhuong_Tangdan(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{	
		if (check_soChinhphuong(arr[i]))
		{
			for (int j = i + 1; j < n; j++)
			{
				if (check_soChinhphuong(arr[j]))
				{
					if (arr[i] > arr[j])
						swap(arr[i], arr[j]);
				}
			}
		}
		
	}
}
void doiCho_2doan_mangMoi(int arr[], int &n, int &m)
{	
	int i = 0;
	int count1 = 0, count2 = 0;
	int k = n - 1;
	while (i < m  && k >= m)
	{
		swap(arr[i], arr[k]);
		i++; k--;
	}
	for (int i = 0; i < m; i++)
	{
		count1++;
	}
	for (int j = m; j < n; j++)
	{
		count2++;
	}
	if (count1 > count2)
	{
		m = m - (count1-count2) ;

	}
	else if (count1 < count2)
	{
		m = m + (count2-count1) ;
	}
	

	for (int i = 0; i < m - 1; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);
		}
	}
	for (int i = m; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);
		}
	}
	
}

bool check_Increasing(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
		if (arr[i] > arr[i + 1])
			return false;
	return true;
}

bool check_Decreasing(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
		if (arr[i] < arr[i + 1])
			return false;
	return true;
}

void check_IncreasingLienTuc(int arr[], int n)
{
	int k = 1;
	int max = 1;
	int dau = 0;
	int cuoi = 0;

	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] < arr[i + 1])
		{
			k++;
			if (k > max)
			{
				max = k;
				dau = i + 2 - k;
				cuoi = i + 2;
			}

		}
		else
			k = 1;
	}
	for (int i = dau; i < cuoi; i++)
		cout << arr[i] << " ";
}

void DayConTangLienTiep(int arr[], int n)
{	
	bool check = true;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (arr[i] < arr[j])
				cout << arr[i] << " " << arr[j];
			
		}
		cout << endl;
	}
}

bool SoNguyenTo(int x)
{
	if (x < 2)
		return false;
	for (int i = 2; i <= x / 2; i++)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}

int SoNguyenToNhoNhat(int arr[], int n)
{
	int min = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (min > arr[i] && SoNguyenTo(arr[i]))
			min = arr[i];
	}
	return min;
}
