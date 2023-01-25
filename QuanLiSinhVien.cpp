#include<iostream>
#include<string.h>
#include<stdio.h>
#include<iomanip>
#include<conio.h>
#include<fstream>
using namespace std;

class Date_Of_Birth{
	public:
		int Day,Month,Year;
	public:
		Date_Of_Birth(){}
		Date_Of_Birth(int D ,int M,int Y){
			this->Day=D;
			this->Month = M;
			this->Year=Y;
		}
		~Date_Of_Birth(){}
		void Input_Date();
		void Output_Date();
};
void Date_Of_Birth::Input_Date(){
	cout<<"\n\t-Nhap ngay sinh-\n";
	cout<<"\nNhap ngay: "; 
	do{ 
		cin>>Day;
		if(Day <=0 ||Day >31)
			cout<<"Khong co nam nay!";
	}while(Day <=0 ||Day >31);
	cout<<"Nhap thang: ";
	do{
		cin>>Month;
		if(Month <=0 ||Month >12)
			cout<<"->Khong co thang nay!";
	}while(Month <=0 ||Month >12 );
	cout<<"Nhap nam: "; 
	do{
		cin>>Year;
		if(Year <=0 ||Year >2023)
			cout<<"->Khong co nam nay!";
	}while(Year <=0 ||Year >2023);
}

void Date_Of_Birth::Output_Date(){
	cout<<"|"<<setw(2)<<Day<<"/"<<setw(2)<<Month<<"/"<<setw(4)<<Year<<"|";
}
class Student_Management{
    public:
        char Number_Code[10];
        char Name[10];
        char Classes[10];
        char Home_Town[10];
    public:
        Student_Management(){}
        Student_Management(char*ms,char*ht,char*Classes,char*qq){
            strcpy(this->Number_Code,ms);
            strcpy(this->Name,ht);
            strcpy(this->Classes,Classes);
            strcpy(this->Home_Town,qq);
        }
        ~Student_Management(){}
        void Input_list();
        void Display();
};
void Student_Management::Input_list(){
    cout<<"\t-Nhap sinh vien-\n";
    cout<<"\nNhap ma so: "; fflush(stdin); cin.getline(Number_Code,10);
    cout<<"Nhap ho ten: "; cin.getline(Name,10);
    cout<<"Nhap lop: "; cin.getline(Classes,10);
    cout<<"Nhap que quan: "; cin.getline(Home_Town,10);
}

void Student_Management::Display(){
    cout<<"|"<<setw(5)<<Number_Code<<"|"<<setw(15)<<Name<<"|"<<setw(10)<<Classes<<"|"<<setw(12)<<Home_Town;
}

class Scholarship_Management:public Student_Management,public Date_Of_Birth{
    public:
        float Math_point,Literature_point,English_point;
		int Practise_point;
    public:
        Scholarship_Management(){}
        Scholarship_Management(char*ms,char*ht,char*Classes,char*qq,float dt,float dv,float da,int drl,int D,int M,int Y)
		:Student_Management(ms,ht,Classes,qq),Date_Of_Birth(D,M,Y){
            this->Math_point = dt;
            this->Literature_point = dv;
            this->English_point = da;
			this->Practise_point =drl;
        }
        ~Scholarship_Management(){}
        
        float Medium_point(){
            return (this->Math_point + this->Literature_point +this->English_point) / 3;
        }
        
        string Ranked_academic(){
			if(Medium_point() >=9 && Medium_point() <=10 &&(Practise_point >=90))
				return "Xuat sac";
            else if(Medium_point() >= 8 && Medium_point() <9 && (Practise_point >=80 && Practise_point < 90))
                return "Gioi";
            else if(Medium_point() >=6.5 && Medium_point() <8 && (Practise_point >=60 && Practise_point < 80))
                return "Kha";
            else if(Medium_point() >=4 && Medium_point() <6.5)
				return "Trung Binh";
            else    
				return "Yeu";
        }
    
