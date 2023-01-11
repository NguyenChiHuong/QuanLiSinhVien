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
    public:
        QuanLiDiem(){}
        QuanLiDiem(char*ms,char*ht,char*lop,char*qq,float dt,float dv,float da):QuanLiSinhVien(ms,ht,lop,qq){
            this->DiemToan = dt;
            this->DiemVan = dv;
            this->DiemAnh = da;
        }
        ~QuanLiDiem(){}
        
        float DiemTrungBinh(){
            return (this->DiemToan + this->DiemVan + this->DiemAnh) / 3;
        }
        
        string HocLuc(){
            if(DiemTrungBinh() >= 8 && DiemTrungBinh() <=10)
                return "Gioi";
            else if(DiemTrungBinh() >=6.5 && DiemTrungBinh() <8)
                return "Kha";
            else if(DiemTrungBinh() >=4 && DiemTrungBinh() <6.5)
				return "Trung Binh";
            else    
				return "Yeu";
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
	for(int i=0;i<52;i++){cout<<"*";}
	cout<<"\n";
}

void dongketieude(){
    for(int i=0;i<111;i++){cout<<"=";}
    cout<<"\n";
}

void dongkengang(){
	for(int i=0;i<111;i++){cout<<"-";}
	cout<<"\n";
}

void tieude(){
    cout<<"|"<<setw(5)<<left<<"Ma so"<<"|"<<setw(15)<<left<<"Ho ten"<<"|"<<setw(10)<<left<<"Lop"<<"|"<<setw(12)<<left<<"Que quan"
        <<"|"<<setw(10)<<"Ngay sinh"<<"|"<<setw(5)<<"Diem toan"<<"|"<<setw(8)<<"Diem van"<<"|"<<setw(8)<<"Diem anh"<<"|";
    cout<<setw(13)<<"DiemTrungBinh"<<"|"<<setw(10)<<"Hoc luc"<<setw(2)<<"|"<<endl;
}

