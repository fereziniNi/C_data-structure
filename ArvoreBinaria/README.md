
# 🌳 Trabalho Prático 05 — Árvore Binária

## 📖 Descrição

Este projeto implementa um **TAD Árvore Binária** em linguagem **C**, permitindo a criação e manipulação de árvores binárias a partir de uma notação textual em parênteses. O programa oferece operações clássicas de percurso e consulta, além de verificação de expressões malformadas.

---

## 📌 Objetivos

✅ Implementar a TAD **Árvore Binária** em C.  
✅ Separar as declarações em arquivos `.h` e as implementações em arquivos `.c`.  
✅ Realizar a verificação de aninhamento correto de parênteses na operação `create`.  
✅ Criar um **Makefile** para automatizar a compilação.  
✅ Manter o projeto organizado e as funções coesas.  

---

## 📋 Operações Disponíveis

- `create (<expressão>)` → Cria a árvore a partir da notação com parênteses.
- `pre` → Imprime a visitação dos nós em pré-ordem.
- `in` → Imprime a visitação dos nós em in-ordem.
- `post` → Imprime a visitação dos nós em pós-ordem.
- `height <n>` → Exibe a altura do nó `n`.
- `print` → Imprime a estrutura hierárquica da árvore no console.
- `exit` → Encerra o programa.

---

## 📝 Exemplo de Utilização

**Entrada:**
```
create (A,(B,(),()),(C,(F,(),()),()))
print
pre
in
post
exit
```

**Saída:**
```
   C
      F
A
   B

A B C F 
B A F C 
B F C A 
```



## 👥 Integrantes do Grupo

- Nicolas Ferezini  
