//file di sviluppo delle funzioni della classe
#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include "bricola.h"
#define MAX_RAND 40

Briscola::Briscola(void){
	punteggio_giocatore = 0;
	punteggio_computer = 0;
	for(int i=0; i < 3; i++){
		mazzo_giocatore[i].numero = 0
		mazzo_giocatore[i].tipo = "nullo";
		mazzo_giocatore[i].presente = false;
		mazzo_computer[i].numero = 0
		mazzo_computer[i].tipo = "nullo";
		mazzo_computer[i].presente = false;
	}
	for(int i=0; i < 40; i++){
		mazzo[i].numero = 0;
		mazzo[i].tipo = "nullo";
		mazzo[i].presente = false;
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
		}
		j = 0;
		if(i >= 10 && i < 20){
			mazzo[i].numero = j+1;
			mazzo[i].tipo = "spade";
			mazzo[i].presente = true;
			j++;
		}
		j = 0;
		if(i >= 20 && i < 30){
			mazzo[i].numero = j+1;
			mazzo[i].tipo = "bastoni";
			mazzo[i].presente = true;
			j++;
		}
		j = 0;
		if(i >= 30){
			mazzo[i].numero = j+1;
			mazzo[i].tipo = "denari";
			mazzo[i].presente = true;
			j++;
		}
	}
}

void Briscola::setMazzoGiocatore(void){
	int n_casuale=0;
	srand(time(NULL));
	for(int i=0; i < 3; i++){
		n_casuale = rand()%MAX_RAND + 1;
		if (mazzo[n_casuale].presente == false){
			i--;
			continue;
		}
		else{
			mazzoGiocatore[i] = mazzo[n_casuale];
			mazzo[n_casuale].presente = false;
		}
	}
	
}

void Briscola::setMazzoComputer(void){
	int n_casuale=0;
	srand(time(NULL));
	for(int i=0; i < 3; i++){
		n_casuale = rand()%MAX_RAND + 1;
		if (mazzo[n_casuale].presente == false){
			i--;
			continue;
		}
		else{
			mazzoComputer[i] = mazzo[n_casuale];
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
	n_casuale = rand()%3+1;
	cout<<"Il tuo avversario ha tirato il "<<mazzo_computer[n_casuale].numero<<" "<<mazzo_computer[n_casuale].tipo<<"."<<endl; 
	mazzo_computer[n_casuale].presente = false;
}

void Briscola::lancioCartaGiocatore(int n){
	cout<<"Hai tirato il "<<mazzo_giocatore[n].numero<<" "<<mazzo_giocatore[n].tipo<<"."<<endl;
	mazzo_giocatore[n].presente = false;
}

void Briscola::pescaCarta(void){
	int n_casuale=0;
	srand(time(NULL));
}

