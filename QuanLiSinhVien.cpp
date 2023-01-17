#include<iostream>
#include<string.h>
#include<stdio.h>
#include<iomanip>
#include<conio.h>
#include<fstream>
using namespace std;

struct NgaySinh{
    int Ngay,Thang,Nam;
};

class QuanLiSinhVien{
    public:
        char MaSo[10];
        char HoTen[10];
        char Lop[10];
        char QueQuan[10];
        NgaySinh ns;
    public:
        QuanLiSinhVien(){}
        QuanLiSinhVien(char*ms,char*ht,char*lop,char*qq){
            strcpy(this->MaSo,ms);
            strcpy(this->HoTen,ht);
            strcpy(this->Lop,lop);
            strcpy(this->QueQuan,qq);
        }
        ~QuanLiSinhVien(){}
        void NhapDanhSach();
        void ThongTin();
};
void QuanLiSinhVien::NhapDanhSach(){
    cout<<"\t-Nhap sinh vien-\n";
    cout<<"\nNhap ma so: "; fflush(stdin); cin.getline(MaSo,10);
    cout<<"Nhap ho ten: "; cin.getline(HoTen,10);
    cout<<"Nhap lop: "; cin.getline(Lop,10);
    cout<<"Nhap que quan: "; cin.getline(QueQuan,10);
    cout<<"\n\t-Nhap ngay sinh-\n";
    cout<<"\nNhap ngay: "; 
    do{ 
    	cin>>ns.Ngay;
    	if(ns.Ngay <=0 || ns.Ngay >31)
    		cout<<"Khong co ngay nay!";
	}while(ns.Ngay <=0 || ns.Ngay >31);
    cout<<"Nhap thang: ";
	do{
		cin>>ns.Thang;
		if(ns.Thang <=0 || ns.Thang >12)
			cout<<"->Khong co thang nay!";
	}while(ns.Thang <=0 || ns.Thang >12 );
    cout<<"Nhap nam: "; 
    do{
    	cin>>ns.Nam;
    	if(ns.Nam <=0 || ns.Nam >2023)
    		cout<<"->Khong co nam nay!";
	}while(ns.Nam <=0 || ns.Nam >2023);
}

void QuanLiSinhVien::ThongTin(){
    cout<<"|"<<setw(5)<<MaSo<<"|"<<setw(15)<<HoTen<<"|"<<setw(10)<<Lop<<"|"<<setw(12)<<QueQuan
        <<"|"<<setw(2)<<ns.Ngay<<"/"<<setw(2)<<ns.Thang<<"/"<<setw(4)<<ns.Nam<<"|";
}

class QuanLiDiem:public QuanLiSinhVien{
    public:
        float DiemToan,DiemVan,DiemAnh;
		int DiemRenLuyen;
    public:
        QuanLiDiem(){}
        QuanLiDiem(char*ms,char*ht,char*lop,char*qq,float dt,float dv,float da,int drl):QuanLiSinhVien(ms,ht,lop,qq){
            this->DiemToan = dt;
            this->DiemVan = dv;
            this->DiemAnh = da;
			this->DiemRenLuyen =drl;
        }
        ~QuanLiDiem(){}
        
        float DiemTrungBinh(){
            return (this->DiemToan + this->DiemVan +this->DiemAnh) / 3;
        }
        
        string HocLuc(){
			if(DiemTrungBinh() >=9 && DiemTrungBinh() <=10 &&(DiemRenLuyen >=90))
				return "Xuat sac";
            else if(DiemTrungBinh() >= 8 && DiemTrungBinh() <9 && (DiemRenLuyen >=80 && DiemRenLuyen < 90))
                return "Gioi";
            else if(DiemTrungBinh() >=6.5 && DiemTrungBinh() <8 && (DiemRenLuyen >=60 && DiemRenLuyen < 80))
                return "Kha";
            else if(DiemTrungBinh() >=4 && DiemTrungBinh() <6.5)
				return "Trung Binh";
            else    
				return "Yeu";
        }
    
