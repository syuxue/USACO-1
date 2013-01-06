/*
ID: 1990jia1
LANG: C
PROG: gift1
*/
#include <stdio.h>
#include <string.h>

int getIndex(char nameList[10][15],char name[15],int NP);

int main()
{
	FILE *fin, *fout;
	int nets[10] = {0,0};
	char nameList[10][15];
	char name[15];
	int NP, index, outcome, income, parts,i;

    fin  = fopen("gift1.in", "r");
    fscanf(fin, "%d\n", &NP);
    for (i = 0; i < NP; i++) {
    	fscanf(fin, "%s\n", nameList[i]);
    }

    for (i = 0; i < NP; i++) {
    	fscanf(fin, "%s\n", name);
    	index = getIndex(nameList, name, NP);
    	fscanf(fin, "%d %d\n", &outcome, &parts);
    	if (parts != 0) {
    		income = outcome / parts;
    		outcome = outcome - outcome % parts;
    		nets[index] -= outcome;
    	}

    	int j;
    	for (j = 0; j < parts; j++) {
    		fscanf(fin, "%s\n", name);
    		index = getIndex(nameList, name, NP);
    		nets[index] += income;
    	}
    }
    fout = fopen("gift1.out", "w");

    for (i = 0; i < NP; i++) {
    	fprintf(fout, "%s %d\n", nameList[i], nets[i]);
    }
    return 0;
}

int getIndex(char nameList[10][15],char name[15],int NP)
{
	int i;
	for (i = 0; i < NP; i++) {
		if (strcmp(nameList[i], name) == 0)
			break;
	}
	return i;
}
