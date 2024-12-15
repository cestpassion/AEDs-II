/* Lista Telefônica Econômica

- Descrição:

Devido ao grande número de reclamações, a companhia telefônica de São Petersburgo está sendo obrigada a investir pesado
na melhora de seus serviços. Para isso a companhia decidiu diminuir o orçamento de alguns setores para aumentar o de outros
mais essenciais. Um dos setores que terá seu orçamento reduzido é o de impressão de listas telefônicas.

Com um orçamento reduzido, o setor de impressão de listas telefônicas não consegue comprar toner suficiente para imprimir
as listas completas. Como os números de telefone são impressos alinhados na vertical, foi sugerida a seguinte solução: a
partir do segundo número de telefone impresso, os dígitos iniciais do próximo número a ser impresso que coincidirem com os
do número acima são omitidos, ficando apenas um espaço em branco.

Por exemplo, para os números 535456, 535488, 536566 e 835456 a impressão é a seguinte:

5 3 5 4 5 6
        8 8
    6 5 6 6
8 3 5 4 5 6

Note que esta impressão economizou a impressão de 6 caracteres. A companhia telefonica cogitou também não imprimir os
sufixos repetidos, mas nos testes feitos viram que a resposta não foi boa para o usuário e decidiram, portanto, fazer
apenas a eliminação em prefixos. Para saber se a economia será suficiente, o setor de impressão quer saber o número máximo
de caracteres que podem ser omitidos. No entanto, como em qualquer cidade grande, são vários os números telefônicos e eles
não querem gastar homens-hora para calcular manualmente este valor. Então cabe a você, novo empregado da companhia,
automatizar a economia feita pelo toner, no número de caracteres.


- Entrada:

A entrada é composta por diversas instâncias e termina com final de arquivo (EOF).
Cada caso de teste contém um inteiro N, que informa o número de telefones na lista.
As próximas N (1 ≤ N ≤ 105) linhas possuem, cada uma delas, um telefone Xi, de até 200 caracteres.
Para um mesmo caso de teste os números de telefone têm a mesma quantidade de caracteres.
Um número de telefone pode começar com o caracter ’0’.


- Saída:

Para cada caso de teste imprima uma linha informando o maior número possível de caracteres economizados por este processo.
*/

/**
 * @file ListaTelefonicaEconomica.c
 * @brief Lista Telefônica Econômica
 *
 * @author Bruna Furtado da Fonseca
 * @version 1.0, 2024-11-01
 */