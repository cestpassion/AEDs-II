/*
 * Refaça a primeira questão deste trabalho com Tabela Hash Direta com Reserva. A função de
 * transformação será (ASCII name) mod tamTab onde tamTab (tamanho da tabela) é 21.
 * 
 * A área de reserva tem tamanho 9, fazendo com que o tamanho total da tabela seja igual a 30.
 * 
 * A saída padrão será a posição de cada elemento procurado na tabela (na hash ou na área de reserva).
 * Se o elemento procurado não estiver na tabela, escreva a palavra NÃO.
 * 
 * Além disso, o name do arquivode log será matrícula hashReserva.txt
 */

/* INFO:
 * 
 */

 /**
  * Tabela Hash Direta com Reserva
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
 * Representa uma reserva auxiliar para armazenar Pokémons que não podem ser alocados
 * na tabela principal.
 */
class Reserva {
    Pokemon[] reservaStorage; // Array que armazena os Pokémons na área de reserva.
    int tam; // Tamanho da área de reserva.

    /**
     * Constrói uma nova reserva com o tamanho especificado.
     *
     * @param tamanho o tamanho da área de reserva.
     */
    Reserva(int tamanho) {
        this.tam = tamanho;
        reservaStorage = new Pokemon[tam];

        // Inicializa todas as posições da reserva com null.
        for (int i = 0; i < reservaStorage.length; i++) {
            reservaStorage[i] = null;
        }
    }
}

/**
 * Implementa uma tabela hash com área de reserva para lidar com colisões.
 */
class TabelaHash {
    Pokemon[] tableHash; // Array que representa a tabela hash principal.
    int tam; // Tamanho da tabela hash.
    Reserva reserva; // Reserva auxiliar para armazenar Pokémons em caso de colisões.

    /**
     * Constrói uma tabela hash com tamanho fixo de 21 e reserva de tamanho 9.
     */
    TabelaHash() {
        this.tam = 21;
        this.tableHash = new Pokemon[21];

        for (int i = 0; i < tableHash.length; i++) 
            tableHash[i] = null;

        this.reserva = new Reserva(9);
    }

    /**
     * Insere um Pokémon na tabela hash ou na reserva em caso de colisão.
     *
     * @param pokemon o Pokémon a ser inserido.
     */
    public void inserir(Pokemon pokemon) {
        int pos = hash(pokemon.getName());

        if (tableHash[pos] == null) {
            tableHash[pos] = pokemon;
        } else {
            // Insere na reserva caso a posição esteja ocupada.
            for (int i = 0; i < reserva.reservaStorage.length; i++) {
                if (reserva.reservaStorage[i] == null) {
                    reserva.reservaStorage[i] = pokemon;
                    break;
                }
            }
        }
    }

    /**
     * Calcula a posição hash para uma string.
     *
     * @param name o nome a ser calculado.
     * @return a posição na tabela hash.
     */
    private int hash(String name) {
        int soma = 0;
        for (int i = 0; i < name.length(); i++) {
            soma += name.charAt(i);
        }
        return soma % tam;
    }

    /**
     * Pesquisa um Pokémon pelo nome na tabela hash e na reserva.
     *
     * @param name o nome do Pokémon a ser pesquisado.
     */
    public void pesquisar(String name) {
        int index = hash(name);

        if (tableHash[index] != null && tableHash[index].getName().equals(name)) {
            System.out.println(" (Posicao: " + index + ") SIM");
        } else {
            boolean encontrado = false;
            for (int i = 0; i < reserva.reservaStorage.length; i++) {
                if (reserva.reservaStorage[i] != null && reserva.reservaStorage[i].getName().equals(name)) {
                    encontrado = true;
                    System.out.println(" (Posicao: " + (21 + i) + ") SIM");
                    break;
                }
            }

            if (!encontrado) {
                System.out.println(" NAO");
            }
        }
    }

    /**
     * Exibe todos os Pokémons armazenados na tabela hash e na reserva.
     */
    public void mostra() {
        for (int i = 0; i < tam; i++) {
            if (tableHash[i] != null) {
                tableHash[i].imprimir();
                System.out.println();
            }
        }
        for (int i = 0; i < reserva.tam; i++) {
            if (reserva.reservaStorage[i] != null) {
                reserva.reservaStorage[i].imprimir();
                System.out.println();
            }
        }
    }
}

/**
 * Classe principal
 */
public class TabelaHashDiretaComReserva {
    public static List<Pokemon> pokemonStorage;

    public static Pokemon search(int id) {
        for (Pokemon p : pokemonStorage) {
            if (id == p.getId()) {
                return p;
            }
        }
        return null;
    }
    public static void main(String[] args) throws Exception {
        try (BufferedReader br = new BufferedReader(new FileReader("/tmp/pokemon.csv"))) { // verde.icei.pucminas.br/tmp/pokemon.csv
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
        TabelaHash abPokemon = new TabelaHash();

        while(!(str = sc.nextLine()).equals("FIM"))
           abPokemon.inserir(search(Integer.parseInt(str)));

        while(!(str = sc.nextLine()).equals("FIM")){
            System.out.print("=> " + str + ":");
            abPokemon.pesquisar(str);
        }

        sc.close();
    }
}