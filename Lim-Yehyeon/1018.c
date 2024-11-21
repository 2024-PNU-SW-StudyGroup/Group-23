#include <stdio.h>

int main(void)
{
	char board[50][50];
	int n, m;
	int min = 80;
	int b = 0, w = 0;
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < n; i++) scanf("%s", &board[i]);
	for(int i = 0; i < n-7; i++)
	{
		for(int j = 0; j < m-7; j++)
		{
			b = 0;
			w = 0;
			for(int x = i; x < i+8; x++)
			{
				for(int y = j; y < j+8; y++)
				{
					if((x+y)%2 == 0)
					{
						if(board[x][y] == 'B') w++;
						else b++;
					}
					else
					{
						if(board[x][y] == 'B') b++;
						else w++;
					}
				}
			}
			min = min < b ? min : b;
			min = min < w ? min : w;
		}
	}
	printf("%d\n", min);
	
	return 0;
}
