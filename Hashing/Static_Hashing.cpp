#include<iostream>
#include<string>

using namespace std;

class Node{
	int num;
	Node* next;
public:
	Node (int num){
		this->num = num;
		this->next = NULL;
	}
	int getNum(){
		return this->num;
	}
	void setNext (Node* temp){
		this->next = temp;
	}
	Node* getNext(){
		return this->next;
	}
};

class HashTable{
	Node ** bkt;
	int size;
public:
	HashTable(int size){
		this->size = size;
		this->bkt = new Node*[size];
	}
	void ins(int);
	int search(int);
	int del(int);
	void display();
};

int hsh (int num){
	return (num%9);  // Should be num%size
}

void HashTable::ins(int num){
	int i = hsh(num);
	Node* temp = new Node(num);
	if (this->bkt[i] != NULL){
		temp->setNext(this->bkt[i]);
	}
	this->bkt[i] = temp;
}

void HashTable::display(){
	for (int i=0; i<this->size; i++){
		cout<<i<<": ";
		Node* temp = this->bkt[i];
		while(temp!=NULL){
			cout<<temp->getNum()<<" ";
			temp = temp->getNext();
		}
		cout<<endl;
	}
}

int HashTable::search(int num){
	int i = hsh(num);
	Node* temp = bkt[i];
	while (temp!=NULL){
		if (temp->getNum() == num)
			return i;
		temp = temp->getNext();
	}
	return -1;
}

int HashTable::del(int num){
	int i=hsh(num);
	Node* temp = bkt[i], *prev=NULL;
	while (temp!=NULL){
		if (temp->getNum() == num){
			if (prev == NULL){
				bkt[i]=temp->getNext();
				delete temp;
				return 0;
			}
			else{
				prev->setNext(temp->getNext());
				delete temp;
				return 0;
			}
		}
		prev = temp;
		temp = temp->getNext();
	}
	return -1;
}

int main(){

	HashTable* h = NULL;
	int choice;
	int num, res;

	do{
		cout<<"1. Create a new Hash table\n";
		cout<<"2. Insert an element\n";
		cout<<"3. Find an element\n";
		cout<<"4. Delete an element\n";
		cout<<"5. Display Hash table\n";
		cout<<"Any other choice to exit\n";
		cout<<"Enter choice: ";
		cin>>choice;

		switch(choice){
			case 1:
				if (h!=NULL){
					delete h;
				}
				cout<<"Enter number of buckets: ";
				int size;
				cin>>size;
				h = new HashTable(size);
				break;

			case 2:
				if(h==NULL){
					cout<<"no hash table exists\n";
					break;
				}
				cout<<"Enter number: ";
				cin>>num;
				h->ins(num);
				break;

			case 3:
				if(h==NULL){
					cout<<"No hash table exists\n";
					break;
				}
				cout<<"Enter number: ";
				cin>>num;
				res = h->search(num);
				if (res == -1)
					cout<<"Number does not exist\n";
				else
					cout<<num<<" exists in bucket "<<res<<"\n";
				break;

			case 4:
				if(h==NULL){
					cout<<"No hash table exists\n";
					break;
				}
				cout<<"Enter number: ";
				cin>>num;
				res = h->del(num);
				if (res == -1)
					cout<<"Number does not exist\n";
				else
					cout<<num<<" deleted from bucket\n";
				break;

			case 5:
				if(h==NULL){
					cout<<"No hash table exists\n";
					break;
				}
				h->display();
				break;

			default: return 0;
		}
	}while(1);


	return 0;
}
