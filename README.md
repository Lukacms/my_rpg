# MUL-200-MYRPG

![](https://github.com/EpitechPromo2026/B-MUL-200-BDX-2-1-myrpg-chloe.camus/blob/main/assets/scenes/logo.png)

## Description
Reproduce a [role play game](https://en.wikipedia.org/wiki/Role-playing_game) using CSFML.<br>
- Ours is an horror game based on [Corpse party](https://en.wikipedia.org/wiki/Corpse_Party)
- Your goal will be to succesfully escape the school you're in, while completing quests.

## How to use the project
- Clone the project
```
git clone git@github.com:Lukacms/my_rpg.git myrpg
```

- Go into the `myrpg` directory. A Makefile is used to compile the code, and it use the following rules:

| Command          | Result                                          |
| ---------------- | ----------------------------------------------- |
| `make`           | Builds a ```my_rpg``` executable.          |
| `make clean`     | Cleans build dumps, keeping the executable.     |
| `make fclean`    | Removes all of the files created by the build.  |
| `make re`        | Calls `make fclean` and then `make`.            |

- execute the programm without any arguments:
```
./my_rpg
```
- or with `-h` option to display help
- any other way will result in program's failure

## Returns 
The program return `0` on success or `84` in case of errors.

# Good luck, and try to stay alive :)
![](https://c.tenor.com/nj8N70Y96EIAAAAC/corpse-party.gif)


## Authors
- Luka Camus
- Louis Bassagal
- Nils Martin
- Kevin Demy

---

## If you want to modify the project / add to it:
- [Epitech Coding style](https://intra.epitech.eu/file/public/technical-documentations/epitech_c_coding_style.pdf)
- This project is finished since `08/05/2022`
