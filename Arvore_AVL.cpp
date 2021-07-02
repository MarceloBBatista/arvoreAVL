#include <iostream>
#include<locale.h>
#include<math.h>
#include <stdio.h>
#include "Cabecalho.h"

using namespace std;
int main()
{
	setlocale(LC_ALL, "Portuguese");
    NO* arvore = NULL;
    NO* q;
    int op, x, y;

    int aux = 0;
    int i = 1;
    int opcao;

    while (i != 0) {
		system("cls");
		printf("\n           ARVORE AVL      ");
		printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
		printf("\n");
		printf("\n");
		printf("\n  (1) - Insert\n   ");
		printf("\n  (2) - Remove\n ");
		printf("\n  (3) - Print Out\n ");
		printf("\n	(0) = Exit\n ");
		printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
		printf("\n\n ");
		printf("\n");
		printf("\n\n\n>> "); cin >> opcao;

		switch (opcao) {
		case 1: 
			cout << "Introduza um numero!" << endl;
			cin >> x;
			insereArvAVL(&arvore, x);
			system("pause");
			break;

		case 2:
			cout << "Remova um elemento!" << endl;
			cin >> y;
			removeArvAVL(&arvore, y);
			system("pause");
			break;

		case 3:
			imprimir(arvore);
			system("pause");
			break;

		case 0:
			cout << "Exit..." << endl;
			i = 0;
			break;
		}
    }

	return 0;
    
}


