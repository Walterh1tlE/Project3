#include <stdio.h>
#include <clocale>
#include <string.h>
#include "header.h"

int main() {
	setlocale(LC_ALL, "rus");
	int choice;
	printf("������������!\n");
	printf("�������� �������, ������� ������ ���������������.\n\n");
	do {
		printf("1. ���� ���������� � ���������.\n");
		printf("2. ����� ���������� � ���������.\n");
		printf("3. ����� ���������� �� �������� ������.\n");
		printf("4. ���������� ��������� �� ��������.\n");
		printf("5. ���������� ����������.\n");
		printf("6. ��������� ����������.\n");
		printf("7. �������� ����������.\n");
		printf("8. ����� �� ���������.\n\n");
		printf("������� ���� �����: ");
		scanf_s("%d", &choice);
		switch (choice) {
		case 1: input();
			break;
		case 2: output();
			break;
		case 3: output_one();
			break;
		case 4: sort_alfavit();
			break;
		case 5: Add();
			break;
		case 6: Custom();
			break;
		case 7: delete_info();
			break;
		case 8:
			printf("��������� ��������� ���� ������!");
			break;
		}
	} while (choice != 8);
	return 0;
}