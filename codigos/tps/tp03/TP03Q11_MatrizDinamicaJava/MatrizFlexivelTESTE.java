import java.util.Scanner;

class Celula {
    public int valor;
    public Celula esquerda, direita, acima, abaixo;

    Celula() {
        this.valor = 0;
        this.esquerda = this.direita = this.acima = this.abaixo = null;
    }
}

class Matriz {
    private Celula primeira;
    private int totalLinhas, totalColunas;

    Matriz() {
        primeira = criarLinha();
        Celula novaLinha = criarLinha();

        for (Celula atual = primeira, proxima = novaLinha; atual != null; atual = atual.direita) {
            atual.abaixo = proxima;
            proxima.acima = atual;
            proxima = proxima.direita;
        }
        totalLinhas = 2;
        totalColunas = 2;
    }

    private Celula criarLinha() {
        Celula inicio = new Celula();
        Celula fim = new Celula();
        inicio.direita = fim;
        fim.esquerda = inicio;
        return inicio;
    }

    private Celula criarLinha(int tamanho) {
        Celula inicio = new Celula();
        Celula atual = inicio;

        for (int i = 1; i < tamanho; i++) {
            Celula nova = new Celula();
            atual.direita = nova;
            nova.esquerda = atual;
            atual = nova;
        }
        return inicio;
    }

    private Celula criarColuna(int tamanho) {
        Celula inicio = new Celula();
        Celula atual = inicio;

        for (int i = 1; i < tamanho; i++) {
            Celula nova = new Celula();
            atual.abaixo = nova;
            nova.acima = atual;
            atual = nova;
        }
        return inicio;
    }

    public void adicionarLinha() {
        Celula ultima = primeira;
        while (ultima.abaixo != null) {
            ultima = ultima.abaixo;
        }
        Celula novaLinha = criarLinha(totalColunas);
        for (Celula atual = ultima, nova = novaLinha; nova != null; nova = nova.direita) {
            atual.abaixo = nova;
            nova.acima = atual;
            atual = atual.direita;
        }
        totalLinhas++;
    }

    public void adicionarColuna() {
        Celula ultima = primeira;
        while (ultima.direita != null) {
            ultima = ultima.direita;
        }
        Celula novaColuna = criarColuna(totalLinhas);
        for (Celula atual = ultima, nova = novaColuna; nova != null; nova = nova.abaixo) {
            atual.direita = nova;
            nova.esquerda = atual;
            atual = atual.abaixo;
        }
        totalColunas++;
    }

    public void inserirValor(int valor, int linha, int coluna) {
        if (linha < 0 || linha >= totalLinhas || coluna < 0 || coluna >= totalColunas) {
            throw new IllegalArgumentException("Posição inválida");
        }
        Celula atual = primeira;
        for (int i = 0; i < linha; i++) {
            atual = atual.abaixo;
        }
        for (int i = 0; i < coluna; i++) {
            atual = atual.direita;
        }
        atual.valor = valor;
    }

    public void exibirDiagonalPrincipal() {
        if (totalLinhas != totalColunas) {
            throw new IllegalStateException("A matriz não é quadrada");
        }
        Celula atual = primeira;
        while (atual != null) {
            System.out.print(atual.valor + " ");
            atual = atual.direita;
            if (atual != null) {
                atual = atual.abaixo;
            }
        }
        System.out.println();
    }

    public void exibirDiagonalSecundaria() {
        if (totalLinhas != totalColunas) {
            throw new IllegalStateException("A matriz não é quadrada");
        }
        Celula atual = primeira;
        while (atual.direita != null) {
            atual = atual.direita;
        }
        while (atual != null) {
            System.out.print(atual.valor + " ");
            atual = atual.esquerda;
            if (atual != null) {
                atual = atual.abaixo;
            }
        }
        System.out.println();
    }

    public void exibir() {
        for (Celula linha = primeira; linha != null; linha = linha.abaixo) {
            for (Celula coluna = linha; coluna != null; coluna = coluna.direita) {
                System.out.print(coluna.valor + " ");
            }
            System.out.println();
        }
    }

    public static void somarMatrizes(Matriz a, Matriz b) {
        Celula linhaA = a.primeira, linhaB = b.primeira;
        while (linhaA != null && linhaB != null) {
            Celula colunaA = linhaA, colunaB = linhaB;
            while (colunaA != null && colunaB != null) {
                System.out.print((colunaA.valor + colunaB.valor) + " ");
                colunaA = colunaA.direita;
                colunaB = colunaB.direita;
            }
            System.out.println();
            linhaA = linhaA.abaixo;
            linhaB = linhaB.abaixo;
        }
    }

    public static void multiplicarMatrizes(Matriz a, Matriz b) {
        if (a.totalColunas != b.totalLinhas) {
            throw new IllegalStateException("As matrizes não podem ser multiplicadas");
        }
        for (Celula linhaA = a.primeira; linhaA != null; linhaA = linhaA.abaixo) {
            for (Celula colunaB = b.primeira; colunaB != null; colunaB = colunaB.direita) {
                int soma = 0;
                Celula atualA = linhaA, atualB = colunaB;
                while (atualA != null && atualB != null) {
                    soma += atualA.valor * atualB.valor;
                    atualA = atualA.direita;
                    atualB = atualB.abaixo;
                }
                System.out.print(soma + " ");
            }
            System.out.println();
        }
    }
}

public class MatrizFlexivel {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int numInstancias = sc.nextInt();
        while (numInstancias-- > 0) {
            Matriz matrizA = new Matriz();
            Matriz matrizB = new Matriz();

            int linhas = sc.nextInt(), colunas = sc.nextInt();
            for (int i = 2; i < linhas; i++) matrizA.adicionarLinha();
            for (int i = 2; i < colunas; i++) matrizA.adicionarColuna();
            for (int i = 0; i < linhas; i++)
                for (int j = 0; j < colunas; j++)
                    matrizA.inserirValor(sc.nextInt(), i, j);

            linhas = sc.nextInt();
            colunas = sc.nextInt();
            for (int i = 2; i < linhas; i++) matrizB.adicionarLinha();
            for (int i = 2; i < colunas; i++) matrizB.adicionarColuna();
            for (int i = 0; i < linhas; i++)
                for (int j = 0; j < colunas; j++)
                    matrizB.inserirValor(sc.nextInt(), i, j);

            matrizA.exibirDiagonalPrincipal();
            matrizA.exibirDiagonalSecundaria();
            Matriz.somarMatrizes(matrizA, matrizB);
            Matriz.multiplicarMatrizes(matrizA, matrizB);
        }

        sc.close();
    }
}
