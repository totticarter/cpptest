#include<iostream>

using namespace std;

struct data{

	char c;//1
	int i;//4
	float a;//4
	double d;//8
};

int main(){


	cout << "len is: " << sizeof(struct data) << endl;
}
