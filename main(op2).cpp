//Zixuan FENG & Adebayo NALLA
//Groupe 1D
#include <iostream>
#include <string> //pour pouvoir utiliser getline
#include <cstdio> //pour pouvoir utiliser sprintf

using namespace std;

const int MAXT=1000;//(une constante) la taille du tableau

int main()
{
    //d�finir des variables
    // valj=valeur du joueur , valo=valeur de l'ordinateur
    int vie,valj,valo,nbmin,commence,recommence;
    //valjs=valeur du joueur au genre de string , valjse=le string pour examiner si 'valjs' est correct
    //FB est la variable pour ��changer Fizz et Buzz
    string nom,valjs,valjse,valos,Fizz,Buzz,FB;
    //les bool��ens pour v��rifier si le valeur est le multiple de 3 ou 5
    bool mult3,mult5;
    //pour la conversion entre int et string
    char tabj[MAXT],tabo[MAXT];
    Fizz="Fizz";
    Buzz="Buzz";

    //la boucle pour recommencer le jeu
    do
    {
		vie=3;

		//saisir le nom du joueur
		cout << "Donnez-moi votre nom de famille , SVP." << endl;
		cin.sync();
		getline(cin,nom);
		//saisir l'intervalle
		cout <<nom<<" , choississez le nombre minimale s'il vous plait."<<endl;
		cout <<"( La valeur doit etre strictement positive. )"<<endl;
		cin >> nbmin ;

		//examiner si la valeur respecte les contraintes , sinon redemander le nombre
		while ( nbmin<=0 )
		{
			cout <<"Le nombre que vous avez donne ne respecte pas les regles."<<endl;
			cout <<"Veuillez me redonner d'autre nombre SVP."<<endl;
			cout <<"( La valeur doit etre strictement positive. )"<<endl;
			cin >> nbmin;
		}

		//demander qui commence le jeu
		cout <<"Bienvenue dans notre simulation du FizzBuzz, voulez-vous commencer?"<<endl;
		cout <<"Appuyez sur 1 pour debuter, 0 pour que l'ordinateur debute."<<endl;
		cin >>commence;
		//v�rifier si la valeur saisie est correcte ( 0 ou 1 ) sinon redemander le nombre
		while ( commence != 0 && commence != 1 )
		{
			cout <<"Le nombre que vous avez importe ne fonctionne pas."<<endl;
			cout <<"Tapez '0' pour que l'ordinateur demarre et tapez '1' pour demarrez."<<endl;
			cin >> commence;
		}

		//le d�but du jeu , recommander les r�gles du jeu
		cout <<"Preparez-vous,le jeu va bientot commencer."<<endl;
		cout <<"Comptez de 1 en 1 egal ou superieur � "<<nbmin<<" ."<<endl;
		cout <<"Dites Fizz lorsqu'il y a un multiple de 3, Buzz lorsqu'il y a une multiple de 5 et FizzBuzz lorsque le nombre est un multiple de 3 et 5."<<endl;
		cout <<"Tapez STOP quand vous voulez arreter le jeu ."<<endl;
		cout <<"Attention : chaque fois que l'on voit 'FizzBuzz' ou 'BuzzFizz' , on �change la conditon de Fizz et de Buzz ."<<endl;
		cout <<"Bonne chance !"<<endl;

		//V�rifier qui va commencer le jeu
		// 1� cas --- l'ordinateur commence le jeu
		if ( commence==0 )
		{
			//saisir l'initialisation
			valo=nbmin;
			//conversion de int vers string
			sprintf( tabo,"%d",valo );
			valos=tabo;
			//v�rifier si 'valo' est le multiple de 3 ou 5
			mult3 = (valo%3==0) ;
			mult5 = (valo%5==0) ;
			//si 'valo' est le multiple de 3 ou 5 , on change 'valos'(le message affich�) � Fizz/Buzz/FizzBuzz
			//utilisant la concat�nation pour g�n�rer le mot FizzBuzz
			if ( mult3 )
			{
				valos=Fizz;
			}
			if ( mult5 )
			{
				if ( mult3 )
				{
					valos=Fizz;
				}
				else
				{
					valos.clear();
			    }
			    valos=valos+Buzz;
			}
			//afficher le message (un nombre/Fizz/Buzz/FizzBuzz)
			cout <<"Ordinateur > "<<valos<<endl;
			valj=valo+1;
			if ( valos==Fizz+Buzz )
            {
                FB=Fizz;
                Fizz=Buzz;
                Buzz=FB;
            }
		}

		// 2� cas --- le joueur commence le jeu
		//saisir l'initialisation
		else
		{
			valj=nbmin;
		}

		//la boucle pour jouer le jeu
		do
		{
			//conversion de int vers string
			sprintf( tabj,"%d",valj );
			valjse=tabj;
			//v�rifier si 'valj' est le multiple de 3 ou 5
			mult3 = (valj%3==0) ;
			mult5 = (valj%5==0) ;
			//si 'valj' est le multiple de 3 ou 5 , on change 'valjse'(le message affich�) � Fizz/Buzz/FizzBuzz
			//utilisant la concat�nation pour g��n��rer le mot FizzBuzz
			if ( mult3 )
			{
				valjse=Fizz;
			}
			if ( mult5 )
			{
				if ( mult3 )
				{
					valjse=Fizz;
				}
				else
				{
					valjse.clear();
				}
				valjse=valjse+Buzz;
			}
			//demander et saisir la r�ponse du joueur
			cout <<nom<<"("<<vie<<" vies)"<<" > ";
			cin >>valjs;

			//v�rifier si le joueur veux arr�ter le jeu
			if ( valjs=="STOP" )
            {
                break;
            }

			//v�rifier si la r�ponse est correcte
			while ( valjs!=valjse )
			{
				//si la r�ponse est incorrecte , le joueur perd un point de vie
				vie=vie-1;
				cout <<"Vous vous etes tromper,vous perdez un point de vie"<<endl;
				cout <<"La bonne valeur est "<<valjse<<" ."<<endl;
				//v�rifier si le joueur a encore de la vie pour continuer le jeu
				if ( vie==0 )
				{
					cout <<"Vous avez perdu !"<<endl;
					break;
				}
				//redemander la r�ponse du joueur
				cout <<nom<<"("<<vie<<" vies)"<<" > ";
				cin >>valjs;
				if ( valjs=="STOP" )
                {
                    break;
                }
			}

			//v�rifier si le joueur a encore de la vie pour continuer le jeu ou si le joueur veux arr�ter le jeu
			if ( vie==0 || valjs=="STOP" )
			{
				break;
			}

			//�changer Fizz et Buzz
			if ( valjs==Fizz+Buzz )
            {
                FB=Fizz;
                Fizz=Buzz;
                Buzz=FB;
            }

			//donner la nouvelle valuation � 'valo'
			valo=valj+1;

			//conversion de int vers string
			sprintf( tabo,"%d",valo );
			valos=tabo;
			//v�rifier si 'valo' est le multiple de 3 ou 5
			mult3 = (valo%3==0) ;
			mult5 = (valo%5==0) ;
			//si 'valo' est le multiple de 3 ou 5 , on change 'valos'(le message affich�) � Fizz/Buzz/FizzBuzz
			//utilisant la concat��nation pour g�n�rer le mot FizzBuzz
			if ( mult3 )
			{
				valos=Fizz;
			}
			if ( mult5 )
			{
				if ( mult3 )
				{
					valos=Fizz;
				}
				else
				{
					valos.clear();
				}
				valos=valos+Buzz;
			}

			//�changer Fizz et Buzz
			if ( valos==Fizz+Buzz )
            {
                FB=Fizz;
                Fizz=Buzz;
                Buzz=FB;
            }
			//afficher le message (un nombre/Fizz/Buzz/FizzBuzz)
			cout <<"Ordinateur > "<<valos<<endl;
			//donner la nouvelle valuation � 'vqlj'
			valj=valo+1;
		}
		while( vie!=0 );

		//proposer au joueur de recommencer ou de quitter
		cout <<"Vous voulez recommencer une partie ou quitter le jeu?"<<endl;
		cout <<"Tapez '0' pour recommencer et tapez '1' pour quitter."<<endl;
		cin >>recommence;
    }
    while ( recommence==0 );

    return 0;
}
