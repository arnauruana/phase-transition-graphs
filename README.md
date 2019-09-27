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
cd ./source
make
`````

A continuació us posem la ajuda d'execució.

````shell
Usage:
        ./graph test
        ./graph brg n p [OPTIONS]
        ./graph rgg n r [OPTIONS]

Options:
 -p     (Default) Print the graph.
 -c     Print the number of connected componenets.
````

