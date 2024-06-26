

Вариант 14

Разработать класс "стек параметров" в соответствии со следующим заданием:

    Состояние класса - стек параметров представляется в виде вектора (массива). Параметром стека могут быть данные сложного типа, например, первое поле число, второе поле строка символов фиксированной длины. Для описания параметра стека целесообразно использовать структуру. Память под массив выделяется статически, во время компиляции, и задается массивом фиксированного размера. 
    
    Протокол класса - Определяет возможности создания и инициализации экземпляров класса и правила их использования (методы класса).

Предусмотреть следующие возможности:

    Создание экземпляров структуры (параметра) с инициализацией начальным состоянием по умолчанию;

    Пустой конструктор для инициализации экземпляров и массивов экземпляров класса (стека) по умолчанию;

    Создание экземпляров класса (стека) с инициализацией заданным количеством параметров из массива параметров;

    Ввод значения экземпляров структуры (параметра) из входного потока;

    Ввод (добавление) параметра в стек из входного потока;

    Вывод значения параметра соответствующего типа в выходной поток;

    Вывод содержимого стека в выходной поток;

    Добавление параметра, заданного переменной, в стек;

    Выборка параметра из стека – копирование параметра в переменную соответствующего типа с удалением из стека;

    Проверка состояния стека (пуст, частично заполнен или полон).

Проектирование класса рекомендуется начать с представления состояния класса, учитывающего заданные операции, а затем реализации конструкторов и метода вывода. Для отладки и исчерпывающего тестирования других методов разработанного класса реализовать диалоговую программу, которая позволяет вводить параметры отлаживаемых методов. Для обработки ошибочных ситуаций использовать механизм исключительных ситуаций.

Повторить разработку класса, реализовав отдельные методы (там, где это оправданно), перегруженными операторами. Состав перегруженных операторов целесообразно согласовать с преподавателем.

Еще раз повторить разработку класса при условии, что память под массив необходимой длины выделяется динамически, во время выполнения программы (с помощью оператора new; память задается указателем на char в состоянии класса). Для хранения данных в экземпляре класса не должна использоваться лишняя память.

Дополнить интерфейс класса следующими возможностями:

    Создание экземпляра класса с его инициализацией другим экземпляром класса (копирующий конструктор);

    Переопределение экземпляра класса (с помощью перегруженного оператора присваивания).

Разработать и реализовать прикладную программу, использующую класс, разработанный другим студентом. Задание для прикладной программы разработать самостоятельно и согласовать с преподавателем.
