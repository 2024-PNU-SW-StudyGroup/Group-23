#include <stdio.h>

int main(void)
{
	int n, check;
	scanf("%d", &n);
	char name[50][50], output[50];
	for(int i = 0; i < n; i++) scanf("%s", &name[i]);
	for(int i = 0; i < 50; i++)
	{
		check = 1;
		for(int j = 1; j < n; j++) if(name[j][i] != name[0][i]) check = 0;
		if(check) output[i] = name[0][i];
		else output[i] = '?';
	}
	printf("%s", output);
	return 0;
}
