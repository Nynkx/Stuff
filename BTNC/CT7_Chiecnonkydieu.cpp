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

/*
Biến toàn cục sử dung
*/
std::vector<std::string> tukhoa = {"LYTUTRONG", "CAMAU", "TITANIC", "ABCDEFGHI"};
std::vector<player> pl;
std::string tuHienThi;
std::string tuDuocChon;
int num;
int SoNguoi;
bool endgame;

/*Tạo câu gợi ý*/
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
    case 3:
        std::cout << "a";
    }
}

/*Thay các ký tự trùng ở chuỗi nguồn vào chuỗi đích theo ký tự <c>*/
void xuatTuKhoa(std::string s1, std::string &s2, char c)
{
    for (int i = 0; i < s1.size(); ++i)
    {
        if (s1[i] == c) s2[i] = c;
    }
}

/*Kiểm tra ký tự <c> xuất hiện bao nhiêu lần trong chuỗi đích*/
int DemTuTrung(std::string s, char c)
{
    int counter = 0;
    for (int i = 0; i < s.size(); ++i)
        if (s[i] == c) counter++;
    return counter;
}

/*In hoa ký tự trong trường hợp nhập ký tự thường*/
char InHoa(char c)
{
    if (c >= 'a' && c <= 'z')
        return c-32;
    return c;
}

/*Khởi tạo các giá trị ban đầu*/
void KhoiTao()
{
    srand((unsigned)time(NULL));
    tuHienThi = "";
    SoNguoi = 3;
    num = /*rand() % tukhoa.size()*/3;
    tuDuocChon = tukhoa[num];
    for(int i = 0; i < SoNguoi; ++i)
    {
        pl.push_back(player());
        pl[i].diem = 0;
        pl[i].luot = 1;
        pl[i].hetluot = false;
    }
    for (int i = 0; i < tuDuocChon.size(); ++i)
    {
        tuHienThi += "*";
    }
    TaoGoiY(num);
    std::cout << "gom " << tuDuocChon.size() << " ky tu.\n";
}

/**/
void doiNguoi(int &n)
{
    n++;
    if (n >= 3) n = 0;
}


int demNguoiBiLoai()
{
    int counter = 0;
    for (int i = 0; i < pl.size(); ++i)
    {
        if (pl[i].hetluot == true)
            counter++;
    }
    return counter;
}

/*Thực hiện cộng trừ điểm và tính lượt*/
int tinhDiem(player &pl, bool isCorrect)
{
    int score = rand() % 9+1;
    if(isCorrect)
        pl.diem += score;
    else
    {
        pl.diem  -= score;
        pl.luot--;
    }
    return score;
}

/*Kiểm tra nếu ô chữ đã dược giải*/
bool KT_KetThuc()
{
    if (tuHienThi == tuDuocChon)
        return true;
    return false;
}

void ChiecNonKyDieu()
{
    char guess = ' ';
    int current = 0;
    KhoiTao();
    while (demNguoiBiLoai() < pl.size())
    {
        if(KT_KetThuc())
        {
            std::cout << tuHienThi << std::endl;
            break;
        }
        if (pl[current].hetluot == true)
        {
            doiNguoi(current);
            continue;
        }
        std::cout << tuHienThi << std::endl;
        do
        {
            if (current == 0)
                std::cout << "Moi nguoi choi thu nhat doan chu: ";
            else std::cout << "Moi nguoi choi thu " << current +1 << " doan chu: ";
            std::cin >> guess;
            guess = InHoa(guess);
            if (DemTuTrung(tuHienThi, guess) != 0)
                std::cout << "Chu nay da duoc doan. Xin doan lai!\n";
        } while (DemTuTrung(tuHienThi, guess) != 0);
        if (DemTuTrung(tuDuocChon, guess) == 0)
        {
            std::cout << "Khong co chu " << guess
                        << " nao. Ban bi tru " << tinhDiem(pl[current], false) << " diem.\n";
        }
        else
        {

            std::cout << "Co " << DemTuTrung(tuDuocChon, guess) << " chu " << guess
                        << ". ban duoc cong " << tinhDiem(pl[current], true) << " diem.\n";
        }
        if (pl[current].luot <= 0) pl[current].hetluot = true;
        xuatTuKhoa(tuDuocChon, tuHienThi, guess);
        if (!KT_KetThuc())
            doiNguoi(current);
    }
    std::cout << "Tro choi ket thuc.";
    if (KT_KetThuc())
        std::cout << " Nguoi choi thu " << current + 1 << " da giai duoc o chu!\n";
    else
        std::cout << " O chu van chua duoc giai!";
}


int main()
{
    ChiecNonKyDieu();
    return 0;
}

