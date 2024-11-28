#include <stdio.h>

int main(void)
{
	int arr[50];
	int temp[50] = {0, };
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		for(int j = 0; j < i; j++)
		{
			if(arr[j] > arr[i]) temp[j]++;
			else temp[i]++;
		}
	}
	for(int i = 0; i < n; i++) printf("%d ", temp[i]);
	
	return 0;
}
