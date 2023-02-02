#include "Header.h"
void Show(Acount* acount, int size) {
	for (int i = 0; i < size; i++) {
		acount[i].Print();
	}
}
int BinSeach(Acount* acount, int size) {
	int left = 0;
	int right = size - 1;
	int middle;
	char key[16];
	cout << "Enter FLname: ";
	cin >> key;
	Sort_byFname(acount, size);
	while (true) {
		middle = (left + right) / 2;
		int res = strcmp(key, acount[middle].FLname);

		if (res > 0) {
			left = middle + 1;
		}
		else if (res < 0) {
			right = middle - 1;
		}
		else {
			return middle;
			break;
		}
		if (left > right) {

			return NULL;
			break;
		}
	}
}
void ASave(Acount * acount, int size)
{
	FILE* F = F = fopen("b.bin", "w");
	FILE* SF = SF = fopen("s.bin", "w");
	fwrite(&size, sizeof(int), 1, SF);
	fwrite(acount, sizeof(Acount), size, F);
	fclose(F);
	fclose(SF);
}
void ASort(Acount* acount, int size)
{
	int switch_on;
	cout << "1 - FLname" << endl;
	cout << "2 - Lname" << endl;
	cout << "3 - Mname" << endl;
	cout << "4 - Balance" << endl;
	cout << "Choice method of sorting: ";
	cin >> switch_on;

	switch (switch_on) {
	case 1:Sort_byFname(acount, size);
		Show(acount, size);
		break;
	case 2:Sort_byLname(acount, size);
		Show(acount, size);
		break;
	case 3:Sort_byMname(acount, size);
		Show(acount, size);
		break;
	case 4:Sort_byBalance(acount, size);
		Show(acount, size);
		break;
	default:cout << "Wrong data";
		break;
	}
}
void Sort_byFname(Acount* acount, int size) {
	for (int i = 0; i < size - 1; i++) {
		int min = i;
		for (int j = i + 1; j < size; j++) {
			if (strcmp(acount[min].FLname, acount[j].FLname) > 0) {
				min = j;
			}
		}
		if (min != i) {swap(acount[i], acount[min]);}
	}
}
void Sort_byLname(Acount* acount, int size) {
	for (int i = 0; i < size - 1; i++) {
		int min = i;
		for (int j = i + 1; j < size; j++) {
			if (strcmp(acount[min].Lname, acount[j].Lname) > 0) {
				min = j;
			}
		}
		if (min != i) {swap(acount[i], acount[min]);}
	}
}
void Sort_byMname(Acount *acount, int size){
	for (int i = 0; i < size - 1; i++) {
		int min = i;
		for (int j = i + 1; j < size; j++) {
			if (strcmp(acount[min].Mname, acount[j].Mname) > 0) {
				min = j;
			}
		}
		if (min != i) {swap(acount[i], acount[min]);}
	}
}
void Sort_byBalance(Acount* acount, int size) {
	for (int i = 0; i < size - 1; i++) {
		int min = i;
		for (int j = i + 1; j < size; j++) {
			if (acount[j].Balance < acount[min].Balance) {
				min = j;
			}
		}
		swap(acount[i], acount[min]);
	}
}
Acount* Add(Acount* acount, int& size) {
	Acount* tmp = new Acount[size + 1];
	for (int i = 0; i < size; i++) {
		tmp[i] = acount[i];
	}
	size++;
	delete[] acount;
	return tmp;
}
Acount* Delete(Acount* acount, int& size) {
	int startd = BinSeach(acount, size);
	if (startd!=NULL)
	{
		Acount* temp = new Acount[size - 1];
		int ind = 0;
		for (int i = 0; i < startd; i++) {
			temp[ind++] = acount[i];
		}
		for (int i = ind + 1; i < size; i++) {
			temp[ind++] = acount[i];
		}
		size = size - 1;
		delete[] acount;
		cout << "Acount deleted corectly"<<endl;
		return temp;
	}
	else
	{
		cout << "No acount with .this Fname" << endl;
		return acount;
	}
}

void Change(Acount* acount, int size) {
	int switch_on;
	int index = BinSeach(acount ,size);
	if (index != NULL){
		cout << acount[index].FLname << " exists " << endl;
		cout << "1 - Fname " << endl;
		cout << "2 - Lname " << endl;
		cout << "3 - Mname " << endl;
		cout << "4 - DateOfBirthday " << endl;
		cout << "5 - Balance " << endl;
		cout << "What do you want to change? " << endl;
		cin >> switch_on;
		switch (switch_on)
		{
		case 1:acount[index].Fill_FLname(); break;
		case 2:acount[index].Fill_Lname(); break;
		case 3:acount[index].Fill_Mname(); break;
		case 4:acount[index].Fill_DateOfBD(); break;
		case 5:acount[index].Fill_Balance(); break;
		default:cout << "Wrong value" << endl; break;
		}
	} 
	else{
		cout << "No acount with .this Fname" << endl;
	}
}
void Add_Deposit(Acount* acount, int size) {
	int switch_on;
	int index = BinSeach(acount, size);
	if (index != NULL) {
		cout << acount[index].FLname << " " << acount[index].Lname << " exists " << endl;
		acount[index].Start_Deposit();

	}
	else {
		cout << "No acount with .this Fname" << endl;
	}
			
}
void Print_Deposit(Acount* acount, int size) {
	for (int i = 0; i < size; i++) {
		acount[i].Show_Deposit();
	}
}

void Check_Deposit(Acount* acount, int size) {
	Date date_end;
	date_end.fillDate();
	for (int i = 0; i < size; i++) {
		acount[i].Pay_Deposit(date_end);
	}
}
