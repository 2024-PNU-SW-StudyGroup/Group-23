#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int n, m;
		int output = 1;
		scanf("%d %d", &n, &m);
		for(int j = 0; j < n; j++)
		{
			output *= m-j;
			output /= 1+j;
		}
		printf("%d\n", output);
	}
	return 0;
}
