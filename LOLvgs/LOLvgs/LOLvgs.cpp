// LOLvgs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>

bool listenVGSBOOL = true;
bool laneBOOL = true;
bool objBOOL = true;
bool selfBOOL = true;
bool enemyBOOL = true;
bool gankBOOL = true;
std::string message = "";


void SendEnter() {

    INPUT ip;

    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    ip.ki.wVk = 0x0D;
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));

    // Release the key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
}

int SendKeys(const std::string& msg)
{
    std::vector<INPUT> vgsoutput(msg.size());

    for (unsigned int i = 0; i < msg.size(); ++i)
    {
        vgsoutput[i].type = INPUT_KEYBOARD;
        vgsoutput[i].ki.wVk = msg[i];
        vgsoutput[i].ki.dwFlags = 0;
        SendInput(1, &vgsoutput[i], sizeof(INPUT));

        vgsoutput[i].ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
        SendInput(1, &vgsoutput[i], sizeof(INPUT));


    }
    return 0;
}

void listenLANE() {
    laneBOOL = true;
    Sleep(150);
    while (laneBOOL) {
        if (GetKeyState('1') & 0x8000) {
            message += " LANE";
            SendEnter();
            Sleep(50);
            SendKeys(message);
            SendEnter();
            laneBOOL = false;
            Sleep(200);
        }
        if (GetKeyState('2') & 0x8000) {
            message += " LANE";
            SendEnter();
            Sleep(50);
            SendKeys(message);
            SendEnter();
            laneBOOL = false;
            Sleep(200);
        }
        if (GetKeyState('3') & 0x8000) {
            message += " LANE";
            SendEnter();
            Sleep(50);
            SendKeys(message);
            SendEnter();
            laneBOOL = false;
            Sleep(200);
        }
        if (GetKeyState('T') & 0x8000) {
            message += " TOWER";
            SendEnter();
            Sleep(50);
            SendKeys(message);
            SendEnter();
            laneBOOL = false;
            Sleep(200);
        }

        if (GetKeyState('G') & 0x8000) {
            message += " INHIB";
            SendEnter();
            Sleep(50);
            SendKeys(message);
            SendEnter();
            laneBOOL = false;
            Sleep(200);
        }

        if (GetKeyState('X') & 0x8000) {
            laneBOOL = false;
            Sleep(200);
        }


    }

}


void listenOBJ() {
    Sleep(220);
    while (objBOOL) {
        if (GetKeyState('S') & 0x8000) {
            message += " DRAKE";
            SendEnter();
            Sleep(50);
            SendKeys(message);
            SendEnter();
            listenVGSBOOL = false;
            objBOOL = false;
            Sleep(200);
        }

        if (GetKeyState('B') & 0x8000) {
            message += " BARON";
            SendEnter();
            Sleep(50);
            SendKeys(message);
            SendEnter();
            listenVGSBOOL = false;
            objBOOL = false;
            Sleep(200);
        }

        if (GetKeyState('G') & 0x8000) {
            message += " INHIB";
            SendEnter();
            Sleep(50);
            SendKeys(message);
            SendEnter();
            listenVGSBOOL = false;
            objBOOL = false;
            Sleep(200);
        }

        if (GetKeyState('T') & 0x8000) {
            message += " TOWER";
            SendEnter();
            Sleep(50);
            SendKeys(message);
            SendEnter();
            listenVGSBOOL = false;
            objBOOL = false;
            Sleep(200);
        }

        if (GetKeyState('1') & 0x8000) {
            message += " TOP";
            listenLANE();
            listenVGSBOOL = false;
            objBOOL = false;
            Sleep(200);
        }

        if (GetKeyState('2') & 0x8000) {
            message += " MID";
            listenLANE();
            listenVGSBOOL = false;
            objBOOL = false;
            Sleep(200);
        }

        if (GetKeyState('3') & 0x8000) {
            message += " BOT";
            listenLANE();
            listenVGSBOOL = false;
            objBOOL = false;
            Sleep(200);
        }

        if (GetKeyState('N') & 0x8000) {
            message += " NEXUS";
            SendEnter();
            Sleep(50);
            SendKeys(message);
            SendEnter();
            listenVGSBOOL = false;
            objBOOL = false;
            Sleep(200);
        }

        if (GetKeyState('X') & 0x8000) {
            listenVGSBOOL = false;
            objBOOL = false;
            Sleep(200);
        }


    }
}

