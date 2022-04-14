// 20120155

#include<iostream>
#include<time.h>
#include<vector>
using namespace std;

void init_Random_arr(int* arr, int n) {
    int left = 0;
    int right = 100;
    srand(time(0)); //seed random
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (right - left + 1) + left;
    }
}
void export_Arr(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//Selection Sort
void selection_Sort(int* arr, int n){
    int min = 0;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}
//Insertion Sort
void insertion_Sort(int* arr, int n) {
    int pos, x;
    for (int i = 1; i < n; i++) {
        x = arr[i];
        pos = i - 1;
        while (pos >= 0 && arr[pos] >= x) {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = x;

    }
}
//Bubble Sort
void bubble_Sort(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > i; j--) {
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
		}
	}
}
//Shaker Sort
void shaker_Sort(int* arr, int n)
{
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	while (Left < Right)
	{
		for (int i = Left; i < Right; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int i = Right; i > Left; i--)
		{
			if (arr[i] < arr[i - 1])
			{
				swap(arr[i], arr[i - 1]);
				k = i;
			}
		}
		Left = k;
	}
}
//Shell Sort
void shell_Sort(int* arr, int n) {
	int interval, i, j, temp;
	for (interval = n / 2; interval > 0; interval /= 2) {
		for (i = interval; i < n; i++) {
			temp = arr[i];
			for (j = i; j >= interval && arr[j - interval] > temp; j -= interval) {
				arr[j] = arr[j - interval];
			}
			arr[j] = temp;
		}
	}
}
//Quick Sort
int partition(int* arr, int low, int high)
{
	int pivot = arr[high];    // pivot
	int left = low;
	int right = high - 1;
	while (true) {
		while (left <= right && arr[left] < pivot) left++; // Tìm phần tử >= arr[pivot]
		while (right >= left && arr[right] > pivot) right--; // Tìm phần tử <= arr[pivot]
		if (left >= right) break; // Đã duyệt xong thì thoát vòng lặp
		swap(arr[left], arr[right]); // Nếu chưa xong, đổi chỗ.
		left++; // Vì left hiện tại đã xét, nên cần tăng
		right--; // Vì right hiện tại đã xét, nên cần giảm
	}
	swap(arr[left], arr[high]);
	return left; // Trả về chỉ số sẽ dùng để chia đổi mảng
}

void quick_Sort(int* arr, int low, int high)
{
	if (low < high)
	{
		/* pi là chỉ số nơi phần tử này đã đứng đúng vị trí
		 và là phần tử chia mảng làm 2 mảng con trái & phải */
		int pi = partition(arr, low, high);

		// Gọi đệ quy sắp xếp 2 mảng con trái và phải
		quick_Sort(arr, low, pi - 1);
		quick_Sort(arr, pi + 1, high);
	}
}
//Merge Sort
void merge(int *arr, int const left, int const mid, int const right)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	
	auto* leftArray = new int[subArrayOne],
		* rightArray = new int[subArrayTwo];

	
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = arr[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = arr[mid + 1 + j];

	auto indexOfSubArrayOne = 0, 
		indexOfSubArrayTwo = 0; 
	int indexOfMergedArray = left; 

	
	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
			arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	
	while (indexOfSubArrayOne < subArrayOne) {
		arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	
	while (indexOfSubArrayTwo < subArrayTwo) {
		arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
}


void merge_Sort(int *arr, int const begin, int const end)
{
	if (begin >= end)
		return; 

	auto mid = begin + (end - begin) / 2;
	merge_Sort(arr, begin, mid);
	merge_Sort(arr, mid + 1, end);
	merge(arr, begin, mid, end);
}
//Binary Insertion Sort
int binary_Search(int* arr, int left, int right, int x)
{

	if (right <= left)
		return(x > arr[left]) ? (left + 1) : left;

	int mid = (left + right) / 2;

	if (arr[mid] == x)
		return mid + 1;

	else if (arr[mid] > x)
	{
		return binary_Search(arr, left, mid - 1, x);
	}
	else return binary_Search(arr, mid + 1, right, x);


}

void binaryinsertion_Sort(int* arr, int n)
{
	int key = 0, pos = 0, newpos = 0;
	int size = n;
	for (int i = 1; i < size; i++)
	{
		key = arr[i];
		pos = i - 1;
		newpos = binary_Search(arr, 0, pos, key);
		while (pos >= newpos)
		{
			arr[pos + 1] = arr[pos];
			pos--;
		}
		arr[pos + 1] = key;

	}

}
//Radix Sort
int getMax(int* arr, int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

void countSort(int* arr, int n, int exp)
{
	int* output = new int[n];
	int i, count[1000] = {};

	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;


	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];


	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}


	for (i = 0; i < n; i++)
		arr[i] = output[i];
}


void radix_Sort(int* arr, int n)
{

	int m = getMax(arr, n);


	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}
//Heap Sort
void sift(int* arr, int left, int right)// xây dựng heap
{
	int i = left;
	int j = i * 2 + 1;
	int x = arr[i];
	while (j <= right)
	{
		if (j < right)
		{
			if (arr[j] <= arr[j + 1])
				j++;
		}
		if (x >= arr[j]) break;
		else
		{
			arr[i] = arr[j];
		}
		i = j;
		j = i * 2 + 1;
	}
	arr[i] = x;

}

void Heapivfy(int* arr, int n)// đưa phần tử vào heap
{
	int left = (n / 2) - 2;
	while (left >= 0)
	{
		sift(arr, left, n);
		left--;
	}
}

void heap_Sort(int* arr, int n)//sắp xếp tăng dần
{

	Heapivfy(arr, n);
	for (int j = n - 1; j >= 0; j--)
	{
		swap(arr[0], arr[j]);

		sift(arr, 0, j - 1);
	}


}
//Interchange Sort
void interchange_Sort(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				swap(arr[i], arr[j]);
			}
		}
	}
}


