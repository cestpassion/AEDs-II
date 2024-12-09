# Tabela Hash em Java

Este projeto implementa uma **Tabela Hash** em Java, utilizando **encadeamento separado** para tratar colisões. A tabela suporta operações de inserção, busca e remoção de elementos, garantindo eficiência e manutenibilidade.

---

## **O que é uma Tabela Hash?**

A **Tabela Hash** é uma estrutura de dados que associa chaves a valores utilizando uma função hash para calcular o índice da chave. Quando múltiplas chaves resultam no mesmo índice (colisão), usamos técnicas como o **encadeamento separado** para tratá-las.

---

## **Funcionamento**

### 1. **Função Hash**
A função hash é responsável por mapear uma chave a um índice na tabela. Neste projeto, usamos:
```java
private int hashFunction(String key) {
    return key.hashCode() % tableSize;
}
```
- `hashCode()` retorna um valor inteiro baseado na chave.
- `tableSize` é o tamanho fixo da tabela, usado para limitar os índices.

### 2. **Tratamento de Colisões**
Usamos **listas ligadas** em cada posição da tabela para armazenar os valores que colidirem no mesmo índice.

### 3. **Operações**
- **Inserção**: Insere o par `(chave, valor)` na tabela, calculando o índice pela função hash.
- **Busca**: Localiza um valor associado à chave, percorrendo a lista na posição calculada.
- **Remoção**: Remove um par `(chave, valor)` da tabela.

---

## **Código Principal**

### Estrutura da Tabela Hash
```java
class HashTable<K, V> {
    private LinkedList<Entry<K, V>>[] table;
    private int tableSize;

    public HashTable(int size) {
        this.tableSize = size;
        this.table = new LinkedList[size];
        for (int i = 0; i < size; i++) {
            table[i] = new LinkedList<>();
        }
    }

    private int hashFunction(K key) {
        return Math.abs(key.hashCode() % tableSize);
    }

    public void put(K key, V value) {
        int index = hashFunction(key);
        for (Entry<K, V> entry : table[index]) {
            if (entry.key.equals(key)) {
                entry.value = value; // Atualiza o valor se a chave já existir
                return;
            }
        }
        table[index].add(new Entry<>(key, value));
    }

    public V get(K key) {
        int index = hashFunction(key);
        for (Entry<K, V> entry : table[index]) {
            if (entry.key.equals(key)) {
                return entry.value;
            }
        }
        return null; // Não encontrado
    }

    public void remove(K key) {
        int index = hashFunction(key);
        table[index].removeIf(entry -> entry.key.equals(key));
    }
}
```

### Classe Auxiliar para os Pares
```java
class Entry<K, V> {
    K key;
    V value;

    Entry(K key, V value) {
        this.key = key;
        this.value = value;
    }
}
```

---

## **Teste de Mesa**

### **Exemplo**
1. Tabela de tamanho `5`.
2. Chaves inseridas: `"A"`, `"B"`, `"C"`, `"D"`, `"E"`.
3. Função hash: `hashCode % 5`.

| **Chave** | **Hash** | **Índice** | **Lista no Índice**      |
|-----------|----------|------------|--------------------------|
| `"A"`     | `65`     | `0`        | `[A -> Valor de A]`      |
| `"B"`     | `66`     | `1`        | `[B -> Valor de B]`      |
| `"C"`     | `67`     | `2`        | `[C -> Valor de C]`      |
| `"D"`     | `68`     | `3`        | `[D -> Valor de D]`      |
| `"E"`     | `69`     | `4`        | `[E -> Valor de E]`      |

### Após Inserir uma Chave com Colisão:
Chave `"F"`, índice `0` (colisão com `"A"`).

| **Chave** | **Hash** | **Índice** | **Lista no Índice**               |
|-----------|----------|------------|-----------------------------------|
| `"A"`     | `65`     | `0`        | `[A -> Valor de A, F -> Valor de F]` |

---

## **Complexidade**

| Operação   | Melhor Caso | Pior Caso               |
|------------|-------------|-------------------------|
| **Inserção** | O(1)        | O(n) (todas chaves colidem) |
| **Busca**    | O(1)        | O(n) (colisões em um índice)|
| **Remoção**  | O(1)        | O(n) (colisões em um índice)|

### **Fatores que afetam o desempenho**
- **Tamanho da tabela**: Uma tabela maior reduz colisões.
- **Função hash**: Uma função bem distribuída evita clusters de colisões.
- **Carga da tabela**: A relação `(número de elementos) / (tamanho da tabela)` deve ser mantida baixa.

---

## **Testes**

```java
public class Main {
    public static void main(String[] args) {
        HashTable<String, String> table = new HashTable<>(5);

        // Inserções
        table.put("A", "Valor A");
        table.put("B", "Valor B");
        table.put("C", "Valor C");
        table.put("D", "Valor D");
        table.put("E", "Valor E");

        // Busca
        System.out.println("Valor associado à chave 'C': " + table.get("C")); // Esperado: Valor C

        // Remoção
        table.remove("C");
        System.out.println("Valor associado à chave 'C' após remoção: " + table.get("C")); // Esperado: null
    }
}
```

---

## **Melhorias Futura**
- **Redimensionamento Dinâmico**: Rehashing automático ao ultrapassar uma carga máxima.
- **Suporte a Genéricos**: Adicionar flexibilidade para diferentes tipos de chaves e valores.
- **Funções Hash Customizáveis**: Permitir que o usuário defina sua própria função hash.
