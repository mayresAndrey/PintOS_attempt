 # pintOS
Para facilitar o export no src/utils depois de usar `make` usar `export PATH=$PATH:$(pwd)`, se nao quiser colocar no .bashrc/zshrc
Mas no src/threads(adicionado no src/threads/Makefile os comandos para executar o pintos mais facil. com GUI ou sem)
não precisa nem no `make check` do src/threads/build (se der algum erro oque foi modificado ta no src/tests/Make.tests:58)

Para funcionar no Arch Linux modifiquei o src/Makefile.build:93 para ele reduzir o tamanho do loader.bin

Objetivos:
- [ ] Alarm Clock
<details>
    <summmary>Timer</summmary>
    Reimplementar time_sleep() no `device/time.c` que ta originalmente implementado com 'busy wait',
    que fica chamando thread_yiel() enquanto o tempo não tiver passado
</details>
# terminar
- [ ] Advanced Scheduler
<details>
    <summmary> </summmary>
</details>

Equipe:
| [<img src="https://avatars.githubusercontent.com/u/96800329?v=4" width=115><br><sub>Luiz Gustavo</sub>](https://github.com/Zed201) |  [<img src="https://avatars.githubusercontent.com/u/101292201?v=4" width=115><br><sub>Heitor Melo</sub>](https://github.com/HeitorMelo)  | [<img src="https://avatars.githubusercontent.com/u/129231720?v=4" width=115><br><sub>Henrique César</sub>](https://github.com/SapoSopa) | [<img src="https://avatars.githubusercontent.com/u/136932932?v=4" width=115><br><sub>Emanuelle Giovanna</sub>](https://github.com/manugio3)
| :---: | :---: | :--:| :--:|
