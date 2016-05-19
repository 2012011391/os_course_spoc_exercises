>描述ucore操作系统中“键盘输入”从请求到完成的整个执行过程，并分析I/O过程的时间开销。
>在trap.c中有处理键盘输入事件‘case IRQ_OFFSET + IRQ_KBD’，发生键盘输入后，产生硬件中断，会调用这一块代码，具体如下：
	case IRQ_OFFSET + IRQ_KBD:
        c = cons_getc();
            //cprintf("kbd [%03d] %c\n", c, c);
            {
              extern void dev_stdin_write(char c);
              dev_stdin_write(c);
            }
            break;

通过cons_getc()获取输入字符；
通过dev_stdin_write()处理输入字符。dev_stdin_write()在dev_stdin.c中定义，具体如下：
void
dev_stdin_write(char c) {
    bool intr_flag;
    if (c != '\0') {
        local_intr_save(intr_flag);
        {
            stdin_buffer[p_wpos % STDIN_BUFSIZE] = c;
            if (p_wpos - p_rpos < STDIN_BUFSIZE) {
                p_wpos ++;
            }
            if (!wait_queue_empty(wait_queue)) {
                wakeup_queue(wait_queue, WT_KBD, 1);
            }
        }
        local_intr_restore(intr_flag);
    }
}
local_intr_save(intr_flag)屏蔽中断并保存上下文（如果有需要）；
stdin_buffer存储输入字符c；
如果等待队列不为空，唤醒等待队列；
恢复中断和之前保存的上下文。
