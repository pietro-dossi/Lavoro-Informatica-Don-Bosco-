//main
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "briscola.h"
using namespace std;

int main(void){
	Briscola b;
	int mossa, priorita=0, conta_carte=0; //l'utente scrive 1 2 3     
	//QUANDO PRIORITA = 0 LA HA IL COMPUTER ALTRIMENTI SE = 1 LA PRIORITA LA HA IL GIOCATORE
	////////////////////////////////////////////
	srand(time(NULL));
	b.setDominante();
	b.setMazzo();
	b.setMazzoComputer();
	b.setMazzoGiocatore();
	conta_carte += 6;
	do{
		b.stampaDominante();
		cout<<endl;
		b.stampaMazzoGiocatore();
		cout<<endl;
		if(priorita == 0){
			b.lancioCartaComputer();
			cout<<endl<<"Fai la tua mossa. Scegli la carta da lanciare. Digita [1, 2, o 3]."<<endl;
			cin>>mossa;
			b.lancioCartaGiocatore(mossa);
			b.calcoloPunteggio(priorita);
			if(conta_carte < 34){
				b.pescaCarta();
			}
			conta_carte += 2;
			cout<<"///////////////////////////////////////////////////////////////////////////////////////////////\n\n\n\n\n"<<endl;
		}
		else{
			cout<<"Fai la tua mossa. Scegli la carta da lanciare. Digita [1, 2, o 3]."<<endl;
			cin>>mossa;
			b.lancioCartaGiocatore(mossa);
			b.lancioCartaComputer();
			b.calcoloPunteggio(priorita);
			if(conta_carte < 34){
				b.pescaCarta();
			}
			conta_carte += 2;
			cout<<"///////////////////////////////////////////////////////////////////////////////////////////////\n\n\n\n\n\n\n\n"<<endl;
		}
	}while(conta_carte < 40);
	if(b.getPunteggioComputer() > b.getPunteggioGiocatore()){
		cout<<"Punteggio avversario: "<<b.getPunteggioComputer()<<endl<<"Punteggio personale: "<<b.getPunteggioGiocatore()<<endl;
		cout<<"Il vincitore della partita e' il tuo avversario."<<endl;
	}
	else{
		cout<<"Punteggio avversario: "<<b.getPunteggioComputer()<<endl<<"Punteggio personale: "<<b.getPunteggioGiocatore()<<endl;
		cout<<"Il vincitore della partita sei tu."<<endl;
	}
	cout<<"Prova conta carte"<<conta_carte;
	cout<<endl;
	system("PAUSE");
	
}
