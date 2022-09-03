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
		
		int contLeafs() {
			return countLeafs(root);
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
		
		int treeLength() {
			BSTNode<T> *p = root;
			Queue<BSTNode<T>*> queue;
			int length = 0;

			if(p != 0){
				queue.enqueue(p);

				while(!queue.empty()){
					p = queue.dequeue();

					length++;

					if(p->right != 0){
						queue.enqueue(p->right);
					}

					if(p->left != 0) {
						queue.enqueue(p->left);
					}
				}
			}
			
			return length;
		}
		
		T sumTreeElements() {
			BSTNode<T> *p = root;
			Queue<BSTNode<T>*> queue;
			T soma = 0;

			if(p != 0){
				queue.enqueue(p);

				while(!queue.empty()){
					p = queue.dequeue();

					soma += p->el;

					if(p->right != 0){
						queue.enqueue(p->right);
					}

					if(p->left != 0) {
						queue.enqueue(p->left);
					}
				}
			}
			
			return soma;
		}
		
		int treeHeight(){
			return treeHeight(root);
		}
		
		int distanceToRoot(const T &el){
			return distanceToRoot(root, el);
		}

	protected:
		BSTNode<T> *root;
		
		void clear(BSTNode <T> *p){
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
		
		int countLeafs(BSTNode<T> *p){
			static int contador = 0;
            if(p != 0){
                countLeafs(p->left);
                
                if(p->left == 0 && p->right == 0){
                	visit(p);
                	contador++;
				}
				
                countLeafs(p->right);
            }
            
            return contador;
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
		
		int treeHeight(BSTNode<T> *p){
			Stack<BSTNode<T>*> stack;
			Queue<BSTNode<T>*> queue;
			int parcialHeight = 0, height = 0;

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
				parcialHeight = distanceToRoot(root, stack.pop()->el);
				
				if(parcialHeight > height){
					height = parcialHeight;
				}
			}
			
			return height;
		}
		
		virtual void visit(BSTNode<T> *p) {
			cout << p->el << " ";
		}
};

int main() {

	BST<int> arvore1;
	int numeroFolhas;
	
	arvore1.insert(10);
	arvore1.insert(20);
	arvore1.insert(30);
	arvore1.insert(12);
	arvore1.insert(9);
	arvore1.insert(19);
	arvore1.insert(13);
	
	cout << "O numero de nos na arvore eh: " << arvore1.treeLength() << endl;
	cout << "A soma dos nos da arvore eh: " << arvore1.sumTreeElements() << endl;
	cout << "As folhas da arvore sao: "; numeroFolhas = arvore1.contLeafs(); cout << endl;
	cout << "O numero de folhas na arvore eh: " << numeroFolhas << endl;
	cout << "A altura da arvore eh: " << arvore1.treeHeight() << endl;
	
	
	

	return 0;
}

