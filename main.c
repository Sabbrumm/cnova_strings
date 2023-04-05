#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define KEY_ESC 27
#define KEY_ENTER 13
#define KEY_CONTROL 224
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_RIGHT 77
#define KEY_LEFT 75
#define KEY_BACKSPACE 8
#define and &&
#define or ||
#define not !

char String1[21] = "";
char String2[21] = "";



int ExitVar = 0;


int Screen = 0;
// 0 - Экран старта /0
// 1 - Экран длины строки /1
// 2 - Экран склеивания строк /3
// 3 - Экран копирования строк /3
// 4 - Экран реверса строки /2
// 5 - Экран ловеркейса /2
// 6 - Экран апперкейса /2
// 7 - Экран среза /4
// 8 - Экран ошибки /0
// 9 - Пасхалка /0

int LastErrorCode = 0;
// 1 - Вы ввели строки суммарной длиной более, чем 20 символов
// 2 - Значение начала среза не может быть меньше, чем 1
// 3 - Значение конца среза не может быть меньше начала среза
// 4 - Значение конца среза больше длины строки

int LastScreenBeforeError = 0;

int MenuPoint = 0;

int DoIntercept = 1;

int CutStart = 0;
int CutEnd = 0;


void cleanup(){
    system("cls");
}

void EasterEgg(){
    system("color 2");
    printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWNNXNNNNNNNWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
           "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNX0OkxdoolcccllllllodxxkkkkkOO0KNWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
           "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWNXKOdol:;,,''''................'''',;:cldxk0XNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
           "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWNXOxdlc:;,'''''''...........................'''',;:ldOXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
           "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKkdol:'...',,''''''''...............................''',,;cd0NWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
           "MMMMMMMMMMMMMMMMMMMMMMMMMMWWWXKOo:,'''..'',,,,,'''........................................'..,cdOXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
           "MMMMMMMMMMMMMMMMMMMMMMMMMWXOol:;,,,',,'',,,'''...................................................;lkKWMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
           "MMMMMMMMMMMMMMMMMMMMMMMWNkl;;;;;,,',,''.............................................................;lx0NMMMMMMMMMMMMMMMMMMMMMMM\n"
           "MMMMMMMMMMMMMMMMMMMMWNKxc;;;;,,''......................'''''...........................................'lONMMMMMMMMMMMMMMMMMMMMM\n"
           "MMMMMMMMMMMMMMMMMMWXklc:;,''''.............................................    ..........................,dXWMMMMMMMMMMMMMMMMMMM\n"
           "MMMMMMMMMMMMMMMMWXkc;;;;'..................................................       ........................':kNWMMMMMMMMMMMMMMMMM\n"
           "MMMMMMMMMMMMMMMNkl;,;,'.''........................................  .................             ..........,lOXWMMMMMMMMMMMMMMM\n"
           "MMMMMMMMMMMMMW0l,'''......................................   .........................                  ......;kNWWWMMMMMMMMMMMM\n"
           "MMMMMMMMMMMMNk:'''...........   ...................................''''''''..................              ...'cxO0XNWMMMMMMMMMM\n"
           "MMMMMMMMMMWXx:''.................................'''''......'',,;::ccllccc::;;,;;;;;;,,'',''......           ...',:dKWWMMMMMMMMM\n"
           "MMMMMMMMMW0l;''........................'''',,,,;;;:::::cc:::cllooddxxddddddoooooooooooolllllcc::;,...        ......;kXWMMMMMMMMM\n"
           "MMMMMMMMW0c,'.................'',,;;;;;:cccclloooddxxxxkkkkxxxkOOOOOOOOkkkkkkkkkkkkkkkkxxxxxdddoolc:,.....   ......';oKMMMMMMMMM\n"
           "MMMMMMMW0c'..............',,;:clloooooddxxxkkkOOOOO00000000000000000000000000000000OOOOOkkkkkkxxxdool:,..............,oNMMMMMMMM\n"
           "MMMMMMWOc'............,;:looddxxkkkkkOOOOOO00000000KKKKKKKK0000KKKKKK00000000000000000OOOOOOkkkkkkxxdol;'.............,kNWMMMMMM\n"
           "MMMMMNO:'......'...';codxkkkkOOO00000000000KKKKKKKKKKKKKKKKKKKKKKKKKKK00K00KKKK000000000OOOOOOkkkkkxxdoc;'.............c0WMMMMMM\n"
           "MMMMWOc'..''''...',coxkkOOOO000000000000KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK0KK000000000000OOOOOOOkkkxxdolc;'............'dNMMMMMM\n"
           "MMMWKl'..'''....';coxkkOO000000000000KKKKKKKKKKKKKKK0KKKKKKKKKKKKKKKKK0000000000000000000OOOOOOOOkkxxddolc;'............;kNMMMMM\n"
           "MMMXd;..''.....',:ldxkkOO000000000000KKKKKKKKKKKKK00000000KKK000000000000000000000000000000OOOOOOkkkxxdool:,'............,xNWMMM\n"
           "MMWk:'.''......';cldxkkOO00000000000KKKKKKKKKKK0000000000000000KKK0000000000000000000000000OOOOOOOkkkxdoolc:,.............:ONWMM\n"
           "MW0c,'.........';codxkOOOO000000000KKKKK00KKKKK0000000000000000KK0000000000000000000000000OOOOOOOOkkxxdoool:;''...........'dXWMM\n"
           "MNd;'.'........,;codxkkOOO00000000000KKKK0KKKKKK000000000000KKK000000000000000000000000000OOOOOOOOkkxxdoool:;,'.......'....:0WMM\n"
           "W0c'...........,:coxkkkOOO000000000000KKKKKKKKKK0000000000000000000000000000000000000000000OOOOOkkkkxdddool:;,'............'oXMM\n"
           "Nx;...........',:codxkkOOOO00000000000KKKKK00000000000KK0000000000000000KK000000000000000000OOOkkkkxddddool:;,'.............:OWM\n"
           "Xo'...........',;codkkkOOOO00000000KKK00000000000000KKKKKKKKKKKKKKKKKKKKKK00000000000000000OOOOOkkkxddddooc:;,'.............'oNM\n"
           "0c....''......',:codkkkkOOO00000000KKKK0000000000000000KKKKKKKKKKKK000KK00000OO000000000000OOOOOkkkxxddoooc:;,'............''cKM\n"
           "O;...''.......',:codxkkkOO00000OOOO0000000000000000000000K0000000000000000OOOOOOOOOO00OOOOOOOOkkkkkxxdooool:;,'............'';kW\n"
           "x,..','.......',:lodxxkkOO0OOOkkxkkkOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkkkkkkkkkkkkxxxxxxxxxxxxxxxdoooolc;,'.............''cK\n"
           "d'..,'........',:lddxxkkkkkxxdoooooooollllooooddxxkkkxkkOOOOOOOkkkkkkkkxxxxdoolcccccccccccclllclloddddollllc:,'...............;k\n"
           "o'.','........';coddxxxxdolcc::cc::;;,,,',,,',,;:clooodxxkkkkkkxxxxxxdddoolc:,'''''''''''',,;;;:::cllllllccc:;'...............;k\n"
           "o,.','........':loddddollc::;;,,,,''''.........',;;:cloodxxxxxxxxxxddoolc:;,'..........''',,,,,,;;;;;::::ccc::,...............;O\n"
           "d,',,'........,cloddolcc:;;,,,,,,;;;:;;,,,''....',,;:ccllodxxxxxxxddolcc:;,''.......',,;;;;;;,,,,,'',,,,;:::::;'..............;0\n"
           "O:',,'........;clooolc::;,,,,,;;;::cc::;;,,''....',,;;:ccldxkOOOkkxolc:;,''..........'''',,,,,'',,,,,,'',;::::;,..............:K\n"
           "Kl''.........':loooolcccc::::;,;;;;;,'.','.',,'...'',;:clodkO000OOkdl:,,'......';;,..,'...,,''...',;;;;;;;:::::,..............cK\n"
           "Nd,..........'clooooolllllc:;,',,;cl;...'..':oc;,,,;;;:codxk00000Okdl:;,'','',;cdo,......':c;'...',;;::::::::::;'.............;0\n"
           "WO;..........,codddddooollc:;;,,:codc,'...';oxdl:::cllcldxxO00000Okdoc:;:c:::ccoxxl;'..',:loc;,'',;;::cccccccc:;'......  .....,O\n"
           "NO;..........;ldxxxxxxddolllcc::cloddoc:;:coxxdoooddddooxkkO0K000Okxdollloooooooodolc:cclollc;,;::::ccllllllllc:'...     .....,k\n"
           "Nk;.........'cdxkkkkkkxxdoodddolccllloolloloooddxxkxxddxkkO0000000Oxdoooodddxxxddollccllcc:::::cllllloodddddoolc,...    ......:0\n"
           "Nk;.........;oxkkkOOOkkkkxxxxxxddooloooooodddxxkkkkkxxxxkOO000000OOxddoooddxxkkkxxxxdddooooolooooodddddxxxxxddoc,.............cK\n"
           "Nk:,.......'cdxkkkOOOOOOOOOkkkkxxxxxxdxxxxkkkkkkkkkxxxxkkkOO000OOOkxxdddddxxkkOOkkkkkkkxxxxxxxxxxxxxxxxxxxxxddol:'............dN\n"
           "N0o;'......,oxkkkkkOOOOOOOOOOOkkkkkkkkkkkkkkkOOOkkkxxxxkkkOO000OOOkxxddddddxxkOOOOOOOkkkkkkxxxkkkkkkkkkkxxxxddooc,..  .......,kN\n"
           "NXx;'''....;dxxxkkkOOOOO000OOOOOOOOOOOOOOOOOOOOOkkkxxxkkkOO00000OOOkxxdddoddxxkOOOOOOOOOkkkkkkkkkkOOkkkxxxxddoool;...........;OW\n"
           "NX0l,'''...:dxxxkkkkOOOO00OOOOOOOOOOOOOO0000000OOkxxxxkkkOO00000OOOkkxddoooodxkOOOOOO0OOOOOOOOOOOOOOOkkxxxdddoolc;...........cKW\n"
           "NXXk:,,,,..:dxxxxxkkkkOOOOOOOOOOOOOOO0000000000OOkxddxkkOOOO00000OOkkkxdollodxkOOOOOO000OOOOOOOOOkkkkxxxddddoollc:'...'''.'.;kWW\n"
           "WNNKd;,::,.;oxxxxxxxkkkkkkkOOOOOOOO000000000000OkxddxxkkOOO00KK000OkkxxdoolodxkOOOOOO000OOOOOkkkkkkkxxxdddooollcc:'.',;:,'',dXWW\n"
           "WNNNOc:lc;''cddxxxxxxkkkkkkkkkkOOOO000000000000OkxdxxxxxxkOO00000OkxxdoooooooxkOOOOO000OOOOOkkkxxxxxxdddoooollccc:,',;:::,;oKWWW\n"
           "WWNNOooolc;,:oddxxxxxxxxxxkkkkkkOOOO0000000000OOkxxxdooloodxxxxxxxdolc::cllloxkOOOOOO00OOOOkkkxxxddddddoooollcccc:;,,:cccco0WWWM\n"
           "WWWN0dddol::lddddxxxxxxxxxxkkkkkOOOOO00000000OOkxddolc:;;:ccclllccc;,,,,:cccloxkOOOOOOOOOOOkkkxxddddddoooollcc::cc:;;:lollkNWWWM\n"
           "WWWWXkddoc::oddddddxxxxxxxxkkkkkkOOOOOOOOOOOOkkxdoll:,....,;;;;,,,'.....,;:::ldkOOOOOOOOOkkkxxddddoodoooollc::::cc:;;:lood0WMWMM\n"
           "WWWWNOxdoc::ldddddddxxxxxxxxxxkkkkkOOOOOOOOOkkkxdlc:;,'..',;,,'''''.....,;;;:lxkkkOOOOOOkkkxxdddoooooooollcc:::cc::::clookXWWMWW\n"
           "WWWWN0xxdooooddddddddxxxxxxxxxxkkkkkkkkOOOOOOOkkxl::;;,,,;;::;;,,,''''',;;;;:oxkkkkOOOOkkkkxxdddoooooooollc::::ccclooloddONWWMMM\n"
           "WWWWN0xkkkkkkxddddddddxxxxxxxxxxkkkkkOOOOOOOOOOkxoc:;;;;::cclllcc::;,,,,,,,:ldxkkOOOOOkkkxxxxdddoooooooollc:::cccloodoooo0WWMMMM\n"
           "WWWWN0kkOOOOxxddddddddddxxxxxxkkkkkkOOOOOOOOOOOOkkxdoolllloddddddolc:::ccllodxkkkOOOOOkkkxxxdddooooooooolcc::cccclodxdddkXWWMMMM\n"
           "WWWWNX0OOOOOkxddddddddddxxxxxxkkkkkkkkkkkkkOOOOOOOkkkxxdddddxxxxxxxollloddxxkkkkkkkOOOOkkkxxxddooooooolllccccccclodxxxxx0WMMMMMM\n"
           "WWWWWNKOOOOOOkxdddddddddxxxxxkkkkkkkkkkkkkkOOOOOOOkkkkxxxxxxxxddxxxdoooddxxxkkkkkkkkOOkkkxxxxddoooooollllccccccclddxdddkXWMMMMMM\n"
           "WWWWWWNKOkxxkkxdddddddddxxxxxkkkkkkkkkkkkkOOOkkkkkkkkxxxxxxxxddddxkxdddddddxxxxkkkkkkkkkkxxxdddooooolllllccccccccloodk0XWMMMMWMM\n"
           "WWWWWWWWNX0OkxdoodxddddddxxxxxkkkkkkkxkkkkkkkkkkkkkxxxxkkkkkkxxxxxkkkxxxxxddddxxxxxxxxxxxxxxdddooooolllllccccclxkkOKNWWMMMMWWMMW\n"
           "WWWWWWWWWWWWNNXKKOxxddddddxxxxxkkxxxxxxxkkkkkxxxxxxxxkkkxddxxkkkkxdddddxxxddddddddddddxxxxddddooooollllcccclclkXWWWWMMMMMMMWWMMM\n"
           "WWWWWWWWWWWWWWWWWXkxddddddddxxxxxxxxkxxxxxxxddddddddoolcc::::cllcc:;:::ccllooooooooodddddddddooooolllllcccccco0WWMMMMMMMMMMWWWMM\n"
           "WWWWWWWWWWWWWMMMWW0xddddddddddxxxxxxxxxxdddolllllc::;;;,,,,,,,,,,,,,,,,,,,,,,;::::cloooodddddooooolllllllccclxXWWMMMMWMMMMWWWWWW\n"
           "WWWWWWWWWWWWWWMMMWXOddddddddddddxxxxxxxdoolc;,,,,,,,;;;;;;;;;;;;;;::;;;;,,''....',;:cllooddddoooollllllllccco0NWMMWWWWMWWWWWWWWW\n"
           "WWWWWWWWWWWWWWWMWMWKxdddddddddddddddxxddolllc:;;;:cllooodddddddddddddooollc::;;;:cccllooodddoollllllllllccccxXWWWWWWWWWWWWWWWWWW\n"
           "WWWWWWWWWWWWWWWWWMMNOdodddddddddddddxxxddddxddddoodooodddxxxxxxxxxxxddoooooooooodddddddddddoollllllllllccccdKWWWWWWWWWWWWWWWWWWW\n"
           "WWWWWWWWWWWMMMMMMMMWKxodddodddoooooodddxxxxxxxxxxdddddddddddddddddddoooooooooodddddxxxxxddollccccclccccc::ckNWWWWWWWWWWWWWWWWWWW\n"
           "WWWWWWWWWWWWWMMMMMMWW0xddooooooooooooddxxxxxxxxxxdddooollllcllllllllllllllloooddddddxxxdoollccccclcccc::::lOWWWWWWWWWWWWWWWWWWWW\n"
           "WWWWWWWWWWWWWMMMMMWWWNOdoooooooooooloddxxxxxxxddddooollllllllllccccllllllloooodddodddddoolcccccllcccc:::::lONWWWWWWWWWWWWWWWWWWW\n"
           "WWWWWWWWWWWWWWWMMMMMWWKxddoooooooolllooddxxddddddddddooooddddddodddddooooooooooodddddooollcccllllcc:::;:::ckNWWWWWWWWWWWWWWWWWWW\n"
           "WWWWWWWMMMMMMWWMMMMMWWXkddooooooooolllloddddddddddddddddxxxkkkkkkkkkxxdddooooooooooooolllccclllllc::;;;;::ckNWWWWWWWWWWWWWWWWWWW\n"
           "WWWWWWMMMMMMMMWWMMMWWWXkdoooooooddoolllloooodddddddddxxkkkkOOOOOOOOOkkxxxddddddooooollllcccclllc::;;;;;;::ckXNWWWWWWWWWWWWWWWWWW\n"
           "WWWWWWMMMMMWWWWWWWWWWWXkddoooooooddooollooooddddddxxxkkOOOOOOOOOOOOOOkkxxxxxxxdddooolccccccccc::;;;;;;;::cckXNWWWWWWWWWWWWWWWWWW\n"
           "WWWWWWWMWWWWWWWWWWWWWWXOddoooooooooooooooooddddddxkkkkkkkkkkkkkkkkkkkkkxxxxxxxxddooollccc::::;;;;;;;;;;::cckNWWWWWWWWWWWWWWWWWWW\n"
           "WWWWWWWWWWWWWWWWWWWWWWNkdddooollllllolloooodddddxxkkkkkkxxxxxddddxxkkkkxxddddddoooollcc::;;;,,,,,;;;;:::ccckNWWWWWWWWWWWWWWWWWWW\n"
           "WWWWWWWWWWWWWWWWWMWWWWNOddddoollllcclccllooodddddddxxxkxxxxdooooodxxxxxddooolooollcc::;;,,,',,,,,;;;::cccccxNWWWWWWWWWWWWWWWWWWW\n"
           "WWWWWWWWWWWMWWWWWWWWWWNOxdddoollllcccc:ccllllooooooooddxxxxdddddooddooooolllccccc::;;,,'''',,,,,;;;:::cccccxXWWWWWWWWWWWWWWWWWWW\n"
           "WWWWWWWWWWWWWWWWWWWWWWNOxddddoollllcc::::::cclllllcccloooooodddooooolllccccc::::;;,,''''',,,,,,;;;::cccccccxXWWWWWWWWWWWWWWWWWWW\n"
           "WWWWWWWWMWWWWWWWWWWWWWN0xddddooolllccc:::;;:::ccccc:::cccllllllcccccc::::::;;,,,'''''',,,,,,,,;;;::ccclllccxXWWWWWWWWWWWWWWWWWWW\n"
           "WWWWWWWWWWWWWWWWWWWWWWN0xdddddoolllcccc:::;;;;;::::;;;;;;;;;;:;;;;;;;;;;;,,,''''''',,,,,,,,,,;;::ccccllllllxXWWWWWWWWWWWWWWWWWWW\n"
           "WWWWWWWWWWWWWWWWWWWWWWN0xdddddooolllcccc::::;;;;;;;;,,,,,,,,,,,,,,,,,,,''''''''''',,,,,,,,,;;;::cclllllllllxXWWWWWWWWWWWWWWWWWWW\n"
           "WWWWWWWWWWWWWWWWWWWWWWN0xxdddddooolllcccc::::;;;;;;;,,,,,,,'''''''''''''''''''',,,,,,,,,,;;;::cccllllllllllxXWWWWWWWWWWWWWWWWWWW\n"
           "WWWWWWWWWWWWWWWWWWWWWWWKkxxxddddoooolllccc:::;;;;;;;;;;;,,,,,,,,',,''''''',,,,,,,,,,,,,;;;::cccllllllllllllkNWWWWWWWWWWWWWWWWWWW\n"
           "WWWWWWWWWWWWWWWWWWWWWWWKkxxxxdddddooolllcccc:::::;;;;;;;;,,,,,,,,,,,,,,,,,,,,,,,,,,,;;;;:::cclllloloooollllkNWWWWWWWWWWWWWWWWWWW\n"
           "WWWWWWWWWWWWWWWWWWWWWWWKkxxxxxxxdddoooollllcccccc:::::;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;::::cccllooooooooollllkXWWWWWWWWWWWWWWWWWWW\n"
           "WWWWWWWWWWWWWWWWWWWWWWNKkxxxxxxxddddddoooollllllccccccc:::::::::::::::;;;;;;;;;;;;;::::cccllloooooooooollllkKXWWWWWWWWWWWWWWWWWW\n"
           "WWWWWWWWWWWWWWWWWWWWWWNXOxxxxxxxxxxxddoooooollllllllllccccccccccc:::::::::::::::::::::ccllloooooddooooollloOKKNWWWWWWWWWWWWWWWWW\n"
           "WWWWWWWWWWWWWWWWWWWWWNNXOxxxxkkkxxxxxddddoooooooolllllllllllccccccccccccccccc::cc:::cclloooddddddddooolllld0K0OkKNWWWWWWWWWWWWWW\n"
           "WWWWWWWWWWWWWWWWWWWXKXNNKkxxkkkkkkkxxxxdddooooooooooooolllllllllcccccccccccccccccccclloooddddddddddoooolld0K00Oc;xXWWNNNNNWWNNWW\n"
           "WWWWWWWWWWWWWWWWWXkclKNNWXOxkkkkkkkkkxxxxddddooooooollooooollllllllllllccccccccccclllooddddddxxxdddddoolx0KOO00o'.cONWNNNNNNNNWN\n"
           "WWWWWWWWWWWWWWWN0l',xXXNNWN0kkkkkkkkkkkxxxxxddooooooooooooooooollllllllllllllllllllloooddxxxxxxxxddddodkKK0O00Kk;..;xXWWWWWWWWWW\n"
           "WWWWWWWWWWWWWWXd;'.c0XXNNNWNKOkkkkkkkkkkkxxxxxddoooooooooooooooooolllllllllllllllloooddxxxxkxxxxxddddk0XKOO00KKOl...,dXWNNWNNNNW\n"
           "WWWWWWWWWWWWWKo,'.'xXXXXNNNWWN0OkkkOOOkkkkkkxxxddddddoooooooooddooollllllllllooooooddxxxxkkkkxxxxxxk0XK0OO00KKK0o'...'oXNNNNNNNN\n"
           "WWWWWWWWWWWWKl,'..:0NXXXXNNNWWWX0OkOOOOOOkkkkxxxxxddddddddddddddooooooooooodddddddddxxxkkkkkkkxxkOKXXK0000KKKK0Oo'....'l0NNNNNNN\n"
           "WWWWWWWWWWWKl,''..oKNXXXXNNNWWWWWNKOkOOOOOkkkkkxxxxxxxxxxddddddddddddddddddddddddddxxkkkkkkkkkO0XXXKK0000KKKKK0Ol'.....':xXNNNNN\n"
           "WWWWWWWWWXkc,'''.'dXNXNNNNNWWWWWWWWNK0OOOOOOkkkkkxxxxxxxxxddxxddddddddddddddddddxxxkkkkkkkkO0KNNXXKKKKKKKKXXKK0kc'......',ckXWNN\n"
           "WWWWWWWNOl;,''''.'dXXXXXNNNWWWWWWWWWWWXKOOkOkkOkkkxxxxxxxxxxxxxxxddddxxdxdddddxxxkkkOOOOOOKXNNNXXXKKKKKXXXXKK00x:........'',ckXN\n"
           "NNWWWNOo;,,,''''.'lKXXXXXXNNWWWWWWWWWWWWNK0OkkOkkkkkkkxxxxxxxxxxxxxxxxxxxxxxxxkkkkOOOOO0XNWWNNNXXXXXXXXXXXXKK0Oo,............,ck\n"
           "NWNKkl;,,'',''''..c0XXXXXXNNWWWWWWWWWWWWWWWX0OkOOOkkkkkkkkxxxxxxxxxxxxxxxxxxkkkkkOOOOKXWWWWNNNNNXXXXXXXXXXKK00k:...............'\n"
           "XOo:,,,'''''''''..:kXXXXXXXNNWWWWWWWMMWWWWWWWNK0OkkkOOOkkkkkkkkkkkkkxxkkkkkkkkkOOO0KNWWWWWWWNNNNNNNXXXXXXKK00Oo'................\n"
           "c;,,,,,''''''''...,dKXXXXXXXNNWWWWMMMMMMMMWWWWWWX0OkkOOOOOkkkkkkkkkkkkkkkkkOOOOO0XNWWWWWWWWWNNNNNXXXXXXXKK00Ox;.................\n"
           "'',,,,''''''''''..'lOKXXXXXXNNWWWWMMMMMMMMMMMWWWWWNKOOOOOOOOkkkkkkkkkkkkkkOOOO0XWWWWWWWWWWWWNNNNNXXXXXKKK000k:'.................\n"
           "'''',,''''''''''''':kKXXXXXXXNNWWWMMMMMMMMMMMMMMWWWWNX0OkOOOOOOOOOOOOOOOOOOO0XWWMWWWWWWWWWWWWWNNNXXXXXKK000Ol'..................\n"
           "''''''''''''''''''';d0XXXNXXNNNWWWMMMMMMMMMMMMMMMMMMMWWX0OkkOOOOOOOOOOOOOO0XWWMMWWWWWWWWWWWWWWWNNXXXXKK0000d,...................\n"
           "''''''''''''''''''.,oOKXNNNXNNNWWWMMMMMMMMMMMMMMMMMMMMMWWKOkkOOOOOOOOOOOOKNWMMMMMMMWWWWWWWWWWWWNNXXXKKK000Oc'...................");
}

