
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.io.IOException;
import java.util.ArrayList;
import java.util.Random;

/**
 *
 * @author Junior
 */
public class Teste {
	public static void main(String[] args) throws IOException {

		int decisao = 0; // VARIAVEL QUE ARMAZENA A DECISAO DE ACAO DE CADA ATOR
		int interacoes = 0;
		
		Sistema s = new Sistema();
		Random rand = new Random();
		Ambiente a = new Ambiente();

		Ator leao = new Ator('L', 'M', 1000);
		Ator leoa = new Ator('L', 'F', 1000, true);
		Ator cachorro = new Ator('C', 'M', 1000);
		Ator cadela = new Ator('C', 'F', 1000, true);
		Ator macaco = new Ator('M', 1000);
		Ator macaca = new Ator('M','F', 1000, true);
		Ator galinha = new Ator('G', 'F', 1000, true);
		Ator galo = new Ator('G', 'M', 1000);
		Ator planta = new Ator('P', 100);
		
		ArrayList<Ator> atores = new ArrayList<Ator>();

		atores.add(leao);
		atores.add(leoa);
		atores.add(cachorro);
		atores.add(cadela);
		atores.add(macaco);
		atores.add(macaca);
		atores.add(galinha);
		atores.add(galo);
		
		for (int i = 0; i < 40; i++) 
			atores.add(planta);
		
		a.addAvulso(atores);

		a.imprimirMatriz();
		System.out.println("\n\n");

		ArrayList<Ator> atores22 = new ArrayList<Ator>();
		atores22.add(leao);
		atores22.add(leoa);
		atores22.add(cachorro);
		atores22.add(cadela);
		atores22.add(macaco);
		atores22.add(macaca);
		atores22.add(galinha);
		atores22.add(galo);
		atores22.add(macaca);
		
		while (true) {
			if(atores22.size() == 0)
				break;
			
			for (int i = 0; i < atores22.size(); i++) {
								
				// QUANDO ATOR � DEVORADO, O NOME DELE � ALTERADO NO AMBIENTE, TEMOS QUE ALTERAR O NOME DO OBJETO TAMB�M
				if(a.getNome(atores22.get(i).getX(), atores22.get(i).getY()) == '-') {
					atores22.get(i).setNome('-');
				}
				// QUANDO O ATOR MORRE POR FALTA DE ENERGIA, O NOME DELE � COLOCADO COMO TRA�O, ENT�O TEMOS QUE REMOV�-LO DA LISTA
				if (atores22.get(i).getNome() == '-') {
					atores22.remove(i);
					break;
				}
				
				System.out.println("\n" + interacoes + " Pressione ENTER para continuar ...\n");
				System.in.read();
				
				atores22.get(i).campoVisao(a);
				// atores22.get(i).imprimeCampoVisao();

				decisao = atores22.get(i).decisao();

				if (decisao == 1) {
					s.andarParaFrente(a, atores22.get(i));
				} else if (decisao == 2) {
					s.andarParaTras(a, atores22.get(i));
				} else if (decisao == 3) {
					s.andarPraCima(a, atores22.get(i));
				} else if (decisao == 4) {
					s.andarPraBaixo(a, atores22.get(i));
				} else if (decisao == 5) {
					s.andarDiagonalInfDireita(a, atores22.get(i));
				} else if (decisao == 6) {
					s.andarDiagonalInfEsquerda(a, atores22.get(i));
				} else if (decisao == 7) {
					s.andarDiagonalSupDireita(a, atores22.get(i));
				} else if (decisao == 8) {
					s.andarDiagonalSupEsquerda(a, atores22.get(i));
				} else if (decisao == 9) {
					s.comerDiagonalInfDireita(a, atores22.get(i));
				} else if (decisao == 10) {
					s.comerDiagonalInfEsquerda(a, atores22.get(i));
				} else if (decisao == 11) {
					s.comerDiagonalSupDireita(a, atores22.get(i));
				} else if (decisao == 12) {
					s.comerDiagonalSupEsquerda(a, atores22.get(i));
				} else if (decisao == 13) {
					s.comerPBaixo(a, atores22.get(i));
				} else if (decisao == 14) {
					s.comerPCima(a, atores22.get(i));
				} else if (decisao == 15) {
					s.comerPDireita(a, atores22.get(i));
				} else if (decisao == 16) {
					s.comerPEsquerda(a, atores22.get(i));
				} else if(decisao == 17) {
					s.reproducao(atores22, a, atores22.get(i));
					 //atores22.add(s.reproducao(a, atores22.get(i)));
					// System.out.println("*****************************************************************");
				}
				a.imprimirMatriz();
				
				interacoes++;
			}
		}

		System.out.println("\n\nAmbiente FINAL!\n\n");

	}
}
