#include <iostream>
#include <ctime>

using namespace std;

int Spielen(int Level);
int TesteHighscore(int Punkte, int Highscore);
int Waehlevel(int Level);
void ZeigInfos();

int main(){
    char Auswahl;
    int Level = 1;
    int Highscore = 0;
    do{
        cout << "Zahlenraten - Menue" << endl;
        cout << "-------------------" << endl;
        cout << "(N)eues Spiele starten" << endl;
        cout << "(L)evel waehlen" << endl;
        cout << "(H)ighscore anzeigen" << endl;
        cout << "(I)nfo" << endl;
        cout << "(B)eenden\n\n";

        cout << "Auswahl: " << endl;
        cin >> Auswahl;
        switch(Auswahl){
            case 'n':
            case 'N':
                cout << "Neue Spiele starten..." << endl;
                int Punkte;
                Punkte = Spielen(Level);
                Highscore = TesteHighscore(Punkte, Highscore);
                break;
            case 'l':
            case 'L':
                Level = Waehlevel(Level);
                break;
            case 'h':
            case 'H':
                cout << "Highscore: " << Highscore << endl << endl;
                break;
            case 'i':
            case 'I':
                ZeigInfos();
                break;
            case 'b':
            case 'B':
                cout << "Spiel beendet." << endl;
                break;
        }
    } while (Auswahl != 'b' && Auswahl != 'B');
    return 0;
}

int Spielen(int Level){
    int Zufallszahl;
    int Geratenezahl;
    int Bereich;
    int Versuche = 0;
    int Punkte;
    srand(time(NULL));

    Bereich = Level * 10;
    Zufallszahl = (rand() % Bereich) + 1;

    do{
        Versuche++;

        cout << "Dein Tip: ";
        cin >> Geratenezahl;
        while(1){
            if(cin.fail()){
                cin.clear();
                cin.ignore();
                cout<< "Ungueltiger Wert" << endl;
                cout << "Dein Tip: ";
                cin >> Geratenezahl;
            }
            if(!cin.fail())
            break;
        }

        if(Geratenezahl < Zufallszahl){
            cout << "Die gesuchte Zahl ist groesser" << endl;
        }
        else if(Geratenezahl > Zufallszahl){
            cout << "Die gesuchte Zahl ist kleiner" << endl;
        }
        else{
            cout << "\nGeschafft!!! " << endl;
            cout << "Du hast die Zahl nach " << Versuche;
            cout << " Versuchen erraten!" << endl;
            Punkte = Bereich - Versuche + 1;
            Punkte *= Level;
            if(Punkte < 0 )
                Punkte = 0;
            cout << "Punkte: " << Punkte << "\n\n\n";
        }

    } while (Zufallszahl != Geratenezahl);
    return Punkte;
}

int TesteHighscore(int Punkte, int Highscore) {
    if(Punkte > Highscore){
        cout << "Glueckwuncsh. Neuer Highscore ! \n\n";
        Highscore = Punkte;
    }
    else{
        cout << "Leider kein neuer Highscore\n\n";
    }
    return Highscore;
}

int Waehlevel(int Level){
    int NeuerLevel;

    do {
        cout << "Aktueller Level: " << Level << endl;
        cout << "Neuer Level (1-10): ";
        cin >> NeuerLevel;

        if(NeuerLevel < 1 || NeuerLevel > 10) {
            cout << "Ungueltiger Level-Wert" << endl;
        }
    } while(NeuerLevel < 1 || NeuerLevel > 10);
}

void ZeigInfos(){
    cout << "Zahlenraten V1.0" << endl;
    cout << "Beispiel aus \"C++ fuer Spieleprogrammierer\"";
    cout << "\n\n";
}