void Arrow(int boo){
    if (boo){
        printf(" <-- [Enter]\n");
    }
    else{
        printf("\n");
    }
}

unsigned int StringLen(const char* stri){
    unsigned int cou = 0;
    for (int i=0; ;i++){
        char j = stri[i];
        if (j=='\0'){
            break;
        }
        else {
            cou++;
        }
    }
    return cou;
}

void StringCat(char* str1, char* str2){
    unsigned int i = StringLen(str1);
    for (int j = 0; j<StringLen(str2); i++, j++){
        printf("%d",str2[j]);
        str1[i]=str2[j];
    }
    str1[i] = '\0';
}

void StringCopy(char* src, char* dest){
    int i = 0;
    for (; i<StringLen(src); i++){
        dest[i]=src[i];
    }
    dest[i]='\0';
}

void StringRev(char* str){
    unsigned int lenn = StringLen(str);
    for (int i = 0; i<lenn/2; i++){
        char k = str[i];
        str[i] = str[lenn-1-i];
        str[lenn-1-i] = k;
    }
}

void StringUpper(char* str){
    for (int i = 0; i<StringLen(str); i++){
        if (str[i]>=97 and 122>=str[i]){
            str[i] = str[i]-32;
        }
    }
}

void StringLower(char* str){
    for (int i = 0; i<StringLen(str); i++){
        if (str[i]>=65 and 90>=str[i]){
            str[i] = str[i]+32;
        }
    }
}