		int HocBong(){
			if(HocLuc()=="Xuat sac") 
				return 10000000;
			else if(HocLuc()=="Gioi") 
				return 8000000;
			else if(HocLuc()=="Kha") 
				return 6000000;
			else return 0;
		}

        friend bool operator < (QuanLiDiem a,float b){
        	if(a.DiemTrungBinh() < b)
        		return true;
        	else
        		return false;
		}
		
		friend bool operator < (QuanLiDiem c ,char*d ){
			return strcmp(c.HoTen,d)<0;
		}
		
		bool TimKiemMa(const char*e){
			return strcmp(this->MaSo,e)==0;
		}
		
		bool TimKiemTen(const char*f){
			return strcmp(this->HoTen,f)==0;
		}
		
		bool TimKiemLop(const char*g){
			return strcmp(this->Lop,g)==0;
        }
        friend istream&operator>>(istream&is,QuanLiDiem &ql);
        friend ostream&operator<<(ostream&os,QuanLiDiem ql);
};
void dongnhande(){
	for(int i=0;i<57;i++){cout<<"*";}
	cout<<"\n";
}

void dongketieude(){
    for(int i=0;i<137;i++){cout<<"=";}
    cout<<"\n";
}

void dongkengang(){
	for(int i=0;i<137;i++){cout<<"-";}
	cout<<"\n";
}

void tieude(){
    cout<<"|"<<setw(5)<<left<<"Ma so"<<"|"<<setw(15)<<left<<"Ho ten"<<"|"<<setw(10)<<left<<"Lop"<<"|"<<setw(12)<<left<<"Que quan"
        <<"|"<<setw(10)<<"Ngay sinh"<<"|"<<setw(5)<<"Diem toan"<<"|"<<setw(8)<<"Diem van"<<"|"<<setw(8)<<"Diem anh"<<"|";
    cout<<setw(13)<<"DiemTrungBinh"<<"|"<<setw(10)<<"Hoc luc"<<"|"<<setw(13)<<"Diem ren luyen"<<"|"<<setw(10)<<"Hoc bong"<<setw(2)<<"|"<<endl;
}

void Bang(){
	cout<<"+"<<"-----"<<"+"<<"---------------"<<"+"<<"----------"<<"+"<<"------------"<<"+"
        <<"----------"<<"+"<<"---------"<<"+"<<"--------"<<"+"<<"--------"<<"+";
    cout<<"-------------"<<"+"<<"----------"<<"+"<<"--------------"<<"+"<<"----------"<<"+"<<endl;
}
istream&operator>>(istream&is,QuanLiDiem & ql){
    ql.QuanLiSinhVien::NhapDanhSach();
    cout<<"\n\t-Nhap diem-\n";
    do{
		cout<<"\nNhap diem toan: "; is>>ql.DiemToan;
    	cout<<"Nhap diem van: "; is>>ql.DiemVan;
		cout<<"Nhap diem anh: "; is>>ql.DiemAnh;
		cout<<"Nhap diem ren luyen: "; is>>ql.DiemRenLuyen;
        if(ql.DiemToan <0 || ql.DiemVan <0||ql.DiemAnh <0 || ql.DiemRenLuyen<0|| ql.DiemToan >10||ql.DiemVan >10 || ql.DiemAnh >10||ql.DiemRenLuyen>100)
            cout<<"->Ban nhap sai!";
    }while(ql.DiemToan <0 || ql.DiemVan <0||ql.DiemAnh <0 ||ql.DiemRenLuyen<0 || ql.DiemToan >10||ql.DiemVan >10 || ql.DiemAnh >10||ql.DiemRenLuyen>100); 
    return is;
}
ostream&operator<<(ostream&os,QuanLiDiem ql){
    ql.QuanLiSinhVien::ThongTin();
    os<<setw(9)<<ql.DiemToan<<"|"<<setw(8)<<ql.DiemVan<<"|"<<setw(8)<<ql.DiemAnh<<"|"<<setw(13)<<ql.DiemTrungBinh()<<"|"
        <<setw(10)<<ql.HocLuc()<<"|"<<setw(14)<<ql.DiemRenLuyen<<"|"<<setw(10)<<ql.HocBong()<<setw(2)<<"|"<<endl; 
    return os;
}
void NhapThongTin(QuanLiDiem ql[],int n){
	int duyet = 0;
    for(int i=0;i<n;i++){
		do{
			duyet = 0;
			cout<<"\n$ Sinh vien thu "<<i+1<<" $"<<endl;
        	cin>>ql[i];
			for(int j=0;j<i;j++){
				if(ql[j].MaSo == ql[i].MaSo){
					cout<<"-Da co sinh vien nay,moi ban nhap lai!"<<endl;
					duyet++; 
				}
			}
		}while(duyet != 0);
    }cout<<endl; dongketieude();
}

