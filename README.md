# DZ_26
Учебный
Задача:  подсчёт суммы элементов массива несколькими потоками.

Массив случайных чисел размером N должен разбиваться на 4 равных частей , каждая из которых выполняется в отдельном потоке.
Каждый поток вычисляет сумму элементов своей части.
По завершении выполнения потоков, вычисляется общая сумма массива.
Входные переменные:

  N =1000000 размер массива;

  M =4 количество частей, на которые будет разбит массив.

Результат:
1)сумма элементов массива определённая расчётом в 4-х потоках.
2)сумма элементов массива определённая в одном потоке
- 
3)определяется время каждого рачёта