		int Scholarships(){
			if(Ranked_academic()=="Xuat sac") 
				return 10000000;
			else if(Ranked_academic()=="Gioi") 
				return 8000000;
			else if(Ranked_academic()=="Kha") 
				return 6000000;
			else return 0;
		}

        friend bool operator < (Scholarship_Management a,float b){
        	if(a.Medium_point() < b)
        		return true;
        	else
        		return false;
		}
		
		friend bool operator < (Scholarship_Management c ,char*d ){
			return strcmp(c.Name,d)<0;
		}
		
		bool Code_search(const char*e){
			return strcmp(this->Number_Code,e)==0;
		}
		
		bool Name_search(const char*f){
			return strcmp(this->Name,f)==0;
		}
		
		bool Class_search(const char*g){
			return strcmp(this->Classes,g)==0;
        }
        friend istream&operator>>(istream&is,Scholarship_Management &ql);
        friend ostream&operator<<(ostream&os,Scholarship_Management ql);
};
void Star_line(){
	for(int i=0;i<57;i++){cout<<"*";}
	cout<<"\n";
}

void Double_line(){
    for(int i=0;i<137;i++){cout<<"=";}
    cout<<"\n";
}

void Width_line(){
	for(int i=0;i<137;i++){cout<<"-";}
	cout<<"\n";
}

void Title(){
    cout<<"|"<<setw(5)<<left<<"Ma so"<<"|"<<setw(15)<<left<<"Ho ten"<<"|"<<setw(10)<<left<<"Lop"<<"|"<<setw(12)<<left<<"Que quan"
        <<"|"<<setw(10)<<"Ngay sinh"<<"|"<<setw(5)<<"Diem toan"<<"|"<<setw(8)<<"Diem van"<<"|"<<setw(8)<<"Diem anh"<<"|";
    cout<<setw(13)<<"Diemtrungbinh"<<"|"<<setw(10)<<"Hoc luc"<<"|"<<setw(13)<<"Diem ren luyen"<<"|"<<setw(10)<<"Hoc bong"<<setw(2)<<"|"<<endl;
}

void Table_line(){
	cout<<"+"<<"-----"<<"+"<<"---------------"<<"+"<<"----------"<<"+"<<"------------"<<"+"
        <<"----------"<<"+"<<"---------"<<"+"<<"--------"<<"+"<<"--------"<<"+";
    cout<<"-------------"<<"+"<<"----------"<<"+"<<"--------------"<<"+"<<"----------"<<"+"<<endl;
}
istream&operator>>(istream&is,Scholarship_Management & ql){
    ql.Student_Management::Input_list();
	ql.Date_Of_Birth::Input_Date();
    cout<<"\n\t-Nhap diem-\n";
    do{
		fflush(stdin);
		cout<<"\nNhap diem toan: "; is>>ql.Math_point;
    	cout<<"Nhap diem van: "; is>>ql.Literature_point;
		cout<<"Nhap diem anh: "; is>>ql.English_point;
		cout<<"Nhap diem ren luyen: "; is>>ql.Practise_point;
        if(ql.Math_point <0 || ql.Literature_point <0||ql.English_point <0 || ql.Practise_point<0|| ql.Math_point >10||ql.Literature_point >10 || ql.English_point >10||ql.Practise_point>100)
            cout<<"->Ban nhap sai!";
    }while(ql.Math_point <0 || ql.Literature_point <0||ql.English_point <0 ||ql.Practise_point<0 || ql.Math_point >10||ql.Literature_point >10 || ql.English_point >10||ql.Practise_point>100); 
    return is;
}
ostream&operator<<(ostream&os,Scholarship_Management ql){
    ql.Student_Management::Display();
	ql.Date_Of_Birth::Output_Date();
    os<<setw(9)<<ql.Math_point<<"|"<<setw(8)<<ql.Literature_point<<"|"<<setw(8)<<ql.English_point<<"|"<<setw(13)<<ql.Medium_point()<<"|"
        <<setw(10)<<ql.Ranked_academic()<<"|"<<setw(14)<<ql.Practise_point<<"|"<<setw(10)<<ql.Scholarships()<<setw(2)<<"|"<<endl; 
    return os;
}

