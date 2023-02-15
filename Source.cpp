/*
��������� �����.
����������� ������� ������ � ��������� ������ ��� ������������� ��������.
������ ����� ����������� �����.

�����: ������ �.�
������: ��-21�
���.������: 6
�������: 17
����: 14.02.2023
*/

#include <iostream>
#include <stack>

using namespace std;


//������� ���������� ��� ����� � �������� ������� C
//�� ���� �������� ���������� ������, ������� ��������, ��������������� � �������

void moveDisks(int n, stack<int>& source, stack<int>& destination, stack<int>& auxiliary) {
    int totalMoves = pow(2, n) - 1;
    for (int i = n; i >= 1; i--)
        source.push(i);

    for (int i = 1; i <= totalMoves; i++) {
        if (i % 3 == 1) {
            if (!source.empty() && (auxiliary.empty() || source.top() < auxiliary.top())) {
                auxiliary.push(source.top());
                source.pop();
                cout << "����������� ���� " << auxiliary.top() << " �� A � B" << endl;
            }
            else {
                destination.push(auxiliary.top());
                auxiliary.pop();
                cout << "����������� ���� " << destination.top() << " �� B � C" << endl;
            }
        }
        else if (i % 3 == 2) {
            if (!source.empty() && (destination.empty() || source.top() < destination.top())) {
                destination.push(source.top());
                source.pop();
                cout << "����������� ���� " << destination.top() << " �� A � C" << endl;
            }
            else {
                source.push(destination.top());
                destination.pop();
                cout << "����������� ���� " << source.top() << " �� C � A" << endl;
            }
        }
        else if (i % 3 == 0) {
            if (!destination.empty() && (auxiliary.empty() || destination.top() < auxiliary.top())) {
                auxiliary.push(destination.top());
                destination.pop();
                cout << "����������� ���� " << auxiliary.top() << " �� C �� B" << endl;
            }
            else {
                source.push(auxiliary.top());
                auxiliary.pop();
                cout << "����������� ���� " << source.top() << " �� B � A" << endl;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "������� ���������� ������: ";
    cin >> n;

    stack<int> source, destination, auxiliary;
    moveDisks(n, source, destination, auxiliary);

    return 0;
}

//�������� ��� ����� : �������� ����(��������� ��������� �����), ��������������� ����(��� ����������� ��������� ����� �������) � ������� ����(�������� ��������� �����).
//��������� �������� ���� N ����������(�� N �� 1, ��� N - ��� ���������� ������).
//����������� ���� ��� ���������� ��������� ��������, ���� ������� ���� �� ����� ��������� ��� N ������ :
//a.���� N ������, �� :
//    i.����������� ���� ����� �������� � ��������������� ������.
//    ii.����������� ���� ����� �������� � ������� ������.
//    iii.����������� ���� ����� ��������������� � ������� ������.
//    b.���� N ��������, �� :
//    i.����������� ���� ����� �������� � ������� ������.
//    ii.����������� ���� ����� �������� � ��������������� ������.
//    iii.����������� ���� ����� ��������������� � ������� ������.
//    ����� ������� ���� ����� ��������� ��� N ������, ������� ����� ���������.
