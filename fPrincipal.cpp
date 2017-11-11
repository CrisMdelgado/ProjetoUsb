//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fPrincipal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "perfgrap"
#pragma resource "*.dfm"
TfrnPrincipal *frnPrincipal;
//---------------------------------------------------------------------------
__fastcall TfrnPrincipal::TfrnPrincipal(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
//Listar portas COM do sistema
void TfrnPrincipal::ListarPortas(){

	TRegistry *registro = new TRegistry;
	TStringList *lista  = new TStringList;

	/*definir chave rais*/

	registro->RootKey = HKEY_LOCAL_MACHINE;

	/*abrir a chave*/
	registro->OpenKey("HARDWARE\\DEVICEMAP\\SERIALCOMM", false);

	/*Obter a lista de portas COM do sistema*/
	registro->GetValueNames(lista);

	/*limpar a lista anterior no combobox*/
	cmbPorta->Items->Clear();

	for(int i=0; i <= lista->Count-1; i++)
		cmbPorta->Items->Add(registro->ReadString(lista->Strings[i]));

	if(cmbPorta->Items->Count > 0)
		cmbPorta->ItemIndex = 0;

	registro->CloseKey();
	delete(registro,lista);

	btnFecharPorta->Enabled = false;
}
void __fastcall TfrnPrincipal::btnListarPortaClick(TObject *Sender)
{
  ListarPortas();
}
//---------------------------------------------------------------------------

void __fastcall TfrnPrincipal::btnAbrirPortaClick(TObject *Sender)
{
	porta = cmbPorta->Text;

	objPorta = new CPortaSerial(porta.c_str());

	if(objPorta->xAberta){
		if(ConfigurarPorta()){
			btnAbrirPorta->Enabled = false;
			btnFecharPorta->Enabled = true;
			lblStatus->Caption = "Conectado";
			lblStatus->Font->Color = clGreen;
			lblStatus->Alignment = taCenter;
			thread->Active = true;
		}
		else{
			ShowMessage("Não foi possivel configurar a porta");
			delete(objPorta);
		}

		edtTx->SetFocus();
	}else{
		ShowMessage("Nao foi possivel configurar a porta");
    }
}
//---------------------------------------------------------------------------

bool TfrnPrincipal::ConfigurarPorta()
{
	if(objPorta->LerConfigPorta())
	{
		 switch(cmbVelocidade->ItemIndex)
		 {
			 case 0: objPorta->config.BaudRate = CBR_4800; break;
			 case 1: objPorta->config.BaudRate = CBR_9600; break;
			 case 2: objPorta->config.BaudRate = CBR_19200; break;
			 case 3: objPorta->config.BaudRate = CBR_38400; break;
			 case 4: objPorta->config.BaudRate = CBR_57600; break;
			 case 5: objPorta->config.BaudRate = CBR_115200; break;
			 case 6: objPorta->config.BaudRate = CBR_128000; break;

			 default: break;
		 }
		 switch(cmbParidade->ItemIndex)
		 {
			 case 0: objPorta->config.Parity = NOPARITY; break;
			 case 1: objPorta->config.Parity = EVENPARITY; break;
			 case 2: objPorta->config.Parity = ODDPARITY; break;
			 case 3: objPorta->config.Parity = MARKPARITY; break;
			 default: break;
		 }
		 switch(cmbBitParada->ItemIndex)
		 {
			 case 0: objPorta->config.StopBits = ONESTOPBIT; break;
			 case 1: objPorta->config.StopBits = TWOSTOPBITS; break;
			 default: break;
		 }
		 switch(cmbBitsDado->ItemIndex)
		 {
			 case 0: objPorta->config.ByteSize = 8; break;
			 case 1: objPorta->config.ByteSize = 9; break;
		 }

		 return objPorta->SetarConfigPorta();
	}

	else
		ShowMessage("Erro fechar porta");

	return false;

}

void __fastcall TfrnPrincipal::btnFecharPortaClick(TObject *Sender)
{
	thread->Active = false;
	delete(objPorta);
	btnFecharPorta->Enabled = false;
	btnAbrirPorta->Enabled = true;
    lblStatus->Caption = "Desconectado";
	lblStatus->Font->Color = clRed;
}
//---------------------------------------------------------------------------

void __fastcall TfrnPrincipal::FormClose(TObject *Sender, TCloseAction &Action)
{
	if(thread->Active)
	{
		btnFecharPortaClick(this);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrnPrincipal::threadRun(TIdThreadComponent *Sender)
{
	if(mmoRx->Lines->Count > 50000)
		mmoRx->Clear();

	ByteRec = objPorta->ReceberByte();
   //inByte = ByteRec;

	if(ByteRec >= 1)
	{
		milivolt = (5.0 / 255.0) * ByteRec * 1e3;
		temperatura = milivolt / 10.0;

		temp_celcius = FormatFloat("0.0", temperatura) + " ºC";
		if(temp_celcius > 40.0)
		{
			corLampada->Brush->Color = clRed;
			lblAviso->Caption = "Temperatura Muito Alta!";
		}
		else if(temp_celcius >= 30.0 && temp_celcius <= 40.0)
		{
			corLampada->Brush->Color = clGreen;
			lblAviso->Caption = "Temperatura Média!";
		}
		else if(temp_celcius < 30.0)
		{
			corLampada->Brush->Color = clBlue;
    		lblAviso->Caption = "Temperatura Normal!";
		}
		mmoRx->Lines->Add(temp_celcius);
	   //	if(inByte == "\n")
		 //	mmoRx->Lines->Add(inByte);
	   //	else
		//	mmoRx->Text = mmoRx->Text + inByte;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrnPrincipal::btnEnviarClick(TObject *Sender)
{

	strcpy(outByte, AnsiString(edtTx->Text).c_str());

	if(btnAbrirPorta->Enabled == false)
	{
		if(edtTx->Text == 'B')
		{
			lblAviso->Visible = true;
			corLampada->Visible = true;
		}

		thread->Active = false;

		objPorta->TransmitirByte(outByte[0]);

		//outByte = char (edtTx->Text.c_str());

		mmoRx->Text = mmoRx->Text + "<" + edtTx->Text.SubString(0,1) + ">";

		thread->Active = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrnPrincipal::btnLimparRXClick(TObject *Sender)
{
	mmoRx->Clear();
}
//---------------------------------------------------------------------------


void __fastcall TfrnPrincipal::FormShow(TObject *Sender)
{
  ListarPortas();
}
//---------------------------------------------------------------------------




