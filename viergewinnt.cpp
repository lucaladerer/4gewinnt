#include <iostream>
#include <string>
#include <random>

using std::cout;
using std::cin;
using std::endl;
using std::string;


class Menu
{
public:
    Menu()
        : m_spieler1(0)
        , m_spieler2(0)
        , m_symbol1("")
        , m_symbol2("")
        , m_feldformat("")
        , m_feldbreite(0)
        , m_feldhoehe(0)
        {
        };
    
    virtual ~Menu(){};


    void startGame()
    {
        //Introtext
        cout << "Willkommen bei Vier Gewinnt!.\nFolgende Spielmodi stehen zur Auswahl:" << endl;
        cout << "(1) -> Mensch\n(2) -> Vertikaler Bot" << endl;
        cout << "(3) -> Hoizontaler Bot\n(4) -> Zufallsbot\n(5) -> Schlauer Bot\n" << endl;

        //Player1
        cout << "Bitte waehlen Sie nun Spieler 1 und dessen Symbol aus:\nSpielmodus:\t\t";  
        cin >> m_spieler1;
        cout << "Spielstein/Symbol:\t";
        cin >> m_symbol1 ;
        cout << endl;

        //Player2
        cout << "Bitte waehlen Sie nun Spieler 2 und dessen Symbol aus:\nSpielmodus:\t\t";
        cin >> m_spieler2;
        cout << "Spielstein/Symbol:\t";
        cin >> m_symbol2;
        cout << endl;

        cout << "Moechten Sie das Spiel auf der Standard-Feldgroesse (7x6) spielen? Falls ja, druecken Sie 'j', falls nein, druecken Sie 'n':\t";
        cin >> m_feldformat;
        cout << endl;
        if(m_feldformat == "j" || m_feldformat == "J")
        {
        	standard = true;
            cout << "Sie haben sich fuer die Standard-Feldgroesse entschieden!" << endl;
        }
        else if(m_feldformat == "n" || m_feldformat == "N")
        {
            standard = false;
            cout << "Welche Breite soll das Spielfeld besitzen? (Mindestens 4):\t";
            cin >> m_feldbreite;
            cout << endl;
            cout << "Welche Hoehe soll das Spielfeld besitzen? (Mindestens 4):\t";
            cin >> m_feldhoehe;
            cout << endl;
        }
    }

    int getPlayer1() const
    {
        return m_spieler1;
    }

    int getPlayer2() const
    {
        return m_spieler2;
    }

    //get Symbol1 from class Menu -> Gamemode -> vererbung an Feld
    string getSymbol1() const
    {
        return m_symbol1;   //\0F1A, \0F1D
    }

    string getSymbol2() const
    {
        return m_symbol2;
    }

    int getFeldbreite() const
    {
        return m_feldbreite;
    }

    int getFeldhoehe() const
    {
        return m_feldhoehe;
    }

    bool getStandard()
    {
        return standard;
    }

protected:
    int m_spieler1;
    int m_spieler2;
    string m_symbol1;
    string m_symbol2;
    string m_feldformat;
    bool standard;
    int m_feldbreite;
    int m_feldhoehe;
};

/*_____________________________________________________________________________________________________*/


class Feld : public Menu
{
public:
    Feld(Menu menu)     //WICHTIG: Hier wird das Objekt der Klasse Menu an Feld übergeben! Erst dann kann man mit Feld auf Menu zugreifen
    : m_menu(menu)

    {
        createField();  //da das Feld sowieso erstellt werden muss, kann das direkt im Konstruktor erledigt werden
        printField();
    };
    

    int alternatingPlayer()
    {
        m_counter++;
        return m_counter;
    }

    //create a Matrix (here 6x6) out of zeros
    void createField()              //[x][y] -> x = Breite (Anzahl Spalten) | y = Höhe (Anzahl Reihen)
    {
        if(m_menu.getStandard() == true)
        {
            rowsFix = 6;    
            colsFix = 7;
            // array[rowsFix][colsFix];    //Feldgröße soll tatsächliche Größe betragen
        }
        else if (m_menu.getStandard() == false)
        {
            rowsFix = m_menu.getFeldhoehe();
            colsFix = m_menu.getFeldbreite();
            // array[rowsFix][colsFix];    //Feldgröße soll tatsächliche Größe betragen
        }

        for (int rows = 0; rows < rowsFix; rows++)
        {
            for (int cols = 0; cols < colsFix; cols++)
            {
                array[rows][cols] = "\u2395";  //leeres Feld -> (\u25A1, \u2395, \u2588, \u2591/2/3, \25A2)     --> WICHTIG! Auch bei Setsymbol ändern
            }
        }
    }

