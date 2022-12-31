To run the project:

```
.../studentDatabaseSystem$ ./build/run_database.sh
```

if any problems with pointer stuff, do:
```
.../studentDatabaseSystem$ gdb runStudentDatabaseSystem
```
then:
`(gdb) run`
to pinpoint where in the code it's failing and why

Install gdb with:   
```
$sudo apt-get update
$sudo apt-get install gdb
```


Mac OS Systems:

The run_database.sh doesn't seem to work (perhaps the file ownership when I git clone?).
Anyways just do:
```
$ clear; gcc -g ./src/main.c -o main; ./main;
```
