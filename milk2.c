/*
 ID: 1990jia1
 LANG: C
 PROG: milk2
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int left;
	int right;
} intvl;

intvl time[5000];

int cmp(const void *a, const void *b)
{
	intvl *ia = (intvl *)a;
	intvl *ib = (intvl *)b;
	return ia->left > ib->left ? 1 : -1;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	FILE *fin, *fout;
	int N, i, moc, moi, start, end;
	fin = fopen("milk2.in", "r");
	fout = fopen("milk2.out", "w");

	fscanf(fin, "%d\n", &N);
	for (i = 0; i < N; i++) {
		fscanf(fin, "%d %d\n", &time[i].left, &time[i].right);
	}
	qsort(time, N, sizeof(time[0]), cmp);

	start = time[0].left;
	end = time[0].right;
	moc = end - start;
	moi = 0;
	for (i = 1; i < N; i++) {
		if (time[i].left <= end)
			end = max(end, time[i].right);
		else {
			moc = max(moc, end - start);
			moi = max(moi, time[i].left - end);
			start = time[i].left;
			end = time[i].right;
		}
	}
	fprintf(fout, "%d %d\n", moc, moi);
	return 0;
}
