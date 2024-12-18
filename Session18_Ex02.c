#include<stdio.h>

//khai bao bien struct
struct Sinhvien{
	char name[50];
	int age;
	char phoneNumber[15];
};

int main(){
	struct Sinhvien Sinhvien1;
	
	//gan cac gia tri cho bien
	strcpy(Sinhvien1.name, "ngo trung chien"); //gan ten cho sinh vien
	Sinhvien1.age = 19;
	strcpy(Sinhvien1.phoneNumber, "0345139926");
	
	//in cac thong so da nhap ra man hinh
	printf("cac so lieu cua sinh vien 1 la: \n");
	printf("Name: %s\n", Sinhvien1.name);
	printf("Age: %d\n", Sinhvien1.age);
	printf("phoneNumber: %s", Sinhvien1.phoneNumber);
	
	//ket thuc chuong trinh 
	return 0;
}
