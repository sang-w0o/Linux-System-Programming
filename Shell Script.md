Linux Shell Script
======

<h2>#1. VIM 설치</h2>

* apt install vim
* 위는 권한이 없다고 출력되며 실패한다.
* apt를 통해 설치하는 것은 인증된 사용자만 가능하도록 되어있다.
* 따라서 앞에 sudo 접두어를 붙여준다.
* __sudo apt install vim__ 
<hr/>

<h2>#2. VIM 편집기의 실행</h2>

* vi fileName 또는 vim fileName 
  * 정식은 vim 명령어 이지만, vim을 설치하면 vi가 vim으로 aliasing된다.
<hr/>

<h2>#3. VI의 모드(mode) 및 단축키</h2>

* vi에는 3가지 모드가 있다.
  * command(명령 모드)
  * edit(편집 모드)
  * ex(ex 모드)

* command와 edit모드 사이의 전환과 command와 ex모드 사이의 전환은 가능하지만,   
  ex모드에서 edit모드로의 전환은 불가하다.

* 편집 모드에서 명령모드로의 진입은 esc 키 이다.

* 명령 모드에서의 단축키
<table>
    <tr>
        <td>h</td>
        <td>커서 왼쪽으로 한 칸 이동</td>
    </tr>
    <tr>
        <td>j</td>
        <td>커서 아래로 한 칸 이동</td>
    </tr>
    <tr>
        <td>k</td>
        <td>커서 위로 한 칸 이동</td>
    </tr>
    <tr>
        <td>l</td>
        <td>커서 오른쪽으로 이동</td>
    </tr>
    <tr>
        <td>^</td>
        <td>행의 맨 앞으로 이동(단, 공백 제외)</td>
    </tr>
    <tr>
        <td>$</td>
        <td>행의 맨 뒤로 이동</td>
    </tr>
    <tr>
        <td>gg</td>
        <td>문서의 처음으로 이동</td>
    </tr>
    <tr>
        <td>G</td>
        <td>문서의 마지막으로 이동</td>
    </tr>
    <tr>
        <td>W, w(word)</td>
        <td>단어 단위로 다음으로 이동</td>
    </tr>
    <tr>
        <td>B, b(backward)</td>
        <td>단어 단위로 앞으로 이동</td>
    </tr>
    <tr>
        <td>i (insert)</td>
        <td>현재 커서 위치에서 입력 모드로 변경</td>
    </tr>
    <tr>
        <td>I (Insert)</td>
        <td>현재 커서가 있는 행의 처음으로 이동 후 입력모드로 변경</td>
    </tr>
    <tr>
        <td>a (append)</td>
        <td>현재 커서 위치에서 우측으로 한 칸 이동 후 입력모드로 변경</td>
    </tr>
    <tr>
        <td>A (Append)</td>
        <td>현재 커서가 있는 행의 가장 우측으로 이동 후 입력모드로 변경</td>
    </tr>
    <tr>
        <td>o</td>
        <td>커서 아래에 새로운 행 추가 후 입력모드로 변경</td>
    </tr>
    <tr>
        <td>O</td>
        <td>커서에 새로운 행 추가(뒤의 문장들은 1줄씩 밀려난다.)</td>
    </tr>
    <tr>
        <td>x</td>
        <td>현재 커서의 문자 1개 삭제(단, 개행은 삭제 불가)</td>
    </tr>
    <tr>
        <td>dd</td>
        <td>현재 커서의 행 삭제</td>
    </tr>
    <tr>
        <td>n + dd</td>
        <td>현재 커서부터 n개의 행 삭제</td>
    </tr>
    <tr>
        <td>D</td>
        <td>현재 커서부터 행의 끝까지 삭제</td>
    </tr>
    <tr>
        <td>J</td>
        <td>현재 커서가 위치한 행의 개행문자 삭제(단, 아래 행의 개행도 삭제됨)</td>
    </tr>
    <tr>
        <td>yy, Y</td>
        <td>현재 행을 복사</td>
    </tr>
    <tr>
        <td>n + yy</td>
        <td>현재 커서부터 n개의 행 복사</td>
    </tr>
    <tr>
        <td>p</td>
        <td>현재 행애 붙여넣기(개행이 포함된 경우는 바로 아래에 복사됨)</td>
    </tr>
    <tr>
        <td>u(undo)</td>
        <td>실행 취소</td>
    <tr>
    <tr>
        <td>ctrl + r(redo)</td>
        <td>앞으로</td>
    </tr>
    <tr>
        <td>v(visual)</td>
        <td>문자 단위로 블럭 지정</td>
    </tr>
    <tr>
        <td>V(Visual)</td>
        <td>행 단위로 블럭 지정</td>
    </tr>
    <tr>
        <td>ctrl + v</td>
        <td>열 단위로 블럭 지정</td>
    </tr>
    <tr>
        <td>ctrl + b(backward)</td>
        <td>한 화면 위로 이동</td>
    </tr>
    <tr>
        <td>ctrl + f(forward)</td>
        <td>한 화면 아래로 이동</td>
    </tr>
    <tr>
        <td>ctrl + u(up)</td>
        <td>한 화면의 반만 위로 이동</td>
    </tr>
    <tr>
        <td>ctrl + d(down)</td>
        <td>한 화면의 반만 아래로 이동</td>
    </tr>
