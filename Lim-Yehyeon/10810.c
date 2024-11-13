#include <stdio.h>

int main(void)
{
	int n, m, i, j, k;
	scanf("%d %d", &n, &m);
	int basket[101] = {0};
	for(int x = 0; x < m; x++)
	{
		scanf("%d %d %d", &i, &j, &k);
		for(int y = i-1; y <= j-1; y++)
		{
			basket[y] = k;
		}
	}
	for(int z = 0; z < n; z++)
	{
		printf("%d ", basket[z]);
	}
	return 0;
}
