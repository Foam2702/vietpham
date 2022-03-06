#include <iostream>
using namespace std;
typedef struct node* reff;
struct node {
	int key;
	reff next;
};
reff getNode(int k) {
	reff p;
	p = (reff)malloc(sizeof(struct node));
	if (p == NULL) {
		cout<<"Loi" ; exit(0);
	}
	p->key = k;
	p->next = NULL;
	return p;
}
bool tang(int a, int b) {
	return a < b;
}
bool giam(int a, int b) {
	return a > b;
}
void makeOrderedList(reff h, int k, bool (*sosanh)(int a,int b)) {
	reff p1 = h, p2 = p1->next;
	while (p2 && sosanh(p2->key,k)) {
		p1 = p2; p2 = p1->next;
	}
	reff p = getNode(k);
	p1->next = p; p->next = p2;
}
void printList(reff head) {
	reff p;
	if (head == NULL) return;
	else {
		for (p = head; p != NULL; p = p->next)
			cout << p->key << " ";
	}
}
void destroyList(reff& head) {
	reff p;
	if (head == NULL) return;
	while (head) {
		p = head;
		head = head->next;
		free(p);
	}
}
int main(){
	reff head = new node;
	if (head != NULL)head->next = NULL;
	int k;
	int n = 1;
	cout << "___________Menu___________" << endl;
	cout << "1. Tang " << endl;
	cout << "2. Giam" << endl;
	cin >> k;
	while (true)
	{
		if (k == 1)
		{
			while (n != 0) {
				cout << "Nhap n: ";
				cin >> n;
				if (n == 0) break;
				makeOrderedList(head, n,tang);
				printList(head->next);
				cout << endl;
			}
			break;
		}
		if (k == 2)
		{
			while (n != 0) {
				cout << "Nhap n: ";
				cin >> n;
				if (n == 0) break;
				makeOrderedList(head, n,giam);
				printList(head->next);
				cout << endl;
			}
			break;
		}
	}
	destroyList(head);
}