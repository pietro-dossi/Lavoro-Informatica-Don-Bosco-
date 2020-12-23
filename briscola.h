//file classe briscola
#include <iostream>
#include <cstdlib>
#include <cstring>

struct recCarta{
	int numero_carta;
	string tipo;
	bool presente;
};

class Briscola{
	private:
		recCarta mazzo[40];
		recCarta mazzo_giocatore[3];
		recCarta mazzo_computer[3];
		int punteggio_giocatore;
		int punteggio_computer;
		string tipo_dominante;
	
	public:
		Briscola(void);//
		void setMazzo(void);//
		void setMazzoGiocatore(void);//
		void setMazzoComputer(void);//
		void setPunteggioGiocatore(int n);//
		void setPunteggioComputer(int n);//
		void setDominante(void);//
		int getPunteggioGiocatore(void);//
		int getPunteggioComputer(void);//
		void stampaDominante(void);//
		void stampaMazzoGiocatore(void);// 
		void stampaMazzoComputer(void);// da fare in seguito.
		void lancioCartaComputer(void);//
		void lancioCartaGiocatore(int n);//
		void pescaCarta(void);
		//calcolo puteggio (confronto tra carte lanciate e tipo dominante; scelta punteggio e chiamata setPunteggio)
		
		
		
		
};