void StringCutter(char* str, int start, int stop){
    if (stop <= StringLen(str) and start<= stop){
        int j = 0;
        char buffer[21] = "";
        for (int i = start-1; i<stop; i++, j++){
            buffer[j] = str[i];
        }
        buffer[j] = '\0';
        StringCopy(buffer, str);
    }

}

int StringComp(char* str1, char* str2){
    if (StringLen(str1)!=StringLen(str2))
        return 0;
    for (int i = 0; i<StringLen(str1); i++){
        if (str1[i]!=str2[i]){
            return 0;
        }
    }
    return 1;
}

void IntroScreen(){
    printf("================================================================\n"
           "\n"
           "\n"
           "                         Строки C-NOVA\n"
           "\n"
           " <<           Используйте стрелки для переключения           >> \n"
           "                        между экранами\n"
           "\n"
           "                     Нажмите ESC для выхода\n"
           "\n"
           "\n"
           "================================================================\n");
}

void LenScreen(){
    printf("================================================================\n"
           "\n"
           "-- Вычисление длины строки  --\n"
           "\n"
           "\n");
    printf("1) Строка A: %s", String1);
    Arrow(MenuPoint==0);
    printf("\n"
           "\n");
    printf("Длина строки: %d\n", StringLen(String1));
    printf("\n"
           "\n");
    printf("================================================================");
}

