#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct Player{
    char name[10];
    int HP_P = 100;
    int atkP[] = {15, 25, 40, 60};
}player;

typedef struct Boss{
    char name[10];
    int HP_B = 100;
    int atkB[] = {15, 25, 40, 60};
}boss;

int *hp_ptrP;
int *hp_ptrB;

int *hp_ptrP = &HP_P
int *hp_ptrB = &HP_B

int main()
{
    player p;
    
    printf("Masukkan nama player "); scanf("%s", p.name);
    
    int c;
    boss enemy;
    boss b[3] = {
        [0].name = "Joko", [0].HP = 10, [0].Atk = 2,
        [1].name = "Budi", [0].HP = 11, [0].Atk = 3,
        [2].name = "Asep", [0].HP = 12, [0].Atk = 4
    };
    
    for(int i = 0; i < 3; i++){
        printf("%d. %s\n", i + 1, b[i].name);
    }
    
    printf("Pilih musuhmu "); scanf("%d", &c);
    switch(c){
        case 1 :
            strcpy(enemy.name, b[0].name);
            enemy.HP = b[0].HP;
            enemy.Atk = b[0].Atk;
        break;
        case 2 :
            strcpy(enemy.name, b[1].name);
            enemy.HP = b[0].HP;
            enemy.Atk = b[0].Atk;
        break;
        case 3 :
            strcpy(enemy.name, b[2].name);
            enemy.HP = b[0].HP;
            enemy.Atk = b[0].Atk;
        break;
    }
    
    puts("%s is your enemy", enemy.name);
    puts("Input ")
}

do{
    puts("It's your turn!");
    printf("Your enemy health: %d\n", health);
    puts("Choose your weapon!");
    puts("(1) Sword");
    puts("(2) Gun");
    printf("Which move do you want: "); // Input skill
    scanf("%d", &move);

    switch(move){ // Penentu damage per skill
        case 1:
        puts("It's your turn!");
        srand(time(NULL));
        x = rand() % 4;
        printf("You deal %d damages\n", atkP[x]);
        damage (hp_ptrP, atkP[x]);
        printf("\nYour enemy health now: %d\n\n", HP_B);
        break;
        case 2:
        puts("It's your turn!");
        srand(time(NULL));
        x = rand() % 4;
        printf("You deal %d damages\n", atkP[x]);
        damage (hp_ptrP, atkP[x]);
        printf("\nYour enemy health now: %d\n\n", HP_B);
        break;
        default:
            printf("Input invalid\n");
    }
    system("cls");
    
    if(health < 0){
        health = 0;
    }else if(health2 < 0){
        health2 = 0;
    }
    printf("\nYour enemy's health: %d\n\n", health);

    puts("It's your enemy's turn!");
    srand(time(NULL));
    x = rand() % 4;
    printf("Your enemy deal %d damages\n", atkB[x]);
    damage2 (hp_ptrB, atkB[x]);
    printf("\nYour health now: %d\n\n", health2);
    
    if(health <= 0){
        puts("\nYou've defeated your enemy!");
        return 0;
    }else if(health2 <= 0){
        puts("\nYou've been defeated.");
        return 0;
    }

    }while (health >= 0 || health2 >= 0);
}

