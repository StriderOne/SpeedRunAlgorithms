#include <iostream>
#include <algorithm>

using namespace std;

struct Cable {
    int from, to, length;

    bool operator< (const Cable& other) {
        return length < other.length;
    }
};

class DisjointSetUnion {

    private: pair<int, int>* nodes;

    public:
        DisjointSetUnion(int size) {
            nodes = new pair<int, int>[size + 1];
            for (int i = 1; i <= size; i++) nodes[i] = {0, i};
        }

        int findRoot(int a) {
            if (a != nodes[a].second) nodes[a].second = findRoot(nodes[a].second);
            return nodes[a].second;
        }

        void merge(int a, int b) {
            if (nodes[a].first > nodes[b].first) nodes[b].second = a;
            else {
                nodes[a].second = b;
                if (nodes[a].first == nodes[b].first) nodes[b].first++;
            }
        }
};

int main() {
    int n, m, maxLength = 0;
    cin >> n >> m;
    Cable cables[m];
    for (int i = 0; i < m; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        cables[i] = {a, b, l};
    }
    sort(cables, cables + m); //передаём сортировке указатели на начало и конец массива
    DisjointSetUnion* dsu = new DisjointSetUnion(n);
    for (int i = 0; i < m; i++) {
        int from = cables[i].from;
        int to = cables[i].to;
        if (dsu->findRoot(from) != dsu->findRoot(to)) {
            if (cables[i].length > maxLength) maxLength = cables[i].length;
            cables[i].length *= -1;
            dsu->merge(dsu->findRoot(from), dsu->findRoot(to));
        }
    }
    cout << maxLength << "\n" << n - 1 << "\n";
    for (Cable c: cables) if (c.length < 0) cout << c.from << " " << c.to << "\n";
    return 0;
}

/*
Задача о нахождении минимального оставного дерева в графе, где вершинами будут 
выступать хабы, а провода - рёбрами графа. Необходимо пройти через все вершины 
так, чтобы сумма рёбер была минимальной. На выбор для реализации есть три известных 
алгоритма: Прима, Краскала и Буровки. Реализуем Краскала. Принцип работы таков: 
алгоритм изначального помещает все ребра графа G = (V, E) в собственное дерево, 
затем объединяя на два некоторых дерева ребром e = {u, v}. Изначально все рёбра 
сортируются по весу в порядке неубывания - если у текущего ребра его концы принадлежат 
разным поддеревьям, то эти поддеревья объединяются. По окончании перебора все V 
окажутся принадлежащими одному поддереву, и ответ найден. Cable отвечает за удобное 
хранение рёбер. Их сортировка потребует O(log(N)) операций, если использовать алгоритм 
из стандартной библиотеки C++. Затем нужно проверять соединяет ли ребро две 
различных компоненты связности графа. Эффективно реализовать это можно с помощью 
структуры данных DisjointSetUnion (Система непересекающихся множеств), создадим 
отдельный класс для работы с ней. Объединять компоненты связности будем методом 
merge(int a, int b), а проверять, находятся ли разные вершины графа в разных 
деревьях (т.е. компонентах связности) методом findRoot(int a). Для описания 
множества используется номер вершины, являющейся корнем соответствующего дерева. 
Для определения, принадлежат ли два элемента к одному и тому же множеству, для 
каждого элемента нужно найти корень соответствующего дерева (поднимаясь вверх 
пока это возможно) и сравнить эти корни. Объединяются множества так: пусть нам 
нужно объединить множества с корнями a и b. Просто присвоим p[a]=b, (где p - 
массив, хранящий прямого предка для каждой вершины), тем самым подвесив всё 
дерево a к корню дерева b. Можно заметить, что при такой реализации при постепенном 
объединении деревьев глубина будет расти вплоть до N. Применим несколько оптимизаций 
к структуре:
1. Ранги вершин: будем хранить для всех деревьев текущую глубину, и при объединении 
подвешивать дерево с меньшей глубиной к корню дерева с большей глубиной 
(в действительности, ранг вершины описывают не точную глубину дерева, а её верхнюю 
границу, но это не играет роли).
2. Сжатие путей: при поиске корня заданной вершины будем переподвешивать её за 
найденный корень. К примеру, мы вызвали findRoot для вершины, которую отделяют от 
корня дерева пять других вершин. Рекурсивный вызов функции обойдёт каждую из них, 
и найдёт корень. На выходе из каждого рекурсивного вызова обновим текущую вершину 
только что найденным корнем. Таким образом, все пять вершин теперь будут подвешены 
напрямую к корню.
P.S. В моей реализации объединим массивы p и массив рангов в массив объектов pair.
В конце выведем ответ. Максимальную длину рёбра можно было получить во время прохода 
по массиву рёбер, количество рёбер, соединяющих все точки будет равняться (n- 1), 
для любого количества точек (это можно заметить эмпирическим путём), а также выведем 
все рёбра, у которых длина > 0, так как во время вышеописанного цикла, необходимо 
отмечать уже использованные в графе рёбра - для этого можно просто менять знак веса 
ребра на противоположный.
*/