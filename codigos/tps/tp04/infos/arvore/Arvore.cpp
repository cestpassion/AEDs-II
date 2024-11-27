// ÁRVORE BINÁRIA EM C++

/* PONTEIROS

- São variáveis que armazenam um endereço de memória.

- Da mesma forma que um int armazena inteiro; um double, número real; um ponteiro
  armazena um endereço de memória.

- Os ponteiros possuem tipo,, ou seja, temos ponteirospara endereços de memória
  de um int, de um float de um char...

- + O asterisco na declaração de uma variável indica que essa não guardará um valor
  | e sim um endereço para o tipo especificado.
  +--> tipoPonteiro *nomeVariável;

- Operador endereço (&) determina o endereço de uma variável.
- Operador de conteúdo de um ponteiro (*) determina o conteúdo da posição de
  memória endereçada pelo ponteiro.

- + new ...
  | 
  +--+ ...
     +-- Ex:
            • char* p1 = new char;
            • int* p2 = new int;
            • float* p3 = new float;
            • Cliente* p4 = new Cliente;
            • int* p5 = new int [MAXTAM];
            • Cliente* p6 = new Cliente[MAXTAM];

- + delete ...
  | 
  +--+ 
     +-- Ex:  
            • delete p1;
            • delete p2;
            • delete p3;
            • delete p4;
            • delete [ ] p5;
            • delete [ ] p6;


*/