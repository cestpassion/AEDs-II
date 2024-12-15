/* C [PROVA 02] Max o Fotógrafo

- Descrição:

Max foi contratado para fotografar 2n pessoas. A i-ésima pessoa mede hi centímetros.
Para isso, ele colocou as pessoas em 2 fileiras de frente para Max, cada uma com n pessoas. Porém, para garantir
que as pessoas das duas fileiras irão aparecer na foto, a j-ésima pessoa da fileira de trás precisa ser X
centímetros maior que a j-ésima pessoa da fileira da frente, para cada j entre 1 e n, inclusive. 

Ajude o Max a definir se isso é possível.


- Entrada: 

A primeira linha possui um número inteiro t ( 1 ≤ t ≤ 104) – indicando o número de testes, cada um com duas linhas. 

A primeira linha de cada teste contem dois inteiros positivos n e x (1 ≤ n ≤ 100, 1 ≤ x ≤ 1000) - indicando o número
de pessoas em cada fileira e o mínimo de centímetros que elas precisam ter de diferença. 

A segunda linha de cada teste contém 2n inteiros positivos h1, h2, ....., h2n (1 ≤ hi ≤ 1000) - indicando a altura
em centímetros de cada pessoa. 


- Saída:

Para cada caso de teste, imprima “SIM” (sem aspas) se Max conseguir ajeitar as pessoas de forma a satisfazer a
condição, e “NAO” (sem aspas e sem acento) se não satisfazer.
*/

/**
 * @file MaxFotografo.c
 * @brief C [PROVA 02] Max o Fotógrafo
 *
 * @author Bruna Furtado da Fonseca
 * @version 1.0, 2024-11-01
 */