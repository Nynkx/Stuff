#include <iostream>
#include <cstdlib>
#include <ctime>


void inputName(std::string &p1, std::string &p2)
{
    std::cout << "Ten nguoi choi 1: ";
    std::cin >> p1;
    std::cout << "Ten nguoi choi 2: ";
    std::cin >> p2;
}

void numGen(int &a, int &b)
{
    srand((unsigned)time(0));
    a = (rand() % 3) +1;
    b = (rand() % 3) +1;
    //a = 1;
    //b = 3;
}

void mainGame()
{
    std::string p1, p2;
    int a = 0, b = 0;
    std::string choice[3] = {"KEO", "BUA", "BAO"};
    inputName(p1,p2);
    do
        numGen(a, b);
    while (a == b);
    std::cout << p1 << " chon " << choice[a-1] << " >< " << p2 << " chon " << choice[b-1];
    std::cout << std::endl << "NGUOI THANG CUOC: ";
    if (a == 3 && b == 1) std::cout << p1;
    else if (a < b)
        std::cout << p2;
    else std::cout << p1;

}

int main()
{
    mainGame();
    return 0;
}
