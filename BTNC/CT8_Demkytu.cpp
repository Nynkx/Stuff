#include <iostream>
#include <fstream>


int Demsotu(std::string path)
{
    std::ifstream input;
    std::string s;
    int len = 0;
    input.open(path);
    if (!input.is_open())
        std::cout << "Khong the mo file!";
    else
    {
        while(!input.eof())
        {
            input >> s;
            len++;
        }
    }
    input.close();
    return len;
}




int main()
{
    std::string filepath;
    std::cout << "Ten file can dem: ";
    std::cin >> filepath;
    std::cout << "Ket qua: File co " << Demsotu(filepath) << " tu!";
    return 0;
}
