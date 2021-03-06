# Упражнение 10 - Памет и указатели. Динамична памет.

## Съдържание

* Памет. Видове памет за една програма.
	* Регистрова
	* Статична
	* Автоматична(Стекова)
	* Динамична
* Указатели - адрес и тип.
* Декларация на указатели
* Указатели и константи
	* Константен указател - int * const ptr
		* не може да променяме указателя, но може да променяме данните
	* Указател към константа - const int * ptr или int const * ptr 
		* можем да променяме указателя, но не и данните
	* Константен указател към константа - const int * const ptr
		* не можем да променяме нито данните, нито указателя
* Основни операции с указатели
	* Извличане на адрес(оператор &)
	* Извличане на стойност(оператор *)
	* Сравняване на адреси(оператори == и !=)
	* Индексиране(оператор [])
* Адресна аритметика с указатели
	* Сравнение (<, <=, >, >=)
	* Аритметика с число (+, -, +=, -=)
	* Инкрементиране (++, --)
	* Разлика на указатели ( - )
	* Преобразуване на типове
* Указатели и типове
	*  void *
	* Преобразуване между типове
	* Указатели и числа
	* NULL и nullptr – разлики и приложения
*Динамична памет - new/delete и правила за работа с динамична памет

## Задача 1

Да се напише функция, която разменя стойностите на две реални числа.

## Задача 2

Създайте функция int * createArray(int size), която създава масив от естествени числа по въведена от клавиатурата стойност n и връща указател към първия елемент. После принтирайте масива в int main().

## Задача 3

Да се състави програма, чрез която в едномерен масив се въвеждат естествени цели числа от клавиатурата. Размерът на масива да се въвежда от клавиатурата и да се заделя динамично памет за него. Програмата да изведе общата сума на въведените числа, най-малкото и най-голямото число.

```
Вход:
7
89 -123 45 19 1204 0 112

Изход:
1346 -123 1204
```

## Задача 4

Създайте с динамична памет символен масив, както и функция, която слепва два символни масива.

```
Пример: startWord = "pesho", addedWord = " is cool" -> "pesho is cool"
```

## Задача 5

Да се състави програма, в която се въвеждат естествени цели числа от клавиатурата. Размерът на масива да се въвежда от клавиатурата и да се заделя динамично памет за него. Програмата да разменя симетричните елементи спрямо средата като по-малкото число остава в началото на масива, а по-голямото в края.

```
Вход:
7
189 123 145 196 1204 0 112

Изход:
112 0 145 196 1204 123 189
```

## Задача 6

Да се състави програма, която прочита n естествени числа от клавиатурата, заделяйки динамична памет за тях, сортира ги в нарастващ ред и ги отпечатва. Всяко от действията да бъде отделна функция.

```
Вход:
7
189 123 145 196 1000 0 112

Изход:
0 112 123 145 189 196 1204
```

## Задача 7

Да се състави програма, която прочита число n и заделя памет за двумерен масив с намаляващ брой елементи на редовете (виж примера), популира масива с числа и го отпечатва накрая. Да бъде заделена точно толкова памет, котлкот са числата в съответния ред. Съвет: използвайте функцията от задачка 1.

```
Вход:
5

Изход:
1 2 3 4 5 1 2 3 4 1 2 3 1 2 1
```

## Задача 8
Запишете следните типове, както биха били записани в C++:
 - Масив с размер 16 от константни указателя от тип int.
 - Масив с размер 4 от масив с размер 64 от тип const int.
 - Указател от масив с 24 променливи от тип const int.
 - Указател от масив с 8 променливи от масив с 16 променливи от тип int.

Ето и няколко по-екстремни случаи:
 - Указател от константен указател от масив с 24 променливи от тип int.
 - Указател от масив с 8 променливи от указател от масив с 32 променливи от тип int.

HINTS:
```
http://c-faq.com/decl/spiral.anderson.html
https://stackoverflow.com/questions/1136146/how-would-you-declare-a-two-dimensional-array-of-pointers-in-c (Първият отговор има добри примери)
```

## Задача 9
Отгатнете типът на `expr` в `DECUCE_TYPE(expr)` в следните примери:
(Ако в expr получавате масив, кажете типът след array to pointer decay)

```cpp
const int a[10];
DEDUCE_TYPE(a);
```

```cpp
const int b[10][20];
DEDUCE_TYPE(b);
```

```cpp
const int *c[10][30];
DEDUCE_TYPE(c[3]);
```

```cpp
const int (*d)[10][30];
DEDUCE_TYPE(d);
```

```cpp
const int * const e[10][30];
DEDUCE_TYPE(e[5]);
```

```cpp
const int * const *f[10][30];
DEDUCE_TYPE(f);
```

## Задача 10

Имате даден масив int arr[N][M]. Създайте масив от указатели от тип int arr2 с размер N и на всеки елемент от arr2 запишете указател към съответният ред от arr. Разберете каква е разликата между arr и arr2.

## Задача 11

Напишете функцията `void my_sort (int *beg, int *end)`, която по дадени начало и край на масив, сортира масива.

Примерна употреба:
```cpp
int arr[7] = {4, 7, 5, 4, 8, 2, 1};
my_sort(arr, arr+7);
// тук трябва: arr = {1, 2, 4, 4, 5, 7, 8};
```

## Задача 12

Напишете функцията `bool my_binary_search (int *beg, int *end, int val)`, която по дадени начало и край на масив и стойност проверява дали стойността се среща в масива.

Примерна употреба:
```cpp
int arr[7] = {4, 7, 5, 4, 8, 2, 1};
my_sort(arr, arr+7);
// тук трябва: arr = {1, 2, 4, 4, 5, 7, 8};
assert(my_binary_search(arr, arr+7, 3) == false);
assert(my_binary_search(arr, arr+7, 8) == true);
```
