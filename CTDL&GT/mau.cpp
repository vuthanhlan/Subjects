#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node* next;
};

struct LinkedList
{
	Node* head;
	Node* tail;
};
Node* CreateNode(int init_data)
{
	Node* node = new Node;
	node->data = init_data;
	node->next = NULL;
	return node;
}

void CreateList(LinkedList& l)
{
	l.head = NULL;
	l.tail = NULL;
}

void AddHead(LinkedList& l, Node* node)
{
	if (l.head == NULL)
	{
		l.head = node;
		l.tail = node;
	}
	else
	{
		node->next = l.head;
		l.head = node;
	}
}

void AddTail(LinkedList& l, Node* node)
{
	if (l.head == NULL)
	{
		l.head = node;
		l.tail = node;
	}
	else
	{
		l.tail->next = node;
		l.tail = node;
	}
}

void InsertAfterQ(LinkedList& l, Node* p, Node* q)
{
	if (q != NULL)
	{
		p->next = q->next;
		q->next = p->next;
		if (l.tail == q)
			l.tail = p;
	}
	else
		AddHead(l, p);
}

int RemoveHead(LinkedList& l, int& x)
{
	if (l.head != NULL)
	{
		Node* node = l.head;
		x = node->data;
		l.head = node->next;
		delete node;
		if (l.head == NULL)
			l.tail = NULL;
		return 1;
	}
	return 0;
}

int RemoveAfterQ(LinkedList& l, Node* q, int& x)
{
	if (q != NULL)
	{
		Node* p = q->next;
		if (p != NULL)
		{
			if (l.tail == p)
				l.tail = q;
			q->next = p->next;
			x = p->data;
			delete p;
			return 1;
		}
		return 0;
	}
	return 0;
}

Node* GetNode(LinkedList l, int index)
{
	Node* node = l.head;
	int i = 0;
	while (node != NULL && i != index)
	{
		node = node->next;
		i++;
	}
	if (i == index && node != NULL)
		return node;
	return NULL;
}

void PrintList(LinkedList l)
{
	if (l.head != NULL)
	{
		Node* node = l.head;
		while (node != NULL)
		{
			cout << node->data << ' ';
			node = node->next;
		}
	}
}

Node* Search(LinkedList l, int x)
{
	Node* node = l.head;
	while (node != NULL && node->data != x)
		node = node->next;
	if (node != NULL)
		return node;
	return NULL;
}

int Length(LinkedList l)
{
	int count = 0;
	Node* node = l.head;
	while (node != NULL)
	{
		count++;
		node = node->next;
	}
	return count;
}

void DestroyList(LinkedList& l)
{
	int x;
	Node* node = l.head;
	while (node != NULL)
	{
		RemoveHead(l, x);
		node = l.head;
	}
	l.tail = NULL;
}
int main()
{
	// Create a linked list
	LinkedList list;
	CreateList(list);

	// Add sample data to list
	Node* node;
	for (int i = 1; i <= 10; i++)
	{
		// Create new node with init data is i
		node = CreateNode(i);
		
		// Add node to head
		// List that is added node by AddHead will be reversed
		//AddHead(list, node);
		
		// Add node to Tail
		AddTail(list, node);
	}

	// Print list
	PrintList(list);
	cout << endl;

	// Get list's length
	int len = Length(list);
	cout << "Length of list: " << len << endl;

	// Get node at index 7
	Node* nodeAtIdx7 = GetNode(list, 7);
	if (nodeAtIdx7 != NULL)
		cout << "Data at node have idx 7: " << nodeAtIdx7->data << endl;

	// Search for 4 in list
	Node* search4InList = Search(list, 4);
	if (search4InList != NULL)
		cout << "4 was founded" << endl;
	else
		cout << "4 not Found" << endl;

	// Remove node after 4 in list
	int x;
	int res = RemoveAfterQ(list, search4InList, x);
	if (res)
	{
		cout << "Data of node has been removed: " << x << endl;
		cout << "List after removed: ";
		PrintList(list);
		cout << endl;
	}
	else
		cout << "Nothing is removed" << endl;

	// Insert 2409 after node 4
	Node* node2409 = CreateNode(2409);
	InsertAfterQ(list, node2409, search4InList);
	cout << "List after insert 2409 after 4: ";
	PrintList(list);
	cout << endl;
	

	// Remove Head
	res = RemoveHead(list, x);
	if (res)
	{
		cout << "Data of node has been removed: " << x << endl;
		cout << "List after removed head: ";
		PrintList(list);
		cout << endl;
	}
	else
		cout << "Nothing is removed" << endl;

	
	// Destroy all node
	DestroyList(list);
	
	return 0;
}



