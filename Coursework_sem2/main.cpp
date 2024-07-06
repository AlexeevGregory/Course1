#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include<chrono>
using namespace std;
using namespace chrono;
struct avl_node{
    int data;
    struct avl_node* left;
    struct avl_node* right;
}*root;

class avlTree{
public:
    int height(avl_node*);
    int diff(avl_node*);
    avl_node* rr_rotation(avl_node*);
    avl_node* ll_rotation(avl_node*);
    avl_node* lr_rotation(avl_node*);
    avl_node* rl_rotation(avl_node*);
    avl_node* balance(avl_node*);
    void Checkbalance(avl_node*);
    avl_node* insert(avl_node*, int);
    avl_node* DeleteElem(avl_node*, int);
    avl_node* FindElem(avl_node*, int);
    void display(avl_node*, int);
    void inorder(avl_node*);
    void preorder(avl_node*);
    void postorder(avl_node*);
    //avl_node* BalancedInsert(avl_node*, int);
    avlTree()
    {
        root = NULL;
    }
};
int main()
{
    setlocale(0, "");
    int choice, item, count = 0, size, *arr = 0, n;
    string str, str1;
    avlTree avl;
    auto start = steady_clock::now();
    auto end = steady_clock::now();
    auto result = duration_cast<nanoseconds>(end - start);
    while (1)
    {
        cout << "\n------------------------------------------------------" << endl;
        cout << "Меню:" << endl;
        cout << "1.Формирование АВЛ дерева" << endl;
        cout << "2.Отображение АВЛ дерева" << endl;
        cout << "3.Определение скорости удаления/добавления/получения элемента дерева" << endl;
        cout << "4.Проверка на сбалансированность дерева" << endl;
        cout << "5.Балансировка дерева" << endl;
        cout << "6.Выход" << endl;
        cout << "Введите число: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Меню" << endl;
            cout << "1. Ввод количества элементов, значение которых сгенерировано случайно" << endl << "2. Ввод чисел через строку" << endl << "Введите число: ";
            cin >> choice;
            switch (choice)
            {
            case(1):
                cout << "Введите число(количество элементов): ";
                cin >> n;
                start = steady_clock::now();
                while (count < n) {
                    item = rand() % 198 - 100;
                    root = avl.insert(root, item);
                    count++;
                }
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                cout << "Время на создание дерева: " << result.count() << "наносекунд";
                cout << endl << endl;
                break;
            case(2):
                cout << "Введите числа: ";
                cin.get();
                getline(cin, str);
                for (int i = 0; i < str.length(); i++) {
                    if (str[i] == ' ') count++;
                }
                size = ++count;
                arr = new int[size];
                count = 0;
                for (int i = 0; i < str.length(); i++) {
                    if (str[i] != ' ') { str1 += str[i]; }
                    if (i == str.length() - 1) { arr[count] = stoi(str1); count++; str1 = " "; }
                    if (str[i] == ' ') { arr[count] = stoi(str1); count++; str1 = " "; }
                }
                start = steady_clock::now();
                for (int i = 0; i < size; ++i) {
                    item = arr[i];
                    root = avl.insert(root, item);
                }
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                cout << "Время на создание дерева: " << result.count() << "наносекунд";
                cout << endl << endl;
                break;
            default:
                cout << "Неправильно введено число" << endl;
                break;
            }
            break;
        case 2:
            if (root == NULL)
            {
                cout << "Дерево пустое" << endl;
                continue;
            }
            cout << "Авл дерево:" << endl;
            avl.display(root, 1);
            break;
        case 3:
            if (root == NULL)
            {
                cout << "Дерево пустое" << endl;
                continue;
            }
            cout << "\n------------------------------------------------------" << endl;
            cout << "Меню:" << endl;
            cout << "1.Определение скорости удаления элемента дерева" << endl << "2.Определение скорости добавления элемента дерева" << endl << "3.Определение скорости поиска элемента дерева" << endl << "Введите число: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "Введите значение элемента: ";
                cin >> item;
                start = steady_clock::now();
                root = avl.DeleteElem(root, item);
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                cout << "Время, потраченное на удаление элемента: " << result.count() << "наносекунд" << endl;
                break;
            case 2:
                cout << "Введите значение элемента: ";
                cin >> item;
                start = steady_clock::now();
                root = avl.insert(root, item);
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                cout << "Время, потраченное на добавление элемента: " << result.count() << "наносекунд" << endl;
                break;
            case 3:
                cout << "Введите значение элемента: ";
                cin >> item;
                start = steady_clock::now();
                root = avl.FindElem(root, item);
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                cout << "Время, потраченное на поиск элемента: " << result.count() << "наносекунд" << endl;
                break;
            default:
                cout << "Неправильно введено число" << endl;
                break;
            }
            cout << endl;
            break;
        case 4:
            avl.Checkbalance(root);
            cout << endl;
            break;
        case 5:
            root = avl.balance(root);
            break;
        case 6:
            exit(1);
            break;
        default:
            cout << "Неправильно введено число" << endl;
        }
    }
    return 0;
}
// Высота АВЛ дерева
int avlTree::height(avl_node* temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height(temp->left);
        int r_height = height(temp->right);
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}
// Разница в высоте
int avlTree::diff(avl_node* temp)
{
    int l_height = height(temp->left);
    int r_height = height(temp->right);
    int b_factor = l_height - r_height;
    return b_factor;
}
// Малый правый поворот
avl_node* avlTree::rr_rotation(avl_node* parent)
{
    avl_node* temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}
