/*
Ханойские башни.
Реализовать решение задачи о ханойских башнях без использования рекурсии.
Вместо этого используйте стеки.

Автор: Шушков А.В
Группа: ПИ-21д
Лаб.работа: 6
Вариант: 17
Дата: 14.02.2023
*/

#include <iostream>
#include <stack>

using namespace std;


//Функция перемещает все диски к целевому стержню C
//На вход подаются количество дисков, главный стержень, вспомогательный и целевой

void moveDisks(int n, stack<int>& source, stack<int>& destination, stack<int>& auxiliary) {
    int totalMoves = pow(2, n) - 1;
    for (int i = n; i >= 1; i--)
        source.push(i);

    for (int i = 1; i <= totalMoves; i++) {
        if (i % 3 == 1) {
            if (!source.empty() && (auxiliary.empty() || source.top() < auxiliary.top())) {
                auxiliary.push(source.top());
                source.pop();
                cout << "Переместили диск " << auxiliary.top() << " из A в B" << endl;
            }
            else {
                destination.push(auxiliary.top());
                auxiliary.pop();
                cout << "Переместили диск " << destination.top() << " из B в C" << endl;
            }
        }
        else if (i % 3 == 2) {
            if (!source.empty() && (destination.empty() || source.top() < destination.top())) {
                destination.push(source.top());
                source.pop();
                cout << "Переместили диск " << destination.top() << " из A в C" << endl;
            }
            else {
                source.push(destination.top());
                destination.pop();
                cout << "Переместили диск " << source.top() << " из C в A" << endl;
            }
        }
        else if (i % 3 == 0) {
            if (!destination.empty() && (auxiliary.empty() || destination.top() < auxiliary.top())) {
                auxiliary.push(destination.top());
                destination.pop();
                cout << "Переместили диск " << auxiliary.top() << " из C во B" << endl;
            }
            else {
                source.push(auxiliary.top());
                auxiliary.pop();
                cout << "Переместили диск " << source.top() << " из B в A" << endl;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите количество дисков: ";
    cin >> n;

    stack<int> source, destination, auxiliary;
    moveDisks(n, source, destination, auxiliary);

    return 0;
}

//Создайте три стека : исходный стек(начальное состояние башен), вспомогательный стек(для перемещения элементов между башнями) и целевой стек(конечное состояние башен).
//Заполните исходный стек N элементами(от N до 1, где N - это количество дисков).
//Используйте цикл для выполнения следующих действий, пока целевой стек не будет содержать все N дисков :
//a.Если N четное, то :
//    i.Переместите диск между исходным и вспомогательным стеком.
//    ii.Переместите диск между исходным и целевым стеком.
//    iii.Переместите диск между вспомогательным и целевым стеком.
//    b.Если N нечетное, то :
//    i.Переместите диск между исходным и целевым стеком.
//    ii.Переместите диск между исходным и вспомогательным стеком.
//    iii.Переместите диск между вспомогательным и целевым стеком.
//    Когда целевой стек будет содержать все N дисков, решение будет завершено.
