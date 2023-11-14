#include <iostream>

using namespace std;

struct ListItem {
    int data;
    ListItem* next;

    ListItem(int d) : data(d), next(nullptr) {}
};

class List {
private:
    ListItem* front;
    ListItem* back;

public:
    List() : front(nullptr), back(nullptr) {}

    ~List() {
        while (front != nullptr) {
            ListItem* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void push(int data) {
        ListItem* newItem = new ListItem(data);

        if (back == nullptr) {
            front = back = newItem;
        } else {
            back->next = newItem;
            back = newItem;
        }
    }

    void pop() {
        if (front != nullptr) {
            ListItem* temp = front;
            front = front->next;
            delete temp;
        }

        if (front == nullptr) {
            back = nullptr;
        }
    }

    List operator+(const List& other) const {
        List result(*this);

        ListItem* current = other.front;
        while (current != nullptr) {
            result.push(current->data);
            current = current->next;
        }

        return result;
    }

    List& operator=(const List& other) {
        if (this == &other) {
            return *this;
        }

        while (front != nullptr) {
            ListItem* temp = front;
            front = front->next;
            delete temp;
        }

        ListItem* current = other.front;
        while (current != nullptr) {
            push(current->data);
            current = current->next;
        }

        return *this;
    }

    friend bool operator==(const List& lhs, const List& rhs) {
        ListItem* left = lhs.front;
        ListItem* right = rhs.front;

        while (left != nullptr && right != nullptr) {
            if (left->data != right->data) {
                return false;
            }
            left = left->next;
            right = right->next;
        }

        return (left == nullptr && right == nullptr);
    }

    friend bool operator!=(const List& lhs, const List& rhs) {
        return !(lhs == rhs);
    }

    friend bool operator<(const List& lhs, const List& rhs) {
        ListItem* left = lhs.front;
        ListItem* right = rhs.front;

        while (left != nullptr && right != nullptr) {
            if (left->data < right->data) {
                return true;
            } else if (left->data > right->data) {
                return false;
            }
            left = left->next;
            right = right->next;
        }

        return (left == nullptr && right != nullptr);
    }

    friend bool operator>(const List& lhs, const List& rhs) {
        return rhs < lhs;
    }

    friend ostream& operator<<(ostream& os, const List& list) {
        ListItem* current = list.front;
        while (current != nullptr) {
            os << current->data << " ";
            current = current->next;
        }
        return os;
    }

    friend istream& operator>>(istream& is, List& list) {
        int data;
        while (is >> data) {
            list.push(data);
        }
        return is;
    }
};

int main() {
    List lista1, lista2;

    lista1.push(1);
    lista1.push(2);
    lista1.push(3);

    lista2.push(4);
    lista2.push(5);
    lista2.push(6);

    cout << "Lista 1: " << lista1 << endl;
    cout << "Lista 2: " << lista2 << endl;

    List lista3 = lista1 + lista2;
    cout << "Lista 3 (lista1 + lista2): " << lista3 << endl;

    List lista4 = lista3;
    cout << "Lista 4 (lista4 = lista3): " << lista4 << endl;

    if (lista1 == lista2) {
        cout << "Lista 1 este egală cu Lista 2" << endl;
    } else {
        cout << "Lista 1 nu este egală cu Lista 2" << endl;
    }

    if (lista1 != lista3) {
        cout << "Lista 1 nu este egală cu Lista 3" << endl;
    } else {
        cout << "Lista 1 este egală cu Lista 3" << endl;
    }

    if (lista1 < lista2) {
        cout << "Lista 1 este mai mică decât Lista 2" << endl;
    } else {
        cout << "Lista 1 nu este mai mică decât Lista 2" << endl;
    }

    if (lista1 > lista2) {
        cout << "Lista 1 este mai mare decât Lista 2" << endl;
    } else {
        cout << "Lista 1 nu este mai mare decât Lista 2" << endl;
    }


    return 0;
}
