//file di sviluppo delle funzioni della classe
#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include "briscola.h"
#define MAX_RAND 40

Briscola::Briscola(void){
	punteggio_giocatore = 0;
	punteggio_computer = 0;
	for(int i=0; i < 3; i++){
		mazzo_giocatore[i].numero = 0;
		mazzo_giocatore[i].tipo = "nullo";
		mazzo_giocatore[i].presente = false;
		mazzo_computer[i].numero = 0;
		mazzo_computer[i].tipo = "nullo";
		mazzo_computer[i].presente = false;
	}
	for(int i=0; i < 40; i++){
		mazzo[i].numero = 0;
		mazzo[i].tipo = "nullo";
		mazzo[i].presente = false;
		mazzo[i].punteggio = 0;
	}
	tipo_dominante = "nullo";
}

void Briscola::setMazzo(void){
	int i=0, j=0;
	for(i=0; i < 40; i++){
		if(i < 10){
			mazzo[i].numero = j+1;
			mazzo[i].tipo = "coppe";
			mazzo[i].presente = true;
			j++;
			if(j == 10){
				j=0;
			}
		}
		//j = 0;
		if(i >= 10 && i < 20){
			mazzo[i].numero = j+1;
			mazzo[i].tipo = "spade";
			mazzo[i].presente = true;
			j++;
			if(j == 10){
				j=0;
			}
		}
		//j = 0;
		if(i >= 20 && i < 30){
			mazzo[i].numero = j+1;
			mazzo[i].tipo = "bastoni";
			mazzo[i].presente = true;
			j++;
			if(j == 10){
				j=0;
			}
		}
		//j = 0;
		if(i >= 30 && i < 40){
			mazzo[i].numero = j+1;
			mazzo[i].tipo = "denari";
			mazzo[i].presente = true;
			j++;
			if(j == 10){
				j=0;
			}
		}
		switch(mazzo[i].numero){
			case 1:
				mazzo[i].punteggio = 11;
				break;
			case 2:
				mazzo[i].punteggio = 0;
				break;
			case 3:
				mazzo[i].punteggio = 10;
				break;
			case 4:
				mazzo[i].punteggio = 0;
				break;
			case 5:
				mazzo[i].punteggio = 0;
				break;
			case 6:
				mazzo[i].punteggio = 0;
				break;
			case 7:
				mazzo[i].punteggio = 0;
				break;
			case 8:
				mazzo[i].punteggio = 2;
				break;
			case 9:
				mazzo[i].punteggio = 3;
				break;
			case 10:
				mazzo[i].punteggio = 4;
				break;
			default:
				break;
		}
	}
}

void Briscola::setMazzoGiocatore(void){
	int n_casuale=0;
	srand(time(NULL));
	for(int i=0; i < 3; i++){
		n_casuale = rand()%MAX_RAND + 1;
		if (mazzo[n_casuale].presente == false){ //si controlla che nel mazzo non ci sia una carta già usata.
			i--;
			continue;
		}
		else{
			mazzo_giocatore[i] = mazzo[n_casuale];
			mazzo[n_casuale].presente = false;
		}
	}
	
}

void Briscola::setMazzoComputer(void){
	int n_casuale=0;
	srand(time(NULL));
	for(int i=0; i < 3; i++){
		n_casuale = rand()%MAX_RAND + 1;
		if (mazzo[n_casuale].presente == false){ //si controlla che nel mazzo non ci sia una carta già usata.
			i--;
			continue;
		}
		else{
			mazzo_computer[i] = mazzo[n_casuale];
			mazzo[n_casuale].presente = false;
		}
	}
	
}

void Briscola::setDominante(void){
	int n_casuale = 0;
	srand(time(NULL));
	n_casuale = rand()%4+1;
	switch(n_casuale){
		case 1:
			tipo_dominante = "coppe";
			break;
		case 2:
			tipo_dominante = "spade";
			break;
		case 3: 
			tipo_dominante = "bastoni";
			break;
		case 4:
			tipo_dominante = "denari";
			break;
		default:
			break; 
	}
}

void Briscola::setPunteggioGiocatore(int n){
	punteggio_giocatore += n;
}

void Briscola::setPunteggioComputer(int n){
	punteggio_computer += n;
}

int Briscola::getPunteggioGiocatore(void){
	return punteggio_giocatore;
}

int Briscola::getPunteggioComputer(void){
	return punteggio_computer;
}

