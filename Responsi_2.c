#include <stdio.h>

typedef struct {
    unsigned int number;
    char NamaDepan[10];
    char NamaBelakang[10];
    char NIM[9];
    unsigned int Umur;
    char jk[10];
    char IPK[4];
}student;

student Data[150];

int ChooseMenu();
void CreateData(FILE*);
void DeleteData(FILE*);
void Export(FILE*);
void Import(FILE*);
void UpdateData(FILE*);
void DisplayData(FILE*);

int main(){
    FILE *dataPtr = NULL;

    if((dataPtr = fopen("binary.txt", "rb+")) == 0){
        puts("\"binary.txt\" tidak ditemukan. Silahkan periksa kembali atau buat baru.");
    }else{
        int choice = 0;

        while ((choice = ChooseMenu()) != 5) {
            switch(choice){
                case 1:
                    UpdateData(dataPtr);
                    Export(dataPtr);
                break;
                case 2:
                    CreateData(dataPtr);
                    Export(dataPtr);
                break;
                case 3:
                    Import(dataPtr);
                    DisplayData(dataPtr);
                break;
                case 4:
                    DeleteData(dataPtr);
                    Export(dataPtr);
                break;
                default:
                    puts("Input tidak dapat dikenali");
                break;
            }
        }
    }
}

int ChooseMenu(){
    printf("\t\t%s\n\t\t%s\n\t\t%s\n\t\t%s\n\t\t%s\n\t\t%s\n\t\t%s",
            "====================(MENU)====================",
            "|1. Masukkan Nilai",
            "|2. Buat Baru",
            "|3. Tampilkan Data",
            "|4. Hapus Data Mahasiswa",
            "|5. Akhiri Program",
            "|Pilihan Anda ");

    int c;
    scanf("%d", &c);
    return c;
}

void CreateData(FILE *fPtr){
    int num = 0;
    while(num <= 0 || num > 159){
        printf("\t\t|Masukkan 3 angka terakhir NIM anda: "); scanf("%d", &num);
        if(num > 159) puts("\t\t|NIM maximal adalah 159");
    }

    fseek(fPtr, (num - 1) *  sizeof(student), SEEK_SET);

    if(Data[num - 1].number != 0){
        printf("\t\t|NIM L0122%.3d data sudah ada.\n", num);
    }else{
        printf("\t\t|Masukkan Nama Depan\t"); scanf("%s", Data[num - 1].NamaDepan);
        printf("\t\t|Masukkan Nama Belakang\t"); scanf("%s", Data[num - 1].NamaBelakang);
        printf("\t\t|Masukkan Umur\t"); scanf("%u", &Data[num - 1].Umur);
        printf("\t\t|Masukkan Gender\t"); scanf("%s", Data[num - 1].jk);
        printf("\t\t|Masukkan IPK\t"); scanf("%s", Data[num - 1].IPK);

        Data[num - 1].number = num;
        sprintf(Data[num - 1].NIM, "L0122%.3d", num);

        fseek(fPtr, (Data[num - 1].number - 1) * sizeof(student), SEEK_SET);

        fwrite(&Data[num - 1], sizeof(student), 1, fPtr);
    }
}

void DeleteData(FILE *fPtr){
    int num = 0;
    while(num <= 0 || num > 159){
        printf("\t\t|Masukkan 3 angka terakhir NIM anda: "); scanf("%d", &num);
        if(num > 159) puts("NIM maximal adalah 159");
    }
    
    fseek(fPtr, (num - 1) * sizeof(student), SEEK_SET);
    
    student sData = {0, "", "", "", 0, "", 0};
    fread(&sData, sizeof(student), 1, fPtr);
    
    if(sData.number == 0){
        printf("\t\tNIM L0122%.3d Tidak ada informasi.\n", num);
    }else{
        fseek(fPtr, (num - 1) * sizeof(student), SEEK_SET);
        
        student blankData = {0, "", "", "", 0, { 0 }};
        
        fwrite(&blankData, sizeof(student), 1, fPtr);
        
    }
}

void Export(FILE *readPtr){
    FILE *writePtr = NULL;

    if ((writePtr = fopen("DataSiswa.txt", "w")) == NULL) {
        puts("\"DataSiswa.txt\" tidak ditemukan. Silahkan periksa kembali atau buat baru.");
    }
    else {
        rewind(readPtr);
        fprintf(writePtr, "%-6s%-11s%-11s%-10s%-6s%-6s\n",
                "No.", "Nama Depan", "Nama Belakang ", "NIM", "Umur", "Nilai");

        while(!feof(readPtr)){
            student sData = {0, "", "", "", 0, "", 0};
            size_t result = fread(&sData, sizeof(student), 1, readPtr);

            if (result != 0 && sData.number != 0) {
                fprintf(writePtr, "%-6d%-11s%-11s%-10s%-6d%-11s%-5s\n",
                        sData.number, sData.NamaDepan, sData.NamaBelakang, sData.NIM, sData.Umur,
                        sData.jk, sData.IPK);
            }
        }
        fclose(writePtr);
    }
    puts("\t\t|File Tersimpan");
}

void Import(FILE *readPtr){
    for(int i = 1; i <= 159; i++){
        fseek(readPtr, (i - 1) * sizeof(student), SEEK_SET);

        student sData = {0, "", "", "", 0, { 0 }};
        fread(&sData, sizeof(student), 1, readPtr);
    }
}

void UpdateData(FILE *fPtr){
    int num = 0;
    while(num <= 0 || num > 159){
        printf("\t\t|Masukkan 3 angka terakhir NIM anda: "); scanf("%d", &num);
        if(num > 159) puts("\t\t|NIM maximal adalah 159");
    }

    fseek(fPtr, (num - 1) * sizeof(student), SEEK_SET);

    student sData = {0, "", "", "", 0, "", 0};
    fread(&sData, sizeof(student), 1, fPtr);

    if(sData.number == 0){
        printf("\t\t|NIM L0122%.3d Tidak ada informasi.\n", num);
    }else{
        printf("\t\t|%-6d%-11s%-11s%-10s%-6d%-11s%-5s\n",
                sData.number, sData.NamaDepan, sData.NamaBelakang, sData.NIM, sData.Umur,
                sData.jk, sData.IPK);
        
        fseek(fPtr, (num - 1) * sizeof(student), SEEK_SET);

        fwrite(&sData, sizeof(student), 1, fPtr);
    }
}

void DisplayData(FILE *readPtr){
    printf("\t\t%-6s%-11s%-11s%-10s%-6s%-11s%-5s\n",
            "|No.", "Nama Depan", "Nama Belakang", "NIM", "Umur", "Gender", "IPK");

    for(int i = 1; i <= 159; i++){
        if(Data[i].number != 0){
            printf("\t\t|%-6d%-11s%-11s%-10s%-6d%-11s%-5s\n",
                Data[i].number, Data[i].NamaDepan, Data[i].NamaBelakang, Data[i].NIM, Data[i].Umur,
                Data[i].jk, Data[i].IPK);
        }
    }
}
