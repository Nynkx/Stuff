#include <iostream>
#include <ctime>
#include <vector>

std::vector<std::string> pattern = {
                                    "==========\n-        -\n-   *    -\n==========",
                                    "==========\n-        -\n-  *  *  -\n==========",
                                    "==========\n-  *  *  -\n-   *    -\n==========",
                                    "==========\n-  *  *  -\n-  *  *  -\n==========",
                                    "==========\n-  * * * -\n-  *  *  -\n==========",
                                    "==========\n-  * * * -\n-  * * * -\n=========="};
std::vector<std::string> word = {"NHAT", "NHI", "TAM", "TU", "NGU", "LUC"};

int tungSucXac()
{
    srand((unsigned)time(NULL));
    return rand() % 6;
}

int main()
{
    int n = tungSucXac();
    std::cout << "Ket qua tung sux xac: " << word[n] << std::endl;
    std::cout << pattern[n];
    return 0;
}
