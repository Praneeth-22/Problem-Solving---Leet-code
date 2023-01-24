#include<bits/stdc++.h>
using namespace std;

class node {
	public:
	int data;
	node* nxt;
	
	node(int val){
		//constructor
		data = val;
		nxt = NULL;
	}
};

void insertAtTail(node* &head,int val){
	node* newNode = new node(val); //new node is created with data,nxt pointer
	
	if (head == NULL){
		head = newNode;
		return;
	}
	
	node* iter = head; // pointer to traverse
	while(iter->nxt != NULL){
		iter = iter->nxt;
	}
	iter->nxt = newNode;
	newNode->nxt = NULL;
}

void insertAtHead(node* &head,int val){
	node* newNodeHead = new node(val);//new node is created with data,nxt pointer
	node* iter = head;
	if(iter->nxt != NULL){
		node* temp = newNodeHead;
		temp->nxt = head;
	}
	head = newNodeHead;	
}

bool searchNode(node* head,int val){
	node* iter = head;
	while(iter->nxt != NULL){
		if(iter->data == val){
			return true;
		}
		iter = iter->nxt;
	}	
	return false;
}

void deleteAtHead(node* &head){
	if(head == NULL) return;
	node* iter = head;
	head = head->nxt;
	delete iter;
	cout<<"deleted the start node"<<endl;
}

void deleteNode(node* &head,int val){
	if(head == NULL) return;
	node* iter = head; //pointing to head node;
	if(iter->nxt == NULL){
		deleteAtHead(iter);
	}
	while(iter->nxt->data != val){
		iter = iter->nxt;
	}
	node* temp = iter->nxt;
	iter->nxt = iter->nxt->nxt; 
	delete temp;
	cout<<"deleted:"<<val<<endl;
}

void display(node* head){
	node* iter = head;
	while(iter != NULL){
		int d = iter->data;
		cout<<d<<" ";
		iter = iter->nxt;
	}
	cout<<endl;
}

int main(){
	node* head = NULL;
	
	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtHead(head,4);
	display(head);
	cout<<searchNode(head,2)<<"\n";
	deleteNode(head,2);
	cout<<searchNode(head,2)<<"\n";
	display(head);
	deleteAtHead(head);
	display(head);
	
	return 0;
}
