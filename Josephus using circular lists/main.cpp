#include <iostream>
#include "Node.h"
#include "CircularList.h"

int josephus(CircularList &lista, int ind, int k) { /// n pers, ind incepe, kth person

    Node *current = lista.getHead();
    for (int i=1; i<ind; i++)
        current = current->getNext(); /// suntem la pers ind

    while (lista.getSize() != 1) {
        //Node *prevDelete = current;
        //for (int i=1; i<k-1; i++)
        //    prevDelete = prevDelete->getNext();
        //Node *prevDelete = current->getPrevDelete(k);
        Node *toDelete = current->getNextDeleted(k);

        if (current != toDelete) {
            lista.deleteNode(toDelete);
            current = current->getNext();
        }
        else {
            current = current->getNext();
            lista.deleteNode(toDelete);
        }
    }
    return lista.getHead()->getKey();
}

int main() {
    /// josephus problem
    /// fiecare sare peste cel de langa el

    int n = 4; int ind = 2; int k = 3;  /// n = 4: 2 si n = 5: 4, daca incepem de la 1 si eliminam din 3 in 3
    CircularList lista(nullptr);
    for (int i=1; i<=n; i++)
        lista.insertNode(i);

    std::cout << josephus(lista, ind, k);

    return 0;
}
