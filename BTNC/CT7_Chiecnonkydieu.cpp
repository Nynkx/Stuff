#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

typedef struct
{
    int diem;
    int luot;
    bool hetluot;
} player;

std::vector<std::string> tukhoa = {"LYTUTRONG", "CAMAU", "TITANIC"};
std::vector<player> pl;
std::string tuHienThi;
std::string tuDuocChon;
unsigned int current = 0;
int num;
int SoNguoi;
int winner = -1;
bool endgame;


void TaoGoiY(int i)
{
    switch(i)
    {
    case 0:
        std::cout << "Day la ten mot truong cao dang chat luong cao, ";
            break;
    case 1:
        std::cout << "Day la ten mot dia danh o Nam bo, ";
            break;
    case 2:
        std::cout << "Day la ten mot bo phim o thap nien 90 the ky XX, ";
            break;
    }
}

void xuatTuKhoa(std::string s, char c)
{
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == c) tuHienThi[i] = c;
    }
}

int DemTuTrung(std::string s, char c)
{
    int counter = 0;
    for (int i = 0; i < s.size(); ++i)
        if (s[i] == c) counter++;
    return counter;
}

char InHoa(char c)
{
    if (c >= 'a' && c <= 'z')
        return c-32;
    return c;
}

void KhoiTao()
{
    tuHienThi = "";
    SoNguoi = 3;
    num = rand() % 3;
    tuDuocChon = tukhoa[num];
    for(int i = 0; i < SoNguoi; ++i)
    {
        pl.push_back(player());
        pl[i].diem = 0;
        pl[i].luot = 5;
        pl[i].hetluot = false;
    }
    for (int i = 0; i < tuDuocChon.size(); ++i)
    {
        tuHienThi += "*";
    }
}

bool KT_TrungLap(std::string s, char c)
{
    for (int i = 0; i < s.size(); ++i)
        if (s[i] == c)
            return true;
    return false;
}

bool KT_KetThuc()
{
    if (tuHienThi == tuDuocChon)
        return true;
    return false;
}

void ChiecNonKyDieu()
{
    srand((unsigned)time(NULL));

    char guess = ' ';
    KhoiTao();
    TaoGoiY(num);
    std::cout << "gom " << tuDuocChon.size() << " ky tu.\n";
    while (SoNguoi != 0)
    {
        if(KT_KetThuc()) break;
        if (pl[current].hetluot == true)
        {
            SoNguoi--;
            goto doinguoi;
        }
        std::cout << tuHienThi << std::endl;

        do
        {
        if (current == 0)
            std::cout << "Moi nguoi choi thu nhat doan chu: ";
        else std::cout << "Moi nguoi choi thu " << current +1 << " doan chu: ";
        std::cin >> guess;
        guess = InHoa(guess);
        if (KT_TrungLap(tuHienThi, guess))
            std::cout << "Chu nay da duoc doan. Xin doan lai!\n";
        } while (KT_TrungLap(tuHienThi, guess));
        if (DemTuTrung(tuDuocChon, guess) == 0)
        {
            int score = rand() % 5 + 1;
            std::cout << "Khong co chu " << guess << " nao. Ban bi tru " << score << " diem.\n";
            pl[current].diem -= score;
            pl[current].luot--;
            if (pl[current].luot <= 0) pl[current].hetluot = true;
        }
        else
        {
            int score = rand() % 5 + 1;
            std::cout << "Co " << DemTuTrung(tuDuocChon, guess) << " chu " << guess << ". ban duoc cong " << score << " diem.\n";
            pl[current].diem += score;
        }
        xuatTuKhoa(tuDuocChon, guess);
    doinguoi:
        if (!KT_KetThuc())
        {
            current++;
            if (current >= 3) current = 0;
        }
    }
    std::cout << "Tro choi ket thuc.";
    if (KT_KetThuc())
        std::cout << " Nguoi choi thu " << current + 1 << " da giai duoc o chu!\n";
    else if (!KT_KetThuc())
        std::cout << " O chu van chua duoc giai!";
}


int main()
{
    ChiecNonKyDieu();
    return 0;
}

