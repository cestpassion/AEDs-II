/* Foto de Relógios

- Descrição:

Você tem duas fotos de um tipo incomum de relógio. O relógio tem n ponteiros, cada um com o mesmo comprimento e nenhum tipo
de marcação. Além disso, os números do relógio estão tão desbotados que você não consegue nem dizer mais em que direção está
na imagem. Portanto, a única coisa que você vê nas fotos são os n tons dos n ponteiros e nada mais.

Você gostaria de saber se as duas imagens podem ter sido tiradas exatamente no mesmo horário do dia, possivelmente com a
câmera girada em ângulos diferentes.


- Tarefa:

Dada a descrição das duas imagens, determine se é possível que essas duas imagens possam estar mostrando o mesmo relógio
exibindo a mesma hora.


- Entrada:

A primeira linha contém um único inteiro n (2 ≤ n ≤ 200000), o número de ponteiros do relógio.

Cada uma das próximas duas linhas contém n inteiros ai (0 ≤ ai <360000), representando os ângulos dos ponteiros do relógio
em uma das imagens, em milésimos de grau.
A primeira linha representa a posição das mãos na primeira imagem, enquanto a segunda linha corresponde à segunda imagem.
O número ai denota o ângulo entre a posição registrada de alguma mão e a direção para cima na imagem, medida no sentido horário.
Os ângulos do mesmo relógio são distintos e não são fornecidos em nenhuma ordem específica.


- Saída:

Produza uma linha contendo uma palavra: possible se os relógios pudessem estar marcando a mesma hora, impossible caso o
contrário.

         .-------.           .-------.
        /         \         /    |    \
       |_____.     |       |_____|     |
       |     |     |       |           |
        \    |    /         \         /
         '-------'           '-------'
          Imagem: Exemplo de Entrada 2
*/

/**
 * @file FotoRelogio.c
 * @brief Foto de Relógios
 *
 * @author Bruna Furtado da Fonseca
 * @version 1.0, 2024-11-01
 */