void listenSELF() {
    Sleep(220);
    while (selfBOOL) {
        if (GetKeyState('A') & 0x8000) {
            message += " AM STACKING";
            SendEnter();
            Sleep(50);
            SendKeys(message);
            SendEnter();
            listenVGSBOOL = false;
            selfBOOL = false;
            Sleep(200);
        }

        if (GetKeyState('B') & 0x8000) {
            message += " AM BACKING";
            SendEnter();
            Sleep(50);
            SendKeys(message);
            SendEnter();
            listenVGSBOOL = false;
            selfBOOL = false;
            Sleep(200);
        }

        if (GetKeyState('Z') & 0x8000) {
            message += " WANT RED BUFF";
            SendEnter();
            Sleep(50);
            SendKeys(message);
            SendEnter();
            listenVGSBOOL = false;
            selfBOOL = false;
            Sleep(200);
        }

        if (GetKeyState('C') & 0x8000) {
            message += " WANT BLUE BUFF";
            SendEnter();
            Sleep(50);
            SendKeys(message);
            SendEnter();
            listenVGSBOOL = false;
            selfBOOL = false;
            Sleep(200);
        }
    }

}

void listenENEMY() {
    Sleep(200);
    while (enemyBOOL) {
        if (GetKeyState('J') & 0x8000) {
            message += " IN JUNGLE";
            SendEnter();
            Sleep(50);
            SendKeys(message);
            SendEnter();
            listenVGSBOOL = false;
            enemyBOOL = false;
            Sleep(200);
        }

        if (GetKeyState('A') & 0x8000) {
            message += " NO FLASH";
            SendEnter();
            Sleep(50);
            SendKeys(message);
            SendEnter();
            listenVGSBOOL = false;
            enemyBOOL = false;
            Sleep(200);
        }

        if (GetKeyState('S') & 0x8000) {
            message += " HAS FLASH";
            SendEnter();
            Sleep(50);
            SendKeys(message);
            SendEnter();
            listenVGSBOOL = false;
            enemyBOOL = false;
            Sleep(200);
        }

        if (GetKeyState('Z') & 0x8000) {
            message += " NO SUMMS";
            SendEnter();
            Sleep(50);
            SendKeys(message);
            SendEnter();
            listenVGSBOOL = false;
            enemyBOOL = false;
            Sleep(200);
        }

        if (GetKeyState('C') & 0x8000) {
            message += " HAS SUMMS";
            SendEnter();
            Sleep(50);
            SendKeys(message);
            SendEnter();
            listenVGSBOOL = false;
            enemyBOOL = false;
            Sleep(200);
        }

        if (GetKeyState('X') & 0x8000) {
            listenVGSBOOL = false;
            enemyBOOL = false;
            Sleep(200);
        }
    }
}

void listenGANK() {
    Sleep(200);
    while (gankBOOL) {
        if (GetKeyState('1') & 0x8000) {
            message += " TOP";
            SendEnter();
            Sleep(50);
            SendKeys(message);
            SendEnter();
            listenVGSBOOL = false;
            gankBOOL = false;
            Sleep(200);
        }

        if (GetKeyState('2') & 0x8000) {
            message += " MID";
            SendEnter();
            Sleep(50);
            SendKeys(message);
            SendEnter();
            listenVGSBOOL = false;
            gankBOOL = false;
            Sleep(200);
        }

        if (GetKeyState('3') & 0x8000) {
            message += " BOT";
            SendEnter();
            Sleep(50);
            SendKeys(message);
            SendEnter();
            listenVGSBOOL = false;
            gankBOOL = false;
            Sleep(200);
        }

        if (GetKeyState('X') & 0x8000) {
            listenVGSBOOL = false;
            gankBOOL = false;
            Sleep(200);
        }
    }
}

void listenVGS() {
    while (listenVGSBOOL) {
        if (GetKeyState('A') & 0x8000) {
            message += "ATTACK";
            objBOOL = true;
            listenOBJ();
            
        }

        if (GetKeyState('C') & 0x8000) {
            message += "DEFEND";
            objBOOL = true;
            listenOBJ();

        }

        if (GetKeyState('S') & 0x8000) {
            message += "I";
            selfBOOL = true;
            listenSELF();

        }

        if (GetKeyState('B') & 0x8000) {
            message += "ENEMY";
            enemyBOOL = true;
            listenENEMY();

        }

        if (GetKeyState('G') & 0x8000) {
            message += "GANKING";
            gankBOOL = true;
            listenGANK();

        }

        if (GetKeyState('M') & 0x8000) {
            SendEnter();
            Sleep(50);
            SendKeys("NVM");
            SendEnter();
            listenVGSBOOL = false;
        }

        if (GetKeyState('X') & 0x8000) {
            listenVGSBOOL = false;

        }
    }
}



int main()
{
    bool contnu = true;
    while (contnu) {
        if (GetKeyState('V') & 0x8000) {
            listenVGSBOOL = true;
            listenVGS();
            message = "";
        }

    }
   
    return 0;
}