void Input_Display(Scholarship_Management ql[],int n){
	int browse = 0;
    for(int i=0;i<n;i++){
		do{
			browse = 0;
			cout<<"\n$ Sinh vien thu "<<i+1<<" $"<<endl;
        	cin>>ql[i];
			for(int j=0;j<i;j++){
				if(ql[j].Number_Code == ql[i].Number_Code){
					cout<<"-Da co sinh vien nay,moi ban nhap lai!"<<endl;
					browse++; 
				}
			}
		}while(browse != 0);
    }cout<<endl; Double_line();
}

void Output_Display(Scholarship_Management ql[],int n){
	Table_line(); Title(); Table_line();
    for(int i=0;i<n;i++){
        cout<<ql[i];
        Table_line();
    } cout<<"\n\n";
} 

void Add_Display(Scholarship_Management ql[],int n){
	int add;
	cout<<"Nhap so sinh vien can them: "; cin>>add;
	int j=n;
	n += add;
	for(int i=j;i<n;i++){
		cout<<"Nhap sinh vien thu "<<i+1<<endl;
		cin>>ql[i];
	}	
	cout<<"\t\t\t\t---DANH SACH SINH VIEN SAU KHI THEM---\n";
	Table_line(); Title(); Width_line();
	for(int i=0;i<n;i++){
        cout<<ql[i];
        Table_line();
	}
}

void Alter_Display(Scholarship_Management ql[],int n){
	char alter[10];
	cout<<"-Nhap ma so sinh vien can sua: ";fflush(stdin); cin.getline(alter,10);
	for(int i=0;i<n;i++){
		if(strcmp(alter,ql[i].Number_Code)==0){
				cout<<"\t-Nhap sinh vien can sua-\n";
				cout<<"\nNhap ma so: "; fflush(stdin); cin.getline(ql[i].Number_Code,10);
				cout<<"Nhap ho ten: "; cin.getline(ql[i].Name,10);
				cout<<"Nhap lop: "; cin.getline(ql[i].Classes,10);
				cout<<"Nhap que quan: "; cin.getline(ql[i].Home_Town,10);
				Date_Of_Birth::Input_Date;
				cout<<"\n\t-Nhap diem-\n";
				do{
					cout<<"\nNhap diem toan: "; cin>>ql[i].Math_point;
					cout<<"Nhap diem van: ";cin>>ql[i].Literature_point;
					cout<<"Nhap diem anh: "; cin>>ql[i].English_point;
					cout<<"Nhap diem ren luyen: "; cin>>ql[i].Practise_point;
		        if(ql[i].Math_point <0 || ql[i].Literature_point <0||ql[i].English_point <0 || ql[i].Practise_point<0|| ql[i].Math_point >10||ql[i].Literature_point >10 || ql[i].English_point >10||ql[i].Practise_point>100)
		            cout<<"->Ban nhap sai!";
		    }while(ql[i].Math_point <0 || ql[i].Literature_point <0||ql[i].English_point <0 ||ql[i].Practise_point<0 || ql[i].Math_point >10||ql[i].Literature_point >10 || ql[i].English_point >10||ql[i].Practise_point>100); 
		cout<<"\t\t\t---DANH SACH SINH VIEN SAU KHI SUA---\n\n";
		Output_Display(ql,n);
		}
	}
}
void Delete_Display(Scholarship_Management ql[],int n){
	char deletes[10];
	cout<<"-Nhap ma so sinh vien can xoa: ";fflush(stdin); cin.getline(deletes,10);
	for(int i=0;i<n;i++){
		if(strcmp(deletes,ql[i].Number_Code)==0){
			ql[i] = ql[i+1];
			i--;
			n--;
		}
	}
	cout<<"\t\t\tDANH SACH SINH VIEN SAU KHI XOA\n";
	Output_Display(ql,n);
}
void Arrange_Medium_point_down(Scholarship_Management ql[],int n){
	for(int i=0;i<n;i++){
    	for(int j=i+1;j<n;j++){
    		if(ql[i].Medium_point() < ql[j].Medium_point()){
    			Scholarship_Management tg = ql[i];
    				ql[i] = ql[j];
    				ql[j] = tg;
			}
		}
	} 
	Output_Display(ql,n); 
	cout<<"\n\n";
} 

