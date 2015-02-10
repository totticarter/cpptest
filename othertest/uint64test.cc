#include<stdint.h>
#include<iostream>

using namespace std;

int main(){

	uint64_t  a = 100ul * 1024ul * 1024ul * 1024ul;
	cout << "sizeof uint64_t: " << sizeof(uint64_t) << endl;
	cout << a << endl;

}
