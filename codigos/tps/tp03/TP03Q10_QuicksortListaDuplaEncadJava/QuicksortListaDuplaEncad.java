/*
 * Refaça a questão 8 deste TP na linguagem Java.
 * O nome do arquivo de log será matrícula_quicksort3.txt.
 */

/*
 * INFO: 
 */

/**
 * Quicksort com LISTA DINÂMICA DUPLAMENTE ENCADEADA em Java
 * @author Bruna Furtado da Fonseca
 * @version 2024-07-16
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

/**
 * Classe Pokémon
 */
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
 * Classe Lista Dupla Encadeada
 */

class ListaDuplaEncad {
    // Atributos
    private Pokemon[] pokemonList;
    private int n;

    // Construtor 1
    public ListaDuplaEncad() {
        this(1000);
    }

    // Construtor 2
    public ListaDuplaEncad(int size) {
        this.pokemonList = new Pokemon[size];
        this.n = 0;
    }

    /**
     * Insere um registro na primeira posição da Lista Dupla e remaneja os demais
     *
     * @param pokemon pokemon a ser inserido
     */
    public void inserirInicio(Pokemon pokemon) throws Exception {
        if (n >= pokemonList.length) {
            throw new Exception("Erro! Contador maior que o array.");

        }

        // Realoca os elementos para o fim do array
        for (int i = n; i > 0; --i)
            pokemonList[i] = pokemonList[i - 1];

        pokemonList[0] = pokemon;
        n++;
    }

    /**
     * Insere um registro na última posição da Lista Dupla.
     *
     * @param pokemon pokemon a ser inserido
     */
    public void inserirFim(Pokemon pokemon) throws Exception {
        if (n >= pokemonList.length)
            throw new Exception("Erro! Contador maior que o array.");

        pokemonList[n] = pokemon;
        n++;
    }

    /**
     * Insere um registro na posição p da Lista Dupla, onde p < n e n é o número
     * de registros cadastrados. Em seguida, esse método remaneja os demais
     * registros.
     *
     * @param pokemon pokemon a ser inserido
     * @param pos     posição em que o pokemon será inserido
     */
    public void inserir(Pokemon pokemon, int pos) throws Exception {
        if (n >= pokemonList.length)
            throw new Exception("Erro! Contador maior que o array.");
        else if (pos < 0 || pos > n)
            throw new Exception("Erro! Posição inválida.");

        // Realoca os elementos para o fim do array
        for (int i = n; i > pos; --i)
            pokemonList[i] = pokemonList[i - 1];

        pokemonList[pos] = pokemon;
        n++;
    }

    /**
     * Remove e retorna o primeiro registro cadastrado na Lista Dupla e remaneja os
     * demais.
     * 
     * @return pokemon removido
     */
    Pokemon removerInicio() throws Exception {
        if (n == 0)
            throw new Exception("Erro! Não há pokemons para remover.");

        Pokemon removedPokemon = pokemonList[0];
        n--;

        for (int i = 0; i < n; ++i)
            pokemonList[i] = pokemonList[i + 1];

        return removedPokemon;
    }

    /**
     * Remove e retorna o último registro cadastrado na Lista Dupla.
     *
     * @return pokemon removido
     */
    Pokemon removerFim() throws Exception {
        if (n == 0)
            throw new Exception("Erro! Não há pokemons para remover.");

        return pokemonList[--n];
    }

    /**
     * Remove e retorna o registro cadastrado na p-ésima posição da Lista Dupla e remaneja
     * os demais.
     *
     * @param pos posição onde na qual será removido o pokemon
     * @return pokemon removido
     */
    Pokemon remover(int pos) throws Exception {
        if (n == 0)
            throw new Exception("Erro! Não há pokemons para remover.");
        if (pos < 0 || pos > n)
            throw new Exception("Erro! Posição inválida.");

        Pokemon removedPokemon = pokemonList[pos];
        n--;

        for (int i = pos; i < n; ++i)
            pokemonList[i] = pokemonList[i + 1];

        return removedPokemon;
    }

    public void mostrar() {
        for (int i = 0; i < n; ++i) {
            System.out.print("[" + i + "] ");
            pokemonList[i].imprimir();
        }
    }
}

/**
 * Classe Ordenação (Quicksort)
 */
class Ordenacao{

}

/**
 * Classe Principal
 */
public class QuicksortListaDuplaEncad {
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
        ListaDuplaEncad pokemon = new ListaDuplaEncad();

        while (!(str = sc.nextLine()).equals("FIM"))
            pokemon.inserirFim(search(Integer.parseInt(str)));

        int operations = sc.nextInt(); // Quantidade de registros a serem inseridos/removidos
        sc.nextLine(); // Lê o quebralinha
        int cont = 0;

        while (cont < operations) {
            str = sc.nextLine();

            String[] subString = str.split(" ");

            switch (subString[0]) {
                case "II":
                    pokemon.inserirInicio(search(Integer.parseInt(subString[1])));
                    break;

                case "IF":
                    pokemon.inserirFim(search(Integer.parseInt(subString[1])));
                    break;

                case "I*":
                    pokemon.inserir(search(Integer.parseInt(subString[2])), Integer.parseInt(subString[1]));
                    break;

                case "RI":
                    System.out.println("(R) " + pokemon.removerInicio().getName());
                    break;

                case "RF":
                    System.out.println("(R) " + pokemon.removerFim().getName());
                    break;

                case "R*":
                    System.out.println("(R) " + pokemon.remover(Integer.parseInt(subString[1])).getName());
                    break;

                default:
                    break;
            }
            cont++;
        }
        pokemon.mostrar();
        sc.close();
    }
}