void InputScreen(char* catch){


    printf("================================================================\n"
           "\n"
           "\n"
           "\n"
           "Введите строку и нажмите ENTER:\n"
           "\n");
    printf("%s", catch);
    printf("\n"
           "\n"
           "\n"
           "\n"
           "================================================================");
}

void CatScreen(){
    printf("================================================================\n"
           "\n"
           "-- Склеить две строки --\n"
           "\n"
           "\n");
    printf("1) Строка A: %s", String1);
    Arrow(MenuPoint==0);
    printf("2) Строка B: %s", String2);
    Arrow(MenuPoint==1);
    printf("3) Склеить строки");
    Arrow(MenuPoint==2);
    printf("\n"
           "\n"
           "\n");
    printf("================================================================");

}

void CpyScreen(){
    printf("================================================================\n"
           "\n"
           "-- Скопировать строку A в строку B --\n"
           "\n"
           "\n");
    printf("1) Строка A: %s", String1);
    Arrow(MenuPoint==0);
    printf("2) Строка B: %s", String2);
    Arrow(MenuPoint==1);
    printf("3) Скопировать");
    Arrow(MenuPoint==2);
    printf("\n"
           "\n"
           "\n");
    printf("================================================================");
}

void RevScreen(){
    printf("================================================================\n"
           "\n"
           "-- Перевернуть строку --\n"
           "\n"
           "\n");
    printf("1) Строка A: %s", String1);
    Arrow(MenuPoint==0);
    printf("2) Перевернуть");
    Arrow(MenuPoint==1);
    printf("\n"
           "\n"
           "\n"
           "\n");
    printf("================================================================");
}