void Arrange_Medium_point_up(Scholarship_Management ql[],int n){
	for(int i=0;i<n;i++){
    	for(int j=i+1;j<n;j++){
    		if(ql[i].Medium_point() > ql[j].Medium_point()){
    			Scholarship_Management tg = ql[i];
    				ql[i] = ql[j];
    				ql[j] = tg;
			}
		}
	}
	Double_line();
	Output_Display(ql,n);
	cout<<"\n\n";
} 

void Arrange_Name(Scholarship_Management ql[],int n){
	char c[10];
	char d[10];
	for(int i=0;i<n;i++){
		strcpy(c,ql[i].Name);
    	for(int j=i+1;j<n;j++){
    		strcpy(d,ql[j].Name);
    		if(strcmp(strupr(c),strupr(d))<0){
    			Scholarship_Management tg = ql[i];
    				ql[i] = ql[j];
    				ql[j] = tg;
			}
		}
	}
	Double_line();
	Output_Display(ql,n);
}

void Code_search(Scholarship_Management ql[],int n){
	char g[10];
	cout<<"\t-Nhap ma can tim kiem: "; cin>>g;
	Double_line();
	cout<<"\t\t\tDANH SACH SINH VIEN"<<endl; Double_line(); Table_line(); Title(); Table_line();
	for(int i=0;i<n;i++){
		if(strcmp(ql[i].Number_Code,g)==0){
			cout<<ql[i];
			Table_line();
		} else cout<<"-Khong co ma sinh vien nay!";
	}
}

void Name_search(Scholarship_Management ql[],int n){
	char f[10];
	cout<<"\t-Nhap ten can tim kiem: "; cin>>f; Double_line();
	cout<<setw(60)<<"\t\t\tDANH SACH SINH VIEN"<<endl; Double_line(); Table_line(); Title(); Table_line();
	for(int i=0;i<n;i++){
		if(strcmp(ql[i].Name,f)==0){
			cout<<ql[i];
			Table_line();
		}else cout<<"-Khong co ten sinh vien nay!";
	}
}

void Class_search(Scholarship_Management ql[],int n){
	char g[10];
	cout<<"\t-Nhap lop can tim kiem: "; cin>>g; Double_line();
	cout<<setw(60)<<"\t\t\tDANH SACH SINH VIEN"<<endl; Double_line(); Table_line(); Title(); Table_line();
	for(int i=0;i<n;i++){
		if(strcmp(ql[i].Classes,g)==0){
			cout<<ql[i];
			Table_line();
		}else cout<<"-Khong co lop nay!";
	}
}

void Home_Town_search(Scholarship_Management ql[],int n){
	char q[10];
	cout<<"\t-Nhap que quan can tim kiem: "; cin>>q; Double_line();
	cout<<setw(60)<<"\t\t\tDANH SACH SINH VIEN"<<endl; Double_line(); Table_line(); Title(); Table_line();
	for(int i=0;i<n;i++){
		if(strcmp(ql[i].Home_Town,q)==0){
			cout<<ql[i];
			Table_line();
		}else cout<<"-Khong co que quan nay!";
	}
} 

