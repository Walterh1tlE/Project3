#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "header.h"

const int MAX_SIZE = 8;
const int MAX_LENGTH = 20;

struct MARSH {
	char startPoint[MAX_LENGTH];
	char endPoint[MAX_LENGTH];
	int number;
};
static MARSH marshes[MAX_SIZE], temp[MAX_SIZE];
int kol_marsh;

extern void input() {
	printf("������� ���������� ���������: ");
	scanf_s("%d", &kol_marsh);
	register int i;
	for (i = 0; i < kol_marsh; i++) {
		printf("������� �������� ���������� ������.\n");
		scanf_s("%s", marshes[i].startPoint);
		printf("������� �������� ��������� ������.\n");
		scanf_s("%s", marshes[i].endPoint);
		printf("������� ����� ��������.\n");
		scanf_s("%d", &(marshes[i].number));
	}
	printf("\n");
}

extern void output() {
	printf("--------------------------------------------------------------\n");
	printf("| # | �������� ���������� ������ | �������� ��������� ������ |\n");
	printf("--------------------------------------------------------------\n");
	register int i;
	for (i = 0; i < kol_marsh; i++) {
		printf("| %d | %-26s | %-25s |\n", marshes[i].number, marshes[i].startPoint, marshes[i].endPoint);
	}
	printf("--------------------------------------------------------------\n");
}

extern void output_one() {
	char choice[MAX_LENGTH];
	register int i = 0;
	getchar();
	gets_s(choice, MAX_LENGTH);
	if (!strcmp(choice, marshes[i].startPoint) || !strcmp(choice, marshes[i].endPoint)) {
		printf("--------------------------------------------------------------\n");
		printf("| # | �������� ���������� ������ | �������� ��������� ������ |\n");
		printf("--------------------------------------------------------------\n");
		
		for (i = 0; i < kol_marsh; i++) {
			printf("| %d | %-26s | %-25s |\n", marshes[i].number, marshes[i].startPoint, marshes[i].endPoint);
		}
		printf("--------------------------------------------------------------\n");
	}
}

extern void sort_alfavit() {
	register int i, j, sortChoice;
	printf("����� ������� �����������:\n");
	printf("1. �� �������� ���������� ������.\n");
	printf("2. �� �������� ��������� ������.\n");
	printf("������� ���� �����: ");
	scanf_s("%d", &sortChoice);
	if (sortChoice == 1) {
		for (i = 1; i < kol_marsh; i++) for (j = kol_marsh - 1; j >= i; j--)
		{
			if (strcmp(marshes[j - 1].startPoint, marshes[j].startPoint) > 0)
			{
				temp[j] = marshes[j - 1];
				marshes[j - 1] = marshes[j];
				marshes[j] = temp[j];
			}
		}
	}
	else {
		for (i = 1; i < kol_marsh; i++) for (j = kol_marsh - 1; j >= i; j--)
		{
			if (strcmp(marshes[j - 1].endPoint, marshes[j].endPoint) > 0)
			{
				temp[j] = marshes[j - 1];
				marshes[j - 1] = marshes[j];
				marshes[j] = temp[j];
			}
		}
	}
	printf("�������� ������������� �� ��������.\n");
	output();
}
extern void Add()
{
	register int AddOrders, a;
	printf("��� ����� ������� �� ������ ��������? \n");
	scanf_s("%d", &AddOrders);
	for (a = kol_marsh; a < kol_marsh + AddOrders; a++)
	{
		printf("������� �����: ");
		scanf_s("%d", &marshes[a].number);
		printf("������� ��������� �����: ");
		scanf_s("%s", marshes[a].startPoint, MAX_LENGTH);
		printf("������� �������� �����: ");
		scanf_s("%s", marshes[a].endPoint, MAX_LENGTH);
		printf("\n");
		printf("���������� ���������.\n\n");
	}
	kol_marsh += AddOrders;
}
extern void Custom()
{
	register int cust, a;
	printf("�������� �����, ����� ��������: \n");
	scanf_s("%d", &cust);
	for (a = 0; a < kol_marsh; a++)
	{
		if (cust == marshes[a].number)
		{
			printf("������� �����: ");
			scanf_s("%d", &marshes[a].number);
			printf("������� ��������� �����: ");
			scanf_s("%s", marshes[a].startPoint, MAX_LENGTH);
			printf("������� �������� �����: ");
			scanf_s("%s", marshes[a].endPoint, MAX_LENGTH);
			a = 2 * kol_marsh;
		}
	}
}
extern void delete_info() {
	register int del, i;
	printf("�������� �����, ����� �������: \n");
	scanf_s("%d", &del);
	for (i = 0; i < kol_marsh; i++)
	{
		if (del == marshes[i].number)
		{
			while (i < kol_marsh)
			{
				marshes[i] = marshes[i + 1];
				i++;
			}
			i = kol_marsh;
			kol_marsh--;
		}
	}
}