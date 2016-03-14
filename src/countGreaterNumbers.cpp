/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int compare(char *c,char *d);
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	if (len<1||Arr==nullptr)
		return -1;
	else{
		int i,a;
		for (i = 0; i < len;i++ )
		{
			a = compare((Arr+i)->date,date);
			if (a == 1)
			{
				return len - i;
			}
			if (a == -1)
				return -1;
		}
	}
	return 0;
}
int compare(char *c, char *d)
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
			if ((d1 == d2) && d1>0 && d1 < 32 && d2>0 && d2 < 32 && m1 != 2 )
				return 0;
			else if ((d1 < d2) && d1>0 && d1 < 32 && d2>0 && d2 < 32 && m1 != 2)
				return 0;
			else if ((d1> d2) && d1>0 && d1 < 32 && d2>0 && d2 < 32 && m1 != 2 )
				return 1;
			else if (m1 == 2 && m2 == 2)
			{
				if ((y1 % 4 == 0 && y1 % 100 != 0 || y1 % 400 == 0) || (y2 % 4 == 0 && y2 % 100 != 0 || y2 % 400 == 0) && d1>0 && d2 > 0 && d1 < 30 && d2 < 30)
				{
					if (d1 == d2)
						return 0;
					else if (d1 > d2)
						return 1;
					else if (d1 < d2)
						return 0;
				}
				else if (d1 < 29 && d2 < 29)
				{
					if (d1 == d2)
						return 0;
					else if (d1 > d2)
						return 1;
					else if (d1 < d2)
						return 0;
				}
			}
			else
				return -1;
		}
		else if ((m1 < m2) && m1 > 0 && m2 > 0 && m1 < 13 && m2 < 13)
		{
			return 0;
		}
		else if ((m1 > m2) && m1 > 0 && m2 > 0 && m1 < 13 && m2 < 13)
		{
			return 1;
		}
	}
	else if (y1 < y2){
		return 0;
	}
	else if (y1 > y2){
		return 1;
	}
}