<table>

* dd, D, x는 삭제라 아니라 잘라내기 이다.
* VI에서는 잘라내기 후 이를 사용하지 않으면, 삭제했다고 본다.

* 블럭 지정 후 ~ 를 누르면 대소문자가 변경된다.

* EX 모드의 명령어 (!는 강제성을 띈다.)
<table>
    <tr>
        <td>:w, :write [fileName]</td>
        <td>저장</td>
    </tr>
    <tr>
        <td>:w! fileName</td>
        <td>기존에 fileName이 존재할 경우, 덮어씀</td>
    </tr>
    <tr>
        <td>:q, :quit</td>
        <td>종료</td>
    </tr>
    <tr>
        <td>:q!</td>
        <td>저장하지 않고 강제 종료</td>
    </tr>
    <tr>
        <td>:wq</td>
        <td>저장과 종료를 동시에 수행</td>
    </tr>
    <tr>
        <td>[범위]s/oldWord/newWord/[option]</td>
        <td>범위에 해당하는 oldWord를 newWord로 치환</td>
    </tr>
    <tr>
        <td>:set nu</td>
        <td>라인 넘버 출력</td>
    </tr>
    <tr>
        <td>:set autoindent</td>
        <td>들여쓰기 기능 켜기</td>
    </tr>
    <tr>
        <td>:set cindent</td>
        <td>C 스타일로 들여쓰기 기능 켜기</td>
    </tr>
</table>

  * 치환의 s 앞의 인자는 범위로, s가 4,15s 이면 4번 부터 15번 행까지 치환한다는 뜻이다.
    * 또한 4,15s는 4,+11s와 같은 의미이다.
    * 문서 전체를 범위로 지정할 때에는 %s 를 주면 된다.
  * 치환의 옵션
    * g 옵션 : 범위 발견된 모든 oldWord를 newWord로 치환한다.
      * (default는 행 단위로 처음 발견된 oldWord만 치환한다.)

  * 윈도우 모드 (명령 모드에서 진입)
    * 윈도우 모드 진입 시에는 ctrl+w를 필수적으로 접두어로 붙인다.
    * 수평분할 : ctrl + w + s(split) 또는 :sp[파일명]
    * 수직분할 : ctrl + w + v(vertical) 또는 :vs[파일명]
    * 창 이동 : ctrl + w + hjkl(좌,하,상,우) 이동
    * 창 닫기 : ctrl + w + c(close)
    * :e fileName : 다른 파이를 연다기
<hr/>

<h2>#4. vim의 환경 설정 파일</h2>

* vim은 환경 설정 파일을 제공한다.
  * 위치 : ~/.vimrc
```sh
set cin
"~/.vimrc file"

set cin
"== set cindent"

set sw=4
"== set shiftwidth=4"

set ts=4
"== set tabstop=4"

set nu
"== set number"
```
<hr/>

<h2>#5. VI에서 도움말 확인 방법</h2>

* 보고자 하는 명령어의 토큰에 커서를 위치시킨 후, __섹션번호 + K__ 를 누르면 된다.
  * 명령어의 경우 섹션번호 없이 __K__ 만 눌러도 된다.
<hr/>

<h2>#6. 권한</h2>

* __-rw-r--r--__ 와 같이 생긴 것을 __권한__ 이라 한다.
* 권한은 총 10자리로, 앞 1자리, 뒤 3자리 3자리 3자리로, 구분된다.
* 첫번째 3자리 : 소유자의 권한
* 두번째 3자리 : 그룹의 권한
* 세번째 3자리 : 나머지 권한
* 맨 앞 1자리 : d(directory), -(file)
* 각 3자리는 __rwx__ 로, 각 단어는 다음의 권한을 의미한다.
  * r : read (읽기 권한)
  * w : write (쓰기 권한)
  * x : execute (실행 권한)
  * __-__ : 권한 없음

