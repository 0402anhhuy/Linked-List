#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

typedef struct Node* node;

// Cap phat dong mot node voi du lieu la so nguyen x
node makeNode(int x){
	node tmp = new Node();
	tmp -> data = x;
	tmp -> next = NULL;
	return tmp;
}

// Kiem tra rong
bool empty(node a){
	return a == NULL;
}

//Dem so luong phan tu
int Size(node a){
	int cnt = 0;
	while(a != NULL){
		cnt++;
		a = a -> next; // Gan dia chi cua node tiep theo cho node hien tai
	}
	return cnt;
}

// Them 1 phan tu vao dau danh sach lien ket
void insertFirst(node &a, int x){
	node tmp = makeNode(x);
	/* Kiem tra neu ds khong co nut nao 
		- True: tmp tro thanh head
	*/
	if(a == NULL) a = tmp;
	else{
		tmp -> next = a;
		a = tmp;
	}
}

// Them 1 phan tu vao cuoi danh sach
void insertLast(node &a, int x){
	node tmp = makeNode(x);
	if(a == NULL) a = tmp;
	else{
		// Tao 1 node tro den phan tu dau ti�n cua ds
		node p = a;
		// Duyet ds
		while(p -> next != NULL){
			p = p -> next;
		}
		p -> next = tmp;
	}
}

// Them 1 phan tu vao giua danh sach
void insertMiddle(node &a, int x, int pos){
	int n = Size(a);
	if(pos <= 0 || pos > n + 1){
		cout << "Vi tri chen khong hop le!\n";
	}
	if(n == 1){
		insertFirst(a, x);
		return;
	}
	else if(n == pos + 1){
		insertLast(a, x);
		return;
	}
	node p = a;
	for(int i = 1; i < pos - 1; i++){
		p = p -> next;
	}
	node tmp = makeNode(x);
	tmp -> next = p -> next;
	p -> next = tmp;
}

// Xoa phan tu o dau
void deleteFirst(node &a){
	if(a == NULL) return;
	node p = a;
	p = p -> next;
	delete(p);
}

// Xoa phan tu o cuoi
void deleteLast(node &a){
	if(a == NULL) return;
	node truoc = NULL, sau = a;
	while(sau -> next != NULL){
		truoc = sau; // La node sat node cuoi cung
		sau = sau -> next;
	}
	if(truoc == NULL){
		a == NULL;
	}
	else{
		truoc -> next = NULL;
		delete(sau -> next);
	}
}

// Xoa phan tu o giua
void deleteMiddle(node &a, int pos){
	int n = Size(a);
	if(pos <= 0 || pos > n + 1) return;
	node truoc = NULL, sau = a;
	for(int i = 1; i < pos - 1; i++){
		truoc = sau;
		sau = sau -> next;
	}
	if(truoc == NULL){
		a = a -> next;
	}
	else{
		truoc -> next = sau -> next;
	}
}

void print(node a){
	while(a != NULL){
		cout << a -> data << " ";
		a = a -> next;
	}
	cout << endl;
}

void sapxep(node &a){
	for(node p = a; p -> next != NULL; p = p -> next){
		node min = p;
		for(node q = p -> next; q != NULL; q = q -> next){
			if(q -> data < min -> data){
				min = q;
			}
		}
		swap(p -> data, min -> data);
	}
}

int main(){
	node head = NULL;
	while(1){
		cout << "------------------MENU-------------------\n";
		cout << "1. Chen phan tu vao dau danh sach\n";
		cout << "2. Chen phan tu vao cuoi danh sach\n";
		cout << "3. Chen phan tu vao giua danh sach\n";
		cout << "4. Xoa phan tu o dau\n";
		cout << "5. Xoa phan tu o cuoi\n";
		cout << "6. Xoa phan tu o giua\n";
		cout << "7. Duyet danh sach lien ket\n";
		cout << "8. Sap xep danh sach lien ket\n";
		cout << "0. Thoat\n";
		cout << "-----------------------------------------\n";
		cout << "Nhap lua chon: ";
		int option; cin >> option;
		if(option == 1){
			int x;
			cout << "Nhap gia tri can chen: "; cin >> x;
			insertFirst(head, x);
		}
		else if(option == 2){
			int x;
			cout << "Nhap gia tri can chen: "; cin >> x;
			insertLast(head, x); 
		}
		else if(option == 3){
			int x, pos;
			cout << "Nhap gia tri can chen: "; cin >> x;
			cout << "Nhap vi tri can chen: "; cin >> pos;
			insertMiddle(head, x, pos);
		}
		else if(option == 4){
			deleteFirst(head);
		}
		else if(option == 5){
			deleteLast(head);
		}
		else if(option == 6){
			int pos;
			cout << "Nhap vi tri can xoa: "; cin >> pos;
			deleteMiddle(head, pos);
		}
		else if(option == 7){
			print(head);
		}
		else if(option == 8){
			sapxep(head);
			print(head);
		}
		else{
			cout << "Thoat";
			break;
		}
	}
	return 0;
}
