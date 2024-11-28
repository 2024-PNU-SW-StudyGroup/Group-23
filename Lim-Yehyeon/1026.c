#include <stdio.h>

int main(void)
{
	int n;
	int a[50], b[50];
	int a_re[50], b_re[50];
	int sum = 0;
	int count = 0;
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i < n; i++) scanf("%d", &b[i]);
	for(int e = 100; e >= 0; e--)
	{
		for(int i = 0; i < n; i++)
		{
			if(a[i] == e)
			{
				a_re[count] = e;
				count++;
			}
		}
	}
	count = 0;
	for(int e = 0; e <= 100; e++)
	{
		for(int i = 0; i < n; i++)
		{
			if(b[i] == e)
			{
				b_re[count] = i;
				count++;
			}
		}
	}
	for(int i = 0; i < n; i++) sum += a_re[i]*b[b_re[i]];
	printf("%d\n", sum);
	return 0;
}
