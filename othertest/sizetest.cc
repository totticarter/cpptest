#include<iostream>

int main(){

	//char *(*a[3][4]);
	//std::cout << sizeof(a) << std::endl;

	//char* str = "aaaaa";
 	//std::cout << sizeof(str) << std::endl;	
	struct s{
		
		int a;
		char b;
		char d;
		short c;
	};
	
	std::cout << sizeof(s) << std::endl;
}
