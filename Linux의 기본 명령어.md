Shell
======

<h2>Shell 이란</h2>
<hr/>

* (1) 키보드로부터 입력 받은 명령어를 OS(커널)에게 전달하여 해당 명령을 실행하게 하는 프로그램
* (2) 쉘의 사전적 의미는 껍데기고, 이는 사용자와 OS(커널) 내부 사이의 인터페이스를 감싸고 있기 때문이다.
* (3) 쉘 인터페이스
  * (1) CLI(Command-Line Interface) or CUI(Character-based User Interface)   
    --> 문자 기반 또는 명령어 기반 인터페이스
  * (2) GUI(Graphic User Interface) : 그래픽을 사용한 인터페이스

<hr/>
<h2>대표적인 쉘의 종류</h2>

1. Bourne Shell
2. Bash(Bourn-Again Shell) => 리눅스 표준에서 사용하는 쉘
3. 그 이외에 다양한 쉘들이 존재한다.

* 이번에 다루는 것은 Bash 이다.
<hr/>

<h2>프롬프트(Prompt)</h2>

* 쉘 프롬프트 : 사용자로부터 입력을 대기하기 위해 출력하는 일종의 문자열
* 시스템마다 출력 형식이 다르다.
* 우분투의 출력 형식은 다음과 같다. __username@ubuntu:~$__
  * __사용자명@호스트명 : (작업중인)디렉토리경로명$
<hr/>

<h2>명령어(Command)</h2>

* 명령어 : 일반적으로 실행 가능한 프로그램
* 명령어의 입력 형식
  * 공백 또는 탭으로 구분되는 하나 이상의 단어로 시작하여 개행 문자로 끝난다.
  * 쉘은 입력 받은 명령어를 단어 또는 토큰 단위로 쪼개어 해석한다.