* 권한 간단 정리
<table>
    <tr>
        <td>권한</td>
        <td>File</td>
        <td>Directory</td>
    </tr>
    <tr>
        <td>r</td>
        <td>파일 읽기 허용</td>
        <td>Directory의 내용 읽기 가능(ls 가능)</td>
    </tr>
    <tr>
        <td>w</td>
        <td>파일 쓰기(수정) 허용</td>
        <td>Directory내에 파일 생성, 삭제 및 이름변경 가능</td>
    </tr>
    <tr>
        <td>x</td>
        <td>파일 실행</td>
        <td>Directory 안으로 진입 허용(cd 가능)</td>
    </tr>
</table>

* 파일의 권한 변경 : chmod 명령어 사용
  * chmod는 관리자(root)와 파일 소유자만 사용할 수 있다.
  * (1) 8진법을 사용하여 권한 변경
    * __-rw-rw-r--__ 를 3자리 씩 자른다.
      * __rw-__  __rw-__  __r--__   
          110      110      100   
          6(10)    6(10)    4(10)
    * 사용법 : chmod 권한(정수) 파일명
      * ex) 위를 r--r--r--로 바꾸고 싶다면 chmod 444 fileName이 된다.
    * 8진법 사용의 장점 : 다수의 권한을 한번에 설정 가능
    * 8진법 사용의 단점 : 일부 권한만 따로 설정할 수 없다.

  * (2) 문자를 사용하여 권한 변경

    * 카테고리
    <table>
        <tr>
            <td>u</td>
            <td>User(파일 소유자)</td>
        </tr>
        <tr>
            <td>g</td>
            <td>Group(소유자가 속한 그룹)</td>
        </tr>
        <tr>
            <td>o</td>
            <td>Other(이외의 나머지)</td>
        </tr>
        <tr>
            <td>a</td>
            <td>All(전체 사용자)</td>
        </tr>
    </table>

    * 연산자 기호
    <table>
        <tr>
            <td>+</td>
            <td>권한 추가</td>
        </tr>
        <tr>
            <td>-</td>
            <td>권한 삭제</td>
        </tr>
        <tr>
            <td>=</td>
            <td>권한 설정</td>
        </tr>
    </table>

    * 사용법 : chmod 카테고리+권한
      * ex) chmod u+x --> 소유자에게 실행 권한 부여
      * ex) chmod u-w --> 소유자에게 쓰기 권한 제거
      * ex) chmod g+w --> 그룹에게 쓰기 권한 부여
      * ex) chmod g+rw --> 그룹에게 읽기/쓰기 권한 부여
      * ex) chmod o-rx --> 나머지 사람들에게 쓰기/실행 권한 제거
      * ex) chmod ug-x --> 소유자와 그룹의 실행 권한 제거
      * ex) chmod +x --> 모든 사용자에게 실행 권한 부여
      * ex) chmod u=rwx --> 소유자에게 읽기/쓰기/실행 권한 부여
      * ex) chmod u+x, go-x --> 소유자에게 실행 권한 부여, 그룹과   
        나머지 사용자에게서는 실행 권한 제거

    * 문자 사용의 장점 : 특정 속성만 수정 가능 및 높은 가독성
    * 단점 : 수정할 속성이 많을 경우, 상대적으로 복잡하다.   
    
* 파일 및 디렉토리 생성시의 기본 권한 값
  * umask : Linux에서 파일 생성 시, 주어진 기본 permission을 제어하기 위한 명령어
  * umask 실행 시 값은 4자리로 출력된다.

  * Linux에서 파일을 생성하면, 기본적으로 모든 권한이 1로 설정된다.
    * __111 111 111__ (rwx rwx rwx)
    * __000 000 010__ (umask 값)
    * 위 2개를 연산한다. (0을 만나면 무조건 0이 됨)
    * __111 111 101__ (rwx rwx r-x)
    * __110 110 110__ (보안 상의 이유로 일반 파일은 실행 권한을 모두 뺀다.)
    * __110 110 100__ (rw- rw- r--)
    * 위는 umask가 0002일 때, 파일 생성 시 기본 권한이 644가 되는 과정이다.

