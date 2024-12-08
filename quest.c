#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó da árvore
typedef struct Node {
    int value;
    struct Node *left, *right;
} Node;

// Função para criar um novo nó
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Função para inserir um novo valor na BST
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Função para realizar a travessia pós-ordem (esquerda, direita, raiz)
void postOrderTraversal(Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->value);
    }
}

// Função para exibir os elementos da árvore em ordem decrescente
void printDescendingOrder(Node* root) {
    if (root != NULL) {
        printDescendingOrder(root->right);
        printf("%d ", root->value);
        printDescendingOrder(root->left);
    }
}

// Função principal para testar as implementações
int main() {
    Node* root = NULL;
    FILE *file;
    int value;

    // Abrir o arquivo em modo de leitura
    file = fopen("entrada.txt", "r");
    
    // Verificar se o arquivo foi aberto com sucesso
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;  // Retorna um erro se não conseguir abrir o arquivo
    }

    // Ler os valores do arquivo e inserir na árvore
    while (fscanf(file, "%d", &value) != EOF) {
        root = insert(root, value);
    }

    // Fechar o arquivo após a leitura
    fclose(file);

    // Realizando a travessia pós-ordem
    printf("Pós-ordem: ");
    postOrderTraversal(root);
    printf("\n");
    
    // Exibindo a árvore em ordem decrescente
    printf("Ordem decrescente: ");
    printDescendingOrder(root);
    printf("\n");
    
    return 0;
}
