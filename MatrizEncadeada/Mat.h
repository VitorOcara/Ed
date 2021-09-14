#ifndef MAT_H
#define MAT_H
#include <iostream>
struct node;


class Mat
{
private:
    node* head;
    node* direita;
    node* abaixo;
    int linha;
    int coluna;
    double valor;
public:

    Mat();

    ~Mat();

    /*Esse metodo le, de um arquivo de entrada, os elementos diferentes de zero de uma
    matriz e monta a estrutura especificada anteriormente. Considere que a entrada
    consiste dos valores de m e n (n´umero de linhas e de colunas da matriz) seguidos
    de triplas (i, j, valor) para os elementos diferentes de zero da matriz. */
    void lerMatriz(std::string tex);


    void criarHead(int l, int c);
    /* Esse m´etodo imprime (uma linha da matriz por linha na saıda) a matriz A, inclusive
    os elementos iguais a zero.*/
    void imprime();

    bool empty();

    /*Esse metodo insere o valor v na linha i, coluna j da matriz A. */
    void insere(int i, int j, double v);


    //função crida por Vitor Willian que retorna o valor de um elemento passando as coordenadas
    double returnValue(int i, int j);

    /* Essa fun¸c˜ao recebe como parˆametro as matrizes A e B, devolvendo uma matriz C
    que ´e a soma de A com B. */
    Mat *soma(Mat *A, Mat *B, Mat *C);
    
    /* Esse m´etodo recebe como parˆametro as matrizes A e B, devolvendo uma matriz C
    que ´e o produto de A por B. */
    Mat *multiplica(Mat *A, Mat *B, Mat *C);




};

#endif
