#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;
map <string, int> weight = { {"+", 0 },
                             {"-", 0 },
                             {"*", 1 },
                             {"/", 1 },
                             {"(", 0 },
                             {")", 2 } };
string ArrInt = "0123456789";
typedef struct Stack {
    string value = "";
    struct Stack* next = 0;
} Stack;

Stack* getLast(Stack* head) {
    if (head == NULL) {
        return NULL;
    }
    while (head->next) {
        head = head->next;
    }
    return head;
}
void AddElementStack(Stack** head, string data) {
    Stack* tmp = new Stack;
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}
void AddElementEndStack(Stack* head, string value) {
    Stack* last = getLast(head);
    Stack* tmp = new Stack;
    tmp->value = value;
    tmp->next = NULL;
    last->next = tmp;
}
void StackNewElement(Stack*& Stack, const string& value) {
    if (!Stack)
        AddElementStack(&Stack, value);
    else
        AddElementEndStack(Stack, value);
}
string CountStackEndElement(Stack** head) {
    Stack* prev = NULL;
    string val;
    if (head == NULL) {
        exit(-1); // считано все выражение - окончание работы
    }
    prev = (*head);
    val = prev->value;
    (*head) = (*head)->next;
    delete prev;
    return val;
}
int SizeStack(Stack* head) {
    int count = 0;
    if (head != nullptr) {
        while (head) {
            count++;
            head = head->next;
        }
    }
    return count;
}
//Когда в стеке более 2-х элементов
Stack* getLastButOne(Stack* head) {
    if (head == NULL) {
        exit(-2);
    }
    if (head->next == NULL) {
        return NULL;
    }
    while (head->next->next) {
        head = head->next;
    }
    return head;
}
string CountEndElement(Stack** head) {
    string value;
    Stack* lastbn = NULL;
    //Получили NULL
    if (!head) {
        exit(-1);
    }
    //Список пуст
    if (!(*head)) {
        exit(-1);
    }
    lastbn = getLastButOne(*head);
    value = lastbn->next->value;

    //Если в списке один элемент
    if (lastbn == NULL) {
        delete (*head);
        *head = NULL;
    }
    else {
        delete (lastbn->next);
        lastbn->next = NULL;
    }
    return value;
}

bool IsOperation(const string& str, map <string, int> map_) {
    auto res = map_.find(str);
    return !(res == map_.end());
}
bool IsNumber(string str) {
    bool flag = 0;
    if (ArrInt.find(str) != string::npos) { flag = 1; }
    return flag;
}
void deleteList(Stack* head) {
    Stack* prev = NULL;
    while (head->next) {
        prev = head;
        head = head->next;
        delete prev;
    }
    delete head;
}
void printStack(const Stack* head, ofstream& fout, bool console) {
    while (head) {
        if (!console)
            fout << head->value << " ";
        else {
            cout << head->value << " ";
            fout << head->value << " ";
        }
        head = head->next;
    }
    if (!console)
        fout << endl;
    else {
        cout << endl;
        fout << endl;
    }
    return;
}
int action(int& value1, int& value2, string& operation) {
    switch (operation[0]) {
    case '+':
        return value1 + value2;
        break;
    case '-':
        return value1 - value2;
        break;
    case '*':
        return value1 * value2;
        break;
    case '/':
        return value1 / value2;
        break;
    default:
        break;
    }
}

