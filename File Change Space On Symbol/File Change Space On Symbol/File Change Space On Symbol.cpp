#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <string.h>
#include <cstdio>
#include <stdlib.h>
using namespace std;

void main()
{
	setlocale(LC_ALL, "ru");
	char ch, sl[50];
	char text[] = " one to three four";
	FILE* pf, * pr;
	pf = fopen("D:\\Code\\Лабораторная работа 8\\new1.txt", "w");
	fprintf(pf, "%s\n", text);
	fclose(pf);
	pf = fopen("D:\\Code\\Лабораторная работа 8\\new1.txt", "r");
	pr = fopen("D:\\Code\\Лабораторная работа 8\\new2.txt", "w");
	while (!feof(pr))
	{
		ch = getc(pf);

		for (char symbol; fscanf(pf, "%c", &symbol) <= 1;)
		{
			if (symbol == ' ')
			{
				symbol = (',');
			}
			fprintf(pr, "%c", symbol);
		}
		putc(ch, pr);
	}
	fclose(pr);
	rewind(pf);
	fgets(sl, 50, pf);
	printf("%s\n", sl);
	pr = fopen("D:\\Code\\Лабораторная работа 8\\new2.txt", "r");
	while (!feof(pr))
	{
		ch = getc(pr);
		putchar(ch);
	}
	fclose(pf);
	fclose(pr);
	getchar();
}