* Super User(root)
  * root 계정을 활성화하는 방법
    * 일반적으로 관리자의 id는 root로 고정되어 있다.
    * 비밀번호 설정하기 : __sudo passwd root__
  
  * root로의 로그인 방법
    * (1) su[-[l]][userID]
      * su : substitute user로, 현재 사용자를 로그아웃하지 않고 다른 사용자   
        계정으로 로그인하는 명령어
      * 암묵적으로 su 명령 사용 시 user는 root로 설정된다.
      * -l, - 옵션 : 새로운 사용자의 환경을 로드하고, 작업 dir를 해당   
        사용자의 홈 dir로 이동하라는 의미.
      * root로 로그인 시, 명령행이 $가 아닌 #으로 끝난다.
 
    * (2) sudo명령어 : su + do로, root의 권한을 잠시 빌려 특정 작업을 수행한다.
      * su명령어는 반드시 root의 비밀번호를 알아야 사용 가능하지만, sudo는   
        일반 계정 사용자에 대해서도 명령을 수행할 수 있다.
<hr/>

<h2>#7. 프로세스</h2>

* 프로그램 : 일반적으로 영구적인 저장장치에 저장된 실행 코드를.
* 프로세스 : 로더에 의해 프로그램이 주기억장치(RAM)에 로드되어 실행되고 있는 것.
  * 프로그램은 1개이지만, 하나의 프로그램을 여러 번 구동하면 프로세스는   
    1개 이상이 될 수 있다.

* 프로세스의 확인
  * (1) ps -af 명령어 (PID 확인 및 실행중인 프로세스 확인)
    * TIME : 각 프로세스가 CPU를 사용한 시간
  * (2) top 명령어 : CPU를 점유하는 프로세스를 내림차순으로 출력한다
    * q : 종료
    * R : 정렬 순서 변경
    * 1 : 전체 CPU 및 각 CPU별로 사용량 확인

* OS는 다수의 프로세스를 구분하기 위해 고유한 번호를 구문하는데, 이를   
  PID(Proccess ID)라 한다.

* 프로세스의 종료
  * C에서 main함수 작성 시, 다음과 같이 한다.
  ```C
  int main(){
      //...
      return 0;
  }
  ```
  * 위의 __return 0__ 은 종료 코드를 의미한다.
  * return된 0은 OS가 확인하는 것이 아니라, 프로세스가 정상적으로 종료했는지의   
    유무를 확인하기 위하여 사용된다.
  * C에서 프로그램의 실행은 main이 아니라, 이전에 Linker에 의해 start-up   
    code가 생성된다. 그 후 main이 실행되는 것이다.
  * __return 0;__ 은 exit(0)과 같고, 이는 원래 __exit(main())__ 이다.

  * 가장 최근에 종료된 Process의 종료값은 __?__ 에 들어가는데, ?의 값은   
    프로세스의 __exit(code)__ 의 code가 들어간다.
    * 확인법 : __echo $?__
  
  * ?는 환경변수로, 프로세스가 정상 종료되었는지 확인하려면 ?의 값을 위처럼 읽어오면 된다.

  * 종료 코드를 설정하는 명령어 : exit [code]
    * exit를 실행한 프로세스를 종료하면서 ?에 code를 설정한다.

  * Linux는 종료 상태값을 저장하기 위해 부호 비트 없이 8bit를 사용한다.   
    따라서 종료 코드의 값은 음수를 가질 수 없으며 0~255 사이의 값으로 한정된다.   
    __만약 범위를 벗어난 값으로 설정될 경우, 이는 미정의 동작이다.__
  * 또한, 0~127번은 특정한 의미가 지정되어 있는 종료코드이다.   
    128번 이후 부터는 받은 시그널값이 더해져서 들어간다.(?)
<hr/>

<h2>#8. 시그널(Signal)</h2>

* 시그널 : 서로 다른 프로세스 사이의 통신을 위한 메커니즘

* 시그널의 종류 확인 : __kill -l__ (1번~31번, 총 31개)

* 시그널을 받았을 때 프로세스의 기본적인 동작은 종료되는 것이다.

* ls -R / 명령이 수행중일 때 ctrl+c를 누르면 프로세스를 종료시킨다.   
  그 후 __echo $?__ 를 하면 __130__ 이 출력된다.   
  Ctrl + C는 interrupt로, 2(SIGINT)를 보낸 것이다.   
  따라서 128 + 2를 한 130이 출력된 것이다.


<h2>#9. Script란</h2>

* Bash 프로그램이 실행하기 위해 나열한 명령어들의 모음