#include <stdio.h>
#include <signal.h>
#include <setjmp.h>

extern jmp_buf	here;

static void run_away (sig)
int	sig;
{
	fprintf (stderr, "\n\tUser Break\n");
	signal (SIGINT, run_away);
	longjmp (here, 2);
}

void sethandlers(void)
{
	signal (SIGINT, run_away);
}