void XuatThongTin(QuanLiDiem ql[],int n){
	Bang(); tieude(); dongkengang();
    for(int i=0;i<n;i++){
        cout<<ql[i];
        Bang();
    } cout<<"\n\n";
} 
void ThemThongTin(QuanLiDiem ql[],int n){
	int them;
	cout<<"Nhap so sinh vien can them: "; cin>>them;
	int j=n;
	n += them;
	for(int i=j;i<n;i++){
		cout<<"Nhap sinh vien thu "<<i+1<<endl;
		cin>>ql[i];
	}	
	cout<<"\t\t\t\t---DANH SACH SINH VIEN SAU KHI THEM---\n";
	Bang(); tieude(); dongkengang();
	for(int i=0;i<n;i++){
        cout<<ql[i];
        Bang();
	}
}

void SuaThongTin(QuanLiDiem ql[],int n){
	char Sua[10];
	cout<<"-Nhap ma so sinh vien can sua: ";fflush(stdin); cin.getline(Sua,10);
	for(int i=0;i<n;i++){
		if(strcmp(Sua,ql[i].MaSo)==0){
				cout<<"\t-Nhap sinh vien sua-\n";
				cout<<"\nNhap ma so: "; fflush(stdin); cin.getline(ql[i].MaSo,10);
				cout<<"Nhap ho ten: "; cin.getline(ql[i].HoTen,10);
				cout<<"Nhap lop: "; cin.getline(ql[i].Lop,10);
				cout<<"Nhap que quan: "; cin.getline(ql[i].QueQuan,10);
				cout<<"\n\t-Nhap ngay sinh-\n";
				cout<<"\nNhap ngay: "; 
				do{ 
					cin>>ql[i].ns.Ngay;
					if(ql[i].ns.Ngay <=0 || ql[i].ns.Ngay >31)
						cout<<"->Khong co ngay nay!";
				}while(ql[i].ns.Ngay <=0 || ql[i].ns.Ngay >31);
				cout<<"Nhap thang: ";
				do{
					cin>>ql[i].ns.Thang;
					if(ql[i].ns.Thang <=0 || ql[i].ns.Thang >12)
						cout<<"->Khong co thang nay!";
				}while(ql[i].ns.Thang <=0 || ql[i].ns.Thang >12 );
				cout<<"Nhap nam: "; 
				do{
					cin>>ql[i].ns.Nam;
					if(ql[i].ns.Nam <=0 || ql[i].ns.Nam >2023)
						cout<<"->Khong co nam nay!";
				}while(ql[i].ns.Nam <=0 || ql[i].ns.Nam >2023);
				 cout<<"\n\t-Nhap diem-\n";
				do{
					cout<<"\nNhap diem toan: "; cin>>ql[i].DiemToan;
					cout<<"Nhap diem van: ";cin>>ql[i].DiemVan;
					cout<<"Nhap diem anh: "; cin>>ql[i].DiemAnh;
					cout<<"Nhap diem ren luyen: "; cin>>ql[i].DiemRenLuyen;
		        if(ql[i].DiemToan <0 || ql[i].DiemVan <0||ql[i].DiemAnh <0 || ql[i].DiemRenLuyen<0|| ql[i].DiemToan >10||ql[i].DiemVan >10 || ql[i].DiemAnh >10||ql[i].DiemRenLuyen>100)
		            cout<<"->Ban nhap sai!";
		    }while(ql[i].DiemToan <0 || ql[i].DiemVan <0||ql[i].DiemAnh <0 ||ql[i].DiemRenLuyen<0 || ql[i].DiemToan >10||ql[i].DiemVan >10 || ql[i].DiemAnh >10||ql[i].DiemRenLuyen>100); 
		cout<<"\t\t\t---DANH SACH SINH VIEN SAU KHI SUA---\n\n";
		XuatThongTin(ql,n);
		}
	}
}
void XoaThongTin(QuanLiDiem ql[],int n){
	char Xoa[10];
	cout<<"-Nhap ma so sinh vien can xoa: ";fflush(stdin); cin.getline(Xoa,10);
	for(int i=0;i<n;i++){
		if(strcmp(Xoa,ql[i].MaSo)==0){
			ql[i] = ql[i+1];
			i--;
			n--;
		}
	}
	cout<<"\t\t\tDANH SACH SINH VIEN SAU KHI XOA\n";
	Bang(); tieude(); Bang();
	XuatThongTin(ql,n);
}
void XapXepDiemTrungBinhGiam(QuanLiDiem ql[],int n){
	for(int i=0;i<n;i++){
    	for(int j=i+1;j<n;j++){
    		if(ql[i].DiemTrungBinh() < ql[j].DiemTrungBinh()){
    			QuanLiDiem tg = ql[i];
    				ql[i] = ql[j];
    				ql[j] = tg;
			}
		}
	} 
	dongkengang();
	XuatThongTin(ql,n); 
	cout<<"\n\n";
} 

