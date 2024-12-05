#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	vector<vector<int>> orders;
	vector<vector<int>> sequences;

	std::ifstream inputFile("Order.txt");
	if (!inputFile.is_open())
	{
		std::cerr << "Error: Could not open file." << std::endl;
		return 1;
	}

	std::string line;
	while (std::getline(inputFile, line))
	{
		std::vector<int> row;
		std::stringstream so(line);
		std::string value;

		while (std::getline(so, value, '|'))
		{
			row.push_back(std::stoi(value));
		}

		orders.push_back(row);
	}

	inputFile.close();

	std::ifstream file("Sequences.txt");
	if (!file.is_open())
	{
		std::cerr << "Error: Could not open file." << std::endl;
		return 1;
	}

	std::string lines;
	while (std::getline(file, lines))
	{
		std::vector<int> row;
		std::stringstream ss(lines);
		std::string value;

		while (std::getline(ss, value, ','))
		{
			row.push_back(std::stoi(value));
		}

		sequences.push_back(row);
	}

	file.close();

	int total = 0;

	for (size_t i = 0; i < sequences.size(); i++)
	{
		bool rule = true;
		for (size_t j = 0; j < sequences[i].size(); j++)
		{

			for (size_t k = 0; k < orders.size(); k++)
			{
				if (orders[k][1] == sequences[i][j])
				{

					for (size_t l = j + 1; l < sequences[i].size(); l++)
					{
						if (sequences[i][l] == orders[k][0])
						{
							rule = false;
						}
					}
				}
			}

		}
		if (rule == true)
		{	
			int m = ((sequences[i].size() - 1) / 2);
			total = total + sequences[i][m];
		}
	}

	std::cout << total;

	return 0;
}
