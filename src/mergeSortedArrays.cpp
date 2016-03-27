/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, {30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int compare1(char c[], char d[]);
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (ALen<1 || BLen<1 || A == NULL || B == NULL)
		return NULL;
	int i, j, a,count=0;
	struct transaction *e = NULL;
	e = (struct transaction *)malloc((ALen+BLen)*sizeof(struct transaction));
	for (i =0,j=0; i <ALen&&j<BLen;)
	{
		a = compare1((A+i)->date, (B+j)->date);
		if (a == -1)
			return NULL; 
		else
		{
			if (a == 1)
			{
				e[count] = A[i];
				count++;
				i++;
				
			}
			else if (a == 2)
			{
				e[count] = B[j];
				count++;
				j++;
			}
		}
	}
	if (i < ALen)
	{
		for (i; i < ALen; i++)
		{
			e[count] = A[i];
			count++;
		}
	}
	if (j < BLen)
	{
		for (j; j < BLen; j++)
		{
			e[count] = B[j];
			count++;
		}
	}
	return e;
}
int compare1(char *c, char *d)
{
	int i;
	for (i = 0; i<10 || i<10; i++)
	{
		if ((*(c + i) <'0' || *(c + i) >'9') || (*(d + i) <'0' || *(d + i) >'9'))
			if ((*(c + i) != '-') || (*(d + i) != '-'))
				return -1;
	}
	int d1 = 0, d2 = 0, m1 = 0, m2 = 0, y1 = 0, y2 = 0;
	for (i = 0; c[i] && d[i]; i++)
	{
		if (i < 2)
		{
			if (c[i] != '-')
				d1 += c[i] - '0';
			if (d[i] != '-')
				d2 += d[i] - '0';
			if (c[i + 1] != '-')
				d1 *= 10;
			if (d[i + 1] != '-')
				d2 *= 10;
		}
		else if (i>2 && i < 5)
		{
			if (c[i] != '-')
				m1 += c[i] - '0';
			if (d[i] != '-')
				m2 += d[i] - '0';
			if (c[i + 1] != '-')
				m1 *= 10;
			if (d[i + 1] != '-')
				m2 *= 10;
		}
		else if (i > 5 && i < 10)
		{
			if (c[i] != '-')
				y1 += c[i] - '0';
			if (d[i] != '-')
				y2 += d[i] - '0';
			if (c[i + 1] != '-'&&c[i + 1] != '\0')
				y1 *= 10;
			if (d[i + 1] != '-'&&d[i + 1] != '\0')
				y2 *= 10;
		}
	}
	if (y1 == y2)
	{
		if (m1 == m2&&m1<13 && m2<13)
		{
			if ((d1 == d2) && d1>0 && d1 < 32 && d2>0 && d2 < 32 && m1 != 2)
				return 1;
			else if ((d1 < d2) && d1>0 && d1 < 32 && d2>0 && d2 < 32 && m1 != 2)
				return 1;
			else if ((d1> d2) && d1>0 && d1 < 32 && d2>0 && d2 < 32 && m1 != 2)
				return 2;
			else if (m1 == 2 && m2 == 2)
			{
				if ((y1 % 4 == 0 && y1 % 100 != 0 || y1 % 400 == 0) || (y2 % 4 == 0 && y2 % 100 != 0 || y2 % 400 == 0) && d1>0 && d2 > 0 && d1 < 30 && d2 < 30)
				{
					if (d1 == d2)
						return 1;
					else if (d1 > d2)
						return 2;
					else if (d1 < d2)
						return 1;
				}
				else if (d1 < 29 && d2 < 29)
				{
					if (d1 == d2)
						return 1;
					else if (d1 > d2)
						return 2;
					else if (d1 < d2)
						return 1;
				}
			}
			else
				return -1;
		}
		else if ((m1 < m2) && m1 > 0 && m2 > 0 && m1 < 13 && m2 < 13)
		{
			return 1;
		}
		else if ((m1 > m2) && m1 > 0 && m2 > 0 && m1 < 13 && m2 < 13)
		{
			return 2;
		}
	}
	else if (y1 < y2){
		return 1;
	}
	else if (y1 > y2){
		return 2;
	}
}
