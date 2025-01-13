/*
 * Refaça a questão anterior, contudo, considerando a estrutura de árvore de árvore. Nessa estrutura,
 * temos uma árvore binária tradicional na qual cada nó tem um ponteiro para outra árvore binária.
 * 
 * Graficamente, a primeira árvore está no plano xy e a árvore de seus nós pode ser imaginada no espaço
 * tridimensional. Temos dois tipos de nós.
 * O primeiro tem um número inteiro como chave, os ponteiros esq e dir (ambos para nós do primeiro tipo)
 * e um ponteiro para nós do segundo tipo.
 * O outro nó tem uma String como chave e os ponteiros esq e dir (ambos para nós do segundo tipo).
 * 
 * A chave de pesquisa da primeira árvore é o atributo captureRate mod 15 e, da outra, é o atributo name.
 * Conforme a figura abaixo.
 * 
 * Destaca-se que nossa pesquisa faz um “mostrar” na primeira árvore e um “mostrar” na segunda.
 * Faremos um “mostrar” na primeira árvore porque ela é organizada pelo captureRate mod 15, permitindo
 * que o valor desejado esteja na segunda árvore de qualquer um de seus nós.
 * Faremos o “mostrar” na segunda porque ela é organizada pelo atributo name.
 * 
 * Antes de inserir qualquer elemento, crie a primeira árvore, inserindo todos seus nós e respeitando a
 * ordem 7, 3, 11, 1, 5, 9, 13, 0, 2, 4, 6, 8, 10, 12 e 14. O arquivo de log será matrícula arvoreArvore.txt
 *                              ____________________________
 *                      🠗      |                            🠗
 *                      7      |                            TI                      
 *                  ⬋   🠗  ⬊   |                         ⬋     ⬊                  
 *               3      ☰    11                      TE        TU
 *            ⬋ 🠗 ⬊         ⬋   ⬊                  ⬋  ⬊      ⬋  ⬊
 *          1   ☰  5       9     13 _______      TA   TER   TO   TUB     
 *         /🠗 ⬊    ⬋🠗 ⬊   ⬋ 🠗⬊    ⬋  ⬊      |
 *        | ☰ □  4 ☰ 6  □ ☰ □  □   □      |
 *         ⬊    ⬋🠗⬊   ⬋🠗⬊                   🠗
 *            □ ☰ □  □ ☰ □                VO
 *                                      ⬋     ⬊
 *                                    VE       VOB
 *                                   ⬋         ⬋  ⬊
 *                                 VA        VOA   VU
 */ 

/* INFO:
 * 
 */

/**
 * Árvore Binária de Árvore Binária em Java
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

class No {
    public int modCapRate;
    public No esq;
    public No dir;
    NoFilho raizfilho;

    public No(int elemento) {
        this(elemento, null, null);
    }

    public No(int elemento, No esq, No dir) {
        this.modCapRate = elemento;
        this.esq = esq;
        this.dir = dir;
        this.raizfilho = null;
    }
}

class NoFilho {
    public Pokemon pokemon;
    public NoFilho esq;
    public NoFilho dir;

    public NoFilho(Pokemon pokemon) {
        this(pokemon, null, null);
    }

    public NoFilho(Pokemon pokemon, NoFilho esq, NoFilho dir) {
        this.pokemon = pokemon;
        this.esq = esq;
        this.dir = dir;
    }
}

class ABdeAB {
    private No raiz;

    public ABdeAB() throws Exception {
        raiz = null;
        inserirKeys();
    }

    // MÉTODOS DE INSERÇÃO:

    public void inserirKeys() throws Exception {
        int[] keys = {7, 3, 11, 1, 5, 9, 13, 0, 2, 4, 6, 8, 10, 12, 14};

        for(int i = 0; i < keys.length; i++){
            raiz = inserirKeys(keys[i], raiz);
        }   
    }

    public No inserirKeys(int key, No i) throws Exception {
        if (i == null) {
            i = new No(key);
        } else if (key < i.modCapRate) {
            i.esq = inserirKeys(key, i.esq);
        } else if (key > i.modCapRate) {
            i.dir = inserirKeys(key, i.dir);
        } else {
            throw new Exception("Erro!");
        }

        return i;
    }

    // Inserção em Java com Retorno de Referência
    public void inserir(Pokemon pokemon) throws Exception {
        int key = pokemon.getCaptureRate() % 15;
        raiz = inserir(pokemon, key, raiz);
    }

    public No inserir(Pokemon pokemon, int key, No i) throws Exception {
        if (i == null) {
            throw new Exception("Erro! Chave inexistente.");
        } else if(key == i.modCapRate){
            i.raizfilho = inserirArvore2(pokemon, i.raizfilho);
        } else if (key < i.modCapRate) {
            i.esq = inserir(pokemon, key, i.esq);
        } else if (key > i.modCapRate) {
            i.dir = inserir(pokemon, key, i.dir);
        } else {
            throw new Exception("Erro!");
        }

        return i;
    }

    public NoFilho inserirArvore2(Pokemon pokemon, NoFilho i) throws Exception {
        if (i == null) {
            i = new NoFilho(pokemon);
        } else if (i.pokemon == null) { // Caso base: substituir nó vazio
            i.pokemon = pokemon;
        } else if (pokemon.getName().compareTo(i.pokemon.getName()) < 0) {
            i.esq = inserirArvore2(pokemon, i.esq);
        } else if (pokemon.getName().compareTo(i.pokemon.getName()) > 0) {
            i.dir = inserirArvore2(pokemon, i.dir);
        } else {
            throw new Exception("Erro! Pokémon já existe.");
        }
        return i;
    }
    

    // Pesquisa
    public void pesquisar(String name) {
        if(pesquisar(name, raiz)){
            System.out.println(" SIM");
        } else {
            System.out.println(" NAO");
        }
    }

    public boolean pesquisar(String name, No i) {
        boolean resp;

        if (i == null) {
            resp = false;
        } else {
            resp = presquisarArvore2(name, i.raizfilho);

            if(!resp){
                System.out.print("  ESQ");
                resp = pesquisar(name, i.esq);
            }

            if(!resp){
                System.out.print("  DIR");
                resp = pesquisar(name, i.dir);
            }
        }
        return resp;
    }

    public boolean presquisarArvore2(String name, NoFilho i){
        boolean resp;

        if(i == null){
            resp = false;
        } else{
            if (name.compareTo(i.pokemon.getName()) == 0) {
                resp = true;
            } else if (name.compareTo(i.pokemon.getName()) < 0) {
                System.out.print(" esq");
                resp = presquisarArvore2(name, i.esq);
            } else {
                System.out.print(" dir");
                resp = presquisarArvore2(name, i.dir);
            }
        }
        return resp;
    }
}

/**
 * Classe principal
 */
public class ArvoreDeArvore {
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
        ABdeAB ababPokemon = new ABdeAB();

        while(!(str = sc.nextLine()).equals("FIM"))
           ababPokemon.inserir(search(Integer.parseInt(str)));

        while(!(str = sc.nextLine()).equals("FIM")){
            System.out.print("=> " + str + "\nraiz");
            ababPokemon.pesquisar(str);
        }

        sc.close();
    }
}