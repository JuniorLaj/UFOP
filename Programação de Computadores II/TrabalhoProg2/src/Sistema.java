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
public class Sistema {

	public Sistema() {
	}

	public void andarParaFrente(Ambiente a, Ator ator) {
		a.setNome(ator.getX(), ator.getY() + 1, ator.getNome());
		a.setNome(ator.getX(), ator.getY(), '-');
		ator.setLocalizacao(ator.getX(), ator.getY() + 1);
		ator.setEnergia(ator.getEnergia() - 10);
		if (ator.getEnergia() <= 0) {
			a.setNome(ator.getX(), ator.getY(), '-');
			ator.setNome('-');
		}
	}

	public void andarParaTras(Ambiente a, Ator ator) {
		a.setNome(ator.getX(), ator.getY() - 1, ator.getNome());
		a.setNome(ator.getX(), ator.getY(), '-');
		ator.setLocalizacao(ator.getX(), ator.getY() - 1);
		ator.setEnergia(ator.getEnergia() - 10);

		if (ator.getEnergia() <= 0) {
			a.setNome(ator.getX(), ator.getY(), '-');
			ator.setNome('-');
		}
	}

	public void andarPraCima(Ambiente a, Ator ator) {
		a.setNome(ator.getX() - 1, ator.getY(), ator.getNome());
		a.setNome(ator.getX(), ator.getY(), '-');
		ator.setLocalizacao(ator.getX() - 1, ator.getY());
		ator.setEnergia(ator.getEnergia() - 10);

		if (ator.getEnergia() <= 0) {
			a.setNome(ator.getX(), ator.getY(), '-');
			ator.setNome('-');
		}
	}

	public void andarPraBaixo(Ambiente a, Ator ator) {
		a.setNome(ator.getX() + 1, ator.getY(), ator.getNome());
		a.setNome(ator.getX(), ator.getY(), '-');
		ator.setLocalizacao(ator.getX() + 1, ator.getY());
		ator.setEnergia(ator.getEnergia() - 10);

		if (ator.getEnergia() <= 0) {
			a.setNome(ator.getX(), ator.getY(), '-');
			ator.setNome('-');
		}
	}

	public void andarDiagonalSupDireita(Ambiente a, Ator ator) {
		a.setNome(ator.getX() - 1, ator.getY() + 1, ator.getNome());
		a.setNome(ator.getX(), ator.getY(), '-');
		ator.setLocalizacao(ator.getX() - 1, ator.getY() + 1);
		ator.setEnergia(ator.getEnergia() - 10);

		if (ator.getEnergia() <= 0) {
			a.setNome(ator.getX(), ator.getY(), '-');
			ator.setNome('-');
		}
	}

	public void andarDiagonalSupEsquerda(Ambiente a, Ator ator) {
		a.setNome(ator.getX() - 1, ator.getY() - 1, ator.getNome());
		a.setNome(ator.getX(), ator.getY(), '-');
		ator.setLocalizacao(ator.getX() - 1, ator.getY() - 1);
		ator.setEnergia(ator.getEnergia() - 10);

		if (ator.getEnergia() <= 0) {
			a.setNome(ator.getX(), ator.getY(), '-');
			ator.setNome('-');
		}
	}

	public void andarDiagonalInfEsquerda(Ambiente a, Ator ator) {
		a.setNome(ator.getX() + 1, ator.getY() - 1, ator.getNome());
		a.setNome(ator.getX(), ator.getY(), '-');
		ator.setLocalizacao(ator.getX() + 1, ator.getY() - 1);
		ator.setEnergia(ator.getEnergia() - 10);
		if (ator.getEnergia() <= 0) {
			a.setNome(ator.getX(), ator.getY(), '-');
			ator.setNome('-');
		}
	}

	public void andarDiagonalInfDireita(Ambiente a, Ator ator) {
		a.setNome(ator.getX() + 1, ator.getY() + 1, ator.getNome());
		a.setNome(ator.getX(), ator.getY(), '-');
		ator.setLocalizacao(ator.getX() + 1, ator.getY() + 1);
		ator.setEnergia(ator.getEnergia() - 10);
		if (ator.getEnergia() <= 0) {
			a.setNome(ator.getX(), ator.getY(), '-');
			ator.setNome('-');
		}
	}

	public void comerPCima(Ambiente a, Ator ator) {
		a.setNome(ator.getX() - 1, ator.getY(), '-');
		if (ator.getEnergia() < 1000) {
			ator.setEnergia(ator.getEnergia() + 10);
		}
		if (ator.getEnergia() > 1000) {
			ator.setEnergia(1000);
		}
	}

	public void comerPBaixo(Ambiente a, Ator ator) {
		a.setNome(ator.getX() + 1, ator.getY(), '-');
		if (ator.getEnergia() < 1000) {
			ator.setEnergia(ator.getEnergia() + 10);
		}
		if (ator.getEnergia() > 1000) {
			ator.setEnergia(1000);
		}
	}

	public void comerPEsquerda(Ambiente a, Ator ator) {
		a.setNome(ator.getX(), ator.getY() - 1, '-');
		ator.setEnergia(ator.getEnergia() + 10);
		if (ator.getEnergia() > 1000) {
			ator.setEnergia(1000);
		}

	}

	public void comerPDireita(Ambiente a, Ator ator) {
		a.setNome(ator.getX(), ator.getY() + 1, '-');
		ator.setEnergia(ator.getEnergia() + 10);
		if (ator.getEnergia() > 1000) {
			ator.setEnergia(1000);
		}
	}

	public void comerDiagonalSupDireita(Ambiente a, Ator ator) {
		a.setNome(ator.getX() - 1, ator.getY() + 1, '-');
		ator.setEnergia(ator.getEnergia() + 10);
		if (ator.getEnergia() > 1000) {
			ator.setEnergia(1000);
		}
	}

	public void comerDiagonalSupEsquerda(Ambiente a, Ator ator) {
		a.setNome(ator.getX() - 1, ator.getY() - 1, '-');
		ator.setEnergia(ator.getEnergia() + 10);
		if (ator.getEnergia() > 1000) {
			ator.setEnergia(1000);
		}
	}

	public void comerDiagonalInfEsquerda(Ambiente a, Ator ator) {
		a.setNome(ator.getX() + 1, ator.getY() - 1, '-');
		ator.setEnergia(ator.getEnergia() + 10);
		if (ator.getEnergia() > 1000) {
			ator.setEnergia(1000);
		}
	}

	public void comerDiagonalInfDireita(Ambiente a, Ator ator) {
		a.setNome(ator.getX() + 1, ator.getY() + 1, '-');
		ator.setEnergia(ator.getEnergia() + 10);
		if (ator.getEnergia() > 1000) {
			ator.setEnergia(1000);
		}
	}
	
	public void reproducao(ArrayList<Ator> atores, Ambiente a, Ator ator) {
		
		ator.setReproduziu(true);
		
		Random rand = new Random();
		int aleatorio = rand.nextInt(1);
		char sexo;
		
		if(aleatorio == 1)
			sexo = 'F';
		else
			sexo = 'M';
		
		Ator novo = new Ator(ator.getNome(), sexo, 1000,true);
		
		for (int i = ator.getX() - 1; i <= ator.getX() + 1; i++) {
			for (int j = ator.getY() - 1; j <= ator.getY() + 1; j++) {
				if (a.dentroDosLimites(i, j))
					if(a.getNome(i, j) == '-') {
						a.setNome(i, j, ator.getNome());
						novo.setX(i);
						novo.setY(j);
						atores.add(novo);
						return;
					}				
			}
		}	
		
	}
	
}
