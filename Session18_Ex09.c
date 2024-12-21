#include<stdio.h>
#include<string.h>

	//tao struct voi cac yeu cau sau gom co id, name, price 
	struct Dish {
		int id;
		char name[50];
		float price;
	};
	
int main(){
	int lua_chon;
	int xacnhan;
	//khai bao mang cau truc nhu sau: struct Dish menu[100]
	struct Dish menu[100];
	//khai bao cho 5 mon an
	 strcpy(menu[0].name, "Ngu hai long vuong");
    menu[0].id = 1;
    menu[0].price = 10.000;

    strcpy(menu[1].name, "Rau muong xao toi");
    menu[1].id = 2;
    menu[1].price = 15.000;

    strcpy(menu[2].name, "trung ran bong dem");
    menu[2].id = 3;
    menu[2].price = 5000;

    strcpy(menu[3].name, "dap vo cay dan");
    menu[3].id = 4;
    menu[3].price = 120.000;

    strcpy(menu[4].name, "mon chua dat ten");
    menu[4].id = 5;
    menu[4].price = 0.55555;


	while(1) {
		printf("-----MENU-----\n");
		printf("1. In ra gia tri cac phan tu co trong menu theo dang (1. member: value)\n");
		printf("2. Them mot phan tu vao vi tri chi dinh\n");
		printf("3. Sua mot phan tu o vi tri chi dinh\n");
		printf("4. Xoa mot phan tu o vi tri chi dinh\n");
		printf("5. Sap xep cac phan tu( khi lua chon menu thi hien thi menu con)\n");
		printf("6. Tim kiem phan tu theo name nhap vao\n");
		printf("7. Thoat\n");
		printf("\n");
		printf("Lua chon cua ban la: \n");
		//tien hanh gan gia tri cho bien lua chon
		scanf("%d", &lua_chon);
		//dung switch case
		switch(lua_chon){
			// in ra cac phan tu co trong menu
			case 1: { // dau {} bao chon ca case chi su dung nhung bien da khai bao trong case
				int i;
				printf("Cac mon an hien co la: \n");
				for(i = 0; i < 5; i++) {
					printf("thong tin cua mon an %d la: \n", i + 1);
					printf("Id: %d\n", menu[i].id);
					printf("name: %s\n", menu[i].name);
					printf("price: %.2f\n", menu[i].price);
				}
				break;
			}
			
			// them mot phan tu vao vi tri chi dinh
			case 2: {
				int n = 5; // so luong mon an co trong menu hien tai
				//dieu kien xem co the them duoc mon an vao trong menu duoc khong 
				if(n >= 100) {
					printf("Menu cua ban da day, khong the them mon an vao trong menu nua\n");
					break;
				}
				int position;
				//yeu cau nguoi dung nhap vao mon an can them
				printf("Moi bna nhap ten mon an can them vao menu");
				scanf("%d", &position);
				// kiam tra dieu kien xem co phu hop hay khong 
				if(position < 0 || position >= 5) {
					printf("Vi tri chi dinnh khong hop le, vui long nhap lai\n");
					break;
				}
				//id se duoc chuong trinh tu dong them, vi id khong the trung nhau
				menu[n].id = n + 1;
				//yeu  cua nguoi dung hap thong tin cvho mon an moi
				printf("Moi ban nhap thong tin cho mon an moi\n");
				getchar();
				fgets(menu[n].name, sizeof(menu[n].name), stdin);
				   //xoa ki tu thua \n khi ta nhan vao enter de co the next xuong dong 
				   menu[n].name[strcspn(menu[n].name, "\n")] = 0;
				//yeu cau nguoi dung nhap gia cho mon an moi
				printf("Moi ban nhap gia tien cho mon an moi\n");
				scanf("%f", &menu[n].price);
				//di chuyen cac phan tu de co the tao khoang trong 
				int i;
                for(i = n; i > position; i--) {
                    menu[i] = menu[i - 1];
                }
                n++;
                printf("Da them mon an moi vao vi tri %d\n", position);
				}
				break;
				
			//sua mot phan tu vao vi tri cu the 
			case 3: {
				int n = 5;
				int position;
				printf("Ban muon sua tai vi tri nao( luu ý chi co the chon tu 0 den %d)\n", n - 1);
				scanf("%d", &position);
				//kiem tra dieu kien xem nguoi dung vúa chon co du dieu kien khong 
				if(position < n || position >= n) {
					printf("vi tri ma ban muon sua khong hop le, moi ban nhap lai\n");
					break;
				}
				//id mon an se duoc giu nguyen khi sua
				//yeu cau nguoi dung nhap ten cho mon an moi
				printf("Moi ban nhap ten cho mon an moi");
				getchar();
				fgets(menu[n].name, sizeof(menu[n].name), stdin);
				menu[position].name[strcspn(menu[position].name, "\n")] = 0; 
				// yeu cau nguoi dung nhap gia cho mon an moi
				printf("moi ban giap gia cho mon an moi da sua");
				scanf("%f", &menu[position].price);
				//in ra thong tin da sua thanh cong
				printf("da sua thanh cong mon an tai vi tri %d", position);
				break;
			}
			
			//xoa mot phantu tai vi tri chi dinh
			case 4: {
				int n = 5;
				int position;
				//yeu cau nguoi dung nhap vao vi tri can xoa 
				printf("Moi ban nhap vao vi tri ma ban muon xoa trong menu( luu y chi co the chon tu 0 den %d)", n - 1);
				scanf("%d", &position);
				//kiem tra xem nguoi dung nhap co dung theo yeu cau khong
				if(position < n || position >= n) {
					printf("vi tri ma ban vua chon de xoa khong hop le, vui long nhap lai vi tri moi");
					break;
				}
				int i;
				// tien hanah xoa phan tu
				 for(i = position; i < n - 1; i++) {
                    menu[i] = menu[i + 1];
                }
                n--;
                //thong bao xem da xoa thanh cong hay chua 
                printf("Da xoa mon an tai vi tri %d\n", position);
				break;
			}
			
			//ap xep cac phan tu
			case 5: {
				int n = 5;
				int sapxep;
				//in ra menu con de nguoi dung co the chon loai sap xep theo tang dan hay giam dan
				printf("Moi ban chon loai sap xep\n");
				printf("1.sap xep theo thu tu giam dan\n");
				printf("2.sap xep theo thu tu tang dan\n");
				//sau do gan gia tri vao bien sapxep
				scanf("%d", &sapxep);
				// tien hanh sap xep theo lua chon cua nguoi dung // co the dung bubble sort de sap xep
				if(sapxep == 1) { // sap xep giam dan
					int i;
					int j;
					 for(i = 0; i < n - 1; i++) {
                        for(j = i + 1; j < n; j++) {
                            if(menu[i].price < menu[j].price) {
                                struct Dish temp = menu[i];
                                menu[i] = menu[j];
                                menu[j] = temp;
                            }
                        }
                    }
				} else if(sapxep == 2) { // sap xep tang dan
					int i, j;
					 for(i = 0; i < n - 1; i++) {
                        for(j = i + 1; j < n; j++) {
                            if(menu[i].price > menu[j].price) {
                                struct Dish temp = menu[i];
                                menu[i] = menu[j];
                                menu[j] = temp;
                            }
                        }
                    }
				} else { //thong bao neu lua chon khong hop le
					printf("Lua chon cua ban khong hop le moi ban nhap lai\n");
					break;
				}
				// thong bao xem chuong trinh co duoc thuc hien dung hay khong 
				printf("menu cua ban da duoc sap xep xong");
				break;
			}
			
			//tim kiem phan tu theo name nhpa vao
			/*case 6: {
				int index;
				// cho nguoi dung nhap vao name mon an muon tim
				printf("Name mon an ban muon tim la gi: \n");
				fgets("%s", &index);
				
				break;
			}*/
			
			//thoat chuong trih
			case 7:
				printf("ban chac chan muon thoat chuong trinh chu, xac nhan rang ban khong phia nguoi may\n");
				printf("1. toi khong phai nguoi may\n");
				printf("2. nguoi may khong phai la toi\n");
				scanf("%d", &xacnhan);
				if(xacnhan == 1) {
					printf("khong duoc ban la nguoi may");
				} else if (xacnhan == 2) {
					printf("khong duoc ban van la nguoi may");
				} else {
					printf("bye, hen gap lai ban sau");
					return 0;
				}
				
			default:
				printf("lua chon cua ban khong hop le moi ban nhap lai");
			}
					
		}
		//ket thuc chuong trinh
		return 0;
	}

