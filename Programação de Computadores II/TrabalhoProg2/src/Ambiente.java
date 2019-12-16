/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.ArrayList;
import java.util.Random;
/**
 *
 * @author Junior
 */
public class Ambiente {
    private char[][] matriz;
    
    public Ambiente(){
       this.matriz = new char[16][16];
    }
       
    public char[][] getMatriz() {
        return matriz;
    }
    
    public char getNome(int x, int y) {
    	return (this.matriz[x][y]);
    }
    
    public void setNome(int x, int y, char nome) {
    	this.matriz[x][y] = nome;
    }
    
    // Função que verifica se a posição (x, y) esta dentro dos limite da matriz
    // Retorna true caso esteja e false caso nao esteja
    public boolean dentroDosLimites(int x, int y) {
    	if(x>15 || x<0 || y>15 || y<0)
    		return false;
    	return true;
    }
    
    public void setMatriz(char[][] matriz) {
        this.matriz = matriz;
    }

    public void imprimirMatriz(){
       
        for(int i=0; i<this.matriz.length; i++){
            for(int j=0; j<this.matriz.length; j++){
                System.out.print(this.matriz[i][j] + "  ");
            }
            System.out.print("\n");
        }
    }
    
    public void addAvulso(ArrayList<Ator> ator){
         Random rand = new Random();
         int k, p;
         
         for(int i=0; i<this.matriz.length; i++){
             for(int j=0; j<this.matriz.length; j++){
                     matriz[i][j] = '-';
             }
         }
         
         for(int i=0; i<ator.size(); i++){
            k = rand.nextInt(16);
            p = rand.nextInt(16);
            if(this.matriz[k][p] != '-') {
            	i--;
            	continue;
            }
            this.matriz[k][p] = ator.get(i).getNome();
            ator.get(i).setLocalizacao(k, p);
            }
        }
         
    }
