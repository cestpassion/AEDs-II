/**
 * Mergesort
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
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
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

class Pesquisa {
    /**
     * Construtor.
    */
    public Pesquisa() {
    }

    /**
     * Algoritmo de pesquisa sequencial interativo.
    *
    * @param pokemonArray array onde será feita a pesquisa
    * @param name         alvo da pesquisa
    * @return true (se encontou)/ false (se nao encontrou)
    */
    public boolean searchSeq(Pokemon[] pokemonArray, String name) {
        boolean answer = false;
        int n = pokemonArray.length;

        for (int i = 0; i < n; i++) {
            if (pokemonArray[i].getName().equals(name)) {
                answer = true;
                i = n; // ou break;
            }
        }
        return answer;
    }

    /**
     * Algoritmo de pesquisa binária interativo.
    *
    * @param pokemonArray array onde será feita a pesquisa
    * @param name         alvo da pesquisa
    * @return true (se encontou)/ false (se nao encontrou)
    */
    public boolean searchBin(Pokemon[] pokemonArray, String name) {
        boolean answer = false;
        int right = (pokemonArray.length - 1), left = 0, middle;

        while (left <= right) {
            middle = (left + right) / 2;

            if (name.equals(pokemonArray[middle].getName())) {
                answer = true;
                left = right + 1; // ou break;
            } else if (name.compareTo(pokemonArray[middle].getName()) > 0) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        return answer;
    }

    /**
     * Algoritmo de pesquisa sequencial recursivo.
    *
    * @param pokemonArray lista onde será feita a pesquisa
    * @param name         alvo da pesquisa
    * @param index        indice atual da pesquisa
    * @return true (se encontou)/ false (se nao encontrou)
    */
    public boolean searchSeqRec(Pokemon[] pokemonArray, String name, int index) {
        if (index == pokemonArray.length)
            return false;

        if (pokemonArray[index].getName().equals(name))
            return true;

        return searchSeqRec(pokemonArray, name, ++index);
    }

    /**
     * Algoritmo de pesquisa binária recursivo.
    *
    * @param pokemonArray array onde será feita a pesquisa
    * @param name         alvo da pesquisa
    * @param left         início do sub-array
    * @param right        fim do sub-array
    * @return true (se encontou)/ false (se nao encontrou)
    */
    public boolean searchBinRec(Pokemon[] pokemonArray, String name, int left, int right) {
        boolean answer;
        int middle = (left + right) / 2;

        if (left > right)
            answer = false;
        else if (name.equals(pokemonArray[middle].getName()))
            answer = true;
        else if (name.compareTo(pokemonArray[middle].getName()) > 0)
            answer = searchBinRec(pokemonArray, name, ++middle, right);
        else
            answer = searchBinRec(pokemonArray, name, left, --middle);

        return answer;
    }
}

class Ordenacao {
    private Pokemon[] array;
    private int n;
    private int movimentacoes;
    private int comparacoes;

    /**
     * Construtor.
    */
    public Ordenacao() {
        array = new Pokemon[801];
        n = array.length;
        movimentacoes = 0;
        comparacoes = 0;
    }

    /**
     * Construtor.
    * 
    * @param int tamanho do array de numeros inteiros.
    */
    public Ordenacao(Pokemon[] pokemonArray, int tam) {
        array = pokemonArray;
        n = tam;
        movimentacoes = 0;
        comparacoes = 0;
    }

    public Pokemon[] getArray() {
        return array;
    }

    public int getMovimentacoes() {
        return movimentacoes;
    }

    public int getComparacoes() {
        return comparacoes;
    }

    /**
     * Troca o conteudo de duas posicoes do array
    * 
    * @param i int primeira posicao
    * @param j int segunda posicao
    */
    public void swap(int i, int j) {
        Pokemon temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        movimentacoes++;
    }

    public void selecao() {
        for (int i = 0; i < (n - 1); i++) {
            int menor = i;
            for (int j = (i + 1); j < n; j++) {
                comparacoes++;
                if (array[menor].getName().compareTo(array[j].getName()) > 0) {
                    menor = j;
                }
            }
            swap(menor, i);
        }
    }

    // Função recursiva para ordenar o array usando Selection Sort
    public void selecaoRecursivo(int i) {
        if (i >= n - 1)
            return;

        int menor = i;
        for (int j = i + 1; j < n; j++) {
            comparacoes++;
            if (array[menor].getName().compareTo(array[j].getName()) > 0)
                menor = j;
        }

        swap(menor, i);
        selecaoRecursivo(++i);
    }