// Малый левый поворот
avl_node* avlTree::ll_rotation(avl_node* parent)
{
    avl_node* temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}
// Большой левый поворот
avl_node* avlTree::lr_rotation(avl_node* parent)
{
    avl_node* temp;
    temp = parent->left;
    parent->left = rr_rotation(temp);
    return ll_rotation(parent);
}
// Большой правый поворот
avl_node* avlTree::rl_rotation(avl_node* parent)
{
    avl_node* temp;
    temp = parent->right;
    parent->right = ll_rotation(temp);
    return rr_rotation(parent);
}
// Балансировка АВЛ дерева
avl_node* avlTree::balance(avl_node* temp)
{
    int bal_factor = diff(temp);
    if (bal_factor > 1)
    {
        if (diff(temp->left) > 0)
            temp = ll_rotation(temp);
        else
            temp = lr_rotation(temp);
    }
    else if (bal_factor < -1)
    {
        if (diff(temp->right) > 0)
            temp = rl_rotation(temp);
        else
            temp = rr_rotation(temp);
    }
    return temp;
}
// Проверка на сбалансированность АВЛ дерева
void avlTree::Checkbalance(avl_node* temp)
{
    int bal_factor = diff(temp);
    if (bal_factor > 1)
    {
        cout << "Дерево несбалансировано" << endl;
    }
    else if (bal_factor < -1)
    {
        cout << "Дерево несбалансировано" << endl;
    }
    else {
        cout << "Дерево сбалансировано" << endl;
    }
}
// Добавление элемента в дерево
avl_node* avlTree::insert(avl_node* root, int value)
{
    if (root == NULL)
    {
        root = new avl_node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value >= root->data)
    {
        root->right = insert(root->right, value);
    }
    return root;
}
// Вывод АВЛ дерева
void avlTree::display(avl_node* ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level + 1);
        cout << endl;
        if (ptr == root) {
            cout << "Root -> ";
        }
        for (i = 0; i < level && ptr != root; i++)
            cout << "        ";
        cout << ptr->data;
        display(ptr->left, level + 1);
    }
}
// Симметричный обход в АВЛ дереве
void avlTree::inorder(avl_node* tree)
{
    if (tree == NULL)
        return;
    inorder(tree->left);
    cout << tree->data << "  ";
    inorder(tree->right);
}
// Прямой обход в АВЛ дереве
void avlTree::preorder(avl_node* tree)
{
    if (tree == NULL)
        return;
    cout << tree->data << "  ";
    preorder(tree->left);
    preorder(tree->right);
}
//  Обратный обход в АВЛ дереве
void avlTree::postorder(avl_node* tree)
{
    if (tree == NULL)
        return;
    postorder(tree->left);
    postorder(tree->right);
    cout << tree->data << "  ";
}
// Функция удаления узла дерева по значению
avl_node* avlTree::DeleteElem(avl_node* root, int value) {
    if (root == nullptr) {
        return root;
    }
    if (value < root->data) {
        root->left = DeleteElem(root->left, value);
    }
    else if (value > root->data) {
        root->right = DeleteElem(root->right, value);
    }
    else if(value == root->data) {
        // Узел со значением value найден
        if (root->left == nullptr) {
            avl_node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            avl_node* temp = root->left;
            delete root;
            return temp;
        }
        // Узел имеет двух потомков: находится следующий по значению узел в правом поддереве
        avl_node* temp = root->right;
        while (temp->left != nullptr) {
            temp = temp->left;
        }

        root->data = temp->data;
        root->right = DeleteElem(root->right, temp->data);
    }
    else {
        cout << "Элемента с данным значением нет в дереве" << endl;
    }
    return root;
}
avl_node* avlTree::FindElem(avl_node* root, int value) {
    if (root == nullptr) {
        return root;
    }
    if (value < root->data) {
        root->left = FindElem(root->left, value);
    }
    else if (value > root->data) {
        root->right = FindElem(root->right, value);
    }
    else if (value == root->data) {
        cout << "Элемент присутствует в дереве" << endl;
    }
    else {
        cout << "Элемента с данным значением нет в дереве" << endl;
    }
    return root;
}
// Добавление элемента в дерево с балансировкой
/*avl_node* avlTree::BalancedInsert(avl_node* root, int value)
{
    if (root == NULL)
    {
        root = new avl_node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
        root = balance(root);
    }
    else if (value >= root->data)
    {
        root->right = insert(root->right, value);
        root = balance(root);
    }
    return root;
}*/