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
