#include "Header.h"

void(*Choice[7])(Acount*,int) = { Show,ASort,Change,Add_Deposit,Print_Deposit,Check_Deposit,ASave };

int main(void) {
	int switch_n;
	int size = 0;
	Acount* acount;
	FILE* F = fopen("b.bin", "r");
	FILE* SF = fopen("s.bin", "r");
	if (!F) {
		size = 3; 
		acount = new Acount[size];
		for (int i = 0; i < size; i++)
		{
			acount[i].Fill();
		}
		F = fopen("b.bin", "w");
		SF = fopen("s.bin", "w");
		fwrite(acount, sizeof(Acount), size, F);
		fwrite(&size, sizeof(int), 1, SF);
	}
	else
	{
		fread(&size, sizeof(int), 1, SF);
		acount = new Acount[size];
		fread(acount, sizeof(Acount), size, F);
	}
	
	fclose(F);
	fclose(SF);

	while (true) {
		cout << "~~~~~~~~~==MENU==~~~~~~~~~" << endl;
		cout << "1 - Print all acount " << endl;
		cout << "2 - Sorting acounts " << endl;
		cout << "3 - Add new acount " << endl;
		cout << "4 - Delete acount " << endl;
		cout << "5 - Edit acount " << endl;
		cout << "6 - Add deposit " << endl;
		cout << "7 - Show all deposits " << endl;
		cout << "8 - Pay the deposit " << endl;
		cout << "9 - Clear console " << endl;
		cout << "10 - Save " << endl;
		cout << "11 - Save and Exit" << endl;
		cout << "~~~~~~~~~==MENU==~~~~~~~~~" << endl;
		cout << "Choice: ";
		cin >> switch_n;
		switch (switch_n)
		{
			case 1:Choice[0](acount,size); break;
			case 2:Choice[1](acount, size); break;
			case 3:acount = Add(acount, size);acount[size - 1].Fill(); break;
			case 4:acount = Delete(acount, size); break;
			case 5:Choice[2](acount, size); break;
			case 6:Choice[3](acount, size); break;
			case 7:Choice[4](acount, size); break;
			case 8:Choice[5](acount, size); break;
			case 9:system("cls");  break;
			case 10:Choice[6](acount, size);  break;
			case 11:Choice[6](acount, size); exit(0); break;
			default:cout << "Wrong value" << endl; break;
		}

	}
}