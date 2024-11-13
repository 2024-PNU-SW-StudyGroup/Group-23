#include <stdio.h>

int main(void)
{
	int n, m, i, j, temp;
	scanf("%d %d", &n, &m);
	int basket[101];
	for(int x = 0; x < n; x++)
	{
		basket[x] = x + 1;
	}
	for(int y = 0; y < m; y++)
	{
		scanf("%d %d", &i, &j);
		temp = basket[i-1];
		basket[i-1] = basket[j-1];
		basket[j-1] = temp;
	}
	for(int z = 0; z < n; z++)
	{
		printf("%d ", basket[z]);
	}
	return 0;
}
