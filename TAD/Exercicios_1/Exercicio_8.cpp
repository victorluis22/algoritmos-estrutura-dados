#include <iostream>

using namespace std;

class facil{
	private:
		int x, y, z;
	public:
		static int p;
		facil(){
		}
		~facil() {
		}
};

int facil::p = 5;

int main() {
	facil p1;
		
	cout << p1.p;
	
	return 0;
}
