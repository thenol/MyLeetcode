### Common Error
* Left-closed, right-open: $ [a,b)\;a<=x<b$
    ```python
    # 1.
    for i in range(n):
        print(i)    # 0,1,2,3...n-1

    # 2. 
    [i if i >3 for i in range(10)] #  Error
    [i if i>3 else 3 for i in range(10)] #  runnable
    [i for i in range(10) if i>3] #  runnable

    ```
* Generator and iterator
    * In general, changing variable variables (for instance, the list) should be avoided in loop control
    ```python
    a=[3,4,5,2,1]
    for i in a: # Note the iteration of i is up to the incremental index of the list, i.e. 【i=a[idx++], where idx increments one by one】
        print('i:',i,a.index(i))
        a.remove(i)
        print(a)
    # result:
    i: 3 0
    [4, 5, 2, 1]
    i: 5 1
    [4, 2, 1]
    i: 1 2
    [4, 2]
    # Iterator: Note the index is generated by the generator,
    #  which is actually the increment of the index of the list

    # Another example:
    class MyNumbers:
    def __iter__(self):
        self.a = 1
        return self
    
    def __next__(self):
        x = self.a
        self.a += 1
        return x
    
    myclass = MyNumbers()
    myiter = iter(myclass)
    ```
* Relationship between loop control variables and variable values in loops
    ```python
    i=0
    a = 1
    while i < 5: # map: <i,a>=<0,3>,<1,3>...<4,6>,<5,stop>
        a+=1
        i+=1
    
    # which means the below:(i:value, limit:value, execution times)=>(limit:2, times:limit-i_0=2)
    #   i=0, running the loop, a=1, executed once
    #   i=1, running the loop, a=2, executed twice

    ```
* Notes on operators:
    * $\lfloor\frac{M}{N}\rfloor-1(\frac{N}{N})\le\lfloor\frac{M-1}{N}\rfloor=\lfloor\frac{M}{N}-\frac{1}{N}\rfloor\le\lfloor\frac{M}{N}\rfloor-\lfloor\frac{1}{N}\rfloor\approx\lfloor\frac{M}{N}\rfloor$
    * $\lfloor\frac{M}{N}\rfloor = M//N $

