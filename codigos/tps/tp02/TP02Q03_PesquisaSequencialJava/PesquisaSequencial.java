import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.List;
import java.util.Date;
import java.util.Arrays;

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
    public Pokemon(){
        this.id = 0;
        this.generation = 0;
        this.name = null;
        this.description = null;
        this.types = new ArrayList<>();;
        this.abilities = new ArrayList<>();;
        this.weight = 0;
        this.height = 0;
        this.captureRate = 0;
        this.isLegendary = false;
        this.captureDate = null;
    }

    // Contrutor 2
    public Pokemon(int id, int generation, String name, String description, List<String> types, List<String> abilities,
                    double weight, double height, int captureRate, boolean isLegendary, Date captureDate){
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
    public int getId() { return this.id; }
    public int getGeneradion() { return this.generation; }
    public String getName() { return this.name; }
    public String getDescription() { return this.description; }
    public List<String> getTypes() { return this.types; }
    public List<String> getAbilities() { return this.abilities; }
    public double getWeight() { return this.weight; }
    public double getHeight() { return this.height; }
    public int getCaptureRate() { return this.captureRate; }
    public boolean getIsLegendary() { return this.isLegendary; }
    public Date getCaptureDate() { return this.captureDate; }

    // Métodos set
    public void setId(int id) { this.id = id; }
    public void setGeneradion(int generation) { this.generation = generation; }
    public void setName(String name) { this.name = name; }
    public void setDescription(String description) { this.description = description; }
    public void setTypes(List<String> types) { this.types = types; }
    public void setAbilities(List<String> abilities) { this.abilities = abilities; }
    public void setWeight(double weight) { this.weight = weight; }
    public void setHeight(double height) { this.height = height; }
    public void setCaptureRate(int captureRate) { this.captureRate = captureRate; }
    public void setIsLegendary(boolean isLegendary) { this.isLegendary = isLegendary; }
    public void setCaptureDate(Date captureDate) { this.captureDate = captureDate; }

    // Método ler
    public void ler(String line){
        line = line.replaceAll("\"", "");
        String[] lineSplitted = line.split("[\\[\\]]");
        lineSplitted[2] = lineSplitted[2].substring(1);

        // id, generation, name, descripstion
        int comma = lineSplitted[0].indexOf(",");
        for(int i = 0; i < 3; i++)
            comma = lineSplitted[0].indexOf(",", ++comma);

        String subString = lineSplitted[0].substring(0, comma);
        String[] attributes = subString.split(",");

        this.setId(Integer.parseInt(attributes[0]));
        this.setGeneradion(Integer.parseInt(attributes[1]));
        this.setName(attributes[2]);
        this.setDescription(attributes[3]);

        // types
        int start = comma + 1;
        for(int i = 0; i < 2; i++)
            comma = lineSplitted[0].indexOf(",", ++comma);

        subString = lineSplitted[0].substring(start, comma);
        List<String> listAttributes = Arrays.asList(subString.split(","));

        for(int i = 0; i < listAttributes.size(); i++)
            listAttributes.set(i, "'" + listAttributes.get(i) + "'");

        this.setTypes(listAttributes);

        // abilities
        listAttributes = Arrays.asList(lineSplitted[1].split(","));;

        for(int i = 0; i < listAttributes.size(); i++)
            listAttributes.set(i, listAttributes.get(i).trim());

        this.setAbilities(listAttributes);

        // weight, height, captureRate, isLegendary, captureDate
        attributes = lineSplitted[2].split(",");

        if(attributes[0] != "") { this.setWeight(Double.parseDouble(attributes[0])); }
        if(attributes[1] != "") { this.setHeight(Double.parseDouble(attributes[1])); }
        this.setCaptureRate(Integer.parseInt(attributes[2]));
        this.setIsLegendary(convertBool(attributes[3]));
        this.setCaptureDate(convertDate(attributes[4]));
    }

    // Método converter para booleano
    public boolean convertBool(String str){
        if(str.equals("1"))
            return true;
        else
            return false;
    }

    // Método converter para Date
    public Date convertDate(String str) {
        SimpleDateFormat outputFormat = new SimpleDateFormat("dd/MM/yyyy");
        try {
            return outputFormat.parse(str);
        } catch (ParseException e) {
            System.err.println("Erro ao converter a data: " + e.getMessage());
            return null;
        }
    }

    // Método imprimir
    public void imprimir(){
        SimpleDateFormat outputFormat = new SimpleDateFormat("dd/MM/yyyy");
        String formattedDate = outputFormat.format(this.getCaptureDate());

        MyIO.println("[#" + this.getId() + " -> " + this.getName() + ": " + this.getDescription() + " - " + this.getTypes()
                    + " - " + this.getAbilities() + " - " + this.getWeight() + "kg - " + this.getHeight() + "m - " + this.getCaptureRate()
                    + "% - " + this.getIsLegendary() + " - " + this.getGeneradion() + " gen] - " + formattedDate);
    }

    // Método clone
    public Pokemon clone(){
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

public class PesquisaSequencial {

    public static void main(String[] args) throws Exception {
        // Lista para armazenar os Pokémon
        List<Pokemon> pokemon = new ArrayList<>();

        // Leitura do arquivo CSV de Pokémon
        BufferedReader reader = new BufferedReader(new FileReader("/tmp/pokemon.csv"));
        String line = reader.readLine(); // Ignora o cabeçalho

        // Leitura do arquivo e criação dos objetos Pokémon
        while ((line = reader.readLine()) != null) {
            Pokemon p = new Pokemon();
            p.ler(line);
            pokemon.add(p);
        }
        reader.close();

        // Inicializando variáveis para pesquisa e log
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        String searchName;
        int comparisons = 0; // Contador de comparações
        long startTime = System.currentTimeMillis(); // Início da contagem de tempo

        // Loop para pesquisar os nomes fornecidos
        while (!(searchName = input.readLine()).equals("FIM")) {
            boolean found = false;
            for (Pokemon p : pokemon) {
                comparisons++; // Contando uma comparação
                if (p.getName().equalsIgnoreCase(searchName)) {
                    found = true;
                    break;
                }
            }

            // Exibir SIM ou NÃO com base no resultado da busca
            if (found) {
                System.out.println("SIM");
            } else {
                System.out.println("NAO");
            }
        }

        // Fim do tempo de execução
        long endTime = System.currentTimeMillis();
        long executionTime = endTime - startTime;

        // Criação do arquivo de log com matrícula, tempo de execução e número de comparações
        String matricula = "847503";
        BufferedWriter logWriter = new BufferedWriter(new FileWriter(matricula + "_sequencial.txt"));
        logWriter.write(matricula + "\t" + executionTime + "ms\t" + comparisons + "\n");
        logWriter.close();
    }
}