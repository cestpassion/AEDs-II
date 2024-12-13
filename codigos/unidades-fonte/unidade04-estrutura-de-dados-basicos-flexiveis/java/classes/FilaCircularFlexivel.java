/*
 * INFO:
 *
 * - As filas são um Tipo Abstrato de Dados (TAD) no qual o primeiro elemento que entra é o primeiro a sair
 *     > First In, First Out (FIFO)
 * 
 * - Tem basicamente os métodos de inserir (enfileirar, enqueue) e remover (desenfileirar, dequeue)
 * 
 * - Primeira solução IF e RI (remoção não é eficiente)
 *     > Por exemplo, inserindo o 1, 3, 5 e 7 e efetuando duas remoções teremos:
 *          1                                 • Primeira remoção: Retorna o 1 e move todos os demais
 *          1   3                                       3   5   7   X
 *          1   3   5                         • Segunda remoção: Retorna o 3 e move todos os demais
 *          1   3   5   7                               5   7   X   X
 * 
 * - Segunda solução II e RF (inserção não é eficiente)
 *     > Por exemplo, inserindo o 1, 3, 5 e 7 e efetuando duas remoções teremos:
 *          1                                 • Na primeira remoção, retiramos o número 1
 *          3   1                                       7   5   3   X
 *          5   3   1                         • Na segunda remoção, retiramos o número 3
 *          7   5   3   1                               7   5   X   X
 * 
 * - Como implementar uma fila sem que uma das operações desloque todos os elementos?
 *     R: Fazendo uma fila circular, ou seja, depois da última posição, retornamos para a primeira
 *
 */

/**
 * Fila Circular com Alocação Flexível em Java
 * @author Bruna Furtado da Fonseca
 * @version 2024-07-16
 */