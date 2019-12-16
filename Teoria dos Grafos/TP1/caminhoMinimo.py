import math
import time
import sys

def dijkstra(listaAdj,inicio,fim):
    temp = time.time()
    math.inf
    dist = [9999999 for x in range(len(listaAdj))]
    pred = [[] for x in range(len(listaAdj))]
    dist[inicio] = 0
    listaAux = [x for x in range(len(listaAdj))]
    while(len(listaAux)!=0):
        z = 9999999
        u = 0
        for x in listaAux:
            if(z>dist[x]):
                z = dist[x]
                u = x
        listaAux.remove(u)
        for aux in listaAdj[u]:
            v = aux[0]
            peso = aux[1]
            if(dist[v]>dist[u]+peso):
                dist[v] = dist[u] + peso
                pred[v] = u

    caminho = recCaminhoVetor(inicio,fim,pred)
    tempF = time.time()
    return (caminho,(tempF-temp),dist[fim])

def bellmanFord(listaAdj,arestas,inicio,fim):
    temp = time.time()
    dist = [9999999 for x in range(len(listaAdj))]
    pred = [None for x in range(len(listaAdj))]
    dist[inicio] = 0
    for i in listaAdj:
        for x in arestas:
            u = x[0]
            v = x[1]
            peso = x[2]
            if(dist[v]>dist[u]+peso):
                dist[v] = dist[u] + peso
                pred[v] = u
    for x in arestas:
        u = x[0]
        v = x[1]
        peso = x[2]
        if(dist[v]>dist[u]+peso):
            print("Não é possível achar menor caminho!");
            sys.exit()

    caminho = recCaminhoVetor(inicio,fim,pred)
    tempF = time.time()
    return (caminho,(tempF-temp),dist[fim])

    

def floydWarshal(matAdj,inicio,fim):
    temp = time.time()
    dist = [[[] for i in range(len(matAdj))] for i in range(len(matAdj))]
    pred = [[[] for i in range(len(matAdj))] for i in range(len(matAdj))]
    
    for i in range(len(matAdj)):
        for j in range(len(matAdj)):
            if(i==j):
                dist[i][j] = 0
            elif(i!=j):
                if(matAdj[i][j]!=0):
                    dist[i][j] = matAdj[i][j]
                    pred[i][j] = i
                else:
                    dist[i][j] = 9999999
                    pred[i][j] = math.nan

    for k in range(len(matAdj)):
        for i in range(len(matAdj)):
            for j in range(len(matAdj)):
                if(dist[i][j]>(dist[i][k]+dist[k][j])):
                    dist[i][j] = dist[i][k] + dist[k][j]
                    pred[i][j] = pred[k][j]
    
    caminho = recCaminhoMatriz(inicio,fim,pred)
    tempF = time.time()
    return (caminho,(tempF-temp),dist[inicio][fim])
    
def recCaminhoVetor(inicio,fim,pred):
    caminho = []
    caminho.append(fim)
    aux = fim
    while(aux!=inicio):
        aux = pred[aux]
        caminho.insert(0,aux)
    
    return caminho

def recCaminhoMatriz(inicio,fim,pred):
    caminho = []
    caminho.append(fim)
    aux = fim
    while(aux!=inicio):
        aux = pred[inicio][aux]
        caminho.insert(0,aux)
    
    return caminho