#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

void fReadFileArr (string FileName,int arr[],int size) {
	ifstream in;
	if (in.is_open()) {
		in.close();
	}
	in.open(FileName,ios_base::in);
	if (in.is_open()) {
		cout << "CONNECTION SUCCESSFULL";
		for (int i = 0; i < size; i++) {
			in >> arr[i];
		}
	}
	in.close();
	
}
void fWriteFileArr(string FileName,int arr[],int size) {
	ofstream out;
	if (out.is_open()) {
		out.close();
	}
	out.open(FileName, ios_base::out);
	if (out.is_open()) {
		
		for (int i = 0; i < size-1 ; i++) {
			out << arr[i] << " ";
		}
		out << arr[size - 1];
		
	}
	out.close();
}
void Pushback_arr_to_flexarr(string FileName,vector<int>&flexarr, int arr[],int size) {

	for (int i = 0; i < size; i++) {
		flexarr.push_back(arr[i]);
	}
	ofstream out;
	if (out.is_open()) {
		out.close();
	}
	out.open(FileName,ios_base::out);
	if (out.is_open()) {
		if (flexarr.empty()) {
			cout << "Mang rong";
		}
		else {
			int length = flexarr.size();
			for (int i = 0; i < length-1; i++) {
				if (flexarr[i] % 2 == 0) {
					out<< flexarr[i]<<" ";
				}
			}
			if (flexarr[size - 1] % 2 == 0) {
				out << flexarr[size - 1];
			}
		}
	}
	out.close();
}
void Write_FlexArr_Decreasing(string FileName,vector<int> &flexarr) {
	ofstream out;
	if (out.is_open()) {
		out.close();
	}
	out.open(FileName,ios_base::out);
	if (out.is_open()) {
		if (flexarr.empty()) {
			cout << "Mang rong";
		}
		else {
			int length = flexarr.size();
			for (int i = 0; i < length-1; i++) {
				for (int j = i + 1; j < length; j++) {
					if (flexarr[i] < flexarr[j]) {
						swap(flexarr[i], flexarr[j]);
						
					}
				}
			}
			for (int i = 0; i < length-1; i++) {
				out << flexarr[i]<<" ";
			}
			out << flexarr[length - 1];
		}
	}
	out.close();
}
int main() {
	int arr[] = {10,15,20,25,30,35,40,50};
	vector<int> flexarr;
	int size = sizeof(arr) / sizeof(arr[0]);
	fWriteFileArr("dayso.txt", arr,size);
	
	fReadFileArr("dayso.txt", arr,size);
	
	Pushback_arr_to_flexarr("daysochan.txt", flexarr, arr,size);
	
	Write_FlexArr_Decreasing("daysodaonguoc.txt", flexarr);
	
	
	return 0;
}