void XapXepDiemTrungBinhTang(QuanLiDiem ql[],int n){
	for(int i=0;i<n;i++){
    	for(int j=i+1;j<n;j++){
    		if(ql[i].DiemTrungBinh() > ql[j].DiemTrungBinh()){
    			QuanLiDiem tg = ql[i];
    				ql[i] = ql[j];
    				ql[j] = tg;
			}
		}
	}
	dongkengang();
	XuatThongTin(ql,n);
	cout<<"\n\n";
} 

void XapXepTheoTen(QuanLiDiem ql[],int n){
	char c[10];
	char d[10];
	for(int i=0;i<n;i++){
		strcpy(c,ql[i].HoTen);
    	for(int j=i+1;j<n;j++){
    		strcpy(d,ql[j].HoTen);
    		if(strcmp(strupr(c),strupr(d))<0){
    			QuanLiDiem tg = ql[i];
    				ql[i] = ql[j];
    				ql[j] = tg;
			}
		}
	}
	XuatThongTin(ql,n);
}

void TimKiemMa(QuanLiDiem ql[],int n){
	char g[10];
	cout<<"\t-Nhap ma can tim kiem: "; cin>>g;
	dongketieude();
	cout<<"\t\t\tDANH SACH SINH VIEN"<<endl; dongketieude(); Bang(); tieude(); Bang();
	for(int i=0;i<n;i++){
		if(strcmp(ql[i].MaSo,g)==0){
			cout<<ql[i];
			Bang();
		}
	}
}

void TimKiemTen(QuanLiDiem ql[],int n){
	char f[10];
	cout<<"\t-Nhap ten can tim kiem: "; cin>>f; dongketieude();
	cout<<setw(60)<<"\t\t\tDANH SACH SINH VIEN"<<endl; dongketieude(); Bang(); tieude(); Bang();
	for(int i=0;i<n;i++){
		if(strcmp(ql[i].HoTen,f)==0){
			cout<<ql[i];
			Bang();
		}else cout<<"-Khong co ten sinh vien nay!";
	}
}

