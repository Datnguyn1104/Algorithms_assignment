#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 100; // Kich thuoc toi da cua cay
const int NIL = -1; // Gia tri cua Node rong

struct Tree {
    string Data[MAX_SIZE];
    int size;
};

int Left_Child (int p, Tree T){ // xac dinh chi so cua node con trai
    int left = 2 * p + 1;
    return (left < T.size) ? left : NIL;
}


int Right_Child (int p, Tree T){ // xac dinh chi so cua node con phai
    int right = 2 * p + 2;
    return (right < T.size) ? right : NIL;
}


void NLR (int p, Tree T){ // Ham duyet tien to
    if (p != NIL && T.Data[p] != "") {
        cout << T.Data[p] << " ";
        NLR(Left_Child(p, T), T);
        NLR(Right_Child(p, T), T);
    }
}

void LNR (int p, Tree T){ // Ham duyet trung to
    if (p != NIL && T.Data[p] != "") {
        LNR(Left_Child(p, T), T);
        cout << T.Data[p] << " ";
        LNR(Right_Child(p, T), T);
    }
}

void LRN (int p, Tree T){ // Ham duyet hau to
    if (p != NIL && T.Data[p] != "") {
        LRN(Left_Child(p, T), T);
        LRN(Right_Child(p, T), T);
        cout << T.Data[p] << " ";
    }
}

int main() {
    Tree T;
    T.size = 15;

    // Bieu thuc a + 5*b/c + d*e^1/2 - c^8
    T.Data[0] = "-";//                          -
    T.Data[1] = "+";//               +                         ^
    T.Data[2] = "^";//        +              *              c     8
    T.Data[3] = "+";//    a       *       d     ^
    T.Data[4] = "*";//          5   /         e   0.5
    T.Data[5] = "c";//             b  c
    T.Data[6] = "8";//
    T.Data[7] = "a";//
    T.Data[8] = "*";//
    T.Data[9] = "d";//
    T.Data[10] = "^";//
    T.Data[11] = "5";//
    T.Data[12] = "/";//
    T.Data[13] = "e";//
    T.Data[14] = "0.5";//
    T.Data[15] = "b";//
    T.Data[16] = "c";//

    cout << "Duyet tien to (NLR): ";
    NLR(0, T);
    cout << endl;

    cout << "Duyet trung to (LNR): ";
    LNR(0, T);
    cout << endl;

    cout << "Duyet hau to (LRN): ";
    LRN(0, T);
    cout << endl;

    return 0;
}
