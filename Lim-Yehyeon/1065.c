#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	if(n < 100) printf("%d", n);
	else
	{
		int cnt = 99;
		int a, b, c;
		for(int i = 100; i <= n; i++)
		{
			a = i/100;
			b = i/10 % 10;
			c = i%10;
			if((c-b) == (b-a)) cnt++;
		}
		printf("%d", cnt);
	}
	
	return 0;
}
