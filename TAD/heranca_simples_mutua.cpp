#include <iostream>

using namespace std;

class BaseClass {
	public:
		BaseClass() {}
		void f (char *s = "unknown") {
			cout << "Function f() in BaseClass called from " << s << endl;
			h();
		}
	protected:
		void g (char *s = "unknown") {
			cout << "Function g() in BaseClass called from " << s << endl;
		}
	private:
		void h() {
			cout << "Function h() in BaseClass\n";
		}
};

class Derived1Level1 : public virtual BaseClass {
	public:
		void f (char *s = "unknown") {
			cout << "Function f() in Derived1Level1 called from " << s << endl;
			g("Derived1Level1");
			h("Derived1Level1");
		}
		void h (char *s = "unknown") {
			cout << "Function h() in DerivedLevel1 called from " << s << endl;
		}
};

class Derived2Level1 : public virtual BaseClass {
	public:
		void f (char *s = "unknown") {
			cout << "Function f() in Derived2Level1 called from " << s << endl;
			g("Derived2Level1");
			//h(); // Error: BaseClass()::h() is not acessible
		}
};

class Derived2Level2 : public Derived1Level1, public Derived2Level1 {
	public:
		void f (char *s = "unknown") {
			cout << "Function f() in Derived2Level2 called from " << s << endl;
			g("Derived2Level2");
			Derived1Level1::h("Derived2Level2");
			BaseClass::f("Derived2Level2");
		}
		
};


int main() {
	BaseClass bc;
	Derived1Level1 d1l1;
	Derived2Level1 d2l1;
	Derived2Level2 d2l2;
	
	bc.f("main(1)");
	//	bc.g(); // Error: BaseClass::g() is not acessible
	//	bc.h(); // Error: BaseClass::h() is not acessible

	d1l1.f("main(2)");
	//	d1l1.g(); // Error: BaseClass::g() is not acessible
	d1l1.h("main(3)");
	
	d2l1.f("main(4)");
	//	d2l1.g(); // Error: BaseClass::g() is not acessible
	//	d2l1.h(); // Error: BaseClass::h() is not acessible
	
	d2l2.f("main(5)");
	//	d2l2.g(); // Error: BaseClass::g() is not acessible
	d2l2.h();
	
	return 0;
}
