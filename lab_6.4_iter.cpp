#include <iostream> 
#include <iomanip> 
#include <time.h> 

using namespace std;

void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

void Print(int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << "a[" << setw(2) << i << " ] = " << a[i] << setw(7);
    cout << endl;
}

int Max(int* a, const int size)
{
    int max = a[0];
    for (int i = 1; i < size; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

int ProductBetweenZeros(int* a, const int size)
{
    int firstZero = -1, secondZero = -1;

    // 1-�� � 2-�� ������ ��������
    for (int i = 0; i < size; i++)
        if (a[i] == 0)
            if (firstZero == -1)
                firstZero = i;
            else {
                secondZero = i;
                break;
            }
    if (firstZero != -1 && secondZero != -1 && secondZero > firstZero + 1) {
        int product = 1;
        for (int i = firstZero + 1; i < secondZero; i++)
            product *= a[i];
        return product;
    }
    else
        return 0; // ���� ���� ���� ���� ��� �� ���� ���� ��������
}

void Sort(int* a, const int size)
{
    int* odd = new int[(size + 1) / 2]; // ����� ��� �������� �������
    int* even = new int[size / 2];      // ����� ��� ������ �������
    int oddIndex = 0, evenIndex = 0;

    for (int i = 0; i < size; i++)
        if (i % 2 == 0) // ������� �������
            odd[oddIndex++] = a[i];
        else // ����� �������
            even[evenIndex++] = a[i];

    // ��'������� ������: �������� ������, ���� ����
    for (int i = 0; i < oddIndex; i++)
        a[i] = odd[i];
    for (int i = 0; i < evenIndex; i++)
        a[oddIndex + i] = even[i];

    delete[] odd;
    delete[] even;
}

int main()
{
    srand((unsigned)time(NULL));

    int n = 0;
    cout << "Enter n: "; cin >> n;
    int* a = new int[n];

    int Low = -10;
    int High = 10;

    Create(a, n, Low, High);
    Print(a, n);

    Sort(a, n);
    cout << "Array after sorting: " << endl;
    Print(a, n);

    cout << "Max = " << Max(a, n) << endl;
    cout << "Product between first and second zero = " << ProductBetweenZeros(a, n) << endl;
    delete[] a;
    return 0;
}
