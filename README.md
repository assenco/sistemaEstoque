# Sistema de Estoque

Sistema de linha de comando para controle de estoque de lojas em geral, desenvolvido em C.
Permite cadastrar produtos, consultar o estoque, editar ou remover itens, mantendo
os dados salvos entre execuções podendo gerar relatórios.

Este repositório também serve como registro da minha evolução como programador:
cada versão representa um novo conjunto de conceitos aplicados ao mesmo projeto.

---

## Funcionalidades

- Cadastro de produtos (nome, quantidade, preço)
- Consulta de todos os produtos em estoque
- Edição e remoção de produtos por código
- Validação de entradas do usuário
- Persistência dos dados em arquivo (a partir da v2)
- Geração de relatórios do estoque em uma página HTML (planejado)
- Disponibilização do sistema em um site para uso público (planejado)

---

## Tecnologias utilizadas

| Tecnologia | Uso no projeto |
|---|---|
| **C** | Linguagem base do sistema, toda a lógica de estoque |
| **Structs** | Organização dos dados de cada produto em uma única entidade (a partir da v2) |
| **Manipulação de arquivos (`fread`/`fwrite`)** | Persistência dos dados entre execuções (a partir da v2) |
| **HTML/CSS** | Interface visual da versão web (planejado) |
| **JavaScript** | Lógica e interatividade da versão web (planejado) |

---

## Versões do projeto

### v1.0 — Versão inicial
Primeira versão funcional do sistema, feita com os conceitos básicos de C.

- Dados armazenados em vetores paralelos (`produto`, `codigo`, `quantidade`, `preco`)
- Toda a lógica concentrada dentro da função `main`
- Sem persistência: os dados existem apenas durante a execução do programa e são perdidos ao fechar
- Objetivo: aplicar estruturas de controle (`if`, `for`, `while`, `switch`), vetores e validação de entrada

### v2.0 — Refatoração com structs, funções e persistência
Reescrita do sistema aplicando conceitos mais avançados de C, mantendo as mesmas funcionalidades da v1.

- Criação da `struct Produto`, unificando os dados de cada item numa só entidade
- Código dividido em funções (`cadastrar`, `consultar`, `editar`, funções de leitura validada, etc.), eliminando repetição
- Persistência dos dados em arquivo binário (`estoque.dat`), usando `fwrite`/`fread`
- Objetivo: aprender a organizar código em unidades reutilizáveis e a gravar dados fora da memória volátil

### v3.0 — Versão web (planejado)
Adaptação do sistema para funcionar em um navegador.

- Interface construída com HTML e CSS
- Lógica de interação em JavaScript
- Ainda em definição: se o back-end continuará em C (via servidor HTTP simples) ou se a lógica será reescrita em JavaScript, mantendo o C apenas como referência conceitual
- Objetivo: aprender o básico de desenvolvimento web e como conectar um sistema já existente a uma interface gráfica acessível pela internet

---

## Como executar (versão atual)

```bash
gcc -o estoque main.c
./estoque
```

O programa cria/lê automaticamente o arquivo `estoque.dat` na mesma pasta do executável.

---

## Estrutura do repositório

```
/
├── main.c          # Código-fonte da versão atual
├── README.md        # Este arquivo
```

*(conforme o projeto evoluir, versões anteriores serão preservadas em tags/releases do GitHub, mantendo o histórico de desenvolvimento acessível)*
