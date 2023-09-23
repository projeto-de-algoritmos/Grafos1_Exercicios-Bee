#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Estrutura para representar um nó de um grafo direcionado
// char visitado = "n" -> nó não visitado / char visitado = "v" -> nó visitado
struct Node {
    int valor;
	bool visitado;
	struct Node *proximo;
};

// Estrutura para representar um grafo direcionado
struct Grafo {
    int numVertices;
    struct Node** listaAdjacente;
};

// Função para criar um novo nó
struct Node* criarNo(int valor) {
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    novoNo->valor = valor;
    novoNo->proximo = NULL;
    return novoNo;
}

// Função para criar um novo grafo direcionado
struct Grafo* criarGrafo(int numVertices) {
    struct Grafo* grafo = (struct Grafo*)malloc(sizeof(struct Grafo));
    grafo->numVertices = numVertices;
    grafo->listaAdjacente = (struct Node**)malloc(numVertices * sizeof(struct Node*));

    for (int i = 0; i < numVertices; i++) {
        grafo->listaAdjacente[i] = NULL;
    }

    return grafo;
}

// Função para adicionar uma aresta direcionada ao grafo
void adicionarAresta(struct Grafo* grafo, int origem, int valor) {
    struct Node* novoNo = criarNo(valor);
    novoNo->proximo = grafo->listaAdjacente[origem];
    grafo->listaAdjacente[origem] = novoNo;
}


void DFS(struct Grafo* grafo) {
	for (int i = 0; i < grafo->numVertices; i++)
	{
		if (!grafo->listaAdjacente[i]->visitado) {
			DFSVisit(grafo, i);
		}
	}
} 

void DFSVisit(struct Grafo *grafo, int vertice) {
	// Ponteiro que aponta pro primeiro nó vizinho da lista do vértice "vertice"
	struct Node *atual = grafo->listaAdjacente[vertice];

	// Marcando o vértice como visitado
	grafo->listaAdjacente[vertice]->visitado = true;

	// Espaço para realizar operações no vértice

	// Percorrendo os vértices adjacentes
	while (atual != NULL) {
		int vizinho = atual->valor;

		if (grafo->listaAdjacente[vizinho]->visitado != true) {
			DFSVisit(grafo, vizinho);
		}

		atual = atual->proximo;
	}
}

int main() {
    int T;
    scanf("%d", &T);

	for (int t = 0; t < T; t++) {
        int N, M;
        scanf("%d %d", &N, &M);
	}



    return 0;	
}
