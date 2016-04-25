>Bakery算法，如果不用choosing机制，是否能够保证同步互斥？
>不用choosing机制,不能保证"忙则等待".反例如下:
1)设有两个进程P0 P1,初始number都为0.
2)P0算出max值(1)后更新number[0]之前,发生进程切换,此时number[0]仍旧为0.
3)P1算出max值(因为此时number[0]仍旧为0,所以max值为1)后更新number[1]=1.此时由于number[0]=0,跳出while循环,P1进入临界区.
4)P1进入临界区后,进程切换回P0,P0完成number[0]赋值,由于已保存的max为1,number[0]=1.此时(number[1],1)>(number[0],0),跳出while循环,P0进入临界区.
5)这样,P0和P1都进入了临界区,不满足"忙则等待".
6)原因主要是number的赋值操作可能被打断,因此应该通过choosing机制保证该赋值操作的原子性.
