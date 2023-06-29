#include <iostream>
#include <string>

class Menu
{
public:
    Menu()
        : m_spieler1(0)
        , m_spieler2(0)
        , m_symbol1("")
        , m_symbol2("")
        {};

    Menu(int spieler1, int spieler2, std::string symbol1, std::string symbol2)
        : m_spieler1(spieler1)
        , m_spieler2(spieler2)
        , m_symbol1(symbol1)
        , m_symbol2(symbol2)
        {
        };
    
    virtual ~Menu(){};

    void startGame()
    {
        //Introtext
        std::cout << "Willkommen bei Vier Gewinnt!.\nFolgende Spielmodi stehen zur Auswahl:" << std::endl;
        std::cout << "(1) -> Mensch\n(2) -> Vertikaler Bot" << std::endl;
        std::cout << "(3) -> Hoizontaler Bot\n(4) -> Zufallsbot\n(5) -> Schlauer Bot\n" << std::endl;

        //Player1
        std::cout << "Bitte wählen Sie nun Spieler 1 und dessen Symbol aus:\nSpielmodus:";  //evtl. Fehler
        std::cin >> m_spieler1;
        std::cout << "Spielstein/Symbol:" << std::endl;
        std::cin >> m_symbol1 ;
        std::cout << std::endl;

        //Player2
        std::cout << "Bitte wählen Sie nun Spieler 2 und dessen Symbol aus:\nSpielmodus:";
        std::cin >> m_spieler2;
        std::cout << "Spielstein/Symbol:" << std::endl;
        std::cin >> m_symbol2;
        std::cout << std::endl;
    }

    //get Symbol1 from class Menu -> Gamemode -> vererbung an Feld
    std::string getSymbol1() const
    {
        return m_symbol1;
    }

protected:
    int m_spieler1;
    int m_spieler2;
    std::string m_symbol1;
    std::string m_symbol2;
};

/*_____________________________________________________________________________________________________*/


class Feld : public Menu
{
public:
    Feld(Menu menu)     //WICHTIG: Hier wird das Objekt der Klasse Menu an Feld übergeben! Erst dann kann man mit Feld auf Menu zugreifen
    : m_menu(menu)
    // : m_feldbreite()
    // , m_feldhoehe()
    {
        createField();  //da das Feld sowieso erstellt werden muss, kann das direkt im Konstruktor erledigt werden
    };


    //create a Matrix (here 6x6) out of zeros
    void createField()
    {
        for (int z = 0; z < 6; z++)
        {
            for (int w = 0; w < 6; w++)
            {
                array[z][w] = "0";
            }
        }
    }

    //print the field
    void printField()
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                std::cout << array[i][j] << "  ";
            }
            std::cout << std::endl;
        }
    }
    

    //set Symbol1 at chosen column
    void setSymbol1(int y)
    {                       
        y--;
        for(int i = 5; i>=0; i--)
        {
            if(array[i][y] == "0")
            {
                array[i][y] = m_menu.getSymbol1();      //Über das Objekt der Klasse Menu wird auf die
                break;                                  //Funktion innerhalb der Klasse Menu zugegriffen
            }
        }
    }

    //set Symbol2 at chosen column
    void setSymbol2(std::string symbol2, int y)         //muss noch angepasst werden
    {                       
        y--;
        for(int i = 5; i>=0; i--)
        {
            if(array[i][y] == "0")
            {
                array[i][y] = symbol2;
                break;
            }
        }
    }

    virtual ~Feld(){};

private:
    int m_feldbreite;
    int m_feldhoehe;
    Menu m_menu;                                        //Objekt von Menu muss hier bereitgestellt werden
    std::string array[6][6];                            //wird später mit dem wirklichen Objekt initialisiert (m_menu ist hier Platzhalter)
};

int main()
{
    Menu spiel;
    spiel.startGame();

    Feld feld(spiel);                                   //default constructor mit Objekt von Menu
    feld.createField();
    feld.setSymbol1(4);
    feld.printField();
    return 0;
}
