/*
ID: 1990jia1
LANG: C
PROG: ride
*/
#include <stdio.h>
#include <ctype.h>

int hash(char *s);

int main() {
	FILE *fin, *fout;
	char comet[7], group[7];

    fin  = fopen("ride.in", "r");
    fout = fopen("ride.out", "w");

    fscanf(fin, "%s%s", comet, group);
	
    if (hash(comet) == hash(group))
        fprintf(fout, "%s", "GO\n");
    else
        fprintf(fout, "%s", "STAY\n");
    return 0;
}

int hash(char *s) {
    int i, h;
	h = 1;
	for(i=0; s[i] && isalpha(s[i]); i++)
		h = ((s[i]-'A'+1)*h) % 47;
	return h;
}
