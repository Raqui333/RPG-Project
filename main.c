#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// enemies info
struct enemies {
          struct snake  { int hp, mp;} sk;
          struct bat    { int hp, mp;} bt;
          struct dragon { int hp, mp;} dg;
} emy = {
          // hp    // mp
          50    ,  50    ,
          100   ,  100   ,
          1000  ,  5000  ,
};

// player info
struct player {
          int hp, mp, lvl;
          char name[7];
} ply = {
          100, 100, 1, "player"
};

int dmg_rate(int dmg){
          srand(time(NULL));
          return rand() % dmg;          
}

void actions(char act){
          char respin = '9';
          char chat[] = "Raqui \033[1;31m[GOD]\033[00m:\n" \
                        "   Hi scum I'm the God of this world and I'll test you!\n" \
                        "   Do you wanna die?\n\n";
          switch (act){
                    case '0': exit(0);
                    case '1': printf("No Quests\n"); break;
                    case '2':
                              printf("%s", chat);
                              
                              printf("0 Yes | 1 No\n");
                              
                              printf("> ");
                              scanf(" %c", &respin);

                              if (respin == '0') { exit(0);
                              } else if (respin == '1') { printf("Good choice\n");
                              } else { printf("Are you kidding me? DIE!"); exit(0); }
                    default: printf("0 Exit | 1 Quests | 2 NPCs\n");
          }
}

int main() {
          // HUD
          char resp = '9';
          while (1==1){
                    system("clear");
                    printf("%s: HP %d | MP %d | LV %d\n\n", ply.name, ply.hp, ply.mp, ply.lvl);

                    actions(resp);

                    printf("> ");
                    scanf(" %c", &resp);
          }

return 0;
}
