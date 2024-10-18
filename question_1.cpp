#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int>& st, int elem) {
    if (st.empty()) {
        st.push(elem);
        return;
    }
    int topElem = st.top();
    st.pop();
    insertAtBottom(st, elem);
    st.push(topElem);
}

void reverseStack(stack<int>& st) {
    if (st.empty()) {
        return;
    }
    int topElem = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, topElem);
}

void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;
    st.push(28);
    st.push(29);
    st.push(30);
    st.push(31);

    cout << "Original Stack: ";
    printStack(st);

    reverseStack(st);

    cout << "Reversed Stack: ";
    printStack(st);

    return 0;
}