void First_question(string text, Stack* OperationStack, string& OutString) {
    int count = 0;
    Stack* Element = 0;
    string str1, OperationInStack = "", str2 = "";
    for (int i = 0; i < text.length(); i++) {
        str1 = text[i];
        if (IsNumber(str1) == 1) {
            cout << str1 << "- это число, заносим его в выходную строку" << endl;
            OutString += str1;
        }
        else {
            if (IsOperation(str1, weight) == 1) {
                OutString += ' ';
                cout << str1 << "- это операнд, заносим его в стек" << endl;
                if (SizeStack(OperationStack) == 0) {
                    StackNewElement(OperationStack, str1);
                }
                else {
                    if (SizeStack(OperationStack) == 1) {
                        Element = getLast(OperationStack);
                        if (weight[str1] < weight[Element->value]) {
                            OperationInStack = CountStackEndElement(&OperationStack);
                            OutString += OperationInStack;
                            OutString += ' ';
                        }
                        StackNewElement(OperationStack, str1);
                    }
                    else {
                        if (SizeStack(OperationStack) > 1) {
                            Element = getLast(OperationStack);
                            if (weight[str1] < weight[Element->value]) {
                                count = SizeStack(OperationStack);
                                while (count > 0) {
                                    if (count > 2) {
                                        OperationInStack = CountEndElement(&OperationStack);
                                        OutString += OperationInStack;
                                        OutString += ' ';
                                    }
                                    else {
                                        OperationInStack = CountStackEndElement(&OperationStack);
                                        OutString += OperationInStack;
                                        OutString += ' ';
                                    }
                                    count--;
                                }
                            }
                            StackNewElement(OperationStack, str1);
                        }
                    }
                }
            }
        }
        if (i == text.length() - 1) { OutString += ' '; }
    }
    count = SizeStack(OperationStack);
    while (count > 0) {
        if (count > 2) {
            OperationInStack = CountEndElement(&OperationStack);
            str2 += ' ';
            str2 += OperationInStack;
        }
        else {
            OperationInStack = CountStackEndElement(&OperationStack);
            str2 += ' ';
            str2 += OperationInStack;
        }
        count--;
    }
    for (int i = (str2.length() - 1); i > 0; i--) { 
        OutString += str2[i]; 
    }
    for (int i = 0; i < OutString.length(); i++) {
        str1 = OutString[i];
        if (str1 == "(" || str1 == ")") {
            OutString.erase(i, 2);
            i -= 2;
        }
    }
    cout << OutString << endl;
    deleteList(OperationStack);
}
void Second_question(string text) {
    string str, strvalue = "";
    int CountOpenBracket = 0, CountCloseBracket = 0, CountOperation = 0, CountValue = 0;
    for (int i = 0; i < text.length(); ++i) {
        str = text[i];
        if (IsNumber(str) == 1) {
            strvalue += str;
        }
        else {
            if (IsOperation(str, weight) == 1){
                if (strvalue.length() > 0) {
                    CountValue++;
                    strvalue = "";
                }
                CountOperation++;
                if (str == "(") {
                    CountOpenBracket++; CountOperation--;
                }
                if (str == ")") {
                    CountCloseBracket++; CountOperation--;
                }
            }
        }
        if (IsNumber(str) == 1 && i == text.length() - 1) {
            CountValue++;
        }
    }
    if (CountOpenBracket == CountCloseBracket && CountValue == CountOperation + 1) {
        cout << "Выражение корректно" << endl;
    }
    else{ cout << "Выражение некорректно" << endl; }
}
void Notation(string text, Stack* OperationStack, string& OutString) {
    int count = 0;
    Stack* Element = 0;
    string str1, OperationInStack = "", str2 = "";
    for (int i = 0; i < text.length(); i++) {
        str1 = text[i];
        if (IsNumber(str1) == 1) {
            OutString += str1;
        }
        else {
            if (IsOperation(str1, weight) == 1) {
                OutString += ' ';
                if (SizeStack(OperationStack) == 0) {
                    StackNewElement(OperationStack, str1);
                }
                else {
                    if (SizeStack(OperationStack) == 1) {
                        Element = getLast(OperationStack);
                        if (weight[str1] < weight[Element->value]) {
                            OperationInStack = CountStackEndElement(&OperationStack);
                            OutString += OperationInStack;
                            OutString += ' ';
                        }
                        StackNewElement(OperationStack, str1);
                    }
                    else {
                        if (SizeStack(OperationStack) > 1) {
                            Element = getLast(OperationStack);
                            if (weight[str1] < weight[Element->value]) {
                                count = SizeStack(OperationStack);
                                while (count > 0) {
                                    if (count > 2) {
                                        OperationInStack = CountEndElement(&OperationStack);
                                        OutString += OperationInStack;
                                        OutString += ' ';
                                    }
                                    else {
                                        OperationInStack = CountStackEndElement(&OperationStack);
                                        OutString += OperationInStack;
                                        OutString += ' ';
                                    }
                                    count--;
                                }
                            }
                            StackNewElement(OperationStack, str1);
                        }
                    }
                }
            }
        }
        if (i == text.length() - 1) { OutString += ' '; }
    }
    count = SizeStack(OperationStack);
    while (count > 0) {
        if (count > 2) {
            OperationInStack = CountEndElement(&OperationStack);
            str2 += ' ';
            str2 += OperationInStack;
        }
        else {
            OperationInStack = CountStackEndElement(&OperationStack);
            str2 += ' ';
            str2 += OperationInStack;
        }
        count--;
    }
    for (int i = (str2.length() - 1); i > 0; i--) {
        OutString += str2[i];
    }
    for (int i = 0; i < OutString.length(); i++) {
        str1 = OutString[i];
        if (str1 == "(" || str1 == ")") {
            OutString.erase(i, 2);
            i -= 2;
        }
    }
    deleteList(OperationStack);
}
void Third_question(string text) {
    int value1 = 0, value2 = 0, countvalue = 0;
    string buffer = "", str;
    for (int i = 0; i < text.length(); ++i) {
        str = text[i];
        if (IsNumber(str) == 1) {
            buffer += str;
        }
        else {
            if(IsOperation(str, weight) == 1) {
                
            }
        }
    }
}

int main() {
    setlocale(0, "");
    string text, FinalString = "";
    Stack* headOperation = 0;
    int n;
    while (1) {
        cout << "------------------------------------" << endl;
        cout << "Меню:" << endl;
        cout << "1.Преобразование простого выражения в польскую нотацию" << endl;
        cout << "2.Проверка выражения на корректность" << endl;
        cout << "3.Вычисление результата выражения" << endl;
        cout << "4.Выход" << endl;
        cout << "Введите число: ";
        cin >> n;
        cin.get();
        switch (n)
        {
        case 1:
            cout << "Введите выражение: ";
            getline(cin, text);
            First_question(text, headOperation, FinalString);
            break;
        case 2:
            cout << "Введите выражение: ";
            getline(cin, text);
            Second_question(text);
            break;
        case 3:
            break;
        case 4:
            exit(1);
        default:
            break;
        }
    }
}