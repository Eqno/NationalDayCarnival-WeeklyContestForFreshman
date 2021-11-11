#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

const int MAXT = 24 * 60 * 60;

char *num_to_time(int, char*);
void gen(int);

int main()
{
	int i;
	
	srand(time(NULL));
	
	for (i=1; i<=1; i++) gen(i);
	
	return 0;
}

char *num_to_time(int t, char *res)
{
	int h, m, s;
	
	s = t % 60; t /= 60;
	m = t % 60; t /= 60;
	h = t % 24;
	sprintf(res, "%02d:%02d:%02d", h, m, s);
	return res; 
}

void gen(int n)
{
	char file_in[16], file_out[16], buf[16];
	int now, meet;
	FILE *fin, *fout;

	sprintf(file_in, "%d.in", n);
	sprintf(file_out, "%d.out", n);
	fin = fopen(file_in, "w");
	fout = fopen(file_out, "w");

	do
	{
		meet = rand() % MAXT;
	} while (!meet); 
	now = rand() % meet;

	fprintf(fin, "%s\n", num_to_time(now, buf));
	fprintf(fin, "%s\n", num_to_time(meet, buf));
	fprintf(fout, "%d\n", (meet-now));

	fclose(fin);
	fclose(fout);
}

