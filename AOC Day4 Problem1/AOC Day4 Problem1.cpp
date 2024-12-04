#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	vector<vector<char>> puzzle = {};

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
		int si = puzzle.size();

		for (size_t j = 0; j < puzzle[i].size(); j++)
		{
			int sj = puzzle[i].size();

			if (puzzle[i][j] == 'X')
			{
				if (i > 2 && j > 2 && puzzle[i - 1][j - 1] == 'M' && puzzle[i - 2][j - 2] == 'A' && puzzle[i - 3][j - 3] == 'S')
				{
					count++;
					
				}
				if (i > 2 && puzzle[i - 1][j] == 'M' && puzzle[i - 2][j] == 'A' && puzzle[i - 3][j] == 'S')
				{
					count++;
					
				}
				if (i > 2 && j < sj - 3 && puzzle[i - 1][j + 1] == 'M' && puzzle[i - 2][j + 2] == 'A' && puzzle[i - 3][j + 3] == 'S')
				{
					count++;
					
				}
				if (j > 2 && puzzle[i][j - 1] == 'M' && puzzle[i][j - 2] == 'A' && puzzle[i][j - 3] == 'S')
				{
					count++;
			
				}
				if (j < sj -3 && puzzle[i][j + 1] == 'M' && puzzle[i][j + 2] == 'A' && puzzle[i][j + 3] == 'S')
				{
					count++;
					
				}
				if (i < si -3 && j > 2 && puzzle[i+1][j - 1] == 'M' && puzzle[i+2][j - 2] == 'A' && puzzle[i+3][j - 3] == 'S')
				{
					count++;
					
				}
				if ( i < si -3 && puzzle[i+1][j] == 'M' && puzzle[i+2][j] == 'A' && puzzle[i+3][j] == 'S')
				{
					count++; 
				

				}
				if (i < si - 3 && j < sj -3 && puzzle[i+1][j + 1] == 'M' && puzzle[i+2][j + 2] == 'A' && puzzle[i+3][j + 3] == 'S')
				{
					count++;
					
				}
			}
		}
	}

	std::cout << count;

	return 0;
}