    //print the field
    void printField()
    {
        for (int i = 0; i < rowsFix; i++)
        {
            for (int j = 0; j < colsFix; j++)
            {
                cout << array[i][j] << "  ";
            }
            cout << endl;
        }
        cout << "\n" << endl;
    }
    

    //set Symbol1 at chosen column
    void setSymbol1()       //-> Eventuell auch direkt nächsten Spieler als Konsequenz spielen lassen
    {           
        m_alteredNumber = alternatingPlayer();
        //if Mensch dann abfragen
        if(m_alteredNumber % 2 == 0)  //Spieler 2
        {
            switch (m_menu.getPlayer2())
            {
                case 1:     //Mensch
                    cout << "Spieler 2, waehlen Sie nun eine Spalte aus:\t";
                    cin >> m_col;   

                    if(m_differPlayer == true)  //boolean für Fallunterscheidung bei Spielstein
                    {
                        m_differPlayer = false;
                    }
                    else
                    {
                        m_differPlayer = true;
                    }
                    break;

                case 2:     //vertikaler Bot
                    m_col = 0;          //links anfangen
                    for(int i = 0; i <=colsFix; i++)      
                    {
                        if(array[0][m_col] == m_menu.getSymbol1() || array[0][m_col] == m_menu.getSymbol2())    
                        {
                            m_col++;
                        }
                        else
                        break;
                    }
                    if(m_differPlayer == true)
                    {
                        m_differPlayer = false;
                    }
                    else
                    {
                        m_differPlayer = true;
                    }
                    break;

                case 3:     //horizontaler Bot
                    m_col = 0;              //Keine Ahnung wie weiter
                    int static counterHoBot1 = 0;
                    for(int c = 0; c <= colsFix; c++)
                    {
                        for(int i = (rowsFix+1); i >= 0; i--)      
                        {
                            if(array[i][m_col] == "\u2395")
                            {
                                counterHoBot1++;
                                break;
                            }
                            else
                            {
                            }
                        }
                        
                    }
                    if(m_differPlayer == true)
                    {
                        m_differPlayer = false;
                    }
                    else
                    {
                        m_differPlayer = true;
                    }
                    break;
                    if(m_differPlayer == true)
                    {
                        m_differPlayer = false;
                    }
                    else
                    {
                        m_differPlayer = true;
                    }
                    break;

                case 4:     //Random Bot
                    std::random_device randomBot;
                    std::mt19937 generator(randomBot());
                    std::uniform_int_distribution<int> distribution(0, colsFix);
                    m_col = distribution(randomBot);
                    if(m_differPlayer == true)
                    {
                        m_differPlayer = false;
                    }
                    else
                    {
                        m_differPlayer = true;
                    }
                    break;

                // case 5:     //Schlauer Bot

                //     if(m_differPlayer == true)
                //     {
                //         m_differPlayer = false;
                //     }
                //     else
                //     {
                //         m_differPlayer = true;
                //     }
                //     break;
            }
        }      
        
        else if(m_alteredNumber % 2 != 0)    //Spieler 1
        {
            switch (m_menu.getPlayer1())
            {
                case 1:     //Mensch
                    cout << "Spieler 1, waehlen Sie nun eine Spalte aus:\t";
                    cin >> m_col;   
                    human = true;
                    if(m_differPlayer == true)  //boolean für Fallunterscheidung bei Spielstein
                    {
                        m_differPlayer = false;
                    }
                    else
                    {
                        m_differPlayer = true;
                    }
                    break;

                case 2:     //vertikaler Bot
                    m_col = 0;          //links anfangen
                    for(int i = 0; i <=colsFix; i++)      
                    {
                        if(array[0][m_col] == m_menu.getSymbol1() || array[0][m_col] == m_menu.getSymbol2())    
                        {
                            m_col++;
                        }
                        else
                        break;
                    }
                    if(m_differPlayer == true)
                    {
                        m_differPlayer = false;
                    }
                    else
                    {
                        m_differPlayer = true;
                    }
                    break;

                case 3:     //horizontaler Bot
                    m_col = 0;              //Keine Ahnung wie weiter
                    int static counterHoBot1 = 0;
                    for(int c = 0; c <= colsFix; c++)
                    {
                        for(int i = (rowsFix+1); i >= 0; i--)      
                        {
                            if(array[i][m_col] == "\u2395")
                            {
                                counterHoBot1++;
                                break;
                            }
                            else
                            {
                            }
                        }
                        
                    }
                    if(m_differPlayer == true)
                    {
                        m_differPlayer = false;
                    }
                    else
                    {
                        m_differPlayer = true;
                    }
                    break;

                case 4:     //Random Bot
                    std::random_device randomBot;
                    std::mt19937 generator(randomBot());
                    std::uniform_int_distribution<int> distribution(1, (colsFix+1));
                    m_col = distribution(randomBot);
                    if(m_differPlayer == true)
                    {
                        m_differPlayer = false;
                    }
                    else
                    {
                        m_differPlayer = true;
                    }
                    break;

                // case 5:     //Schlauer Bot

                //     if(m_differPlayer == true)
                //     {
                //         m_differPlayer = false;
                //     }
                //     else
                //     {
                //         m_differPlayer = true;
                //     }
                //     break;
            }
        }      

        if(human)
        {
            m_col--;                     //arrays fangen bei 0 an -> Mensch fängt bei 1 an zu zählen
        }


        if(array[0][m_col] == m_menu.getSymbol1() || array[0][m_col] == m_menu.getSymbol2())    //maximale Feldhöhe erreicht?
        {
            cout << "Ungültige Eingabe, bitte erneut auswaehlen!\n" << endl;
            m_alteredNumber = alternatingPlayer();
            setSymbol1();   
        }
        else
        {
            for(int i = (rowsFix +1); i>=0; i--)
            {
                if(array[i][m_col] == "\u2395")   //mit "\u25A1" kann man auch Vierecke machen
                {
                    if(m_differPlayer == 1) //Fallunterscheidung Spieler 1
                    {
                        array[i][m_col] = m_menu.getSymbol1();      //Über das Objekt der Klasse Menu wird auf die
                        checkWin(i, m_col);
                    }
                    else                    //Fallunterscheidung Spieler 2
                    {
                        array[i][m_col] = m_menu.getSymbol2();   //mit \u0F1A = Kreis und mit \u0F1D = Kreuz aber sehr klein
                    }
                    break;                                  //Funktion innerhalb der Klasse Menu zugegriffen
                }
            }
        }
    }
    

