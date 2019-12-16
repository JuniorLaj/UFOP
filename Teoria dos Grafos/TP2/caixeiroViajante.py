import math
import time
from random import randint
from random import choice

def nearestneighbor(listaAdj):
    u = 0
    s = []
    s.append(u)
    naoVisitados = [x for x in range(len(listaAdj))]
    naoVisitados.remove(u)
    while(len(naoVisitados)!=0):
        x = listaAdj[u]
        aux = math.inf
        v = None
        for z in x:
            adj = z[0]
            peso = z[1]
            if(aux>peso and adj in naoVisitados):
                aux = peso
                v = adj
        s.append(v)
        naoVisitados.remove(v)
        u = v
    s.append(s[0])
    distancia = avalia(s,listaAdj)
    return s,distancia

def twoopt(listaS,listaAdj):
    tempoDisponivel = 10
    distancia = None
    while(tempoDisponivel>0):
        temp = time.time()
        i1 = randint(1,len(listaS)-2)
        i2 = randint(1,len(listaS)-2)
        if(i1!=i2):
            sLinha = listaS.copy()
            i1Aux = sLinha[i1]  
            i2Aux = sLinha[i2]
            sLinha[i1] = i2Aux
            sLinha[i2] = i1Aux
            distsLinha = avalia(sLinha,listaAdj)
            distS =  avalia(listaS,listaAdj)
            if(distsLinha < distS):
                listaS = sLinha.copy()
                distancia = distsLinha
            else:
                distancia = distS
        temp2 = (time.time() - temp)
        tempoDisponivel = tempoDisponivel - temp2
    return (listaS,distancia)

def avalia(s,listaAdj):
    custo = 0
    for i in range(0,len(s)-1):
        u = s[i]
        v = s[i+1]
        for x in listaAdj[u]:
            if(x[0]==v):
                peso = x[1]
                custo = custo + peso
                break
    return custo