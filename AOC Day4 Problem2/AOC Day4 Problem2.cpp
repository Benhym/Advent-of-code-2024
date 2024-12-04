#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	vector<vector<char>> puzzle{};

	std::ifstream file("Puzzle.txt");
	if (!file.is_open())
	{
		std::cerr << "Error: Unable to open file!" << std::endl;
		return 1;
	}

	std::string line;
	while (std::getline(file, line))
	{
		std::vector<char> row;
		std::istringstream linestream(line);
		char input;

		while (linestream >> input)
		{
			row.push_back(input);
		}

		puzzle.push_back(row);
	}

	file.close();

	int count = 0;

	for (size_t i = 0; i < puzzle.size(); i++)
	{
		for (size_t j = 0; j < puzzle[i].size(); j++)
		{
			if (i != 0 && j != 0 && i != puzzle.size()-1 && j != puzzle[i].size()-1)
			{
				if (puzzle[i][j] == 'A')
				{
					if (puzzle[i - 1][j - 1] == 'M' && puzzle[i + 1][j + 1] == 'S')
					{
						if (puzzle[i + 1][j - 1] == 'M' && puzzle[i - 1][j + 1] == 'S')
						{
							count++;
						}
						if (puzzle[i + 1][j - 1] == 'S' && puzzle[i - 1][j + 1] == 'M')
						{
							count++;
						}
					}
					if (puzzle[i - 1][j - 1] == 'S' && puzzle[i + 1][j + 1] == 'M')
					{
						if (puzzle[i + 1][j - 1] == 'M' && puzzle[i - 1][j + 1] == 'S')
						{
							count++;
						}
						if (puzzle[i + 1][j - 1] == 'S' && puzzle[i - 1][j + 1] == 'M')
						{
							count++;
						}
					}
				}
			}
		}
	}

	std::cout << count;

	return 0;
}