void TimKiemLop(QuanLiDiem ql[],int n){
	char g[10];
	cout<<"\t-Nhap lop can tim kiem: "; cin>>g; dongketieude();
	cout<<setw(60)<<"\t\t\tDANH SACH SINH VIEN"<<endl; dongketieude(); Bang(); tieude(); Bang();
	for(int i=0;i<n;i++){
		if(strcmp(ql[i].Lop,g)==0){
			cout<<ql[i];
			Bang();
		}else cout<<"-Khong co lop nay!";
	}
}

void TimKiemQueQuan(QuanLiDiem ql[],int n){
	char q[10];
	cout<<"\t-Nhap que quan can tim kiem: "; cin>>q; dongketieude();
	cout<<setw(60)<<"\t\t\tDANH SACH SINH VIEN"<<endl; dongketieude(); Bang(); tieude(); Bang();
	for(int i=0;i<n;i++){
		if(strcmp(ql[i].QueQuan,q)==0){
			cout<<ql[i];
			Bang();
		}else cout<<"-Khong co que quan nay!";
	}
} 

void GhiFileTxt(QuanLiDiem ql[],int n){
	ofstream file;
	file.open("QLSV.txt",ios::out);
	if(!file){
		cerr<<"-Khong the ghi file .txt"<<endl;
	}
	file<<"Ma so"<<" "<<"Ho ten"<<" "<<"Lop"<<" "<<"Que quan"<<" "<<"Ngay sinh"<<" "<<"Diem toan"<<" "
		<<"Diem van"<<" "<<"Diem anh"<<" "<<"DiemTrungBinh"<<" "<<"Hoc luc"<<" "<<"Diem Ren Luyen"<<" "<<"Hoc bong"<<endl;
	for(short int i=0;i<n;i++){
		file<<left<<ql[i].MaSo<<" "<<left<<ql[i].HoTen<<" "<<left<<ql[i].Lop<<" "<<left<<ql[i].QueQuan<<" "
			<<left<<ql[i].ns.Ngay<<"/"<<left<<ql[i].ns.Thang<<"/"<<left<<ql[i].ns.Nam<<" "
			<<left<<ql[i].DiemToan<<" "<<left<<ql[i].DiemVan<<" "<<left<<ql[i].DiemAnh<<" "
			<<left<<ql[i].DiemTrungBinh()<<" "<<left<<ql[i].HocLuc()<<" "
			<<left<<ql[i].DiemRenLuyen<<" "<<left<<ql[i].HocBong()<<endl;
	}
	file.close();
}

void DocFileTxt(QuanLiDiem ql[],int n){
	ifstream file;
	file.open("QLSV.Txt",ios::in);
	if(!file){
		cerr<<"-Khong the doc file .txt"<<endl;
	}
    Bang(); tieude(); Bang();
	for(short int i=0;i<n;i++){
		cout<<"|"<<setw(5)<<ql[i].MaSo<<"|"<<setw(15)<<ql[i].HoTen<<"|"<<setw(10)<<ql[i].Lop<<"|"<<setw(12)<<ql[i].QueQuan
        	<<"|"<<setw(2)<<ql[i].ns.Ngay<<"/"<<setw(2)<<ql[i].ns.Thang<<"/"<<setw(4)<<ql[i].ns.Nam<<"|";
        cout<<setw(9)<<ql[i].DiemToan<<"|"<<setw(8)<<ql[i].DiemVan<<"|"<<setw(8)<<ql[i].DiemAnh<<"|"<<setw(13)<<ql[i].DiemTrungBinh()<<"|"
        	<<setw(10)<<ql[i].HocLuc()<<"|"<<setw(14)<<ql[i].DiemRenLuyen<<"|"<<setw(10)<<ql[i].HocBong()<<"|"<<endl; Bang();
	}
	file.close();
} 

