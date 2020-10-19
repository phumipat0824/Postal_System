/*
name Prasobsuk Namueangrak
sec 01
id 62160098
*/
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;
class Faculty{
	private:
		class node_fac{
			public:
				string name_fac;
				string name;
				string id_fac;
				node_fac *next;	
		};
		node_fac *head; 
		node_fac *tail;
		int count;
	public:
		Faculty(){
			this->head = NULL;
			this->tail = NULL;
			this->count = 0;
		}
		~Faculty(){
			for(int i=1;i<this->count;i++){
				node_fac *tmp = this->head;
				this->head = this->head->next;
				delete tmp;
				tmp = NULL;
			}
			this->head = NULL;
			this->tail = NULL;
		}
		void Add_fac(string name,string name_fac, string id_fac){
			node_fac *tmp = new node_fac;
			tmp->name = name;
			tmp->name_fac = name_fac;
			tmp->id_fac = id_fac;
			tmp->next = NULL;
			if(head==NULL){
				head = tmp;
				tail = tmp;
			}else{
				tail->next = tmp;
				tail = tail->next;
			}
			count++;
		}
		bool Loaddata_fac(string faculty){
			string name_fac, id_fac,name, filename, filein;
			filename = faculty + ".dat";
			ifstream myfile;
			myfile.open(filename.c_str());
			if(myfile.fail()){
				return false;
			}else{
				while(getline(myfile, filein)){
					name = filein.substr(0, filein.find(','));
					filein.erase(0, filein.find(' ')+1);
					filein.erase(0, filein.find(' ')+1);
					name_fac = filein.substr(0, filein.find(','));
					filein.erase(0, filein.find(',')+1);
					id_fac = filein.substr(0, filein.find(','));
					filein.erase(0, filein.find(',')+1);
					Add_fac(name,name_fac, id_fac);
					count++;
				}
				Add_fac(name,name_fac, id_fac);
				return true;
			}
		}
//		string Check(string FacID){
//			node_fac *tmp = head;
//			while(tmp->next != NULL){
//				if(FacID == tmp->id_fac){
//					return tmp->name_fac;
//					break;
//				}
//			tmp = tmp->next;
//			}
//			return "don't have faculty'";
//		}
		string Check(string FacID){
			node_fac *tmp = head;
			cout<<FacID<<endl;
			while(tmp != NULL){
				if(FacID == tmp->id_fac){
					return tmp->name;

				}
			tmp = tmp->next;
			}
			return "don't have faculty'";
		}
};
class Check{
	private : 
		class node_check{
			public:
				string ID;
				string Fac;
				string Date;
				string Tin;
				string Tout;
				node_check *next;
		};
		node_check *head;
		node_check *tail;
		int count;
		Faculty list;
	public:
		string menu(){
			string choose;
			cout<<"====== BUUCHANA ======="<<endl
				<<"1.Check-in" <<endl
				<<"2.Check-out"<<endl
				<<"3.Exit"<<endl
				<<"======================"<<endl;
			cout<<"Enter: ";
			cin>>choose;
			return choose;
		}
		string checkin(){
			string choose;
			cout<<"================== Personal Check-in =================="<<endl
				<<"01	Faculty of Agriculture"<<endl
				<<"02	Faculty of Allied Health Sciences"<<endl
				<<"03	Faculty of Architecture"<<endl
				<<"04	Faculty of Arts"<<endl
				<<"05	Faculty of Business Administration"<<endl
				<<"06	Faculty of Commerce and Accountancy"<<endl
				<<"07	Faculty of Communication Arts"<<endl
				<<"08	Faculty of Dentistry"<<endl
				<<"09	Faculty of Economics"<<endl
				<<"10	Faculty of Education"<<endl
				<<"11	Faculty of Engineerin"<<endl
				<<"12	Faculty of Fisheries"<<endl
				<<"13	Faculty of Informatics"<<endl
				<<"14	Faculty of Humanities"<<endl
				<<"15	Faculty of Law"<<endl
				<<"16	Faculty of Medicine"<<endl
				<<"17	Faculty of Science"<<endl
				<<"=================================================="<<endl
				<<"Enter Code :";
			cin>>choose;
			return choose;
		}
		string Checking(){
			node_check *tmp;
			string m = menu();
			string Fac;	
			if(m == "1"){
				string fac = checkin();
				cout<<fac;
				Fac = list.Check(fac);
				cout<<Fac<<endl;
			}
			
		}
};
class Student{
	public:
		class node{
			public:
				string stdID;
				string name;
				string tel;
				string pass;
				node *next;	
		};
		node *head;
		node *tail;
		int count;
		Faculty *list;
	
