import caminhoMinimo
import sys

#Leitura do arquivo fonte do grafo

fileName = input("Arquivo do grafo: ")
inicio = input("Digite o vértice de origem (primeiro é o vértice 0): ")
if(int(inicio)<0):
    print("Só é permitidos valores maiores ou iguais que 0 para vértice origem.")
    sys.exit()
final = int(input("Digite o vértice de destino: "))

file = open(fileName)
str = file.readline()
str = str.split(" ")
numVertices = int(str[0])
numArestas = int(str[1])

#Preenchimento das estruturas de dados

listaAdj = [[] for x in range(numVertices)]
matAdj = [[0 for x in range(numVertices)] for x in range(numVertices)]
vertices = [x for x in range(numVertices)]
arestas = []
for i in range(numArestas):
    str = file.readline()
    str = str.split(" ")
    origem = int(str[0])
    destino = int(str[1])
    peso = int(str[2])
    listaAdj[origem].append((destino,peso))
    matAdj[origem][destino] = peso
    arestas.append((origem,destino,peso))

    if(final>len(listaAdj)):
        print("Vértice de destino não existente nesse grafo!\n")
        sys.exit()

while(1):
    value = input("Digite o algoritmo que deseja executar:\n\t1 - Dijkstra\n\t2 - Bellman-Ford\n\t3 - Floyd-Warshall\n")
    if(int(value)==1):
        caminho,tempo,custo = caminhoMinimo.dijkstra(listaAdj,int(inicio),int(final))
        print("Origem: ",inicio)
        print("Destino: ",final)      
        print("Caminho: ",caminho)
        print("Custo: ",custo)
        print("Tempo gasto: ",tempo,"s")
        break;
    elif(int(value)==2):
        caminho,tempo,custo = caminhoMinimo.bellmanFord(listaAdj,arestas,int(inicio),int(final))
        print("Origem: ",inicio)
        print("Destino: ",final)      
        print("Caminho: ",caminho)
        print("Custo: ",custo)
        print("Tempo gasto: ",tempo,"s")
        break;
    elif(int(value)==3):
        caminho, tempo,custo = caminhoMinimo.floydWarshal(matAdj,int(inicio),int(final))
        print("Origem: ",inicio)
        print("Destino: ",final)      
        print("Caminho: ",caminho)
        print("Custo: ",custo)
        print("Tempo gasto: ",tempo,"s")
        break;
    else:
        print("Digite um valor correto.")
        
