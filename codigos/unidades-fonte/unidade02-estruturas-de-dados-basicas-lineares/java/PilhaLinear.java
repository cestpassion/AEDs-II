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
 * Pilha com Alocação Linear em Java
 * @author Bruna Furtado da Fonseca
 * @version 2024-07-16
 */

import java.util.Scanner;

class Stack{
    // Atributos
    private int[] stack;
    private int top;

    // Construtor 1
    public Stack() {
        this(10);
    }

    // Construtor 2
    public Stack(int tam) {
        this.stack = new int[tam];
        this.top = -1;
    }

    // Métodos de Inserção
    public void push(int elemento) throws Exception {
        if(this.top >= (stack.length - 1))
            throw new Exception("Erro ao inserir o elemento! Pilha cheia.");

        stack[++top] = elemento;
    }
    
    public int pop() throws Exception {
        if(top == -1)
            throw new Exception("Erro! Não há elementos para remover.");

        return stack[top--];
    }
    

    // Método Mostrar
    public void mostrar() throws Exception {
        if(top == -1)
            throw new Exception("Erro! Não há elementos para mostrar");
        
        for(int i = top; i >= 0; --i)
            System.out.println("[" + i + "]\t" + stack[i]);
    }
    

    // // Método Pesquisar
    // public boolean pesquisar() {
    
    // }

    // // Método Ordenar
    // public void ordenar() {
    
    // }
}

public class PilhaLinear{
    int
}