* 기본적인 명령어의 예시
  * date : 시스템의 현재 날짜 및 시각 출력
  * cal : 간단한 달력 출력 (현재 날짜의 달)
  * ls : 현재 directory내의 파일 목록 출력
    * -a 옵션 : 숨겨진 파일까지 모두 출력
    * -l 옵션 : 권한 목록까지 출력
      * 둘 다 출력하고 싶으면 -al 옵션을 주면 된다. ( -a + -l)
    * -d 옵션 : 인수로 지정한 directory 자체의 정보 출력
      * -ld로 주로 사용한다.
    * -R 옵션 : 인수로 지정한 directory부터 최하위 directory까지의 정보를 각각 모두 출력한다.
    * -F 옵션 : 각 심볼이 directory면 끝에 /를 붙여준다. 또한, 파일일 경우 실행 가능한 파일이면 뒤에 *를 붙여준다.
    * -r 옵션 : 기존 ls의 결과를 역순으로 출력한다.
  * uname : 시스템의 종류 출력
    * -v 옵션 : 버전 및 배포날짜 출력
    * -p 옵션 : 프로세서 정보 출력
  * id : 로그인한 사용자의 정보 출력 (uid=1000(로그인 계정명))
  * cat : 인자로 전달된 파일의 내용을 출력한다.
    * 사용법 : cat [filename]
    * filename에 들어온 인수의 파일 내용을 화면으로 출력한다.
    * filename인수가 없다면 표준 입력으로부터 들어온 데이터를 화면에 출력한다.
    * -n 옵션 : Line Number를 출력한다.
    * -b 옵션 : 비어있지 않은 행에 대해서만 Line Number값을 매겨 출력한다.
    * cat의 연산자 옵션
      * __<__ : 내용 보기 (사용법 : cat < [filename]) 
        * < 연산자는 생략 가능하다.
      * __>__ : 새로운 파일을 기존 파일의 내용으로 생성 후 저장
        * 사용법 : cat [originFile] > [newFile]
      * __>>__ : 내용 추가
        * 사용법 : cat [fileToAdd] >> [resultFile]
        * ex) a에 1,2,3,4,5가 있고, e에 10,11,12가 있다고 하자.
        * cat a >> e를 하면 e가 10,11,12,1,2,3,4,5가 된다.
      * __>__ : 파일 병합
        * 사용법 : cat [1stFile] [2ndFile] > [newFile]
        * ex) a에 1,2,3,4,5가 있고 b에 6,7,8,9가 있다고 하자.
        * cat a b > c : c가 1,2,3,4,5,6,7,8,9가 된다.
        * cat b a > c : c가 6,7,8,9,1,2,3,4,5가 된다.
    * 단점 : 화면 출력을 제어할 수 없다. (긴 파일 읽을 시 불편함)
  * more : 파일의 내용을 출력하며, 화면 출력을 제어할 수 있다.
    * 사용법 : more [filename]
    * 단축 키
      * Space, f(Forward) : 다음 페이지로 이동
      * b(Backword) : 이전 페이지로 이동
      * = : 현재 줄 번호 표시
      * d : 다음 페이지의 절반만 이동
      * q : 종료
      * enter : 한 줄 아래로 이동
  * less : more를 발전시킨 명령어
    * 사용법 : less [filename]
    * 단축키 : more이 가진 단축키에 추가로 더 제공.
      * more에서는 안되는 방향키의 사용이 가능하다.
      * PageDown : 이전 페이지로 이동
      * PageUp : 다음 페이지로 이동
      * /word : word가 위치한 줄로 이동
      * j : 한 줄 아래로 이동
      * k : 한 줄 위로 이동
      * g : 문서의 처음으로 이동
      * G : 문서의 마지막으로 이동
      * nG : 문서의 n번째 줄로 이동
  * head, tail : 파일의 일부 내용 출력
    * 사용법 : head -n [filename], tail -n [filename]
    * -n 옵션 : n 뒤에는 숫자가 들어가는데, 숫자만큼의 라인을 출력한다.
    * head : 파일 내용의 처음부터 지정한 숫자만큼의 줄 출력
    * tail : 파일 내용의 끝부터 역순으로 지정한 숫자만큼의 줄 출력
  * pwd : 현재 위치한 디렉토리를 출력한다.
  * echo tokens : tokens를 표준 출력으로 전송한다.
    * C언어의 printf, puts함수와 같은 개념이다.
  * cd 경로 : 경로에 표기된 위치로 이동한다.
    * 경로에 ~ 를 입력하면, 사용자의 home directory로 이동한다.
    * 경로를 지정하지 않으면 사용자의 home directory로 이동한다.
    * 경로에 - 를 입력하면, 이동하기 직전의 위치로 이동한다.
      * 주의 : 이동한 위치들의 히스토리가 저장되지 않는다.
  * alias : 복잡한 명령어에 별칭을 붙여준다.
    * 사용법 : alias newname='origincmd'
    * alias만 수행하면, 지정된 별칭들과 원본 명령의 쌍이 출력된다.
    * 주의 : alias된 것은 재부팅 시 사라진다.
    * 별칭 삭제 방법 : unalias newname
  * man : 명령어에 대한 도움말을 출력한다.
    * 사용법 : man command
<hr/>

<h2>명령행</h2>

* 명령행 : 명령어가 입력된 행
* 명령행의 구성요소
  * (1) 명령어
  * (2) 옵션 : - 또는 --로 시작하는 문자 또는 문자열
    * 모든 명령어가 -또는 --로 시작하는 옵션을 지원하지는 않는다.
    * 일반적으로 -옵션을 제공하며, 일부만 추가적으로 --옵션을 지원한다.
  * (3) 인자 : -나 --없이 사용되는 독립적인 단어 또는 토큰
    * 인자는 주로 파일명, 경로명, 사용자명 등이 쓰인다.
    * 예시 : cat 파일명 (cat examples.desktop)
  * 옵션이 인자를 가지는 경우도 있다.
    * 일반적인 명령행의 형태 : __명령어__ __인자__ __옵션__
    * 옵션이 인자를 가지는 경우 : __명령어__ __--옵션__ __옵션인자__

