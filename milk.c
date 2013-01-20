/*
ID: 1990jia1
LANG: C
PROG: milk
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int price;
	int amount;
} milk;

milk a[5000];

int cmp(const void *a, const void *b)
{
	milk *ia = (milk *)a;
	milk *ib = (milk *)b;
	return ia->price > ib->price ? 1 : -1;
}

int main()
{
	FILE *fin, *fout;
	int N, M, i, total;
	fin  = fopen("milk.in", "r");
	fout = fopen("milk.out", "w");
	fscanf(fin, "%d %d", &N, &M);

	for (i = 0; i < M; i++) {
		fscanf(fin, "%d %d", &a[i].price, &a[i].amount);
	}
	qsort(a, M, sizeof(a[0]), cmp);

	total = 0;
	for (i = 0; i < M; i++) {
		if (N > a[i].amount) {
			total += a[i].price * a[i].amount;
			N -= a[i].amount;
		} else {
			total += a[i].price * N;
			break;
		}
	}
	fprintf(fout, "%d\n", total);
	return 0;
}
