/*classe para controle da porta serial UART
Autor:
Data: 20/10/2017
Copyrigth: CC

Descrisão:
	Hist.: 20/10/2017 - criação da classe principal
	Versão 1.0
*/

//---------------------------------------------------------------------------
#ifndef CPortaSerialH
#define CPortaSerialH

#include<Windows.h>
#include<Classes.hpp>

//---------------------------------------------------------------------------


class CPortaSerial{

	private:
		HANDLE hPorta;
		bool Aberta;
		COMMTIMEOUTS CommTimeouts;

		bool __fastcall getAberta();
		HANDLE __fastcall getHandle();

	public:
		CPortaSerial(char *tPorta);
		~CPortaSerial();

		DCB config;

		unsigned char __fastcall  ReceberByte();
		bool __fastcall TransmitirByte(unsigned char dado);
		bool __fastcall LerConfigPorta();
		bool __fastcall SetarConfigPorta();

		__property bool xAberta = {read = getAberta};
};
#endif
