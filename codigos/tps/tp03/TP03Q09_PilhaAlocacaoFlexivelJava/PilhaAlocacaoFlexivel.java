/**
 * Pilha com Alocação Flexível em Java
 * @author Bruna Furtado da Fonseca
 * @version 2024-07-16
 */

/*
 * Refaça a questão 6 deste TP
 */

/*
 * INFO:
 * 
 */

/**
* Lista com Alocação Sequencial em Java
* @author Bruna Furtado da Fonseca
* @version 2024-07-16
*/

/* 
 * Crie uma Lista de registros baseada na de inteiros vista na sala de aula. Sua lista deve conter todos os atributos e
 * métodos existentes na lista de inteiros, contudo, adaptados para a classe Pokémon. Lembre-se que, na verdade, temos uma
 * lista de ponteiros (ou referências) e cada um deles aponta para um registo.
 * 
 * Neste exercício, faremos inserções, remoções e mostraremos os elementos de nossa lista. Os métodos de inserir e remover
 * devem operar conforme descrito a seguir, respeitando parâmetros e retornos:
 * - Primeiro, o void inserirInicio(Pokemon pokemon) insere um registro na primeira posição da Lista e remaneja os demais.
 * - Segundo, o void inserir(Pokemon pokemon, int posição) insere um registro na posição p da Lista, onde p < n e n é o
 *   número de registros cadastrados. Em seguida, esse método remaneja os demais registros.
 * - O void inserirFim(Pokemon pokemon) insere um registro na última posição da Lista.
 * - O Pokemon removerInicio() remove e retorna o primeiro registro cadastrado na Lista e remaneja os demais.
 * - O Pokemon remover(int posição) remove e retorna o registro cadastrado na p-ésima posição da Lista e remaneja os demais.
 * - O Pokemon removerFim() remove e retorna o último registro cadastrado na lista. 
 * 
 * A entrada padrão é composta por duas partes:
 * - A primeira é igual a entrada da primeira questão.
 * - As demais linhas correspondem a segunda parte.
 *   > A primeira linha da segunda parte tem um número inteiro n indicando a quantidade de registros a serem
 *     inseridos/removidos.
 *   > Nas próximas n linhas, tem-se n comandos de inserção/remoção a serem processados neste exercício. Cada uma dessas
 *     linhas tem uma palavra de comando: 
 *     • II inserir no início,
 *     • I* inserir em qualquer posição,
 *     • IF inserir no fim,
 *     • RI remover no início,
 *     • R* remover em qualquer posição e
 *     • RF remover no fim.
 * 
 * No caso dos comandos de inserir, temos também o nome do arquivo que contém o registro a ser inserido.
 * No caso dos comandos de “em qualquer posição”, temos também esse nome. 
 * No Inserir, a posição fica imediatamente após a palavra de comando.
 * 
 * A saída padrão tem uma linha para cada registro removido sendo que essa informação será constituída pela palavra “(R)” e
 * o atributo name.
 * No final, a saída mostra os atributos relativos a cada registro cadastrado na lista após as operações de inserção e
 * remoção.
 */

/*
 * INFO: 
 * 
 * - As listas são um Tipo Abstrato de Dados (TAD) no qual podemos inserir e remover elementos em qualquer posição
 *
 * - Variáveis:
 *     > array (de elementos)
 *     > n (contador)
 *  
 *  - Métodos:
 *      > Construtores
 *      > Inserção de elemento
 *          • void inserirInicio(elemento)
 *          • void inserirFim(elemento)
 *          • void inserir(elemento, posição)
 *      > Remoção de elementos
 *          • elemento removerInicio()
 *          • elemento removerFim()
 *          • elemento remover(posição)
 *      > Mostrar, pesquisar, ordenar, ...
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

class Celula {
    public Pokemon pokemon; // Elemento inserido na celula.
    public Celula prox; // Aponta a celula prox.

    /**
     * Construtor da classe.
     */
    public Celula() {
        this(null);
    }

    /**
     * Construtor da classe.
     * 
     * @param pokemon pokemon inserido na celula.
     */
    public Celula(Pokemon pokemon) {
        this.pokemon = pokemon;
        this.prox = null;
    }
}

