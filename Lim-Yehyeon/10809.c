#include <stdio.h>

int main()
{
	char word[100];
	scanf("%s", &word);
	int alp[26];
	for(int i = 0; i < 26; i++){
		alp[i] = -1;
	}
	int n;
	for(int i = 0; word[i] != NULL; i++){
		n = word[i] - 97;
		if(alp[n] == -1) alp[n] = i;
	}
	for(int i = 0; i < 26; i++){
		printf("%d ", alp[i]);
	}
	
	return 0;
}
