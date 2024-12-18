#include<stdio.h>

struct sinhvien {
	int id;
	char name[50];
	int age;
	char phoneNumber[15];
};

int main(){
	struct sinhvien sinhvien1[5];
	
	//yeu cau nguoi dung nhap thong tin cho tung sinh vien
	int i;
	for(i = 0; i < 5; i++){
		printf("moi ban nhap thong tin cho tung sinh vien %d: \n", i + 1);
		
		sinhvien1[i].id = i + 1;
		
		printf("moi ban nhap ten cho sinh vien: ");
		fgets(sinhvien1[i].name, sizeof(sinhvien1[i].name), stdin);
		//tien hanh xoa ten vua nhap sau khi nhap
		sinhvien1[i].name[strcspn(sinhvien1[i].name, "\n")] = 0;
		
		printf("moi ban nhap tuoi cho sinh vien: ");
		scanf("%d", &sinhvien1[i].age);
		getchar();
		
		printf("moi ban nhap sdt cho tung sinh vien: ");
		fgets(sinhvien1[i].phoneNumber, sizeof(sinhvien1[i].phoneNumber), stdin);
		//tien hanh xoa sdt vua nhap de luu gia tri moi
		sinhvien1[i].phoneNumber[strcspn(sinhvien1[i].phoneNumber, "\n")] = 0;
		
	}
	printf("\n");
	//in tat ca cac thong tin sinh vien vua nhap xong 
	printf("thong tin cua tat ca sinh vien la: \n");
	
	for(i = 0; i < 5; i++){
		printf("thong tin cua sinh vien %d la: \n", i + 1);
		printf("Id: %d\n", sinhvien1[i].id);
		printf("name: %s\n", sinhvien1[i].name);
		printf("age: %d\n", sinhvien1[i].age);
		printf("phoneNumber: %s\n", sinhvien1[i].phoneNumber);
		

}
	//ket thuc chuong trinh
	return 0;
}

