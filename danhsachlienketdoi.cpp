#include <iostream>
using namespace std;

struct node {
    int data;
    node* next; // địa chỉ node sau
    node* prev; // địa chỉ node trước
};

node* makeNode(int x) {
    node* newNode = new node;
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void duyet(node* head) {
    while (head != NULL) {
        cout << head->data << ' ';
        head = head->next;
    }
    cout << endl;
}

int size(node* head) {
    int cnt = 0;
    while (head != NULL) {
        ++cnt;
        head = head->next;
    }
    return cnt;
}

void themdau(node*& head, int x) {
    node* newNode = makeNode(x);
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

void themcuoi(node*& head, int x) {
    node* newNode = makeNode(x);
    if (head == NULL) {
        head = newNode;
        return;
    }
    node* tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    // tmp->next lưu địa chỉ của node mới ở phần next
    tmp->next = newNode;
    newNode->prev = tmp;
}

void themgiua(node*& head, int x, int k) {
    node *newNode = makeNode(x);
    int n = size(head);
    if(k == 1){
    	themdau(head, x);
    	return;
	}
    if (k < 1 || k > n) return;
    node* tmp = head;
    for (int i = 1; i <= k - 1; i++) {
        tmp = tmp->next;
    }
    // newNode trỏ next vào địa chỉ của node thứ k
    newNode->next = tmp;
    // cho node k - 1 trỏ vào newNode
    tmp->prev->next = newNode;
    // cho phần prev của newNode trỏ vào node k - 1
    newNode->prev = tmp->prev;
    // tmp trỏ vào newNode
    tmp->prev = newNode;
}

void xoadau(node *&head)
{
	if(head == NULL) return ;
	node *deleteNode = head;
	head = head->next;
	if(head != NULL){
		head->prev = NULL;
	}
	delete deleteNode;
}

void xoacuoi(node *&head){
	if(head == NULL) return;
	node *tmp = head;
	if(head->next == NULL){
		head = NULL;
		delete tmp;
		return;
	}
	while(tmp->next != NULL){
		tmp = tmp->next;
	}
	// tmp
	node *deleteNode = tmp;
	tmp->prev->next = NULL;
	delete deleteNode;
}

void xoagiua(node *&head,  int k){
	int n = size(head);
	if(k < 1 || k > n) return ;
	if( k == 1) xoadau(head);
	else {
		node *tmp = head;
		for(int i = 1; i <= k - 1; i++){
			tmp = tmp->next;
		}
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		delete tmp;
	}	
}

void sx(node *&head){
	for(node *i = head; i != NULL; i = i->next){
		node *min = i;
		for(node *j = i->next; j != NULL;j= j->next){
			if(min->data > j->data){
				min = j;
			}
		}
		swap(min->data, i->data);
	}
}

int main() {
    node* head = NULL;
	while(1){
		cout << "--------------MENU------------------\n";
		cout << "1. Chen phan tu vao dau danh sach" << endl;
		cout << "2. Chen phan tu vao cuoi danh sach" << endl;
		cout << "3. Chen phan tu vao giua danh sach" << endl;
		cout << "4. Xoa phan tu o dau" << endl;
		cout << "5. Xoa phan tu o cuoi" << endl;
		cout << "6. Xoa phan tu o giua" << endl;
		cout << "7. Duyet danh sach" << endl;
		cout << "0. Thoat" << endl;
		cout << "---------------------------------------;" << endl;
		cout << "Nhap lua chon: ";
		int lc ; cin >> lc;
		if(lc == 1){
			int x; cout << "Nhap gia tri can chen: "; cin >> x;
			themdau(head, x);
		}
		else if(lc == 2){
			int x; cout << "Nhap gia tri can chen: "; cin >> x;
			themcuoi(head,x);
		}
		else if( lc == 3){
			int x; cout << "Nhap gia tri can chen :"; cin >> x;
			int pos; cout << "Nhap vi tri chan chen"; cin >> pos;
			themgiua(head,x ,pos);
		}
		else if(lc == 4){
			xoadau(head);
		}
		else if(lc == 5){
			int pos; cout << "Nhap vi tri chan xoa"; cin >> pos;
			xoagiua(head,pos);
		}
		else if(lc == 6){
			int pos; cout << "Nhap vi tri chan xoa"; cin >> pos;
			xoacuoi(head);
		} 
		else if(lc == 7){
			duyet(head);
		} else if(lc == 0){
			break;
		}
	}
	return 0;
}

