# Упражнение 8 - Многомерни масиви

## Съдържание
* Какво е многомерен масив?
* Дефиниране и достъпване на многомерен масив

## Задача 1:
Имате предварително въведени стойности от естествени числа, принадлежащи на интервала `[10..99]`. Числата са въведени в квадратна таблица с размери 6 реда и 6 колони. Да се състави програма, чрез която се намира и извежда сумата на всички елементи за всяка колона с нечетен номер: 1, 3 и 5. Програмата да извежда и общата сума на всички колони.

```
int input[N][N] = {
	{11, 12, 13, 14, 15, 16}, 
	{21, 22, 23, 24, 25, 26}, 
	{31, 32, 33, 34, 35, 36}, 
	{41, 42, 43, 44, 45, 46}, 
	{51, 52, 53, 54, 55, 56}, 
	{61, 62, 63, 64, 65, 66}
};

Изход:
Row 1 sum is: 216 (сума от елементите 11, 21, 31, 41, 51, 61)
Row 3 sum is: 228 (сума от елементите 13, 23, 33, 43, 53, 63)
Row 5 sum is: 240 (сума от елементите 15, 25, 35, 45, 55, 65)
Total sum is: 684 (сума на елементите)
```

## Задача 2:
Да се напише програма, която въвежда квадратна матрица с размери *n* x *n*  от цели числа и използва функция, за да провери дали матрицата е "магически квадрат" (сумите по редовете и стълбовете да са равни).

```
Вход1:
3
1 1 1
1 1 1
1 1 1

Изход1:
Magic

Вход2:
3
1 2 3
3 2 1
2 3 1

Изход2:
Normal
```

## Задача 3
Транспонирайте матрица *NxN* (*N* въведено от клавиатурата). Операцията транспониране представлява първия ред на дадена матрица да стане първа колона, втория ред на матрицата да стане втора колона и така всички редове да станат колони (a<sub>i,j</sub> -> a<sub>j,i</sub>)

```
Вход:
3
1 2 3
4 5 6
7 8 9

Изход:
1 4 7
2 5 8
3 6 9
```

## Задача 4
Да се напише функция, която проверява дали в квадратна матрица *NxN* има диагонал (прав или обратен, не задължително главен), по който всички елементи са различни.

```
Вход:
1 2 3 	
2 1 4
1 4 3  	

Изход:	
True 	
```

**Обяснение:**

2,4 са диагонал и са различни числа 	

## Задача 5
Да се напише програма, която умножава матриците A(nxm) и B(mxk), където 1 <= n <= 20, 1 <= m <= 30 и 1 <= k <= 40.

## Задача 6
На стандартния вход ще Ви бъде подадено естественото число k и на следващия ред изречение с не повече от 1024 символа, завършващо с нов ред. Вашата задача е да намерите броят на думите с дължина k. За улеснение може да приемете, че под дума се разбира всяка последователност от не whitespace символи. Дали символ е whitespace може да проверите с помощта на std::isspace (не е най-добрият вариант, но да кажем, че за задачата е ОК).

```
Вход:
4
Lorem ipsum dolor sit amet consectetur adipiscing elit Pellentesque vestibulum nibh ut porta semper Suspendisse dapibus efficitur nulla Curabitur mauris ante ultricies id hendrerit nec euismod efficitur erat

Изход:
5
```

**Обяснение на примера:** 

Думите с по 4 букви (в реда на срещането им) са : amet, elit, nibh, ante, erat.

## Задача 7
На стандартния вход ще Ви бъде подадено изречение с не повече от 1024 символа, завършващо с нов ред. Вашата задача е замените цифрите (от 0 до 9) от такива записани като текст в такива записани с цифри:

```
Вход:
Two number nines, a number nine large, a number six with extra dip, a number seven, and a large soda.eight

Изход:
2 number 9s, a number 9 large, a number 6 with extra dip, a number 7, and a large soda.8
```

## Задача 8
При дадена матрица NxN (N не повече от 31) намерете сумата от числата по всички диагонали успоредни на вторичния диагонал.

```
Вход:
4
1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16

Изход:
4 11 21 34 30 23 13
```

**Обяснение на примера:**

Диагоналите са:
4 = 4
3 + 8 = 11
2 + 7 + 12 = 21
1 + 6 + 11 + 16 = 34
5 + 10 + 15 = 30
9 + 14 = 23
13 = 13

## Задача 9
При дадена матрица NxN (N не повече от 31) намерете позициите (като двойки ред и колона) които представляват най-голямата стойност за реда и най-малката стойност за колоната в която се намират.

```
Вход:
4
2 1 4 1
3 1 3 2
3 3 4 3
3 3 3 3

Изход:
1 2
3 2
```

**Обяснение на примера:**

На позиция 1 2 (започвайки броенето от 0) стои числото 3. Ако разгледаме ред 1, ще видим, че най-голямата стойност в него е точно 3. Ако се загледаме в колона 2, ще забележим, че най-малкото число е числото 3.
Същото може да се каже и за позиция 3 2.
