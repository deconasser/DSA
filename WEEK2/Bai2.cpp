#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define Max (1000000000 + 7)
long long d[1000001];
struct Node {
	int value;
	Node* next;
};
typedef struct Node* node;
node head = nullptr;
int getSize(Node* head) {
    int size = 0;
    Node* current = head;
    while (current != nullptr) {
        size++;
        current = current->next;
    }
    return size;
}
void insert(int x, int k) {
	node p = new Node();
	p->value = k;
	if(x == getSize(head)) {
		if(head == nullptr) head = p;
		else {
			node tmp = head;
			while(tmp->next) {
				tmp = tmp ->next;
			}
			tmp->next = p;
		}
	}
	else if(x == 0) {
		if(head == nullptr) head = p;
		else {
			p->next = head->next;
			head = p;
		}
	}
	else {
		node tmp = head;
		x--;
		while(x--) {
			tmp = tmp->next;
		}
		p->next = tmp->next;
		tmp->next = p;
	}

}
void delete_(int x) {
	x--;
	node p = head;
	while(x--) {
		p = p->next;
	}
	p->next = p->next->next;
}
int main()
{  
	insert(0,1);
	insert(1,3);
	insert(1,4);
	insert(2,2);
	delete_(1);
	cout << getSize(head);
	while(tmp) {
		cout << tmp->value << " ";
		tmp = tmp->next;
	}
	return 0;
}