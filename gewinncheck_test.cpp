#include <iostream>

int main() {
    int feld[6][6];
    int setpos = 0;
    for(int x = 0; x < 6; x++){
        for(int y = 0; y < 6; y++){
            feld[x][y] = 0;
        }
    }

    std::cout << "Wo moechten Sie den Stein setzen? (Spalte 1-6)\n" << std::endl;
    std::cin >> setpos;

    for(int i = 5; i >= 0; i--){
        if(feld[i][setpos] == 0){
            feld[i][setpos] = 1;
            break;
        }
    }

    for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                std::cout << feld[i][j] << "  ";
            }
            std::cout << std::endl;
        }


    bool run = true;
    bool win = false;
    bool check_dol = false;
    bool check_dul = false;
    bool check_dor = false;
    bool check_dur = false;
    int win_buffer = 0;
    while(run){
        if(win) run = false;
        else {
            for(int x = 0; x < 6; x++){
                for(int y = 0; y < 6; y++){
                    if(feld[x][y] != 0){
                        win_buffer = feld[x][y];
                        for(int dol = 1; dol < 4; dol++){
                            if(feld[x-dol][y-dol] != win_buffer) break;     // nach diagonal oben links checken
                            else if(x-dol < 0 || y-dol < 0) break;
                            else if(feld[x+dol][y-dol] != win_buffer) break;    // nach diagonal unten links checken
                            else if(x+dol > 5 || y-dol < 0) break;
                            else if(feld[x-dol][y+dol] != win_buffer) break;    // nach diagonal oben rechts suchen
                            else if(x-dol < 0 || y+dol > 5) break;
                            else if(feld[x+dol][y+dol] != )
                            else win = true;
                        }

                    }
                }
            }
        }
    }

    return 0;
}
