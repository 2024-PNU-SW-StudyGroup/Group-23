#include <stdio.h>

int main(void)
{
	int x;
	scanf("%d", &x);
	int k = 1;
	while(1)
	{
		if((k-1)*k/2 < x && x <= k*(k+1)/2) break;
		k++;
	}
	
	if(k%2 != 0)
	{
		int a = k*(k+1)/2;
		printf("%d/%d", a-x+1, k-(a-x));
	}
	else
	{
		int a = k*(k+1)/2;
		printf("%d/%d", k-(a-x), a-x+1);
	}
		
	return 0;
}