void GhiFileCsv(QuanLiDiem ql[],int n){
	ofstream file;
	file.open("QLSV.csv",ios::out);
	if(!file){
		cerr<<"-Khong the ghi file .scv"<<endl;
	}
	file<<"Ma so"<<","<<"Ho ten"<<","<<"Lop"<<","<<"Que quan"<<","<<"Ngay sinh"<<","<<"Diem toan"<<","
		<<"Diem van"<<","<<"Diem anh"<<","<<"DiemTrungBinh"<<","<<"Hoc luc"<<","<<"Hoc bong"<<endl;
	for(short int i=0;i<n;i++){
		file<<left<<ql[i].MaSo<<","<<left<<ql[i].HoTen<<","<<left<<ql[i].Lop<<","<<left<<ql[i].QueQuan<<","
			<<left<<ql[i].ns.Ngay<<"/"<<left<<ql[i].ns.Thang<<"/"<<left<<ql[i].ns.Nam<<","
			<<left<<ql[i].DiemToan<<","<<left<<ql[i].DiemVan<<","<<left<<ql[i].DiemAnh<<","
			<<left<<ql[i].DiemTrungBinh()<<","<<left<<ql[i].HocLuc()<<","
			<<left<<ql[i].DiemRenLuyen<<","<<left<<ql[i].HocBong()<<endl;
	}
	file.close();
}
void DocFileCsv(QuanLiDiem ql[],int n){
	ifstream file;
	file.open("QLSV.csv",ios::in);
	if(!file){
		cerr<<"-Khong the doc file .scv"<<endl;
	}
    Bang(); tieude(); Bang();
	for(short int i=0;i<n;i++){
	cout<<"|"<<setw(5)<<ql[i].MaSo<<"|"<<setw(15)<<ql[i].HoTen<<"|"<<setw(10)<<ql[i].Lop<<"|"<<setw(12)<<ql[i].QueQuan
        	<<"|"<<setw(2)<<ql[i].ns.Ngay<<"/"<<setw(2)<<ql[i].ns.Thang<<"/"<<setw(4)<<ql[i].ns.Nam<<"|";
        cout<<setw(9)<<ql[i].DiemToan<<"|"<<setw(8)<<ql[i].DiemVan<<"|"<<setw(8)<<ql[i].DiemAnh<<"|"<<setw(13)<<ql[i].DiemTrungBinh()<<"|"
        	<<setw(10)<<ql[i].HocLuc()<<"|"<<setw(14)<<ql[i].DiemRenLuyen<<"|"<<setw(10)<<ql[i].HocBong()<<"|"<<endl; Bang();
	}
	file.close();
} 

