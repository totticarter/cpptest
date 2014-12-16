#include<iostream>

int main(){

	char a[] = "hello";
	a[0] = 'x';
	std::cout << a << std::endl;

	char* p = "world";
	p[0] = 'x';

}
