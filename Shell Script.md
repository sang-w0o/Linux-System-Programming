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

<h2>#6. Script란</h2>

* Bash 프로그램이 실행하기 위해 나열한 명령어들의 모음