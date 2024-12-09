# Guia de Instalação e Uso do WSL (Windows Subsystem for Linux)  

O **WSL (Windows Subsystem for Linux)** permite executar um ambiente Linux diretamente no Windows, sem necessidade de máquinas virtuais ou dual boot. Este guia explica como baixar, instalar e utilizar o WSL.

---

## 🛠️ Pré-requisitos  
1. **Sistema operacional compatível:**  
   - Windows 10 (versão 2004 ou superior com Build 19041 ou superior).  
   - Windows 11.  
2. **Conexão com a Internet.**  
3. **Acesso de administrador ao sistema.**

---

## 📥 Passo 1: Ativar o WSL  

1. **Abrir o PowerShell como Administrador:**  
   - Pressione `Win + S`, digite *PowerShell*, clique com o botão direito em *Windows PowerShell* e selecione *Executar como administrador*.  

2. **Ativar o WSL:**  
   Execute o comando:  
   ```powershell
   wsl --install
   ```  
   Este comando instala o WSL, configura a versão 2 (WSL 2) como padrão e baixa uma distribuição Linux padrão (geralmente Ubuntu).  

3. **Reiniciar o computador:**  
   Após a instalação, reinicie o sistema para aplicar as alterações.  

---

## 🖥️ Passo 2: Escolher ou Instalar Outras Distribuições Linux  

1. **Listar distribuições disponíveis:**  
   Execute o comando no PowerShell:  
   ```powershell
   wsl --list --online
   ```  

2. **Instalar uma distribuição específica:**  
   Substitua `<NomeDistribuicao>` pelo nome da distribuição desejada:  
   ```powershell
   wsl --install -d <NomeDistribuicao>
   ```  

3. **Distribuições populares:**  
   - `Ubuntu`  
   - `Debian`  
   - `Kali-Linux`  
   - `Fedora`  

---

## 🛠️ Passo 3: Configurar o WSL  

1. **Definir a versão do WSL:**  
   Para garantir que você está usando o WSL 2, execute:  
   ```powershell
   wsl --set-default-version 2
   ```  

2. **Verificar distribuições instaladas:**  
   ```powershell
   wsl --list --verbose
   ```  

3. **Alterar a versão do WSL de uma distribuição:**  
   Substitua `<Distribuicao>` pelo nome da distribuição:  
   ```powershell
   wsl --set-version <Distribuicao> 2
   ```  

---

## ▶️ Passo 4: Usar o WSL  

1. **Abrir o Linux:**  
   - Digite o nome da distribuição no menu Iniciar (ex.: *Ubuntu*).  

2. **Configurar o ambiente inicial:**  
   - Durante o primeiro uso, você será solicitado a configurar um nome de usuário e senha para o ambiente Linux.  

3. **Executar comandos Linux:**  
   - Use comandos como `ls`, `cd`, `mkdir`, `sudo apt update`, etc., diretamente no terminal.  

---

## 🖇️ Integração com Windows  

1. **Acessar arquivos do Windows no WSL:**  
   - Os discos do Windows estão montados no caminho `/mnt/c`.  
   - Por exemplo:  
     ```bash
     cd /mnt/c/Users/SeuUsuario/Documents
     ```  

2. **Executar comandos do Windows no Linux:**  
   - Use o nome do comando no Linux, como:  
     ```bash
     notepad.exe
     ```  

3. **Usar o Linux no terminal do Windows:**  
   - Abra o PowerShell ou CMD e execute:  
     ```powershell
     wsl
     ```  

---

## 📦 Passo 5: Instalar Ferramentas no Linux  

1. **Atualizar o sistema:**  
   ```bash
   sudo apt update && sudo apt upgrade -y
   ```  

2. **Instalar pacotes adicionais:**  
   Exemplos:  
   - **Git:**  
     ```bash
     sudo apt install git -y
     ```  
   - **Node.js e npm:**  
     ```bash
     sudo apt install nodejs npm -y
     ```  
   - **Python:**  
     ```bash
     sudo apt install python3 python3-pip -y
     ```  

---

## 🩹 Problemas Comuns  

- **Erro: Virtualização desativada:**  
  Certifique-se de que a virtualização está habilitada na BIOS/UEFI.  

- **Distribuição não inicia:**  
  Reinstale a distribuição:  
  ```powershell
  wsl --unregister <Distribuicao>
  wsl --install -d <Distribuicao>
  ```  

- **Versão incompatível do WSL:**  
  Atualize o Windows para a versão mais recente.  

---

Com o WSL configurado, você pode aproveitar o poder do Linux integrado ao Windows para desenvolvimento e aprendizado! 🎉  
