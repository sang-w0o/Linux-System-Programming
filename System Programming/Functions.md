System Programming 시 사용되는 함수
======

<h2>main(int argc, char **argv)</h2>

* argc(Argument Count) : 호출 시 인자의 개수
* argv(Argument Vector Table) : 호출 시의 인자를 저장한 배열
<hr/>

<h2>fopen</h2>

```C
FILE *fopen(Const char *pathname, const char *mode);
```
* fopen() functions opens the file whose name is the string pointed to by __pathname__ and associates a stream with it.
* Header file : stdio.h
* mode
<table>
    <tr>
        <td>fopen() mode</td>
        <td>open() flags</td>
    </tr>
    <tr>
        <td>r</td>
        <td>O_RDONLY</td>
    </tr>
    <tr>
        <td>w</td>
        <td>O_WRONLY | O_CREAT | O_TRUNC</td>
    </tr>
    <tr>
        <td>a</td>
        <td>O_WRONLY | O_CREAT | O_APPEND</td>
    </tr>
    <tr>
        <td>r+</td>
        <td>O_RDWR</td>
    </tr>
    <tr>
        <td>w+</td>
        <td>O_RDWR | O_CREAT | O_TRUNC</td>
    </tr>
    <tr>
        <td>a+</td>
        <td>O_RDWR | O_CREAT | O_APPEND</td>
    </tr>
</table>

* Return value : Upon successful completion, fopen() returns a __FILE__ pointer. Otherwise, __NULL__ is returned and __errno__ is set to indicate the error.
<hr/>

<h2>fread</h2>

```c
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
```

* fread() function reads __nmemb__ items of data, each __size__ bytes long, from the stream pointed to by __stream__, storing them at the location given by __ptr__.
* Header file : stdio.h
* Return value : On success, fread() returns __the number of items read__. If an error occurs, or the EOF is reached, the return value is a __short item count(or 0)__.
<hr/>

<h2>fwrite</h2>

```c
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
```

* fwrite() functions writes __nmemb__ items of data, each __size__ bytes long, to the stream pointed by __stream__, obtaining them from the location given by __ptr__.
* Header file : stdio.h
* Return value : On success, fwrite() returns __the number of items written__. If an error occurs, or the EOF is reached, the return value is a __short item count(or 0)__.
<hr/>

<h2>fflush</h2>

```c
int fflush(FILE *stream);
```

* fflush() forces the flush of the given stream's buffer.
* Header file : stdio.h
* Return value : Upon successful completion, __0__ is returned. Otherwise, __EOF__ is returned and __errno__ is set to indicate the error.
<hr/>

<h2>fclose</h2>

```c
int fclose(FILE *stream);
```

* fclose() function flushes the stream pointed by __stream__ and closes the underlying file descriptor.
* Header file : stdio.h
* Return value : Upon successful completion, __0__ is returned. Otherwise, __EOF__ is returned and __errno__ is set to indicate the error.
<hr/>

<h2>fseek</h2>

```C
int fseek(FILE *stream, long offset, int whence);
```

* fseek() sets the __file position indicator__ for the stream pointed by __stream__. The new position, measured in bytes, is obtained by __adding offset bytes__ to the position specified by __whence__. If whence is set to __SEEK_SET, SEEK_CUR, SEEK_END__ , the offset is relative to the start of the file, the current position indicator, or EOF.
* Header file : stdio.h
* Return value : Upon successful completion, fseek() returns __0__. Otherwise, __-1__ is returned and __errno__ is set to indicate the error.
<hr/>

<h2>ftell</h2>

```C
long ftell(FILE *stream);
```

* The ftell() function obtains the __current value of the file position indicator__ for the stream pointed by __stream__.
* Header file : stdio.h
* Return value : Uppon successful completion, ftell() returns the __current offset__. Otherwise, __-1__ is returned and __errno__ is set to indicate the error.
<hr/>

<h2>read</h2>

```C
ssize_t read(int fd, void *buf, size_t count);
```

* read() attempts to read up to __count__ bytes from the file descriptor __fd__ into the buffer starting at __buf__.
* Header file : unistd.h
* Return value : On success, __the number of bytes read is returned(zero indicates EOF)__ , and the file position is advanced by its number. __It is not an error if this number is smaller than the number of bytes requested; this may happen for example because fewer bytes are  actually availiable right now__. On error, __-1__ is returned and __errno__ is set appropriately.
* It is better to check error with __ferror() and feof()__ .
<hr/>

<h2>ferror, feof</h2>

```C
int ferror(FILE *stream);
int feof(FILE *stream);
```

* ferror() tests the error indicator for the stream pointed to by __stream__, returning __nonzero if it is set__.
* feof() tests the EOF indicator for the stream pointed to by __stream__, returning __nonzero if it is set__.

<h2>write</h2>

```C
ssize_t write(int fd, const void *buf, size_t count);
```

* write() writes up to __count__ bytes from the buffer starting at __buf__ to the file referred to by the file descriptor __fd__.
* Header file : unistd.h
* Return value : On success, __the number of bytes written is returned(zero indicates nothing is written). It is not an error if this number is smaller than the number of bytes requested.__
<hr/>

<h2>open</h2>

```C
int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);
```

* The open() system call opens the file specified by __pathname__. If the specified file does not exist, it may optionally be created by open().
* Mostly used __flags__ types.
<table>
    <tr>
        <td>O_APPEND</td>
        <td>The file is opened in append mode.</td>
    </tr>
    <tr>
        <td>O_CREAT</td>
        <td>If pathname doesn't exist, create it as a regular file.</td>
    </tr>
    <tr>
        <td>O_TRUNC</td>
        <td>If the file already exists and is a regular file and the acess mode allows writing, it will be truncated to length 0.</td>
    </tr>
    <tr>
        <td>O_RDONLY</td>
        <td>Request opening of the file for read-only.</td>
    </tr>
    <tr>
        <td>O_WRONLY</td>
        <td>Request opening of the file for write-only.</td>
    </tr>
    <tr>
        <td>O_RDWR</td>
        <td>Request opening of the file for read/write.</td>
    </tr>
</table>

* __mode__ : Set the access of the file in hexa-decimal value.
```C
// example
int fd = open("./ex.txt", O_RDONLY | O_TRUNC | O_CREAT, 0644);
```
  * The example code above opens ex.txt file in __read only mode if it exists, and truncate it. If it doens't exist, if creates ex.txt file, and changes its mod to 644, which is rw-r--r--.__
* Header file : sys/types.h sys/stat.h fcntl.h
* Return value : open() returns the __new file descriptor, or -1 if an error occured__. __errno__ is set appropriately to indicate the error.
<hr/>
