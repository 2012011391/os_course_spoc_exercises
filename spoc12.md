(0)12.1的第3题：ucore的进程控制块数据结构是如何组织的？主要字段分别表示什么？有哪些函数对它进行了修改？有哪些函数用到它？试着解释为何要修改或使用它。
答：proc_struct；
enum proc_state state;                      // 进程状态
int pid;                                    // 进程ID
int runs;                                   // 进程运行时间
uintptr_t kstack;                           // 进程内核栈
volatile bool need_resched;                 // 是否需要被调度或释放ＣＰＵ
struct proc_struct *parent;                 // 父进程
struct mm_struct *mm;                       // 进程的内存管理结构
struct context context;                     // 上下文
struct trapframe *tf;                       // Trap frame for current interrupt
uintptr_t cr3;                              // ＣＲ３寄存器值，存储页目录表基址
uint32_t flags;                             // 进程标识
char name[PROC_NAME_LEN + 1];               // 进程名字


(1)12.2的第4题：请在ucore启动时显示空闲进程（idleproc）和初始进程（initproc）的进程标识。
答：idleproc = 0, initproc = 1.


(2)12.2的第5题：请在ucore启动时显示空闲线程（idleproc）和初始进程(initproc)的进程控制块中的“pde_t *pgdir”的内容。它们是否一致？为什么？
答：


(3)12.3的第2题：第一个用户进程执行的代码在哪里？它是什么时候加载到内存中的？
答：


(4)12.4的第2题：试分析ucore操作系统内核是如何把子进程exit()的返回值传递给父进程wait()的？
答：


(5)12.4的第3题：试分析sleep()系统调用的实现。在什么地方设置的定时器？它对应的等待队列是哪个？它的唤醒操作在什么地方？
答：


(6)12.4的第3题：设计一个简化的进程管理子系统，可以管理并调度简化进程。



