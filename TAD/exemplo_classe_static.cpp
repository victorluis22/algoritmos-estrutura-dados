#include <iostream>

using namespace std;

class facil {
	private:
		int x, y, z;
	public:
		static int p;
		
		facil() {}
		
		void mostrap() {
			cout << p << endl;
		}
		
		~facil() {}	
};

int facil::p = 1;

int main() {
	facil p1, p2, p3;
	
	p1.mostrap();
	p2.mostrap();
	p3.mostrap();
	
	
	return 0;
}
