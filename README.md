# Log-Analyzer
A log analyzer for HTTP requests to a web server

## How to use 

- Add the log file you want to process as shown below,
```c#
ifstream filename("access_log.txt"); 
```
- Open up a new terminal 

- Use the command ```make``` to compile the code

- Run the code using the command ```./log```

Example Output is shown below, 
```
Most Accessed Sites:

1.th site: index.html accessed  140265 times.
2.th site: 3.gif accessed  24006 times.
3.th site: 2.gif accessed  23606 times.
4.th site: 4.gif accessed  8018 times.
5.th site: 244.gif accessed  5149 times.
.      .      .       .       .    .
.      .      .       .       .    .
.      .      .       .       .    .
.      .      .       .       .    .

Run Time : 3.67214 seconds

```
