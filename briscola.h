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
		Briscola(void);
		void setMazzo(void);
		void setMazzoGiocatore(void);
		void setMazzoComputer(void);
		void setPunteggioGiocatore(int n);
		void setPunteggioComputer(int n);
		int getPunteggioGiocatore(void);
		int getPunteggioComputer(void);
		void stampaDominante(void);
		void stampaMazzoGiocatore(void);
		void stampaMazzoComputer(void);
		
		
		
};
