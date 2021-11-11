#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	/* for memset */
#include <time.h>

const int MAXP = 1e+3;
const int MAXL = 1e+5;
const int RANGEP = MAXP + 10;

void swap(int *a, int *b)
{ *a^=*b^=*a^=*b; }
int rand_range(int min, int max)
{ return min + (rand() % (max-min+1)); }
void init(void);
void gen(int, int);
void gen_example(FILE*, int, int);

int main()
{
	init();
	
	gen(20, MAXP);
	return 0;
}

void init()
{
	srand(time(NULL));
}

void gen(int count, int maxp)
{
	char buf[16];
	int i, p, l, min, max;
	FILE *fp = NULL;

	for (i=1; i<=count; i++)
	{
		p = maxp;
		if (i < count)
		{
			min = maxp * i / count;
			max = maxp * (i+1) / count;
			p = rand_range(min, max);
		}

		l = p - 1;
		if (rand() & 1)
		{
			min = p-1;
			max = (p - 1) * p / 2;
			if (max > MAXL) max = MAXL;
			l = rand_range(min, max);
		}

		sprintf(buf, "%d.in", i);
		fp = fopen(buf, "w");

		gen_example(fp, p, l);

		fclose(fp);
	}
}

void gen_example(FILE *fp, int points, int lines)
{
	int i, j;
	int offseti, offsetj, indexl, indexr, l, r;
	int lcount, rcount, left[RANGEP], right[RANGEP];
	int count = 0, graph[RANGEP][RANGEP];
	//const int MAXLEN = INT_MAX / lines;
	const int MAXLEN = 1e5;
	/* init */
	fprintf(fp, "%d %d\n", points, lines);
	memset(graph, 0, sizeof graph);

	/* init tree generator */
	lcount = 1; rcount = points-1;
	left[0] = rand_range(1, points);
	for (i=0; i<rcount; i++)
	{
		right[i] = i+((i+1<left[0])? 1: 2);
	}

	/*
	 * generating tree
	 * which can guarantee graph connected
	 */
	for (i=1; i<points; i++)
	{
		indexl = rand() % lcount; l = left[indexl];
		indexr = rand() % rcount; r = right[indexr];
		fprintf(fp, "%d %d %d\n",
				l, r, rand_range(1, MAXLEN));
		left[lcount] = right[indexr];
		graph[l][r] = graph[r][l] = 1;
		count++;
		lcount++; rcount--;
		swap(right+indexr, right+rcount);
	}

	/* generating graph */
retry:
	if (count < lines)
	{
		/* set random offset */
		offseti = rand_range(0, points-1);
		for (i=0; i<points; i++)
		{
			l = (i + offseti) % points + 1;

			offsetj = rand_range(0, points-1);
			for (j=0; j<points; j++)
			{
				r = (j + offsetj) % points + 1;

				/* check if edge exists */
				if (l != r && !graph[l][r])
				{
					graph[l][r] = graph[r][l] = 1;
					fprintf(fp, "%d %d %d\n",
							l, r, rand_range(1, MAXLEN));
					count++;
					goto retry;
				}
			}
		}
	}
}