		Student(){
			this->head = NULL;
			this->tail = NULL;
			this->count = 0;
			list = new Faculty;
		}
		~Student(){
			for(int i=1;i<this->count;i++){
				node *tmp = this->head;
				this->head = this->head->next;
				delete tmp;
				tmp = NULL;
			}
			this->head = NULL;
			this->tail = NULL;
		}
		void Add_std(string ID, string n, string t, string p){
			node *tmp = new node;
			tmp->stdID = ID;
			tmp->name = n;
			tmp->tel = t;
			tmp->pass = p;
			tmp->next = NULL;
			if(head==NULL){
				head = tmp;
				tail = tmp;
			}else{
				tail->next = tmp;
				tail = tail->next;
			}
			count++;
			
		}
		bool Loaddata_std(string student){
			list->Loaddata_fac("faculty");
			string stdID, name, tel, faculty,pass, filename, filein;
			filename = student + ".dat";
			ifstream myfile;
			myfile.open(filename.c_str());
			if(myfile.fail()){
				return false;
			}else{
				while(getline(myfile, filein)){
					stdID = filein.substr(0, filein.find(','));
					filein.erase(0, filein.find(',')+1);
					name = filein.substr(0, filein.find(' ')+2);
					filein.erase(0, filein.find(',')+1);
					tel = filein.substr(0, filein.find(','));
					filein.erase(0, filein.find(',')+1);
					pass = filein.substr(0, filein.find(','));
					filein.erase(0, filein.find(',')+1);
					filein.erase(0, filein.find(' ')+1);
					filein.erase(0, filein.find(' ')+1);
					name = name+".";
					Add_std(stdID, name, tel,pass);
					count++;
				}
				//Add_std(stdID, name, tel,pass);
				return true;
			}
			
		}
		void Show_Menu(){
			cout << "=============== BUUCHANA ===============" << endl;
			cout << "1.Student Information" << endl;
			cout << "2.Staff Information" << endl;
			cout << "3.Exit" << endl;
			cout << "========================================" << endl;
		}
		void Showdata_std(){
			node *tmp = head;
			cout << "===================================================== BUUCHANA ==================================================" << endl;
			cout << "NO" << "\t\t" << "Student ID" << "\t\t" << "Student Name" << "\t\t" << "Tel." << "\t\t\t" << "Department" << endl;
			cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
			int i=0;
			while(tmp->next != NULL){
				string FacID;
				FacID = tmp->stdID.substr(2,2);
				string FacName;
                FacName = list->Check(FacID);
				cout <<  i+1 << "." << "\t\t"<< tmp->stdID << "\t\t"<< setw(14) << left << tmp->name 
				<< "\t\t"<< setw(14) << left << tmp->tel <<"\t\t"<< setw(14) << left << FacName;
				cout << endl;
				i++;
				tmp = tmp->next;
			}		
		}
		bool Checkpass(string user,string pasw){
			node *tmp =head;
			while(tmp != NULL){
				if(tmp->pass == pasw && tmp->stdID == user){
					return true;
					break;
				}
				tmp = tmp->next;
			}//while
		}
		void Showstd_case_one(){
			node *tmp = head;
			node *l,*j;
			string Name,id,Tel;
			l = head;
			j = l;
			for(l = head;l!=NULL;l=l->next){
				for(j=l;j!=NULL;j=j->next){
					if(l->stdID > j->stdID){
						id = l->stdID;
						Name = l->name;
						Tel = l->tel;
						l->stdID = j->stdID;
						l->name = j->name;
						l->tel = j->tel;
						j->stdID = id;
						j->name = Name;
						j->tel = Tel;
					}
				}
			}
			cout<<"================ BUUCHANA ==============="<<endl;
			cout<<"NO"<<"\t\t"<<"Student ID"<<"\t\t"<<"Student Name"<<"\t\t"<<"Tel."<<"\t\t"<<"Department"<<endl;
			
			int i=0;
			while(tmp != NULL){
				string FacID;
				FacID = tmp->stdID.substr(2,2);
				string FacName;
                FacName = list->Check(FacID);
				cout <<  i+1 << "." << "\t\t"<< tmp->stdID << "\t\t"<< setw(14) << left << tmp->name 
				<< "\t\t"<< setw(14) << left << tmp->tel <<"\t\t"<< setw(14) << left << FacName;
				cout << endl;
				i++;
				tmp = tmp->next;
			}	
			
		}
		void Showstd_case_two(){
		
			node *l,*j;
			string Name,id,Tel;
			l = head;
			j = l;
			for(l = head;l!=NULL;l=l->next){
				for(j=l;j!=NULL;j=j->next){
					if(l->stdID < j->stdID){
						id = l->stdID;
						Name = l->name;
						Tel = l->tel;
						l->stdID = j->stdID;
						l->name = j->name;
						l->tel = j->tel;
						j->stdID = id;
						j->name = Name;
						j->tel = Tel;
					}
				}
			}
			cout<<"================ BUUCHANA ==============="<<endl;
			cout<<"NO"<<"\t\t"<<"Student ID"<<"\t\t"<<"Student Name"<<"\t\t"<<"Tel."<<"\t\t"<<"Department"<<endl;
//				node *tmp = head;
			int i=0;
			for(node *tmp = head;tmp != NULL;tmp=tmp->next){
				string FacID;
				FacID = tmp->stdID.substr(2,2);
				string FacName;
                FacName = list->Check(FacID);
				cout <<  i+1 << "." << "\t\t"<< tmp->stdID << "\t\t"<< setw(14) << left << tmp->name 
				<< "\t\t"<< setw(14) << left << tmp->tel <<"\t\t"<< setw(14) << left << FacName;
				cout << endl;
				i++;
				;
			}	
			
		}
		void Showstd_case_three(){
			
			node *l,*j;
			string Name,id,Tel;
			l = head;
			j = l;
			for(l = head;l!=NULL;l=l->next){
				for(j=l;j!=NULL;j=j->next){
					if(l->name > j->name){
						id = l->stdID;
						Name = l->name;
						Tel = l->tel;
						l->stdID = j->stdID;
						l->name = j->name;
						l->tel = j->tel;
						j->stdID = id;
						j->name = Name;
						j->tel = Tel;
					}
				}
			}
			cout<<"================ BUUCHANA ==============="<<endl;
			cout<<"NO"<<"\t\t"<<"Student ID"<<"\t\t"<<"Student Name"<<"\t\t"<<"Tel."<<"\t\t"<<"Department"<<endl;
			node *tmp = head;
			int i=0;
			while(tmp != NULL){
				string FacID;
				FacID = tmp->stdID.substr(2,2);
				string FacName;
                FacName = list->Check(FacID);
				cout <<  i+1 << "." << "\t\t"<< tmp->stdID << "\t\t"<< setw(14) << left << tmp->name 
				<< "\t\t"<< setw(14) << left << tmp->tel <<"\t\t"<< setw(14) << left << FacName;
				cout << endl;
				i++;
				tmp = tmp->next;
			}	
			
		}
		void Showstd_case_for(){
			
			node *l,*j;
			string Name,id,Tel;
			l = head;
			j = l;
			for(l = head;l!=NULL;l=l->next){
				for(j=l;j!=NULL;j=j->next){
					if(l->name < j->name){
						id = l->stdID;
						Name = l->name;
						Tel = l->tel;
						l->stdID = j->stdID;
						l->name = j->name;
						l->tel = j->tel;
						j->stdID = id;
						j->name = Name;
						j->tel = Tel;
					}
				}
			}
			cout<<"================ BUUCHANA ==============="<<endl;
			cout<<"NO"<<"\t\t"<<"Student ID"<<"\t\t"<<"Student Name"<<"\t\t"<<"Tel."<<"\t\t"<<"Department"<<endl;
			node *tmp = head;
			int i=0;
			while(tmp != NULL){
				string FacID;
				FacID = tmp->stdID.substr(2,2);
				string FacName;
                FacName = list->Check(FacID);
				cout <<  i+1 << "." << "\t\t"<< tmp->stdID << "\t\t"<< setw(14) << left << tmp->name 
				<< "\t\t"<< setw(14) << left << tmp->tel <<"\t\t"<< setw(14) << left << FacName;
				cout << endl;
				i++;
				tmp = tmp->next;
			}	
			
		}
		void Menutwo(){
			cout<<"====== Student Information ======="<<endl
				<<"1.Student ID Ascending"<<endl
				<<"2.Student ID Descending"<<endl
				<<"3.Student Name Ascending"<<endl
				<<"4.Student Name Descending"<<endl
				<<"======================"<<endl;
		}
		
};
class Staff{
	private:
		class node{
			public:
				string staffID;
				string nameStaff;
				string telStaff;
				string facultyStaff;
				string passStaff;
				string gen;
				node *next;	
		};
		node *head;
		node *tail;
		int count;
		Faculty *list;
	public:
		Staff(){
			this->head = NULL;
			this->tail = NULL;
			this->count = 0;
			list = new Faculty;
		}
		~Staff(){
			for(int i=1;i<this->count;i++){
				node *tmp = this->head;
				this->head = this->head->next;
				delete tmp;
				tmp = NULL;
			}
			this->head = NULL;
			this->tail = NULL;
		}
		void Add_staff(string ID, string n, string t, string fac, string pass){
			node *tmp = new node;
			tmp->staffID = ID;
			tmp->nameStaff = n;
			tmp->telStaff = t;
			tmp->facultyStaff = fac;
			tmp->passStaff = pass;
			tmp->next = NULL;
			if(head==NULL){
				head = tmp;
				tail = tmp;
			}else{
				tail->next = tmp;
				tail = tail->next;
			}
			count++;
		}
		bool Loaddata_staff(string staff){
			list->Loaddata_fac("faculty");
			string staffID;
			string nameStaff, telStaff, facultyStaff, passStaff, filename, filein;
			filename = staff + ".dat";
			ifstream myfile;
			myfile.open(filename.c_str());
			if(myfile.fail()){
				return false;
			}else{
				while(getline(myfile, filein)){
					staffID = filein.substr(0, filein.find(','));
					filein.erase(0, filein.find(',')+1);
					nameStaff = filein.substr(0, filein.find(','));
					filein.erase(0, filein.find(',')+1);
					telStaff = filein.substr(0, filein.find(','));
					filein.erase(0, filein.find(',')+1);
					filein.erase(0, filein.find(' ')+1);
					filein.erase(0, filein.find(' ')+1);
					facultyStaff = filein.substr(0, filein.find(','));
					filein.erase(0, filein.find(',')+1);
					passStaff = filein.substr(0, filein.find(' '));
					filein.erase(0, filein.find(',')+1);
					Add_staff(staffID, nameStaff, telStaff, facultyStaff, passStaff);
					count++;
				}
				Add_staff(staffID, nameStaff, telStaff, facultyStaff, passStaff);
				return true;
			}
		}
		void ShowMenu_staff(){
			cout << "=============== BUUCHANA ===============" << endl;
			cout << "1.Overall Staff Information" << endl;
			cout << "2.Academic staff Information" << endl;
			cout << "3.User account management" << endl;
			cout << "4.Return to main menu" << endl;
			cout << "========================================" << endl;
		}
		void Showdata_staff(){
			node *tmp = head;
			cout << "===================================================== BUUCHANA ==================================================" << endl;
			cout << "NO" << "\t" << "Staff ID" << "\t" << "Staff Name" << "\t\t\t" << "Tel." << "\t\t\t" << "Department" << endl;
			cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
			int i=0;
			while(tmp->next != NULL){
				string FacID;
				FacID = tmp->staffID.substr(2,2);
				string FacName;
                FacName = list->Check(FacID);
				cout <<  i+1 << "." << "\t"<< tmp->staffID << "\t" << setw(30) << left << tmp->nameStaff << "\t" << setw(21) << left << tmp->telStaff 
				<<"\t"<< setw(14) << left << FacName;
				cout << endl;
				i++;
				tmp = tmp->next;
			}
		}
		void Showdata_academic_staff(){
			node *tmp = head;
			cout << "============================================================= BUUCHANA ==========================================================" << endl;
			cout << "NO" << "\t" << "Academic Staff ID" << "\t" << "Gender" << "\t\t" << "Academic Staff Name" << "\t\t" << "Tel." << "\t\t\t" << "Department" << endl;
			cout << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
			int i = 0; 
			while(tmp->next != NULL){
				string FacID;
				FacID = tmp->staffID.substr(2,2);
				string FacName;
                FacName = list->Check(FacID);
				string gender;
				string type;
				string Fname, Mname, Lname,tel;
				tel = tmp->telStaff;
				tel.erase(3,1);
				tel.erase(6,1);
				tel.insert(0,"(");
				tel.insert(4,")");
				gender = tmp->nameStaff.substr(0, tmp->nameStaff.find(' '));
				if(gender=="Mr."){
					tmp->gen = "Male";	
				}else if(gender=="Ms."){
					tmp->gen = "FeMale";	
				}
				type = tmp->staffID[5];
				if(type == "1"){
					i++;
					cout << i << ".";
					int space = 0;
					Fname = tmp->nameStaff;
					Mname = tmp->nameStaff;
					Lname = tmp->nameStaff;
					Fname = Fname.erase(0, Fname.find(' ')+1);
					for(int i=0;i<Fname.size();i++){
						if(Fname[i] == ' '){
							space++;
						}
					}
					cout << "\t" << tmp->staffID << "\t\t" << setw(14) << left << tmp->gen << "\t" ;
					if(space == 1){
						cout << Fname[0] << ".";
						Fname.erase(0, Fname.find(' ')+1);
						cout << setw(30) << left << Fname;
					}else if(space == 2){
						int index = Fname.find(' ');
						Fname.erase(index+2, Fname.find(' ',index+1)-(index+2));
						Fname.insert(index+2,".");
						cout << setw(32) << left << Fname;
					}
					cout  << setw(24) << left << tel << setw(14) << left << FacName;
					cout << endl;
				}
				tmp = tmp->next;
			}
		}
		void Showdata_staff_password(){
			node *tmp = head;
			cout << "====================== BUUCHANA ========================" << endl;
			cout << "NO" << "\t" << "Staff ID" << "\t" << "Started year" << "\t"<< "Encrypt password" << endl;
			cout << "--------------------------------------------------------" << endl;
			int r=0;
			string pass;
			char temp;
			while(tmp->next != NULL){
				string s;
				s = tmp->staffID.substr(0,2);
				stringstream num(s);
				int year=0;
			 	num >> year;
				pass = tmp->passStaff;
				int n = pass.size();
				if(n % 2 == 0){
					for(int i=0;i<n/2-1;i++){
						temp = pass[i];
						pass[i] = pass[n-i-1];
						pass[n-i-1] = temp;
					}
				}else if(n % 2 != 0){
					for(int i=0;i<n/2;i++){
						temp = pass[i];
						pass[i] = pass[n-i-1];
						pass[n-i-1] = temp;
					}
				}
				cout <<  r+1 << "." << "\t" << tmp->staffID << "\t    " << (year+2500)-543 << "\t   " << pass;
				cout << endl;
				tmp = tmp->next;
				r++;
			}
		}
		
