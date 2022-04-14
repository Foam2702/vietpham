#include <iostream>
#include <list>
using namespace std;
// Khai báo Bảng Băm
struct Hash {
	int slots; // số ô nhớ of bảng băm
	list<int>* htable;
};
// Cài đặt các phương thức of Bảng Băm
/* Hàm băm */
int hashFunc(Hash& h, int x) {
	return (x % h.slots);
}
/* Hàm thêm 1 phan tu x vao bang bam */
void insertItem(Hash& h, int x) {
	int index = hashFunc(h, x);
	h.htable[index].push_back(x);
}
/* Hàm tìm 1 phan tu co khóa cho trước */
list<int>::iterator searchItem(Hash h,int key) {
	int index = hashFunc(h, key);

	list<int>::iterator i;
	for (i = h.htable[index].begin(); i != h.htable[index].end(); i++) {
		if (*i == key)
			return i;
	}
}

/* Hàm kiểm tra 1 phan tu có tren bảng băm hay không */
bool searchItem_2(Hash h,int key) {
	int index = hashFunc(h, key);

	list<int>::iterator i;
	for (i = h.htable[index].begin(); i != h.htable[index].end(); i++) {
		if (*i == key)
			return true;
	}
	return false;
}


/* Hàm in Bảng Băm */
void displayHT(Hash h) {
	for (int i = 0; i < h.slots; i++) {
		cout << i;
		for (auto x : h.htable[i]) {
			cout << "-->" << x;

		}
		cout << endl;
	}
	cout << endl;
}
/* Hàm xóa 1 node khỏi bảng băm */
void deleteItem(Hash& h,int key) {
	int index = hashFunc(h, key);
	list<int>::iterator i;
	for (i = h.htable[index].begin(); i != h.htable[index].end(); i++) {
		if (*i == key)
			break;
	}
	if (i != h.htable[index].end())
	{
		h.htable[index].erase(i);
		cout << "Bang bam sau khi xoa " << endl;;
		displayHT(h);
	}
	else {
		cout << "Khong co phan tu trong bang bam"<<endl;
	}
}

int main() {
	Hash h;
	int arr[] = { 5,18,3,7,20 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int del,find;
	h.slots = size ;
	h.htable = new list <int>[h.slots];
	for (int i = 0; i < size; i++) {
		insertItem(h, arr[i]);
	}
	displayHT(h);

	cout << "Nhap phan tu muon tim:"; cin >> find;
	if (searchItem_2(h, find)) {
		cout << "Co phan tu trong bang bam" << endl;
	}
	else {
		cout << "Khong co phan tu trong bang bam"<<endl;
	}
	cout << "Nhap phan tu muon xoa :"; cin >> del;
	deleteItem(h, *searchItem(h, del));

}