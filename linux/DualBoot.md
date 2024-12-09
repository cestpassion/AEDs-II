# Dual Boot: Windows e Linux  

Este guia detalhado explica como configurar um sistema dual boot com Windows e Linux no mesmo dispositivo. Antes de começar, leia atentamente e faça backup de todos os seus dados importantes.

---

## ⚠️ Aviso  
- O procedimento pode ser arriscado e resultar em perda de dados ou danos ao sistema.  
- Certifique-se de que você entende cada etapa antes de prosseguir.  
- Use o procedimento por sua conta e risco.

---

## ✅ Pré-requisitos  

1. **Dispositivo com Windows instalado.**  
2. **Pen drive (8GB ou mais) para o instalador do Linux.**  
3. **Distribuição Linux (ISO),** como Ubuntu, Fedora ou Mint.  
4. **Ferramenta para criar pendrive bootável:**  
   - Windows: [Rufus](https://rufus.ie)  
   - Linux: `dd` ou `balenaEtcher`.  
5. **Espaço disponível no disco:** pelo menos 20 GB para o Linux.  
6. **Backup dos dados importantes.**  

---

## 🛠️ Passo a Passo  

### 1. Preparar o Windows  
1. **Verifique o espaço disponível:**  
   - No Windows, vá ao *Explorador de Arquivos* → *Este Computador* → clique com o botão direito no disco (geralmente `C:`) → *Propriedades*.  

2. **Reduza o tamanho do disco:**  
   - Pressione `Win + R`, digite `diskmgmt.msc` e pressione *Enter*.  
   - Clique com o botão direito no disco principal e selecione *Diminuir Volume*.  
   - Libere pelo menos 20 GB para o Linux (recomenda-se 50 GB ou mais).  

3. **Desative o Inicialização Rápida:**  
   - Acesse *Painel de Controle* → *Opções de Energia* → *Escolher o comportamento dos botões de energia*.  
   - Clique em *Alterar configurações não disponíveis no momento*.  
   - Desmarque a opção *Ativar inicialização rápida*.  

---

### 2. Criar o Pendrive Bootável  
1. Baixe a ISO da distribuição Linux de sua preferência.  
2. Conecte o pendrive ao computador.  
3. Use o Rufus para criar o pendrive bootável:  
   - Selecione o dispositivo (pendrive).  
   - Escolha a ISO do Linux.  
   - Configure o esquema de partição como *GPT* (para sistemas UEFI) ou *MBR* (para sistemas mais antigos).  
   - Clique em *Iniciar*.  

---

### 3. Configurar a BIOS/UEFI  
1. **Reinicie o computador e entre na BIOS/UEFI:**  
   - Pressione a tecla apropriada durante a inicialização (*ESC*, *DEL*, *F2*, etc.).  
2. **Configure a ordem de boot:**  
   - Certifique-se de que o pendrive está configurado como a primeira opção de inicialização.  
3. Desative o *Secure Boot* (se necessário).  

---

### 4. Instalar o Linux  
1. **Inicie pelo pendrive:**  
   - Insira o pendrive e reinicie o computador.  
   - Escolha o pendrive no menu de inicialização.  

2. **Inicie o instalador do Linux:**  
   - Escolha *Try Linux* para usar o sistema sem instalar (opcional).  
   - Clique em *Install Linux*.  

3. **Escolha a opção de instalação:**  
   - Selecione *Instalar ao lado do Windows* (se disponível).  
   - Caso contrário, escolha *Particionamento Manual* e configure as partições:  
     - **/ (Raiz):** 20 GB (Ext4).  
     - **Swap (opcional):** igual à RAM do sistema.  
     - **/home:** o restante do espaço livre (Ext4).  

4. **Siga as instruções:**  
   - Defina idioma, fuso horário, nome de usuário e senha.  

---

### 5. Configurar o GRUB  
- O GRUB será instalado automaticamente durante o processo de instalação.  
- Ele detectará o Windows e adicionará ao menu de inicialização.  

---

### 6. Finalizar  
1. Remova o pendrive após a instalação.  
2. Reinicie o computador e escolha o sistema operacional no GRUB.  

---

## 🩹 Problemas Comuns  
- **Windows não aparece no GRUB:**  
  - Inicie o Linux, abra o terminal e execute:  
    ```bash
    sudo update-grub
    ```  
- **Sistema não inicializa:**  
  - Verifique a ordem de boot na BIOS/UEFI.  

---

Com o dual boot configurado, você pode alternar entre Windows e Linux conforme necessário. Boa sorte! 🎉
