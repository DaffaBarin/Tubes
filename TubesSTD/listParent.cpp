#include "listParent.h"

void createListParent(List_Parent &L) {
    L.first = NULL;
}

address_parent CreateElmParent(infotypeParent in){
    address_parent P = new parent;
    P -> info = in;
    P -> next = NULL;
    P -> prev = NULL;
    return P;
}

void insertFirstParent(List_Parent &L, address_parent P){
    if (L.first == NULL) {
        L.first = P;
        P -> next = P;
        P -> prev = P;
    } else {
        P -> next = L.first;
        P -> prev = L.first -> prev;
        L.first -> prev -> next = P;
        L.first -> prev = P;
        L.first = P;
    }
}
void insertAfterParent(List_Parent &L, address_parent Prec, address_parent P){
    P -> next = Prec -> next;
    P -> prev = Prec;
    Prec -> next -> prev = P;
    Prec -> next = P;
}

void insertLastParent(List_Parent &L, address_parent P){
    P -> next = L.first;
    P -> prev = L.first -> prev;
    L.first -> prev -> next = P;
    L.first -> prev = P;
}

void insertSortedParent(List_Parent &L, infotypeParent in){
    if (findElmParent(L,in.namaLapas) == NULL){
        if (in.namaLapas < L.first -> info.namaLapas){
            insertFirstParent(L,CreateElmParent(in));
        } else if (in.namaLapas > L.first -> prev -> info.namaLapas) {
            insertLastParent(L,CreateElmParent(in));
        } else {
            address_parent P = L.first;
            do {
                P = P -> next;
            }while(P!= L.first && P -> info)
            insertAfterParent(L,P -> prev,CreateElmParent(in));
        }
    } else {
        cout << "Lapas sudah terdaftar"<<endl;
    }
}

void deleteFirstParent(List_Parent &L, address_parent &P){
    if (L.first -> next == L.first) {
        P = L.first;
        P -> next = NULL;
        P -> prev = NULL;
        L.first = NULL;
    } else {
        P = L.first;
        L.first = P -> next;
        L.first -> prev = P -> prev;
        P -> prev -> next = L.first;
        P -> next = NULL;
        P -> prev = NULL;
    }
}

void deleteAfterParent(List_Parent &L, address_parent Prec, address_parent &P){
    P = Prec -> next;
    P -> next -> prev = Prec;
    Prec -> next = P -> next;
    P -> next = NULL;
    P -> prev = NULL;
}

void deleteLastParent(List_Parent &L, address_parent &P) {
    P = L.first -> prev;
    P -> prev -> next = L.first;
    L.first -> prev = P -> prev;
    P -> next = NULL;
    P -> prev = NULL;
}
void deleteSpesificParent(List_Parent &L, string X){
    address_parent P = findElmParent(L,X);
    if (P != NULL && P -> next != NULL && P -> prev != NULL){
        if (P = L.first){
            deleteFirstParent(L,P);
        } else {
            deleteAfterParent(L,P -> prev,P);
        }
    }else {
        cout << "Lapas tidak ditemukan"<<endl;
    }
}

address_parent findElmParent(List_Parent L, string X){
    address_parent P = L.first;
    if (P!= NULL) {
        do {
            P = P -> next;
        } while (P != L.first && P -> info.namaLapas != X);
    } if (P -> info.namaLapas == X){
        return P;
    }
    return NULL;
}

void printInfoParent(List_Parent L){
    address_parent P = L.first;
    if (P != NULL){
        do {
            cout<<"Lapas: "<<P -> info.namaLapas<<endl;
            cout<<"ID: "<<P -> info.IDLapas<<endl;
            cout<<"Luas lapas: "<< P -> info.luasLapas<<endl;
            cout<<endl;
            P = P -> next;
        }while(P != L.first);
    }
    cout<<endl;
}
