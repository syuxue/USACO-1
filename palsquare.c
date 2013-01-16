/*
ID: 1990jia1
LANG: C
PROG: palsquare
*/
#include <stdio.h>
#include <string.h>


void chbase(char *digt, int a, int b)
{
	int i = 0;
	while (a != 0) {
		int c = a % b;
		if (c > 9) {
			digt[i++] = 'A' + c - 10;
		} else {
			digt[i++] = '0' + c;
		}
		a /= b;
	}
	digt[i] = '\0';
}

void strrev(char *orig)
{
	char dest[10];
	strcpy(dest, orig);
	int len, i;
	len = strlen(orig);
	for (i = 0; i < len; i++) {
		orig[i] = dest[len - i - 1];
	}
}
int isPald(char *digt)
{
	int len, i;
	len = strlen(digt);
	for (i = 0; i < len; i++) {
		if (digt[i] != digt[len - i -1])
			return 0;
	}
	return 1;
}

int main()
{
	int b, i;
	char orig[10], squa[20];
	FILE *fin, *fout;
	fin = fopen("palsquare.in", "r");
	fout = fopen("palsquare.out", "w");

	fscanf(fin, "%d", &b);
	for (i = 0; i < 300; i++) {
		int squ = (i + 1) * (i + 1);
		chbase(squa, squ, b);
		if (isPald(squa)) {
			chbase(orig, i + 1, b);
			strrev(orig);
			fprintf(fout, "%s %s\n", orig, squa);
		}
	}
	return 0;
}
