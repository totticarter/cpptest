#include<iostream>
using namespace std;

class Base{

	public:
		virtual void f(float x) {cout << "Base::f(floatx)" << x << endl;} with virtual, different para
		void h(float x){cout << "Base::h(float)" << x << endl;} without virtual, same para
		void g(float x){cout << "Base::g(float)" << x << endl;} without virtual, different para
};

class Derived: public Base{

	public:
		virtual void f(int x) {cout << "Derived::f(int x) " << x << endl;}
		void h(float x) {cout << "Derived::h(float)" << x << endl;}
		void g(int x) {cout << "Derived::g(float)" << x << endl;}
};

int main(){

	Derived d;
	Base* pb = &d;
	Derived* pd = &d;
	pb->g(3.14f);
	pd->g(3.14f);
	
	pb->f(3.14f);
	pd->f(3.14f);
}
