#include <stdio.h>

int main(void)
{
	int n;
	int divisor = 0;
	long long max = 0, min = 1000000;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &divisor);
		if(divisor > max) max = divisor;
		if(divisor < min) min = divisor;
	}
	printf("%lld\n", max*min);
	return 0;
}
