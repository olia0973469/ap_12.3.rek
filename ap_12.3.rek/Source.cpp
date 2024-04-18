#include <iostream>

using namespace std;

typedef int Info;

struct Elem
{
    Elem* next,
        * prev;
    int info;
};

void enqueue(Elem*& first, Elem*& last, Info value)
{
    if (last == NULL) {
        last = new Elem;
        last->info = value;
        last->next = NULL;
        last->prev = NULL;
        first = last;
    }
    else {
        Elem* tmp = new Elem;
        tmp->info = value;
        tmp->next = NULL;
        tmp->prev = last;
        last->next = tmp;
        last = tmp;
    }
}

Info dequeue(Elem*& first, Elem*& last)
{
    if (first == NULL) {
        return -1; 
    }
    else if (first == last) {
        Info value = first->info;
        delete first;
        first = NULL;
        last = NULL;
        return value;
    }
    else {
        Elem* tmp = first->next;
        Info value = first->info;
        delete first;
        first = tmp;
        first->prev = NULL;
        return value;
    }
}

void printList(Elem* L)
{
    while (L != NULL) {
        cout << L->info << " ";
        L = L->next;
    }
    cout << endl;
}

bool sameValue(Elem* L)
{
    while (L != NULL && L->next != NULL) {
        if (L->info == L->next->info) {
            return true;
        }
        L = L->next;
    }
    return false;
}

int main()
{
    Elem* first = NULL,
        * last = NULL;
    for (int i = 1; i <= 10; i++)
        enqueue(first, last, i);

    cout << "List: ";
    printList(first);

    cout << "Has neigbour elements with same value?" << endl;
    if (sameValue(first))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
