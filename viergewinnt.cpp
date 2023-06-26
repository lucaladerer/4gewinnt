#include <iostream>
#include <string>

class Menu
{
public:
    Menu()
        : m_spieler1(), m_spieler2(){};

    void startGame()
    {
        std::cout << "Willkommen bei Vier Gewinnt!.\nFolgende Spielmodi stehen zur Auswahl:" << std::endl;
        std::cout << "(1) -> Mensch\n(2) -> Vertikaler Bot" << std::endl;
        std::cout << "(3) -> Hoizontaler Bot\n(4) -> Zufallsbot\n(5) -> Schlauer Bot\n"
                  << std::endl;
        std::cout << "Bitte wählen Sie nun Spieler 1 aus:" << std::endl;
        std::cin >> m_spieler1;
        std::cout << "Bitte wählen Sie nun Spieler 2 aus:" << std::endl;
        std::cin >> m_spieler2;
        std::cout << std::endl;
    }

protected:
    std::string m_spieler1;
    std::string m_spieler2;
};

/*_____________________________________________________________________________________________________*/


class Feld
{
public:
    Feld()
    : m_feldbreite(), m_feldhoehe()
    {};

    std::string array[6][6];    //Hier solle noch static stehen

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

    void setSymbol1(std::string symbol1, int x, int y)
    {
        x--;
        y--;
        array[x][y] = symbol1;
    }

    void setSymbol2(std::string symbol2, int x, int y)
    {
        x--;
        y--;
        array[x][y] = symbol2;
    }


    virtual ~Feld(){};

private:
    int m_feldbreite;
    int m_feldhoehe;
};

int main()
{
    Menu spiel;
    spiel.startGame();
    Feld feld;
    feld.createField();
    feld.setSymbol1("X", 2, 4);
    feld.setSymbol2("Y", 1, 1);
    feld.printField();
    return 0;
}
