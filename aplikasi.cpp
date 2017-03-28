//Andini Salimah 1301164080
#include <iostream>
#include "aplikasi.h"
#include "parent.h"
#include "childs.h"
#include "RELASI.h"
using namespace std;

ListC L;
ListP Lp;
ListR Lr;
void menu(ListP P, ListC C, ListR R)
{
    int pilihan;
    createListC(L);
    createListP(Lp);
    createListR(Lr);

    do
    {
        cout<<"   =====MENU=====  "<<endl<<
            "1. Insert parent"<<endl<<
            "2. Insert child"<<endl<<
            "3. Insert relasi"<<endl<<
            "4. View parent"<<endl<<
            "5. View child"<<endl<<
            "6. Find parent"<<endl<<
            "7. Find child"<<endl<<
            "8. View relasi"<<endl<<
            "9. Find relasi"<<endl<<
            "10. Disconnect relasi"<<endl<<
            "11. Delete parent"<<endl<<
            "12. Delete child"<<endl<<
            "0. EXIT"<<endl<<
            cout<<"Input Menu :  ";
        cin>>pilihan;

        switch(pilihan)
        {
        case 1:
            system("cls");
            insert_parent(P);
            break;
        case 2:
            system("cls");
            insert_child(C);
            break;
        case 3:
            system("cls");
            insert_relasi(R,P,C);
            break;
        case 4:
            system("cls");
            view_parent(P);
            break;
        case 5:
            system("cls");
            view_child(C);
            break;
        case 6:
            system("cls");
            search_parent(P);
            break;
        case 7:
            system("cls");
            search_child(C);
            break;
        case 8:
            system("cls");
            view_relasi(R);
            break;
        case 9:
            system("cls");
            search_relasi(R,P,C);
            break;
        case 10:
            system("cls");
            putus_relasi(R,P,C);
            break;
        case 11:
            system("cls");
            delete_parent(P, R);
            break;
        case 12:
            system("cls");
            delete_child(C, R);
            break;
        case 0:
            system("cls");
            exit();
            break;
        default:
            cout<<"wrong input"<<endl;
            break;
        }
        cout<<"\npress enter"<<endl;
        getch();
        cout<<endl;
    }
    while (pilihan != 0);
    cout<< " Terima kasih sudah memasuki data" <<endl;
}
void insert_parent(ListP &L)
{
    infotypeP x;
    addressP P, Q;
    cout<<"ID : ";
    cin>>x.id;
    cout<<"Nama web : ";
    cin>>x.namaweb;
    cout<<"Sosial media : ";
    cin>>x.sosialmedia;
    cout<<"Id Sosial Media : ";
    cin>>x.idsosialmedia;
    cout<<"Pembuat : ";
    cin>>x.pembuat;
    cout<<"Lokas : ";
    cin>>x.lokasi;
    P = alokasi(x);
    if(firstP(L) == NULL)
    {
        insertFirstP(L,P);
    }
    else
    {
        Q = firstP(L);
        while(nextP(Q) != NULL && infoP(Q).id != infoP(P).id)
        {
            Q = nextP(Q);
        }
        if(infoP(P).id != infoP(Q).id)
        {
            insertLastP(L, P);
        }
        else
        {
            cout<<"Error"<<endl;
        }
    }
}


void insert_child(ListC &L)
{
    infotypeC x;
    addressC P, Q;
    cout<<"ID : ";
    cin>>x.id;
    cout<<"Nama : ";
    cin>>x.nama;
    cout<<"NIM : ";
    cin>>x.nim;
    cout<<"e-mail : ";
    cin>>x.email;
    cout<<"Alamat : ";
    cin>>x.alamat;
    cout<<"No.hp : ";
    cin>>x.nomorhape;
    P = alokasi(x);
    if(firstC(L) == NULL)
    {
        insertFirstC(L, P);
    }
    else
    {
        Q = firstC(L);
        while(Q != lastC(L) && infoC(Q).id != infoC(P).id)
        {
            Q = nextC(P);
        }
        if(infoC(P).id != infoC(P).id)
        {
            insertLastC(L, P);
        }
        else
        {
            cout<<"Error"<<endl;
        }
    }
}

