#include<pthread.h>
#include<iostream>

using namespace std;

void* func(void*){

	cout << "hello world!" << endl;
}

int main(){

	pthread_t pt;
	int a;
	pthread_attr_t pat;
	pthread_attr_getdetachstate(&pat,&a);
	cout << "detach state is: " << a << endl;
	pthread_create(&pt, NULL, func, NULL);
	pthread_join(pt,NULL);
}
