#include <iostream>
#include <string>

class Menu
{
public:
    Menu()
    : m_spieler1()
    , m_spieler2()
    {};


    void startGame()
    {
        std::cout << "Willkommen bei Vier Gewinnt!.\nFolgende Spielmodi stehen zur Auswahl:" << std::endl; 
        std::cout << "(1) -> Mensch\n(2) -> Vertikaler Bot" << std::endl;
        std::cout << "(3) -> Hoizontaler Bot\n(4) -> Zufallsbot\n(5) -> Schlauer Bot\n" << std::endl;
        std::cout << "Bitte wählen Sie nun Spieler 1 aus:" << std::endl;
        std::cin >> m_spieler1;
        std::cout << "Bitte wählen Sie nun Spieler 2 aus:" << std::endl;
        std::cin >> m_spieler2;
    }

protected:
std::string m_spieler1;
std::string m_spieler2;
};



class Feld
{
public:
    Feld()
    : m_feldbreite()
    , m_feldhoehe()
    , m_array[][]()
    {
        m_array[m_feldbreite][m_feldhoehe];

        // for(int i = 0; i < m_feldbreite; i++)
        // {
        //     for(int j = 0; j < m_feldhoehe; j++)
        //     {
        //         m_array[i][j] = 0;
        //     }
        // }
    };

    // void buildField()
    // {
    //     for(int i = 0; i < m_feldbreite; i++)
    //     {
    //         for(int j = 0; j < m_feldhoehe; j++)
    //         {
    //             array[i][j] = 0;
    //         }
    //     }
    // }

    virtual ~Feld() {};
    
private:
    int m_feldbreite;
    int m_feldhoehe;
    int array[][];
};

int main()
{
    Menu spiel;
    spiel.startGame();
    Feld feld;
    feld.buildField();
    return 0;
}

