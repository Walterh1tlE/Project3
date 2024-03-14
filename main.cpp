#include <stdio.h>
#include <clocale>
#include <string.h>
#include "header.h"

int main() {
	setlocale(LC_ALL, "rus");
	int choice;
	printf("Здравствуйте!\n");
	printf("Выберите функцию, которой хотите воспользоваться.\n\n");
	do {
		printf("1. Ввод информации о маршрутах.\n");
		printf("2. Вывод информации о маршрутах.\n");
		printf("3. Вывод информации по названию пункта.\n");
		printf("4. Сортировка маршрутов по алфавиту.\n");
		printf("5. Добавление информации.\n");
		printf("6. Изменение информации.\n");
		printf("7. Удаление информации.\n");
		printf("8. Выход из программы.\n\n");
		printf("Введите свой выбор: ");
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
			printf("Программа закончила свою работу!");
			break;
		}
	} while (choice != 8);
	return 0;
}