		bool Checkpass(string user,string pasw){
			node *tmp =head;
			while(tmp != NULL){
				if(tmp->passStaff == pasw && tmp->staffID == user){
					return true;
					break;
				}
				tmp = tmp->next;
			}//while
		}
};

int main(){
	Faculty *fac = new Faculty;
	Student *std = new Student;
	Staff *staff = new Staff;
	Check *c = new Check;
	int menu, menu_staff;
	int choose;
	string user,pass,check;
	fac->Loaddata_fac("faculty");
	std->Loaddata_std("student");
	staff->Loaddata_staff("staff");
/*	backtomenu:
	do{
		std->Show_Menu();
		cout << "Enter: ";
		cin >> menu;
		if(menu==1){
			std->Showdata_std();
		}else if(menu==2){
			do{
				staff->ShowMenu_staff();
				cout << "Enter: ";
				cin >> menu_staff;
					if(menu_staff==1){
						staff->Showdata_staff();
					}else if(menu_staff==2){
						staff->Showdata_academic_staff();
					}else if(menu_staff==3){
						staff->Showdata_staff_password();
					}else if(menu_staff==4){
						goto backtomenu;
					}
			}while(menu_staff!=4);
		}	
	}while(menu != 3);*/
	

	cout<<"====== BUUCHANA ======="<<endl;
		cout<<"1.User Login"<<endl;
		cout<<"2.Exit"<<endl;
	cout<<"======================"<<endl;
		cin>>choose;
		if(choose == 1){
	loop:		cout<<"======= Login ========"<<endl;
			cout<<"Enter Username: ";
				cin>>user;
			cout<<"Enter Password: ";
				cin>>pass;
			cout<<"======================"<<endl;
		}else{
			return 0;
		}

			check = user.substr(4,2);
			if(check == "01"){
				if(staff->Checkpass(user,pass) == true){
					cout << "============================== BUUCHANA "
						<< "=========================================" << endl;
						cout << "1.Student Information" << endl;
						cout << "2.Exit" << endl;
						cout << "========================================="
						<< "========================================\n" << endl;
					
				}else{
					cout << "!!!!!Invalid Username or Password!!!!" << endl;
						goto loop;
				}
							int choice;
						cin>>choice;
						if(choice == 1){
				menu:			std->Menutwo();
							int choose;
							cin>>choose;
							if(choose == 1){
								std->Showstd_case_one();
								goto menu;
							}else if(choose == 2){
								std->Showstd_case_two();
								goto menu;
							}else if(choose == 3){
								std->Showstd_case_three();
								goto menu;
							}else if(choose == 4){
								std->Showstd_case_for();
								goto menu;
							}
						}else if(choice == 2){
							return 0;
						}
				}else{
					cout << "!!!!!Invalid Username or Password!!!!" << endl;
				}if(check == "02"){
					if(staff->Checkpass(user,pass) == true){
						cout << "============================== BUUCHANA "
						<< "=========================================" << endl;
						cout << "1.Student Information" << endl;
						cout << "2.Staff Information" << endl;
						cout << "3.Exit" << endl;
						cout << "========================================="
						<< "========================================\n" << endl;
					}else{
						cout << "!!!!!Invalid Username or Password!!!!" << endl;
						goto loop;
					}
				}else{
					if(std->Checkpass(user,pass) == true ){
//						cout << "============================== BUUCHANA "
//							<< "=========================================" << endl;
//							cout << "1.Personal Check-in //Coming soon" << endl;
//							cout << "2.Exit" << endl;
//							cout << "========================================="
//							<< "========================================\n" << endl;
							c->Checking();
					}else{
					cout << "!!!!!Invalid Username or Password!!!!" << endl;
						goto loop;
					}
				}
				
}	


