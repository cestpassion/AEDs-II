# Principais Comandos - AEDS II

Este documento oferece uma referência abrangente dos principais comandos utilizados durante a disciplina de Algoritmos e Estrutura de Dados II. Ele abrange comandos essenciais para Linux, VIM, e linguagens de programação como Java, C/C++, e C#.

## Índice

- [Linux](#linux)
- [VIM](#vim)
- [Java](#java)
- [C/C++](#cc)
- [C#](#csharp)

## Cheat-Sheets

- [C++ Cheat Sheet](CPP-Cheat-Sheet.pdf)
- [C# Cheat Sheet](CSharp-Cheat-Sheet.pdf)
- [Java Cheat Sheet](Java-Cheat-Sheet.pdf)
- [Linux Cheat Sheet](Linux-Cheat-Sheet.pdf)
- [VIM Cheat Sheet](Vim-Cheat-Sheet.pdf)

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

VIM é um editor de texto poderoso e versátil. Aqui estão alguns comandos e técnicas essenciais para ajudá-lo a navegar e editar arquivos eficientemente.

### Modos de Operação

- **Modo Normal**: O modo padrão ao abrir o VIM, onde você pode executar comandos de navegação e edição.
- **Modo de Inserção**: Usado para editar o texto.
- **Modo Visual**: Usado para selecionar texto.

```bash
# Entrar em diferentes modos
i                   # Entra no modo de inserção (antes do cursor)
I                   # Entra no modo de inserção (no início da linha)
a                   # Entra no modo de inserção (depois do cursor)
A                   # Entra no modo de inserção (no final da linha)
Esc                 # Sai do modo de inserção e volta para o modo normal
v                   # Entra no modo visual (seleção de texto)
V                   # Entra no modo visual em linha (seleção de linhas)
Ctrl + v             # Entra no modo visual de bloco (seleção de bloco de texto)
```

### Salvando e Saindo

```bash
:w                  # Salva o arquivo
:w [arquivo]        # Salva o arquivo com um nome diferente
:wq                 # Salva e sai do editor
:x                  # Equivalente a :wq
:q                  # Sai do editor (se não houver alterações)
:q!                 # Sai sem salvar as alterações
:wq!                # Força a escrita e saída, mesmo se o arquivo estiver somente leitura
```

### Navegação

```bash
h, j, k, l          # Movimenta o cursor (esquerda, baixo, cima, direita)
0                   # Vai para o início da linha
$                   # Vai para o final da linha
gg                  # Vai para o início do arquivo
G                   # Vai para o fim do arquivo
[linha]G             # Vai para uma linha específica
Ctrl + f            # Avança uma página
Ctrl + b            # Retrocede uma página
```

### Edição

```bash
dd                  # Deleta a linha atual
d[comando]          # Deleta com base em movimento (ex: dw para deletar uma palavra)
yy                  # Copia (yanka) a linha atual
y[comando]          # Copia com base em movimento (ex: yw para copiar uma palavra)
p                   # Cola o conteúdo copiado após o cursor
P                   # Cola o conteúdo copiado antes do cursor
x                   # Deleta o caractere sob o cursor
r [caractere]       # Substitui o caractere sob o cursor por outro
u                   # Desfaz a última ação
Ctrl + r            # Refaz a última ação desfeita
```

### Pesquisa e Substituição

```bash
/ [termo]           # Pesquisa o termo para frente
? [termo]           # Pesquisa o termo para trás
n                   # Vai para a próxima ocorrência da pesquisa
N                   # Vai para a ocorrência anterior da pesquisa
:%s/[antigo]/[novo]/g  # Substitui todas as ocorrências no arquivo
:%s/[antigo]/[novo]/gc # Substitui todas as ocorrências no arquivo com confirmação
```

### Seleção e Manipulação de Texto

```bash
v                   # Seleciona texto no modo visual
V                   # Seleciona linhas no modo visual
Ctrl + v             # Seleciona um bloco de texto no modo visual de bloco
d                   # Deleta o texto selecionado
y                   # Copia o texto selecionado
p                   # Cola o texto copiado
```

### Trabalhando com Múltiplos Arquivos

```bash
:tabnew [arquivo]   # Abre um novo arquivo em uma nova aba
:tabn              # Vai para a próxima aba
:tabp              # Vai para a aba anterior
:bn                # Vai para o próximo buffer
:bp                # Vai para o buffer anterior
:bd                # Deleta (fecha) o buffer atual
```

### Outros Comandos Úteis

```bash
:set number         # Exibe números de linha
:set nonumber       # Oculta números de linha
:set relativenumber # Exibe números de linha relativos
:! [comando]        # Executa um comando do shell (ex: :!ls)
:read [arquivo]     # Insere o conteúdo de um arquivo no cursor
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
