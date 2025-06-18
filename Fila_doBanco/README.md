
# 🏦 Trabalho Prático 04 — Fila do Banco

## 📖 Descrição

Este projeto implementa a simulação de uma **fila de atendimento em banco**, com atendimento prioritário e restrições de atendimento sequencial. A proposta envolve a criação de duas filas, sendo uma para o **público geral** e outra para **prioridades**, atendidas de acordo com as regras definidas.

---

## 📌 Objetivos

✅ Implementar uma TAD **Fila Estática Circular** em linguagem **C**.  
✅ Separar o projeto em arquivos `.h` para as declarações e `.c` para as implementações da TAD Fila.  
✅ Criar um programa que simula o funcionamento de um banco, respeitando as restrições de atendimento entre as filas.  
✅ Incluir um **Makefile** para automatizar a compilação.  
✅ Aplicar boas práticas de codificação e estrutura modular.

---

## 📝 Regras de Atendimento

- Se a fila de prioridades estiver vazia, o atendimento ocorre com o primeiro da fila geral.
- Se a fila de prioridades **não estiver vazia**, ela tem preferência, **desde que não tenha sido atendido três clientes prioritários consecutivos**.
- Caso três clientes prioritários sejam atendidos seguidos, obrigatoriamente um cliente da fila geral será chamado antes de retornar para a fila de prioridades.

---

## 📥 Entrada e 📤 Saída

**Entrada:**  
- Comando de inserção de cliente na fila:  
  `p Nome` → cliente prioritário  
  `g Nome` → cliente geral  
- Comando de chamada de cliente para atendimento: `s`  
- Comando de encerramento do expediente: `f`  

**Saída:**  
- Ordem dos clientes atendidos após o comando `f`.

### 📌 Exemplo:

**Entrada:**
```
g Rodrigo
g Bia
p Joel
s
g Fatima
p Frederico
p Luciana
s
s
p Fabiana
p Elen
p Fabio
g Valter
s
s
s
s
s
s
s
f
```

**Saída:**
```
Joel
Frederico
Luciana
Rodrigo
Fabiana
Elen
Fabio
Bia
Fatima
Valter
```

## 👥 Integrantes do Grupo

- Nicolas Ferezini  
