#ifndef THREADS_THREAD_H
#define THREADS_THREAD_H
 
#include <debug.h>
#include <list.h>
#include <stdint.h>

/* States in a thread's life cycle. */
enum thread_status
  {
    THREAD_RUNNING,     /* Running thread. */
    THREAD_READY,       /* Not running but ready to run. */
    THREAD_BLOCKED,     /* Waiting for an event to trigger. */
    THREAD_DYING        /* About to be destroyed. */
  };

/* Thread identifier type.
   You can redefine this to whatever type you like. */
typedef int tid_t;
#define TID_ERROR ((tid_t) -1)          /* Error value for tid_t. */

/* Thread priorities. */
#define PRI_MIN 0                       /* Lowest priority. */
#define PRI_DEFAULT 31                  /* Default priority. */
#define PRI_MAX 63                      /* Highest priority. */

/* Nosso código começa aqui */

//==============================================================================================================
//IMPLEMENTAÇÃO DO FLOAT 

#define FLOAT_SHIFT_AMOUNT 17
#define F mypow(14)
#define Q 14

int mypow(int p);
typedef int float_type;

#define FLOAT_CONST(A) ((float_type)(A * F))
#define FLOAT_ADD(A,B) (A + B)
#define FLOAT_ADD_MIX(A,B) (A + (B * F))
#define FLOAT_SUB(A,B) (A - B)
#define FLOAT_SUB_MIX(A,B) (A - (B * F))
#define FLOAT_MULT_MIX(A,B) (A * B) 
#define FLOAT_DIV_MIX(A,B) (A / B)
#define FLOAT_MULT(A,B) ((float_type) (((int64_t) A) * B/ F)) 
#define FLOAT_DIV(A,B) ((float_type)((((int64_t) A) * F) / B))
#define FLOAT_INT_PART(A) (A >> FLOAT_SHIFT_AMOUNT)
#define FLOAT_ROUND(A) (A >= 0 ? ((A +(1 * mypow(Q - 1))) / F ) : ((A - (1 * mypow(Q - 1))) / F))

//==============================================================================================================

/* Nosso código termina aqui */

/* A kernel thread or user process.

   Each thread structure is stored in its own 4 kB page.  The
   thread structure itself sits at the very bottom of the page
   (at offset 0).  The rest of the page is reserved for the
   thread's kernel stack, which grows downward from the top of
   the page (at offset 4 kB).  Here's an illustration:

        4 kB +---------------------------------+
             |          kernel stack           |
             |                |                |
             |                |                |
             |                V                |
             |         grows downward          |
             |                                 |
             |                                 |
             |                                 |
             |                                 |
             |                                 |
             |                                 |
             |                                 |
             |                                 |
             +---------------------------------+
             |              magic              |
             |                :                |
             |                :                |
             |               name              |
             |              status             |
        0 kB +---------------------------------+

   The upshot of this is twofold:

      1. First, `struct thread' must not be allowed to grow too
         big.  If it does, then there will not be enough room for
         the kernel stack.  Our base `struct thread' is only a
         few bytes in size.  It probably should stay well under 1
         kB.

      2. Second, kernel stacks must not be allowed to grow too
         large.  If a stack overflows, it will corrupt the thread
         state.  Thus, kernel functions should not allocate large
         structures or arrays as non-static local variables.  Use
         dynamic allocation with malloc() or palloc_get_page()
         instead.

   The first symptom of either of these problems will probably be
   an assertion failure in thread_current(), which checks that
   the `magic' member of the running thread's `struct thread' is
   set to THREAD_MAGIC.  Stack overflow will normally change this
   value, triggering the assertion. */
/* The `elem' member has a dual purpose.  It can be an element in
   the run queue (thread.c), or it can be an element in a
   semaphore wait list (synch.c).  It can be used these two ways
   only because they are mutually exclusive: only a thread in the
   ready state is on the run queue, whereas only a thread in the
   blocked state is on a semaphore wait list. */
struct thread
  {
    /* Owned by thread.c. */
    tid_t tid;                          /* Thread identifier. */
    enum thread_status status;          /* Thread state. */
    char name[16];                      /* Name (for debugging purposes). */
    uint8_t *stack;                     /* Saved stack pointer. */
    int priority;                       /* Priority. */
    struct list_elem allelem;           /* List element for all threads list. */

    /* Shared between thread.c and synch.c. */ 
    struct list_elem elem;              /* List element. */

   #ifdef USERPROG
    /* Owned by userprog/process.c. */
    uint32_t *pagedir;                  /* Page directory. */
   #endif

    /* Owned by thread.c. */
    unsigned magic;                     /* Detects stack overflow. */

   /*Nosso código começa aqui*/

    int wakeup_time; /* Tempo que a thread precisa acordar. */
    int nice; /* A legalidade de uma thread com outras. */
    float_type recent_cpu; /* Medir o quanto de tempo da CPU recebeu recentemente. */

    /*Nosso código termina aqui*/
  };

//==============================================================================================================

/* If false (default), use round-robin scheduler.
   If true, use multi-level feedback queue scheduler.
   Controlled by kernel command-line option "-o mlfqs". */
extern bool thread_mlfqs;

/* System-wide segundo o documento do site*/ 
extern float_type load_avg; //eh um numero real

/* Nosso código começa aqui */

//para o timer_sleep 
bool compare_wakeup_time(const struct list_elem *a, const struct list_elem *b, void *aux UNUSED);
void thread_sleep(int64_t ticks);

//para o timer_interrupt
void thread_wakeup(void);

/* Nosso código termina aqui */

void thread_init (void);
void thread_start (void);

void thread_tick (void);
void thread_print_stats (void);

typedef void thread_func (void *aux);
tid_t thread_create (const char *name, int priority, thread_func *, void *);

void thread_block (void);
void thread_unblock (struct thread *);

struct thread *thread_current (void);
tid_t thread_tid (void);
const char *thread_name (void);

void thread_exit (void) NO_RETURN;
void thread_yield (void);

/* Performs some operation on thread t, given auxiliary data AUX. */
typedef void thread_action_func (struct thread *t, void *aux);
void thread_foreach (thread_action_func *, void *);

int thread_get_priority (void);
void thread_set_priority (int);
int thread_get_ready_threads();

int thread_get_nice (void);
void thread_set_nice (int);
int thread_get_recent_cpu (void);
int thread_get_load_avg (void);

#endif /* threads/thread.h */
