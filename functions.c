#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"functions.h"
#define MAX_STUDENTS 100
#define MAX_TEACHERS 100
#define MAX_CLASSES 10

void displayMenu(){
	system("cls");
	int choice;
    do{
    	printf("\t  *** Student Management System Using C ***\n");
		printf("\n");
	    printf("\t\t      CHOOSE YOUR ROLE\n");
	    printf("\t============================================\n");
	    printf("\t[1] Admin.\n");
	    printf("\t[2] Student.\n");
	    printf("\t[3] Teacher.\n");
	    printf("\t[0] Exit the Program.\n");
	    printf("\t============================================\n");
	    printf("\tEnter The Choice: ");
	    scanf("%d",&choice);
	    getchar();
	    switch(choice){
	    	case 1:
	    		system("cls");
	    		loginAdmin();
	    		break;
	    	case 2:
	    		system("cls");
				showStudents();
				break;
			case 3:
				system("cls");
				showTeacher();
				break;
			case 0:
				printf("\n\tTam biet!");
				return;	
			default:
				system("cls");
				printf("\n\tvui long chon lai!!!\n");
				break;		
		}
	}while(choice!=0);
}

void loginAdmin(){
	system("cls");
	char email[100];
    char password[100];
    char correctEmail[]="student";
    char correctPassword[]="1";

    printf("\n\n\t  *** Student Management System Using C ***\n");
    printf("\n");
    printf("\t\t  emailTest: student\n");
    printf("\t\t  passTest: 1\n");
    printf("\t\t\t      LOGIN\n");
    printf("\t\t  ============================\n");
    printf("\t\t  Email: ");
    scanf("%s",email);
    printf("\t\t  Password: ");
    scanf("%s",password);
    printf("\t\t  ============================\n");
    if(strcmp(email,correctEmail)==0 && strcmp(password,correctPassword)==0){
    	system("cls");
        printf("\t\t  Dang nhap thanh cong!\n");
        displayAdminMenu();
    }else{
    	system("cls");
        printf("\t\t  Dang nhap that bai!\n");
    }
}

void endProgram(){
	system("cls");
	printf("\t\t\t========= Thank You =========\n");
	printf("\t\t\t======== See You Soon =======\n");
}

void displayAdminMenu(){
	int choice;
	printf("\n\n\t  *** Student Management System Using C ***\n");
	printf("\n");
    printf("\n\t\t  ========================\n");
    printf("\t\t\t    MENU\n");
    printf("\t\t  ========================\n");
    printf("\t\t  [1] Students management.\n");
    printf("\t\t  [2] Classrooms management.\n");
    printf("\t\t  [3] Teacher management.\n");
    printf("\t\t  [4] User Guideline.\n");
    printf("\t\t  [5] About Us.\n");
    printf("\t\t  [0] Exit the Program.\n");
    printf("\t\t  ========================\n");
    printf("\t\t  Enter The Choice: ");
    scanf("%d",&choice);
    getchar();
    switch(choice){
    	case 1:
    		system("cls");
    		displayStudentMenu();
    		break;
    	case 2:
    		system("cls");
			displayClassMenu();
			break;
		case 3:
			system("cls");
			displayTeacherMenu();
			break;
		case 4:
			system("cls");
			userGuideline();
			displayAdminMenu();
			break;
		case 5:
			system("cls");
			aboutUs();
			displayAdminMenu();
			break;
		case 0:
			system("cls");
			return;
		default:
			system("cls");
			printf("\t\t  vui long chon lai!!!\n");
			break;							
	}
}

void userGuideline(){
	system("cls");
	printf("\tchon 1 de quan li sinh vien gom cac tinh nang nhu them, sua, xoa,...\n");
	printf("\tchon 2 de quan li giao vien gom cac tinh nang nhu them, sua, xoa,...\n");
	printf("\tchon 3 de quan li lop gom cac tinh nang nhu them, sua, xoa,...\n\n\n");
}

void aboutUs(){
	system("cls");
	printf("\tmodule: Student Management System Using C\n");
	printf("\tnguoi thuc hien: Dao Quang Huy\n\n");
}

