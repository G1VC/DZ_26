// Potok4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

using namespace std;
#include <iostream>
#include <thread>
#include <ctime>
#include <cstdlib>



static int sum = 0;
static int sum1 = 0;
static int sum2 = 0;
static int sum3 = 0;
static int sum0 = 0;
void add(int n1, int n2, int myArray[]) {
    for (int i = n1; i < n2 + 1; i++) {
        sum = myArray[i] + sum;
    }
}

void add1(int n1, int n2, int myArray[]) {
    for (int i = n1; i < n2 + 1; i++) {
        sum1 = myArray[i] + sum1;
    }

}
void add2(int n1, int n2, int myArray[]) {
    for (int i = n1; i < n2 + 1; i++) {
        sum2 = myArray[i] + sum2;
    }
}

void add3(int n1, int n2, int myArray[]) {
    for (int i = n1; i < n2 + 1; i++) {
        sum3 = myArray[i] + sum3;
    }
}

void add0(int n1, int n2, int myArray[]) {
    for (int i = n1; i < n2 + 1; i++) {
        sum0 = myArray[i] + sum0;
    }
}


int main()
{
    setlocale(LC_ALL, "");

    // Инициализация генератора случайных чисел
   //std::srand(std::time(nullptr));
    int N_arr = 1000000;
    // Создание массива
    int myArray[999999];
    // Генерация случайных чисел и заполнение массива
    for (int i = 0; i < N_arr; ++i) {
        myArray[i] = rand() % 9 + 1;
    }
    // int myArray[] = {1, 2, 3, 4, 5,6,7,8,9,10,11,12};
   //Расчёт суммы элементов сгенерированного   массива четырьмя потоками
    clock_t t1, t2, t3;
    t1 = std::clock(); // Метка 1-начала расчёта
    int n1 = 0; int n2 = N_arr / 4 - 1;
    std::thread th1(add, n1, n2, myArray);

    n1 = N_arr / 4; n2 = N_arr / 2 - 1;
    std::thread th2(add1, n1, n2, myArray);

    n1 = N_arr / 2; n2 = N_arr * 3 / 4 - 1;
    std::thread th3(add2, n1, n2, myArray);

    n1 = N_arr * 3 / 4; n2 = N_arr - 1;
    std::thread th4(add3, n1, n2, myArray);
    th1.join();
    th2.join();
    th3.join();
    th4.join();
    std::cout << "Расчёт суммы элементов сгенерированного   массива с помощью четырёх потоков" << std::endl;
    std::cout << "potokovaya Sum1 = " << sum << std::endl;
    std::cout << "potokovaya Sum2 = " << sum1 << std::endl;
    std::cout << "potokovaya Sum3 = " << sum2 << std::endl;
    std::cout << "potokovaya Sum4 = " << sum3 << std::endl;
    std::cout << "*** Summa elementov massiva = " << sum + sum1 + sum2 + sum3 << std::endl;
    t2 = std::clock(); // Метка 2-конца расчёта
    std::cout << "t1 = " << t1 << std::endl;
    std::cout << "t2 = " << t2 << std::endl;
    t3 = t2 - t1; // Разница между меткамиcalculation time
    std::cout << "t3 = " << t3 << std::endl;
    std::cout << "calculation time = " << ((double)t3 / CLOCKS_PER_SEC) << " sec." << std::endl;
    //Расчёт суммы элементов сгенерированного выше массива одним потоком
    std::cout << "Расчёт суммы элементов этого же  массива одним потоком" << std::endl;
    clock_t t4, t5, t6;
    t4 = std::clock(); // Метка начала расчёта
    n1 = 0; n2 = N_arr - 1;
    std::thread th5(add0, n1, n2, myArray);
    th5.join();
    //th5.join();
    std::cout << "Summa = " << sum0 << std::endl;
    t5 = std::clock(); // Метка конца расчёта
    std::cout << "t1 = " << t4 << std::endl;
    std::cout << "t2 = " << t5 << std::endl;
    t6 = t5 - t4; // Разница между метками-calculation time
    std::cout << "t3 = " << t6 << std::endl;
    std::cout << "calculation time = " << ((double)t6 / CLOCKS_PER_SEC) << " sec." << std::endl;

    return 0;
}
