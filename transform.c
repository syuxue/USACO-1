/*
 ID: 1990jia1
 LANG: C
 PROG: transform
 */
#include <stdio.h>

typedef struct {
	int n;
	char m[10][10];
} matrix;

matrix rotate(matrix a) {
	int i, j;
	matrix b;
	b.n = a.n;
	for (i = 0; i < a.n; i++) {
		for (j = 0; j < a.n; j++) {
			b.m[i][j] = a.m[a.n-1- j][i];
		}
	}
	return b;
}

matrix reflect(matrix a) {
	int i, j;
	matrix b;
	b.n = a.n;
	for (i = 0; i < a.n; i++) {
		for (j = 0; j < a.n; j++) {
			b.m[i][j] = a.m[i][a.n-1-j];
		}
	}
	return b;
}

int comp(matrix a, matrix b) {
	int i, j;
	for (i = 0; i < a.n; i++) {
		for (j = 0; j < a.n; j++) {
			if (a.m[i][j] != b.m[i][j])
				return 0;
		}
	}
	return 1;
}

int main() {
	int N, i, j;
	matrix orig, dest, trans;
	FILE *fin, *fout;
	fin = fopen("transform.in", "r");
	fout = fopen("transform.out", "w");

	fscanf(fin, "%d\n", &N);
	orig.n = N;
	dest.n = N;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			orig.m[i][j] = getc(fin);
		getc(fin);
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			dest.m[i][j] = getc(fin);
		getc(fin);
	}
	trans = orig;

	for (i = 0; i < 3; i++) {
		trans = rotate(trans);
		if (comp(trans, dest)) {
			fprintf(fout, "%d\n", ++i);
			return 0;
		}
	}

	trans = reflect(orig);
	if (comp(trans, dest)) {
		fprintf(fout, "%d\n", 4);
		return 0;
	}

	for (i = 0; i < 3; i++) {
		trans = rotate(trans);
		if (comp(trans, dest)) {
			fprintf(fout, "%d\n", 5);
			return 0;
		}
	}

	if (comp(orig, dest)) {
		fprintf(fout, "%d\n", 6);
		return 0;
	}

	fprintf(fout, "%d\n", 7);
	return 0;
}
