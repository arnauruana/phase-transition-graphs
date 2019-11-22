# Grau-A-Projecte-T19

Transició de fase i components connexes en grafs aleatoris.

## Recursos

* Documentació (Només lectura): https://www.overleaf.com/read/vtpvhcbdvqvq
* Tutorial doctest: https://accu.org/index.php/journals/2343
* Binamial Random Graphs: https://en.wikipedia.org/wiki/Erd%C5%91s%E2%80%93R%C3%A9nyi_model
* Random Geometric Graphs: https://en.wikipedia.org/wiki/Random_geometric_graph
* GraphViz Online Generator: http://webgraphviz.com/
* Un altre GraphViz Online Generator: https://dreampuf.github.io/GraphvizOnline/

### Nota sobre GraphViz

Es necessari fer servir el motor NEATO per generar grafs on es tingui en compte la posició dels nodes. D'altre manera els nodes es posicionen automàticament.

Podeu instal·lar GraphViz al vostre PC (Linux) amb la comanda:

`````shell
apt install graphviz
`````

Per generar una imatge d'un graf podeu usar:

`````shell
./graph OPCIONS | dot -Kneato -Tpng -o graph.png
`````

Per exemple:

````shell
./graph rgg 32 0.3 -p | dot -Kneato -Tpng -o graph.png
````



## Compilar i executar

El projecte es pot compilar amb un compilador de C++11 i Make (Linux). A continuació un exemple amb una distribució basada en Debian.

`````shell
apt install build-essential
make
`````

Aquí teniu un altre exemple amb una distribució basada en ArchLinux:

~~~shell
sudo pacman -S gcc make r --needed --noconfirm
make
~~~

A continuació us posem la ajuda d'execució.

````shell
Usage:
        ./graph test
        ./graph brg n p [OPTIONS]
        ./graph rgg n r [OPTIONS]

Where n is the amount of vertex (natural number), and p and r are decimal numbers in the range 0-1, or intervals wiritten in the form low:hight:step

Options:
 -p         (Default) Print the graph.
 -c         Print the number of connected componenets.
 -c k       Like C but do it k times and output a CSV space separated table.
 -s         Print the size of the maximum connected component.
 -s k       Like S but do it k times and output a CSV space separated table.
 -k         Print whether the graph is complete or not.
 -k k       Like K but do it k times and output a CSV space separated table.
 -r         Print whether the graph is regular or not.
 -r k       Like R but do it k times and output a CSV space separated table.
````

Per exemple, per generar una llista del número de components conexes dels grafs de mida 20 en el model binomail des de p=0, fins a p=0.5 amb un increment de 0.005 a cada iteració es pot fer amb la seguent commanda:

````shell
./graph brg 20 0.0:0.5:0.005 -c
````

### Generar els grafics de linies
El codi en R utilitzat ha estat el seguent (adaptat a cada cas):
````R
mydf <- read.table("brg1.csv", sep=" ")
b <- sapply(mydf, function (x) as.integer(x>1))
x <- seq(0,0.99999,0.001)
v <- rowMeans(b[,-101])

plot(x,v, type = "l",xlab="p",ylab="")
````

**Per a general el grafic del desplaçament de la transició de fase el codi es el seguent:**

````R
filelist <- list.files(pattern="*.csv")
library(gtools)
filelist <- mixedsort(filelist)

thecenter <- function(filepath) {
  mydf <- read.table(filepath, sep=" ")
  b <- sapply(mydf, function (x) as.integer(x<=1))
  x <- seq(0,999)
  v <- rowMeans(b[,-1001])
  z <- sapply(v, function (x) 0.5-abs(x-0.5))
  z <- smooth(z, "3RSS")
  m <- mean(which(z==max(z)))
  #plot(z, type = "l", xlab="% of p",ylab="")
  return(m)
}

x <- thecenter("t-brg5.csv")
print(filelist)
b <- sapply(filelist, function (x) thecenter(x))
s <- seq(5,100,5)
plot(s, b, type = "l", ylab="% of p", xlab="N")
````

## Authors

- [@arnauruana](https://github.com/arnauruana)
- [@elmeunick9](https://github.com/elmeunick9)
- [@thesorahd](https://github.com/thesorahd)
