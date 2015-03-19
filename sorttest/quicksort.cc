#include<iostream>
void quick_sort(int s[], int l, int r)
{
	if (l < r)
	{
		//Swap(s[l], s[(l + r) / 2]); //.............. ...1
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while(i < j && s[j] >= x) // ..........x..
				j--;  
			if(i < j) 
				s[i++] = s[j];

			while(i < j && s[i] < x) // ............x..
				i++;  
			if(i < j) 
				s[j--] = s[i];
		}
		s[i] = x;
		quick_sort(s, l, i - 1); // .... 
		quick_sort(s, i + 1, r);
	}
}

int main(){

	int a[7] = {4,2,6,8,1,3,9};
	quick_sort(a, 0, 6);
	for(int i = 0; i < 7; i++){
	
		std::cout << a[i] << ", " << std::endl;
	}
}
