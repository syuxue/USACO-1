/*
 ID: 1990jia1
 LANG: C
 PROG: calfflac
 */
#include <stdio.h>

int readchar(char *text, FILE *fin) {
	char a;
	int i = 0;
	while ((a = fgetc(fin)) != EOF)
		text[i++] = a;
	return i;
}

int isChar(char a) {
	if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
		return 1;
	return 0;
}

int isEqual(char m, char n) {
	int a, b;
	a = m >= 'a' ? m - 'a' : m - 'A';
	b = n >= 'a' ? n - 'a' : n - 'A';
	if (a == b)
		return 1;
	return 0;
}

int main() {
	FILE *fin, *fout;
	char text[20000];
	int len, i, j, max, m, n, k, num;
	fin = fopen("calfflac.in", "r");
	fout = fopen("calfflac.out", "w");

	len = readchar(text, fin);
	max = 0;

	for (i = 1; i < len - 1; i++) {
		if (!isChar(text[i]))
			continue;

		j = i - 1;
		k = i + 1;
		num = 0;
		while (j >= 0 && k < len) {
			if (!isChar(text[j])) {
				j--;
				continue;
			}
			if (!isChar(text[k])) {
				k++;
				continue;
			}
			if (isEqual(text[j], text[k])) {
				num++;
				if ((num * 2 + 1) > max) {
					max = num * 2 + 1;
					m = j;
					n = k;
				}
				j--;
				k++;
			} else
				break;
		}
		j = i;
		num = 0;
		while (j >= 0 && k < len) {
			if (!isChar(text[j])) {
				j--;
				continue;
			}
			if (!isChar(text[k])) {
				k++;
				continue;
			}
			if (isEqual(text[j], text[k])) {
				num++;
				if ((num * 2) > max) {
					max = num * 2;
					m = j;
					n = k;
				}
				j--;
				k++;
			} else
				break;
		}
	}

	fprintf(fout, "%d\n", max);
	for (i = m; i < n + 1; i++) {
		fprintf(fout, "%c", text[i]);
	}
	fprintf(fout, "%c", '\n');
	return 0;
}
