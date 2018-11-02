#include "mesinkata.c"
//blm include include

int main(){
    int input;
    char username[100];
    Kata command;

    printf("(1)New Game\n");
    printf("(2)Start Game\n");
    printf("(3)Load Game\n");
    printf("(4)Exit\n");

    scanf("%d",&input);
    while ((input!=1)&&(input!=2)&&(input!=3)&&(input!=4)){
        printf("Inputan salah. Silahkan input angka yang valid.\n");
        scanf("%d",&input);
    }

    while (input!=4){
        switch (input){
            case 1:
                scanf("%s",&username);
                break;
            case 2:
                //boolean CekUsername(char username[30],*gatau mau nyimpen nama2 user dimana*)
                printf("Masukkan command\n");
                scanf(" %s", command.TabKata);
                while (!IsKataSama(command,KataEXIT)){
                    if (IsKataSama(command, KataGU)){
                    //fungsi GU
                    }
                    else if (IsKataSama(command, KataGD)){
                        //fungsi GD
                    }
                    else if (IsKataSama(command, KataGL)){
                        //fungsi GL
                    }
                    else if (IsKataSama(command, KataGR)){
                        //fungsi GR
                    }
                    else if (IsKataSama(command, KataORDER)){
                        //fungsi ORDER
                    }
                    else if (IsKataSama(command, KataPUT)){
                        //fungsi PUT
                    }
                    else if (IsKataSama(command, KataTAKE)){
                        //fungsi TAKE
                    }
                    else if (IsKataSama(command, KataCH)){
                        //fungsi CH
                    }
                    else if (IsKataSama(command, KataCT)){
                        //fungsi CT
                    }
                    else if (IsKataSama(command, KataPLACE)){
                        //fungsi PLACE
                    }
                    else if (IsKataSama(command, KataGIVE)){
                        //fungsi GIVE
                    }
                    else if (IsKataSama(command, KataRECIPE)){
                        //fungsi RECIPE
                    }
                    else if (IsKataSama(command, KataSAVE)){
                        //fungsi SAVE
                    }
                    else if (IsKataSama(command, KataLOAD)){
                        //fungsi LOAD
                    }
                    else {
                        printf("Command tidak valid. Silahkan input command lagi.\n");
                    }
                    scanf(" %s", command.TabKata);
                }
                if (IsKataSama(command,KataEXIT)){
                    input=4;
                }
                break;
            case 3:
                break;
        }
    }

    if (input==4){
        printf("Permainan berakhir! Sampai jumpa!\n");
        printf("    CREDITS:\n");
        printf("    Afviany Ryzki\n");
        printf("    I Pute Gede Wirasuta\n");
        printf("    Kintan Sekar Adinda\n");
        printf("    M. Rifky I Bariansyah\n");
        printf("    Pandyaka Aptanagi\n");
        printf("    Raihan Asyraf\n");
    }
}
