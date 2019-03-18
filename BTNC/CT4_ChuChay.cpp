#include <iostream>
#include <windows.h>

std::string nhapTen()
{
    std::string ten;
    std::cout << "Nhap ten: ";
    std::cout.flush();
    getline(std::cin, ten);
    return ten;
}

void ChuChay()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    std::string ten;
    int n = 1;
    int t = 0;
    int color = 1;
    ten = nhapTen();
    while (true)
    {
        std::cout.flush();
        system("cls");
        for(int i = 1; i <= n; ++i)
            std::cout << "\n";
        if (t == 0) goto breakpoint;
        for (int j = 1; j <= t; ++j)
            std::cout << "\t";
    breakpoint:
        SetConsoleTextAttribute(handle, color);
        std::cout << ten;
        n++;
        color++;
        if (n >= 30)
        {
            n = 1;
            t++;
            if (t >= 10) t = 0;
        }
        if (color >= 16) color = 1;
        Sleep(10);
    }
}

int main()
{
    ChuChay();
    return 0;
}

