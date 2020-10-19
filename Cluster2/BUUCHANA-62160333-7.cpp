/*
K:  Open file
LANG: CPP
AUTHOR: 62160333 Phumipat Katsuwan
MAJOR: SE
*/
#include<iostream>
#include <sstream>
#include<bits/stdc++.h>
#include<string>
#include<fstream>
#include <iomanip> 
using namespace std;
class DbLinkedList_f{
	 protected:
		class node {
			public:
				string Faculty,FacultyId;
				node *link;
				node *plink;
			public:
				node(string faculty ,string facultyId){
				Faculty = faculty;
				FacultyId = facultyId;
				link = NULL;
				plink = NULL;
				}
			};
		node *head;
		node *tail;
		int count;
	public :
		
		DbLinkedList_f(){
			this->head = NULL;
			this->tail = NULL;
			this->count = 0;
		}
		void add(string faculty,string facultyId){
			node* NewNode = new node(faculty,facultyId);
			if(head==NULL){
				head = NewNode;
				tail = NewNode;
				count++;
			}
			else{
				tail -> link = NewNode;
				NewNode -> plink = tail;
				tail = NewNode;
				count++;
			}
	}
		string getFaculty(string id){
			string sd;
			node*print = head;		
			for(int i=1;i<=count;i++){	
				//sd = print->FacultyId;	
				if(print->FacultyId == id){
					return print->Faculty;
				}	
				print = print->link; 				
			}
			//cout<<print->Faculty<<endl;
			return id;
		}
		void show(){
			node*print = head;		
			for(int i=1;i<=count;i++){		
				cout<<print->FacultyId<<endl;
				cout<<print->Faculty<<endl;
				print = print->link;
				}					 				
			}
};
class DbLinkedList_S{
	private :
		class node {
			public:
				DbLinkedList_f fac;
				string Id,FirstName,LastName,Tel,Faculty,Title,Pass;
				node *link;
				node *plink;
			public:
				node(string id ,string title,string firstname ,string lastname,string tel ,string pass){
				Id = id;
				Title = title;
				FirstName = firstname ;
				LastName = lastname;
				Tel = tel;
				
				Pass = pass;
				link = NULL;
				plink = NULL;
				}
			};
			DbLinkedList_f fac;
		node *head;
		node *tail;
		int count;
	public :
		
		DbLinkedList_S(){
			string filein,faculty,facultyId;
				ifstream file_fac("faculty.dat", ios::in);
			while(getline(file_fac,filein)){
					filein.erase(0,filein.find('f')+2);
				faculty = filein.substr(0,filein.find(','));
				       filein.erase(0,filein.find(',')+1);
				facultyId = filein.substr(0,filein.find(' '));
				      filein.erase(0,filein.find(',')+1);
			fac.add(faculty,facultyId);	
	}	
	
			this->head = NULL;
			this->tail = NULL;
			this->count = 0;
		}
		void add_s( string id ,string title,string firstname,string lastname ,string tel ,string pass){
			node* NewNode = new node(id ,title ,firstname ,lastname ,tel ,pass);
			if(head==NULL){
				head = NewNode;
				tail = NewNode;
				count++;
			}
			else{
				tail -> link = NewNode;
				NewNode -> plink = tail;
				tail = NewNode;
				count++;
			}
		}

		

