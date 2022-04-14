#include<iostream>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};
typedef node* tree;
node* initnode(int value)
{
	node* p = new node;
	p->data = value;
	p->left = NULL;
	p->right = NULL;
	return p;
}
void insert(tree&root, int value){
	if (root== NULL){
		node* p = initnode(value);
		root = p;
	}
	else{
		if (value < root->data) {
			insert(root->left, value);
		}
		else {
			insert(root->right, value);
		}
		
		
	}
}
void inorder_search(tree root){ //lnr
	if (root != NULL) {
		inorder_search(root->left);
		cout << root->data <<" ";
		inorder_search(root->right);
	}
	cout << endl;
}
void preorder_search(tree root){ //nlr
	if (root != NULL) {
		cout << root->data << " ";
		preorder_search(root->left);
		preorder_search(root->right);
	}
	cout << endl;
}
void postorder_search(tree root) { //lrn
	if (root != NULL) {
		
		preorder_search(root->left);
		preorder_search(root->right);
		cout << root->data << " ";
	}
	cout << endl;
}

bool is_leafnode(tree root) {
	if (root->right == NULL && root->left == NULL)
		return true;
	return false;
}
int count_leafnode(tree root) {
	if (root == NULL)
		return 0;
	if (is_leafnode(root))
		return 1;
	return count_leafnode(root->left) + count_leafnode(root->right);
}
int main(){
	int n, value;
	tree root = NULL;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> value;
		insert(root, value);
	}
	/*inorder_search(root);
	preorder_search(root);
	postorder_search(root);*/
	cout << count_leafnode(root);
}
