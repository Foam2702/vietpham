
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<time.h>

using namespace std;

long long chiPhi() {
	return -1;
}

int main() {
	//Bo cmt cac dong duoi day neu ban muon giao tiep chuong trinh thong qua file

	// if (fopen("./input1.txt", "r")) {
	//     freopen("./input1.txt", "r", stdin);
	//     //freopen("./output1.txt", "w", stdout);
	// }

	/* 1. Read the input */
	clock_t start, end;

	int N, Ai, K, Bi, sum = 0, keep;
	vector<int>B;
	priority_queue<int> pq;//maxheap
	//priority_queue<int, vector<int>, greater<int>()> pq; //minhheap
	cin >> N;

	for (int i = 0; i < N; i++)
	{

		cin >> Ai;


		pq.push(Ai);
	}

	cin >> K;

	for (int i = 0; i < K; i++)
	{

		cin >> Bi;
		B.push_back(Bi);
	}
	for (int i = 0; i < B.size(); i++)
	{
		if (B[i] == 1)
		{
			sum += pq.top();
			pq.pop();
		}
		else if (B[i] == 2)
		{
			keep = pq.top();
			pq.pop();
			sum += pq.top();
			pq.pop();
			pq.push(keep);
		}
	}
	cout << sum;

	/* 2. Perform algorithm */

	start = clock();
	//cout << chiPhi();

	end = clock();

	//Luu y rang ban se phai cmt dong duoi day lai khi nop bai, neu khong se bi sai output.

	//cerr << "Execution time: " << ((double)(end - start)) / CLOCKS_PER_SEC << "s";
	return 0;
}