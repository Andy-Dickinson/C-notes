//---------------------------------------------------------------------------

#ifndef SplashH
#define SplashH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TSplashForm : public TForm
{
__published:	// IDE-managed Components
  TEdit *Edit1;
  TEdit *Edit2;
  TEdit *Edit3;
  TEdit *Edit4;
  TEdit *Edit5;
  TEdit *Edit6;
  TEdit *Edit7;
  TEdit *Edit8;
  TEdit *Edit9;
  TEdit *Edit10;
  TEdit *Edit11;
  TEdit *Edit12;
  TEdit *Edit13;
  TEdit *Edit14;
  TEdit *Edit15;
  TEdit *Edit16;
  TEdit *Edit17;
  TEdit *Edit18;
  TEdit *Edit19;
  TEdit *Edit20;
  TEdit *Edit21;
  TEdit *Edit22;
  TEdit *Edit23;
  TEdit *Edit24;
  TEdit *Edit25;
  TEdit *Edit26;
  TEdit *Edit27;
  TEdit *Edit28;
  TEdit *Edit29;
  TEdit *Edit30;
  TEdit *Edit31;
  TEdit *Edit32;
  TEdit *Edit33;
  TEdit *Edit34;
  TEdit *Edit35;
  TEdit *Edit36;
  TEdit *Edit37;
  TEdit *Edit38;
  TEdit *Edit39;
  TEdit *Edit40;
  TEdit *Edit41;
  TEdit *Edit42;
  TEdit *Edit43;
  TEdit *Edit44;
  TEdit *Edit45;
  TEdit *Edit46;
  TEdit *Edit47;
  TEdit *Edit48;
  TEdit *Edit49;
  TEdit *Edit50;
  TEdit *Edit51;
  TEdit *Edit52;
  TEdit *Edit53;
  TEdit *Edit54;
  TEdit *Edit55;
  TEdit *Edit56;
  TEdit *Edit57;
  TEdit *Edit58;
  TEdit *Edit59;
  TEdit *Edit60;
  TEdit *Edit61;
  TEdit *Edit62;
  TEdit *Edit63;
  TEdit *Edit64;
  TEdit *Edit65;
  TEdit *Edit66;
  TEdit *Edit67;
  TEdit *Edit68;
  TEdit *Edit69;
  TEdit *Edit70;
  TEdit *Edit71;
  TEdit *Edit72;
  TEdit *Edit73;
  TEdit *Edit74;
  TEdit *Edit75;
  TEdit *Edit76;
  TEdit *Edit77;
  TEdit *Edit78;
  TEdit *Edit79;
  TEdit *Edit80;
  TEdit *Edit81;
  TEdit *Rule1Total;
  TButton *Start;
  TButton *Save;
  TButton *Clear;
  TButton *Load1;
  TButton *Rule1Button;
  TButton *Init;
  TButton *Rule2Button;
  TEdit *Rule2Total;
  TButton *Rule3Button;
  TEdit *Rule3Total;
  TButton *Load2;
  TButton *Load3;
  TCheckBox *CheckBox1;
  TCheckBox *CheckBox2;
  TCheckBox *CheckBox3;
  TCheckBox *CheckBox4;
  TCheckBox *CheckBox5;
  TCheckBox *CheckBox6;
  TCheckBox *CheckBox7;
  TCheckBox *CheckBox8;
  TCheckBox *CheckBox9;
  TCheckBox *CheckBox11;
  TCheckBox *CheckBox12;
  TCheckBox *CheckBox13;
  TCheckBox *CheckBox14;
  TCheckBox *CheckBox15;
  TCheckBox *CheckBox16;
  TCheckBox *CheckBox17;
  TCheckBox *CheckBox18;
  TCheckBox *CheckBox19;
  TCheckBox *CheckBox10;
  TButton *Load4;
  TStringGrid *OptionsTable;
  TBitBtn *UpdateTable;
  TButton *Rule4Button;
  TEdit *Rule4Total;
  TLabel *OptionsTableLabel;
  void __fastcall Rule1TotalDblClick(TObject *Sender);
  void __fastcall Load1Click(TObject *Sender);
  void __fastcall ClearClick(TObject *Sender);
  void __fastcall SaveClick(TObject *Sender);
  void __fastcall StartClick(TObject *Sender);
  void __fastcall Rule1ButtonClick(TObject *Sender);
  void __fastcall InitClick(TObject *Sender);
  void __fastcall Rule2ButtonClick(TObject *Sender);
  void __fastcall Rule2TotalDblClick(TObject *Sender);
  void __fastcall Rule3ButtonClick(TObject *Sender);
  void __fastcall Rule3TotalDblClick(TObject *Sender);
  void __fastcall Load2Click(TObject *Sender);
  void __fastcall Load3Click(TObject *Sender);
  void __fastcall Load4Click(TObject *Sender);
  void __fastcall UpdateTableClick(TObject *Sender);
  void __fastcall Rule4ButtonClick(TObject *Sender);
  void __fastcall Rule4TotalDblClick(TObject *Sender);
private:	// User declarations
        TEdit *CellNames[9][9];
        bool  CellSolved[9][9];            // Set once a single value has been found or written.
        bool Checking;

        unsigned short CellMasks[9][9];    // masks show which values are possible in each cell
        unsigned short CellValues[9][9];   // Has cell value if cell is solved. 0 if not solved.

public:		// User declarations
        __fastcall TSplashForm(TComponent* Owner);

void __fastcall InitializeSudukoArrays();
void __fastcall ReadSudukoArray();
void __fastcall SetSudukoValue(short row, short col, short value, TColor color);
bool __fastcall Rule1();
bool __fastcall CheckSolution(short row, short col, short solution, TColor color);
bool __fastcall Rule2();
bool __fastcall CheckExclusiveCell(short Item, short Type);
bool __fastcall Rule3();
bool __fastcall CheckDuplicateCells(short Item, short Type);
bool __fastcall Rule4();
bool __fastcall CheckForTwoOptionsCells(short Item, short Type);

void __fastcall UpdateIndexes(short Item, short Type, short index, short &row, short &col, short &squ);
short __fastcall NumberOfBits(short Item);
void __fastcall UpdateCheckBoxes();
bool __fastcall CheckGroupFinished(short Item, short Type);
void __fastcall UpdateOptionsTable();

};
//---------------------------------------------------------------------------
extern PACKAGE TSplashForm *SplashForm;
//---------------------------------------------------------------------------
#endif
