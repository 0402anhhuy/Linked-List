#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node* prev;
};

typedef struct Node* node;

node makeNode(int x){
	node tmp = new Node();
	tmp -> next = NULL;
	tmp -> data = x;
	tmp -> prev = NULL;
	return tmp;
}

int Size(node a){
	int cnt = 0;
	while(a != NULL){
		cnt++;
		a = a -> next;
	}
	return cnt;
}

// Them phan tu vao dau ds lien ket
void insertFirst(node &a, int x){
	node tmp = makeNode(x);
	if(a == NULL) a = tmp;
	else{
		tmp -> next = a;
		a -> prev = tmp;
		a = tmp;
	}
}

// Them phan tu vao cuoi ds lien ket
void insertLast(node &a, int x){
	node tmp = makeNode(x);
	if(a == NULL) a = tmp;
	else{
		node p = a;
		while(p -> next != NULL){
			p = p -> next;
		}
		p -> next = tmp;
		tmp -> prev = p;
	}
}

// Them phan tu vao giua ds lien ket
void insertMiddle(node &a, int x, int pos){
	int n = Size(a);
	if(pos < 0 || pos > n) cout << "Vi tri chen khong hop le\n";
	else if(pos == 0){
		insertFirst(a, x);
		return;
	}
	else if(pos == n){
		insertLast(a, x);
		return;
	}
	else{
		node p = a;
		for(int i = 0; i < pos; i++){
			p = p -> next;
		}
		node tmp = makeNode(x);
		tmp -> next = p;
		p -> prev -> next = tmp;
		tmp -> prev = p -> prev;
		p -> prev = tmp;
	}
}

// Xoa phan tu o dau ds lien ket
void deleteFirst(node &a){
	if(a == NULL) return;
	node tmp = a;
	a = a -> next;
	if(a != NULL){
		a -> prev = NULL;
	}
	delete tmp;
}

// Xoa phan tu o cuoi ds lien ket
void deleteLast(node &a){
	if(a == NULL) return;
	if(a -> next == NULL){
		delete a;
		a = NULL;
		return;
	}
	node p = a;
	while(p -> next != NULL){
		p = p -> next;
	}
	p -> prev -> next = NULL;
	delete p;
}

// Xoa phan tu o giua ds lien ket (xoa o chi so i)
void deleteMiddle(node &a, int pos){
	int n = Size(a);
	if(pos < 0 || pos >= n) cout << "Vi tri xoa khong hop le\n";
	else if(pos == 0){
		deleteFirst(a);
		return;
	}
	else if(pos == n - 1){
		deleteLast(a);
		return;
	}
	else{
		node p = a;
		for(int i = 0; i < pos; i++){
			p = p -> next;
		}
		p -> prev -> next = p -> next;
		p -> next -> prev = p -> prev;
		delete p;
	}
}

void printList(node a){
	while(a -> next != NULL){
		cout << a -> data << " ";
		a = a -> next;
	}
	cout << a -> data;
}

int main(){
	int n, x; cin >> n >> x;
	node First = makeNode(x);
	for(int i = 1; i < n; i++){
		int p; cin >> p;
		insertLast(First, p);
	}
	int a, k; cin >> a >> k;
	insertMiddle(First, a, k);
	deleteFirst(First);
	deleteLast(First);
	int pos; cin >> pos;
	deleteMiddle(First, pos);
	printList(First);
	return 0;
}
