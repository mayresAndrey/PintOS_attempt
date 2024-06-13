# pintOS
<details>
<summary>Mudanças no ./src </summary>

- Para facilitar o export no src/utils depois de usar `make` usar `export PATH=$PATH:$(pwd)`, se nao quiser colocar no .bashrc/zshrc
Mas no src/threads(adicionado no src/threads/Makefile os comandos para executar o pintos mais facil. com GUI ou sem)
não precisa nem no `make check` do src/threads/build (se der algum erro oque foi modificado ta no src/tests/Make.tests:58)

- Para funcionar no Arch Linux modifiquei o src/Makefile.build:93 para ele reduzir o tamanho do loader.bin

- Adicionado logica para ir executando os testes em especifico, no caso do threads, basicamente usa `make ngui/gui TEST=<nome_do_test>`
</details>


### Objetivos:
- [ ] Alarm Clock
- [ ] Advanced Scheduler
### Detalhamentos:
<details>
    <summary>Alarm</summary>
    Reimplementar ` timer_sleep()` no `device/time.c` que ta originalmente implementado com 'busy wait',
    que fica chamando `thread_yiel()` enquanto o tempo não tiver passado
    ideia:
    Adicionar a verificação ao scheduler, adicionando um campo na struct de threads para indicar o tempo que ela deve ficar parada se tiver com status de blocking
</details>
<details>
    <summary>Scheduler</summary>
    Implementar uma mlfqs, na documentação oficial ele diz para dar opção de ter o mlfqs ou o por prioridade, então deveria implementar os dois(verificar!!); Com o mlfqs as prioridades definidas pelas threads devem ser ignoradas e controladas pelo escalonador
    
   [Fila esquema](https://www.google.com/url?sa=i&url=https://medium.com/@francescofranco_39234/multilevel-feedback-queue-3ae862436a95&psig=AOvVaw0uPvTNvKvDx0bKwYGvKyn_&ust=1718223750727000&source=images&cd=vfe&opi=89978449&ved=0CBIQjRxqFwoTCLD727Sw1IYDFQAAAAAdAAAAABAI) 
</details>


Equipe:
| [<img src="https://avatars.githubusercontent.com/u/96800329?v=4" width=115><br><sub>Luiz Gustavo</sub>](https://github.com/Zed201) |  [<img src="https://avatars.githubusercontent.com/u/101292201?v=4" width=115><br><sub>Heitor Melo</sub>](https://github.com/HeitorMelo)  | [<img src="https://avatars.githubusercontent.com/u/129231720?v=4" width=115><br><sub>Henrique César</sub>](https://github.com/SapoSopa) | [<img src="https://avatars.githubusercontent.com/u/136932932?v=4" width=115><br><sub>Emanuelle Giovanna</sub>](https://github.com/manugio3)
| :---: | :---: | :--:| :--:|
