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
 *     - II inserir no início,
 *     - I* inserir em qualquer posição,
 *     - IF inserir no fim,
 *     - RI remover no início,
 *     - R* remover em qualquer posição e
 *     - RF remover no fim.
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

 import java.util.Date;
 import java.text.ParseException;
 import java.text.SimpleDateFormat;
 import java.util.ArrayList;
 import java.util.List;
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
     public int getGeneration() { return this.generation; }
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
 
     /**
      * Lê uma linha do arquivo pokemon.csv e armazena os objetos:
      * id, generation, name, description, types, abilities, weight, height, captureRate,
      * isLegendary e captureDate.
      *
      * @param line String com linha a ser lida
      */
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
         listAttributes = Arrays.asList(lineSplitted[1].split(","));
 
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
 
     /**
      * Converte uma String com um número inteiro 0 ou 1 em tipo boolean
      *
      * @param str String com um número inteiro 0 ou 1
      * @return true / false
      */
     public boolean convertBool(String str){
         if(str.equals("1"))
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
     public void imprimir(){
         SimpleDateFormat outputFormat = new SimpleDateFormat("dd/MM/yyyy");
         String formattedDate = outputFormat.format(this.getCaptureDate());
 
         System.out.println("[#" + this.getId() + " -> " + this.getName() + ": " + this.getDescription() + " - " + this.getTypes()
                     + " - " + this.getAbilities() + " - " + this.getWeight() + "kg - " + this.getHeight() + "m - " + this.getCaptureRate()
                     + "% - " + this.getIsLegendary() + " - " + this.getGeneration() + " gen] - " + formattedDate);
     }
 
     /**
      * Clona o pokemon selecionado
      *
      * @return pokemon clonado
      */
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
 
 class Lista {
     // Atributos
     private Pokemon[] pokemonList;
     private int n;
 
     // Construtor 1
     public Lista(){
         this(1000);
     }
 
     // Construtor 2
     public Lista(int size){
         this.pokemonList = new Pokemon[size];
         this.n = 0;
     }
     
     /**
      * Insere um registro na primeira posição da Lista e remaneja os demais
      *
      * @param pokemon pokemon a ser inserido
      */
     void inserirInicio(Pokemon pokemon) throws Exception {
         if(n >= pokemonList.length){
             throw new Exception("Erro! Contadior maior que o array." + n);
             
         }
 
         // Realoca os elementos para o fim do array
         for(int i = n; i > 0; --i)
             pokemonList[i] = pokemonList[i - 1];
 
         pokemonList[0] = pokemon;
         n++;
     }
 
     /**
      * Insere um registro na posição p da Lista, onde p < n e n é o número
      * de registros cadastrados. Em seguida, esse método remaneja os demais
      * registros.
      *
      * @param pokemon pokemon a ser inserido
      * @param pos posição em que o pokemon será inserido
      */
     void inserir(Pokemon pokemon, int pos) throws Exception {
         if(n >= pokemonList.length)
             throw new Exception("Erro! Contadior maior que o array.");
         else if(pos < 0 || pos > n)
             throw new Exception("Erro! Posição inválida.");
         
         // Realoca os elementos para o fim do array
         for(int i = n; i > pos; --i)
             pokemonList[i] = pokemonList[i - 1];
 
         pokemonList[pos] = pokemon;
         n++;
     }
 
     /**
      * Insere um registro na última posição da Lista.
      *
      * @param pokemon pokemon a ser inserido
      */
     void inserirFim(Pokemon pokemon) throws Exception {
         if(n >= pokemonList.length)
             throw new Exception("Erro! Contadior maior que o array.");
         
         pokemonList[n] = pokemon;
         n++;
     }
 
     /**
      * Remove e retorna o primeiro registro cadastrado na Lista e remaneja os demais.
      * 
      * @return pokemon removido
      */
     Pokemon removerInicio() throws Exception {
         if(n == 0)
             throw new Exception("Erro! Não há pokemons para remover.");
 
         Pokemon removedPokemon = pokemonList[0];
         n--;
 
         for(int i = 0; i < n; ++i)
             pokemonList[i] = pokemonList[i + 1];
 
         return removedPokemon;
     }
 
     /**
      * Remove e retorna o registro cadastrado na p-ésima posição da Lista e remaneja os demais.
      *
      * @param pos posição onde na qual será removido o pokemon
      * @return pokemon removido
      */
     Pokemon remover(int pos) throws Exception {
         if(n == 0)
             throw new Exception("Erro! Não há pokemons para remover.");
         else if(pos < 0 || pos > n)
             throw new Exception("Erro! Posição inválida.");
 
         Pokemon removedPokemon = pokemonList[pos];
         n--;
 
         for(int i = pos; i < n; ++i)
             pokemonList[i] = pokemonList[i + 1];
 
         return removedPokemon;
     }
 
     /**
      * Remove e retorna o último registro cadastrado na lista.
      *
      * @return pokemon removido
      */
     Pokemon removerFim() throws Exception {
         if(n == 0)
             throw new Exception("Erro! Não há pokemons para remover.");
         
         return pokemonList[--n];
     }
 
     void mostrarId(int id){
         for(int i = 0; i < n; ++i){    
             if(id == pokemonList[i].getId()){
                 pokemonList[i].imprimir();
             }
         }
     }
 
     void mostrar(){
         for(int i = 0; i < n; ++i){
             System.out.print("[" + i + "] ");
             pokemonList[i].imprimir();
         }
     }
 }
 
 public class Teste {
     public static void main(String[] args){
         Arq.openRead("pokemon.csv"); // verde.icei.pucminas.br/tmp/pokemon.csv
         String line = null;
         Lista pokemon = new Lista();
         
         Arq.readLine(); // Lê a primeira linha
         while(Arq.hasNext()){
             line = Arq.readLine();
             Pokemon p = new Pokemon();
             p.ler(line);
             try {
                 pokemon.inserirFim(p);
             } catch (Exception e) {
                 System.err.println("Erro ao inserir Pokémon: " + e.getMessage());
             }
         }
         Arq.close();
 
         String str;
         int id;
 
         // Pesquisar pokemon por id
         while(!(str = MyIO.readLine()).equals("FIM")){
             id = Integer.parseInt(str);
             pokemon.mostrarId(id);
         }
 
         int newPokemons = MyIO.readInt(); // quantidade de registros a serem inseridos/removidos
         int cont = 0;
         Lista cadastros = new Lista();
 
         while(cont < newPokemons){
             str = MyIO.readLine();
 
             String[] subString = str.split(" ");
 
             if(subString[0].equals("II") || subString[0].equals("IF")){
                 Arq.openRead("" + subString[1] + ".csv");
                 
                 Arq.readLine(); // Lê a primeira linha
                 while(Arq.hasNext()){
                     line = Arq.readLine();
                     Pokemon p = new Pokemon();
                     p.ler(line);
 
                     try {
                         cadastros.inserirFim(p);
                     } catch (Exception e) {
                         System.err.println("Erro ao inserir Pokémon: " + e.getMessage());
                     }
                     
                     if(str.equals("II")){
                         try {
                             pokemon.inserirInicio(p);
                         } catch (Exception e) {
                             System.err.println("Erro ao inserir Pokémon: " + e.getMessage());
                         }
                     }
                     else{
                         try {
                             pokemon.inserirFim(p);
                         } catch (Exception e) {
                             System.err.println("Erro ao inserir Pokémon: " + e.getMessage());
                         }
                     }
                 }          
                 Arq.close();
             }
             else if(subString[0].equals("I*")){
                 Arq.openRead("" + subString[2] + ".csv");
 
                 Arq.readLine(); // Lê a primeira linha
                 while(Arq.hasNext()){
                     line = Arq.readLine();
                     Pokemon p = new Pokemon();
                     p.ler(line);
                     
                     try {
                         cadastros.inserirFim(p);
                     } catch (Exception e) {
                         System.err.println("Erro ao inserir Pokémon: " + e.getMessage());
                     }
 
                     try {
                         pokemon.inserir(p, Integer.parseInt(subString[1]));
                     } catch (Exception e) {
                         System.err.println("Erro ao inserir Pokémon: " + e.getMessage());
                     }
                 }  
                 Arq.close();        
             }
             else if(subString[0].equals("RI")){
                 try {
                     System.out.println("(R) " + pokemon.removerInicio().getName());
                 } catch (Exception e) {
                     System.err.println("Erro ao remover Pokémon do início: " + e.getMessage());
                 }
             } else if(subString[0].equals("RF")){
                 try {
                     System.out.println("(R) " + pokemon.removerFim().getName());
                 } catch (Exception e) {
                     System.err.println("Erro ao remover Pokémon do fim: " + e.getMessage());
                 }
             } else if(subString[0].equals("R*")){
                 try {
                     System.out.println("(R) " + pokemon.remover(Integer.parseInt(subString[1])).getName());
                 } catch (Exception e) {
                     System.err.println("Erro ao remover Pokémon da posição " + subString[1] + ": " + e.getMessage());
                 }
             }
             cont++;
         }
         cadastros.mostrar();
     }
 }