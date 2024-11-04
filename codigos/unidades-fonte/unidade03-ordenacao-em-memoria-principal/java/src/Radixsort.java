/*
 * INFO:    BOLHA
 *
 * - Funcionamento básico
 * 
 *    * = bolha
 *    ^ = ordenado
 *     
 *      comparação  |                     array                       |   troca
 *    -----------------------------------------------------------------------------
 *       47 > 20 ?  | 101      115      30       63       47       20*|     V
 *       63 > 20 ?  | 101      115      30       63       20* <->  47 |     V
 *       30 > 20 ?  | 101      115      30       20* <->  63       47 |     V
 *      115 > 20 ?  | 101      115      20* <->  30       63       47 |     V
 *      101 > 20 ?  | 101      20* <-> 115       30       63       47 |     V
 *                  | 20^ <->  101     115       30       63       47 |     
 *  
 * 
 *    -----------------------------------------------------------------------------
 *       63 > 47 ?  | 20^      101     115       30       63       47*|     V
 *       30 > 47 ?  | 20^      101     115       30       47* <->  63 |     F
 *      115 > 30 ?  | 20^      101     115       30* ---  47       63 |     V
 *      101 > 30 ?  | 20^      101     30* <->  115       47       63 |     V
 *                  | 20^      30^ <-> 101      115       47       63 |
 * 
 * 
 *    -----------------------------------------------------------------------------
 *       47 > 63 ?  | 20^      30^     101       115      47      63*|     F
 *      115 > 47 ?  | 20^      30^     101       115      47* --- 63 |     V
 *      101 > 47 ?  | 20^      30^     101       47* <-> 115      63 |     V
 *                  | 20^      30^     47^ <->   101     115      63 |     
 *
 * 
 *    -----------------------------------------------------------------------------
 *      115 > 63 ?  | 20^      30^     47^       101      115      63*|     V
 *      101 > 63 ?  | 20^      30^     47^       101      63* <->  115|     V
 *                  | 20^      30^     47^       63^ <->  101      63 |      
 * 
 * 
 *    -----------------------------------------------------------------------------
 *     101 > 115 ?  | 20^      30^     47^       63^     101      115*|     F
 *                  | 20^      30^     47^       63^     101^ --- 115 |      
 * 
 * 
 * - Conclusão:
 *
 *      > O problema dos algoritmos de seleção e da bolha é porque eles realizam várias comparações
 *        redundantes
 *      > Além disso, a bolha faz um número quadrático de movimentações
 *      > Algoritmo estável
 * 
 * - Análise do Número de Comparações:
 * 
 *      Método de ordenação por seleção em que os registros são comparados dois a dois e o menor é
 *      movimentado para o início do array.
 * 
 *          •   C(n) = n(n-1)     , para os três casos
 *                    --------
 *                       2
 * 
 *      > Pior caso: o array está ordenado de forma decrescente
 * 
 *                            n-1
 *          •    Mmax(n) = 3 * ∑ (n - 1) = 3 * n(n-1)
 *                            i=1             --------
 *                                                2
 * 
 *      > Caso médio: depende do número de inversões em todas as permutações do array
 * 
 *          •    Mmed(n) = 3 * n(n-1)
 *                            --------
 *                               4
 */  

/**
 * Ordenação Interna - Algoritmo Radixsort em Java
 * @author Bruna Furtado da Fonseca
 * @version 2024-07-16
 */