void Bang(){
	cout<<"+"<<"-----"<<"+"<<"---------------"<<"+"<<"----------"<<"+"<<"------------"<<"+"
        <<"----------"<<"+"<<"---------"<<"+"<<"--------"<<"+"<<"--------"<<"+";
    cout<<"-------------"<<"+"<<"----------"<<"+"<<endl;
}
istream&operator>>(istream&is,QuanLiDiem & ql){
    ql.QuanLiSinhVien::NhapDanhSach();
    cout<<"\n\t-Nhap diem-\n";
    do{
		cout<<"\nNhap diem toan: "; 
        is>>ql.DiemToan;
    	cout<<"Nhap diem van: ";
    	is>>ql.DiemVan;
		cout<<"Nhap diem anh: ";
    	is>>ql.DiemAnh;
        if(ql.DiemToan <0 || ql.DiemVan <0||ql.DiemAnh <0 || ql.DiemToan >10||ql.DiemVan >10 || ql.DiemAnh >10)
            cout<<"->Ban nhap sai!";
    }while(ql.DiemToan <0 || ql.DiemVan <0||ql.DiemAnh <0 || ql.DiemToan >10||ql.DiemVan >10 || ql.DiemAnh >10); 
    return is;
}
ostream&operator<<(ostream&os,QuanLiDiem ql){
    ql.QuanLiSinhVien::ThongTin();
    os<<setw(9)<<ql.DiemToan<<"|"<<setw(8)<<ql.DiemVan<<"|"<<setw(8)<<ql.DiemAnh<<"|"<<setw(13)<<ql.DiemTrungBinh()<<"|"
        <<setw(10)<<ql.HocLuc()<<"|"<<endl; 
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
	int a = n+1;
	cout<<"\t-Nhap sinh vien them-\n";
	cout<<"\nNhap ma so: "; fflush(stdin); cin.getline(ql[n].MaSo,10);
	cout<<"Nhap ho ten: "; cin.getline(ql[n].HoTen,10);
	cout<<"Nhap lop: "; cin.getline(ql[n].Lop,10);
	cout<<"Nhap que quan: "; cin.getline(ql[n].QueQuan,10);
	cout<<"\n\t-Nhap ngay sinh-\n";
	cout<<"\nNhap ngay: "; 
	do{ 
		cin>>ql[n].ns.Ngay;
		if(ql[n].ns.Ngay <=0 || ql[n].ns.Ngay >31)
			cout<<"Khong co ngay nay!";
	}while(ql[n].ns.Ngay <=0 || ql[n].ns.Ngay >31);
	cout<<"Nhap thang: ";
	do{
		cin>>ql[n].ns.Thang;
		if(ql[n].ns.Thang <=0 || ql[n].ns.Thang >12)
			cout<<"->Khong co thang nay!";
	}while(ql[n].ns.Thang <=0 || ql[n].ns.Thang >12 );
	cout<<"Nhap nam: "; 
	do{
		cin>>ql[n].ns.Nam;
		if(ql[n].ns.Nam <=0 || ql[n].ns.Nam >2023)
			cout<<"->Khong co nam nay!";
	}while(ql[n].ns.Nam <=0 || ql[n].ns.Nam >2023);
	 cout<<"\n\t-Nhap diem-\n";
	do{
		cout<<"\nNhap diem toan: "; 
		cin>>ql[n].DiemToan;
		cout<<"Nhap diem van: ";
		cin>>ql[n].DiemVan;
		cout<<"Nhap diem anh: ";
		cin>>ql[n].DiemAnh;
		if(ql[n].DiemToan <0 || ql[n].DiemVan <0||ql[n].DiemAnh <0 || ql[n].DiemToan >10||ql[n].DiemVan >10 || ql[n].DiemAnh >10)
			cout<<"->Ban nhap sai!";
	}while(ql[n].DiemToan <0 || ql[n].DiemVan <0||ql[n].DiemAnh <0 || ql[n].DiemToan >10||ql[n].DiemVan >10 || ql[n].DiemAnh >10); 
	n++;
	cout<<"\t\t\tDANH SACH SINH VIEN SAU KHI THEM\n";
	Bang(); tieude(); Bang();
	XuatThongTin(ql,a);
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

void GhiFile(QuanLiDiem ql[],int n){
	ofstream file;
	file.open("QLSV.csv",ios::out);
	if(!file){
		cerr<<"-Khong the ghi file."<<endl;
	}
	file<<"Ma so"<<","<<"Ho ten"<<","<<"Lop"<<","<<"Que quan"<<","<<"Ngay sinh"<<","<<"Diem toan"<<","
		<<"Diem van"<<","<<"Diem anh"<<","<<"DiemTrungBinh"<<","<<"Hoc luc"<<","<<endl;
	for(short int i=0;i<n;i++){
		file<<left<<ql[i].MaSo<<","<<left<<ql[i].HoTen<<","<<left<<ql[i].Lop<<","<<left<<ql[i].QueQuan<<","
			<<left<<ql[i].ns.Ngay<<"/"<<left<<ql[i].ns.Thang<<"/"<<left<<ql[i].ns.Nam<<","
			<<left<<ql[i].DiemToan<<","<<left<<ql[i].DiemVan<<","<<left<<ql[i].DiemAnh<<","
			<<left<<ql[i].DiemTrungBinh()<<","<<left<<ql[i].HocLuc()<<endl;
	}
	file.close();
}
void DocFile(QuanLiDiem ql[],int n){
	ifstream file;
	file.open("QLSV.csv",ios::in);
	if(!file){
		cerr<<"-Khong the doc file."<<endl;
	}
    Bang(); tieude(); Bang();
	for(short int i=0;i<n;i++){
		cout<<"|"<<setw(5)<<ql[i].MaSo<<"|"<<setw(15)<<ql[i].HoTen<<"|"<<setw(10)<<ql[i].Lop<<"|"<<setw(12)<<ql[i].QueQuan
        	<<"|"<<setw(2)<<ql[i].ns.Ngay<<"/"<<setw(2)<<ql[i].ns.Thang<<"/"<<setw(4)<<ql[i].ns.Nam<<"|";
        cout<<setw(9)<<ql[i].DiemToan<<"|"<<setw(8)<<ql[i].DiemVan<<"|"<<setw(8)<<ql[i].DiemAnh<<"|"<<setw(13)<<ql[i].DiemTrungBinh()<<"|"
        	<<setw(10)<<ql[i].HocLuc()<<"|"<<endl; dongkengang();
	}
	file.close();
} 
int main(){
    int n;
	QuanLiDiem ql[100];
	//QuanLi*ql= new QuanLi;
    tieptuc:{
	int a; 
	cout<<"\n\n*****************<QUAN LI SINH VIEN>****************"<<endl;
	cout<<"*\t\t\t\t\t\t   *\n*\t Nhap 1.NHAP DANH SACH SINH VIEN           *"<<endl;      
	cout<<"*\t\t\t\t\t\t   *\n*\t Nhap 2.DANH SACH THONG TIN SINH VIEN      *"<<endl;
    cout<<"*\t\t\t\t\t\t   *\n*\t Nhap 3.THEM SINH VIEN LEN DANH SACH       *"<<endl;
	cout<<"*\t\t\t\t\t\t   *\n*\t Nhap 4.XOA SINH VIEN TRONG DANH SACH      *"<<endl;  
    cout<<"*\t\t\t\t\t\t   *\n*\t Nhap 5.XAP XEP DANH SACH SINH VIEN        *"<<endl;  
    cout<<"*\t\t\t\t\t\t   *\n*\t Nhap 6.TIM KIEM THONG TIN SINH VIEN       *"<<endl;
	cout<<"*\t\t\t\t\t\t   *\n*\t Nhap 7.GHI DU LIEU VAO FILE               *"<<endl; 
	cout<<"*\t\t\t\t\t\t   *\n*\t Nhap 8.DOC DU LIEU TU FILE                *"<<endl; 
	cout<<"*\t\t\t\t\t\t   *\n*\t Nhap 0.THOAT                              *"<<endl;
	cout<<"*\t\t\t\t\t\t   *"<<endl; 						  
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
			cout<<"\t\t\t---THEM SINH VIEN LEN DANH SACH---"<<endl;
			ThemThongTin(ql,n);
			break;
		}
		case 4:{
			cout<<"\t\t\t---XOA SINH VIEN TRONG DANH SACH---"<<endl;
			XoaThongTin(ql,n);
			break;
		}
		case 5:{
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
					cout<<"\t\t\tDANH SACH SINH VIEN"<<endl; dongketieude();
					XapXepDiemTrungBinhGiam(ql,n);
					break;
				}
				case 2:{
					cout<<"\t\t---DANH SACH SINH VIEN TANG DAN THEO DIEM TRUNG BINH---\n"<<endl; dongketieude();
					cout<<"\t\t\tDANH SACH SINH VIEN"<<endl; dongketieude();
					XapXepDiemTrungBinhTang(ql,n);
					break;
				}
				case 3:{
					cout<<"\t\t---DANH SACH SINH VIEN TANG DAN THEO TEN---\n"<<endl; dongketieude();
					cout<<"\t\t\tDANH SACH SINH VIEN"<<endl; dongketieude();
				    XapXepTheoTen(ql,n);
					break;
				}
				dung1:case 0:exit(0);
			}
			char traloi1;	
			cout<<"-Ban muon tiep tuc (y/n)?: ";
			cin>>traloi1;
			if(traloi1=='y' || traloi1=='Y') goto tieptuc;
			if(traloi1=='n' || traloi1=='N') goto dung1;
		}
		case 6: int c; cout<<"\n";
			cout<<"=================XAP XEP SINH VIEN=================="<<endl; 
			cout<<"\n Nhap 1.DANH SACH SINH VIEN TIM KIEM THEO MA SO"<<endl;
			cout<<"\n Nhap 2.DANH SACH SINH VIEN TIM KIEM THEO TEN"<<endl;
			cout<<"\n Nhap 3.DANH SACH SINH VIEN TIM KIEM THEO LOP"<<endl;
			cout<<"\n Nhap 4.DANH SACH SINH VIEN TIM KIEM THEO QUE QUAN"<<endl; 
			cout<<"\n Nhap 0.THOAT"<<endl;
			for(int i=0;i<65;i++){cout<<"=";} cout<<"\n";
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
			}
			char traloi2;	
			cout<<"-Ban muon tiep tuc (y/n)?: ";
			cin>>traloi2;
			if(traloi2=='y' || traloi2=='Y') goto tieptuc;
			if(traloi2=='n' || traloi2=='N') goto dung2;
			
		case 7:{
			cout<<"\n\t\t---GHI DU LIEU VAO FILE---"<<endl;
			XuatThongTin(ql,n);
			GhiFile(ql,n);
			cout<<"\n->Ghi file thanh cong.";
			break;
		}	
		case 8:{
			cout<<"\n\t\t---DOC DU LIEU TU FILE---"<<endl;
			GhiFile(ql,n);
			DocFile(ql,n);
			cout<<"\n->Doc file thanh cong.";
			break;
		}	
		dung:case 0:exit(0);
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
