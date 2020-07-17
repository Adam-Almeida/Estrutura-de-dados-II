![](https://github.com/Adam-Almeida/estrutura-de-dados-II/blob/master/ADAMPERSONALGIT.png)


# C - Shellsort | Csv | Struct
> App de exibição de conteúdo do arquivo .csv ordenado.

Utilize o código apenas como estudo e base para o seu aprendizado.

> Saída em oredenação alfabética em III Colunas.
![]()

> Saída em oredenação alfabética em V Colunas.
![](https://github.com/Adam-Almeida/estrutura-de-dados-II/blob/master/exSaidaVcolumns.jpg)


## Code -> Shellsort

A - Z | :

```sh
for (pri = 0; pri <= total; pri++)
  {
    for(y = pri+1; y <= total; y++){
      r = strcmp(nome[pri], nome[y]);
      if (r > 0){		
        strcpy(aux, nome[pri]);
        strcpy(nome[pri], nome[y]);
        strcpy(nome[y], aux);
      }
    }
```

Inversão da Ordenação Z - A:

```sh
if (r > 0)
```

## Estrutado arquivo .csv

> O arquivo .csv exibido está divido em 5 colunas, sendo cada uma delas separadas por (ponto e vírgula).

```sh
codigo_ocorrencia;fator_nome;fator_aspecto;fator_condicionante;fator_area
```
