#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// enemies info
struct enemies {
          struct snake  { int hp, mp; } sk;
          struct bat    { int hp, mp; } bt;
          struct dragon { int hp, mp; } dg;
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
          char attack_one[6];
          char attack_two[9];
          char attack_three[8];
} ply = {
          100, 100, 1, "player", "Slash", "Fireball", "Iceball"
};

// hud
char hud[99];

int dmg_rate(int dmg){
          srand(time(NULL));
          return rand() % dmg;          
}

void battle(int enemy){
          struct att_now { int hp, mp; char name[10]; } choice;
          
          if (enemy == 1) { struct att_now choice = { emy.sk.hp, emy.sk.mp, "snake" };
          } else if (enemy == 2) { struct att_now choice = { emy.sk.hp, emy.sk.mp, "bat" };
          } else if (enemy == 3) { struct att_now choice = { emy.sk.hp, emy.sk.mp, "dragon" };
          } else { printf("what this kind of programmer is doing?\n"); }
          
          while (1==1){
                    char respin = '9';
                    system("clear");
                    
                    sprintf(hud, "%s: HP %d | MP %d | LV %d", ply.name, ply.hp, ply.mp, ply.lvl);
                    printf("%s\n", hud);
          
                    printf("%s: HP %d | MP %d\n\n", choice.name, choice.hp, choice.mp);
          
                    printf("Actions: 0 Run | 1 %s | 2 %s | 3 %s\n", ply.attack_one, ply.attack_two, ply.attack_three);
                    
                    printf("> ");
                    scanf(" %c", &respin);
          
                    switch (respin){
                              case '0': choice.hp = -999; break;
                              case '1': if (ply.mp >= 20) { ply.mp = ply.mp - 20; choice.hp = choice.hp - dmg_rate(20);
                                        } else { choice.hp = choice.hp - dmg_rate(10); }
                                        break;
                              default: printf("nothing\n\n");
                    }
                    
                    if (choice.mp >= 20) { choice.mp = choice.mp - 20; ply.hp = ply.hp - dmg_rate(20);
                    } else { ply.hp = ply.hp - dmg_rate(10); }
                    
                    if (choice.hp <= 0 && choice.hp != -999) { printf("You Win!\n"); system("read"); break;
                    } else if (ply.hp <= 0) { printf("Game Over\n"); system("read"); exit(0);
                    } else if (choice.hp == -999) { printf("You Run!\n"); system("read"); break; }
          }
}

void help_npc(){
          char chat_1[] = "\nhelp_npc:\n" \
                          "   Hello, I will show you some functions of this world\n" \
                          "   first; Battle, let's get started!\n\n";
          
          printf("%s", chat_1);
          system("read");
          battle(1);
}

void actions(char act){
          char respin = '9';
          switch (act){
                    case '0': exit(0);
                    case '1': printf("No Quests\n\n0 Exit | 1 Quests | 2 NPCs\n"); break;
                    case '2': printf("0 Back | 1 Help | 2 Raqui\n");
                              
                              printf("> ");
                              scanf(" %c", &respin);
                              
                              if (respin == '1') help_npc();
                    default: printf("0 Exit | 1 Quests | 2 NPCs\n");
          }
}

int main() {
          // HUD
          sprintf(hud, "%s: HP %d | MP %d | LV %d", ply.name, ply.hp, ply.mp, ply.lvl);
          char resp = '9';
          while (1==1){
                    system("clear");
                    printf("%s\n\n", hud);

                    actions(resp);

                    printf("> ");
                    scanf(" %c", &resp);
          }

return 0;
}
