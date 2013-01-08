/*
ID: 1990jia1
LANG: C
PROG: namenum
*/
#include <stdio.h>
#include <string.h>

typedef struct {
	char src[13];
	char des[13];
} name;
name list[5000];
char map[30] = "2223334445556667777888999";

int getdes()
{
	FILE *dict;
	int i = 0, flag = 1, j = 0, c;
	dict = fopen("dict.txt", "r");
	while ((c = getc(dict)) != EOF) {
		if (flag == 0) {
			if (c != '\n')
				continue;
			else {
				flag = 1;
				j = 0;
			}
		} else if (c == 'Z' || c == 'Q') {
			flag = 0;
			continue;
		} else if (c != '\n'){
			list[i].src[j] = c;
			list[i].des[j++] = map[c - 'A'];
		} else {
			list[i].src[j] = '\0';
			list[i].des[j] = '\0';
			i++;
			j = 0;
		}
	}
	return i;
}

int main()
{
	FILE *fin, *fout;
	char num[13];
	int i, flag = 0;
	fin  = fopen("namenum.in", "r");
	fout  = fopen("namenum.out", "w");
	int len = getdes();
	fscanf(fin, "%s", num);
	for (i = 0; i < len; i++) {
		if (!strcmp(num, list[i].des)) {
			fprintf(fout, "%s\n", list[i].src);
			flag = 1;
		}
	}
	if (!flag)
		fprintf(fout, "NONE\n");
	return 0;
}
