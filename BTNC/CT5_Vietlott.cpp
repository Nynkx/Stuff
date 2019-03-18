#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

bool isMatch(std::vector<int> a, int n)
{
    for (int i = 0; i < a.size(); ++i)
        if (a[i] == n) return true;
    return false;
}

std::vector<int> SapXep(std::vector<int> a)
{
    for (int i = 0; i < a.size() -1; ++i)
    {
        int Min = i;
        for (int j = i+1; j < a.size(); ++j)
            if (a[j] < a[Min]) Min = j;
        int temp;
        temp = a[i];
        a[i] = a[Min];
        a[Min] = temp;
    }
    return a;
}

void nhapMang(std::vector<int> &a)
{
    int value;
    int i = 0;
    std::cout << "Moi ban chon 6 so tu 1 den 45" << std::endl;
    do
    {
        std::cout << "So thu " << i+1 << ": ";
        std::cin >> value;
        if (value <= 0 || value >= 46)
        {
            std::cout << "So phai nam trong khoang tu 1 den 45!" << std::endl;
            continue;
        }
        if (isMatch(a, value))
        {
            std::cout << "So bi trung. Xin nhap so khac!" << std::endl;
            continue;
        }
        a.push_back(value);
        i++;
    } while (i < 6);
}

void xuatMang(std::vector<int> a)
{
    for (int i = 0; i < a.size(); ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

void taoMang(std::vector<int> &a)
{
    srand((unsigned)time(NULL));
    int value;
    int i = 0;
    do
    {
        value = rand() % (45 + 1);
        if (isMatch(a, value)) continue;
        a.push_back(value);
        i++;
    } while (i < 6);
}

int XuLy(std::vector<int> a, std::vector<int> kq)
{
    int match = 0;
    for (int i = 0; i < kq.size(); ++i)
            if (isMatch(a, kq[i]))
                match++;
    return match;
}

void xuatKetQua(int n)
{
    switch(n)
    {
        case 3: std::cout << "Ban da trung 30 ngan dong!";
            break;
        case 4: std::cout << "Ban da trung 300 ngan dong!";
            break;
        case 5: std::cout << "Ban da trung 10 trieu dong!";
            break;
        case 6: std::cout << "Ban da trung 12 ty dong!";
            break;
        default: std::cout << "Chuac ban may man lan sau!";
    }
}

int main()
{
    std::vector<int> a;
    std::vector<int> kq;
    int match;
    nhapMang(a);
    taoMang(kq);
    match = XuLy(a, kq);
    std::cout << "Day so da nhap : ";
    xuatMang(SapXep(a));
    std::cout << "Ket qua so xo: ";
    xuatMang(SapXep(kq));
    std::cout <<"Ban da doan trung "<< match << " so. ";
    xuatKetQua(match);
    return 0;
}
