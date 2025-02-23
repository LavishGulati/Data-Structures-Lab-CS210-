#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *next;

    node(int d){
        data = d;
        next = NULL;
    }
};

node *inputLinkedList(){
    int n;
    cin >> n;

    if(n == 0) return NULL;

    int x;
    cin >> x;
    node *head = new node(x);
    node *temp = head;

    for(int i = 0; i < n-1; i++){
        cin >> x;
        temp->next = new node(x);
        temp = temp->next;
    }

    return head;
}

void printList(node *head){
    node *temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void swap(node *temp1, node *temp2){
    int x = temp1->data;
    temp1->data = temp2->data;
    temp2->data = x;
}

void bubbleSort(node *head){
    node *temp = head;
    while(temp->next != NULL) temp = temp->next;

    while(temp != head){
        node *prev = head;
        while(1){
            if(prev->data > prev->next->data){
                swap(prev, prev->next);
            }
            if(prev->next == temp) break;
            prev = prev->next;
        }
        // printList(head);
        temp = prev;
    }
}

int main(){
    node *head = inputLinkedList();

    bubbleSort(head);
    printList(head);
}
