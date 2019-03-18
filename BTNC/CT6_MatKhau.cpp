#include <iostream>
#include <conio.h>

std::string nhapMK()
{
    std::string s;
    char ch;
    std::cout << "Moi nhap password: ";
    while ((ch = _getch()) != '\r')
    {
        s += ch;
        std::cout << '*';
    }
    std::cout << std::endl;
    return s;
}

bool KiemTraMK(std::string pass1, std::string pass2)
{
    if (pass1 == pass2) return true;
    return false;
}




int main()
{
    std::string password;
    const std::string DEF_PASSWORD = "LTT-2019-.";
    unsigned int failedAtt = 0;
    do
    {
        password = nhapMK();
        if (!KiemTraMK(password, DEF_PASSWORD))
        {
            std::cout << "Password sai!" << std::endl;
            failedAtt++;
            if (failedAtt >= 3)
            {
                std::cout << "Ban khong duoc phep su dung chuong trinh nay!";
                break;
            }
        }
        else std::cout << "Password dung." << std::endl;
    } while(!KiemTraMK(password, DEF_PASSWORD));
    return 0;
}
