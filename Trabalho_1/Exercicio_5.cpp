#include <iostream>
#include <stdlib.h>

using namespace std;

class Node{
	public:
		Node *next;
		int info;
		
		Node(int el = 0, Node *node = 0) {
			info = el;
			next = node;
		}
};

class SequentialList{	
	private:
		Node *head, *tail;
	public:
		
		SequentialList() {
			head = 0;
			tail = 0;
		}
		
		void addToHead(int el){
			if (head == 0){
				head = tail = new Node(el);
			}
			else{
				head = new Node(el, head);
			}
		}
		
		void addToTail(int el) {
			if (head == 0){
				head = tail = new Node(el);
			}
			else{
				tail->next = new Node(el);
				tail = tail->next;
			}
		}
	
		int deleteFromHead() {
			Node *tmp = head;
			int el = head->info;
			
			if (head == tail) {
				head = tail = 0;
			}
			else{
				head = head->next;
			}
			delete tmp;
			return el;
		}
		
		int deleteFromTail() {
			Node *tmp;
			int el = tail->info;
			
			if (head == tail) {
				head = tail = 0;
			}
			else{
				for(tmp = head; tmp->next != tail; tmp = tmp->next);
				tail = tmp;
				tmp = tail->next;
				tail->next = 0;
				delete tmp;
			}
			
			return el;
		}
		
		int deleteNode(int el) {
			Node *tmp, *aux;

			if (head != 0) {
				if(head == tail && el == head->info){
					head = tail = 0;
				}
				else if(el == head->info){
					tmp = head;
					head = head->next;
					delete tmp;	
				}
				else{
					for(aux = head, tmp = head->next; tmp != 0 && tmp->info != el; tmp = tmp->next, aux = aux->next);
					
					if (tmp != 0){
						aux->next = tmp->next;
						
						if (tmp == tail){
							tail = aux;
						}
						
						delete tmp;
					}
				}
			}
			
			return el;
		}
		void printNodes() {
			for(Node *tmp = head; tmp != 0; tmp = tmp->next){
				cout << tmp->info << endl;
			}
		}
		
		int sequentialListLength() {
			int counter = 0;
			
			for(Node *tmp = head; tmp != 0; tmp = tmp->next) {
				counter++;
			}
			
			return counter;
		}
		
		void printPrimeNodes() {
			int divisores;
			
			for(Node *tmp = head; tmp != 0; tmp = tmp->next){
				divisores = 0;
				for(int i = 1; i <= tmp->info; i++) {
					if(tmp->info % i == 0) {
						divisores++;
					}
				}
				
				if(divisores == 2) {
					cout << tmp->info << endl;
				}
			}
		}
		
		void add14toTail() {
			addToTail(14);
		}
		
		void insertMiddle() {
			int i, el;
			Node *tmp;
			int length = sequentialListLength();
			
			if(length % 2 == 0 && length != 0) {
				cout << "\nEntre com um numero inteiro para inserir no meio da lista: "; cin >> el;
				for(i = 1, tmp = head; i < (length/2); i++, tmp = tmp->next);
				tmp->next = new Node(el, tmp->next);
			}
		}
		
		int findIndex() {
			int index = 0, haveFindedEl = 0;
			int el;
			
			cout << "\nEntre com o numero que deseja procurar: "; cin >> el;
			
			for(Node *tmp = head; tmp != 0; tmp = tmp->next) {
				if(tmp->info == el) {
					haveFindedEl = 1;
					break;
				}
				else{
					index++;
				}
			}
			
			if(haveFindedEl) {
				cout << "\n(direcao: head -> tail) " << el << " encontrado na " << index << " posicao" << endl;
			}
			else{
				cout << "\n" << el << " nao encontrado" << endl;
			}
			
			return index;
		}
		
};

int main() {
	
	int el, i;
	SequentialList sl1;
	
	
	cout << "Insercao de 10 numeros:\n";
	for(int i = 0; i < 10; i++) {
		cout << "Insira um numero inteiro: "; cin >> el;
		sl1.addToTail(el);
	}
	
	cout << "\n\nPrint de Elementos Primos:\n";
	sl1.printPrimeNodes();
	
	system("pause");
	
	cout << "\n\nInsercao de elemento no meio:\n";
	sl1.insertMiddle();
	sl1.printNodes();
	
	system("pause");
	
	cout << "\n\nProcura por indices:\n";
	sl1.findIndex();
	
	system("pause");
	
	cout << "\n\nInsercao de 14 no final da lista:\n";
	sl1.add14toTail();
	sl1.printNodes();
	
	return 0;
}
