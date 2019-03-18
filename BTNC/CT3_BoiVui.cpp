#include <iostream>

typedef struct
{
    int day;
    int month;
    int year;
} Date;

Date GetDate(std::string s)
{
    Date date;
    date.day = std::stoi(s.substr(0,2));
    date.month = std::stoi(s.substr(3,2));
    date.year = std::stoi(s.substr(6));
    return date;
}

void xuatQue(int n)
{
    switch (n)
    {
    case 0:
        std::cout << "Ban se gap nhieu may man trong tuong lai gan. Nhat la ve tinh cam!!!";
        break;
    case 1:
        std::cout << "Hay can than, co nguoi nao do dang noi xau sau lung ban day!!!";
        break;
    case 2:
        std::cout << "Tuong lai doi voi ban khong tot cung khong xau, nhung can than van hon!!!";
        break;
    case 3:
        std::cout << "Ban se gap mot it kho khan trong cuoc song, nhung dung lo se co cao nhan giup do ban!!!";
        break;
    }
}

void BoiVui()
{
    std::string s;
    std::cout << "Ngay sinh cua ban (DD/MM/YY): ";
    std::cin >> s;
    Date date = GetDate(s);
    int n = (date.year + date.day + date.month) % 3;
    std::cout << "LA SO CUA BAN:\n";
    xuatQue(n);
}

int main()
{
    BoiVui();
    return 0;
}
