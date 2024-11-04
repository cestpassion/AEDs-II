/**
 * Matriz Dinâmica em Java
 * @author Bruna Furtado da Fonseca
 * @version 2024-07-16
 */

/*
 * Complete o código da classe matriz dinâmica visto na sala de aula.
 * 
 * A primeira tarefa consiste em, no construtor da classe Matriz, dados os números de linha e coluna, fazer as devidas
 * alocações de células.
 * 
 * As demais tarefas são as implementações dos métodos:
 *  - Matriz soma(Matriz)
 *  - Matriz multiplicacao(Matriz)
 *  - void mostrarDiagonalPrincipal()
 *  - void mostrarDiagonalSecundaria(). 
 * 
 * ENTRADA:
 * 
 * - A entrada padrão é composta por vários casos de teste sendo que o número de casos é um inteiro contido na primeira
 *   linha da entrada. 
 * 
 * - Em seguida, temos cada um dos casos de teste. Cada caso é composto por duas matrizes.
 * 
 * - Para cada caso de teste, temos que suas duas primeiras linhas contêm um número inteiro cada um representando os
 *   números de linhas e de colunas da primeira matriz, respectivamente.
 * 
 * - Em seguida, temos os elementos da primeira matriz que estão representados nas próximas l linhas onde l é o número de
 *   linhas dessa matriz.
 * 
 * - Cada uma dessas linhas têm c colunas onde c é o número de colunas dessa matriz.
 * 
 * - Nas duas linhas seguintes, temos os números de linhas e colunas da segunda matriz do caso de teste.
 * 
 * - As l2 linhas seguintes têm c2 colunas contendo os elementos da segunda matriz.
 * 
 * - l2 e c2 correspondem aos números de linhas e colunas da segunda matriz do caso de teste, respectivamente.
 * 
 * SAÍDA:
 * 
 * - A saída padrão contém várias linhas para cada caso de teste.
 * 
 *   > As duas primeiras linhas de saída de um caso de teste correspondem às diagonais principal e secundaria da primeira
 *     matriz, respectivamente.
 *
 *   > As demais ls linhas de um caso de teste correspondem as linhas matriz obtida pela soma das duas matrizes do caso
 *     de teste sendo que essas linhas contêm cs colunas referentes às colunas da matriz de soma. Da mesma forma, as
 *     linhas seguintes do caso teste contêm lm linhas com cm colunas representando os elementos da matriz de
 *     multiplicação onde lm e cm são os números de linhas e colunas da matriz de multiplicação.
 */

/*
 * INFO:
 * 
 */

import java.util.Date;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

class Pokemon {
    // Atributos
    private int id;
    private int generation;
    private String name;
    private String description;
    private List<String> types;
    private List<String> abilities;
    private double weight;
    private double height;
    private int captureRate;
    private boolean isLegendary;
    private Date captureDate;

    // Contrutor 1
    public Pokemon() {
        this.id = 0;
        this.generation = 0;
        this.name = null;
        this.description = null;
        this.types = new ArrayList<>();
        this.abilities = new ArrayList<>();
        this.weight = 0;
        this.height = 0;
        this.captureRate = 0;
        this.isLegendary = false;
        this.captureDate = null;
    }

    // Contrutor 2
    public Pokemon(int id, int generation, String name, String description, List<String> types, List<String> abilities,
            double weight, double height, int captureRate, boolean isLegendary, Date captureDate) {
        this.id = id;
        this.generation = generation;
        this.name = name;
        this.description = description;
        this.types = types;
        this.abilities = abilities;
        this.weight = weight;
        this.height = height;
        this.captureRate = captureRate;
        this.isLegendary = isLegendary;
        this.captureDate = captureDate;
    }

    // Métodos get
    public int getId() {
        return this.id;
    }

    public int getGeneration() {
        return this.generation;
    }

    public String getName() {
        return this.name;
    }

    public String getDescription() {
        return this.description;
    }

    public List<String> getTypes() {
        return this.types;
    }

    public List<String> getAbilities() {
        return this.abilities;
    }

    public double getWeight() {
        return this.weight;
    }

    public double getHeight() {
        return this.height;
    }

    public int getCaptureRate() {
        return this.captureRate;
    }

    public boolean getIsLegendary() {
        return this.isLegendary;
    }

    public Date getCaptureDate() {
        return this.captureDate;
    }

    // Métodos set
    public void setId(int id) {
        this.id = id;
    }

