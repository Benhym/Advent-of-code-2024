#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int main()
{
	std::vector<char> sequence;

	std::ifstream file("List.txt");

	if (!file.is_open())
	{
		std::cerr << "Error: Unable to open file!" << std::endl;
		return 1;
	}

	char c;

	while (file.get(c))
	{
		sequence.push_back(c);

	}

	file.close();

	bool active = true;
	int num1 = 0;
	int num2 = 0;
	int total = 0;

	for (size_t i = 0; i < sequence.size(); i++)
	{
		if (sequence[i] == 'd' && sequence[i + 1] == 'o' && sequence[i + 2] != 'n' && sequence[i + 3] != '\'' && sequence[i + 4] != 't')
		{
			active = true;
		}
		if (sequence[i] == 'd' && sequence[i + 1] == 'o' && sequence[i + 2] == 'n' && sequence[i + 3] == '\'' && sequence[i + 4] == 't')
		{
			active = false;
		}
		if (active == true)
		{
			if (sequence[i] == 'm' && sequence[i + 1] == 'u' && sequence[i + 2] == 'l' && sequence[i + 3] == '(')
			{
				if (isdigit(sequence[i + 4]) && sequence[i + 5] == ',')
				{
					if (isdigit(sequence[i + 6]) && sequence[i + 7] == ')')
					{
						num1 = sequence[i + 4] - '0';
						num2 = sequence[i + 6] - '0';
						total = total + (num1 * num2);
					}
					else if (isdigit(sequence[i + 6]) && isdigit(sequence[i + 7]) && sequence[i + 8] == ')')
					{
						num1 = sequence[i + 4] - '0';
						num2 = ((sequence[i + 6] - '0') * 10) + (sequence[i + 7] - '0');
						total = total + (num1 * num2);
					}
					else if (isdigit(sequence[i + 6]) && isdigit(sequence[i + 7]) && isdigit(sequence[i + 8]) && sequence[i + 9] == ')')
					{
						num1 = sequence[i + 4] - '0';
						num2 = ((sequence[i + 6] - '0') * 100) + ((sequence[i + 7] - '0') * 10) + (sequence[i + 8] - '0');
						total = total + (num1 * num2);
					}
				}
				else if (isdigit(sequence[i + 4]) && isdigit(sequence[i + 5]) && sequence[i + 6] == ',')
				{
					if (isdigit(sequence[i + 7]) && sequence[i + 8] == ')')
					{
						num1 = ((sequence[i + 4] - '0') * 10) + (sequence[i + 5] - '0');
						num2 = sequence[i + 7] - '0';
						total = total + (num1 * num2);
					}
					else if (isdigit(sequence[i + 7]) && isdigit(sequence[i + 8]) && sequence[i + 9] == ')')
					{
						num1 = ((sequence[i + 4] - '0') * 10) + (sequence[i + 5] - '0');
						num2 = ((sequence[i + 7] - '0') * 10) + (sequence[i + 8] - '0');
						total = total + (num1 * num2);
					}
					else if (isdigit(sequence[i + 7]) && isdigit(sequence[i + 8]) && isdigit(sequence[i + 9]) && sequence[i + 10] == ')')
					{
						num1 = ((sequence[i + 4] - '0') * 10) + (sequence[i + 5] - '0');
						num2 = ((sequence[i + 7] - '0') * 100) + ((sequence[i + 8] - '0') * 10) + (sequence[i + 9] - '0');
						total = total + (num1 * num2);
					}
				}
				else if (isdigit(sequence[i + 4]) && isdigit(sequence[i + 5]) && isdigit(sequence[i + 6]) && sequence[i + 7] == ',')
				{
					if (isdigit(sequence[i + 8]) && sequence[i + 9] == ')')
					{
						num1 = ((sequence[i + 4] - '0') * 100) + ((sequence[i + 5] - '0') * 10) + (sequence[i + 6] - '0');
						num2 = sequence[i + 8] - '0';
						total = total + (num1 * num2);
					}
					else if (isdigit(sequence[i + 8]) && isdigit(sequence[i + 9]) && sequence[i + 10] == ')')
					{
						num1 = ((sequence[i + 4] - '0') * 100) + ((sequence[i + 5] - '0') * 10) + (sequence[i + 6] - '0');
						num2 = ((sequence[i + 8] - '0') * 10) + (sequence[i + 9] - '0');
						total = total + (num1 * num2);
					}
					else if (isdigit(sequence[i + 8]) && isdigit(sequence[i + 9]) && isdigit(sequence[i + 10]) && sequence[i + 11] == ')')
					{
						num1 = ((sequence[i + 4] - '0') * 100) + ((sequence[i + 5] - '0') * 10) + (sequence[i + 6] - '0');
						num2 = ((sequence[i + 8] - '0') * 100) + ((sequence[i + 9] - '0') * 10) + (sequence[i + 10] - '0');
						total = total + (num1 * num2);
					}
				}
			}
		}

	}

	std::cout << total;

	return 0;
}