int main() {
    int n ;
    int* arr; 
    double time_use;
    clock_t start, end;
   
    
    cout << "Nhap so luong phan tu (>=200.000) :"; cin >> n;
    arr = new int[n];
    

    //Thời gian chạy của Selection Sort
	init_Random_arr(arr, n);
    start = clock();
    selection_Sort(arr,n);
    end = clock();
    time_use = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Thoi gian chay selection sort : " << time_use << endl;
	
    
    //Thời gian chạy của Insertion Sort
	init_Random_arr(arr, n);
    start = clock();
    insertion_Sort(arr, n);
    end = clock();
    time_use = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Thoi gian chay insertion sort : " << time_use << endl;

	
	//Thời gian chạy của Bubble Sort
	init_Random_arr(arr, n);
	start = clock();    
	bubble_Sort(arr, n);  
	end = clock();  
	time_use = (double)(end - start) / CLOCKS_PER_SEC;   
	cout << "Thoi gian chay bubble sort : " << time_use << endl;
	

	//Thời gian chạy của Shaker Sort
	init_Random_arr(arr, n);
	start = clock();     
	shaker_Sort(arr, n);  
	end = clock();  
	time_use = (double)(end - start) / CLOCKS_PER_SEC;   
	cout << "Thoi gian chay shaker sort : " << time_use << endl;
	

	//Thời gian chạy của Shell Sort
	init_Random_arr(arr, n);
	start = clock();     
	shell_Sort(arr, n); 
	end = clock(); 
	time_use = (double)(end - start) / CLOCKS_PER_SEC;   
	cout << "Thoi gian chay shell sort : " << time_use << endl;
	

	//Thời gian chạy của Quick Sort
	init_Random_arr(arr, n);
	start = clock();    
	quick_Sort(arr, 0, n - 1); 
	end = clock();  
	time_use = (double)(end - start) / CLOCKS_PER_SEC;    
	cout << "Thoi gian chay quick sort : " << time_use << endl;
	

	//Thời gian chạy của Merge Sort
	init_Random_arr(arr, n);
	
	start = clock();     
	merge_Sort(arr, 0, n - 1);
	end = clock();  
	time_use = (double)(end - start) / CLOCKS_PER_SEC;    
	cout << "Thoi gian chay merge sort: " << time_use << endl;
	
	

	//Thời gian chạy của Binary Insertion Sort
	init_Random_arr(arr, n);
	start = clock();     
	binaryinsertion_Sort(arr, n);  
	end = clock(); 
	time_use = (double)(end - start) / CLOCKS_PER_SEC;    
	cout << "Thoi gian chay binary insertion sort : " << time_use << endl;
	

	//Thời gian chạy của Radix Sort
	init_Random_arr(arr, n);
	start = clock();   
	radix_Sort(arr, n);
	end = clock();  
	time_use = (double)(end - start) / CLOCKS_PER_SEC;    
	cout << "Thoi gian chay radix sort : " << time_use << endl;
	

	//Thời gian chạy của Heap Sort
	init_Random_arr(arr, n);
	start = clock();     
	heap_Sort(arr, n);  
	end = clock();  
	time_use = (double)(end - start) / CLOCKS_PER_SEC;    
	cout << "Thoi gian chay heap sort : " << time_use << endl;


	//Thời gian chạy của Interchange Sort
	init_Random_arr(arr, n);
	start = clock();
	interchange_Sort(arr, n);
	end = clock();
	time_use = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Thoi gian chay interchange sort : " << time_use << endl;


	delete[]arr;
    
	
    
	
}