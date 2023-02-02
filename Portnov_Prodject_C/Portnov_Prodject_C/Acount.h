#include "Date.h"

struct Acount {
	char FLname[16];
	char Lname[16];
	char Mname[16];
	long long Balance;
	Date date_of_birthday;
	Date date_of_startD;
	int year_of_endD = 0;

	void Fill() {

		cout << "Enter Fname: ";cin >> FLname;
		cout << "Enter Lname: ";cin >> Lname;
		cout << "Enter Mname: ";cin >> Mname;
		date_of_birthday.fillDate();
		cout << "Enter balance: ";cin >> Balance;
		cout << endl;
	}
	void Fill_FLname() {
		cout << "Enter new FLname: "; cin >> FLname;
	}
	void Fill_Lname() {
		cout << "Enter new Lname: "; cin >> Lname;
	}
	void Fill_Mname() {
		cout << "Enter new Mname: "; cin >> Mname;
	}
	void Fill_Balance() {
		cout << "Enter new balance: "; cin >> Balance;
	}
	void Fill_DateOfBD() {
		date_of_birthday.fillDate();
	}
	void Print() {
		cout << "******************************" << endl;
		cout << " FLname: " << FLname << endl;
		cout << " Lname: " << Lname << endl;
		cout << " Mname: " << Mname << endl;
		cout << " Date of birthday: "; date_of_birthday.PrintDate();
		cout << " Balance amount: " << Balance << endl;
		cout << endl;
	}
	void Start_Deposit() {
		if (year_of_endD == 0) {
			cout << "Enter date of start of deposite" << endl;
			date_of_startD.fillDate();

			year_of_endD = date_of_startD.year+1;
		}
		else {
			cout << "You have already one";
		}
	}
	void Show_Deposit() {
		if (year_of_endD != 0) {
			Print();
			cout << "Date of start deposit: "; date_of_startD.PrintDate();
			cout << "Date of end deposit: " << date_of_startD.day << "." << date_of_startD.month << "." << year_of_endD << endl;
			cout << endl;
		}
	}
	void Pay_Deposit(Date date_end) {
		if (year_of_endD != 0) {
			if (date_end.year >= year_of_endD && date_end.month >= date_of_startD.month && date_end.day >= date_of_startD.day) {
				Balance += (Balance / 100) * 15;
				date_of_startD.year = 0;date_of_startD.month = 0;date_of_startD.day = 0;
				year_of_endD = 0;
			}
		}
	}
};
