# Principais Comandos - AEDS II

Este documento oferece uma referência abrangente dos principais comandos utilizados durante a disciplina de Algoritmos e Estrutura de Dados II. Ele abrange comandos essenciais para Linux, VIM, e linguagens de programação como Java, C/C++, e C#.

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
cd [diretório]             # Entra no diretório especificado
cd ..                      # Retorna ao diretório anterior
cd ~                       # Vai para o diretório home

# Listagem de arquivos
ls                         # Lista os arquivos e diretórios do diretório atual
ls -l                      # Lista com detalhes (permissões, proprietário, tamanho)
ls -a                      # Lista arquivos ocultos
ls -la                     # Lista com detalhes e arquivos ocultos

# Manipulação de arquivos e diretórios
cp [origem] [destino]      # Copia arquivos ou diretórios
cp -r [origem] [destino]   # Copia diretórios recursivamente
mv [origem] [destino]      # Move ou renomeia arquivos ou diretórios
rm [arquivo]               # Remove arquivos
rm -r [diretório]          # Remove diretórios recursivamente
mkdir [diretório]          # Cria um novo diretório
rmdir [diretório]          # Remove um diretório vazio

# Exibição de conteúdo de arquivos
cat [arquivo]              # Mostra o conteúdo de um arquivo
more [arquivo]             # Exibe o conteúdo do arquivo página por página
less [arquivo]             # Exibe o conteúdo do arquivo com navegação
head [arquivo]             # Mostra as primeiras linhas de um arquivo
tail [arquivo]             # Mostra as últimas linhas de um arquivo
tail -f [arquivo]          # Acompanha o crescimento do arquivo em tempo real

# Pesquisa de conteúdo
grep [padrão] [arquivo]    # Pesquisa o padrão dentro do arquivo
grep -r [padrão] [diretório]  # Pesquisa recursivamente no diretório

# Permissões de arquivos
chmod [permissões] [arquivo]  # Altera permissões de arquivos
chown [usuário]:[grupo] [arquivo]  # Altera proprietário e grupo de arquivos
```

## VIM

Comandos básicos para edição de texto no VIM:

```bash
# Modos de operação
i                   # Entra no modo de inserção (início da edição)
Esc                 # Sai do modo de inserção para o modo normal
:v                 # Entra no modo visual para seleção de texto

# Salvando e saindo
:w                  # Salva o arquivo
:q                  # Sai do editor
:wq                 # Salva e sai do editor
:q!                 # Sai sem salvar as alterações

# Navegação
h, j, k, l          # Movimenta o cursor (esquerda, baixo, cima, direita)
gg                  # Vai para o início do arquivo
G                   # Vai para o fim do arquivo
[linha]G             # Vai para uma linha específica

# Edição
dd                  # Deleta uma linha
d[comando]          # Deleta com base em movimento (ex: dw para deletar uma palavra)
yy                  # Copia uma linha
p                   # Cola o conteúdo copiado após o cursor
u                   # Desfaz a última ação
Ctrl + r            # Refaz a última ação desfeita

# Pesquisa e substituição
/p [termo]          # Pesquisa o termo para frente
? [termo]           # Pesquisa o termo para trás
:%s/[antigo]/[novo]/g  # Substitui todas as ocorrências no arquivo
```

## Java

Comandos básicos para compilação e execução de programas em Java:

```bash
# Compilação
javac [arquivo.java]             # Compila o arquivo Java
javac -d [diretório] [arquivo.java]  # Compila e coloca os arquivos .class em um diretório

# Execução
java [NomeDaClasse]              # Executa a classe compilada
java -cp [diretório]:[outros] [NomeDaClasse]  # Executa com classpath especificado

# Empacotamento
jar cf [arquivo.jar] [arquivos]  # Cria um arquivo JAR
jar tf [arquivo.jar]             # Lista o conteúdo do arquivo JAR
```

## C/C++

Comandos básicos para compilação e execução de programas em C e C++:

```bash
# Compilação C
gcc [arquivo.c] -o [executável]    # Compila o arquivo C
gcc -Wall -o [executável] [arquivo.c]  # Compila com todas as mensagens de advertência

# Compilação C++
g++ [arquivo.cpp] -o [executável]  # Compila o arquivo C++
g++ -std=c++17 [arquivo.cpp] -o [executável]  # Compila com uma versão específica do C++

# Execução
./[executável]                    # Executa o programa compilado

# Depuração
gdb [executável]                 # Inicia o depurador GDB
g++ -g [arquivo.cpp] -o [executável]  # Compila com informações de depuração
```

## C#

Comandos básicos para compilação e execução de programas em C# usando o .NET CLI:

```bash
# Criação de projeto
dotnet new console -n [NomeDoProjeto]   # Cria um novo projeto de console
cd [NomeDoProjeto]                      # Entra no diretório do projeto

# Compilação
dotnet build                            # Compila o projeto

# Execução
dotnet run                              # Executa o projeto

# Publicação
dotnet publish -c Release -o [diretório]  # Publica o projeto para o diretório especificado
```
