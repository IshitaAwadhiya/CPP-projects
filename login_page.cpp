#include<iostream>
#include<fstream>

using namespace std;

class temp{
	string username,email,password;
	string searchName,searchPass,searchEmail;
	fstream file;
	public:
		void login();
		void signUP();
		void forgot();
}obj;

void temp :: signUP(){
	cout<<"\nEnter Your User Name:";
	cin>>username;
	cout<<"\nEnter Email Address:";
	cin>>email;
	cout<<"\nEnter Your Password:";
	cin>>password;
	
	file.open("loginData.txt",ios :: out | ios :: app);
	file<<username<<"*"<<email<<"*"<<password<<endl;
	file.close();
}

int main(){

	char choice;
	while(choice !=4){
	cout<<"\n1-Login";
	cout<<"\n2-Signup";
	cout<<"\n3-Forget Password";
	cout<<"\n4-Exit";
	cout<<"\nEnter your choice:";
	cin>>choice;
	
	switch(choice){
		case '1':
			obj.login();
		break;
		case '2':
			obj.signUP();
		break;
		case '3':
			obj.forgot();
		break;
		case '4':
			return 0;
		break;
		default:
			cout<<"Invalid Selection...!";
		
	}
}
}
/* : : scope resolution operator */


void temp :: login(){
	cout<<"------------LOGIN------------\n";
	cout<<"Enter Your User Name:"<<endl;
	cin>>searchName;
	cout<<"Enter Your Password:"<<endl;
	cin>>searchPass;
	
	file.open("loginData.txt", ios :: in);
	/*in openfile in read mode */
	
	getline(file,username,'*');
	getline(file,email,'*');
	getline(file,password,'\n');
	
	while(!file.eof()){
		if(username == searchName){
			if(password == searchPass){
				cout<<"\n Account Login Successfully....!";
				cout<<"\n Email:"<<email<<endl;\
			}
			else{
				cout<<"Password is incorrect....!";
			}
		}
	getline(file,username,'*');
	getline(file,email,'*');
	getline(file,password,'\n');
	
	}
	file.close();
}

void temp :: forgot(){
	cout<<"\n Enter Your Username:";
	cin>>searchName;
	cout<<"\n Enter Your Email Address:";
	cin>>searchEmail;
	
	file.open("loginData.txt", ios :: in);
	getline(file,username,'*');
	getline(file,email,'*');
	getline(file,password,'\n');
	
	while(!file.eof()){
		if(username == searchName){
			if(email == searchEmail){
				cout<<"\nAccount Found...!"<<endl;
				cout<<"Your Password:"<<password<<endl;
			}
			else{
				cout<<"Not Found....!\n";
			}
		}
		else{
			cout<<"Not Found....!\n";
		}
	getline(file,username,'*');
	getline(file,email,'*');
	getline(file,password,'\n');
	}
	file.close();
}