void Briscola::stampaDominante(void){
	cout<<"Il tipo dominante. La briscola e': "<<tipo_dominante<<"."<<endl;
}

void Briscola::stampaMazzoGiocatore(void){
	cout<<"Le tue carte "<<endl; //per ora le stampiamo scritte poi se c'è tempo ascii art
	for(int i=0; i < 3; i++){
		cout<<mazzo_giocatore[i].numero<<" "<<mazzo_giocatore[i].tipo<<endl;
	}
}

void Briscola::lancioCartaComputer(void){
	int n_casuale=0;
	srand(time(NULL));
	n_casuale = rand()%2+1;
	cout<<"Il tuo avversario ha tirato il "<<mazzo_computer[n_casuale].numero<<" "<<mazzo_computer[n_casuale].tipo<<"."<<endl; 
	mazzo_computer[n_casuale].presente = false;
}

void Briscola::lancioCartaGiocatore(int n){
	cout<<"Hai tirato il "<<mazzo_giocatore[n-1].numero<<" "<<mazzo_giocatore[n-1].tipo<<"."<<endl;
	mazzo_giocatore[n-1].presente = false;
}

void Briscola::pescaCarta(void){ // funzione errata
	int n_casuale=0, n_casuale2=0;
	srand(time(NULL));
	
	do{
		n_casuale = rand()%MAX_RAND + 1;
	}while(mazzo[n_casuale].presente == false);
	mazzo[n_casuale].presente = false;
	
	do{
		n_casuale2 = rand()%MAX_RAND + 1;
	}while(mazzo[n_casuale2].presente == false);
	mazzo[n_casuale2].presente = false;
	
	//while(mazzo[n_casuale2].presente != false){
		for(int i=0; i < 3; i++){
			if(mazzo_computer[i].presente == false){
				mazzo_computer[i] = mazzo[n_casuale2];
				//mazzo[n_casuale2].presente = false;
			}
		}
	//}
	//while(mazzo[n_casuale].presente != false){
		for(int i=0; i < 3; i++){
			if(mazzo_giocatore[i].presente == false){
				mazzo_giocatore[i] = mazzo[n_casuale];
				//mazzo[n_casuale].presente = false;
			}
		}
	//}
}

void Briscola::calcoloPunteggio(int &p){
	int posizione_computer=0, posizione_giocatore=0, i=0;
	for(i=0; i < 3; i++){
		if(mazzo_giocatore[i].presente == false){
			posizione_giocatore = i;
		}
		if(mazzo_computer[i].presente == false){
			posizione_computer = i;
		}
	}
	/// per il punteggio 
	if(mazzo_giocatore[posizione_giocatore].tipo == tipo_dominante && mazzo_computer[posizione_computer].tipo == tipo_dominante){
		if(mazzo_giocatore[posizione_giocatore].punteggio > mazzo_computer[posizione_computer].punteggio){
			setPunteggioGiocatore(mazzo_giocatore[posizione_giocatore].punteggio + mazzo_computer[posizione_computer].punteggio);
			p = 1;
		}
		else{
			setPunteggioComputer(mazzo_giocatore[posizione_giocatore].punteggio + mazzo_computer[posizione_computer].punteggio);
			p = 0;	
		}
	}
	else{
		if(mazzo_giocatore[posizione_giocatore].tipo == tipo_dominante && mazzo_computer[posizione_computer].tipo != tipo_dominante){
			setPunteggioGiocatore(mazzo_giocatore[posizione_giocatore].punteggio + mazzo_computer[posizione_computer].punteggio);
			p = 1;
		}
		else{
			if(mazzo_giocatore[posizione_giocatore].tipo != tipo_dominante && mazzo_computer[posizione_computer].tipo == tipo_dominante){
				setPunteggioComputer(mazzo_giocatore[posizione_giocatore].punteggio + mazzo_computer[posizione_computer].punteggio);
				p = 0;
			}
			else{
				if(mazzo_giocatore[posizione_giocatore].tipo != tipo_dominante && mazzo_computer[posizione_computer].tipo != tipo_dominante){
					if(p == 0){
						setPunteggioComputer(mazzo_giocatore[posizione_giocatore].punteggio + mazzo_computer[posizione_computer].punteggio);
						p = 0;
					}
					else{
						setPunteggioGiocatore(mazzo_giocatore[posizione_giocatore].punteggio + mazzo_computer[posizione_computer].punteggio);
						p = 1;
					}
				}
			}
			
		}
	}
	///
}
