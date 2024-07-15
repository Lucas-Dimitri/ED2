#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Estrutura para os nós da árvore AVL
struct AVLNode
{
    string title;
    string developers;
    string publishers;
    string japan_release;
    string north_america_release;
    string PAL_region_release;
    AVLNode *left;
    AVLNode *right;
    int height;
};

// Função para obter a altura de um nó
int height(AVLNode *N)
{
    if (N == nullptr)
        return 0;
    return N->height;
}

// Função para obter o valor máximo entre dois números
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Função para criar um novo nó da árvore AVL
AVLNode *newNode(string title, string developers, string publishers, string japan_release, string north_america_release, string PAL_region_release)
{
    AVLNode *node = new AVLNode();
    node->title = title;
    node->developers = developers;
    node->publishers = publishers;
    node->japan_release = japan_release;
    node->north_america_release = north_america_release;
    node->PAL_region_release = PAL_region_release;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1; // novo nó é inicialmente adicionado como folha
    return (node);
}

// Função para rodar para a direita a subárvore com raiz em y
AVLNode *rightRotate(AVLNode *y)
{
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    // Rotação
    x->right = y;
    y->left = T2;

    // Atualização das alturas
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Retorna nova raiz
    return x;
}

// Função para rodar para a esquerda a subárvore com raiz em x
AVLNode *leftRotate(AVLNode *x)
{
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    // Rotação
    y->left = x;
    x->right = T2;

    // Atualização das alturas
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Retorna nova raiz
    return y;
}

// Função para obter o fator de balanceamento de um nó
int getBalance(AVLNode *N)
{
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

// Função para inserir um novo nó na árvore AVL
AVLNode *insert(AVLNode *node, string title, string developers, string publishers, string japan_release, string north_america_release, string PAL_region_release)
{
    // 1. Inserção normal em árvore binária de busca
    if (node == nullptr)
        return (newNode(title, developers, publishers, japan_release, north_america_release, PAL_region_release));

    if (title < node->title)
        node->left = insert(node->left, title, developers, publishers, japan_release, north_america_release, PAL_region_release);
    else if (title > node->title)
        node->right = insert(node->right, title, developers, publishers, japan_release, north_america_release, PAL_region_release);
    else // Chaves duplicadas não são permitidas
        return node;

    // 2. Atualização da altura deste ancestral nó
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Obter o fator de balanceamento deste ancestral nó para verificar se este nó ficou desbalanceado
    int balance = getBalance(node);

    // Se este nó ficar desbalanceado, então existem 4 casos

    // Caso Esquerda Esquerda
    if (balance > 1 && title < node->left->title)
        return rightRotate(node);

    // Caso Direita Direita
    if (balance < -1 && title > node->right->title)
        return leftRotate(node);

    // Caso Esquerda Direita
    if (balance > 1 && title > node->left->title)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Caso Direita Esquerda
    if (balance < -1 && title < node->right->title)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Retorna o ponteiro do nó (inalterado)
    return node;
}

// Função para gerar a saída no formato Graphviz (DOT)
void generateDot(AVLNode *node, ofstream &dotFile)
{
    if (node != nullptr)
    {
        if (node->left != nullptr)
            dotFile << "\"" << node->title << "\" -> \"" << node->left->title << "\";" << endl;
        if (node->right != nullptr)
            dotFile << "\"" << node->title << "\" -> \"" << node->right->title << "\";" << endl;
        generateDot(node->left, dotFile);
        generateDot(node->right, dotFile);
    }
}

void exportToGraphviz(AVLNode *root, const string &filename)
{
    ofstream dotFile(filename);
    dotFile << "digraph AVLTree {" << endl;
    generateDot(root, dotFile);
    dotFile << "}" << endl;
    dotFile.close();
}

int main()
{
    AVLNode *root = nullptr;

    root = insert(root, "Game A", "Dev A", "Pub A", "2022-01-01", "2022-02-01", "2022-03-01");
    root = insert(root, "Game B", "Dev B", "Pub B", "2021-01-01", "2021-02-01", "2021-03-01");
    root = insert(root, "Game C", "Dev C", "Pub C", "2020-01-01", "2020-02-01", "2020-03-01");
    root = insert(root, "Game D", "Dev D", "Pub D", "2019-01-01", "2019-02-01", "2019-03-01");
    root = insert(root, "Game E", "Dev E", "Pub E", "2018-01-01", "2018-02-01", "2018-03-01");
    root = insert(root, "Game F", "Dev F", "Pub F", "2017-01-01", "2017-02-01", "2017-03-01");
    root = insert(root, "Game G", "Dev G", "Pub G", "2016-01-01", "2016-02-01", "2016-03-01");

    // Exporta a árvore AVL para o formato Graphviz
    exportToGraphviz(root, "avltree.dot");

    cout << "Arquivo Graphviz gerado: avltree.dot" << endl;

    return 0;
}