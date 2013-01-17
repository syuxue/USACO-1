/*
 ID: 1990jia1
 LANG: C
 PROG: dualpal
 */
#include <stdio.h>
#include <string.h>

void chbase(char *digt, int a, int b)
{
	int i = 0;
	while (a != 0) {
		int c = a % b;
		digt[i++] = '0' + c;
		a /= b;
	}
	digt[i] = '\0';
}

int isPald(char *digt)
{
	int len, i;
	len = strlen(digt);
	if (digt[0] == '0')
		return 0;
	for (i = 0; i < len; i++) {
		if (digt[i] != digt[len - i -1])
			return 0;
	}
	return 1;
}

int main() {
	int N, S, count, a, b, num;
	char digt[20];
	FILE *fin, *fout;
	fin = fopen("dualpal.in", "r");
	fout = fopen("dualpal.out", "w");

	fscanf(fin, "%d %d", &N, &S);
	a = S + 1;
	count = 0;
	while(count < N) {
		num = 0;
		for (b = 2; b < 11; b++) {
			chbase(digt, a, b);
			if (isPald(digt)) {
				if (++num == 2) {
					fprintf(fout, "%d\n", a);
					count++;
					break;
				}
			}
		}
		a++;
	}
	return 0;
}