void insert_relasi(ListR &R,ListC C, ListP P)
{
    infotypeP x;
    infotypeC y;
    addressP S;
    addressC Q;
    addressR O;
    cout<<"ID SOIAL MEDIA : ";
    cin>>x.id;
    cout<<"ID SISWA : ";
    cin>>y.id;
    S = findElmP(P, x);
    Q = findElm(C, y);
    if(S != NULL && Q != NULL)
    {
        O = alokasi(S, Q);
        if(firstR(R) != NULL)
        {
            insertLastR(R, O);
        }
        else
        {
            insertFirstR(R, O);
        }
    }
    else
    {
        cout<<"Error"<<endl;
    }

}


void view_parent(ListP L)
{
    if(firstP(L)!=NULL){
          printInfoP(L);
    }
    else{
        cout<<"tidak ada"<<endl;
    }
    getch();
    system("cls");

}


void view_child(ListC L)
{
    if(firstC(L)!=NULL){
          printInfoC(L);
    }
    else{
        cout<<"tidak ada"<<endl;
    }
    getch();
    system("cls");
}


void search_parent(ListP P)
{
    infotypeP x;
    addressP y;
    cout<<"Search Sosial Media : ";
    cin>>x.id;
    y = findElmP(P, x);
    if(y != NULL)
    {
        cout<<"ID : "<<infoC(y).id<<endl;
        cout<<"Nama Web : "<<infoC(y).namaweb<<endl;
        cout<<"sosialmedia : "<<infoC(y).sosialmedia<<endl;
        cout<<"ID Sosial Media : "<<infoC(y).idsosialmedia<<endl;
        cout<<"Pembuat : "<<infoC(y).pembuat<<endl;
        cout<<"Lokasi : "<<infoC(y).lokasi<<endl;
    }
    else
    {
        cout<<"Error"<<endl;
    }
}

void search_child(ListC P)
{
    infotypeC x;
    addressC y;
    cout<<"Search Mahasiswa : ";
    cin>>x.id;
    y = findElm(P, x);
    if(y != NULL)
    {
        cout<<"ID : "<<infoC(y).id<<endl;
        cout<<"Nama : "<<infoC(y).nama<<endl;
        cout<<"NIM : "<<infoC(y).nim<<endl;
        cout<<"email : "<<infoC(y).email<<endl;
        cout<<"Alamat : "<<infoC(y).alamat<<endl;
        cout<<"nomor hape: "<<infoC(y).nomorhape<<endl;
    }
    else
    {
        cout<<"Error"<<endl;
    }
}



void view_relasi(ListR L)
{
    printInfoR(L);
}


void search_relasi(ListR R, ListP P, ListC C)
{
    infotypeP x;
    infotypeC y;
    addressP S;
    addressC Q;
    addressR O;
    cout<<"ID SOSIAL MEDIA : ";
    cin>>x.id;
    cout<<"ID SISWA : ";
    cin>>y.id;
    S = findElmP(P, x);
    Q = findElm(C, y);
    if(S != NULL && Q != NULL)
    {
        O = findElmSosialdanMahasiswa(R, S, Q);
        if(O != NULL)
        {
            cout<<infoP(O->P).namaweb<<" Relasinya:  "<<infoC(O->Q).nama<<endl;
        }
        else
        {
            cout<<"Error"<<endl;
        }
    }
    else
    {
        cout<<"Error"<<endl;
    }
}


