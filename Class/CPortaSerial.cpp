//---------------------------------------------------------------------------

#pragma hdrstop

#include "CPortaSerial.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

CPortaSerial::CPortaSerial(char *tPorta){

	hPorta = CreateFileA(tPorta,
						GENERIC_READ |  GENERIC_WRITE,
						0,
						NULL,
						OPEN_EXISTING,
						0,
						NULL);

	if(hPorta == INVALID_HANDLE_VALUE)
		Aberta = false;

	else{
		if(GetCommTimeouts(hPorta, &CommTimeouts) == 0)
			Aberta = false;

			else{
				CommTimeouts.ReadIntervalTimeout = 10;
				CommTimeouts.ReadTotalTimeoutMultiplier = 5;
				CommTimeouts.ReadTotalTimeoutConstant = 100;

				CommTimeouts.WriteTotalTimeoutMultiplier = 5;
				CommTimeouts.ReadTotalTimeoutConstant = 100;

				if (SetCommTimeouts(hPorta, &CommTimeouts) == 0)
					Aberta = false;

				else
					Aberta = true;

			}

	}
}
//---------------------------------------------------------------------------
CPortaSerial::~CPortaSerial(){

	CloseHandle(hPorta);
	Aberta = false;
}
//---------------------------------------------------------------------------
//public
unsigned char __fastcall  CPortaSerial::ReceberByte(){

	DWORD nBytesRead;
	DWORD dwCommEvent;
	char byte=0x00;

	//SetCommMask(hPorta,EV_RXCHAR);
	//WaitCommEvent(hPorta, &dwCommEvent, 0);

	//if (dwCommEvent & EV_RXCHAR)
		ReadFile(hPorta, &byte, 1, &nBytesRead, NULL);

	return byte;


}
bool __fastcall CPortaSerial::TransmitirByte(unsigned char dado){

	DWORD nBytesWrite;
	return WriteFile(hPorta, &dado, 1, &nBytesWrite, NULL);

}

bool __fastcall CPortaSerial::LerConfigPorta(){

	return GetCommState(hPorta, &config);
}

bool __fastcall CPortaSerial::SetarConfigPorta(){

	if(!SetCommState(hPorta, &config)){
		return false;
	}
	else
		return true;
}
 //private
bool __fastcall CPortaSerial::getAberta(){

	return Aberta;
}
HANDLE __fastcall CPortaSerial::getHandle(){

	return hPorta;

}

