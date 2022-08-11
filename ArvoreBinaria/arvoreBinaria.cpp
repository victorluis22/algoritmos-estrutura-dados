#include <iostream>
#include <queue>
#include <stack>

#define BINARY_SEARCH_TREE

using namespace std;

template <class T>
class Queue: public queue<T>{
	public:
		T dequeue() {
			T tmp = queue<T>::front();
			queue<T>::pop();
			return tmp;
		}
		
		void enqueue(const T &el){
			queue<T>::push(el);
		}
		
};

template <class T>
class Stack: public stack<T>{
	public:
		T pop() {
			T tmp = stack<T>::top();
			stack<T>::pop();
			return tmp;
		}
		
		void push(const T &el){
			stack<T>::push(el);
		}
		
};

template <class T>
class BSTNode{
	public:
		T el;
		BSTNode<T> *left, *right;
		
		BSTNode() {
			left = right = 0;
		}
		
		BSTNode(const T &e, BSTNode<T> *l = 0, BSTNode<T> *r = 0){
			el = e;
			left = l;
			right = r;
		}
};

template <class T>
class BST{
	public:
		BST(){
			root = 0;
		}
		
		bool isEmpty() {
			return root == 0;
		}
		
		T* search(const T &el) {
			return search(root, el);
		}
		
		void breadthFirstUDLR() {
			Queue<BSTNode<T>*> queue;
			BSTNode<T> *p = root;
			
			if(p != 0){
				queue.enqueue(p);
				
				while(!queue.empty()){
					p = queue.dequeue();
					
					visit(p);
					
					if(p->left != 0) {
						queue.enqueue(p->left);
					}
					
					if(p->right != 0){
						queue.enqueue(p->right);
					}
				}
			}
		}
		
		void breadthFirstUDRL() {
			Queue<BSTNode<T>*> queue;
			BSTNode<T> *p = root;
			
			if(p != 0){
				queue.enqueue(p);
				
				while(!queue.empty()){
					p = queue.dequeue();
					
					visit(p);
					
					if(p->right != 0){
						queue.enqueue(p->right);
					}
					
					if(p->left != 0) {
						queue.enqueue(p->left);
					}
					
					
				}
			}	
		}
		
		void breadthFirstDULR() {
			Stack<BSTNode<T>*> stack;
			BSTNode<T> *p = root;
			Queue<BSTNode<T>*> queue;
			
			if(p != 0){
				queue.enqueue(p);
				
				while(!queue.empty()){
					p = queue.dequeue();
					
					stack.push(p);
					
					if(p->right != 0){
						queue.enqueue(p->right);
					}
					
					if(p->left != 0) {
						queue.enqueue(p->left);
					}
				}
			}
			
			while(!stack.empty()){
				visit(stack.top());
				stack.pop();
			}
		}
		
		
		void breadthFirstDURL() {
			Stack<BSTNode<T>*> stack;
			BSTNode<T> *p = root;
			Queue<BSTNode<T>*> queue;
			
			if(p != 0){
				queue.enqueue(p);
				
				while(!queue.empty()){
					p = queue.dequeue();
					
					stack.push(p);
					
					if(p->left != 0) {
						queue.enqueue(p->left);
					}
					
					if(p->right != 0){
						queue.enqueue(p->right);
					}
				}
			}
			
			while(!stack.empty()){
				visit(stack.top());
				stack.pop();
			}
		}
		
		void insert(const T &info) {
			BSTNode<T> *p = root, *prev = 0;
			
			while(p != 0) {
				prev = p;
				if(info < p->el) {
					p = p->left;
				}
				else if(info > p->el) {
					p = p->right;
				}
				else{
					p = 0;
				}
			}
			
			if(root == 0) {
				root = new BSTNode<T>(info);
			}
			else if(info < prev->el){
				prev->left = new BSTNode<T>(info);
			}
			else if(info > prev->el){
				prev->right = new BSTNode<T>(info);
			}
			else{
				cout << "\nJa existe esse no!" << endl;
			}
		}
		
	protected:
		BSTNode<T> *root;
		
		T* search(BSTNode<T> *p, const T &el) {
			while(p != 0){
				if(el == p->el) {
					return &p->el;
				}
				else if(el < p->el) {
					p = p->left;
				}
				else{
					p = p->right;
				}
			}
			
			return 0;
		}
		
		virtual void visit(BSTNode<T> *p) {
			cout << p->el << " ";
		}
};

int main() {
	
	BST<int> b1;
	
	b1.insert(8);
	b1.insert(2);
	b1.insert(3);
	b1.insert(10);
	b1.insert(11);
	
	cout << "De cima para baixo, esquerda para direita" <<  endl;
	
	b1.breadthFirstUDLR();
	
	cout << "\n\nDe cima para baixo, direita para esquerda" <<  endl;
	
	b1.breadthFirstUDRL();
	
	cout << "\n\nDe baixo para cima, esquerda para direita" <<  endl;
	
	b1.breadthFirstDULR();
	
	cout << "\n\nDe baixo para cima, direita para esquerda" <<  endl;
	b1.breadthFirstDURL();
	
	return 0;
}

