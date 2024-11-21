#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		int data = a;
		for(int j = 1; j < b; j++) data = data*a % 10;
		if(data%10 != 0) printf("%d\n", data%10);
		else printf("10\n");
	}
	
	return 0;
}
