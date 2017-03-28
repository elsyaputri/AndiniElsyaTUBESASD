//Elsya Putri S 1301164201
#ifndef APLIKASI_H_INCLUDED
#define APLIKASI_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "childs.h"
#include "parent.h"
#include "RELASI.h"

using namespace std;


void menu();
void insert_parent(ListP &L);
void insert_child(ListC &L);
void insert_relasi(ListR &R, ListP P, ListC C);
void view_parent(ListP L);
void view_child(ListC L);
void search_parent(ListP P);
void search_child(ListC P);
void view_relasi(ListR L);
void printinfo(ListR L);
void search_relasi(ListR R, ListP P, ListC C);
void putus_relasi(ListR &R, ListP P, ListC C);
void delete_parent(ListP &L, ListR &R);
void delete_child(ListC &L, ListR &R);
void sort_relasi(ListR &L);
void exit();

#endif // APLIKASI_H_INCLUDED
