#include "Acount.h"

void Show(Acount*, int);
void ASave(Acount *, int);
void ASort(Acount*, int);

void Sort_byFname(Acount*, int);
void Sort_byLname(Acount*, int);
void Sort_byMname(Acount*, int);

void Sort_byBalance(Acount*, int);


Acount* Add(Acount*, int&);
Acount* Delete(Acount*, int&);

void Change(Acount*, int);

void Add_Deposit(Acount*, int);
void Print_Deposit(Acount*, int);
void Check_Deposit(Acount*, int);