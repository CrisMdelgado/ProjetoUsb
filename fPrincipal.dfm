object frnPrincipal: TfrnPrincipal
  Left = 0
  Top = 0
  Caption = 'Uart CPP Interface'
  ClientHeight = 575
  ClientWidth = 650
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object GrupBox: TGroupBox
    Left = 1
    Top = -2
    Width = 648
    Height = 579
    Caption = 'SerialPort'
    Color = clSilver
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentBackground = False
    ParentColor = False
    ParentFont = False
    TabOrder = 0
    object Port: TLabel
      Left = 16
      Top = 24
      Width = 26
      Height = 18
      Caption = 'Port'
    end
    object Velocidade: TLabel
      Left = 16
      Top = 80
      Width = 68
      Height = 18
      Caption = 'Velocidade'
    end
    object Label1: TLabel
      Left = 16
      Top = 136
      Width = 72
      Height = 18
      Caption = 'Bit pacotes'
    end
    object Label2: TLabel
      Left = 16
      Top = 192
      Width = 63
      Height = 18
      Caption = 'Pariedade'
    end
    object Label3: TLabel
      Left = 16
      Top = 248
      Width = 5
      Height = 18
    end
    object bitParada: TLabel
      Left = 16
      Top = 248
      Width = 66
      Height = 18
      Caption = 'Bit Parada'
    end
    object Label4: TLabel
      Left = 193
      Top = 407
      Width = 18
      Height = 18
      Caption = 'RX'
    end
    object Label5: TLabel
      Left = 192
      Top = 21
      Width = 19
      Height = 18
      Caption = 'TX'
    end
    object lblStatus: TLabel
      Left = 16
      Top = 300
      Width = 104
      Height = 18
      Caption = 'Desconectado'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object corLampada: TShape
      Left = 328
      Top = 423
      Width = 65
      Height = 65
      Shape = stCircle
      Visible = False
    end
    object lblAviso: TLabel
      Left = 432
      Top = 448
      Width = 5
      Height = 18
      Visible = False
    end
    object cmbPorta: TComboBox
      Left = 16
      Top = 48
      Width = 145
      Height = 22
      Style = csOwnerDrawFixed
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object cmbVelocidade: TComboBox
      Left = 16
      Top = 104
      Width = 145
      Height = 22
      Style = csOwnerDrawFixed
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemIndex = 2
      ParentFont = False
      TabOrder = 1
      Text = '19200'
      Items.Strings = (
        '4800'
        '9600'
        '19200'
        '38400'
        '57600'
        '115200'
        '128000')
    end
    object cmbBitsDado: TComboBox
      Left = 16
      Top = 160
      Width = 145
      Height = 22
      Style = csOwnerDrawFixed
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemIndex = 0
      ParentFont = False
      TabOrder = 2
      Text = '8'
      Items.Strings = (
        '8'
        '9')
    end
    object cmbParidade: TComboBox
      Left = 16
      Top = 216
      Width = 145
      Height = 22
      Style = csOwnerDrawFixed
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemIndex = 0
      ParentFont = False
      TabOrder = 3
      Text = 'None'
      Items.Strings = (
        'None'
        'Even'
        'Odd'
        'Trass')
    end
    object cmbBitParada: TComboBox
      Left = 16
      Top = 272
      Width = 145
      Height = 22
      Style = csOwnerDrawFixed
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemIndex = 0
      ParentFont = False
      TabOrder = 4
      Text = '1'
      Items.Strings = (
        '1'
        '2')
    end
    object mmoRx: TMemo
      Left = 192
      Top = 50
      Width = 361
      Height = 351
      Lines.Strings = (
        '')
      ScrollBars = ssVertical
      TabOrder = 5
    end
    object btnLimparRX: TButton
      Left = 233
      Top = 405
      Width = 75
      Height = 25
      Caption = 'Clear RX'
      TabOrder = 6
      OnClick = btnLimparRXClick
    end
    object btnListarPorta: TButton
      Left = 16
      Top = 386
      Width = 145
      Height = 25
      Caption = 'Listar Portas'
      TabOrder = 7
      OnClick = btnListarPortaClick
    end
    object edtTx: TEdit
      Left = 232
      Top = 18
      Width = 225
      Height = 26
      TabOrder = 8
    end
    object btnEnviar: TButton
      Left = 478
      Top = 19
      Width = 75
      Height = 25
      Caption = 'Enviar'
      TabOrder = 9
      OnClick = btnEnviarClick
    end
    object btnAbrirPorta: TButton
      Left = 16
      Top = 324
      Width = 145
      Height = 25
      Caption = 'Abrir Portas'
      TabOrder = 10
      OnClick = btnAbrirPortaClick
    end
    object btnFecharPorta: TButton
      Left = 16
      Top = 355
      Width = 145
      Height = 25
      Caption = 'Fechar Portas'
      TabOrder = 11
      OnClick = btnFecharPortaClick
    end
  end
  object thread: TIdThreadComponent
    Active = False
    Loop = True
    Priority = tpHigher
    StopMode = smTerminate
    ThreadName = 'ctp_serial'
    OnRun = threadRun
    Left = 496
    Top = 96
  end
end