void LowerScreen(){
    printf("================================================================\n"
           "\n"
           "-- Понизить регистр строки --\n"
           "\n"
           "\n");
    printf("1) Строка A: %s", String1);
    Arrow(MenuPoint==0);
    printf("2) Понизить регистр");
    Arrow(MenuPoint==1);
    printf("\n"
           "\n"
           "\n"
           "\n");
    printf("================================================================");
}

void UpperScreen(){
    printf("================================================================\n"
           "\n"
           "-- Повысить регистр строки --\n"
           "\n"
           "\n");
    printf("1) Строка A: %s", String1);
    Arrow(MenuPoint==0);
    printf("2) Повысить регистр");
    Arrow(MenuPoint==1);
    printf("\n"
           "\n"
           "\n"
           "\n");
    printf("================================================================");
}

void CutScreen(){
    printf("================================================================\n"
           "\n"
           "-- Срез строки --\n"
           "!! Отсчет символов начинается с первого, а не с нулевого !!"
           "\n"
           "\n");
    printf("1) Строка A: %s", String1);
    Arrow(MenuPoint==0);
    printf("2) Срезать начиная с символа: %d", CutStart);
    Arrow(MenuPoint==1);
    printf("3) Заканчивая символом: %d", CutEnd);
    Arrow(MenuPoint==2);
    printf("4) Срезать");
    Arrow(MenuPoint==3);
    printf("\n"
           "\n");
    printf("================================================================");
}

