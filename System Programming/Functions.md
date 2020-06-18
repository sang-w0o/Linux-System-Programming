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

* fseek() sets the __file position indicator__ for the stream pointed by __stream__. The new position, measured in bytes, is obtained by __adding offset bytes__ to the position specified by __whence__. If whence is set to __SEEK_SET, SEEK_CUR, SEEK_END__ , the offset is relative to the __start of the file, the current position indicator, or EOF__.
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
        <td>If the file already exists and is a regular file and the access mode allows writing, it will be truncated to length 0.</td>
    </tr>
    <tr>   
        <td>O_EXCL</td>
        <td>Encure that this call creates the file : If this flag s specified in conjunction with O_CREAT, and pathname already exists, then open() fails with the error EEXIST.</td>
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
* Mostly used __mode__ symbolic constants.
<table>
    <tr>
        <td>S_IRWXU</td>
        <Td>00700, user(File owner) has rwx permission.</td>
    </tr>
    <tr>
        <td>S_IRUSR</td>
        <Td>00400, user has r-- permission.</td>
    </tr>
    <tr>
        <td>S_IWUSR</td>
        <Td>00200, user has -w- permission.</td>
    </tr>
    <tr>
        <td>S_IXUSR</td>
        <Td>00100, user has --x permission.</td>
    </tr>
</table>

* U(USR) : User, G(GRP) : Group, O(OTH) : Others

```C
// example
int fd = open("./ex.txt", O_RDONLY | O_TRUNC | O_CREAT, 0644);
int fd = open("./ex.txt", O_RDONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
```
  * The example code above opens ex.txt file in __read only mode if it exists, and truncate it. If it doens't exist, if creates ex.txt file, and changes its mod to 644, which is rw-r--r--.__
* Header file : sys/types.h sys/stat.h fcntl.h
* Return value : open() returns the __new file descriptor, or -1 if an error occured__. __errno__ is set appropriately to indicate the error.
<hr/>

<h2>close</h2>

```C
int close(int fd);
```

* close() closes a file descriptor, so that it no longer refers to any file and may be resued.
* Header file : unistd.h
* Return value : close() returns __0 on success. On error, -1 is returned__, and __errno__ is set appropriately.
<hr/>

<h2>lseek</h2>

```C
off_t lseek(int fd, off_t offset, int whence);
```

* lseek() repositions the file offset of the open file description associated with the file descriptor __fd__ to the argument __offset__ according to the directive __whence__ as following table.

<table>
    <tr>
        <td>SEEK_SET</td>
        <td>The file offset is set to offset bytes.</td>
    </tr>
    <tr>
        <td>SEEK_CUR</td>
        <td>The file offset is set to its current location plus offset bytes.</td>
    </tr>
    <tr>
        <td>SEEK_END</td>
        <td>The file offset is set to the size of the file plus offset bytes.</td>
    </tr>
</table>

* leek() allows the file offset to be set beyond the EOF. __(but doesn't change the size of the file)__ 
* Header file : sys/types.h unistd.h
* Return value : Upon successful completion, lseek() returns __the resulting offset location as measured in bytes from the beginning of the file__. On error, the value __(off_t)-1__ is returned and __errno__ is set to indicate the error.
<hr/>

<h2>dup</h2>

```C
int dup(int oldfd);
```

* dup() syscall creates a copy of the file descriptor __oldfd__, using the lowest-numbered unused file descriptor for the new descriptor.
* Header file : unistd.h
* Return value : On success, dup() returns the __new file descriptor__. On error, __-1__ is returned, and __errno__ is set to indicate the error.
<hr/>

<h2>dup2</h2>

```C
int dup2(int oldfd, int newfd);
```

* dup2() syscall performs the same task as __dup()__, but instead of using the lowest-numbered unused file descriptor, it __uses the file descriptor number specified in newfd__. If the file descriptor __newfd__ was previously open, it is silently closed before being used.
* Header file : unistd.h
* Return value : On success, dup() returns the __new file descriptor__. On error, __-1__ is returned, and __errno__ is set to indicate the error.
<hr/>

<h2>unlink</h2>

```C
int unlink(const char *pathname);
```

* unlink() deletes a name from the filesystem. If that name was the __last link to a file and no processes have the file open, the file is deleted__ and the space it was usng is made availiable for reuse. If the name was the last link to a file __but any processes still have the file open, the file will remain in existance until the last file descriptor referring to it is closed__. If the name referred to a symbolic link, the link is removed. If the name referred to a socket, FIFO, or device, the name for it is removed __but processes which have the object open may continue to use it__.
* Header file : unistd.h
* Return value : On success, __0__ is returned. On error, __-1__ is returned and __errno__ is set appropriately.
<hr/>

<h2>mmap</h2>

```C
void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
```

* mmap() creates a new mapping in the virtual address space of the calling process. The starting address for the new mapping is specified in __addr__. The __length__ argument specifies the length of the mapping __(must be greater than 0)__.   
  If __addr__ is NULL, then the kernel chooses the address at which to create the mapping. If __addr__ is not NULL, then the kernel takes it as a __hint about where to place the mapping. The address of the new mapping is returned as a result of the call__.   
  The contents of a file mapping are initialized using __length__ bytes starting at offset __offset__ in the file referred to by the file descriptor __fd__.   
  The __prot__ argument describes the desired memory protection of the mapping and __must not conflict with the open mode of the file__.   
  The __flags__ argument determines whether updates to the mapping are visible to other proceses mapping the same region, and whether updates are carried through the underlying file.

* Mostly used __prot__ types.
  * PROT_READ : For read-only.
  * PROT_WRITE : For write-only.
* Mostly used __flags__ types.
  * MAP_PRIVATE : Specified process can access.
  * MAP_SHARED : Share with all processes.

* Header file : sys/mman.h
* Return value : On success, mmap() returns a __pointer to the mapped area__. On error, the value __MAP_FAILED(which is (void *)-1)__ is returned and __errno__ is set appropriately.
<hr/>

<h2>munmap</h2>

```C
int munmap(void *addr, size_t length);
```

* munmap() syscall deletes the mappings for the specified address range, and causes further references to adresses within the range to generate invalid memory references.   
  The address __addr__ must be a multiple of the page size(but __length__ need not be). It is not an error if the indicated range does not contain any mapped pages.
* Header file : sys/mman.h
* Return value : On success, munmap() returns __0__. On failure, it returns __-1__, and __errno__ is set to indicate the cause of the error.
<hr/>

<h2>lstat</h2>

```C
int lstat(const char *pathname, struct stat *statbuf);
```
* lstat() retrieves information about the file pointed to by __pathname. If __pathname__ is a symbolic link, then it returns information about the link itself, not the file that it refers to__.
* The stat structure
  * lstart() syscall returns a __stat__ structure, which contains the following fields.
  ```C
  struct stat {
      ino_t st_ino;         // Inode number
      mode_t st_mode;       // File type and mode
      nlink_t st_nlink;     // Number of hard links
      uid_t st_uid;         // User ID of owner
      git_t st_gid;         // Group ID of owner
      off_t st_size;        // Total size, in bytes
  };
  ```
* Header file : sys/types.h sys/stat.h unistd.h
* Return value : On success, __0__ is returned. On error, __-1__ is returned, and __errno__ is set appropriately.
<hr/>
