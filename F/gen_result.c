#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	long long ans = 0;
	while (n--)
	{
		int c;
		scanf("%d", &c);
		ans += c;
	}
	if (ans <= 200000)
		puts("2O wan is gou 1e");
	else if (ans <= 30000000)
		puts("wo want 3 qian wan");
	else
		puts("3 qian wan is sti11 bu gou");
	return 0;
}
