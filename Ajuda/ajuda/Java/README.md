# Códigos Auxiliares em Java:

Este README contém exemplos de códigos em Java projetados para auxiliar no entendimento e prática de conceitos fundamentais de programação em Java. Cada exemplo é fornecido com uma explicação para ajudar a compreender o funcionamento do código e como ele pode ser utilizado em diferentes contextos.

>### ⚠️ Para melhor entendimento, debug os códigos ou use ferramentas online de vizualização de execução; como por exemplo, o [Python Tutor](https://pythontutor.com/), que possue suporte para Python, Java, C, C++ e JavaScript.

<br>

## Sumário

- [Leitura e Impressão de Números Inteiros de uma Linha em Looping](#leitura-e-impress%C3%A3o-de-strings-de-uma-linha-em-looping)

<br>

## Leitura e Impressão de Strings de uma Linha em Looping
```java
import java.util.Scanner;

public class LoopingDeEntrada {
    public static void main(String[] args){
        Scanner entrada = new Scanner(System.in);
    
        System.out.print("Digite um texto: ");
        while(entrada.hasNext()){
            System.out.println("Token: "+entrada.next());
        }
        entrada.close();
    }
}
```

#### Explicando:
* O loop while continua enquanto entrada.hasNext() retorna true. O método hasNext() verifica se ainda há mais tokens (palavras) para ler na entrada.
* Dentro do loop, entrada.next() lê o próximo token (palavra) da entrada e o imprime precedido pela mensagem "Token: ".
* O loop irá continuar lendo e imprimindo tokens até que não haja mais tokens disponíveis (por exemplo, quando o usuário pressionar Ctrl+D no Unix/Linux ou Ctrl+Z no Windows para indicar o final da entrada).

### Exemplo de entrada:
    Bom dia
    Tudo bem?
    Como vai voce?


### Exemplo de saída:
    Digite um texto:
    Token: Bom
    Token: dia
    Token: Tudo
    Token: bem?
    Token: Como
    Token: vai
    Token: voce?

<br>
