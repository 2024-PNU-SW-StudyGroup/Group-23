#include <stdio.h>

int main(void)
{
	int n, m, a, b;
	int pack = 1000, nat = 1000;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		if(a < pack) pack = a;
		if(b < nat) nat = b;
	}
	a = n/6;
	b = n%6;
	if(b*nat >= pack) printf("%d", pack*a + pack);
	else if(nat*6 < pack) printf("%d", n*nat);
	else printf("%d", a*pack + b*nat);
	
	return 0;
}
