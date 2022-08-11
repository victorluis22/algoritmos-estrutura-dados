#include <iostream>

using namespace std;

class DLLNode{
	public:
		int info;
		DLLNode *next, *prev;
		
		DLLNode(int el = 0, DLLNode *n = 0, DLLNode *p = 0) {
			info = el;
			next = n;
			prev = p;
		}
};

class DLLNodeList{
	protected:
		DLLNode *head, *tail;
	public:
		DLLNodeList() {
			head = tail = 0;
		}
		
		void addToTail(int el) {
			if(tail != 0) {
				tail = new DLLNode(el, 0, tail);
				tail->prev->next = tail;
			}
			else{
				head = tail = new DLLNode(el);
			}
		}
		
		int removeFromTail() {
			int el = tail->info;
			
			if(head == tail) {
				delete head;
				head = tail = 0;
			}
			else if(head == 0) {
				cout << "\nLista vazia!!" << endl;
			}
			else{
				tail = tail->prev;
				delete tail->next;
				tail->next = 0;
			}
			
			return el;
		}
		
		void printData() {
			DLLNode *tmp;
			
			for(tmp = head; tmp != 0; tmp = tmp->next) {
				cout << "\nInformacao armazenada: " << tmp->info << endl;
				cout << "Endereco atual: " << tmp << endl;
				cout << "Proximo endereco: " << tmp->next << endl;
				cout << "Endereco anterior: " << tmp->prev << endl;
			}
		}
		
		bool isInList(int el) {
			for(DLLNode *tmp = head; tmp != 0; tmp = tmp->next) {
				if(tmp->info == el) {
					return true;
				}
			}
			
			return false;
		}
		
		bool isEmpty() {
			if(head == 0) {
				return true;
			}
			else{
				return false;
			}
		}
		
		void clearList() {
			while(!isEmpty()) {
				removeFromTail();
			}
		}
		
		void reverseList() {
			DLLNodeList aux;
			
			for(DLLNode *tmp = tail; tmp != 0; tmp = tmp->prev) {
				aux.addToTail(tmp->info);
			}
			
			clearList();
			head = aux.head;
		}
		
		int listLength() {
			int length = 0;
			
			for(DLLNode *tmp = head; tmp != 0; tmp = tmp->next) {
				length++;
			}
			
			return length;
		}
		
		int removeLast(){
			return removeFromTail();
		}
		
		int indexRemove(int index) {
			int el;
			DLLNode *tmp;
			
			if(index+1 > listLength() || index < 0){
				cout << "\nPosicao inexistente" << endl;
				return -1;
			}
			else{
				for(tmp = head; tmp != 0 && index > 0; tmp= tmp->next, index--);
				
				if(tmp == head) {
					tmp->next->prev = 0;
					head = tmp->next;
					
				}
				else if(tmp == tail) {
					tmp->prev->next = 0;
					tail = tmp->prev;
				}
				else{
					tmp->prev->next = tmp->next;
					tmp->next->prev = tmp->prev;
				}
				
				el = tmp->info;
				delete tmp;
				return el;
			}
		}
		
		void insertMiddle(int el) {
			DLLNode *tmp;
			int i;
			
			if(listLength() % 2 == 0) {
				for(i = 1, tmp = head; i < (listLength()/2) && tmp != 0; tmp = tmp->next, i++);
				tmp->next = new DLLNode(el, tmp->next, tmp);
			}
		}
};

int main() {
	DLLNodeList d1;
	
	d1.addToTail(10);
	d1.addToTail(20);
	d1.addToTail(40);
	d1.addToTail(30);
	
	d1.insertMiddle(3);
	
	d1.printData();
	return 0;
}
