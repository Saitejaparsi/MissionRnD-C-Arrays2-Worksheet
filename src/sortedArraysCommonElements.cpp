/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

typedef struct transaction {
	int amount;
	char date[11];
	char description[20];
}s;
int compare(char c[11], char d[11]);
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (ALen<1||BLen<1||A==NULL||B==NULL)
		return NULL;
	else
	{
		int i, j, a,count=0;
		s **b = NULL;
		b = (s **)malloc(sizeof(s));
		for (i = 0; i < ALen; i++)
		{
			for (j = 0; j < BLen; j++)
			{
				a = compare(A->date, B->date);
				if (a == 1)
				{
					b[count] = (s *)malloc(sizeof(s));
					b[count]= A;
					count++;
				}
				if (a == -1)
					return NULL;
			}
		}
		if (count==0)
			return NULL;
		return b[0];
	}
}
int compare(char c[11], char d[11])
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
		if (m1 == m2&&m1 < 13 && m2 < 13)
		{
			if ((d1 == d2) && d1 > 0 && d1 < 32 && d2>0 && d2 < 32 && m1 != 2)
				return 1;
			else if ((d1 < d2) && d1>0 && d1 < 32 && d2>0 && d2 < 32 && m1 != 2)
				return 0;
			else if ((d1 > d2) && d1 > 0 && d1 < 32 && d2>0 && d2 < 32 && m1 != 2)
				return 0;
			else if (m1 == 2 && m2 == 2)
			{
				if ((y1 % 4 == 0 && y1 % 100 != 0 || y1 % 400 == 0) || (y2 % 4 == 0 && y2 % 100 != 0 || y2 % 400 == 0) && d1>0 && d2 > 0 && d1 < 30 && d2 < 30)
				{
					if (d1 == d2)
						return 1;
					else if (d1 > d2)
						return 0;
					else if (d1 < d2)
						return 0;
				}
				else if (d1 < 29 && d2 < 29)
				{
					if (d1 == d2)
						return 1;
					else if (d1 > d2)
						return 0;
					else if (d1 < d2)
						return 0;
				}
			}
			else
				return -1;
		}
	}
	return 0;
}







