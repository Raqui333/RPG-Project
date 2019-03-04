# Rpg Project
default compiler is clang (clang++), you can easily change it in Makefile; change the variable CXX with your compiler</br>
e.g</br>
```CXX = g++</br>```

## Damage Rate Algorithm
the damage rate is calculated based by Enemy Hp divided by 10</br>
e.g</br>
Goblin 50HP 50MP => 0-5</br>
Wolf  100HP 100HP => 0-10</br>

## Experience Algorithm
experience earned by player when win is half of Enemy Hp</br>
e.g</br>
Goblin 50HP 50MP => 25xp</br>
Wolf  100HP 100MP => 50xp</br>
