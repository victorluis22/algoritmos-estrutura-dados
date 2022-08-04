#include <iostream>

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
};

int main() {
	intSLLNodeList sl1;
	
	sl1.addToHead(2);
	sl1.addToHead(5);
	sl1.addToHead(3);
	
	int maior, menor;
	
	sl1.maiorMenor(maior, menor);
	
	cout << "\nO maior node e: " << maior;
	cout << "\nO menor node e: " << menor;
}