    public void setGeneradion(int generation) {
        this.generation = generation;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public void setTypes(List<String> types) {
        this.types = types;
    }

    public void setAbilities(List<String> abilities) {
        this.abilities = abilities;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public void setCaptureRate(int captureRate) {
        this.captureRate = captureRate;
    }

    public void setIsLegendary(boolean isLegendary) {
        this.isLegendary = isLegendary;
    }

    public void setCaptureDate(Date captureDate) {
        this.captureDate = captureDate;
    }

    /**
     * Lê uma linha do arquivo pokemon.csv e armazena os objetos:
     * id, generation, name, description, types, abilities, weight, height,
     * captureRate,
     * isLegendary e captureDate.
     *
     * @param line String com linha a ser lida
     */
    public void ler(String line) {
        line = line.replaceAll("\"", "");
        String[] lineSplitted = line.split("[\\[\\]]");
        lineSplitted[2] = lineSplitted[2].substring(1);

        // id, generation, name, descripstion
        int comma = lineSplitted[0].indexOf(",");
        for (int i = 0; i < 3; i++)
            comma = lineSplitted[0].indexOf(",", ++comma);

        String subString = lineSplitted[0].substring(0, comma);
        String[] attributes = subString.split(",");

        this.setId(Integer.parseInt(attributes[0]));
        this.setGeneradion(Integer.parseInt(attributes[1]));
        this.setName(attributes[2]);
        this.setDescription(attributes[3]);

        // types
        int start = comma + 1;
        for (int i = 0; i < 2; i++)
            comma = lineSplitted[0].indexOf(",", ++comma);

        subString = lineSplitted[0].substring(start, comma);
        List<String> listAttributes = Arrays.asList(subString.split(","));

        for (int i = 0; i < listAttributes.size(); i++)
            listAttributes.set(i, "'" + listAttributes.get(i) + "'");

        this.setTypes(listAttributes);

        // abilities
        listAttributes = Arrays.asList(lineSplitted[1].split(","));

        for (int i = 0; i < listAttributes.size(); i++)
            listAttributes.set(i, listAttributes.get(i).trim());

        this.setAbilities(listAttributes);

        // weight, height, captureRate, isLegendary, captureDate
        attributes = lineSplitted[2].split(",");

        if (attributes[0] != "") {
            this.setWeight(Double.parseDouble(attributes[0]));
        }
        if (attributes[1] != "") {
            this.setHeight(Double.parseDouble(attributes[1]));
        }
        this.setCaptureRate(Integer.parseInt(attributes[2]));
        this.setIsLegendary(convertBool(attributes[3]));
        this.setCaptureDate(convertDate(attributes[4]));
    }

    /**
     * Converte uma String com um número inteiro 0 ou 1 em tipo boolean
     *
     * @param str String com um número inteiro 0 ou 1
     * @return true / false
     */
    public boolean convertBool(String str) {
        if (str.equals("1"))
            return true;
        else
            return false;
    }

    /**
     * Converte uma String com uma data para o tipo Date
     *
     * @param str String com uma data
     * @return data tipo Date / null
     */
    public Date convertDate(String str) {
        SimpleDateFormat outputFormat = new SimpleDateFormat("dd/MM/yyyy");
        try {
            return outputFormat.parse(str);
        } catch (ParseException e) {
            System.err.println("Erro ao converter a data: " + e.getMessage());
            return null;
        }
    }

    /**
     * Imprime o pokemon selecionado
     */
    public void imprimir() {
        SimpleDateFormat outputFormat = new SimpleDateFormat("dd/MM/yyyy");
        String formattedDate = outputFormat.format(this.getCaptureDate());

        System.out.println(
                "[#" + this.getId() + " -> " + this.getName() + ": " + this.getDescription() + " - " + this.getTypes()
                        + " - " + this.getAbilities() + " - " + this.getWeight() + "kg - " + this.getHeight() + "m - "
                        + this.getCaptureRate()
                        + "% - " + this.getIsLegendary() + " - " + this.getGeneration() + " gen] - " + formattedDate);
    }

    /**
     * Clona o pokemon selecionado
     *
     * @return pokemon clonado
     */
    public Pokemon clone() {
        Pokemon clone = new Pokemon();

        clone.id = this.id;
        clone.generation = this.generation;
        clone.name = this.name;
        clone.description = this.description;
        clone.types = this.types;
        clone.abilities = this.abilities;
        clone.weight = this.weight;
        clone.height = this.height;
        clone.captureRate = this.captureRate;
        clone.isLegendary = this.isLegendary;
        clone.captureDate = this.captureDate;

        return clone;
    }
}

/**
 * Classe que representa uma célula da matriz com ponteiros para células
 * adjacentes (cima, baixo, esquerda e direita).
 * Cada célula armazena um valor int.
 */
class Celula {
    public int elemento; // valor armazenado na célula
    public Celula inf; // Ponteiro para a célula inferior
    public Celula sup; // Ponteiro para a célula superior
    public Celula esq; // Ponteiro para a célula à esquerda
    public Celula dir; // Ponteiro para a célula à direita

    /**
     * Construtor padrão que inicializa o elemento da célula como null.
     */
    public Celula() {
        this(0);
    }

    /**
     * Construtor que inicializa o valor da célula com o valor fornecido.
     * 
     * @param elemento valor a ser armazenado na célula.
     */
    public Celula(int elemento) {
        this(elemento, null, null, null, null);
    }

    /**
     * Construtor completo que inicializa todos os valores e os ponteiros da célula.
     * 
     * @param elemento valor a ser armazenado na célula.
     * @param inf      Ponteiro para a célula inferior.
     * @param sup      Ponteiro para a célula superior.
     * @param esq      Ponteiro para a célula à esquerda.
     * @param dir      Ponteiro para a célula à direita.
     */
    public Celula(int elemento, Celula inf, Celula sup, Celula esq, Celula dir) {
        this.elemento = elemento;
        this.inf = inf;
        this.sup = sup;
        this.esq = esq;
        this.dir = dir;
    }
}

/**
 * Classe que representa uma matriz bidimensional utilizando células duplamente
 * encadeadas.
 * Permite operações de soma e multiplicação de matrizes, além de exibir as
 * diagonais principal e secundária.
 */
class DinamicMatriz {
    private Celula start; // Célula inicial da matriz, localizada no canto superior esquerdo
    private int row; // Número de linhas da matriz
    private int column; // Número de colunas da matriz

    /**
     * Construtor padrão que cria uma matriz 3x3 com células inicializadas.
     */
    public DinamicMatriz() {
        this(3, 3);
    }

    /**
     * Construtor que cria uma matriz com o número de linhas e colunas especificado.
     * As células da matriz são duplamente encadeadas em todas as direções.
     * 
     * @param row  Número de linhas da matriz.
     * @param column Número de colunas da matriz.
     */
    public DinamicMatriz(int row, int column) {
        this.row = row;
        this.column = column;

        // Alocar a matriz com this.row linhas e this.column colunas
        // Criação e ligação das células
        start = new Celula(); // Inicializa a célula de início
        Celula rowCurrent = start; // Controla a célula inicial de cada linha

        for (int i = 0; i < row; i++) { // Percorre todas as linhas
            Celula columnCurrent = rowCurrent; // Controla a célula de cada coluna dentro da linha

            for (int j = 1; j < column; j++) { // Cria e liga células na linha
                columnCurrent.dir = new Celula(); // Cria célula à direita
                columnCurrent.dir.esq = columnCurrent; // Liga célula à esquerda
                columnCurrent = columnCurrent.dir; // Avança para a próxima célula na linha
            }
            if (i < row - 1) { // Caso não seja a última linha, cria uma nova linha
                rowCurrent.inf = new Celula(); // Cria célula inferior para a próxima linha
                rowCurrent.inf.sup = rowCurrent; // Liga célula superior
                rowCurrent = rowCurrent.inf; // Avança para a próxima linha
            }
        }
    }

}

public class MatrizDinamica {
    public static List<Pokemon> pokemonStorage;

    public static Pokemon search(int id) {
        for (Pokemon p : pokemonStorage) {
            if (id == p.getId()) {
                return p;
            }
        }
        return null;
    }

    public static void main(String[] args) throws NumberFormatException, Exception {
        try (BufferedReader br = new BufferedReader(new FileReader("pokemon.csv"))) { // verde.icei.pucminas.br/tmp/pokemon.csv
            String line;
            pokemonStorage = new ArrayList<>();

            br.readLine(); // Lê a primeira linha (cabeçalho)
            while ((line = br.readLine()) != null) {
                Pokemon p = new Pokemon();
                p.ler(line);
                pokemonStorage.add(p);
            }
        } catch (IOException e) {
            System.err.println("Erro ao ler o arquivo: " + e.getMessage());
        }

        Scanner sc = new Scanner(System.in);
        String str;
        DinamicMatriz pokemon = new DinamicMatriz();

        while (!(str = sc.nextLine()).equals("FIM"))
            pokemon.push(search(Integer.parseInt(str)));

        int operations = sc.nextInt(); // Quantidade de registros a serem inseridos/removidos
        sc.nextLine(); // Lê o quebralinha
        int cont = 0;

        while (cont < operations) {
            str = sc.nextLine();

            String[] subString = str.split(" ");

            switch (subString[0]) {
                case "I":
                    pokemon.push(search(Integer.parseInt(subString[1])));
                    break;

                case "R":
                    System.out.println("(R) " + pokemon.pop().getName());
                    break;

                default:
                    break;
            }
            cont++;
        }
        pokemon.mostraRecursivo();
        sc.close();
    }
}