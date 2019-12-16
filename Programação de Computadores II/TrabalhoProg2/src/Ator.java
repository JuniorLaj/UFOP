import java.util.ArrayList;
import java.util.Random;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Junior
 */
public class Ator extends Sistema {
	char nome;
	int x;
	int y;
	int energia; 
	boolean reproduziu;
	char[][] visao; // ator enxerga apenas os que estão a sua volta, ele próprio é o centro da matriz
	char sexo;
	
	public Ator(char nome, char sexo, int energia) {
		this.nome = nome;
		this.energia = energia;
		this.sexo = sexo;
		this.reproduziu = false;
		visao = new char[3][3];
	}
	
	public Ator(char nome, char sexo, int energia, boolean reproduziu) {
		this.nome = nome;
		this.energia = energia;
		this.sexo = sexo;
		this.reproduziu = true;
		visao = new char[3][3];
	}
	
	public Ator(char nome, int energia) {
		this.nome = nome;
		this.energia = energia;
		visao = new char[3][3];
		this.reproduziu = true;
	}
	
	public boolean getReproduziu() {
		return this.reproduziu;
	}
	
	public void setReproduziu(boolean rep) {
		this.reproduziu = rep;
	}
	
	public int getX() {
		return x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public int getY() {
		return y;
	}

	public void setY(int y) {
		this.y = y;
	}

	public void setLocalizacao(int k, int h) {
		this.x = k;
		this.y = h;
	}

	public int getEnergia() {
		return energia;
	}

	public void setEnergia(int energia) {
		this.energia = energia;
	}

	public char getNome() {
		return (this.nome);
	}

	public void setNome(char nome) {
		this.nome = nome;
	}

	public void campoVisao(Ambiente ambiente) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (ambiente.dentroDosLimites(this.x + (i - 1), this.y + (j - 1)))
					this.visao[i][j] = ambiente.getNome(this.x + (i - 1), this.y + (j - 1));
				else
					this.visao[i][j] = '*';
			}
		}
	}

	public void imprimeCampoVisao() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				System.out.print(this.visao[i][j] + " ");
			}
			System.out.print("\n");
		}
	}

	/*
	 * METODO QUE VERIFICA SE ATOR É UMA PRESA LEAO DEVORA : CACHORRO, MACACO,
	 * GALINHA CACHORRO DEVORA: GALINHA MACACO E GALINHA DEVORAM : PLANTA
	 */
	private boolean presa(char n) {
		// LEAO COME TODOS OS OUTROS ANIMAIS
		if (this.nome == 'L' && (n == 'C' || n == 'M' || n == 'G'))
			return (true);
		// CACHORRO COME A GALINHA
		else if (this.nome == 'C' && (n == 'G'))
			return (true);
		// MACACO E GALINHA COMER PLANTA
		else if ((this.nome == 'M' || this.nome == 'G') && n == 'P')
			return (true);
		else
			return (false);

	}

	// METODO QUE VERIFICA SE ATOR É UM PREDADOR, SEGUE A MESMA CADEIA ALIMETAR DO
	// METODO PRESA
	private boolean predador(char n) {
		// LEAO NAO POSSUI PREDADOR
		if (this.nome == 'L')
			return (false);
		// LEAO COME TODOS OS OUTROS ANIMAIS
		else if ((this.nome == 'C' || this.nome == 'M' || this.nome == 'G') && n == 'L')
			return (true);
		// CACHORRO COME A GALINHA
		else if ((this.nome == 'G') && (n == 'C'))
			return (true);
		else
			return (false);
	}

	// METODO DIRECAO, DIZ AO ATOR EM QUAL DIRECAO ESTA O OUTRO ATOR A SER DEVORADO
	/*
	 * - - C - L - - P - O METODO DEVE DIZER AO LEAO QUE EM SUA DIAGONAL SUPERIOR
	 * DIREITA TEM UM CACHORRO ... ... ABAIXO DE SI HÁ UMA PLANTA E EM TODOS OS
	 * OUTROS LUGARES NAO HÁ NADA O METODO RECEBE UMA POSICAO DO CAMPO DE VISAO DO
	 * PROPRIO ATOR E RETORNAR UMA POSICAO EXEMPLO : PARA A POSICAO [2, 1] O METODO
	 * RETORNA O INTEIRO 4
	 */
	private int direcaoParaDevorar(int i, int j) {
		if (i == 0 && j == 0)
			return 12;
		else if (i == 0 && j == 1)
			return 14;
		else if (i == 0 && j == 2)
			return 11;
		else if (i == 1 && j == 0)
			return 16;
		else if (i == 1 && j == 2)
			return 15;
		else if (i == 2 && j == 0)
			return 10;
		else if (i == 2 && j == 1)
			return 13;
		else
			return 9;
	}

	// ANALOGO AO METODO direcaoParaDevorar(int i, int j), O METODO DIRECAO PARA
	// ANDAR DIZ AO ATOR PARA ONDE ANDAR
	private int direcaoParaAndar(int i, int j) {
		if (i == 0 && j == 0)
			return 8;
		else if (i == 0 && j == 1)
			return 3;
		else if (i == 0 && j == 2)
			return 7;
		else if (i == 1 && j == 0)
			return 2;
		else if (i == 1 && j == 2)
			return 1;
		else if (i == 2 && j == 0)
			return 6;
		else if (i == 2 && j == 1)
			return 4;
		else
			return 5;
	}
	
	/*
	 * METODO QUE TOMA AS DECISOES ANALISANDO O CAMPO DE VISAO 0 : NAO FAZER NADA 1
	 * : ANDAR PARA FRENTE 2 : ANDAR PARA TRAS 3 : ANDAR PARA CIMA 4 : ANDAR PARA
	 * BAIXO 5 : ANDAR PARA DIAGONAL INFERIOR DIREITA 6 : ANDAR PARA DIAGONAL
	 * INFERIOR ESQUERDA 7 : ANDAR PARA DIAGONAL SUPERIOR DIREITA 8 : ANDAR PARA
	 * DIAGONAL SUPERIOR ESQUERDA 9 : COMER NA DIAGONAL INFERIOR DIREITA 10 : COMER
	 * NA DIAGONAL INFERIOR ESQUERDA 11 : COMER NA DIAGONAL SUPERIOR DIREITA 12 :
	 * COMER NA DIAGONAL SUPERIOR ESQUERDA 13 : COMER PARA BAIXO 14 : COMER PARA
	 * CIMA 15 : COMER PARA DIREITA 16 : COMER PARA A ESQUERDA
	 */
	public int decisao() {
		// PLANTA NAO FAZ NADA
		// ATOR MORTO TAMBEM NAO FAZ NADA
		if (this.nome == 'P' || this.nome == '-')
			return 0;
		
		int i,j; // AUXILIARES PARA PERCORRER CAMPO DE VISAO
		
		for(i=0; i<=2; i++) {
			for(j=0; j<=2; j++) {
				// MAPA ACABOU : NADA PARA FAZER NESTA POSICAO ...
				// ... A POSICAO [1, 1] É A DO PROPRIO ATOR
				if (this.visao[i][j] == '*' || (i == 1 && j == 1))
					continue;
				if (predador(this.visao[i][j])) {
					// ENCONTROU PREDADOR, ATOR DEVE CORRER PARA DIRECAO OPOSTA
					if(i==0 && j==0) {
						if(this.visao[2][1] == '-')
							return(direcaoParaAndar(2, 1));
					} else if(i==2 && j==0) {
						if(this.visao[0][1] == '-')
							return(direcaoParaAndar(0, 1));
					} else if(i==0 && j==2) {
						if(this.visao[2][1] == '-')
							return(direcaoParaAndar(2, 1));
					} else if(i==2 && j==2) {
						if(this.visao[0][1] == '-')
							return(direcaoParaAndar(0, 1));
					}else if(j<1) { // PREDADOR A ESQUERDA
						for(int k=0; k<=2; k++)
							if(this.visao[k][2] == '-')
								return(direcaoParaAndar(k, 2));
					} else if(j > 1) { // PREDADOR A DIREITA
						for(int k=0; k<=2; k++)
							if(this.visao[k][0] == '-')
								return(direcaoParaAndar(k, 0));
					} else if(i>1) { // PREDADOR EM BAIXO
						for(int k=0; k<=2; k++)
							if(this.visao[0][k] == '-')
								return(direcaoParaAndar(0, k));
					} else if(i < 1) { // PREDADOR EM CIMA
						for(int k=0; k<=2; k++)
							if(this.visao[2][k] == '-')
								return(direcaoParaAndar(2, k));
					} 
				}
			}
		}
		
		for(i=0; i<=2; i++)
			for(j=0; j<=2; j++)
				if(presa(this.visao[i][j]))
					return(direcaoParaDevorar(i, j));
		
		for(i=0; i<=2; i++) {
			for(j=0; j<=2; j++) {
				if(i==1 && j==1)
					continue;
				if(this.visao[i][j] == this.nome && this.reproduziu == false)
					return(17);
			}
		}		
		
		int k, h;

		Random rand = new Random();
		while (true) {
			do {
				k = rand.nextInt(3);
				h = rand.nextInt(3);
			} while ((this.visao[k][h] == '*' || (k == 1 && h == 1)));
			if (this.visao[k][h] == '-') {
				int c = direcaoParaAndar(k, h);
				return c;
			}
		}
	}
}