void displayStudentMenu(){
	system("cls");
	int choice;
    do{
    	printf("\n\t**** Student Management System Using C ****\n");
	    printf("\n");
	    printf("\t\t\tSTUDENT MENU\n");
	    printf("\t\t============================\n");
	    printf("\t\t[1] Add A New student.\n");
	    printf("\t\t[2] Show All students.\n");
	    printf("\t\t[3] Search A student.\n");
	    printf("\t\t[4] Edit A student.\n");
	    printf("\t\t[5] Delete A student.\n");
	    printf("\t\t[6] Sort Students by Name\n");
	    printf("\t\t[0] Exit the Program.\n");
	    printf("\t\t============================\n");
	    printf("\t\tEnter The Choice: ");
	    scanf("%d",&choice);
	    getchar();
	    switch(choice){
	    	case 1:
	    		system("cls");
	    		addStudent();
	    		break;
	    	case 2:
	    		system("cls");
				showStudents();
				break;
			case 3:
				system("cls");
				findStudent();
				break;
			case 4:
				system("cls");
				editStudent();
				break;
			case 5:
				system("cls");
				deleteStudent();
				break;
			case 6:
				system("cls");
				sortStudents();
				break;
			case 0:
				system("cls");
				printf("\t\tTam biet!");
				return;	
			default:
				system("cls");
				printf("\t\tvui long chon lai!!!\n");
				break;							
		}
	}while(choice!=0);
}

int isValidEmail(const char *email){
	if(email==NULL || strlen(email)<12){
    	return 0;
    }
    const char *at=strchr(email,'@gmail');
    const char *dot=strrchr(email,'.com');
    return (at && dot && at<dot);
}

int isValidPhone(const char *phone){
	int i;
	int length=0;
    for(i = 0; phone[i] != '\0'; i++) {
        if(!(phone[i] >= '0' && phone[i] <= '9')){
            return 0;
        }
        length++;
    }
    if(length==10 || length==11){
        return 1;
    }else{
        return 0;
    }
    return 1;
}

