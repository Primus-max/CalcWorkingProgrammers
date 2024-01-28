// Вася работает программистом и получает 50$ за каждые 100 строк кода
//  За каждое третье опоздание на работу Васю штрафуют на 20$.Реализовать меню :
// ■ пользователь вводит желаемый доход Васи и количество
// опозданий, посчитать, сколько строк кода ему надонаписать;
// ■ пользователь вводит количество строк кода, написанное
// Васей и желаемый объем зарплаты.Посчитать, сколько
// раз Вася может опоздать;
// ■ пользователь вводит количество строк кода и количество
// опозданий, определить, сколько денег заплатят Васе и
// заплатят ли вообще


#include <iostream>
using namespace std;

const int SELERY_PER_LINE = 2;
const int LATE_PENALTY = 20;
const int ACCEPTABLE_LATE = 3;
const string ERROR_INPUT = "Некорректный ввод. Пожалуйста, введите положительное число, и не строку";

// Вспомогательный метод проверки корректного ввода пользователя. Не строка и не отрицательное число.
// Использвал дженерики, не проходили, но будем.
template <typename T>
T CheckUserInput(const std::string& str) {
    T result = 0;
    T fraction = 0.1;
    bool isFractionalPart = false;
    bool isNegative = false;

    for (char ch : str) {
        if (ch == '-' && result == 0) {
            isNegative = true;
        }
        else if (ch == '.' && !isFractionalPart) {
            isFractionalPart = true;
        }
        else if (ch >= '0' && ch <= '9') {
            if (isFractionalPart) {
                result += (ch - '0') * fraction;
                fraction *= 0.1;
            }
            else {
                result = result * 10 + (ch - '0');
            }
        }
        else {
            // Некорректный символ
            return static_cast<T>(-1);
        }
    }

    return isNegative ? -result : result;
}


/// <summary>
/// Метод получения желаемого дохода от пользователя
/// </summary>
/// <returns>double доход</returns>
double GetWishSalary() 
{
    string userInput;
    double wishSalary = 0;

    cout << "Укажите желаемый доход:" << endl;

    while (true) {
        cin >> userInput;

        double result = CheckUserInput<double>(userInput);

        if (result >= 0) {
            wishSalary = result;
            return wishSalary;
        }
        else {
            cout << ERROR_INPUT << endl;
        }
    }
}

/// <summary>
/// Метод получения количества опозданий от пользователя
/// </summary>
/// <returns>int количество опозданий</returns>
int GetLateCount() 
{
    string userInput;
    int lateCount = 0;

    cout << "Укажите количество опозданий:" << endl;

    while (true) {
        cin >> userInput;

        int result = CheckUserInput<int>(userInput);

        if (result >= 0) {
            lateCount = result;
            return lateCount;
        }
        else {
            cout << ERROR_INPUT << endl;
        }
    }
}

/// <summary>
/// Метод получения количества написанных строк от пользователя 
/// </summary>
/// <returns>int количество строк</returns>
int GetCountWriteline()
{
    string userInput;
    int countWriteline = 0;

    cout << "Укажите количество написанных строк:" << endl;

    while (true) {
        cin >> userInput;

        int result = CheckUserInput<int>(userInput);

        if (result >= 0) {
            countWriteline = result;
            return countWriteline;
        }
        else {
            cout << ERROR_INPUT << endl;
        }
    }

    return countWriteline;
}

/// <summary>
/// Метод рассчитывает: пользователь вводит желаемый доход Васи и количество опозданий, посчитать, сколько строк кода ему надо написать;
/// </summary>
/// <param name="wishSalary">Желаемый доход</param>
/// <param name="lateCount">Количество опозданий</param>
/// <returns>int количество строк которые необходимо написать</returns>
int HowMuchWriteline(double wishSalary, int lateCount)
{
    int lateRatio = (lateCount) / ACCEPTABLE_LATE;
    int penaltyAmount = lateRatio * LATE_PENALTY;
    double salaryWhithPenalty = wishSalary - penaltyAmount;
    double totalLines = salaryWhithPenalty / SELERY_PER_LINE;

    // Округляем до ближайшего целого числа
    int needWritliine = static_cast<int>(totalLines + 0.5);

    return needWritliine;
}




int main()
{
    setlocale(LC_ALL, "Russian");

    double wishSalary = 0;
    int lateCount = 0;
    int countWriteline = 0;

    cout << "Я помогу в расчётах рабочего времени (Васи-часов * количество обозданий / чашек кофе)" << endl;
    cout << "---------------------------------------------------------------------------------------------" << endl;
    cout << "Если тебе нужно рассчиать:" << endl;
    cout << "1. Сколько строк кода нужно будет написать при желаемой оплате и количестве опозданий" << endl;
    cout << "2. Сколько раз можно опоздать при желаемой зарплате и написанных строках кода" << endl;
    cout << "3. Сколько раз можно опоздать при написанном количестве строк кода" << endl;
     
    while (true)
    {
        int userChoice;
        cin >> userChoice;

        switch (userChoice)
        {
        case (1): 
        {
            wishSalary = GetWishSalary();
            lateCount = GetLateCount();
            int needWriteline = HowMuchWriteline(wishSalary, lateCount);

            cout << "В таком случае необходимо написать :" << needWriteline << " строчек кода" << endl;        }

        default:
            break;
        }
    }

   
    
    //countWriteline = GetCountWriteline();

    
    

}


