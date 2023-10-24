#include<iostream>
#include <stdlib.h>
using namespace std;
struct node{
	int data;
	node* next;

};
struct queue {
	node* front;
	node* rear;
};
void init(queue &q) {
	q.front = NULL;
	q.rear = NULL;
}
node* CreateNode(int x) {
	node* p;
	p =	new node;
	if (p == NULL) {
		cout << "Khong hop le"<<endl;
	}
	p->data = x;
	p->next = NULL;
	return p;
}
int isEmpty(queue q) {
	if (q.front == NULL) {
		return 1;
	}
	return 0;
}
void push(queue& q, node*newnode) {
	if (q.front == NULL) {
		q.front = newnode;
		q.rear = newnode;
	}
	else {
		q.rear->next = newnode;//dat con tro next cua phan tu cuoi ve NewNode
		q.rear = newnode;//gan lai phan tu cuoi cua danh sach
	}
}
void pop(queue& q) {
	//int y=-1;
	//node* p = NULL;
	if (!isEmpty(q)) {
		//gan node p bang phan tu dau tien cua queue
		//p = q.front;
		//gan du lieu cua node p vao x
		//y = p->data;
		//xoa di node dau tien cua queue
		q.front = q.front->next;
		//delete p;
		//neu front bang NULL thi gan luon rear bang NULL
		if (q.front == NULL) {
			q.rear = NULL;
		}
	}
	//return y;
}
void Input(queue& q, int n) {
	//duyet N lan
	for (int i = 0; i < n; i++) {
		//nhap phan tu vao bien x
		int x;
		cin >> x;
		//tao node p co du lieu la x
		node* p;
		p = CreateNode(x);
		//them node p vao queue
		push(q, p);
	}
}
void Output(queue q) {
	//duyet tu dau den cuoi hang doi
	for (node* p = q.front; p != NULL; p = p->next) {
		//hien thi data cua cac node
		cout << p->data<<" ";
	}
	cout << endl;
}
int main() {
	queue q;
	init(q);
	int n;
	cin >> n;
	Input(q, n);
	pop(q);
	Output(q);
}