    public void insercao() {
        for (int i = 1; i < n; i++) {
            Pokemon tmp = array[i];
            int j = i - 1;

            comparacoes++;
            while ((j >= 0) && (array[j].getCaptureDate().compareTo(tmp.getCaptureDate()) > 0)) {
                movimentacoes++;
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = tmp;
        }
    }

    public void heapsort(   ){
        // Alterar o vetor ignorando a posicao zero
        Pokemon[] tmp = new Pokemon [n + 1];

        for (int i = 0; i < n; i++){
            tmp[i + 1] = array[i];
        }

        array = tmp;

        // Contrucao do heap
        for (int tamHeap = 2; tamHeap <= n; tamHeap++){
            construir(tamHeap);
        }

        // Ordenação propriamente dita
        int tamHeap = n;
        while (tamHeap > 1){
            swap(1, tamHeap--);
            reconstruir(tamHeap);
        }

        // Alterar o vetor para voltar a posicao zero
        tmp = array;
        array = new Pokemon[n];

        for (int i = 0; i < n; i++){
            array[i] = tmp[i + 1];
        }
    }

    public void construir(int tamHeap){
        for (int i = tamHeap; i > 1 && (array[i].getHeight() > array[i / 2].getHeight() ||
                                        (array[i].getHeight() == array[i / 2].getHeight() &&
                                        array[i].getName().compareTo(array[i/2].getName()) > 0));
                                        i /= 2){
            swap(i, i / 2);
        }
    }

    public void reconstruir(int tamHeap){
        int i = 1;
        while (i <= (tamHeap / 2)){
            int filho = getMaiorHeight(i, tamHeap);

            if (array[i].getHeight() < array[filho].getHeight() ||
                (array[i].getHeight() == array[filho].getHeight() &&
                array[i].getName().compareTo(array[filho].getName()) < 0))
            {
                swap(i, filho);
                i = filho;
            }
            else
            {
                break;
            }
        }
    }

    public int getMaiorHeight(int i, int tamHeap){
        int filho;

        if (2 * i == tamHeap) { // Só há um filho (esquerdo)
            filho = 2 * i;
        }
        else if (array[2 * i].getHeight() > array[2 * i + 1].getHeight() ||
                (array[2 * i].getHeight() == array[2 * i + 1].getHeight() &&
                array[2 * i].getName().compareTo(array[2 * i + 1].getName()) > 0)){
            filho = 2 * i; // Filho esquerdo é maior
        }
        else{
            filho = 2 * i + 1; // Filho direito é maior
        }
        return filho;
    }

    // Método Mergesort
    public void mergesort(){
        mergesort(0, n - 1);
    }
    public void mergesort(int left, int right) {
        if (left < right) {
            int middle = (left + right) / 2;
            mergesort(left, middle); // Ordena a metade esquerda
            mergesort(middle + 1, right); // Ordena a metade direita
            merge(left, middle, right); // Junta as metades ordenadas
        }
    }

    // Método para combinar as duas metades
    public void merge(int left, int middle, int right) {
        int n1 = middle - left + 1;
        int n2 = right - middle;
        
        Pokemon[] leftArray = new Pokemon[n1];
        Pokemon[] rightArray = new Pokemon[n2];

        // Copia os dados para os arrays temporários
        System.arraycopy(array, left, leftArray, 0, n1);
        System.arraycopy(array, middle + 1, rightArray, 0, n2);

        // Índices iniciais
        int i = 0, j = 0, k = left;

        // Ordena os arrays temporários
        while (i < n1 && j < n2) {
            comparacoes++;
            // Ordenação por tipos, se houver empate, ordena por nome
            if (leftArray[i].getTypes().equals(rightArray[j].getTypes())) {
                if (leftArray[i].getName().compareTo(rightArray[j].getName()) > 0) {
                    array[k++] = leftArray[i++];
                } else {
                    array[k++] = rightArray[j++];
                }
            } else if (leftArray[i].getTypes().get(0).compareTo(rightArray[j].getTypes().get(0)) < 0) {
                array[k++] = leftArray[i++];
            } else {
                array[k++] = rightArray[j++];
            }
        }

        // Copia os elementos restantes
        while (i < n1) {
            array[k++] = leftArray[i++];
        }
        while (j < n2) {
            array[k++] = rightArray[j++];
        }
    }
}

public class Mergesort {
    public static void main(String[] args){
        List<Pokemon> pokemonStorage = new ArrayList<>();
        
        try (BufferedReader br = new BufferedReader(new FileReader("files/pokemon.csv"))) { // verde.icei.pucminas.br/tmp/pokemon.csv
            String line;

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
        Pokemon[] pokemonArray = new Pokemon[801];
        int index = 0;
        int id;

        while(!(str = sc.nextLine()).equals("FIM")){ // Armazena a nova lista de pokémons
            id = Integer.parseInt(str);
            for(Pokemon p : pokemonStorage){
                if(id == p.getId())
                    pokemonArray[index++] = p;
            }  
        }

        Ordenacao mergesort = new Ordenacao(pokemonArray, index);

        long inicio = System.nanoTime(); // Medir o tempo de execução
        mergesort.mergesort();
        long fim = System.nanoTime();
        long tempoExecucao = fim - inicio; // Tempo em nanossegundos

        int comparacoes = mergesort.getComparacoes();
        int movimentacoes = mergesort.getMovimentacoes(); 

        pokemonArray = mergesort.getArray();
        for(int i = 0; i < index; i++)
            pokemonArray[i].imprimir();
        
        // Criar o arquivo de log
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("files/847503_mergesort.txt"))) {
            writer.write("847503" + "\t" + comparacoes + "\t" + movimentacoes + "\t" + tempoExecucao);
        } catch (IOException e) {
            System.err.println("Erro ao criar o arquivo de log: " + e.getMessage());
        }

        sc.close();
    }
}
