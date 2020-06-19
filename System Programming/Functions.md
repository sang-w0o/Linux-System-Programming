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

<h2>getpwuid</h2>

```C
struct passwd *getpwuid(uid_t uid);
```

* getpwuid() returns a pointer to a structure containing the broken-out fields of the record in the password database that matches the user ID, __uid__.

* The __passwd__ structure is defined in __pwd.h__ as follows:
```C
struct passwd {
    char *pw_name;          //username
    char *pw_passwd;        //user password
    uid_t pw_uid;           // user ID
    git_t pw_gid            // group ID
    char *pw_gecos;         // user information
    char *pw_dir;           // home directory
    char *pw_shell;         // shell program
};
```

* Header file : sys/types.h pwd.h
* Return value : getpwuid() returns a __pointer to the passwd structure, or NULL if the matching entry is not found or an error occurs__.   
  If an error occurs, __errno__ is set appropriately.
<hr/>

<h2>getgrgid</h2>

```C
struct group *getgrgid(git_t gid);
```

* getgrgid() function returns a pointer to a sturcture containing the broken-out fields of the record in the group database that matches the group ID __gid__.
* The __group__ structure is defined in __grp.h__ as follows:
```C
struct group {
    char *gr_name;          // group name
    char *gr_passwd;        // group password
    gid_t gr_gid;           // groupd ID
    char **gr_mem;          // NULL-terminated array of pointers
                            // to names of group members
};
```
* Header file : sys/types.h grp.h
* Return value : getgrgid() function returns a __pointer to a group structure, or NULL if the matching entry is not found or an error occurs__.   
  If an error occurs, __errno__ is set appropriately.
<hr/>

<h2>readlink</h2>

```C
ssize_t readlink(const char *pathname, char *buf, size_t bufsiz);
```

* readlink() places the contents of the symbolic link __pathname__ in the buffer __buf__, which has size __bufsiz__.   
  readlink() __does not append a null byte to buf__.   
  It will silently truncate the contents (to a length of __bufsiz__ characters), in case the buffer is too small to hold all of the elements.
* Header file : unistd.h fcntl.h unistd.h
* Return value : On success, readlink() returns __the number of bytes placed in buf. (If the returned value equals bufsiz, then truncation may have occured).__ On error, __-1__ is returned and __errno__ is set to indicate the error.
<hr/>

<h2>chdir</h2>

```C
int chdir(const char *path);
```

* chdir() changes the current working directory of the calling process t the directory specified in __path__.
* Header file : unistd.h
* Return value : On success, __0__ is returned. On error, __-1__ is returned and __errno__ is set appropriately.
<hr/>

<h2>getcwd</h2>

```C
char *getcwd(char *buf, size_t size);
```

* getcwd() returns a __null-terminated string__ containing an absolute pathname that is the current working directory of the calling process.   
  The pathname is returned as the function result and via the argument __buf__, if present.
* getcwd() function copies an absolute pathname of the current working directory to the array pointed to by __buf__, which is of length __size__.
* If the length of the absolute pathname of the current working directory, including the terminating nul byte, exteeds __size__ bytes, __NULL__ is returned, and __errno__ is set to __ERANGE__.
* Header file : unistd.h
* Return value : On success, getcwd() returns a __pointer to a string containing the pathname of the curren working directory__.   
  On failure, it returns __NULL__, and __errno__ is set to indicate the error.
<hr/>

<h2>opendir</h2>

```C
DIR *opendir(const char *name);
```

* opendir() function opens a directory stream corresponding to the directory __name__, and returns __a pointer to the directory stream__.   
  __The stream is positioned at the first entry in the directory__.
* Header file : sys/types.h dirent.h
* Return value : opendir() returns __a pointer to the directory stream__. On error, __NULL__ is returned and __errno__ is set appropriately.
<hr/>

<h2>readdir</h2>

```C
struct dirent *readdir(DIR *dirp);
```

* readdir() function returns __a pointer to a dirent strucure representing the next directory entry in the directory stream pointed by dirp__. 
* The __dirent__ structure is defined as follows:
```C
struct dirent {
    int_t d_ino;                // Inode number
    off_t d_off;                // Not an offset; see below
    unsigned short d_reclen;    // Length of this record
    unsigned char d_type;       // Type of file : Not supported by all
                                // filesystem types.
    char d_name[256];           // Null-terminated filename
};
```
  * __d_off__ is the same as would be calling __telldir()__ at the current position in the directory system.