void putus_relasi(ListR &R, ListP P, ListC C)
{
    infotypeP x;
    infotypeC y;
    addressP p;
    addressC q;
    addressR r, r1, rd;
    cout<<"ID SOSIAL MEDIA : ";
    cin>>x.id;
    cout<<"ID NAMA MAHASISWA : ";
    cin>>y.id;
    p = findElmP(P, x);
    q = findElm(C, y);
    if(p != NULL && q != NULL && firstR(R) != NULL)
    {
        r = findElmSosialdanMahasiswa(R, p, q);
        if(r == firstR(R))
        {
            deleteFirstR(R, r);
        }
        else if(r != firstR(R) && nextR(r) != NULL)
        {
            r1 = r;
            r = firstR(R);
            while(nextR(r) != r1)
            {
                r = nextR(r);
            }
            deleteAfterR(R, r, rd);
        }
        else
        {
            deleteLastR(R, r);
        }
    }
    else
    {
        cout<<"Error"<<endl;
    }
}


void delete_parent(ListP &L, ListR &Lr)
{
    infotypeP x;
    addressP p, p1, p2, pd;
    addressR r, r1, r2, rd;
    cout<<"ID SOSIAL MEDIA : ";
    cin>>x.id;
    p = findElmP(L, x);
    if(p != NULL && firstR(Lr) != NULL)
    {
        r = firstR(Lr);
        while(r != NULL)
        {
            if(r->P == p)
            {
                if(r == firstR(Lr))
                {
                    deleteFirstR(Lr, rd);
                    if(firstR(Lr) != NULL)
                    {
                        r = firstR(Lr);
                    }
                }
                else if(r == lastR(Lr))
                {
                    deleteLastR(Lr, rd);
                    r = firstR(Lr);
                }
                else
                {
                    r1 = r;
                    r = firstR(Lr);
                    r2 = firstR(Lr);
                    while(nextR(r2) != r1)
                    {
                        r2 = nextR(r2);
                    }
                    deleteAfterR(Lr, r2, rd);
                }
            }
            r = nextR(r);
        }

        if(p == firstP(L))
        {
            deleteFirstP(L, pd);
            if(firstP(L) != NULL)
            {
                p = firstP(L);
            }
        }
        else if(nextP(p) == NULL)
        {
            deleteLastP(L, pd);
            p = firstP(L);
        }
        else
        {
            p1 = p;
            p = firstP(L);
            p2 = firstP(L);
            while(nextP(p2) != p1)
            {
                p2 = nextP(p2);
            }
            deleteAfterP(L, p2, pd);
        }
    }
}

void delete_child(ListC &L, ListR &R)
{
    infotypeC y;
    addressC c, c1, c2, cd;
    addressR r, r1, r2, rd;
    cout<<"ID MAHASISWA : ";
    cin>>y.id;
    c = findElm(L, y);
    if(c != NULL && firstR(Lr) != NULL)
    {
        r = firstR(Lr);
        while(r != NULL)
        {
            if(r->Q == c)
            {
                if(r == firstR(Lr))
                {
                    deleteFirstR(Lr, rd);
                    if(firstR(Lr) != NULL)
                    {
                        r = firstR(Lr);
                    }
                }
                else if(r == lastR(Lr))
                {
                    deleteLastR(Lr, rd);
                    r = firstR(Lr);
                }
                else
                {
                    r1 = r;
                    r = firstR(Lr);
                    r2 = firstR(Lr);
                    while(nextR(r2) != r1)
                    {
                        r2 = nextR(r2);
                    }
                    deleteAfterR(Lr, r2, rd);
                }
            }
            r = nextR(r);
        }

        if(c == firstC(L))
        {
            deleteFirstC(L, cd);
            if(firstC(L) != NULL)
            {
                c = firstC(L);
            }
        }
        else if(c == lastC(L))
        {
            deleteLastC(L, cd);
            c = firstC(L);
        }
        else
        {
            c1 = c;
            c = firstC(L);
            c2 = firstC(L);
            while(nextC(c2) != c1)
            {
                c2 = nextC(c2);
            }
            deleteAfterC(L, c2, cd);
        }

    }
}




void exit()
{
    cout<<"Terimakasih :))"<<endl;
}
