# Principais Comandos - AEDS II

Este documento oferece uma referência rápida dos principais comandos utilizados durante a disciplina de Algoritmos e Estrutura de Dados II. Ele abrange comandos essenciais para Linux, VIM, e linguagens de programação como Java, C/C++, e C#.

## Índice

- [Linux](#linux)
- [VIM](#vim)
- [Java](#java)
- [C/C++](#cc)
- [C#](#csharp)

## Linux

Comandos básicos para uso do terminal no Linux:

```bash
# Navegação entre diretórios
cd [diretório]     # Entra no diretório especificado
cd ..              # Retorna ao diretório anterior

# Listagem de arquivos
ls                 # Lista os arquivos do diretório atual
ls -la             # Lista com detalhes e arquivos ocultos

# Manipulação de arquivos e diretórios
cp [origem] [destino]  # Copia arquivos ou diretórios
mv [origem] [destino]  # Move ou renomeia arquivos ou diretórios
rm [arquivo]           # Remove arquivos
rm -r [diretório]      # Remove diretórios recursivamente

# Exibição de conteúdo de arquivos
cat [arquivo]      # Mostra o conteúdo de um arquivo
less [arquivo]     # Exibe o conteúdo de um arquivo página por página
```

## VIM

Comandos básicos para edição de texto no VIM:

```bash
# Modos de operação
i                   # Entra no modo de inserção
Esc                 # Sai do modo de inserção para o modo normal

# Salvando e saindo
:w                  # Salva o arquivo
:q                  # Sai do editor
:wq                 # Salva e sai do editor
:q!                 # Sai sem salvar as alterações

# Navegação
h, j, k, l          # Movimenta o cursor (esquerda, baixo, cima, direita)
gg                  # Vai para o início do arquivo
G                   # Vai para o fim do arquivo

# Edição
dd                  # Deleta uma linha
yy                  # Copia uma linha
p                   # Cola o conteúdo copiado
u                   # Desfaz a última ação
```

## Java

Comandos básicos para compilação e execução de programas em Java:

```bash
# Compilação
javac [arquivo.java]    # Compila o arquivo Java

# Execução
java [NomeDaClasse]     # Executa a classe compilada

# Pacotes
javac -d [diretório] [arquivo.java]   # Compila o arquivo e coloca os .class em um diretório especificado
```

## C/C++

Comandos básicos para compilação e execução de programas em C e C++:

```bash
# Compilação C
gcc [arquivo.c] -o [executável]    # Compila o arquivo C

# Compilação C++
g++ [arquivo.cpp] -o [executável]  # Compila o arquivo C++

# Execução
./[executável]                    # Executa o programa compilado
```

## C#

Comandos básicos para compilação e execução de programas em C# usando o .NET CLI:

```bash
# Criação de projeto
dotnet new console -n [NomeDoProjeto]   # Cria um novo projeto de console

# Compilação
dotnet build                            # Compila o projeto

# Execução
dotnet run                              # Executa o projeto
```
