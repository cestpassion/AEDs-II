/*
 * INFO:
 * 
 * - As pilhas são um Tipo Abstrato de Dados (TAD) no qual o primeiro elemento que entra é o último a sair
 *     > First In, Last Out (FILO)
 * 
 * - Tem basicamente os métodos de inserir (empilhar, pop) e remover (desempilhar, push)
 * 
 * - Primeira solução IF e RF
 *     > Por exemplo, inserindo o 1, 3, 5 e 7 e efetuando duas remoções teremos:
 *                     7                               X   X
 *                 5   5                               5   X
 *             3   3   3                               3   3
 *         1   1   1   1                               1   1
 * 
 * - Segunda solução II e RI (inserção e remoção não eficientes)
 *     > Em cada inserção ou remoção, movemos todos os elementos
 *     > Por exemplo, inserindo o 1, 3, 5 e 7 e efetuando duas remoções teremos:
 *                     1                       • Primeira remoção: Retorna o 7 e move todos os demais
 *                 1   3                       • Segunda remoção: Retorna o 5 e move todos os demais
 *             1   3   5                               X   X
 *         1   3   5   7                               1   X
 *                                                     3   1
 *                                                     5   3
 */

/**
 * Pilha com Alocação Linear em C
 * @author Bruna Furtado da Fonseca
 * @version 2024-07-16
 */