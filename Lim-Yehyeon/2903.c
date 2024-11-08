#include <stdio.h>

int main(void)
{
	int n, output = 3, su = 2;
	scanf("%d", &n);
	
	for(int i = 1; i < n; i++)
	{
		output += su;
		su *= 2;
	}
	
	printf("%d", output * output);
		
	return 0;
}
