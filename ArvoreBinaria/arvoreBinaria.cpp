#include <iostream>
#include <queue>
#include <stack>
#include <math.h>

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
		int balanceFactor = 0;

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
		
		~BST(){
			clear();
		}
		
		void clear(){
			clear(root);
		}

		bool isEmpty() {
			return root == 0;
		}
		
		void preorder(){
			return preorder(root);
		}
		
		void inorder(){
			return inorder(root);
		}
		
		void postorder(){
			return postorder(root);
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
	 	
		void findAndDeleteByMerging(const T &el){
			BSTNode<T> *node = root, *prev = 0;
			
			while(node != 0){
				if(node->el == el){
					break;
				}
				prev = node;
				
				if(el < node->el){
					node = node->left;
				}
				else{
					node = node->right;
				}
			}
			
			if(node != 0 && node->el == el){
				if(node == root){
					deleteByMerging(root, prev, "root");
				}
				else if(prev->left == node){
					deleteByMerging(prev->left, prev, "left");
				}
				else{
					deleteByMerging(prev->right, prev, "right");
				}
			}
			else if(root != 0){
				cout << "Elemento " << el <<  " nao esta na arvore" << endl;
			}
			else{
				cout << "Arvore vazia" << endl;
			}
		}
		
		BSTNode<T>* rotateRight(BSTNode<T> *grandParent, BSTNode<T> *parent, BSTNode<T> *child){
			if(parent != root){
				grandParent->right = child;
				parent->left = child->right;
				child->right = parent;
			}
			else{
				parent->left = child->right;
				child->right = parent;
				root = child;
			}
			
			return child;
		}
		
		BSTNode<T>* rotateLeft(BSTNode<T> *grandParent, BSTNode<T> *parent, BSTNode<T> *child){
			if(parent != root){
				grandParent->right = child;
				parent->right = child->left;
				child->left = parent;
			}
			else{
				parent->right = child->left;
				child->left = parent;
				root = child;
			}
			
			return child;
		}
		
		void createBackbone(){
			return createBackbone(root);
		}
		
		int distanceToRoot(const T &el){
			return distanceToRoot(root, el);
		}
		
		void showNodeHeight(){
			return showNodeHeight(root);
		}
		
		void showBalanceFactors(){
			return showBalanceFactors(root);
		}
		
		void createPerfectTree(){
			return createPerfectTree(root);
		}
		
		int treeLength(){
			return treeLength(root);
		}
		
		void DWS(){
			createBackbone();
			createPerfectTree();
		}
		
		BSTNode<T> * searchParentNode(const T &el){
			return searchParentNode(root, el);
		}
		
		
	protected:
		
		BSTNode<T> *root;
		
		void clear(BSTNode<T> *p){
			root = 0;
		}
		
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
		
		BSTNode<T>* searchParentNode(BSTNode<T> *p, const T &el) {
			BSTNode<T> *parent = p;
			
			while(p != 0){
				if(el == p->el) {
					return parent;
				}
				else if(el < p->el) {
					parent = p;
					p = p->left;
				}
				else{
					parent = p;
					p = p->right;
				}
			}

			return 0;
		}
		
		void preorder(BSTNode<T> *p){
            if(p != 0){
                visit(p);
                inorder(p->left);
                inorder(p->right);
            }
		}

		void inorder(BSTNode<T> *p){
            if(p != 0){
                inorder(p->left);
                visit(p);
                inorder(p->right);
            }
		}

		void postorder(BSTNode<T> *p){
            if(p != 0){
                inorder(p->left);
                inorder(p->right);
                visit(p);
            }
		}
		
		void deleteByMerging(BSTNode<T> *node, BSTNode<T> *prev, const char *direction){
			BSTNode<T> *tmp = node;
			
			if(node != 0){
				if(!node->right){
					node = node->left;
					if(direction == "right")
						prev->right = node;
					else if(direction == "left"){
						prev->left = node;
					}
					else if(direction == "root"){
						root = node;
					}
				}
				else if (!node->left){
					node = node->right;
					if(direction == "right")
						prev->right = node;
					else if(direction == "left"){
						prev->left = node;
					}
					else if(direction == "root"){
						root = node;
					}
				}
				else{
					tmp = node->left;
					
					while(tmp->right != 0){
						tmp = tmp->right;
					}
					
					tmp->right = node->right;
					
					tmp = node;
					node = node->left;
					
					if(direction == "right")
						prev->right = node;
					else if(direction == "left"){
						prev->left = node;
					}
					else if(direction == "root"){
						root = node;
					}
				}
			}
			delete tmp;
		}
		
		void createBackbone(BSTNode<T> *tmp){
			BSTNode<T> *prev = tmp;
			while(tmp != 0){
				if(tmp->left != 0){
					tmp = rotateRight(prev, tmp, tmp->left);
				}
				else{
					prev = tmp;
					tmp = tmp->right;
				}
			}
		}
		
		int distanceToRoot(BSTNode<T> *p, const T &el){
			int distance = 1;
			
			while(p != 0){
				if(el == p->el) {
					return distance;
				}
				else if(el < p->el) {
					distance++;
					p = p->left;
				}
				else{
					distance++;
					p = p->right;
				}
			}
			
			return 0;
		}
		
		void showNodeHeight(BSTNode<T> *p){
			Queue<BSTNode<T>*> queue;
			Queue<BSTNode<T>*> aux;
			
			if(p != 0){
				queue.enqueue(p);

				while(!queue.empty()){
					p = queue.dequeue();

					aux.enqueue(p);

					if(p->left != 0) {
						queue.enqueue(p->left);
					}

					if(p->right != 0){
						queue.enqueue(p->right);
					}
				}
			}

			while(!aux.empty()){
				cout << "\nNo = "; visit(aux.front()); 
				cout << "Altura = " << distanceToRoot(aux.front()->el);
				aux.dequeue();
			}
			
		}
		
		void showBalanceFactors(BSTNode<T> *p){
			Queue<BSTNode<T>*> queue;
			Queue<BSTNode<T>*> aux;
			
			if(p != 0){
				queue.enqueue(p);

				while(!queue.empty()){
					p = queue.dequeue();

					aux.enqueue(p);

					if(p->left != 0) {
						queue.enqueue(p->left);
					}

					if(p->right != 0){
						queue.enqueue(p->right);
					}
				}
			}

			while(!aux.empty()){
				cout << "\nNo = "; visit(aux.front()); 
				cout << "Fator = " << aux.front()->balanceFactor;
				aux.dequeue();
			}
			
		}
		
		int treeLength(BSTNode<T> *p){
			static int counter = 1;
			
            if(p != 0){
                treeLength(p->left);
                treeLength(p->right);
                counter++;
            }
            
            return counter;
		}
		
		void createPerfectTree(BSTNode<T> *p){
			int n = treeLength();
			int m = pow(2, floor(log2(n+1))) - 1;
			BSTNode<T> *prev = p;
						
			for(int i = 0; i < (n - m); i++){
				p = rotateLeft(prev, p, p->right);
				prev = p;
				p = p->right;
				
			}
			
			while(m > 1){
				p = root;
				m /= 2;
				
				for(int i = 0; i < m; i++){
					p = rotateLeft(prev, p, p->right);
					prev = p;
					p = p->right;
				}
			}
		}
		
		virtual void visit(BSTNode<T> *p) {
			cout << p->el << " ";
		}
};

int main() {

	BST<int> arvore1;

	arvore1.insert(10);
	arvore1.insert(9);
	arvore1.insert(8);
	arvore1.insert(190);
	
	arvore1.showNodeHeight();
	
	cout << endl << endl;
	arvore1.showBalanceFactors();
	
	return 0;
}

