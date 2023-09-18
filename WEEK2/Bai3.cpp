#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
};
struct DoubleLinkedList{
    Node* head;
    DoubleLinkedList(int a[], int n){
        Node* newNode = new Node();
        newNode->data = a[0];
        newNode->next = NULL;
        newNode->prev = NULL;
        head = newNode;
        Node* p = head;
        for (int i = 1; i < n; i++){
            Node* newNode = new Node();
            newNode->data = a[i];
            newNode->next = NULL;
            newNode->prev = p;
            p->next = newNode;
            p = p->next;
        }
    }
};
int count_triplets(DoubleLinkedList db){
    int res = 0;
    Node* p = db.head;
    if (p == NULL || p->next == NULL || p->next->next == NULL){
        return 0;
    }
    while (p->next->next){
        Node* q = p->next;
        while (q->next){
            Node* r = q->next;
            while (r){
                if (p->data + q->data + r->data == 0){
                    res++;
                }
                r = r->next;
            }
            q = q->next;
        }
        p = p->next;
    }
    return res;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    DoubleLinkedList db(a, n);
    cout << count_triplets(db);
}