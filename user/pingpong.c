#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    /*
    ping pong
        Escreva um programa de nível de usuário que utilize chamadas de sistema do xv6 para o ''pingpong'', ou seja, um byte entre dois processos por meio de um par de pipes, um para cada direção. O
        processo pai deve enviar um byte para o filho; o filho deve imprimir "<pid>: recebeu ping", onde
        <pid> é o seu ID de processo, escrever o byte no pipe para o pai e sair; o pai deve ler o byte do
        filho, imprimir "<pid>: recebeu pong" e sair. Sua solução deve estar no arquivo user/pingpong.c.
        
        Algumas dicas:
        • Adicione o programa ao UPROGS no Makefile;
        • Use pipe para criar um pipe;
        • Use fork para criar um filho;
        • Use read para ler de um pipe e write para escrever em um pipe;
        • Use getpid para encontrar o ID do processo da chamada do processo;
        • Programas de usuário no xv6 têm um conjunto limitado de funções de biblioteca disponíveis
        para eles. Você pode ver a lista em user/user.h; o código-fonte (exceto para chamadas de
        sistema) está em user/ulib.c, user/printf.c e user/umalloc.c.
     */

    int p[2];
    char buffer[10];
    pipe(p);
    int pid;
    pid = fork();

    if (pid < 0){
        printf("Erro\n");
        exit(0);
    } else if (pid == 0){ // Zero is son
        read(p[0], buffer, sizeof(buffer));
        printf("%d: recebeu %s\n", getpid(), buffer);
        write(p[1], "pong", 5);
        close(p[0]);
        close(p[1]);
        exit(0);
    }else{
        write(p[1], "ping", 5);
        wait(0);
        read(p[0], buffer, sizeof(buffer));
        printf("%d: recebeu %s\n", getpid(), buffer);
        close(p[0]);
        close(p[1]);
    }
    return 0;
}
