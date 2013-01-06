/*
ID: 1990jia1
LANG: C
PROG: friday
*/
#include <stdio.h>
#include <ctype.h>
int main()
{
	int days, N , i;
	int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int frq[7] = {1};
	FILE *fin, *fout;
	days = 14;
	fin  = fopen("friday.in", "r");
	fout = fopen("friday.out", "w");

	fscanf(fin, "%d", &N);
	for (i = 0; i < N; i++) {
		if (i == 100) {
			months[1] = 29;
		} else if (i % 4 == 0 && i % 100 != 0) {
			months[1] = 29;
		} else
			months[1] = 28;

		int qty = 12;
		if (i == N-1)
			qty = 11;
		int j;
		for (j = 0; j < qty; j++) {
			days += months[j];
			frq[days % 7]++;
		}
	}

	for (i = 0; i < 6; i++) {
		fprintf(fout, "%d ", frq[i]);
	}
	fprintf(fout, "%d\n", frq[6]);
	return 0;
}