		void show_staff( ){
			string idck;
			node*print = head;
			cout<<"================================ BUUCHANA ===================================="<<endl;
			cout <<setw(7)<<left;
			cout<<"NO";
			cout <<setw(15)<<left;
			cout <<"Staff ID";
			cout <<setw(30)<<left;
			cout<<"Staff Name";
			cout<<setw(15)<<left;
			cout<<"Tel";
			cout<<"Department"<<endl;
			cout<<"-------------------------------------------------------------------------------"<<endl;
			for(int i=1;i<=count;i++){
				string f = print->FirstName;
				string l = print->LastName;
				string t = print->Tel;
				print->FirstName = print->FirstName+' '+print->LastName;
				cout <<setw(5)<<left;
				cout<<i;
				cout <<setw(13)<<left;
				cout << print->Id;
				cout <<setw(3)<<left;
				cout <<print->Title;
				cout <<setw(25)<<left;
				cout<<print->FirstName;
			//	cout<<setw(15)<<left;
			//	cout<<print->LastName;
				cout<<setw(17)<<left;
				cout<<print->Tel;
				idck = print->Id.substr(2,2);
				cout<< fac.getFaculty(idck)<<endl;
			//	cout<<print->Faculty<<endl;
				print->FirstName = f;
				print->LastName = l;
				print->Tel = t;
				print = print->link; 				
			}
		}
		void show_a(){
			string idck;
			int no=1;
			node*print = head;
			cout<<"================================ BUUCHANA ===================================="<<endl;
			cout <<setw(5)<<left;
			cout<<"NO";
			cout <<setw(23)<<left;
			cout <<"Academic Staff ID";
			cout <<setw(10)<<left;
			cout <<"Gender";
			cout <<setw(25)<<left;
			cout<<"Academic Staff Name";
			cout<<setw(25)<<left;
			cout<<"Tel";
			cout<<"Department"<<endl;
			cout<<"-------------------------------------------------------------------------------"<<endl;
			for(int i=1;i<=count;i++){
				if(print->Id[4]=='0' && print->Id[5]=='1'){					
				cout <<setw(10)<<left;
				cout<<no;
				no++;
				cout <<setw(18)<<left;
				cout << print->Id;
				cout <<setw(10)<<left;
				string f = print->FirstName;
				string l = print->LastName;
				string t = print->Tel;
				if(print->Title=="Mr."){
					cout<<"Male";
				}
				else if(print->Title=="Ms."){
					cout<<"Female";
				}
				string mid = print->LastName.substr(0,print->LastName.find(' '));	
						if(mid==print->LastName){
							print->FirstName = print->FirstName.substr(0,1)+'.'+' ';
						}
						else{
							print->FirstName = print->FirstName;
							print->LastName.erase(0,print->LastName.find(' ')+1);
							print->LastName = mid = ' '+mid.substr(0,1)+'.'+' '+print->LastName;
						}				      	
				print->Tel.at(3) = ')';
				print->Tel = "("+print->Tel.substr(0,4)+print->Tel.substr(4,3)+print->Tel.substr(8,4);				
				cout <<setw(25)<<left;
				print->FirstName = print->FirstName+print->LastName;
				cout<<print->FirstName;
				cout<<setw(25)<<left;
			//	cout<<print->LastName;
			//	cout<<setw(19)<<left;
				cout<<print->Tel;
				idck = print->Id.substr(2,2);
				cout<< fac.getFaculty(idck)<<endl;
				print->FirstName = f;
				print->LastName = l;
				print->Tel = t;
				 
				}	
						print = print->link;					
			}
	}
	void show_p(){
			string ring ;
			string king ;
			int no=1;
			string tump;
			int rl;
			node*print = head;
			cout<<"================================ BUUCHANA ===================================="<<endl;
			cout <<setw(5)<<left;
			cout<<"NO";
			cout <<setw(13)<<left;
			cout <<"Staff ID";
			cout <<setw(20)<<left;
			cout <<"Started year";
			cout <<setw(25)<<left;
			cout<<"Encrypt password"<<endl;

			cout<<"-------------------------------------------------------------------------------"<<endl;
			for(int i=1;i<=count;i++){
								
				cout <<setw(5)<<left;
				cout<<i;
				
				cout <<setw(17)<<left;
				cout << print->Id;
				
				tump = "25";
				
				cout<<setw(17)<<left;
				string p;
				string pas = print->Pass;
				
				p=print->Id.substr(0,2);
			//	print->Id=tump+print->Id.substr(0,2);
				stringstream ss ;
				int rl1;
				ss<<p;
				ss>>rl1;
				ss.clear();
				rl1 = rl1 +1957;
				
				cout<<rl1;
				cout<<setw(17)<<left;
				if(print->Pass.size()%2!=0){
					ring = print->Pass;
					king = string(ring.rbegin(),ring.rend());
					print->Pass = king;
					cout<< king<<endl;
					print->Pass = pas;
				}
				else{
					int ging;
					ging = print->Pass.size()/2;
					char aink =  print->Pass[ging-1];
					char sing =  print->Pass[ging];
					ring = print->Pass;
					king = string(ring.rbegin(),ring.rend());
					print->Pass = king;
					king[ging-1] = aink;
					king[ging] = sing;
					cout<< king<<endl;
					print->Pass = pas;
				}
				
				print = print->link; 			
		}		
}
		int checkin( string id,string pass){
				node *print = head;
			for(int i=0;i<count;i++){
				if(print->Id == id && print->Pass==pass){
				return 1;
				}
				print = print->link;
			}//for
			return 2;
	}
};
class DbLinkedList: public DbLinkedList_f{
	private :
		class node {
			public:
				string Id,Name,Tel,Pass;
				node *link;

