/* C [PROVA 02] MINSTACK - Smallest on the Stack

- Descripton:

Every Christmas the good old man can go to every house in the world and leave gifts for the children who have been
good throughout the year, but this is only possible because of his magic gift bag. It would be impossible for Santa
to carry all the presents in his bag, the volume and weight of them all makes this obviously unfeasible. What
actually happens is that your bag is a kind of magical portal to your gift factory at the North Pole. Where the
presents are stacked by their elves and Noel always takes the gift from the top of that pile when he accesses his
magical bag.

Gifts have a numerical measure of the degree of fun they can provide children, and Santa is always concerned with
the least fun gift he will deliver throughout the night because he does not want any child to feel bad about it.
you receive. However, this can not be done in advance because throughout the night as the good old man takes gifts
from the pile to deliver, others are still being made and placed on the pile. So the most he can know is the value
of the least fun present on the stack up to that point.

Your task is, given the sequence of operations done on the stack of gifts, answer Santa's queries about the value
of the least entertaining gift on the stack thus far.


- Input:

The first line of the input contains an integer N (1 ≤ N ≤ 106) corresponding to the number of operations performed
on the present stack. The operations can be of three types: "PUSH V" where V (1 ≤ V ≤ 109) is an integer representing
the degree of fun of the present being placed on the stack; "POP" which represents that Santa Claus is taking a gift
from the cell to deliver and "MIN" representing a Noel query to know the smallest gift value in the stack.


- Output:

The output consists of a line containing an integer with the smallest present value in the stack for queries of type
"MIN" or "EMPTY" for "MIN" and "POP" operations when the stack is empty.
*/

/**
 * @file Natal.c
 * @brief C [PROVA 02] MINSTACK - Smallest on the Stack
 *
 * @author Bruna Furtado da Fonseca
 * @version 1.0, 2024-11-02
 */