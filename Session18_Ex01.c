#include<stdio.h>

struct Sinhvien {
	char name[50];
	int age;
	char phoneNumber[15];
	};
	
	//tien hanh cac thao tac trong ham int main
int main(){
	struct Sinhvien Sinhvien1;
	printf("moi ban nhap ten cho sinh vien: ");
	fgets(Sinhvien1.name, sizeof(Sinhvien1), stdin);
	printf("moi ban nhap tuoi cho sinh vien: ");
	scanf("%d", &Sinhvien1.age);
	printf("moi ban nhap sdt cua sinh vien: ");
	scanf("%s", &Sinhvien1.phoneNumber);
	
	//tien hanh in ra man hinh cac so lieu da nhap vao cua sinhvien1
	printf("cac so lieu cua sinh vien 1 la: \n");
	printf("Name: %s\n", Sinhvien1.name);
	printf("Age: %d\n", Sinhvien1.age);
	printf("phoneNumber: %s", Sinhvien1.phoneNumber);
	
	//ket thuc chuong trinh 
	return 0;
}
	