void Write_FileTxt(Scholarship_Management ql[],int n){
	ofstream file;
	file.open("QLSV.txt",ios::out);
	if(!file){
		cerr<<"-Khong the ghi file .txt"<<endl;
	}
	file<<"Ma so"<<" "<<"Ho ten"<<" "<<"Lop"<<" "<<"Que quan"<<" "<<"Ngay sinh"<<" "<<"Diem toan"<<" "
		<<"Diem van"<<" "<<"Diem anh"<<" "<<"Diemtrungbinh"<<" "<<"Hoc luc"<<" "<<"Diem Ren Luyen"<<" "<<"Hoc bong"<<endl;
	Scholarship_Management::Date_Of_Birth();
	for(short int i=0;i<n;i++){
		file<<left<<ql[i].Number_Code<<" "<<left<<ql[i].Name<<" "<<left<<ql[i].Classes<<" "<<left<<ql[i].Home_Town<<" "
			<<left<<ql[i].Day<<"/"<<left<<ql[i].Month<<"/"<<left<<ql[i].Year<<","
			<<left<<ql[i].Math_point<<" "<<left<<ql[i].Literature_point<<" "<<left<<ql[i].English_point<<" "
			<<left<<ql[i].Medium_point()<<" "<<left<<ql[i].Ranked_academic()<<" "
			<<left<<ql[i].Practise_point<<" "<<left<<ql[i].Scholarships()<<endl;
	}
	file.close();
}

void Read_FileTxt(Scholarship_Management ql[],int n){
	ifstream file;
	file.open("QLSV.Txt",ios::in);
	if(!file){
		cerr<<"-Khong the doc file .txt"<<endl;
	}
    Table_line(); Title(); Table_line();
	Scholarship_Management::Date_Of_Birth();
	for(short int i=0;i<n;i++){

		cout<<"|"<<setw(5)<<ql[i].Number_Code<<"|"<<setw(15)<<ql[i].Name<<"|"<<setw(10)<<ql[i].Classes<<"|"<<setw(12)<<ql[i].Home_Town
       		<<"|"<<setw(2)<<ql[i].Day<<"/"<<setw(2)<<ql[i].Month<<"/"<<setw(4)<<ql[i].Year<<"|";
        cout<<setw(9)<<ql[i].Math_point<<"|"<<setw(8)<<ql[i].Literature_point<<"|"<<setw(8)<<ql[i].English_point<<"|"<<setw(13)<<ql[i].Medium_point()<<"|"
        	<<setw(10)<<ql[i].Ranked_academic()<<"|"<<setw(14)<<ql[i].Practise_point<<"|"<<setw(10)<<ql[i].Scholarships()<<"|"<<endl; Table_line();
	}
	file.close();
} 

void Write_FileCsv(Scholarship_Management ql[],int n){
	ofstream file;
	file.open("QLSV.csv",ios::out);
	if(!file){
		cerr<<"-Khong the ghi file .scv"<<endl;
	}
	file<<"Ma so"<<","<<"Ho ten"<<","<<"Lop"<<","<<"Que quan"<<","<<"Ngay sinh"<<","<<"Diem toan"<<","
		<<"Diem van"<<","<<"Diem anh"<<","<<"Diemtrungbinh"<<","<<"Hoc luc"<<","<<"Hoc bong"<<endl;
	Scholarship_Management::Date_Of_Birth();
	for(short int i=0;i<n;i++){
		file<<left<<ql[i].Number_Code<<","<<left<<ql[i].Name<<","<<left<<ql[i].Classes<<","<<left<<ql[i].Home_Town<<","
			<<left<<ql[i].Day<<"/"<<left<<ql[i].Month<<"/"<<left<<ql[i].Year<<","
			<<left<<ql[i].Math_point<<","<<left<<ql[i].Literature_point<<","<<left<<ql[i].English_point<<","
			<<left<<ql[i].Medium_point()<<","<<left<<ql[i].Ranked_academic()<<","
			<<left<<ql[i].Practise_point<<","<<left<<ql[i].Scholarships()<<endl;
	}
	file.close();
}
void Read_FileCsv(Scholarship_Management ql[],int n){
	ifstream file;
	file.open("QLSV.csv",ios::in);
	if(!file){
		cerr<<"-Khong the doc file .scv"<<endl;
	}
    Table_line(); Title(); Table_line();
	Scholarship_Management::Date_Of_Birth();
	for(short int i=0;i<n;i++){
		cout<<"|"<<setw(5)<<ql[i].Number_Code<<"|"<<setw(15)<<ql[i].Name<<"|"<<setw(10)<<ql[i].Classes<<"|"<<setw(12)<<ql[i].Home_Town
        	<<"|"<<setw(2)<<ql[i].Day<<"/"<<setw(2)<<ql[i].Month<<"/"<<setw(4)<<ql[i].Year<<"|";
        cout<<setw(9)<<ql[i].Math_point<<"|"<<setw(8)<<ql[i].Literature_point<<"|"<<setw(8)<<ql[i].English_point<<"|"<<setw(13)<<ql[i].Medium_point()<<"|"
        	<<setw(10)<<ql[i].Ranked_academic()<<"|"<<setw(14)<<ql[i].Practise_point<<"|"<<setw(10)<<ql[i].Scholarships()<<"|"<<endl; Table_line();
	}
	file.close();
} 

