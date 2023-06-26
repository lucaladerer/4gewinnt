#include <iostream>
#include <string>

class Menu
{
public:
    Menu()
        : m_spieler1()
        , m_spieler2()
        , m_symbol1()
        , m_symbol2()
        {};

    void startGame()
    {
        std::cout << "Willkommen bei Vier Gewinnt!.\nFolgende Spielmodi stehen zur Auswahl:" << std::endl;
        std::cout << "(1) -> Mensch\n(2) -> Vertikaler Bot" << std::endl;
        std::cout << "(3) -> Hoizontaler Bot\n(4) -> Zufallsbot\n(5) -> Schlauer Bot\n" << std::endl;

        std::cout << "Bitte wählen Sie nun Spieler 1 und dessen Symbol aus:\nSpielmodus:";  //evtl. Fehler
        std::cin >> m_spieler1;
        std::cout << "Spielstein/Symbol:" << std::endl;
        std::cin >> m_symbol1 ;
        std::cout << std::endl;

        std::cout << "Bitte wählen Sie nun Spieler 2 und dessen Symbol aus:\nSpielmodus:";
        std::cin >> m_spieler2;
        std::cout << "Spielstein/Symbol:" << std::endl;
        std::cin >> m_symbol2;
        std::cout << std::endl;
    }

protected:
    std::string m_spieler1;
    std::string m_spieler2;
    std::string m_symbol1;
    std::string m_symbol2;
};

/*_____________________________________________________________________________________________________*/


class Feld : public Menu
{
public:
    // Feld()
    // : m_feldbreite()
    // , m_feldhoehe()
    // {};

    std::string array[6][6];

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

    std::string getSymbol1()
    {
        symbol1 = m_symbol1;
        return symbol1;
    }

    void setSymbol1(int y)
    {                       //sollte eventuell noch invertiert werden
        y--;
        for(int i = 5; i>=0; i--)
        {
            if(array[i][y] == "0")
            {
                array[i][y] = m_symbol1;
                break;
            }
        }
    }

    void setSymbol2(std::string symbol2, int y)
    {                       //sollte eventuell noch invertiert werden
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
    std::string symbol1;
};

int main()
{
    Menu spiel;
    spiel.startGame();
    Feld feld;
    feld.createField();
    feld.setSymbol1(4);
    feld.printField();
    return 0;
}