* 여러 행의 명령행을 작성하는 방법 : 한 행의 끝에 \ 를 입력한다.
  * 예시 : echo hello, \  (다음줄) world
<hr/>

<h2>명령어의 자동 완성</h2>

* 대부분의 쉘 프로그램은 명령어의 자동 완성을 지원한다.
* 사용 방법 : 명령어 또는 인자의 일부 입력 후 tab키 입력
  * 여러 경우가 존재할 경우 tab을 여러 번 치면 된다.
<hr/>

<h2>히스토리 기능</h2>

* 이전에 입력한 명령어를 다시 실행하기 위해 사용하는 기능
* 사용 방법 : history 입력 시, 기존에 입력한 모든 명령어가 출력된다.
* history [n] : 최근에 입력한 n개의 명령어만 출력된다.
* 또한 history에서 특정 명령어의 index를 실행하려면 __!index__ 또는 __!!index__ 를 입력하면 된다.
<hr/> 

<h2>파일 시스템(File System)</h2>

* 파일 시스템 : 컴퓨터에서 파일이나 자료를 쉽게 발견 및 접근할 수 있도록 보관, 조직하는 체계
* __/__ 는 root 라고 한다.
* 리눅스는 파일 시스템을 계층적인 directory 구조로 구성했다.
* 트리 형식으로 directory를 구성하고, 각 directory는 하위에 파일 또는 다른 directory를 포함할 수 있다.
* 이 때, 파일 시스템의 최상위 directory를 __root__ 라 한다.
* 또한 directory들끼리의 구분을 위해 슬래시(/)를 사용한다.
<hr/>

<h2>Home Directory</h2>

* 사용자가 로그인하면, 자신만의 고유한 directory로 이동하는데, 이를 __home directory__ 라 한다.
* 일반적으로 home directory는 __/home/사용자명__ 으로 지정된다.
<hr/>

<h2>경로(Path)</h2>

* 경로 : 파일 시스템 상에서 특정 directory까지의 이동 경로
* (1) 절대 경로 : /(루트) directory로부터 특정 directory 또는 파일까지의 경로
  * directory끼리 구분하기 위해 /를 사용한다.
* (2) 상대 경로 : 현재 작업 디렉토리(Current Working Directory)로, 로그인한 사용자의 현재 위치
  * __.__ : 현재 위치
  * __..__ : 현재 위치보다 한 단계 부모 directory로 이동
<hr/>

<h2>제어키</h2>

* 제어키 : 터미널 창에서 CTRL과 함께 사용되는 키
  * (1) Ctrl + C : Interrupt 발생
    * 대부분의 프로세스는 Interrupt를 받으면 종료된다.
  * (2) Ctrl + D : EOF 표시
    * cat같은 명령어는 EOF를 만나면 정상 종료되므로, 이러한 경우에 사용한다.
    * bash도 표준 입력으로부터 데이터를 받기 때문에 EOF를 전송하면 종료된다.
  * (3) Ctrl + \ : 현재 명령어를 중지(quit) 시킨다.
  * (4) Ctrl + s : 현재 명령어를 일시 정지(stop) 시킨다.
  * (5) Ctrl + q : stop된 명령어를 계속 실행(start) 시킨다.
  * (6) Ctrl + ? : delete와 같이 커서 다음 문자를 하나 씩 지운다.
  * (7) Ctrl + u : 전체 명령행을 모두 삭제한다.
  * (8) Ctrl + z : 현재 명령어로 실행된 프로그램을 잠시 일시 중지시킨다.
    * fg 명령어를 입력하여 일시 중지된 프로그램을 다시 구동한다.
<hr/>

<h2>단축키</h2>

