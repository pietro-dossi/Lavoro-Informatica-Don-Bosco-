//file classe briscola
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct recCarta{
	int numero;
	string tipo;
	bool presente; //variabile per la gestione delle carte (se true la carta non è mai stata pescata, se false la carta è gia stata pescata)
	int punteggio;
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
		void stampaMazzoComputer(void);// 
		void lancioCartaComputer(void);//
		void lancioCartaGiocatore(int n);//
		void pescaCarta(void);//
		void calcoloPunteggio(int &p);//
		
		
		
		
};
