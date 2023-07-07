#include <iostream>

int main() {
    int feld[6][6];
    int setpos = 0;
    for(int x = 0; x < 6; x++){
        for(int y = 0; y < 6; y++){
            feld[x][y] = 0;
        }
    }

bool run_instance = true;

while(run_instance) {
    std::cout << "Wo moechten Sie den Stein setzen? (Spalte 1-6)\n" << std::endl;
    std::cin >> setpos;
    std::cout << std::endl;

    // for(int i = 5; i >= 0; i--){
    //     if(feld[i][setpos-1] == 0){
    //         feld[i][setpos-1] = 1;
    //         break;
    //     }
    // }
    feld[0][setpos-1] = 1;

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
    bool check = true;
    int win_buffer = 0;
    while(check){
        if(win) check = false;
        else {
            for(int x = 0; x < 6; x++){
                for(int y = 0; y < 6; y++){
                    if(feld[x][y] != 0){
                        win_buffer = feld[x][y];
                        for(int dol = 1; dol < 4; dol++){
                            if(feld[x-dol][y-dol] != win_buffer) break;   // nach diagonal oben links checken
                            else if(x-dol < 0 || y-dol < 0) break;
                            else win = true;
                            }
                            for(int dul = 1; dul < 4; dul++){
                            if(feld[x+dul][y-dul] != win_buffer) break;   // nach diagonal unten links checken
                            else if(x+dul > 5 || y-dul < 0) break;
                            else win = true;
                            }
                            for(int dor = 1; dor < 4; dor++){
                            if(feld[x-dor][y+dor] != win_buffer) break;   // nach diagonal oben rechts suchen
                            else if(x-dor < 0 || y+dor > 5) break;
                            else win = true;
                            }
                            for(int dur = 1; dur < 4; dur++){
                            if(feld[x+dur][y+dur] != win_buffer) break;   // nach diagonal unten rechts suchen
                            else if(x+dur > 5 || y+dur > 5) break; 
                            else win = true; 
                            }
                            for(int r = 1; r < 4; r++){     
                            if(feld[x][y+r] != win_buffer) break;         // nach rechts suchen
                            else if(y+r > 5) break;
                            else win = true;
                            }
                            for(int l = 1; l < 4; l++){
                            if(feld[x][y-l] != win_buffer) break;         // nach links suchen
                            else if(y-l < 0) break;
                            else win = true;
                            }
                            for(int u = 1; u < 4; u++){
                            if(feld[x+u][y] != win_buffer) break;         // nach unten suchen
                            else if(x+u > 5) break;
                            else win = true;
                            }
                            for(int o = 1; o < 4; o++){
                            if(feld[x-o][y] != win_buffer) break;         // nach oben suchen
                            else if(x-o < 0) break;
                            else win = true;
                            }
                            }
                            
                        

                    }
                }
            }
        }
    if(win) run_instance = false;
    }

    return 0;
}
