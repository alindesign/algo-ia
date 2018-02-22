#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void spaceException() {
	printf("Nu exista suficient spatiu");
	exit(0);
}

int * allocList(int length) {
	int * list = (int *)malloc(length * sizeof(int));

	if (list == NULL) {
		spaceException();
		return NULL;
	}

	return list;
}

void readList(int * numbers, int length) {
	for (int i = 0; i < length; i++) {
		printf("Numar: ");
		scanf_s("%d", &numbers[i]);
	}
}

void writeList(int * numbers, int length) {
	for (int i = 0; i < length; i++) {
		printf("- %d\n", numbers[i]);
	}
}

int sumList(int * numbers, int length) {
	int sum = 0;
	for (int i = 0; i < length; i++) {
		sum += numbers[i];
	}

	return sum;
}

bool searchOnList(int * numbers, int length, int number) {
	bool found = false;

	for (int i = 0; i < length && !found; i++) {
		if (number == numbers[i]) {
			found = true;
		}
	}

	return found;
}

void switchItemsList(int * numbers, int x, int y) {
	int temp = numbers[x];
	numbers[x] = numbers[y];
	numbers[y] = temp;

}

int minList(int * numbers, int length) {
	int min = numbers[0];

	for (int i = 1; i < length; i++) {
		if (numbers[i] < min) {
			min = numbers[i];
		}
	}

	return min;
}

void removeFromList(int * numbers, int * length, int x) {
	int newMax = *length - 1;
	for (int i = x; i < newMax; i++) {
		numbers[i] = numbers[i + 1];
	}

	*length = newMax;
}

void removeValueFromList(int * numbers, int * length, int x) {
	for (int i = 0; i < *	length; i++) {
		if (numbers[i] == x) {
			removeFromList(numbers, length, i);
		}
	}
}

void main() {
	/* 1. Se da o lista de numere. Sa se calculeze suma acestora. */	int * elements = allocList(1), searchElement;	printf("Numar de elemente: ");
	scanf_s("%d", elements);

	int * numbers = allocList(* elements);

	readList(numbers, *elements);
	printf("Suma totala: %d", sumList(numbers, *elements));

	/* END 1 */

	_getch();


	/* 2. 
	 * Se da o lista de numere. Sa se verifice daca un anumit
	 * numar exista sau nu in aceasta lista. 
	 */
	printf("\nCauta un elemente: ");
	scanf_s("%d", &searchElement);

	printf("Numarul %d%s exista in lista!", searchElement, searchOnList(numbers, *elements, searchElement) ? "" : " nu");

	_getch();

	/* 3.
	 * Se da o lista de numere. Sa se schimbe valorile dintre
	 * doua pozitii date din aceasta lista.
	 */
	int x, y;

	printf("\nSchimbati elementul de pe pozitia: ");
	scanf_s("%d", &x);

	printf("Cu elementul de pe pozitia: ");
	scanf_s("%d", &y);

	printf("- Inainte:\n");
	writeList(numbers, *elements);
	
	switchItemsList(numbers, x, y);

	printf("\n- Dupa:\n");
	writeList(numbers, *elements);

	_getch();

	/*
	 * 4. Gasiti valoarea minima dintr-o lista de numere.
	 */
	printf("- Elementul minim din lista este: %d", minList(numbers, *elements));

	_getch();

	/*
	 * 5. Sa se elimine un numar aflat pe o anumita pozitie intr-o lista
	 */
	int rem;

	printf("\nStergeti elementul de pe pozitia: ");
	scanf_s("%d", &rem);

	printf("- Inainte:\n");
	writeList(numbers, *elements);

	removeFromList(numbers, elements, rem);

	printf("\n- Dupa:\n");
	writeList(numbers, *elements);

	_getch();

	/*
	 * 6. Sa se elimine un numar dat dintr-o lista data.
	 */

	int value;

	printf("\nStergeti elementul egal cu: ");
	scanf_s("%d", &value);

	printf("- Inainte:\n");
	writeList(numbers, *elements);

	removeValueFromList(numbers, elements, value);

	printf("\n- Dupa:\n");
	writeList(numbers, *elements);

	_getch();

	/*
	 * 7. Sa se adauge un numar dat pe o pozitie data intr-o lista.
	 */

	int pos;

	printf("\nIntroduceti valoarea: ");
	scanf_s("%d", &value);

	printf("Pe pozitia: ");
	scanf_s("%d", &pos);

	printf("- Inainte:\n");
	writeList(numbers, *elements);

	//pushValueToList(numbers, elements, value);

	printf("\n- Dupa:\n");
	writeList(numbers, *elements);

	_getch();
}