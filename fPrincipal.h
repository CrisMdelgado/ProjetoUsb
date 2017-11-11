//---------------------------------------------------------------------------

#ifndef fPrincipalH
#define fPrincipalH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>

#include <IdBaseComponent.hpp>
#include <IdThreadComponent.hpp>

#include <registry.hpp> //TRegistry para acessar o regedit
#include "CPortaSerial.h"
#include <Vcl.ExtCtrls.hpp>
#include "perfgrap.h"

//---------------------------------------------------------------------------
class TfrnPrincipal : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GrupBox;
	TLabel *Port;
	TLabel *Velocidade;
	TLabel *Label1;
	TComboBox *cmbPorta;
	TComboBox *cmbVelocidade;
	TComboBox *cmbBitsDado;
	TLabel *Label2;
	TComboBox *cmbParidade;
	TLabel *Label3;
	TComboBox *cmbBitParada;
	TLabel *bitParada;
	TMemo *mmoRx;
	TLabel *Label4;
	TButton *btnLimparRX;
	TButton *btnListarPorta;
	TEdit *edtTx;
	TLabel *Label5;
	TButton *btnEnviar;
	TButton *btnAbrirPorta;
	TButton *btnFecharPorta;
	TLabel *lblStatus;
	TIdThreadComponent *thread;
	TShape *corLampada;
	TLabel *lblAviso;
	void __fastcall btnListarPortaClick(TObject *Sender);
	void __fastcall btnAbrirPortaClick(TObject *Sender);
	void __fastcall btnFecharPortaClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall threadRun(TIdThreadComponent *Sender);
	void __fastcall btnEnviarClick(TObject *Sender);
	void __fastcall btnLimparRXClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations

	CPortaSerial *objPorta;
	AnsiString porta;
	AnsiString inByte;
	unsigned char ByteRec;
	unsigned char outByte[10];

    AnsiString temp_celcius;
    double milivolt, temperatura;


public:		// User declarations
	__fastcall TfrnPrincipal(TComponent* Owner);

	void ListarPortas();  //listar portas COM do sistema
	bool ConfigurarPorta(); //definir configurações de operação
};
//---------------------------------------------------------------------------
extern PACKAGE TfrnPrincipal *frnPrincipal;
//---------------------------------------------------------------------------
#endif
