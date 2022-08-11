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
		
};

int main() {
	DLLNodeList d1;
	
	d1.addToTail(23);
	d1.addToTail(345);
	
	d1.printData();
	
	cout << "\nTem 345 na lista? " << d1.isInList(345) << endl;
	cout << d1.removeFromTail() << endl;
	
	d1.printData();
	return 0;
}
