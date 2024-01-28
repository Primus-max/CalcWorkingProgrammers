// Вася работает программистом и получает 50$ за каждые 100 строк кода
//  За каждое третье опоздание на работу Васю штрафуют на 20$.Реализовать меню :
// ■ пользователь вводит желаемый доход Васи и количество
// опозданий, посчитать, сколько строк кода ему надо написать;
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
// Использовал дженерики, не проходили, но будем.
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

    cout << "Укажите желаемый доход : " ;

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

    cout << "Укажите количество опозданий : ";

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

    cout << "Укажите количество написанных строк : ";

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

/// <summary>
/// Метод рассчитывает: сколько раз Вася может опоздать;
/// </summary>
/// <param name="wishSalary">Желаемая зарплата</param>
/// <param name="writeLines">Количество написанных строк кода</param>
/// <returns>int количество раз сколько можно опоздать</returns>
int HowMuhCanLate(double wishSalary, int writeLines)
{
    int lateCount = 0;

    double totalSalary = writeLines * SELERY_PER_LINE;
    double penaltyAmount = wishSalary - totalSalary;

    if (penaltyAmount >= 0)
        return lateCount = penaltyAmount / LATE_PENALTY;
    else
        return -1;
}

/// <summary>
/// Метод рассчитывает:  сколько денег заплатят Васе и заплатят ли вообще
/// </summary>
/// <param name="writeLines">Количество написанных строк код</param>
/// <param name="lateCounts">Количество опозданий</param>
/// <returns></returns>
double HowMuchSalary(int writeLines, int lateCounts)
{
    double totalSalary = writeLines * SELERY_PER_LINE;
    double remainingSalary = totalSalary - (lateCounts * LATE_PENALTY);

    if (remainingSalary >= 0)    
        return remainingSalary;
    else
        return -1;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    double wishSalary = 0;
    int lateCount = 0;
    int countWriteline = 0;

    cout << "Я помогу в расчётах рабочего времени (Васи-часов * количество опозданий / чашек кофе)" << endl;
    cout << "---------------------------------------------------------------------------------------------" << endl;
    cout << "Если тебе нужно рассчитать:" << endl;
    cout << "1. Сколько строк кода нужно будет написать при желаемой оплате и количестве опозданий" << endl;
    cout << "2. Сколько раз можно опоздать при желаемой зарплате и написанных строках кода" << endl;
    cout << "3. Сколько раз можно опоздать при написанном количестве строк кода" << endl;
     
   
        int userChoice;
        cin >> userChoice;

        switch (userChoice)
        {
            case (1): 
            {
            wishSalary = GetWishSalary();
            lateCount = GetLateCount();
            int needWriteline = HowMuchWriteline(wishSalary, lateCount);

            cout << "В таком случае необходимо написать : " << needWriteline << " строчек кода" << endl;        
            cout << "---------------------------------------------------------------------------------------------" << endl;
            
            break;
            }

            case (2):
            {
                wishSalary = GetWishSalary();
                countWriteline = GetCountWriteline();;
                int canCountLate = HowMuhCanLate(wishSalary, countWriteline);

               if(canCountLate >= 0)
                    cout << "В таком случае опоздать можно будет : " << canCountLate << " раз" << endl;
               else
                   cout << "Опаздывать больше нельзя" << endl;

                cout << "---------------------------------------------------------------------------------------------" << endl;

                break;
            }

            case (3):
            {
                countWriteline = GetCountWriteline();
                lateCount = GetLateCount();
                double remainingSalary = HowMuchSalary(countWriteline, lateCount);

                if(remainingSalary >= 0)
                    cout << "В таком случае зарплата будет : " << remainingSalary << " денег" << endl;
                else
                    cout << "Придётся или меньше опаздывать или написать больше строчек код, потому что зарплата будет : " << remainingSalary << " денег" << endl;

                cout << "---------------------------------------------------------------------------------------------" << endl;

                break;
            }

            default:
                break;
        }
}


