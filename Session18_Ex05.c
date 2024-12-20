#include<stdio.h>
#include<string.h>
//khai bao struct voi cac yeu cau nhu de bai
	struct Sinhvien {
		int id;
		char name[50];
		int age;
		char phoneNumber[20];
	};
//xay dung ham tim kiem phan tu theo id 
	int timsinhvien(struct Sinhvien arr[], int n, int id) {
		int i;
		for(i = 0; i < n; i++) {
			if ( arr[i].id == id){
				return i;
			}
		}
		return -1;
	}
//ham in danh sach sinh vien
	void indanhsachsinhvien(struct Sinhvien arr[], int n) {
		printf("danh sach sinh vien dang co hien tai la: \n");
		int i;
		for(i = 0; i < n; i++){
			printf("ID: %d\n", arr[i].id);
			printf("Name: %s\n", arr[i].name);
			printf("Age: %d\n", arr[i].age);
			printf("phoneNumber: %s\n", arr[i].phoneNumber);
		}
	}

int main(){
//khai bao va gan gia tri cho mang danh sach sinh vien
	struct Sinhvien sinhvien[50] = {
		{1, "Nguyen van A", 19, "035127623"},
		{2, "Nguyen van B", 22, "034612536"},
		{3, "Nguyen van C", 11, "035263447"},
		{4, "Nguyen van D", 23, "025325143"},
		{5, "Nguyen van Z", 16, "036256747"},
	};
//luc nay so luong sinh vien trong mang la 5 
	int n = 5;
	int idcantim;
	int vitri;
//yeu cau nguoi dung nhap vao id can tim
	printf("id ma ban muon tim la: ");
	scanf("%d", &idcantim);
//goi ham tim sinh vien
	vitri = timsinhvien(sinhvien, n, idcantim);
//kiem tra dieu kien
	if(vitri == -1){
        printf("Khong tim thay sinh vien voi id %d\n", idcantim);
    } else {
        printf("Sinh vien tim thay: %s\n", sinhvien[vitri].name);
        printf("Nhap ten moi: ");
        getchar();
        fgets(sinhvien[vitri].name, sizeof(sinhvien[vitri].name), stdin);
        size_t len = strlen(sinhvien[vitri].name);
        if (sinhvien[vitri].name[len - 1] == '\n') {
            sinhvien[vitri].name[len - 1] = '\0';
        }
        printf("Nhap tuoi moi: ");
        scanf("%d", &sinhvien[vitri].age);
	}
//ket thuc chuong trinh
	return 0;
	
}