void ErrorScreen(){
    printf("================================================================\n"
           "\n"
           "\n"
           "Ошибка!\n"
           "\n");
    if (LastErrorCode == 1){
        printf("Вы ввели строки суммарной длиной более, чем 20 символов\n");
    }
    else if (LastErrorCode == 2){
        printf("Значение начала среза не может быть меньше, чем 1\n");
    }
    else if (LastErrorCode == 3){
        printf("Значение конца среза не может быть меньше начала среза\n");
    }
    else if (LastErrorCode == 4){
        printf("Значение конца среза больше длины строки\n");
    }
    printf("\n"
           "\n"
           "Нажмите ESC или Enter для продолжения\n"
           "\n"
           "\n"
           "================================================================\n");
}

void UI(){
    if (Screen==0) {
        IntroScreen();
    }
    if (Screen==1) {
        LenScreen();
    }
    if (Screen==2) {
        CatScreen();
    }
    if (Screen==3) {
        CpyScreen();
    }
    if (Screen==4) {
        RevScreen();
    }
    if (Screen==5) {
        LowerScreen();
    }
    if (Screen==6) {
        UpperScreen();
    }
    if (Screen==7) {
        CutScreen();
    }
    if (Screen==8){
        ErrorScreen();
    }
    if (Screen==9){
        EasterEgg();
    }
}

