#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{   
    // Pipe for communication
    int pipefd[2];
    int pid;

    char *ls_args[] = {"ls", NULL};
    char *nl_args[] = {"nl", NULL};

    pipe(pipefd);

    pid = fork();
    if (pid < 0)
        perror("Fork failed!");
    else if (pid > 0)
    {
        // Redirect Stdout to Pipe's write end
        close(pipefd[0]);
        dup2(pipefd[1], 1);
        close(pipefd[1]);

        execvp(*ls_args, ls_args);
    }
    else
    {
        pid = fork();
        if (pid < 0)
            perror("Fork failed!");
        else if (pid > 0)
        {
            // Redirect Stdin to Pipe's read end
            close(pipefd[1]);
            dup2(pipefd[0], 0);
            close(pipefd[0]);

            execvp(*nl_args, nl_args);
        }
        else
        {
            // Wait until childrens exit
            wait(NULL);
            wait(NULL);
        }
        
    }
}