* 단축키는 현재 명령행을 쉽게 편집하기 위해 bash에서 제공한다.
* Ctrl + e : end로, 커서를 명령행의 맨 뒤로 이동
* Ctrl + a : ahead로, 커서를 명령행의 맨 앞으로 이동
* Ctrl + f : forward로, 커서를 다음 칸으로 이동
* Ctrl + b : backward로, 커서를 한 칸 앞으로 이동
* Alt + f : 단어 단위로 커서를 한 단어 다음으로 이동
* Alt + b : 단어 단위로 커서를 한 단어 앞으로 이동
* Ctrl + d : 해당 커서 뒤의 문자를 1개씩 지운다.
* Alt + l : 현재 커서부터 그 토큰의 마지막까지 모두 소문자로 변경
* Alt + u : 현재 커서부터 그 토큰의 마지막까지 모두 대문자로 변경
<hr/>

<h2>파일 가공(필터) 명령어</h2>

* sort : 파일 내용을 __행 단위로 오름차순__ 으로 정렬한다.
  * 사용법 : sort [filename]
  * 정렬은 지정한 토큰의 __첫 번째 문자를 기준__ 으로 된다.
  * 정렬된 내용은 화면으로 출력되며, 원본은 변하지 않는다.
  * -k 옵션 : 토큰 번호를 k 다음에 입력한다.
    * 토큰은 1base이고, 개행 또는 탭으로 구분된다.
    * ex) sort -k2 fruits.txt
  * -t 옵션 : 특정 구분자를 지정하여 정렬한다.
    * ex) sort -t ':' -k 4 /etc/passwd
    * --> :를 구분자로 한 4번째 토큰을 기준으로 정렬한다.
  * -n 옵션(number) : 해당 컬럼을 문자가 아닌 __정수로 인식하여 정렬__ 한다.
    * ex) sort -t ':' -k 4 -n /etc/passwd
  * -r 옵션(reverse) : 오름 차순이 아닌 __내림 차순__ 으로 정렬한다.
  * -R 옵션(random) : 키의 해시값을 가지고 랜덤하게 정렬한다.
  * -f 옵션 : 문자의 대소문자와 관계없이 정렬을 수행한다.
  * -b 옵션(blank) : 검색의 기준이 되는 토큰 앞에 있는 공백을 무시하고 정렬한다.
  * -c 옵션 : 이미 파일이 정렬되어 있는지를 체크한다.
    * 정렬이 되어있다면 아무런 내용도 출력하지 않는다.
    * 정렬이 잘못되어 있다면 정렬을 위반한 곳의 정보를 출력한다.

* uniq : 텍스트 파일 내에 중복된 행이 존재할 경우, 중복된 행을 없애고 하나의 행으로 반환한다.
  * 사용법 : uniq [filename]
  * 중복 제거 기준 : 중복된 행이 __연속으로 존재한 경우만__ 중복을 없앤다.
  * -c 옵션(count) : 중복된 횟수를 출력한다.
  * -d 옵션(duplicate) : 중복된 행만 중복을 없애 출력한다.
  * -D 옵션 : 중복된 행을 중복제거 없이 그대로 출력한다.
  * -u 옵션 : 중복되지 않은 행만 출력한다.

* wc : 단어의 수를 출력한다
  * 사용법 : wc [filename]
  * 출력 : 라인 수, 토큰 수, 모든 문자들의 수(공백, 개행 포함)
  * -l 옵션 : 라인 수만 출력
  * -w 옵션 : 토큰(단어)의 수만 출력
  * -c 옵션 : 모든 문자들의 수(공백, 개행 포함)만 출력
    * 옵션들의 조합도 가능하다. -lw, -lwc 등
<hr/>

<h2>파일 종류 확인 명령어</h2>

* Linux에서는 Windows와는 다르게 확장자의 개념이 없기 때문에 파일의 종류를 쉽게 확인할 수 없다.
* 따라서 파일의 종류를 확인하기 위해서는 적절한 명령어를 알아야 한다.

