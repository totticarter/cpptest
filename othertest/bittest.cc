#include<iostream>

int main(){

	int count = 0;
	int x = 9999;
	while(x){

		count++;
		x = x&(x-1);
		std::cout << "x = " << x <<  std::endl;
		
	}

	std::cout << "count = " << count << std::endl;
	int a = 8192&8191;
	std::cout << "a = " << a << std::endl;

}
