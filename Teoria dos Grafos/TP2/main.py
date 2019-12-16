import caixeiroViajante
import sys
import math

#Leitura do arquivo fonte do grafo

fileName = input("Arquivo do grafo: ")
'''
inicio = input("Digite o vértice de origem (primeiro é o vértice 0): ")
if(int(inicio)<0):
    print("Só é permitidos valores maiores ou iguais que 0 para vértice origem.")
    sys.exit()
final = int(input("Digite o vértice de destino: "))
'''
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
    peso = float(str[2])
    listaAdj[origem].append((destino,peso))
    matAdj[origem][destino] = peso
    arestas.append((origem,destino,peso))

print("Grafo: ",fileName)
[listaNearestneighbor,distanciaNN] = caixeiroViajante.nearestneighbor(listaAdj)
print("DistânciaNN: ", distanciaNN)
print("Processando...")
listaTwoopt,distanciaOpt = caixeiroViajante.twoopt(listaNearestneighbor,listaAdj)
print("Distância 2opt: ",distanciaOpt)
print("Rota: ",listaTwoopt)