* file : 파일의 종류를 출력한다.
  * 사용법 : file [fileName]
<hr/>

<h2>Meta 문자</h2>

* 메타 문자 : 수많은 파일들에 대하여 그룹을 지정할 수 있는 __특수한 문자__ 로, 쉘이 제공한다.
* 이는 Wild Card라고도 하며, Globbing이라고도 한다.
* 와일드카드를 사용하면 쉘은 와일드카드를 일치하는 파일명 또는 경로명으로 확장한다.

* (1) * : Asterisk
  * 쉘은 *를 0개 이상의 임의의 문자로 해석한다.
  * ex) echo * : *가 현재 directory의 모든 파일명으로 확장된다.
  * ex) echo /bin/g* : /bin내의 g로 시작하는 모든 파일명 및 directory 출력
  * ex) echo /bin/*zip : /bin내의 zip로 끝나는 모든 파일명 및 directory 출력
  * *는 1개 이상 사용 가능하다.
* (2) ?
  * 쉘은 ?를 임의의 한 문자로 해석한다.
  * ?도 1개 이상 사용 가능하다.
* (3) [] : Bracket
  * []내에 들어간 문자열 중 1개가 일치하는 것들을 선택한다.
  * ex) echo [1234]abc --> 1abc, 2abc, 3abc, 4abc중 존재하는 것을 선택
  * ex) echo[a-z][a-z][a-z] --> 3개의 알파벳으로 된 것 선택
  * ex) echo[0-9][0-9][0-9] --> 3개의 숫자로 된 것 선택
  * ex) echo [0-9,a-z]* 또는 echo[0-9a-z]* --> 숫자 또는 문자로 시작하는 것 선택
  * 여집합 사용하기 : 앞에 ^ 기호를 붙인다.
    * ex) echo [^0-9]* : 숫자로 시작하지 않는 모든 것 선택.

  * 위의 -를 사용한 문자 범위 집합은 UNIX 표기법이다. 
  * 따라서 호환성이 떨어지고, 경우에 따라 LINUX에서 제대로 동작하지 않을 수 있다.
  * 이를 위해 정규 표현식이 등장했다.
<table>
    <tr>
        <td>정규 표헌식</td>
        <td>UNIX 표기법</td>
    </tr>
    <tr>
        <td>[[:lower:]]</td>
        <td>[a-z]</td>
    </tr>
    <tr>
        <td>[[:digit:]]</td>
        <td>[0-9]</td>
    </tr>
    <tr>
        <td>[[:alnum]]</td>
        <td>[A-Za-z0-9]</td>
    </tr>
    <tr>
        <td>[^[:digit:]]</td>
        <td>[^0-9]</td>
    </tr>
</table>

  * []도 1개 이상 사용 가능하다. 
<hr/>

<h2>File 및 Directory 조작</h2>

* 빈 파일 생성
  * (1) touch 명령어
    * 사용법 : touch fileName
  * (2) > 사용
    * 사용법 : > fileName

* 빈 directory 생성
  * mkdir 명령어
    * 사용법 : mkdir dirName [dirName2, dirName3...]
    * 한번에 여러개의 directory를 생성할 수 있다.

* 파일 삭제 (복구 불가)
  * rm 명령어
  * 사용법 : rm fileName1 [fileName2, fileName3...]
  * -i 옵션 : 파일 삭제 전 확인 수행
  * -r 옵션 : 재귀적으로 하위 directory를 순회하며 모든 file과 directory를 삭제한다.
  * -f 옵션 : 모든 경고 및 오류를 건너뛰고 강제적으로 삭제한다.

* directory 삭제 (빈 directory만 삭제 가능하다.)
  * rmdir 명령어
  * 사용 방법 : rmdir dirName1 [dirName2, dirName3...]
  * --ignore-fail-on-non-empty 옵션 : 내용이 있어도 해당 directory의 삭제를 수행한다.

* file 및 directory의 복사
  * cp 명령어
  * 사용법 : cp fileName dirName 또는 cp srcFileName destFileName
  * 사용법 2 : cp file1 [file2,...] destDirName
    * 여러개의 file을 destDirName(목적지)로 복사한다.
  * -i 옵션 : 복사될 파일이 목적지에 존재할 경우, 덮어씌워지기 때문에 확인창을 출력한다.
  * -r 옵션 : directory를 통째로 복사할 때 사용

* file 및 directory의 이동
  * mv 명령어
  * 사용법 : cp와 동일
  * -i 옵션 : 복사될 파일이 목적지에 이미 존재할 경우, 덮어씌워지기 때문에 확인창을 출력한다.
  * mv는 기본적으로 대상 파일이 존재할 경우, 덮어쓰게 된다.
  * file또는 directory의 이름을 바꿀 때, mv명령어를 사용할 수 있다.
    * mv oldFileName newFileName

* link
  * ln 명령어 : Hard Link 또는 Symbolic Link를 만들 때 사용한다.

  * 아이노드(inode) : OS가 특정 file 또는 directory 등을 식별하기 위해 각각 부여하는 고유 번호들을 담고 있는 정보 구조체
    * inode구조체에는 실제 파일 또는 디렉토리가 있는 HDD의 위치 정보가 있다.

  * Hard Link : 같은 파일에 대하여 다른 이름을 부여하는 개념
    * 사용법 : ln fileName linkName
    * ex) hello.txt에 대해서 ln hello.txt hello2.txt를 수행하면 hello2.txt가 생기는데,   
    ls -i로 inode값을 보면 hello와 hello2는 동일한 값을 가진다. 
    * 따라서 당연하게도 hello.txt를 수정하면 hello2.txt도 똑같이 수정되어 보인다.
    * 즉, hello.txt와 hello2.txt는 동일한 inode 구조체를 참조하는 것이다.
    * 단, rm hello.txt를 수행해도 hello2.txt는 그대로 남아있다.
    * 따라서 __Hard Link는 복사에 대한 오버헤드를 피하기 위해 필수적인 기능__ 이다.
    * Hard Link의 제약 조건
      * (1) File System 외부에서는 파일을 참조할 수 없다.
        * Linux를 비롯한 대부분의 OS는 서로 다른 Partition의 inode 정보(테이블)를 공유하는   
        기능을 제공하지 않기 때문이다.
      * (2) Hard Link는 Directory를 참조할 수 없다.
        * 이를 허용하면, cp나 ls 에 대하여 -R 옵션을 사용하면 무한 루프에 빠지게 되기 때문이다.
        * 단, 자신과 부모 directory에 한해서만 허용한다.

  * Symbolic Link(Soft Link) : Hard Link가 directory를 참조할 수 없다는 제약 조건을 극복하기 위해 등장한 것.
    * 사용법 : ln -s fileName[or dirName] newName
    * ex) mkdir sub 후 ln -s sub sub2를 하면 sub2와 sub1은 같은 것을 가리킨다.
      * 이 후 touch /sub2/newfile을 하고, ls /sub를 하면 sub에도 newfile이 생겼음을 알 수 있다.
     * 단, newName의 크기는 가리키는 경로의 길이값이 된다.
     * 그 이유는 Symbolic Link는 기존 directory의 inode정보를 참조하는게 아니라,   
    __기존 directory의 경로만 갖고 있기 때문__ 이다.
     * 즉, Windows의 바로가기와 같은 개념이다.
     * Symbolic Link도 경우에 따라 Hard Link처럼 무한루프에 걸릴 수 있지만,   
        Linux System에서 이를 감지하고 탐색을 중지시킨다.
<hr/>

<h2>nano 텍스트 파일 편집기</h2>

* vim, emacs, gedit, nano 등 다양한 종류가 있다.

* nano 편집기 사용 방법 : nano [filename]
  * 편집기에 들어가면 아래에 단축키들이 출력된다.
<hr/>
