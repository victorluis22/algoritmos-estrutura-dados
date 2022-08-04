#include <iostream>

using namespace std;

class Node{
	public:
		int info;
		Node *next;
		
		Node(int el = 0, Node *pr = 0) {
			info = el;
			next = pr;
		}
};

class Queue{
	private:
		Node *head, *tail;
	public:
		Queue() {
			head = tail = 0;
		}
		
		void clearQ(){
			Node *tmp = head;
			
			while(tmp != 0){
				tmp = tmp->next;
				delete head;
				head = tmp;
			}
		}
		
		bool isEmpty() {
			return (head == 0);
		}
		
		void enqueue(int el){
			if(head == 0){
				head = tail = new Node(el, 0);
			}
			else{
				tail->next = new Node(el, 0);
				tail = tail->next;
			}
			
		}
		
		void dequeue() {
			if (!isEmpty()) {
				cout << "\nElemento removido: " << firstEl();
				Node *tmp = head;
				
				if(head == tail) {
					head = tail = 0;
				}
				else{
					head = head->next;
				}
				
				delete tmp;
			}
			else{
				cout << "\nLista vazia, nenhum elemento retirado!";
			}
		}
		
		int firstEl() {
			if(head == 0) {
				cout << "\nLista vazia" << endl;
				return -1;
			}
			else{
				return head->info;
			}
		}
		
		void printQueue() {
			for(Node *tmp = head; tmp != 0; tmp = tmp->next) {
				cout << "\nInformacao armazenada: " << tmp->info << endl;
				cout << "Endereco atual: " << tmp << endl;
				cout << "Proximo endereco: " << tmp->next << endl;
			}
		}		
};

int main() {
	
	Queue fila;
	
	cout << "Conteudo atual da fila: " << endl;
	fila.enqueue(10);
	fila.enqueue(20);
	fila.enqueue(30);
	fila.printQueue();
	
	fila.dequeue();
	fila.printQueue();
	fila.dequeue();
	fila.printQueue();
	fila.dequeue();
	fila.printQueue();
	fila.dequeue();
	fila.printQueue();
	
	return 0;
}
