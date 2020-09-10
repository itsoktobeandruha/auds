#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string line;
    int count=0;
    std::ifstream in("C:\\input.txt");
    if (in.is_open())
    {
        while (std::getline(in, line))
        {
            std::cout << line << std::endl;
            count++;
        }
    }
    in.close();
    std::cout << std::endl;
    in.open("C:\\input.txt");
    std::string *mass = new std::string[count];
    for (int i = 0; i < count; i++)
    {
        std::getline(in, mass[i]);
    }
    for (int i = 0; i < count; i++)
    {
        std::cout << mass[i] << std::endl;
    }
	//я считал я красавчик всё в массиве всё красиво
    for (int i=0; i<count-1; i++)
    {
        for (int j = 0; j < count-i-1; j++)
        {
            if (mass[j] > mass[j+1])
                std::swap(mass[j], mass[j+1]);
        }
    }
    std::cout << std::endl;
    for (int i = 0; i < count; i++)
    {
        std::cout << mass[i] << std::endl;
    }
	//я отсортировал я красавчик всё в массиве у лёхи ксива
    int tmp_count = 0;
	for (int i=0; i<count-1; i++)
	{
        if (mass[i] != mass[i + 1])
            tmp_count++;
        if (i + 1 == count - 1 && mass[i] == mass[i + 1])
            tmp_count++;
	}
    std::string* doublicate_mass = new std::string[tmp_count];
    for (int i = 0, j = 0; i < count - 1; i++)
    {
        if (mass[i] != mass[i + 1])
        {
            doublicate_mass[j] = mass[i];
            j++;
        }
        if (i + 1 == count - 1 && mass[i] == mass[i + 1])
        {
            doublicate_mass[j] = mass[i];
	    }
    }
    std::cout << std::endl;
    for (int i = 0; i < tmp_count; i++)
    {
        std::cout << doublicate_mass[i] << std::endl;
    }
    in.close();
    std::cout << count << std::endl;
    std::cout << "End of program" << std::endl;
    return 0;
}