class FlexStack {
    // Atributos
    private Celula top;

    // Construtor 1
    public FlexStack() {
        top = null;
    }

    /**
     * Insere um pokemon na pilha (politica FILO).
     *
     * @param pokemon pokemon a ser inserido
     */
    public void push(Pokemon pokemon) {
        Celula tmp = new Celula(pokemon);
        tmp.prox = top;
        top = tmp;

        tmp = null;
    }

    /**
     * Remove um pokemon da pilha (politica FILO).
     * 
     * @return pokemon removido.
     * @trhows Exception se a sequencia nao conter pokemons.
     */
    Pokemon pop() throws Exception {
        if (top == null)
            throw new Exception("Erro! Não há pokemons para remover.");

        Pokemon removedPokemon = top.pokemon;
        Celula tmp = top;
        top = top.prox;

        tmp.prox = null;
        tmp = null;

        return removedPokemon;
    }

    /**
     * Mostra os pokemon numerados por [index], comecando do topo.
     */
    public void mostrar() {
        int index = 0;
        for (Celula i = top; i != null; i = i.prox) {
            System.out.print("[" + index++ + "] ");
            i.pokemon.imprimir();
        }
    }

    /**
     * Mostra os pokemon numerados por [index], invertendo a impressão. De forma
     * recursiva.
     */
    public void mostraRecursivo() {
        int index = getSizeStack();
        mostraRecursivo(top, index);
    }

    private void mostraRecursivo(Celula i, int index) {
        if (i != null) {
            mostraRecursivo(i.prox, --index);
            System.out.print("[" + index + "] ");
            i.pokemon.imprimir();
        }
    }

    /**
     * Encontra o tamanho da Pilha Flexível.
     */
    public int getSizeStack() {
        int size = 0;
        for (Celula i = top; i != null; i = i.prox, size++)
            ;

        return size;
    }

    /**
     * Soma o peso de todos os pokemon, comecando do topo.
     */
    public double getSumWeight() {
        return getSumWeight(top);
    }

    public double getSumWeight(Celula i) {
        double result = 0;

        if (i != null)
            result += i.pokemon.getWeight() + getSumWeight(i.prox);

        return result;
    }

    /**
     * Soma a altura de todos os pokemon, comecando do topo.
     */
    public double getSumHeight() {
        return getSumHeight(top);
    }

    public double getSumHeight(Celula i) {
        double result = 0;

        if (i != null)
            result += i.pokemon.getHeight() + getSumHeight(i.prox);

        return result;
    }

    /**
     * Encontra o pokemon mais pesado.
     */
    public Pokemon getHeavier() {
        Pokemon heavier = top.pokemon;
        for (Celula i = top.prox; i != null; i = i.prox) {
            if (i.pokemon.getWeight() > heavier.getWeight())
                heavier = i.pokemon;
        }
        return heavier;
    }

    /**
     * Encontra o pokemon mais leve.
     */
    public Pokemon getLighter() {
        Pokemon lighter = top.pokemon;
        for (Celula i = top.prox; i != null; i = i.prox) {
            if (i.pokemon.getWeight() < lighter.getWeight())
                lighter = i.pokemon;
        }
        return lighter;
    }

    /**
     * Encontra o pokemon mais alto.
     */
    public Pokemon getHigher() {
        Pokemon higher = top.pokemon;
        for (Celula i = top.prox; i != null; i = i.prox) {
            if (i.pokemon.getWeight() > higher.getWeight())
                higher = i.pokemon;
        }
        return higher;
    }

    /**
     * Encontra o pokemon mais baixo.
     */
    public Pokemon getLower() {
        Pokemon lower = top.pokemon;
        for (Celula i = top.prox; i != null; i = i.prox) {
            if (i.pokemon.getWeight() < lower.getWeight())
                lower = i.pokemon;
        }
        return lower;
    }
}

public class PilhaAlocacaoFlexivel {
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
        FlexStack pokemon = new FlexStack();

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