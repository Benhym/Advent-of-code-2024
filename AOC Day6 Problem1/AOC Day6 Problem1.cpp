#include <iostream>
#include <fstream>
using namespace std;

int main() 
{
    char map[130][130];

    ifstream inputFile("Map.txt");

    if (!inputFile) 
    {
        cerr << "Unable to open file";
        return 1;
    }
    int row = 0, col = 0;
    char ch;


    while (inputFile.get(ch)) 
    {
       if (ch == '\n') 
        {
            col = 0;
            row++;
            continue;
        }

        if (row >= 130 || col >= 130) 
        {
            cerr << "Input exceeds array dimensions!" << endl;
            break;
        }
        map[row][col] = ch;
        col++;
    }

    inputFile.close();

    bool guardFound = false;
    int guardj = 0;
    int guardi = 0;

    while (guardFound == false)
    for (int i = 0; i < 130; i++)
    {
        for (int j = 0; j < 130; j++)
        {
            if (map[i][j] == '^')
            {
                guardi = i;
                guardj= j;
                guardFound = true;
                map[i][j] = 'x';
                std::cout << "Done find";
            }
        }
    }

    bool guardGone = false;
    bool guardUp = true;
    bool guardRight = false;
    bool guardDown = false;
    bool guardLeft = false;

    while (guardGone == false)
    {
        if (guardUp == true)
        {
            if (map[guardi - 1][guardj] != '#')
            {
                map[guardi - 1][guardj] = 'x';
                guardi = guardi - 1;
                if (guardi == 0)
                {
                    guardGone = true;
                }
            }
            if (map[guardi - 1][guardj] == '#')
            {
                guardUp = false;
                guardRight = true;
            }
            std::cout << "up";
        }
        if (guardRight == true)
        {
            if (map[guardi][guardj + 1] != '#')
            {
                map[guardi][guardj +1 ] = 'x';
                guardj = guardj + 1;
                if (guardj == 130)
                {
                    guardGone = true;
                }
            }
            if (map[guardi][guardj + 1] == '#')
            {
                guardRight = false;
                guardDown = true;
            }
            std::cout << "right";
        }
        if (guardDown == true)
        {
            if (map[guardi + 1][guardj] != '#')
            {
                map[guardi + 1][guardj] = 'x';
                guardi = guardi + 1;
                if (guardi == 130)
                {
                    guardGone = true;
                }
            }
            if (map[guardi + 1][guardj] == '#')
            {
                guardDown = false;
                guardLeft = true;
            }
            std::cout << "down";
        }
        if (guardLeft == true)
        {
            if (map[guardi][guardj - 1] != '#')
            {
                map[guardi][guardj - 1] = 'x';
                guardj = guardj - 1;
                if (guardj == 0)
                {
                    guardGone = true;
                }
            }
            if (map[guardi][guardj - 1] == '#')
            {
                guardLeft = false;
                guardUp = true;
            }
            std::cout << "left";
        }
    }

    int count = 0;
    
    for (int i = 0; i < 130; i++)
    {
        for (int j = 0; j < 130; j++)
        {
            if (map[i][j] == 'x')
            {
                count++;
            }
        }
    }

    std::cout << count << 'Y' << guardi << 'X' << guardj;

    return 0;
}