#include<iostream>
using namespace std;

//struct SINHVIEN
//{
//	char MaSV[10];
//	char Hodem[20];
//	char Ten[10];
//	char GT[10];
//	int Namsinh;
//	float DiemTK;
//};
struct Node{
	int data;
	Node *next;
};
typedef struct Node Node;// ko phai khai bao struc nhieu lan nua chi can dung Node la duoc
 Node *makeNode(int x){
 	Node *newNode = new Node();//c++
// 	node * newNode=(node*)malloc(sizeof(node)); // trong C
	newNode->data=x;
	newNode->next=NULL;
	return newNode;
 }
 void duyet(Node *head){
 	while(head!=NULL){
 		cout<<head->data<<" ";
 		head=head->next;
	}
 }
 int count(Node *head){
 	int dem=0;
 	while(head!=NULL){
 		dem++;
 		head=head->next;
	 }
	 return dem;
 }
 //pushFront nay cho C
 void pushFront(Node **head, int x){
 	Node *newNode=makeNode(x);
 	//buoc 1: phan next cua newNode=>head
 	newNode->next= *head; //*head => dia chi cua node head trong dslk
 	// buoc 2: Cap nhat node head => newNode
 	*head = newNode;
 }
 //pushFront2 nay cho C++
 void pushFront2(Node *&head, int x)
 {
 	Node *newNode = makeNode(x);
 	newNode->next = head;
 	head = newNode;
 }
 int main()
 {
 	Node *head = NULL;
 	for(int i=1; i<=5; i++){
 		pushFront(&head,i);
	}
	for(int i=10; i<=20; i++){
		pushFront2(head,i);
	}
	
	duyet(head);
	cout<<count(head);
	 
 }



