#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* pnext;
};

struct Hash {
	int slots;
	Node** htable;
};

Node* init_Node(int value) {
	Node* p = new Node;
	if (p == NULL) {
		cout << "NOT ENOUGH MEMORY" << endl;
	}
	else {
		p->data = value;
		p->pnext = NULL;
	}
	return p;
}
int hashFunc(Hash& h, int x) {
	return (x % h.slots);
}

void init_Hash(Hash& h) {
	h.htable = new Node * [h.slots];
	for (int i = 0; i < h.slots; i++) {
		h.htable[i] = NULL;
	}
}
/* Hàm thêm 1 phan tu x vao bang bam */
void insert_Item(Hash& h, int value) {
	Node* p = init_Node(value);
	
	int index = hashFunc(h, value);
	if (h.htable[index] == NULL) {
		h.htable[index] = p;
	}
	else {
		Node* q = h.htable[index];
		while (q->pnext) {
			q = q->pnext;
		}
		q->pnext = p;
	}
	
}
bool search_Item2(Hash h, int key) {
	int index = hashFunc(h, key);
	Node* p = h.htable[index];
	while (p != NULL && p->data != key)
		p = p->pnext;
	if (p == NULL)
		return NULL;
	if (p != NULL)
		return true;
	else
		return false;
}

void displayHT(Hash h) {
	for (int i = 0; i < h.slots; i++) {
		cout << i;
		if (h.htable[i]) {
			Node* g;
			g = h.htable[i];
			while (g) {
				cout << "-->" << g->data;
				g = g->pnext;
			}
		}
		cout << endl;
	}
	
}
void DeleteHead(Node*& l)
{
	if (l != NULL)
	{
		Node* p = l;
		l = l->pnext;
		delete p;
	}
}

void DeleteAfter(Node*& q)
{
	Node* p = q->pnext;
	if (p != NULL)
	{
		q->pnext = p->pnext;
		delete p;
	}
}
void DeleteNode(Hash &h, int k)
{
	int i = hashFunc(h,k);
	Node* p = h.htable[i];
	Node* q = p;
	while (p != NULL && p->data != k)
	{
		q = p; 
		p = p->pnext;
	}
	if (p == NULL)
		cout << "Khong tim thay phan tu de xoa" << endl;
	else if (p == h.htable[i])
		DeleteHead(h.htable[i]); 
	else
		DeleteAfter(q); 
}

/* Hàm in Bảng Băm */

void free_Hash(Hash& h) {
	for (int i = 0; i < h.slots; i++) {
		delete h.htable[i];
	}
	delete[]h.htable;
}
int main() {
	Hash h;
	int n,value,del,find;
	cout << "Nhap so luong phan tu:"; cin >> n;
	h.slots = n;
	init_Hash(h);
	for (int i = 0; i < h.slots; i++) {
		cout << "Gia tri:"; cin >> value;
		insert_Item(h, value);
	}
	displayHT(h);
	/////////////////////////
	cout << "Nhap phan tu muon xoa:"; cin >> del;
	DeleteNode(h, del);
	displayHT(h);
	/////////////////////////
	cout << "Nhap phan tu can tim:"; cin >> find;
	if (search_Item2(h, find)) {
		cout << "Tim thay phan tu" << endl;
	}
	else {
		cout << "Khong tim thay phan tu";
	}
	free_Hash(h);
	
	
}