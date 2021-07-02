#include <iostream>
#include<locale.h>
#include<math.h>
#include <stdio.h>
#include "Cabecalho.h"

using namespace std;

struct NO
{
	int informacao;
	int altura;
	struct NO* esquerda;
	struct NO* direita;
};

// Função auxiliar altura de um nó
int alt_no(struct NO* no) {
	if (no == NULL) {
		return -1;
	}
	else {
		return no->altura;
	}
}


//calcula o balanceamento de um nó.
int balanceamento_NO(struct NO* no) {
	return labs(alt_no(no->esquerda) - alt_no(no->direita));
}

//calcula o maior valor
int maior(int x, int y) {
	if (x > y) {
		return x;
	}
	else
	{
		return y;
	}
}

//Funções de rotação

void RotacaoLL(Arv_AVL* raiz) {

	struct NO* no;
	no = (*raiz)->esquerda;
	(*raiz)->esquerda = no->direita;
	no->direita = (*raiz);
	(*raiz)->altura = maior(alt_no((*raiz)->esquerda), alt_no((*raiz)->direita) + 1);

	no->altura = maior(alt_no(no->esquerda), (*raiz)->altura + 1);

	*raiz = no;
}

void RotacaoRR(Arv_AVL* raiz) {

	struct NO* no;
	no = (*raiz)->direita;
	(*raiz)->direita = no->esquerda;
	no->esquerda = (*raiz);
	(*raiz)->altura = maior(alt_no((*raiz)->esquerda), alt_no((*raiz)->direita) + 1);

	no->altura = maior(alt_no(no->direita), (*raiz)->altura + 1);

	*raiz = no;

}

void RotacaoLR(Arv_AVL* raiz) {

	RotacaoRR(&(*raiz)->esquerda);
	RotacaoLL(raiz);
}

void RotacaoRL(Arv_AVL* raiz) {

	RotacaoLL(&(*raiz)->direita);
	RotacaoRR(raiz);
}

//Função de inserção
int insereArvAVL(Arv_AVL* raiz, int valor) {

	int res;
	if (*raiz == NULL) {
		struct NO* novo;
		novo = (struct NO*)malloc(sizeof(struct NO));

		if (novo == NULL) {
			return 0;
		}

		novo->informacao = valor;
		novo->altura = 0;
		novo->esquerda = NULL;
		novo->direita = NULL;
		*raiz = novo;
		return 1;
	}

	struct NO* atual = *raiz;
	if (valor < atual->informacao) {
		if (res = insereArvAVL(&(atual->esquerda), valor) == 1) {
			if (balanceamento_NO(atual) >= 2) {
				if (valor < (*raiz)->esquerda->informacao) {
					RotacaoLL(raiz);
				}
				else
				{
					RotacaoLR(raiz);
				}
			}
		}
	}
	else
	{
		if (valor > atual->informacao) {
			if (res = insereArvAVL(&(atual->direita), valor) == 1) {
				if (balanceamento_NO(atual) >= 2) {
					if ((*raiz)->direita->informacao < valor) {
						RotacaoRR(raiz);
					}
					else
					{
						RotacaoRL(raiz);
					}
				}
			}
		}
		else {
			cout << "Valor duplicado" << endl;
			return 0;
		}
	}
	atual->altura = maior(alt_no(atual->esquerda), alt_no(atual->direita)) + 1;
	return res;
}

//Função de remover
int removeArvAVL(Arv_AVL* raiz, int valor) {

	if (*raiz == NULL) {
		cout << "ERROR!" << endl << "Valor inexistente." << endl;
		return 0;
	}
	int res;
	if (valor < (*raiz)->informacao) {
		if ((res = removeArvAVL(&(*raiz)->esquerda, valor)) == 1) {
			if (balanceamento_NO(*raiz) >= 2) {
				if (alt_no((*raiz)->direita->esquerda) <= alt_no((*raiz)->direita->direita)) {
					RotacaoRR(raiz);
				}
				else
				{
					RotacaoRL(raiz);
				}
			}
		}
	}if ((*raiz)->informacao < valor) {
		if ((res = removeArvAVL(&(*raiz)->direita, valor)) == 1) {
			if (balanceamento_NO(*raiz) >= 2) {
				if (alt_no((*raiz)->esquerda->direita) <= alt_no((*raiz)->esquerda->esquerda)) {
					RotacaoLL(raiz);
				}
				else
				{
					RotacaoLR(raiz);
				}
			}
		}
	}if ((*raiz)->informacao == valor) {
		if (((*raiz)->esquerda == NULL || (*raiz)->direita == NULL)) {
			struct NO* oldNode = (*raiz);
			if ((*raiz)->esquerda != NULL) {
				*raiz = (*raiz)->esquerda;
			}
			else
			{
				*raiz = (*raiz)->direita;
			}
			free(oldNode);
		}
		else
		{
			struct NO* temp = buscarMenor((*raiz)->direita);
			(*raiz)->informacao = temp->informacao;
			removeArvAVL(&(*raiz)->direita, (*raiz)->informacao);
			if (balanceamento_NO(*raiz) >= 2) {
				if (alt_no((*raiz)->esquerda->direita) <= alt_no((*raiz)->esquerda->esquerda)) {
					RotacaoLL(raiz);
				}
				else
				{
					RotacaoLR(raiz);
				}
			}
		}
		return 1;
	}
	return res;
}

struct NO* buscarMenor(struct NO* atual) {

	struct NO* no1 = atual;
	struct NO* no2 = atual->esquerda;
	while (no2 != NULL)
	{
		no1 = no2;
		no2 = no2->esquerda;
	}
	return no1;
}

void imprimir(NO* raiz) {
	if (raiz == NULL) {

		cout << " " << endl;
		return;
	}
	if (raiz != NULL) {
		cout << (raiz)->informacao << "  ";
		imprimir(((raiz)->esquerda));
		imprimir(((raiz)->direita));
	}
	;

}