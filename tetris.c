#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_FILA 5

/*
    Estrutura que representa uma peça do Tetris.
    Cada peça tem um nome (I, O, T, L, etc)
    e um ID único gerado automaticamente.
*/
struct Peca {
    char nome;
    int id;
};

/*
    Função que gera uma nova peça automaticamente.
    O nome é aleatório e o id é um número único.
*/
struct Peca gerarPeca() {
    struct Peca nova;
    char tipos[] = {'I', 'O', 'T', 'L', 'S', 'Z', 'J'};
    
    nova.nome = tipos[rand() % 7];
    nova.id = rand() % 1000 + 1; // Id entre 1 e 1000
    
    return nova;
}

/*
    Função para mostrar o conteúdo da fila circular.
*/
void mostrarFila(struct Peca fila[], int inicio) {
    printf("\n=== FILA ATUAL DE PECAS ===\n");
    printf("Pos | Nome | ID\n");
    printf("----------------------\n");

    for (int i = 0; i < TAM_FILA; i++) {
        int pos = (inicio + i) % TAM_FILA;
        printf("%3d |   %c   | %d\n", i + 1, fila[pos].nome, fila[pos].id);
    }

    printf("----------------------\n");
}

/*
    Função dequeue — remove a peça da frente da fila
    e avança o índice de início.
*/
void jogarPeca(int *inicio) {
    printf("\nPeca jogada! Avancando fila...\n");
    *inicio = (*inicio + 1) % TAM_FILA;
}

/*
    Função enqueue — insere uma nova peça no final da fila.
*/
void inserirPeca(struct Peca fila[], int inicio) {
    int fim = (inicio + TAM_FILA - 1) % TAM_FILA;

    fila[fim] = gerarPeca();
    printf("\nNova peca inserida no final da fila!\n");
}

int main() {
    srand(time(NULL));

    struct Peca fila[TAM_FILA];
    int inicio = 0;
    int opcao;

    // Inicializando a fila com 5 peças
    for (int i = 0; i < TAM_FILA; i++) {
        fila[i] = gerarPeca();
    }

    do {
        printf("\n=== MENU TETRIS STACK – NIVEL NOVATO ===\n");
        printf("1 - Jogar peca (dequeue)\n");
        printf("2 - Inserir nova peca (enqueue)\n");
        printf("3 - Visualizar fila\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:
                jogarPeca(&inicio);
                mostrarFila(fila, inicio);
                break;

            case 2:
                inserirPeca(fila, inicio);
                mostrarFila(fila, inicio);
                break;

            case 3:
                mostrarFila(fila, inicio);
                break;

            case 0:
                printf("Encerrando sistema...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