int checkId(char *id){	
    FILE *file=fopen("datastudent.bin","rb");
    struct Student student;
    while(fread(&student,sizeof(struct Student),1,file)){
        if(strcmp(student.studentId,id)==0){
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

int checkEmail(const char *email){	
    FILE *file=fopen("datastudent.bin","rb");
    struct Student student;
    while(fread(&student,sizeof(struct Student),1,file)){
        if(strcmp(student.email,email)==0){
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

int checkPhone(const char *phone){
    FILE *file=fopen("datastudent.bin","rb");
    struct Student student;
    while(fread(&student,sizeof(struct Student),1,file)){
        if(strcmp(student.phone,phone)==0){
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

int checkName(const char *name){	
    FILE *file=fopen("datastudent.bin","rb");
    struct Student student;
    while(fread(&student,sizeof(struct Student),1,file)){
        if(strcmp(student.name,name)==0){
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

void addStudent(){
    struct Student newStudent;
    printf("\n\n\t\t*** Add A New Student ***\n");
    while(1){
        printf("\t\tEnter The ID: ");
        scanf("%s",newStudent.studentId);
        if(strlen(newStudent.studentId)==0 || strlen(newStudent.studentId)>9){
            printf("\t\tKhong hop le! Vui long nhap lai!\n");
            continue;
        }
        if(checkId(newStudent.studentId)){
            printf("\t\tLoi: ID nay da ton tai!!!\n");
            continue;
        }
        break;
    }
    while(1){
        printf("\t\tEnter The Name: ");
        scanf(" %[^\n]",newStudent.name);
        if(strlen(newStudent.name)==0){
            printf("\t\tKhong hop le! Vui long nhap lai!\n");
            continue;
        }
        if(checkName(newStudent.name)){
            printf("\t\tLoi: Ten nay da ton tai!!!\n");
            continue;
        }
        break;
    }
    while(1){
        printf("\t\tEnter The Gender (0-Nu, 1-Nam): ");
        int genderInput;
        scanf("%d",&genderInput);
        if(genderInput==0){
            newStudent.gender=false;
            break;
        }else if(genderInput==1){
            newStudent.gender=true;
            break;
        }else{
            printf("\t\tKhong hop le! Vui long nhap 0 hoac 1!\n");
        }
    }
    while(1){
        printf("\t\tEnter The Email: ");
        scanf("%s",newStudent.email);
        if(!isValidEmail(newStudent.email)){
            printf("\t\tKhong dung dinh dang abc@gmail.com! Vui long nhap lai!\n");
            continue;
        }
        if(checkEmail(newStudent.email)){
            printf("\t\tLoi: Gmail nay da ton tai!!!\n");
            continue;
        }
        break;
    }
    while(1){
        printf("\t\tEnter The Phone: ");
        scanf("%s",newStudent.phone);
        if(!isValidPhone(newStudent.phone)){
            printf("\t\tKhong hop le! Vui long nhap lai!\n");
            continue;
        }
        if(checkPhone(newStudent.phone)){
        	printf("\t\tLoi: So dien thoai nay da ton tai!!!\n");
        	continue;
        }
        break;
    }
    FILE *writeFile=fopen("datastudent.bin","ab");
    fwrite(&newStudent,sizeof(struct Student),1,writeFile);
    fclose(writeFile);
    printf("\t\tThem sinh vien thanh cong!\n");
}

void showStudents(){
    FILE *file=fopen("datastudent.bin","rb");
    struct Student student;
    printf("\t\t\t\t\t\t*** All Students ***\n");
    printf("\t--------------------------------------------------------------------------------------------------------\n");
    printf("\t|%-10s | %-20s | %-30s | %-20s | %-10s|\n", "ID", "Name", "Email", "Phone", "NO. Course");
    printf("\t--------------------------------------------------------------------------------------------------------\n");
    while(fread(&student,sizeof(struct Student),1,file)){
        printf("\t|%-10s | %-20s | %-30s | %-20s | %-10s|\n",student.studentId, student.name, student.email, student.phone,"1");
        printf("\t--------------------------------------------------------------------------------------------------------\n");
    }
    fclose(file);
}

void findStudent(){
    char name[20];
    struct Student student;
    int found=0;
    printf("\t\tNhap ten hoc sinh muon tim: ");
    scanf(" %[^\n]",name);
    FILE *file=fopen("datastudent.bin","rb");
    printf("\t--------------------------------------------------------------------------------------------------------\n");
	printf("\t|%-10s | %-20s | %-30s | %-20s | %-10s|\n", "ID", "Name", "Email", "Phone", "NO.Course");
	printf("\t--------------------------------------------------------------------------------------------------------\n");
    while (fread(&student,sizeof(struct Student),1,file)) {
        if(strstr(student.name,name)!=NULL){
            found=1;
            printf("\t|%-10s | %-20s | %-30s | %-20s | %-10s|\n",student.studentId, student.name, student.email, student.phone, "1");
        	printf("\t--------------------------------------------------------------------------------------------------------\n");
        }
    }
    if(!found){
    	system("cls");
        printf("\t\tKhong ton tai sinh vien voi ID %s\n",name);
    }
    fclose(file);
}

void editStudent(){
    char id[10];
    printf("\t\t*** Edit a Student ***\n");
    printf("\tEnter The Student ID: ");
    scanf("%s",id);
    FILE *file = fopen("datastudent.bin","rb+");
    struct Student student;
    int found=0;
    long pos;
    while(fread(&student,sizeof(struct Student),1,file)){
        if(strcmp(student.studentId,id)==0){
            found=1;
            pos=ftell(file)-sizeof(struct Student);
            printf("\tStudent Found for ID: %s\n",student.studentId);
            printf("\t\tStudent Informations\n");
            printf("\t----------------------------------\n");
            printf("\tName: %s\n",student.name);
            printf("\tGender: %s\n",student.gender ? "Nam" : "Nu");
            printf("\tEmail: %s\n",student.email);
            printf("\tPhone: %s\n",student.phone);
            while(1){
                printf("\tEnter The New Name: ");
                scanf(" %[^\n]",student.name);
                if(strlen(student.name)==0){
                    printf("\tTen khong hop le! Vui long nhap lai\n");
                    continue;
                }
                break;
            }
            while(1){
                printf("\tEnter The New Gender (0-Nu, 1-Nam): ");
                int genderInput;
                scanf("%d",&genderInput);
                if(genderInput==0){
                    student.gender=false;
                }else if(genderInput==1){
                    student.gender=true;
                }
                break;
            }
            while(1){
                printf("\tEnter The New Email: ");
                scanf("%s",student.email);
                if(strlen(student.email)>0 && !isValidEmail(student.email)){
                    printf("\tKhong dung dinh dang! Vui long nhap lai!\n");
                    continue;
                }
                break;
            }
            while(1){
                printf("\tEnter The New Phone: ");
                scanf("%s",student.phone);
                if(strlen(student.phone)>0 && !isValidPhone(student.phone)){
                    printf("\tSo dien thoai khong dung! Vui long nhap lai!\n");
                    continue;
                }
                break;
            }
            fseek(file,pos,SEEK_SET);
            fwrite(&student,sizeof(struct Student),1,file);
            printf("\tCap nhat sinh vien thanh cong.\n");
            break;
        }
    }
    if(!found){
        printf("Khong ton tai sinh vien voi ID %s\n",id);
    }
    fclose(file);
}

void deleteStudent(){
    char id[10];
    printf("\t\t*** Delete a Student ***\n");
    printf("\tEnter The Student ID: ");
    scanf("%s",id);
    FILE *file=fopen("datastudent.bin","rb");
    struct Student student;
    int found=0;
    FILE *tempFile=fopen("temp.dat","wb");
    while(fread(&student,sizeof(struct Student),1,file)){
        if(strcmp(student.studentId,id)==0){
            found=1;
            printf("\tOne Student Found for ID: %s\n",student.studentId);
            printf("\tName: %s\n",student.name);
            printf("\tGender: %s\n",student.gender ? "Nam" : "Nu");
            printf("\tEmail: %s\n",student.email);
            printf("\tPhone: %s\n",student.phone);
            printf("\tBan co muon xoa sinh vien nay khong? (Y/N): ");
            char ans;
            scanf("%c",&ans);
            if (ans=='Y' || ans=='y'){
                printf("\tXoa sinh vien thanh cong.\n");
                continue;
            }
        }
        fwrite(&student,sizeof(struct Student),1,tempFile);
    }
    if(!found){
        printf("\tKhong tim thay sinh vien co ID %s.\n",id);
    }
    fclose(file);
    fclose(tempFile);
    remove("datastudent.bin");
    rename("temp.dat","datastudent.bin");
}

void sortStudents(){
    FILE *file=fopen("datastudent.bin","rb");
    struct Student students[MAX_STUDENTS];
    int count=0;
    while(fread(&students[count],sizeof(struct Student),1,file) && count<MAX_STUDENTS){
        count++;
    }
    fclose(file);
    int order;
    printf("\tChon thu tu sap xep: \n");
    printf("\t1. Tang dan\n");
    printf("\t2. Giam dan\n");
    printf("\tLua chon cua ban (1/2): ");
    scanf("%d",&order);
    int i,j;
    for(i=0;i<count-1;i++){
        for(j=i+1;j<count;j++){
            int comparison=strcmp(students[i].name,students[j].name);
            if((order==1 && comparison>0) || (order==2 && comparison<0)){
                struct Student temp=students[i];
                students[i]=students[j];
                students[j]=temp;
            }
        }
    }
    printf("\t\t*** Sorted Students ***\n");
    printf("\t--------------------------------------------------------------------------------------------------------\n");
    printf("\t|%-10s | %-20s | %-10s | %-30s | %-20s|\n", "ID", "Name", "Gender", "Email", "Phone");
	printf("\t--------------------------------------------------------------------------------------------------------\n");
    for(i=0;i<count;i++){
        printf("\t|%-10s | %-20s | %-10s | %-30s | %-20s|\n", students[i].studentId, students[i].name, students[i].gender ? "Nam" : "Nu", students[i].email, students[i].phone);
        printf("\t--------------------------------------------------------------------------------------------------------\n");
    }
}



void displayTeacherMenu(){
	system("cls");
	int choice;
    do{
    	printf("\n\t**** Student Management System Using C ****\n");
	    printf("\n");
	    printf("\t\t\tTEACHER MENU\n");
	    printf("\t\t============================\n");
	    printf("\t\t[1] Add A New teacher.\n");
	    printf("\t\t[2] Show All teacher.\n");
	    printf("\t\t[3] Search A teacher.\n");
	    printf("\t\t[4] Edit A teacher.\n");
	    printf("\t\t[5] Delete A teacher.\n");
	    printf("\t\t[0] Exit the Program.\n");
	    printf("\t\t============================\n");
	    printf("\t\tEnter The Choice: ");
	    scanf("%d",&choice);
	    getchar();
	    switch(choice){
	    	case 1:
	    		system("cls");
	    		addTeacher();
	    		break;
	    	case 2:
	    		system("cls");
				showTeacher();
				break;
			case 3:
				system("cls");
				findTeacher();
				break;
			case 4:
				system("cls");
				editTeacher();
				break;
			case 5:
				system("cls");
				deleteTeacher();
				break;
			case 0:
				system("cls");
				printf("\t\tTam biet!");
				return;	
			default:
				system("cls");
				printf("\t\tvui long chon lai!!!\n");
				break;							
		}
	}while(choice!=0);
}

int checkIdGV(char *id){
    FILE *file=fopen("datateacher.bin","rb");
    struct Teacher teacher;
    while(fread(&teacher,sizeof(struct Teacher),1,file)){
        if(strcmp(teacher.teacherId,id)==0){
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

int checkEmailGV(const char *email){
    FILE *file=fopen("datateacher.bin","rb");
    struct Teacher teacher;
    while(fread(&teacher,sizeof(struct Teacher),1,file)){
        if(strcmp(teacher.email,email)==0){
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

int checkPhoneGV(const char *phone){
    FILE *file=fopen("datateacher.bin","rb");
    struct Teacher teacher;
    while(fread(&teacher,sizeof(struct Teacher),1,file)){
        if(strcmp(teacher.phone,phone)==0){
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

int checkNameGV(const char *name){
    FILE *file=fopen("datateacher.bin","rb");
    struct Teacher teacher;
    while(fread(&teacher,sizeof(struct Teacher),1,file)){
        if(strcmp(teacher.name,name)==0){
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

void addTeacher(){
    struct Teacher teacher;
    printf("\n\n\t\t*** Add A New Teacher ***\n");  
    while(1){
        printf("\t\tEnter The ID: ");
        scanf("%s",teacher.teacherId);
        if(strlen(teacher.teacherId)==0 || strlen(teacher.teacherId)>9){
            printf("\t\tKhong hop le! Vui long nhap lai!\n");
            continue;
        }
        if(checkIdGV(teacher.teacherId)){
            printf("\t\tLoi: ID nay da ton tai!!!\n");
            continue;
        }
        break;
    }
    while(1){
        printf("\t\tEnter The Name: ");
        scanf(" %[^\n]",teacher.name);
        if(strlen(teacher.name)==0){
            printf("\t\tKhong hop le! Vui long nhap lai!\n");
            continue;
        }
        if(checkNameGV(teacher.name)){
            printf("\t\tLoi: Ten nay da ton tai!!!\n");
            continue;
        }
        break;
    }
    while(1){
        printf("\t\tEnter The Gender (0-Nu, 1-Nam): ");
        int genderInput;
        scanf("%d",&genderInput);
        if(genderInput==0){
            teacher.gender=false;
            break;
        }else if(genderInput==1){
            teacher.gender=true;
            break;
        }else{
            printf("\t\tKhong hop le! Vui long nhap 0 hoac 1!\n");
        }
    }
    while(1){
        printf("\t\tEnter The Email: ");
        scanf("%s",teacher.email);
        if(!isValidEmail(teacher.email)){
            printf("\t\tKhong dung dinh dang @gmail.com! Vui long nhap lai!\n");
            continue;
        }
        if(checkEmailGV(teacher.email)){
            printf("\t\tLoi: Gmail nay da ton tai!!!\n");
            continue;
        }
        break;
    }
    while(1){
        printf("\t\tEnter The Phone: ");
        scanf("%s",teacher.phone);
        if(!isValidPhone(teacher.phone)){
            printf("\t\tKhong hop le! Vui long nhap lai!\n");
            continue;
        }
        if(checkPhoneGV(teacher.phone)){
        	printf("\t\tLoi: So dien thoai nay da ton tai!!!\n");
        	continue;
        }
        break;
    }
    FILE *writeFile=fopen("datateacher.bin","ab");
    fwrite(&teacher,sizeof(struct Teacher),1,writeFile);
    fclose(writeFile);
    printf("\t\tThem giao vien thanh cong!\n");
}

void showTeacher(){
    FILE *file=fopen("datateacher.bin","rb");
    struct Teacher teacher;
    printf("\t\t\t\t\t\t*** All Teacher ***\n");
    printf("\t--------------------------------------------------------------------------------------------------------\n");
    printf("\t|%-10s | %-20s | %-30s | %-20s | %-10s|\n", "ID", "Name", "Email", "Phone", "NO.Course");
    printf("\t--------------------------------------------------------------------------------------------------------\n");
    while(fread(&teacher,sizeof(struct Teacher),1,file)){
        printf("\t|%-10s | %-20s | %-30s | %-20s | %-10s|\n",teacher.teacherId, teacher.name, teacher.email, teacher.phone, "1");
        printf("\t--------------------------------------------------------------------------------------------------------\n");
    }
    fclose(file);
}

void editTeacher(){
    char id[10];
    printf("\t\t*** Edit a Teacher ***\n");
    printf("\tEnter The Teacher ID: ");
    scanf("%s",id);
    FILE *file=fopen("datateacher.bin","rb+");
    struct Teacher teacher;
    int found=0;
    long pos;
    while(fread(&teacher,sizeof(struct Teacher),1,file)){
        if(strcmp(teacher.teacherId, id)==0){
            found=1;
            pos=ftell(file)-sizeof(struct Teacher);
            printf("\tTeacher Found for ID: %s\n",teacher.teacherId);
            printf("\t\tTeacher Informations\n");
            printf("\t----------------------------------\n");
            printf("\tName: %s\n",teacher.name);
            printf("\tGender: %s\n",teacher.gender ? "Nam" : "Nu");
            printf("\tEmail: %s\n",teacher.email);
            printf("\tPhone: %s\n",teacher.phone);
            while(1){
                printf("\tEnter The New Name: ");
                scanf(" %[^\n]",teacher.name);
                if(strlen(teacher.name)==0){
                    printf("\tTen khong hop le! Vui long nhap lai\n");
                    continue;
                }
                break;
            }
            while(1){
                printf("\tEnter The New Gender (0-Nu, 1-Nam): ");
                int genderInput;
                scanf("%d",&genderInput);
                if(genderInput==0){
                    teacher.gender=false;
                }else if(genderInput==1){
                    teacher.gender=true;
                }
                break;
            }
            while(1){
                printf("\tEnter The New Email: ");
                scanf("%s",teacher.email);
                if(strlen(teacher.email)>0 && !isValidEmail(teacher.email)){
                    printf("\tKhong dung dinh dang! Vui long nhap lai!\n");
                    continue;
                }
                break;
            }
            while(1){
                printf("\tEnter The New Phone: ");
                scanf("%s",teacher.phone);
                if(strlen(teacher.phone)>0 && !isValidPhone(teacher.phone)){
                    printf("\tSo dien thoai khong dung! Vui long nhap lai!\n");
                    continue;
                }
                break;
            }
            fseek(file,pos,SEEK_SET);
            fwrite(&teacher,sizeof(struct Teacher),1,file);

            printf("\tCap nhat giao vien thanh cong.\n");
            break;
        }
    }
    if(!found){
        printf("Khong ton tai giao vien voi ID %s\n",id);
    }
    fclose(file);
}

void deleteTeacher(){
    char id[10];
    printf("\t\t*** Delete a Teacher ***\n");
    printf("\tEnter The Teacher ID: ");
    scanf("%s",id);
    FILE *file=fopen("datateacher.bin","rb");
    struct Teacher teacher;
    int found=0;
    FILE *tempFile=fopen("temp.dat","wb");
    while(fread(&teacher,sizeof(struct Teacher),1,file)){
        if(strcmp(teacher.teacherId,id)==0){
            found=1;
            printf("\tOne Teacher Found for ID: %s\n",teacher.teacherId);
            printf("\tName: %s\n",teacher.name);
            printf("\tGender: %s\n",teacher.gender ? "Nam" : "Nu");
            printf("\tEmail: %s\n",teacher.email);
            printf("\tPhone: %s\n",teacher.phone);
            printf("\tBan co muon xoa giao vien nay khong? (Y/N): ");
            char ans;
            scanf("%c",&ans);
            if(ans=='Y' || ans=='y'){
                printf("\tXoa giao vien thanh cong.\n");
                continue;
            }
        }
        fwrite(&teacher,sizeof(struct Teacher),1,tempFile);
    }
    if(!found){
        printf("\tKhong tim thay giao vien co ID %s.\n",id);
    }
    fclose(file);
    fclose(tempFile);
    remove("datateacher.bin");
    rename("temp.dat","datateacher.bin");
}

void findTeacher(){
	char name[20];
    struct Teacher teacher;
    int found=0;
    printf("\t\tNhap ten giao vien muon tim: ");
    scanf("%[^\n]",name);
    FILE *file=fopen("datateacher.bin","rb");
    printf("\t--------------------------------------------------------------------------------------------------------\n");
	printf("\t|%-10s | %-20s | %-30s | %-20s | %-10s|\n", "ID", "Name", "Email", "Phone", "NO.Course");
	printf("\t--------------------------------------------------------------------------------------------------------\n");
    while(fread(&teacher,sizeof(struct Teacher),1,file)) {
        if(strstr(teacher.name,name)!=NULL){
            found=1;
            printf("\t|%-10s | %-20s | %-30s | %-20s | %-10s|\n",teacher.teacherId, teacher.name, teacher.email, teacher.phone, "1");
        	printf("\t--------------------------------------------------------------------------------------------------------\n");
        }
    }
    if(!found){
    	system("cls");
        printf("\t\tKhong co giao vien ten '%s'.\n",name);
    }
    fclose(file);
}


void displayClassMenu(){
	system("cls");
	int choice;
    do{
    	printf("\n\t**** Student Management System Using C ****\n");
	    printf("\n");
	    printf("\t\t\tCLASSROOM MENU\n");
	    printf("\t\t============================\n");
	    printf("\t\t[1] Add A New classroom.\n");
	    printf("\t\t[2] Show All classroom.\n");
	    printf("\t\t[3] Search A classroom.\n");
	    printf("\t\t[4] Edit A classroom.\n");
	    printf("\t\t[5] Delete A classroom.\n");
	    printf("\t\t[6] Sort classroom by Name\n");
	    printf("\t\t[7] Add A Students\n");
	    printf("\t\t[8] Delete A Students\n");
	    printf("\t\t[0] Exit the Program.\n");
	    printf("\t\t============================\n");
	    printf("\t\tEnter The Choice: ");
	    scanf("%d",&choice);
	    getchar();
	    switch(choice){
	    	case 1:
	    		system("cls");
	    		addClass();
	    		break;
	    	case 2:
	    		system("cls");
				showClass();
				break;
			case 3:
				system("cls");
				printf("chua lam b eii");
				break;
			case 4:
				system("cls");
				editClass();
				break;
			case 5:
				system("cls");
				deleteClass();
				break;
			case 6:
				system("cls");
				printf("chua lam b eii");
				break;
			case 7:
				system("cls");
				printf("chua lam b eii");
				break;
			case 8:
				system("cls");
				printf("chua lam b eii");
				break;			
			case 0:
				system("cls");
				printf("\t\tTam biet!");
				return;	
			default:
				system("cls");
				printf("\t\tvui long chon lai!!!\n");
				break;							
		}
	}while(choice!=0);
}

int checkIdClass(char *id){
    FILE *file=fopen("dataclass.bin","rb");
    struct Classroom classroom;
    while(fread(&classroom,sizeof(struct Classroom),1,file)){
        if(strcmp(classroom.classroomId,id)==0){
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

int checkNameClass(const char *classroomName){
    FILE *file=fopen("dataclass.bin","rb");
    struct Classroom classroom;
    while(fread(&classroom,sizeof(struct Classroom),1,file)){
        if(strcmp(classroom.classroomName,classroomName)==0){
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

void addClass(){
    struct Classroom classroom;
    printf("\n\n\t\t*** Add A New Classroom ***\n");  
    while(1){
        printf("\t\tEnter The ID: ");
        scanf("%s",classroom.classroomId);
        if(strlen(classroom.classroomId)==0 || strlen(classroom.classroomId)>9){
            printf("\t\tKhong hop le! Vui long nhap lai!\n");
            continue;
        }
        if(checkIdClass(classroom.classroomId)){
            printf("\t\tLoi: ID nay da ton tai!!!\n");
            continue;
        }
        break;
    }
    while(1){
        printf("\t\tEnter The Name: ");
        scanf(" %[^\n]",classroom.classroomName);
        if(strlen(classroom.classroomName)==0){
            printf("\t\tKhong hop le! Vui long nhap lai!\n");
            continue;
        }
        if(checkNameClass(classroom.classroomName)){
            printf("\t\tLoi: Ten nay da ton tai!!!\n");
            continue;
        }
        break;
    }
   
    FILE *writeFile=fopen("dataclass.bin","ab");
    fwrite(&classroom,sizeof(struct Classroom),1,writeFile);
    fclose(writeFile);
    printf("\t\tThem lop thanh cong!\n");
}

void showClass(){
    FILE *file=fopen("dataclass.bin","rb");
    struct Classroom classroom;
    printf("\t\t*** All Classroom ***\n");
    printf("\t------------------------------------\n");
    printf("\t|%-10s | %-20s |\n", "ID", "Name");
    printf("\t------------------------------------\n");
    while(fread(&classroom,sizeof(struct Classroom),1,file)){
        printf("\t|%-10s | %-20s |\n",classroom.classroomId,classroom.classroomName);
    	printf("\t------------------------------------\n");
    }
    fclose(file);
}

void editClass(){
    char id[10];
    printf("\t\t*** Edit a Classroom ***\n");
    printf("\tEnter The Classroom ID: ");
    scanf("%s",id);
    FILE *file=fopen("dataclass.bin","rb+");
    struct Classroom classroom;
    int found=0;
    long pos;
    while(fread(&classroom,sizeof(struct Classroom),1,file)){
        if(strcmp(classroom.classroomId,id)==0){
            found=1;
            pos=ftell(file)-sizeof(struct Classroom);
            printf("\tClassroom Found for ID: %s\n",classroom.classroomId);
            printf("\t\tClassroom Informations\n");
            printf("\t----------------------------------\n");
            printf("\tName: %s\n",classroom.classroomName);
            while(1){
                printf("\tEnter The New Name: ");
                scanf("%[^\n]",classroom.classroomName);
                if(strlen(classroom.classroomName)==0){
                    printf("\tTen khong hop le! Vui long nhap lai\n");
                    continue;
                }
                break;
            }
            fseek(file,pos,SEEK_SET);
            fwrite(&classroom,sizeof(struct Classroom),1,file);
            printf("\tCap nhat lop thanh cong.\n");
            break;
        }
    }
    if(!found){
        printf("Khong ton tai lop voi ID %s\n",id);
    }
    fclose(file);
}

void deleteClass(){
    char id[10];
    printf("\t\t*** Delete a Classroom ***\n");
    printf("\tEnter The Classroom ID: ");
    scanf("%s",id);
    FILE *file=fopen("dataclass.bin","rb");
    struct Classroom classroom;
    int found=0;
    FILE *tempFile=fopen("temp.dat","wb");
    while(fread(&classroom, sizeof(struct Classroom),1,file)){
        if(strcmp(classroom.classroomId,id)==0){
            found=1;
            printf("\tOne Classroom Found for ID: %s\n",classroom.classroomId);
            printf("\tName: %s\n",classroom.classroomName);
            printf("\tBan co muon xoa lop nay khong? (Y/N): ");
            char ans;
            scanf("%c",&ans);
            if(ans=='Y' || ans=='y'){
                printf("\tXoa lop thanh cong.\n");
                continue;
            }
        }
        fwrite(&classroom,sizeof(struct Classroom),1,tempFile);
    }
    if(!found){
        printf("\tKhong tim thay lop co ID %s.\n",id);
    }
    fclose(file);
    fclose(tempFile);
    remove("dataclass.bin");
    rename("temp.dat","dataclass.bin");
}


