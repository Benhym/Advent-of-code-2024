#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

enum stability
{
	Assending,
	Decending,
	Neither
};

bool isStable(const std::vector<int>& row) 
{
	for (size_t j = 1; j < row.size(); ++j) 
	{
		int difference = std::abs(row[j] - row[j - 1]);
		if (difference < 1 || difference > 3 || row[j] == row[j - 1]) 
		{
			return false;
		}
	}
	return true;
}

stability assendDecend(const std::vector<int>& row)
{
	if (row.size() < 2)
	{
		return Neither;
	}

	bool isAssending  = true;
	bool isDecending = true;

	for (size_t k = 1; k < row.size(); ++k)
	{
		if (row[k] > row[k - 1])
		{
			isDecending = false;
		}
		else if (row[k] < row[k -1])
		{
			isAssending = false;
		}
		else
		{
			isAssending = false;
			isDecending = false;
		}
	}
	if (isAssending) return Assending;
	if (isDecending) return Decending;
	return Neither;
}

int main()
{
	//Declare 2D vector to hold numbers from list
	vector<vector<int>> list = {};

	//Open file for reading
	std::ifstream file("List.txt");
	if (!file.is_open())
		{
			std::cerr << "Error: Unable to open file!" << std::endl;
			return 1;
		}

	std::string line;
	while (std::getline(file, line))
	{
		//A vector to hold numbers for the current line
		std::vector<int> row;
		std::istringstream lineStream(line);
		int number;

		// Read numbers from the line and add to the row vector
		while (lineStream >> number)
		{
			row.push_back(number);
		}

		//Add the row to list vector
		list.push_back(row);
	}


	file.close();

	int count = 0;

	for (const auto& row : list) {
		if (row.size() > 1 && isStable(row)) {
			switch (assendDecend(row))
			{
				case Assending:
					count++;
					break;
				case Decending:
					count++;
					break;
				case Neither:
					break;
			}
		}
	}

	std::cout << count;

	return 0;
}