int main(){
//	QuanLiDiem ql[100];
	int n;
	QuanLiDiem*ql = new QuanLiDiem;
    tieptuc:{
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
	dongnhande();
    cout<<" -Moi ban nhap: ";
    cin>>a;
    switch(a){
    	case 1: {
    		cout<<"\n->Nhap so sinh vien: ";
			do{
			    cin>>n;
		        if(n <0) cout<<"Ban nhap sai!\n";
			}while(n <0);
    		NhapThongTin(ql,n);
			break;
		}
		case 2: {
			dongketieude();
			cout<<setw(60)<<"DANH SACH SINH VIEN"<<endl; dongketieude();
			cout<<"\n"; 
    		XuatThongTin(ql,n);
			break;
		}
		case 3:{
			cout<<"\t\t\t---THEM THONG TIN SINH VIEN LEN DANH SACH---"<<endl;
			ThemThongTin(ql,n);
			break;
		}
		case 4:{
			cout<<"\t\t\t---SUA THONG TIN SINH VIEN TRONG DANH SACH---"<<endl;
			SuaThongTin(ql,n);
			break;
		}
		case 5:{
			cout<<"\t\t\t---XOA THONG TIN SINH VIEN TRONG DANH SACH---"<<endl;
			XoaThongTin(ql,n);
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
					cout<<"\t\t---DANH SACH SINH VIEN GIAM DAN THEO DIEM TRUNG BINH---\n"<<endl; dongketieude();
					cout<<"\t\t\tDANH SACH SINH VIEN"<<endl;
					XapXepDiemTrungBinhGiam(ql,n);
					break;
				}
				case 2:{
					cout<<"\t\t---DANH SACH SINH VIEN TANG DAN THEO DIEM TRUNG BINH---\n"<<endl; dongketieude();
					cout<<"\t\t\tDANH SACH SINH VIEN"<<endl; 
					XapXepDiemTrungBinhTang(ql,n);
					break;
				}
				case 3:{
					cout<<"\t\t---DANH SACH SINH VIEN TANG DAN THEO TEN---\n"<<endl; dongketieude();
					cout<<"\t\t\tDANH SACH SINH VIEN"<<endl; 
				    XapXepTheoTen(ql,n);
					break;
				}
				dung1:case 0:exit(0);
				default:
				cout<<"->Ban nhap khong dung!";
				break;
			}
			char traloi1;	
			cout<<"-Ban muon tiep tuc (y/n)?: ";
			cin>>traloi1;
			if(traloi1=='y' || traloi1=='Y') goto tieptuc;
			if(traloi1=='n' || traloi1=='N') goto dung1;
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
				    TimKiemMa(ql,n);
					break;
				}
				case 2:{
					cout<<"\t\t---DANH SACH SINH VIEN TIM KIEM THEO TEN---\n"<<endl; 
				    TimKiemTen(ql,n);
					break;
				}
				case 3:{
					cout<<"\t\t---DANH SACH SINH VIEN TIM KIEM THEO LOP---\n"<<endl;
				    TimKiemLop(ql,n);
					break;
				}
				case 4:{
					cout<<"\t\t---DANH SACH SINH VIEN TIM KIEM THEO QYE QUAN---\n"<<endl; 
				    TimKiemQueQuan(ql,n);
					break;
				}
				dung2:case 0:exit(0);
				default:
				cout<<"->Ban nhap khong dung!";
				break;
			}
			char traloi2;	
			cout<<"-Ban muon tiep tuc (y/n)?: ";
			cin>>traloi2;
			if(traloi2=='y' || traloi2=='Y') goto tieptuc;
			if(traloi2=='n' || traloi2=='N') goto dung2;
			
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
				XuatThongTin(ql,n);
				GhiFileTxt(ql,n);
				cout<<"\n-Ghi file .txt thanh cong";
				break;
			case 2:
				cout<<"\n\t\t\t---DOC DU LIEU VAO FILE QLSV.txt---"<<endl;
				DocFileTxt(ql,n);
				cout<<"\n->Doc file .txt thanh cong";
				break;
			dung3:case 0:exit(0);
			default:
				cout<<"->Ban nhap khong dung!";
				break;
			}
			char traloi3;
			cout<<"-Ban muon tiep tuc (y/n)?: ";
			cin>>traloi3;
			if(traloi3=='y' || traloi3=='Y') goto tieptuc;
			if(traloi3=='n' || traloi3=='N') goto dung3;
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
				XuatThongTin(ql,n);
				GhiFileCsv(ql,n);
				cout<<"\n->Ghi file .scv thanh cong.";
				break;
			case 2:
				cout<<"\n\t\t\t---DOC DU LIEU TU FILE QLSV.scv---"<<endl;
				DocFileCsv(ql,n);
				cout<<"\n->Doc file .scv thanh cong.";
				break;
			dung5:case 0:exit(0);
			default:
				cout<<"->Ban nhap khong dung!";
				break;
			}
			char traloi5;	
			cout<<"-Ban muon tiep tuc (y/n)?: ";
			cin>>traloi5;
			if(traloi5=='y' || traloi5=='Y') goto tieptuc;
			if(traloi5=='n' || traloi5=='N') goto dung5;
		}	
		dung:case 0:exit(0);
		default:
			cout<<"->Ban nhap khong dung!";
			break;
		}
	}
	char traloi;	
	cout<<"-Ban muon tiep tuc (y/n)?: ";
	cin>>traloi;
	if(traloi=='y' || traloi=='Y') goto tieptuc;
	if(traloi=='n' || traloi=='N') goto dung;
	cout<<endl;
	return 0;
}
