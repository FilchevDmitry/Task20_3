#include <iostream>
#include<fstream>
#include<string>

int main()
{
	std::string fish;
	int count =0;
	do
	{
		std::cout<< "What kind of fish do you catch ? (to exit, enter no) : ";
		std::cin >> fish;
		if (fish != "no")
		{
			std::ifstream river("river.txt");
			if (!river.is_open())
			{
				std::cout << "File not open" << std::endl;
			}
			else
			{
				std::string fishInRiver;
				bool one = true;
				while (!river.eof()&one)
				{
					std::getline(river, fishInRiver);
					if (fishInRiver == fish)
					{
						std::ofstream bask("basket.txt", std::ios::app);
						if (!bask.is_open())
						{
							std::cout << "File not open" << std::endl;
						}
						else
						{
							bask << fish << std::endl;
							count++;
							one = false;
						}
						bask.close();
					}
				}
				river.close();
			}
		}
	} 
	while (fish != "no");
	std::cout << count << " fish were caught during this fishing trip" << std::endl;
}