				node *plink;
			public:
				node(string id ,string name ,string tel,string pass){
				Id = id;
				Name = name+'.';
				Tel = tel;
				Pass = pass;
				
				link = NULL;
				plink = NULL;
				}
			};
		DbLinkedList_f fac;
		node *head;
		node *tail;
		int count;
	public :
		
		DbLinkedList(){
			string filein,faculty,facultyId;
				ifstream file_fac("faculty.dat", ios::in);
			while(getline(file_fac,filein)){
					filein.erase(0,filein.find('f')+2);
				faculty = filein.substr(0,filein.find(','));
				       filein.erase(0,filein.find(',')+1);
				facultyId = filein.substr(0,filein.find(' '));
				      filein.erase(0,filein.find(',')+1);
			fac.add(faculty,facultyId);	
	}	
			this->head = NULL;
			this->tail = NULL;
			this->count = 0;
			
		}
		void add( string id ,string name ,string tel,string pass){
			node* NewNode = new node(id ,name , tel, pass);
			if(head==NULL){
				head = NewNode;
				tail = NewNode;
				count++;
			}
			else{
				tail -> link = NewNode;
				NewNode -> plink = tail;
				tail = NewNode;
				count++;
			}
			
		}
		void show( ){
				string idck ;
			node*print = head;
			cout<<"================================ BUUCHANA ===================================="<<endl;
			cout <<setw(5)<<left;
			cout<<"NO";
			cout <<setw(15)<<left;
			cout <<"Student ID";
			cout <<setw(22)<<left;
			cout<<"Name";
			cout<<setw(15)<<left;
			cout<<"Tel";
			cout<<"Department"<<endl;
			cout<<"-------------------------------------------------------------------------------"<<endl;
			for(int i=1;i<=count;i++){
				
				cout <<setw(5)<<left;
				cout<<i;
				cout <<setw(13)<<left;
				cout << print->Id;
				cout <<setw(20)<<left;
				cout<<print->Name;
				cout<<setw(17)<<left;
				cout<<print->Tel;
				idck = print->Id.substr(2,2);
				cout<< fac.getFaculty(idck)<<endl;
			//	cout<<DbLinkedList_f::getFaculty(idck)<<endl;
				//print->Faculty<<endl;
				print = print->link; 				
			}
   }
   void show_backward(){
   			string idck;
			node*print=tail;
			cout<<"================================ BUUCHANA ===================================="<<endl;
			cout <<setw(5)<<left;
			cout<<"NO";
			cout <<setw(15)<<left;
			cout <<"Student ID";
			cout <<setw(22)<<left;
			cout<<"Name";
			cout<<setw(15)<<left;
			cout<<"Tel";
			cout<<"Department"<<endl;
			cout<<"-------------------------------------------------------------------------------"<<endl;
			for(int i=1;i<=count;i++){
				
				cout <<setw(5)<<left;
				cout<<i;
				cout <<setw(13)<<left;
				cout << print->Id;
				cout <<setw(20)<<left;
				cout<<print->Name;
				cout<<setw(17)<<left;
				cout<<print->Tel;
				idck = print->Id.substr(2,2);
				cout<< fac.getFaculty(idck)<<endl;
				print=print->plink;
			}
			cout<<endl;
		}
	int checkin( string id,string pass){
			node*print = head;
			for(int i=1;i<=count;i++){
				if(print->Id == id && print->Pass == pass){
					return 1; 
				}
				print = print->link;
			}
		return 2;
	}
	void sortAscending(){
		string temp;
		string ne , pr;
		string id,name,tel,pass;
		int p = 0;
		int a = 0;   		
		node* i= head;	
		node* j= head;
		for(i=head;i!=NULL;i=i->link){										
			for(j=i;j!=NULL;j=j->link){				
				stringstream ss;
				ne = i->Id;
				ss<<ne;
				ss>>p;
				stringstream sss;
				pr = j->Id;
				sss<<pr;
				sss>>a;
				if(p>a){
					id = i->Id;
					name = i->Name;
					tel = i->Tel;
					pass = i->Pass;
					i->Id = j->Id;
					i->Name = j->Name;
					i->Tel = j->Tel;
					i->Pass = j->Pass;
					j->Id = id;
					j->Name = name;
					j->Tel = tel;
					j->Pass = pass;					
				}
			}
		}
	show();
	}
void sortDescending(){
		string temp;
		string ne , pr;
		string id,name,tel,pass;
		int p = 0;
		int a = 0;   		
		node* i= head;	
		node* j= head;
		for(i=head;i!=NULL;i=i->link){										
			for(j=i;j!=NULL;j=j->link){				
				stringstream ss;
				ne = i->Id;
				ss<<ne;
				ss>>p;
				stringstream sss;
				pr = j->Id;
				sss<<pr;
				sss>>a;
				if(p<a){
					id = i->Id;
					name = i->Name;
					tel = i->Tel;
					pass = i->Pass;
					i->Id = j->Id;
					i->Name = j->Name;
					i->Tel = j->Tel;
					i->Pass = j->Pass;
					j->Id = id;
					j->Name = name;
					j->Tel = tel;
					j->Pass = pass;					
				}
			}
		}
	show();
	}
	void sortNameAscending(){
		string temp;
		string ne , pr;
		string id,name,tel,pass;
		int p = 0;
		int a = 0;   		
		node* i= head;	
		node* j= head;
		for(i=head;i!=NULL;i=i->link){										
			for(j=i;j!=NULL;j=j->link){				
				if(i->Name > j->Name){
					id = i->Id;
					name = i->Name;
					tel = i->Tel;
					pass = i->Pass;
					i->Id = j->Id;
					i->Name = j->Name;
					i->Tel = j->Tel;
					i->Pass = j->Pass;
					j->Id = id;
					j->Name = name;
					j->Tel = tel;
					j->Pass = pass;
					
				}
			}
		}
	show();
	}
void sortNameDescending(){
		string temp;
		string ne , pr;
		string id,name,tel,pass;
		int p = 0;
		int a = 0;   		
		node* i= head;	
		node* j= head;
		for(i=head;i!=NULL;i=i->link){										
			for(j=i;j!=NULL;j=j->link){				
				if(i->Name < j->Name){
					id = i->Id;
					name = i->Name;
					tel = i->Tel;
					pass = i->Pass;
					i->Id = j->Id;
					i->Name = j->Name;
					i->Tel = j->Tel;
					i->Pass = j->Pass;
					j->Id = id;
					j->Name = name;
					j->Tel = tel;
					j->Pass = pass;
					
				}
			}
		}
	show();
	}
};
int main(){
	DbLinkedList Data_student;
	DbLinkedList_S Data_staff;
	DbLinkedList_f Data_faculty;	
	
	int Option;
	int No;
	int i =0;
	string facultyId;
	string faculty;
	string idck;
	string studentID,num,name,tel,filein,filestudent,filename,line,pass,title,mid;
	ifstream file_stu("student.dat", ios::in);
			while(getline(file_stu,filein)){
				num = filein.substr(0,filein.find(','));
				      filein.erase(0,filein.find(',')+1);
				name = filein.substr(0,filein.find(' ')+2);
				      filein.erase(0,filein.find(',')+1);
				tel = filein.substr(0,filein.find(','));
				      filein.erase(0,filein.find(',')+1);
				pass = filein.substr(0,filein.find(','));
				      filein.erase(0,filein.find(',')+1);
			Data_student.add(num,name,tel,pass);	
			}
	ifstream file_staff("staff.dat", ios::in);
			string firstname,lastname;
			while(getline(file_staff,filein)){
				num = filein.substr(0,filein.find(','));
				      filein.erase(0,filein.find(',')+1);
				title = filein.substr(0,filein.find(' '));
				      filein.erase(0,filein.find(' ')+1);
				firstname = filein.substr(0,filein.find(' '));
				      filein.erase(0,filein.find(' ')+1);
				lastname = filein.substr(0,filein.find(','));
				      filein.erase(0,filein.find(',')+1);				     
				tel = filein.substr(0,filein.find(','));
				      filein.erase(0,filein.find(',')+1);
				pass = filein.substr(0,filein.find(','));
				      filein.erase(0,filein.find(',')+1);	
				Data_staff.add_s(num,title,firstname,lastname,tel,pass);			
			}	
			
		int choose;
FIRST:
		do{
		cout<<"================BUUCHANA==============="<<endl;
		cout<<"1.User Login"<<endl;
		cout<<"2.Exit"<<endl;
		cout<<"======================================="<<endl;
		cout<<"Enter: ";		
		cin>>choose;
		string user;
		string passInput;
		string subuser;
		if(choose == 1 ){
			cout<<"=======Login========"<<endl;
			cout<<"Enter UserName : ";
			cin>>user;
			cout<<"Enter password : ";
			cin>>passInput;
			cout<<"===================="<<endl;			
			subuser = user.substr(4,2);
			if(user.length()==8){
				if(Data_student.checkin(user,passInput)==1){
					int optionStudent;
					do{
					cout<<"====== BUUCHANA ======="<<endl;
					cout<<"1.Personal Check-in "<<endl;//Coming soon
					cout<<"2.Exit"<<endl;
					cout<<"======================"<<endl;
					cout<<"Enter: ";
					cin>>optionStudent;
					if(optionStudent == 1){
						cout<<"Coming soon"<<endl;
					//	goto FIRST;
					}
					else{
						goto FIRST;
					}
				}while(optionStudent!=2);
			}
				else if(Data_student.checkin(user,passInput)==2){
					 cout<<"!!!!!Invalid Username or Password!!!!"<<endl;
				}
			}
			else if(user.length()==10){
				if(subuser == "01"&&Data_staff.checkin(user,passInput)==1){
					int optionStaff;
PROFESSOR:
					do{
					cout<<"====== BUUCHANA ======="<<endl;
					cout<<"1.Student Information"<<endl;
					cout<<"2.Exit"<<endl;
					cout<<"======================"<<endl;
					cout<<"Enter: ";
					cin>>optionStaff;
					if(optionStaff == 1){
					do{
					cout<<"	====== Student Information ======="<<endl;
					cout<<"1.Student ID Ascending"<<endl;
					cout<<"2.Student ID Descending"<<endl;
					cout<<"3.Student Name Ascending"<<endl;
					cout<<"4.Student Name Descending"<<endl;
					cout<<"======================"<<endl;
					cout<<"Enter: ";
					cin>>optionStaff;
						if(optionStaff == 1){
							Data_student.sortAscending();
							cout<<"==============================================================================="<<endl;
						}
						else if(optionStaff == 2){
							Data_student.sortDescending();
							cout<<"==============================================================================="<<endl;
						}
						else if(optionStaff == 3){
							Data_student.sortNameAscending();
							cout<<"==============================================================================="<<endl;
						}
						else if(optionStaff == 4){
							Data_student.sortNameDescending();
							cout<<"==============================================================================="<<endl;
						}
					}while(optionStaff!=5);
				}
					else{
						goto FIRST;
					}
					}while(optionStaff!=2);
				}
				else if(subuser == "02"&&Data_staff.checkin(user,passInput)==1){
MENU:
					do{
					cout<<"====================== BUUCHANA ============================="<<endl;
					cout<<"1.Student Registration"<<endl;
					cout<<"2.Staff Information"<<endl;
					cout<<"3.Exit"<<endl;
					cout<<"=============================================================="<<endl;
					cout<<"Enter: ";
					cin>>Option;
					if(Option == 1){
						Data_student.show();
						cout<<"==============================================================================="<<endl;
					}
					else if(Option == 2){
						int optionA;
						do{
						cout<<"====================== BUUCHANA ============================="<<endl;
						cout<<"1.Overall Staff Information"<<endl;
						cout<<"2.Academic staff Information"<<endl;
						cout<<"3.User account management"<<endl;
						cout<<"4.Return to main menu"<<endl;
						cout<<"=============================================================="<<endl;
						cout<<"Enter: ";
						optionA = 0;
						cin>>optionA;
						if(optionA == 1){
							Data_staff.show_staff();
							cout<<"==============================================================================="<<endl;
						}
						else if(optionA == 2){
							Data_staff.show_a();
							cout<<"==============================================================================="<<endl;
						}
						else if(optionA == 3){
							Data_staff.show_p();
							cout<<"==============================================================================="<<endl;
						}
						else if(optionA == 4){
							goto MENU;	
							
						}
					
						}while(optionA!=4);
					}
				}while(Option!=3);
								}
								else if(Data_staff.checkin(user,passInput)==2){
									cout<<"!!!!!Invalid Username or Password!!!!"<<endl;
								}			
			}
			else if(user.length()!=8&&user.length()!=10){
			cout<<"!!!!!Invalid Username or Password!!!!"<<endl;
			}	
		}
				
	}while(choose!=2);

}//main
