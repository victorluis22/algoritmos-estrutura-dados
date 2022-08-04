#include <iostream>
#define MAX 100

using namespace std;

class intSLLNode{
	public:
		intSLLNode *next;
		int info;
		
		intSLLNode(int el = 0, intSLLNode *node = 0) {
			info = el;
			next = node;
		}
};

class intSLLNodeList{	
	private:
		intSLLNode *head, *tail;
	public:
		
		intSLLNodeList() {
			head = 0;
			tail = 0;
		}
		
		void addToHead(int el){
			if (head == 0){
				head = tail = new intSLLNode(el);
			}
			else{
				head = new intSLLNode(el, head);
			}
		}
		
		void addToTail(int el) {
			if (head == 0){
				head = tail = new intSLLNode(el);
			}
			else{
				tail->next = new intSLLNode(el);
				tail = tail->next;
			}
		}
	
		int deleteFromHead() {
			intSLLNode *tmp = head;
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
			intSLLNode *tmp;
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
			intSLLNode *tmp, *aux;

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
			for(intSLLNode *tmp = head; tmp != 0; tmp = tmp->next){
				cout << "\nInformacao armazenada: " << tmp->info << endl;
				cout << "Endereco atual: " << tmp << endl;
				cout << "Proximo endereco: " << tmp->next << endl;
			}
		}
		
		bool isInList(int el) {
			intSLLNode *tmp;
			
			for(tmp = head; tmp != 0 && tmp->info != el; tmp = tmp->next);
			return tmp != 0;
		}
		
		void maiorMenor(int &maior, int &menor) {
			intSLLNode *tmp;
			maior = menor = head->info;
			
			for(tmp = head; tmp != 0; tmp = tmp->next) {
				if(tmp->info > maior){
					maior = tmp->info;
				}
				
				if(tmp->info < menor) {
					menor = tmp->info;
				}
			}
		}
		
		int listLength () {
			intSLLNode *tmp;
			int contador = 0;
			
			for(tmp = head; tmp != 0; tmp = tmp->next) {
				contador++;
			}
			
			return contador;
		}
		
		float mediaAritmetica() {
			intSLLNode *tmp;
			int qtdeElementos = listLength();
			float soma;
			
			for(tmp = head, soma = 0; tmp != 0; tmp = tmp->next) {
				soma += tmp->info;
			}
			
			return soma / qtdeElementos;
		}
		
		void concat(intSLLNodeList nova){
			tail->next = nova.head;
		}
		
		void insertMiddle(int el) {
			intSLLNode *tmp;
			int qtdElemento = listLength();
			int contador = 1;
			
			if (qtdElemento % 2 == 0 && qtdElemento >= 2) {
				for(tmp = head; contador < qtdElemento/2; tmp = tmp->next) {
					contador++;
				}
				tmp->next = new intSLLNode(el, tmp->next);
			}
		}
		
		int intSLLNodeListCmp(intSLLNodeList sl2) {
			intSLLNode *tmp1, *tmp2;
			int igualdade = 1;
			
			if(listLength() == sl2.listLength()) {
				for(tmp1 = head, tmp2 = sl2.head; tmp1 != 0 && tmp2 != 0; tmp1 = tmp1->next, tmp2 = tmp2->next) {
					if(tmp1->info != tmp2->info) {
						return 0;
					}
				}
			}
			else{
				igualdade = 0;
			}
			
			return igualdade;
		}
		
		void returnEven(int evens[MAX], int *total){
			intSLLNode *tmp;
			int cont = 0;
			
			for(tmp = head; tmp != 0; tmp = tmp->next) {
				if(tmp->info % 2 == 0){
					evens[cont] = tmp->info;
					cont++;
				}
			}
			
			*total = cont;
		}
};

int main() {
	
	intSLLNodeList sl1;
	int total;
	int evens[MAX];
	
	sl1.addToHead(10);
	sl1.addToHead(45);
	sl1.addToTail(98);
	sl1.addToHead(23);
	sl1.addToHead(22);
	
	sl1.returnEven(evens, &total);
	
	for(int i = 0; i < total; i++) {
		cout << evens[i] << endl;
	}
	
	
	return 0;
}
