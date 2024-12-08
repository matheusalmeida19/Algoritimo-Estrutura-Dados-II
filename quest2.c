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

// Função para buscar um elemento na BST
Node* search(Node* root, int value) {
    if (root == NULL || root->value == value) {
        return root;
    }

    if (value < root->value) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Função para encontrar o nó com o valor mínimo (usado na remoção)
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Função para remover um elemento da BST
Node* removeNode(Node* root, int value) {
    if (root == NULL) {
        return root;
    }

    // Procurando pelo nó a ser removido
    if (value < root->value) {
        root->left = removeNode(root->left, value);
    } else if (value > root->value) {
        root->right = removeNode(root->right, value);
    } else {
        // Se o nó tem um único filho ou nenhum filho
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Se o nó tem dois filhos, pegamos o menor valor da subárvore direita
        Node* temp = minValueNode(root->right);
        root->value = temp->value;
        root->right = removeNode(root->right, temp->value);
    }

    return root;
}

// Função para realizar a travessia em ordem crescente (esquerda, raiz, direita)
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->value);
        inorderTraversal(root->right);
    }
}

// Função para realizar a travessia em ordem decrescente (direita, raiz, esquerda)
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

    // Inserindo elementos na árvore
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Árvore em ordem crescente: ");
    inorderTraversal(root);
    printf("\n");

    printf("Árvore em ordem decrescente: ");
    printDescendingOrder(root);
    printf("\n");

    // Remover um nó específico (por exemplo, 20)
    root = removeNode(root, 20);
    printf("\nÁrvore após remoção do nó 20:\n");

    // Exibir a árvore após remoção
    printf("Árvore em ordem crescente: ");
    inorderTraversal(root);
    printf("\n");

    printf("Árvore em ordem decrescente: ");
    printDescendingOrder(root);
    printf("\n");

    // Buscar um elemento (exemplo: 70)
    Node* found = search(root, 70);
    if (found != NULL) {
        printf("\nElemento 70 encontrado na árvore.\n");
    } else {
        printf("\nElemento 70 não encontrado na árvore.\n");
    }

    return 0;
}
