# Упражнение 5 - Циклични процеси. Видове циклични процеси. Контрол на изпълнението. Блок схеми.

## Съдържание
* Циклични процеси
	* Оператор WHILE
	* Оператор DO-WHILE
	* Оператор FOR
* Контрол на изпълнението
	* break
	* continue
	* goto
	* Кога се използват и защо да не прекаляваме с тяхното използване?
* Блок схеми

## Задача 1
Да се състави програма, която отпечатва първите 20 четни естествени числа.

## Задача 2
Да се състави програма, която отпечатва първите 13 числа от редицата на Фибоначи.

f<sub>1</sub> = 1

f<sub>2</sub> = 1

f<sub>n</sub> = f<sub>n-1</sub> + f<sub>n-2</sub>

## Задача 3
Да се състави програма, която отпечатва всички числа, които са квадрати на целочислени числа и сa по-малки от числото *n*, което се въвежда от клавиатурата.

```
Вход 1:
5

Изход 1:
1 4

Вход 2:
99

Изход 2:
1 4 9 16 25 36 49 64 81
```

## Задача 4
Да се състави програма, която въвежда от клавиатурата числа до срещане на '0' и извежда сумата им.

```
Вход:
1 2 4 12 1000 0

Изход:
1019
```

## Задача 5
Да се състави програма, която въвежда от клавиатурата числа до въвеждане на 0 и извежда броя на числата (без нулата).

```
Вход:
1 2 4 12 1000 0

Изход:
5
```

## Задача 6
Да се състави програма, която чете от клавиатурата цели числа до въвеждане на отрицателно число и извежда броя на въведените четни положителни числа.

```
Вход:
3 13 24 55 0 46 -8

Изход:
2
```

## Задача 7
Да се състави програма, която чете от клавиатурата целите числа *m* и *n*, *m* < *n*, и извежда на екрана всички цели числа в интервала \[m,n\], които се делят на 3.

```
Вход:
2 5

Изход:
3
```

## Задача 8
Да се състави програма, която прочита от клавиатурата цяло число *k* и след него последователност от числа, докато сумата им стане по-голяма или равна на *k* и извежда броя на въведените числа.

```
Вход:
10 2 4 5

Изход:
3
```

## Задача 9
На стандартния вход ще Ви бъде дадено едно цяло не отрицателно число. Намерете и изведете броят на цифрите му.

## Задача 10
На стандартния вход ще Ви бъде дадено едно цяло не отрицателно число. Обърнете редът на цифрите му и изведете числото което се получава.

Пример:
```
Вход:
15842

Изход:
24851
```

## Задача 11
На стандартния вход ще получите числото n и още n на брой числа - оценките от журито на участник в състезание по ски скокове. Оценката дадена от член на журито представлява цяло не отрицателно число. Журито се състои от n члена, като има поне три на брой члена (n>=3). С цел да се намали ефекта от подкупване на член на журито, от оценките се махат най-високата и най-ниската и на останалите се смята средно аритметично, което е и финалната оценка на състезателя. При дадените оценки, на стандартния вход трябва да изведете финалната оценка на състезателя с два знака след десетичната запетая, закръглена надолу (примерно 5.649 се закръгля на 5.64 независимо че цифрата 9 на хилядните е >=5).

Пример:
```
Вход:
5
4 2 7 9 6

Изход:
5.66
```

## Задача 12
На стандартния вход ще Ви бъде дадено цяло не отрицателно число. Кажете дали то е просто, като изведете "prime" ако е и "not prime" ако не е.

## Задача 13
На стандартния вход ще Ви бъде дадено числото n и още n цели не отрицателни числа. Намерете най-дългия последователен участък с еднакви числа и изведете неговата сума. Ако има няколко най-дълги, които са с еднаква дължина, то изведете първата срещната отляво надясно.

Пример:
```
Вход:
13
4 1 1 1 1 2 2 1 1 3 3 3 3

Изход:
4

```
**Обяснение на примера**: В примера имаме пет последователности от съседни еднакви числа. Една четворка, четири единици, две двойки, две единици, и четири тройки. Най-дъгите последователности са четирите единици и четирите тройки (в края), обаче от тях най-вляво са четирите единици. Заради това извеждаме тяхната сума.