void StringCatcher(char* catch){
    int key = 0;
    while (key!=KEY_ENTER and key!=KEY_ESC){
        cleanup();
        InputScreen(catch);
        key = _getch();
        if (key>=32 and key <=126){
            unsigned int lenn = StringLen(catch);
            if (lenn<20){
                catch[lenn] = (char)key;
                catch[lenn+1] = '\0';
            }
        }
        if (key == KEY_BACKSPACE){
            unsigned int lenn = StringLen(catch);
            if (lenn>0){
                catch[lenn-1] = '\0';
            }
        }
        if (key == KEY_CONTROL){
            key = _getch();
            continue;
        }

    }
}

int checkforeaster(char* str){
    return StringComp(str, "SinevVE");
}


void Intercept(){
    int key = _getch();

    if (key==KEY_ESC) {
        if (Screen!=8 and Screen!=9){
            ExitVar = 1;
        }
        else {
            Screen = LastScreenBeforeError;
            system("color F");
        }
    }

    else if (key>=48 and key<=57){
        int numero = key-48;
        if (Screen==7){
            if (MenuPoint == 1) {
                if (CutStart*10+numero<=20)
                CutStart = CutStart*10+numero;
            }
            if (MenuPoint == 2) {
                if (CutEnd*10+numero<=20)
                CutEnd = CutEnd*10+numero;
            }
        }
    }

    else if (key == KEY_ENTER) {
        if (Screen == 1){
            if (MenuPoint == 0) {
                cleanup();
                StringCatcher(String1);
            }
        }
        else if (Screen == 2){
            if (MenuPoint == 0) {
                cleanup();
                StringCatcher(String1);
            }
            if (MenuPoint == 1) {
                cleanup();
                StringCatcher(String2);
            }
            if (MenuPoint == 2) {
                if (StringLen(String1)+StringLen(String2)<=20){
                    StringCat(String1, String2);
                }
                else {
                    LastScreenBeforeError = 2;
                    LastErrorCode = 1;
                    Screen = 8;
                }
            }
        }
        else if (Screen == 3){
            if (MenuPoint == 0) {
                cleanup();
                StringCatcher(String1);
            }
            if (MenuPoint == 1) {
                cleanup();
                StringCatcher(String2);
            }
            if (MenuPoint == 2) {
                StringCopy(String1, String2);
            }
        }
        else if (Screen == 4){
            if (MenuPoint == 0) {
                cleanup();
                StringCatcher(String1);
            }
            if (MenuPoint == 1) {
                if (not checkforeaster(String1))
                StringRev(String1);
                else{
                    LastScreenBeforeError = 4;
                    Screen=9;
                }
            }
        }
        else if (Screen == 5){
            if (MenuPoint == 0) {
                cleanup();
                StringCatcher(String1);
            }
            if (MenuPoint == 1) {
                StringLower(String1);
            }
        }
        else if (Screen == 6){
            if (MenuPoint == 0) {
                cleanup();
                StringCatcher(String1);
            }
            if (MenuPoint == 1) {
                StringUpper(String1);
            }
        }
        else if (Screen == 7){
            if (MenuPoint == 0) {
                cleanup();
                StringCatcher(String1);
            }
            if (MenuPoint == 3) {
                if (CutStart<1){
                    LastScreenBeforeError = 7;
                    LastErrorCode = 2;
                    Screen=8;
                }
                else if (CutEnd<CutStart){
                    LastScreenBeforeError = 7;
                    LastErrorCode = 3;
                    Screen=8;
                }
                else if (CutEnd>StringLen(String1)){
                    LastScreenBeforeError = 7;
                    LastErrorCode = 4;
                    Screen=8;
                }
                else {
                    StringCutter(String1, CutStart, CutEnd);
                }
            }


        }
        else if (Screen == 8 or Screen == 9){
            Screen = LastScreenBeforeError;
            system("color F");
        }


    }

    else if (key == KEY_CONTROL){
        key = _getch();
        if (key == KEY_UP){
            if (Screen == 2 or Screen == 3){
                MenuPoint--;
                if (MenuPoint < 0){
                    MenuPoint= 2;
                }
            }
            if (Screen == 4 or Screen == 5 or Screen == 6){
                MenuPoint--;
                if (MenuPoint < 0){
                    MenuPoint= 1;
                }
            }
            if (Screen == 7){
                MenuPoint--;
                if (MenuPoint < 0){
                    MenuPoint= 3;
                }
            }

        }
        else if (key == KEY_DOWN){
            if (Screen == 2 or Screen == 3){
                MenuPoint++;
                if (MenuPoint >2){
                    MenuPoint=0;
                }
            }
            if (Screen == 4 or Screen == 5 or Screen == 6){
                MenuPoint++;
                if (MenuPoint > 1){
                    MenuPoint=0;
                }
            }
            if (Screen == 7){
                MenuPoint++;
                if (MenuPoint >3){
                    MenuPoint=0;
                }
            }

        }
        else if (key == KEY_RIGHT){
            Screen++;
            MenuPoint=0;
            if (Screen>7){
                Screen=0;
            }
        }
        else if (key == KEY_LEFT){
            Screen--;
            MenuPoint=0;
            if (Screen<0){
                Screen=7;
            }
        }
    }

    else if (key == KEY_BACKSPACE){
        if (Screen==7){
            if (MenuPoint == 1) {
                CutStart = CutStart/10;
            }
            if (MenuPoint == 2) {
                CutEnd = CutEnd/10;
            }
        }
    }

}
int main() {
    SetConsoleOutputCP(CP_UTF8);

    // Я честно понимаю что значит этот код, я очень хочу красивое название окошка
    // Я создаю динамический массив из ансайнд шортов, потому что они по два байта, сделано чтобы
    // адекватно воспринимался юникод. L перед строкой - это для того чтобы каждый символ в ней воспринимался как
    // wchar_t - то есть читался виндой. Мне это очень нужно правда просто для красоты очень хочется.....

    const unsigned short * myTitle = L"Строки C-NOVA [v0.1a]";
    SetConsoleTitleW(myTitle);

    while (not ExitVar){
        cleanup();
        UI();
        if (DoIntercept){
            Intercept();
        }
    }
    return 0;
}