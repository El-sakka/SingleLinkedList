/*Sigle Linked List */
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *next;
};
Node *head = NULL;

// to insert a node at the end of the linkedlist
void InsertEnd(int x) {
	Node * temp = new Node();
	temp->data = x;
	temp->next = NULL;
	if (head == NULL)
		head = temp;
	else {
		Node *temp1 = head;
		while (temp1->next != NULL)
			temp1 = temp1->next;
		temp1->next = temp;
	}
}

// to insert a node at the beginning of the linkedlist
void InsertBeginnig(int x) {
	Node *temp = new Node();
	temp->data = x;
	temp->next = head;
	head = temp;
}

// to insert a node at i-th position in the linkedlist
void InsertPosition(int x, int n) {
	Node *temp1 = new Node();
	temp1->data = x;
	temp1->next = NULL;
	if (n == 1) {
		temp1->next = head;
		head = temp1;
		return;
	}
	Node *temp2 = head;
	for (int i = 0; i < n - 2; i++) {
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
}

// to delete a node from the linked list
void Delete(int n) {
	Node *temp1 = head;
	if (n == 1) {
		head = temp1->next;
		delete temp1;
		return;
	}
	for (int i = 0; i < n - 2; i++) {
		temp1 = temp1->next;
	}
	Node *temp2 = temp1->next;
	temp1->next = temp2->next;
	delete temp2;
}

// Reverse list iterative method
void ReverseList() {
	Node *current, *prev, *Next;
	current = head;
	prev = NULL;
	while (current != NULL) {
		Next = current->next;
		current->next = prev;
		prev = current;
		current = Next;
	}
	head = prev;
}

// Reverse list Recusrion Method
void ReverseRec(Node *p) {
	if (p->next == NULL) // point to last node
	{
		head = p;	// head point to last node
		return;
	}
	ReverseRec(p->next);
	Node *prev = p->next;
	prev->next = p;
	p->next = NULL;
}

// iterative method of print function
void PrintList() {
	Node *temp = head;
	cout << "List is : ";
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n";
}

// Recursion Method for Forward Print function
void PrintFow(Node *p) {
	if (p == NULL)
		return;
	cout << p->data << " ";
	PrintFow(p->next);
}

// Recusion Method for Reverse Print Function
void PrintRev(Node *p) {
	if (p == NULL)
		return;
	PrintRev(p->next);
	cout << p->data << " ";
}

int main() {
	/*int n,x;
	 cout<<"How many number you want to insert \n";
	 cin>>n;
	 for(int i=0;i<n;i++){
	 cout<<"Enter your Number \n";
	 cin>>x;
	 //InsertEnd(x);
	 InsertBeginnig(x);
	 PrintList();
	 }
	 */
	InsertPosition(1, 1);
	InsertPosition(2, 2);
	InsertPosition(3, 3);
	InsertPosition(4, 4);
	InsertPosition(5, 5);
	//InsertPosition(,1);
	PrintFow(head);
	cout << endl;
	PrintRev(head);
	cout << endl;
	ReverseRec(head);
	PrintFow(head);
	cout << endl;
	PrintRev(head);
	cout << endl;

	return 0;
}
