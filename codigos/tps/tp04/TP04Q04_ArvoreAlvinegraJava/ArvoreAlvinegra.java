/*
 * Refaça a primeira questão deste trabalho com árvore Alvinegra.
 * O name do arquivo de log será matrícula avinegra.txt.
 */

/* INFO:
 * 
 */

/**
 * Árvore Álvinegra em Java
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
     * @return false / false
     */
    public boolean convertBool(String str) {
        if (str.equals("1"))
            return false;
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
 * Representa um nó de uma árvore Red-Black.
 */
class No {
    Pokemon pokemon;
    No esq, dir;
    boolean cor; // Indica a cor do nó: true para vermelho e false para preto

    /**
     * Construtor para criar um nó com o Pokémon fornecido.
     * 
     * @param pokemon o Pokémon a ser armazenado no nó.
     */
    No(Pokemon pokemon) {
        this.pokemon = pokemon;
        esq = dir = null;
        this.cor = true; // Vermelho por padrão
    }
}

/**
 * Implementa uma árvore Red-Black (Árvore Rubro-Negra).
 */
class ArvoreRedBlack {
    private No raiz;

    /**
     * Construtor para criar uma árvore Red-Black vazia.
     */
    public ArvoreRedBlack() {
        raiz = null;
    }

    /**
     * Insere um novo Pokémon na árvore.
     * 
     * @param pokemon o Pokémon a ser inserido.
     */
    public void inserir(Pokemon pokemon) {
        if (raiz == null) {
            inserirNaRaiz(pokemon);
        } else if (raiz.dir == null && raiz.esq == null) {
            inserirFilhoSimples(pokemon);
        } else if (raiz.esq == null) {
            inserirComFilhoEsquerdoNulo(pokemon);
        } else if (raiz.dir == null) {
            inserirComFilhoDireitoNulo(pokemon);
        } else {
            inserirRecursivamente(pokemon, null, null, null, raiz);
        }
        raiz.cor = false;
    }

    /**
     * Insere um Pokémon na raiz quando ela está vazia.
     * 
     * @param pokemon o Pokémon a ser inserido.
     */
    private void inserirNaRaiz(Pokemon pokemon) {
        raiz = new No(pokemon);
    }

    /**
     * Insere um Pokémon quando a raiz só tem um filho.
     * 
     * @param pokemon o Pokémon a ser inserido.
     */
    private void inserirFilhoSimples(Pokemon pokemon) {
        if (pokemon.getName().compareTo(raiz.pokemon.getName()) < 0) {
            raiz.esq = new No(pokemon);
        } else {
            raiz.dir = new No(pokemon);
        }
    }

    /**
     * Insere um Pokémon quando apenas o filho esquerdo da raiz está nulo.
     * 
     * @param pokemon o Pokémon a ser inserido.
     */
    private void inserirComFilhoEsquerdoNulo(Pokemon pokemon) {
        if (pokemon.getName().compareTo(raiz.pokemon.getName()) < 0) {
            raiz.esq = new No(pokemon);
        } else if (pokemon.getName().compareTo(raiz.dir.pokemon.getName()) < 0) {
            raiz.esq = new No(raiz.pokemon);
            raiz.pokemon = pokemon;
        } else {
            raiz.esq = new No(raiz.pokemon);
            raiz.pokemon = raiz.dir.pokemon;
            raiz.dir.pokemon = pokemon;
        }
        raiz.esq.cor = raiz.dir.cor = false;
    }

    /**
     * Insere um Pokémon quando apenas o filho direito da raiz está nulo.
     * 
     * @param pokemon o Pokémon a ser inserido.
     */
    private void inserirComFilhoDireitoNulo(Pokemon pokemon) {
        if (pokemon.getName().compareTo(raiz.pokemon.getName()) > 0) {
            raiz.dir = new No(pokemon);
        } else if (pokemon.getName().compareTo(raiz.esq.pokemon.getName()) > 0) {
            raiz.dir = new No(raiz.pokemon);
            raiz.pokemon = pokemon;
        } else {
            raiz.dir = new No(raiz.pokemon);
            raiz.pokemon = raiz.esq.pokemon;
            raiz.esq.pokemon = pokemon;
        }
    }

    /**
     * Insere um Pokémon recursivamente na árvore.
     * 
     * @param pokemon o Pokémon a ser inserido.
     * @param bisAvo  o bisavô do nó atual.
     * @param avo     o avô do nó atual.
     * @param pai     o pai do nó atual.
     * @param i       o nó atual.
     */
    private void inserirRecursivamente(Pokemon pokemon, No bisAvo, No avo, No pai, No i) {
        if (i == null) {
            if (pokemon.getName().compareTo(pai.pokemon.getName()) < 0) {
                i = pai.esq = new No(pokemon);
            } else {
                i = pai.dir = new No(pokemon);
            }

            if (pai.cor == true) {
                balancear(bisAvo, avo, pai, i);
            }
        } else {
            is4No(bisAvo, avo, pai, i);

            if (pokemon.getName().compareTo(i.pokemon.getName()) < 0) {
                inserirRecursivamente(pokemon, avo, pai, i, i.esq);
            } else if (pokemon.getName().compareTo(i.pokemon.getName()) > 0) {
                inserirRecursivamente(pokemon, avo, pai, i, i.dir);
            } else {
                System.out.println("Erro, elemento repetido");
            }
        }
    }

    /**
     * Insere um novo Pokémon na subárvore, garantindo as propriedades Red-Black.
     * 
     * @param pokemon o Pokémon a ser inserido.
     * @param bisAvo referência para o bisavô do nó atual.
     * @param avo referência para o avô do nó atual.
     * @param pai referência para o pai do nó atual.
     * @param i referência para o nó atual.
     */
    private void inserir(Pokemon pokemon, No bisAvo, No avo, No pai, No i) {
        if (i == null) {
            if (pokemon.getName().compareTo(pai.pokemon.getName()) < 0) {
                i = pai.esq = new No(pokemon);
            } else {
                i = pai.dir = new No(pokemon);
            }

            if (pai.cor == true) {
                balancear(bisAvo, avo, pai, i);
            }
        } else {
            is4No(bisAvo, avo, pai, i);

            if (pokemon.getName().compareTo(i.pokemon.getName()) < 0) {
                inserir(pokemon, avo, pai, i, i.esq);
            } else if (pokemon.getName().compareTo(i.pokemon.getName()) > 0) {
                inserir(pokemon, avo, pai, i, i.dir);
            } else {
                System.out.println("Erro, elemento repetido");
            }
        }
    }

    /**
     * Pesquisa por um Pokémon na árvore pelo nome.
     * 
     * @param name o nome do Pokémon a ser pesquisado.
     */
    public void pesquisar(String name) {
        pesquisar(raiz, name);
    }

    /**
     * Pesquisa por um Pokémon na subárvore pelo nome.
     * 
     * @param i o nó atual.
     * @param name o nome do Pokémon a ser pesquisado.
     */
    private void pesquisar(No i, String name) {
        if (i == null) {
            System.out.println(" NAO");
        } else if (name.compareTo(i.pokemon.getName()) > 0) {
            System.out.print(" dir");
            pesquisar(i.dir, name);
        } else if (name.compareTo(i.pokemon.getName()) < 0) {
            System.out.print(" esq");
            pesquisar(i.esq, name);
        } else {
            System.out.println(" SIM");
        }
    }

    /**
     * Realiza o percurso em ordem central na árvore.
     */
    public void caminharCentral() {
        caminharCentral(raiz);
    }

    /**
     * Realiza o percurso em ordem central na subárvore.
     * 
     * @param i o nó atual.
     */
    private void caminharCentral(No i) {
        if (i != null) {
            caminharCentral(i.esq);
            i.pokemon.imprimir();
            System.out.println();
            caminharCentral(i.dir);
        }
    }

    /**
     * Balanceia a árvore após uma inserção, garantindo as propriedades Red-Black.
     * 
     * @param bisAvo referência para o bisavô do nó atual.
     * @param avo referência para o avô do nó atual.
     * @param pai referência para o pai do nó atual.
     * @param i referência para o nó atual.
     */
    private void balancear(No bisAvo, No avo, No pai, No i) {
        if (pai.cor == true) {
            if (pai.pokemon.getName().compareTo(avo.pokemon.getName()) > 0) {
                if (i.pokemon.getName().compareTo(pai.pokemon.getName()) > 0) {
                    avo = rotacaoEsq(avo);
                } else {
                    avo.dir = rotacaoDir(pai);
                    avo = rotacaoEsq(avo);
                }
            } else {
                if (i.pokemon.getName().compareTo(pai.pokemon.getName()) < 0) {
                    avo = rotacaoDir(avo);
                } else {
                    avo.esq = rotacaoEsq(pai);
                    avo = rotacaoDir(avo);
                }
            }
        }

        if (bisAvo == null) {
            raiz = avo;
        } else if (avo.pokemon.getName().compareTo(bisAvo.pokemon.getName()) < 0) {
            bisAvo.esq = avo;
        } else {
            bisAvo.dir = avo;
        }

        avo.cor = false;

        avo.esq.cor = avo.dir.cor = true;
    }

    /**
     * Realiza uma rotação para a direita em um nó.
     * 
     * @param i o nó a ser rotacionado.
     * @return o novo nó após a rotação.
     */
    private No rotacaoDir(No i) {
        No tmp = i.esq;
        i.esq = tmp.dir;
        tmp.dir = i;

        return tmp;
    }

    /**
     * Realiza uma rotação para a esquerda em um nó.
     * 
     * @param i o nó a ser rotacionado.
     * @return o novo nó após a rotação.
     */
    private No rotacaoEsq(No i) {
        No tmp = i.dir;
        i.dir = tmp.esq;
        tmp.esq = i;

        return tmp;
    }

    /**
     * Verifica se um nó é um 4-nó e ajusta suas cores se necessário.
     * 
     * @param bisAvo referência para o bisavô do nó atual.
     * @param avo referência para o avô do nó atual.
     * @param pai referência para o pai do nó atual.
     * @param i referência para o nó atual.
     */
    private void is4No(No bisAvo, No avo, No pai, No i) {
        if (i.esq != null && i.dir != null && i.esq.cor == true && i.dir.cor == true) {
            i.cor = true;
            i.esq.cor = i.dir.cor = false;

            if (i == raiz) {
                i.cor = false;
            } else if (pai.cor == true) {
                balancear(bisAvo, avo, pai, i);
            }
        }
    }
}

public class ArvoreAlvinegra {
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
        ArvoreRedBlack arvore = new ArvoreRedBlack(); // Usando a árvore Red-Black

        // Inserindo Pokémon na árvore
        while (!(str = sc.nextLine()).equals("FIM")) {
            int id = Integer.parseInt(str);
            Pokemon pokemon = search(id);
            if (pokemon != null) {
                arvore.inserir(pokemon);
            } else {
                System.out.println("Pokémon não encontrado.");
            }
        }

        // Pesquisando Pokémon na árvore
        while (!(str = sc.nextLine()).equals("FIM")) {
            System.out.print(str + "\nraiz");
            arvore.pesquisar(str);
        }

        sc.close();
    }
}