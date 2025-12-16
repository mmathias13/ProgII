#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"
#include "ponto.h"

/********************************************************************
	TAD: Circulo (centro, raio)
	
	OBS: Nao modifique nada neste arquivo.
********************************************************************/

/* TAD Opaco */
 struct circulo{
    
    float r;
    tPonto centro;

};

/* Funcoes exportadas */

/**
 * @brief Retorna um circulo com centro nas coordenadas (x,y) e raio r
 * @param x Posição x do centro do círculo
 * @param y Posição y do centro do círculo
 * @param r Raio do Círculo
 * @return Ponteiro para a estrutura tCirculo criada 
 */
tCirculo Circulo_Cria (float x, float y, float r){
    tCirculo c = (tCirculo *)malloc(sizeof(tCirculo));
    
    c->centro = Pto_Cria(x, y);
    c->r = r;

    return c;
}

/**
 * @brief Libera a memória alocada pelo círculo
 * @param c Variável do tipo tCírculo que será apagada.
 */
void Circulo_Apaga (tCirculo c){
    
    Pto_Apaga(c->centro);
    free(c);

}

/**
 * @brief Retorna o ponto que representa o centro do circulo
 * @param c Círculo que terá o seu centro retornado
 * @return Variável do tipo ponto que representa o centro de "c"
 */
tPonto Circulo_Acessa_Centro (tCirculo c){
    return c->centro;
}

/**
 * @brief Funcao que acessa o raio do círculo
 * @param c Círculo que terá o seu raio retornado
 * @return o raio do círculo
 */
float Circulo_Acessa_Raio (tCirculo c){
    return c->r;
}

/**
 * @brief Funcao que atribui um novo centro para um círculo
 * @param c Círculo que terá o seu centro atualizado
 * @param p Ponto que representará o novo centro do círculo
 */
void Circulo_Atribui_Centro (tCirculo c, tPonto p){
    c->centro = p;
}

/**
 * @brief Funcao que atribui um novo raio para um círculo
 * @param c Círculo que terá o seu raio atualizado
 * @param r Novo raio do círculo
 */
void Circulo_Atribui_Raio (tCirculo c, float r){
    c->r = r;
}

int Circulo_Interior(tCirculo c, tPonto p) {
    float dx = Pto_Acessa_x(p) - Pto_Acessa_x(c->centro);
    float dy = Pto_Acessa_y(p) - Pto_Acessa_y(c->centro);

    float dist2 = dx*dx + dy*dy;
    float r2 = c->r * c->r;

    return (dist2 <= r2) ? 1 : 0;
}
