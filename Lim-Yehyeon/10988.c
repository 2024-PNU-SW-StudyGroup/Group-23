#include <stdio.h>
#include <string.h>

int main(void)
{
	char word[101];
	scanf("%s", &word);
	int len, n = 1;
	len = strlen(word);
	
	for(int i = 0; i < len/2; i++)
	{
		if(word[i] != word[len-1-i])
		{
			n = 0;
			break;
		}
	}
	printf("%d", n);
	
	return 0;
}
