#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>


int main()
{
    std::vector<int> leftList{};
    std::vector<int> rightList{};
    std::vector<int> allList{};

    std::ifstream inputFile("List1 and 2.txt");
    std::string line;

    if (!inputFile.is_open())
    {
        std::cerr << "Error: Unable to open file!" << std::endl;
        return 1;
    }

    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        int num1;
        int count = 0;

        while (iss >> num1 && count < 4)
        {
            allList.push_back(num1);
            count++;
        }
    }

    inputFile.close();

    int j = 0;

    for (size_t i = 0; i < allList.size(); i++)
    {
        if (i % 2 == 0)
        {
            leftList.push_back(allList[i]);
        }
        else
        {
            rightList.push_back(allList[i]);
        }
    }

    for (int num : leftList)
    {
        int frequency = count(rightList.begin(), rightList.end(), num);

        j = j + (num * frequency);
    }

    std::cout << j;

    return 0;
}