* Header file : dirent.h
* Return value : On success, readdir() returns __a pointer to a dirent structure__. If the end of the directory stream is reached, __NULL__ is returned and __errno is not changed__.   
  If an error occurs, __NULL__ is returned and __errno is set appropriately__.
<hr/>

<h2>closedir</h2>

```C
int closedir(DIR *dirp);
```

* closedir() function closes the directory stream associated with __dirp__. A successful call to closedir() __also closes the underlying file descriptor associated with dirp__.   
  The directory stream __dirp__ is not availiable after this call.
* Header file : sys/types.h dirent.h
* Return value : Upon success, closedir() returns __0__. On error, __-1__ is returned, and __errno__ is set appropriately.
<hr/>

<h2>rewinddir</h2>

```C
void rewinddir(DIR *dirp);
```

* rewinddir() function resets the position of the directory stream __dirp__ to the beginning of the directory.
* Header file : sys/types.h dirent.h
<hr/>

<h2>alarm</h2>

```C
unsigned int alarm(unsigned int seconds);
```

* alarm() arranges for __SIGALRM__ signal to be delivered to the calling process in __seconds__ seconds.
* Header file : unistd.h
* Return value : alarm() returns the __number of seconds remaining until any previously sheduled alarm was due to be delivered__, or __0__ if there was no previously scheduled alarm.
<hr/>

<h2>signal</h2>

```C
typedef void (*sighandler_t)(int);
sighandler_t signal(int signum, sighandler_t handler);
```

* signal() sets the disposition of the signal __signum__ to __handler__, which is either __SIG_IGN, SIG_DFL, or the address of a programmer-defined function__.
* Header file : signal.h
* Return value : signal() returns the __previous value of the signal handler__, or __SIG_ERR__ on error.   
  In the event of an error, __errno__ is set to indicate the cause.
<hr/>

<h2>sigprocmask</h2>

```C
int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);
```

* sigprocmask() is used to fetch and/or change the signal mask of the calling thread. The signal mask is the set of signals whose delivery is currently blocked for the caller.
* The behavior of the call is dependent on the value of __how__ as follows:

<table>
    <tr>
        <td>SIG_BLOCK</td>
        <td>The set of blocked signals is the union of the current set and set argument.</td>
    </tr>
    <tr>
        <td>SIG_UNBLOCK</td>
        <td>The signals in set are remove from the current set of blocked signals. It is permissible to attempt to unblock a signal which is not blocked.</td>
    </tr>
    <tr>
        <td>SIG_SETMASK</td>
        <td>The set of blocked signals is set to the argument set.</td>
    </tr>
</table>

* If __oldset__ is not NULL, previous signal set will be saved in __oldset__.
* If __set__ is NULL, it ignores __how__ and saves signal mask to __oldset__.
* Header file : signal.h
* Return value : sigprocmask() returns __0__ on success and __-1__ on error.   
  In the event of an error, __errno__ is set to indicate the cause.
<hr/>

<h2>sigemptyset</h2>

```C
int sigemptyset(sigset_t *set);
```

* sigemptyset() initializes the signal set given by __set__ to empty, with all signals excluded from the set.
* Header file : signal.h
* Return value : 
<hr/>

<h2>sigaddset</h2>

```C
int sigaddset(sigset_t *set, int signum);
```

* sigaddset() add respectively signal __signum__ from __set__.
* Header file : signal.h
* Return value : sigaddset() returns __0__ on success, and __-1__ on error. On error, __errno__ is set to indicate the cause of the error.
<hr/>

<h2>sigismember</h2>

```C
int sigismember(const sigset_t *set, int signum);
```

* sigismember() tests whether __signum__ is a member of __set__.
* Header file : signal.h
* Return value : sigismember() returns __1__ if __signum__ is a member of __set__, __0__ if __signum__ is not a member, and __-1__ on error.   
  On error, __errno__ is set to indicate the cause of the error.
<hr/>

<h2>sigpending</h2>

```C
int sigpending(sigset_t *set)
```

* sigpending() returns the set of signals that are pending for delivery to the calling thread.   
  The mask of pending signals is returned in __set__.
* Header file : signal.h
* Return value : sigpending() returns __0__ on success and __-1__ on error. In the event of an error, __errno__ is set to indicate the cause.
<hr/>
