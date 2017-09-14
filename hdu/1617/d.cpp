#include <stdio.h>
#include <string.h>

int t, n, i;
int cc[10];
void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
void insert(int num, int *cc) {
	int i;
	if (num == n)
	{
		int nu = num * 2;
		while (nu --) {printf(" "); }
		printf("writeln(");
		for (i = 0; i < n - 1; i++) {
			printf("%c,", cc[i] + 'a');
		}
		printf("%c)\n", cc[n - 1] + 'a');
			return;
	}
	int c[10];
	for (i = 0; i < num; i ++)
		c[i] = cc[i];
	for (i = num; i >= 0; i --) {
		if (num == i) {
			int nu = num * 2;
			while (nu --) {printf(" "); }
			c[i] = i;
			printf("if %c < %c then\n", c[i - 1] + 'a', num + 'a');
			insert(num + 1, c);
		}
		else if (i == 0) {
			int nu = num * 2;
			while (nu --) {printf(" "); }
			printf("else\n");
			swap(c[i], c[i + 1]);
			insert(num + 1, c);
		}
		else {
			int nu = num * 2;
			while (nu --) {printf(" "); }
			printf("else if %c < %c then\n", c[i - 1] + 'a', num + 'a');
			swap(c[i], c[i + 1]);
			insert(num + 1, c);
		}
	}
}
void out() {
	printf("program sort(input,output);\n");
	printf("var\n");
	for (i = 0; i < n - 1; i++) {
		printf("%c,",'a' + i);
	}
	printf("%c : integer;\n", 'a' + n - 1);
	printf("begin\n");
	printf("  readln(");
	for (i = 0; i < n - 1; i++) {
		printf("%c,",'a' + i);
	}
	printf("%c);\n", 'a' + n - 1);
	insert(1, cc);
	printf("end.\n");
	if (t) printf("\n");
}

int main() {
	scanf("%d", &t);
	while (t --) {
		memset(cc, 0, sizeof(cc));
		scanf("%d", &n);
		out();
	}
	return 0;
}