    bool checkWin(int row, int column)
    {
        //horizontal
        if(array[row][column] == array[row][column + 1])
        {
            
        }
        //vertical

        //diagonal
    }

    bool checkWinner()
    {

    }


    virtual ~Feld(){};

private:
    int m_feldbreite;
    int m_feldhoehe;
    Menu m_menu;                                        //Objekt von Menu muss hier bereitgestellt werden
                                                        //wird später mit dem wirklichen Objekt initialisiert (m_menu ist hier Platzhalter)
    string array[15][15];           //Maximal Feldgröße, solle aber variabel sein (Tatsächliche Feldgröße kleiner) -> Steine können außerhalb platziert werden                    
    int m_col;
    int static m_counter;
    int m_alteredNumber;                                //wechselt zwischen gerade und ungerade -> Spieler 1 und Spieler 2
    bool m_differPlayer;                                //für Fallunterscheidung nach Spielstein
    int rowsFix;
    int colsFix;
    bool human;
};

int Feld::m_counter = 0; //Wichtig für Initialisierung von static Memebervariable

int main()
{
    Menu spiel;
    spiel.startGame();

    Feld feld(spiel);                                   //default constructor mit Objekt von Menu
    // feld.setSymbol1();
    // feld.printField();
    // feld.setSymbol1();
    // feld.printField();
    // while(feld.checkWin() == false)           //Gewinnbedingungen -> Schleife beendet wenn 4 in einer Reihe
    // {
    //     feld.setSymbol1();
    //     feld.printField();
    // }
    for(int v = 0; v<= 15; v++)
    {
        feld.setSymbol1();
        feld.printField();
    }

    return 0;
}
