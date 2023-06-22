#include <iostream>
#include <string>

int main(){
 
    int m_feldbreite = 6;
    int m_feldhoehe = 6;
    int array[m_feldbreite][m_feldhoehe] = {0};
    

        for(int i = 0; i < m_feldbreite; i++)
        {
            for(int j = 0; j < m_feldhoehe; j++)
            {
                array[i][j] = 0;
                if(j!=5)
                std::cout << array[i][j] << " ";
                else
                std::cout << std::endl;
            }
        }


    return 0;
}