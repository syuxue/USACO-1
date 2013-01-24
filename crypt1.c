/*
ID: 1990jia1
LANG: C
PROG: crypt1
*/
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	int *ia = (int *)a;
	int *ib = (int *)b;
	return *ia > *ib ? 1 : -1;
}

void getnum(int *dgts, int *a, int N)
{
	int i, j, k;
	for (i = 0; i < N; i++) {
		for	(j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				a[i*N*N+j*N+k] = dgts[i] * 100 + dgts[j] * 10 + dgts[k];
			}
		}
	}
}

int binsearch(int *a, int x, int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high)/2;
		if (x < a[mid])
			high = mid - 1;
		else if (x > a[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

int main()
{
	FILE *fin, *fout;
	int N, i, j, k, l, n, len, count;
	int dgts[10], a[1000], poss[10];
	fin  = fopen("crypt1.in", "r");
	fout = fopen("crypt1.out", "w");

	fscanf(fin, "%d\n", &N);
	for (i = 0; i < N; i++) {
		fscanf(fin, "%d", dgts+i);
	}
	qsort(dgts, N, sizeof(dgts[0]), cmp);
	getnum(dgts, a, N);

	count = 0;
	len = N * N * N;
	for (i = 0; i < len; i++) {
		k = 0;
		for (j = 0; j < N; j++) {
			int index = binsearch(a, a[i] * dgts[j], len);
			if (index != -1) {
				poss[k++] = a[index];
			}
		}
		for (l = 0; l < k; l++) {
			for (n = 0; n < k; n++) {
				int y = (poss[n]*10 + poss[l])/10;
				int flag = binsearch(a, y, len);
				if (flag != -1)
					count++;
			}
		}
	}

	fprintf(fout, "%d\n", count);
	return 0;
}