## Задача 14
След като за поредна седмица нямате време да си научите за поредното теоретично тестче по Алгебра 1, започвате да си задавате въпроса, къде губите това време и колко е много от него наистина губите. Тогава се сещате за това, което всички приятели и колеги ви казват, а именно, че губите ужасно много време играейки на компютъра и то точно определена игра (която не е Лига). Затова решавате да проверите тяхната хипотеза.
Сещате се също, че точно тази определена игра (която 100% не е Лига), пази история затова кога сте играли на нея, но я пази под формата на интервали "hh:mm - hh:mm" където левият час е времето от което сте започнали да играете, а десният час е времето в което сте приключили (левият интервал е затворен (включително левия час и минута), а десния е отворен („невключително“ десния час и минута)). Възможно е да сте започнали да играете повторно играта точно тогава, когато сте приключили предишния път, нека илюстрираме това с пример: "13:00 - 13:45" и веднага след това "13:45 - 14:00", като в конкретния пример, що се отнася до времетраене, може да се каже че е еквивалентно на единичния интервал "13:00 - 14:00". Ако започнете да се играете по-рано като час, от часа в който предишния път сте спрели да играете, то тогава приемете, че сте започнали да играете точно на следващия ден и също приемете, че в дадения ви интервал няма и един ден в който не сте играли. Никоя последователна сесия от игране не продължава повече от 12. часа. Ако левият ви час е по-късен от колкото е десния, то тогава приемете, че просто сте започнали последователната игрална сесия в един ден и сте я приключили на следващия. Знаейки тази информация искате да изчислите часовете и минутите, които губите по тази игра средно на ден.

**Ограничения**:
Времената са в 24 часов формат.
Една „игрална сесия“ не продължава повече от 12 часа.
Няма ден в който да не сте играли.

**Вход**: На стандартния ви вход ще ви бъде дадено едно цяло не отрицателно число n. На последващите n реда ще имате интервали в формата "hh:mm - hh:mm" - началото и краят на една „последователната игрална сесия“. Игралните сесии ще Ви бъдат дадени в хронологичен ред, от най-старата към най-новата.

**Изход**: На стандартния изход трябва да изведете две числа - часовете и минутите (закръглени надолу) които редно на ден губите по тази игра изведени в формата "hh:mm".

Пример:
```
Вход:
6
14:30 - 15:15
15:55 - 16:20
12:30 - 12:45
23:30 - 00:30
17:20 - 17:40
17:40 - 18:20

Изход:
01:08
```

**Обяснение на примера:**
Играли сте в продължителност на три дена:
- Първият ден сте направили две последователни игрални сесии: `14:30 - 15:15` и `15:55 - 16:20` - с общо игрално време 70 мин.
- Вторият ден - една и част от друга : `12:30 - 12:45` и `23:30 - 00:30` - 45 мин. (не броим последния половин час от втората сесия за този ден)
- Третият ден - част от една и още две: `23:30 - 00:30`, `17:20 - 17:40` и `17:40 - 18:20` - 90 мин. (не броим първия половин час от първата сесия за този ден)
Общо излиза 205 мин. за 3 дена, което прави 1 час и 8 мин на ден.

## Задача 15
На стандартния вход ще Ви бъдат дадени две цели не отрицателни числа a и b и цифрата d. Изведете на стандартния изход колко цифри d ще напишете, за да изпишете всички числа в интервала \[a, b\].

Пример:
```
Вход:
1 100 1

Изход:
21
```

## Задача 16
На стандартния вход ще Ви бъдат дадени целите не отрицателни числа a, b, c и d. Изведете всички възможни тройки не отрицателни цели числа (x, y, z), които удовлетворяват уравнението: `a*x + b*y + c*z = d`.

Пример:
```
Вход:
6 3 8 24

Изход:
0 0 3
0 8 0
1 6 0
2 4 0
3 2 0
4 0 0
```

## Задача 17
На стандартния вход ще Ви бъде дадено не отрицателно цяло нечетно число n, n>=3. На стандартния изход трябва да изведете съответната снежинка с размери n на n.

Пример:
```
Вход:
9

Изход:
*...*...*
.*..*..*.
..*.*.*..
...***...
*********
...***...
..*.*.*..
.*..*..*.
*...*...*
```