int main(){
	Scholarship_Management ql[100];
	int n;
	//Scholarship_Management*ql = new Scholarship_Management;
    continues:{
	int a; 
	cout<<"\n\n*******************<QUAN LI SINH VIEN>*******************"<<endl;
	cout<<"*\t\t\t\t\t\t\t*\n*\t Nhap 1.NHAP DANH SACH SINH VIEN                *"<<endl;      
	cout<<"*\t\t\t\t\t\t\t*\n*\t Nhap 2.DANH SACH THONG TIN SINH VIEN           *"<<endl;
    cout<<"*\t\t\t\t\t\t\t*\n*\t Nhap 3.THEM SINH VIEN LEN DANH SACH            *"<<endl;
    cout<<"*\t\t\t\t\t\t\t*\n*\t Nhap 4.SUA SINH VIEN TRONG DANH SACH           *"<<endl; 
	cout<<"*\t\t\t\t\t\t\t*\n*\t Nhap 5.XOA SINH VIEN TRONG DANH SACH           *"<<endl;  
    cout<<"*\t\t\t\t\t\t\t*\n*\t Nhap 6.XAP XEP DANH SACH SINH VIEN             *"<<endl;  
    cout<<"*\t\t\t\t\t\t\t*\n*\t Nhap 7.TIM KIEM THONG TIN SINH VIEN            *"<<endl;
	cout<<"*\t\t\t\t\t\t\t*\n*\t Nhap 8.GHI-DOC DU LIEU VAO FILE QLSV.txt       *"<<endl; 
	cout<<"*\t\t\t\t\t\t\t*\n*\t Nhap 9.GHI-DOC DU LIEU TU FILE QLSV.scv        *"<<endl; 
	cout<<"*\t\t\t\t\t\t\t*\n*\t Nhap 0.THOAT                                   *"<<endl;
	cout<<"*\t\t\t\t\t\t\t*"<<endl; 						  
	Star_line();
    cout<<" -Moi ban nhap: ";
    cin>>a;
    switch(a){
    	case 1: {
    		cout<<"\n->Nhap so sinh vien: ";
			do{
			    cin>>n;
		        if(n <0) cout<<"Ban nhap sai!\n";
			}while(n <0);
    		Input_Display(ql,n);
			break;
		}
		case 2: {
			Double_line();
			cout<<setw(60)<<"DANH SACH SINH VIEN"<<endl; Double_line();
			cout<<"\n"; 
    		Output_Display(ql,n);
			break;
		}
		case 3:{
			cout<<"\t\t\t---THEM THONG TIN SINH VIEN LEN DANH SACH---"<<endl;
			Add_Display(ql,n);
			break;
		}
		case 4:{
			cout<<"\t\t\t---SUA THONG TIN SINH VIEN TRONG DANH SACH---"<<endl;
			Alter_Display(ql,n);
			break;
		}
		case 5:{
			cout<<"\t\t\t---XOA THONG TIN SINH VIEN TRONG DANH SACH---"<<endl;
			Delete_Display(ql,n);
			break;
		}
		case 6:{
			int b; cout<<"\n";
			cout<<"===============XAP XEP DANH SACH SINH VIEN================="<<endl;  
			cout<<"\n Nhap 1.DANH SACH SINH VIEN GIAM DAN THEO DIEM TRUNG BINH"<<endl;
			cout<<"\n Nhap 2.DANH SACH SINH VIEN TANG DAN THEO DIEM TRUNG BINH"<<endl;
			cout<<"\n Nhap 3.DANH SACH SINH VIEN TANG DAN THEO TEN"<<endl; 
			cout<<"\n Nhap 0.THOAT"<<endl;
			for(int i=0;i<58;i++){cout<<"=";} cout<<"\n";
			cout<<"-Moi ban nhap: "; cin>>b; cout<<"\n";
			switch(b){
				case 1:{
					cout<<"\t\t---DANH SACH SINH VIEN GIAM DAN THEO DIEM TRUNG BINH---\n"<<endl; Double_line();
					cout<<"\t\t\tDANH SACH SINH VIEN"<<endl;
					Arrange_Medium_point_down(ql,n);
					break;
				}
				case 2:{
					cout<<"\t\t---DANH SACH SINH VIEN TANG DAN THEO DIEM TRUNG BINH---\n"<<endl; Double_line();
					cout<<"\t\t\tDANH SACH SINH VIEN"<<endl; 
					Arrange_Medium_point_up(ql,n);
					break;
				}
				case 3:{
					cout<<"\t\t---DANH SACH SINH VIEN TANG DAN THEO TEN---\n"<<endl; Double_line();
					cout<<"\t\t\tDANH SACH SINH VIEN"<<endl; 
				    Arrange_Name(ql,n);
					break;
				}
				stop1:case 0:exit(0);
				default:
				cout<<"->Ban nhap khong dung!";
				break;
			}
			char answer1;	
			cout<<"-Ban muon tiep tuc (y/n)?: ";
			cin>>answer1;
			if(answer1=='y' || answer1=='Y') goto continues;
			if(answer1=='n' || answer1=='N') goto stop1;
		}
		case 7: int c; cout<<"\n";
			cout<<"=================XAP XEP SINH VIEN=================="<<endl; 
			cout<<"\n Nhap 1.DANH SACH SINH VIEN TIM KIEM THEO MA SO"<<endl;
			cout<<"\n Nhap 2.DANH SACH SINH VIEN TIM KIEM THEO TEN"<<endl;
			cout<<"\n Nhap 3.DANH SACH SINH VIEN TIM KIEM THEO LOP"<<endl;
			cout<<"\n Nhap 4.DANH SACH SINH VIEN TIM KIEM THEO QUE QUAN"<<endl; 
			cout<<"\n Nhap 0.THOAT"<<endl;
			for(int i=0;i<63;i++){cout<<"=";} cout<<"\n";
			cout<<"-Moi ban nhap: "; cin>>c;  cout<<"\n";
			switch(c){
				case 1:{
					cout<<"\t\t---DANH SACH SINH VIEN TIM KIEM THEO MA SO---\n"<<endl; 
				    Code_search(ql,n);
					break;
				}
				case 2:{
					cout<<"\t\t---DANH SACH SINH VIEN TIM KIEM THEO TEN---\n"<<endl; 
				    Name_search(ql,n);
					break;
				}
				case 3:{
					cout<<"\t\t---DANH SACH SINH VIEN TIM KIEM THEO LOP---\n"<<endl;
				    Class_search(ql,n);
					break;
				}
				case 4:{
					cout<<"\t\t---DANH SACH SINH VIEN TIM KIEM THEO QUE QUAN---\n"<<endl; 
				    Home_Town_search(ql,n);
					break;
				}
				stop2:case 0:exit(0);
				default:
				cout<<"->Ban nhap khong dung!";
				break;
			}
			char answer2;	
			cout<<"-Ban muon tiep tuc (y/n)?: ";
			cin>>answer2;
			if(answer2=='y' || answer2=='Y') goto continues;
			if(answer2=='n' || answer2=='N') goto stop2;
			
		case 8:{
			int d; cout<<"\n";
			cout<<"=================GHI DU LIEU VAO FILE QLSV.txt==================";
			cout<<"\n\t\tNhap 1.GHI DU LIEU VAO FILE QLSV.text";
			cout<<"\n\t\tNhap 2.DOC DU LIEU TU FILE QLSV.text";
			cout<<"\n\t\tNhap 0.THOAT"; cout<<"\n";
			for(int i=0;i<=65;i++){cout<<"=";}
			cout<<"\n-Moi ban nhap: "; cin>>d;
			switch (d)
			{
			case 1:
				cout<<"\n\t\t\t---GHI DU LIEU VAO FILE QLSV.txt---"<<endl;
				Output_Display(ql,n);
				Write_FileTxt(ql,n);
				cout<<"\n-Ghi file .txt thanh cong";
				break;
			case 2:
				cout<<"\n\t\t\t---DOC DU LIEU VAO FILE QLSV.txt---"<<endl;
				Read_FileTxt(ql,n);
				cout<<"\n->Doc file .txt thanh cong";
				break;
			stop3:case 0:exit(0);
			default:
				cout<<"->Ban nhap khong dung!";
				break;
			}
			char answer3;
			cout<<"-Ban muon tiep tuc (y/n)?: ";
			cin>>answer3;
			if(answer3=='y' || answer3=='Y') goto continues;
			if(answer3=='n' || answer3=='N') goto stop3;
		}	
		case 9:{
			int e; cout<<"\n";
			cout<<"================GHI DU LIEU VAO FILE QLSV.scv=================";
			cout<<"\n\t\tNhap 1.GHI DU LIEU VAO FILE QLSV.scv";
			cout<<"\n\t\tNhap 2.DOC DU LIEU TU FILE QLSV.scv"; 
			cout<<"\n\t\tNhap 0.THOAT"; cout<<"\n";
			for(int i=0;i<=63;i++){cout<<"=";} cout<<"\n";
			cout<<"\n-Moi ban nhap: "; cin>>e;
			switch (e)
			{
			case 1:
				cout<<"\n\t\t\t---GHI DU LIEU VAO FILE QLSV.scv---"<<endl;
				Output_Display(ql,n);
				Write_FileCsv(ql,n);
				cout<<"\n->Ghi file .scv thanh cong.";
				break;
			case 2:
				cout<<"\n\t\t\t---DOC DU LIEU TU FILE QLSV.scv---"<<endl;
				Read_FileCsv(ql,n);
				cout<<"\n->Doc file .scv thanh cong.";
				break;
			stop5:case 0:exit(0);
			default:
				cout<<"->Ban nhap khong dung!";
				break;
			}
			char answer5;	
			cout<<"-Ban muon tiep tuc (y/n)?: ";
			cin>>answer5;
			if(answer5=='y' || answer5=='Y') goto continues;
			if(answer5=='n' || answer5=='N') goto stop5;
		}	
		stop:case 0:exit(0);
		default:
			cout<<"->Ban nhap khong dung!";
			break;
		}
	}
	char answer;	
	cout<<"-Ban muon tiep tuc (y/n)?: ";
	cin>>answer;
	if(answer=='y' || answer=='Y') goto continues;
	if(answer=='n' || answer=='N') goto stop;
	cout<<endl;
	return 0;
}

