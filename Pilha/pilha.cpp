#include <iostream>

using namespace std;

class Node {
	public:
			int info;
		Node *next;
		
		Node(int el = 0, Node *pr = 0) {
			info = el;
			next = pr;
		}
};

class Stack{
	private:
		Node *head;
	public:
		Stack() {
			head = 0;
		}
		void clear() {
			Node *tmp = head;
			
			while(tmp != 0) {
				tmp = tmp->next;
				delete head;
				head = tmp;
			}
		}
		
		bool isEmpty() {
			return (head == 0);
		}
		
		void push(int el) {
			head = new Node(el, head);
		}
		
		void pop() {
			if(head == 0) {
				cout << "\nPilha vazia!!" << endl;
			}
			else if(head->next == 0){
				head = 0;
			}
			else{
				Node *tmp = head->next;
				delete head;
				head= tmp;
			}
		}
		
		int popEl() {
			if(head == 0) {
				cout << "\nPilha vazia" << endl;
				return -1;
			}
			else{
				return head->info;
			}
		}
		
		void printStack() {
			for(Node *tmp = head; tmp != 0; tmp = tmp->next) {
				cout << "\nInformacao armazenada: " << tmp->info << endl;
				cout << "Endereco atual: " << tmp << endl;
				cout << "Proximo endereco: " << tmp->next << endl;
			}
		}
};

int main() {
	
	Stack pilha;
	
	pilha.push(10);
	pilha.push(20);
	pilha.push(30);
	
	cout << "\nPilha atual: " << endl;
	pilha.printStack();
	
	cout << "\nElemento no topo da pilha: " << pilha.popEl()<< endl;
	
	cout << "\nPilha atual: " << endl;
	
	pilha.pop();
	pilha.printStack();
	
	cout << "\nElemento no topo da pilha: " << pilha.popEl()<< endl;
	
	if(pilha.isEmpty() != 0) {
		cout << "\nPilha Vazia" << endl;
	}
	else{
		cout << "\nPilha nao vazia" << endl;
	}
	
	pilha.clear();
	pilha.printStack();
	
	if(pilha.isEmpty() != 0) {
		cout << "\nPilha vazia" << endl;
	}
	else{
		cout << "\nPilha nao vazia" << endl;
	}
	
	
	return 0;
}
