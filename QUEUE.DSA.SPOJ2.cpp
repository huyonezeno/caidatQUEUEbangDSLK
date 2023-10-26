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
	node *p=new node;
	if (!isEmpty(q)) {
		p=q.front;
		q.front = q.front->next;
	       delete p;
	}
}
void Input(queue& q, int n) {
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		node* p;
		p = CreateNode(x);
		push(q, p);
	}
}
void Output(queue q) {
	for (node* p = q.front; p != NULL; p = p->next){
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

