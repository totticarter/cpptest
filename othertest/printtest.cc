#include<stdio.h>

int main(){

 	int a = 0x123456789;
	char* pc = (char*)&a;
	short* ps = &a;
	printf("0x%x, 0x%x, 0x%x", (int)(*pc[0]), (int)(*pc[1]), (int)(*pc[2]));
	printf("0x%x, 0x%x, 0x%x", (int)(*pc[0]), (int)(*pc[1]), (int)(*pc[2]));

}
