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
    
    std::cout << leftList[0] << "/n" << rightList[0] << "/n" << leftList[1] << "/n" << rightList[1];

    int i = 0;
    int j = 0;

 
    std::sort(std::begin(leftList), std::end(leftList));
    std::sort(std::begin(rightList), std::end(rightList));
    
    for (auto num : leftList)
    {
        if (leftList[j] > rightList[j])
        {
            i = i + (leftList[j] - rightList[j]);
            std::cout << leftList[j] - rightList[j] << "\n";
        }
        if (rightList[j] > leftList[j])
        {
            i = i + (rightList[j] - leftList[j]);
            std::cout << rightList[j] - leftList[j] << "\n";
        }
        else
        {
            std::cout << "0\n";         
        }
        j++;
    }
    
    std::cout << i;
 
    return 0;
}