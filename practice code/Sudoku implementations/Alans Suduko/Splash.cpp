//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Splash.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSplashForm *SplashForm;

//---------------------------------------------------------------------------
  const short Masks[10] = {0, 1, 2, 4, 8, 16, 32, 64, 128, 256};   // valid offsets are 1 to 9
  const short FullMask = 1+2+4+8+16+32+64+128+256;                 // all mask bits are set
  const short TYPE_ROW = 1;
  const short TYPE_COL = 2;
  const short TYPE_SQU = 3;

//---------------------------------------------------------------------------

__fastcall TSplashForm::TSplashForm(TComponent* Owner)
        : TForm(Owner)
{
  // Parameters are rows then columns
  CellNames[0][0] = Edit1;
  CellNames[0][1] = Edit2;
  CellNames[0][2] = Edit3;
  CellNames[0][3] = Edit4;
  CellNames[0][4] = Edit5;
  CellNames[0][5] = Edit6;
  CellNames[0][6] = Edit7;
  CellNames[0][7] = Edit8;
  CellNames[0][8] = Edit9;
  CellNames[1][0] = Edit10;
  CellNames[1][1] = Edit11;
  CellNames[1][2] = Edit12;
  CellNames[1][3] = Edit13;
  CellNames[1][4] = Edit14;
  CellNames[1][5] = Edit15;
  CellNames[1][6] = Edit16;
  CellNames[1][7] = Edit17;
  CellNames[1][8] = Edit18;
  CellNames[2][0] = Edit19;
  CellNames[2][1] = Edit20;
  CellNames[2][2] = Edit21;
  CellNames[2][3] = Edit22;
  CellNames[2][4] = Edit23;
  CellNames[2][5] = Edit24;
  CellNames[2][6] = Edit25;
  CellNames[2][7] = Edit26;
  CellNames[2][8] = Edit27;
  CellNames[3][0] = Edit28;
  CellNames[3][1] = Edit29;
  CellNames[3][2] = Edit30;
  CellNames[3][3] = Edit31;
  CellNames[3][4] = Edit32;
  CellNames[3][5] = Edit33;
  CellNames[3][6] = Edit34;
  CellNames[3][7] = Edit35;
  CellNames[3][8] = Edit36;
  CellNames[4][0] = Edit37;
  CellNames[4][1] = Edit38;
  CellNames[4][2] = Edit39;
  CellNames[4][3] = Edit40;
  CellNames[4][4] = Edit41;
  CellNames[4][5] = Edit42;
  CellNames[4][6] = Edit43;
  CellNames[4][7] = Edit44;
  CellNames[4][8] = Edit45;
  CellNames[5][0] = Edit46;
  CellNames[5][1] = Edit47;
  CellNames[5][2] = Edit48;
  CellNames[5][3] = Edit49;
  CellNames[5][4] = Edit50;
  CellNames[5][5] = Edit51;
  CellNames[5][6] = Edit52;
  CellNames[5][7] = Edit53;
  CellNames[5][8] = Edit54;
  CellNames[6][0] = Edit55;
  CellNames[6][1] = Edit56;
  CellNames[6][2] = Edit57;
  CellNames[6][3] = Edit58;
  CellNames[6][4] = Edit59;
  CellNames[6][5] = Edit60;
  CellNames[6][6] = Edit61;
  CellNames[6][7] = Edit62;
  CellNames[6][8] = Edit63;
  CellNames[7][0] = Edit64;
  CellNames[7][1] = Edit65;
  CellNames[7][2] = Edit66;
  CellNames[7][3] = Edit67;
  CellNames[7][4] = Edit68;
  CellNames[7][5] = Edit69;
  CellNames[7][6] = Edit70;
  CellNames[7][7] = Edit71;
  CellNames[7][8] = Edit72;
  CellNames[8][0] = Edit73;
  CellNames[8][1] = Edit74;
  CellNames[8][2] = Edit75;
  CellNames[8][3] = Edit76;
  CellNames[8][4] = Edit77;
  CellNames[8][5] = Edit78;
  CellNames[8][6] = Edit79;
  CellNames[8][7] = Edit80;
  CellNames[8][8] = Edit81;

  SplashForm->Width = 358;
  SplashForm->Height = 321;

  ClearClick((TObject*)Clear);
}
//
void __fastcall TSplashForm::ClearClick(TObject *Sender)
{
  // Clear the Suduko grid
  InitializeSudukoArrays();

  Checking = true;

  for (short row=0; row<9; row++)
  {
    for (short col=0; col<9; col++)
    {
      CellNames[row][col]->Color = clWindow;
      CellNames[row][col]->Font->Color = clRed;
      CellNames[row][col]->Text = "";
      CellMasks[row][col] = FullMask;
    }
  }
  UpdateCheckBoxes();
  Checking = false;
}
//
void __fastcall TSplashForm::Load1Click(TObject *Sender)
{
  ClearClick( (TObject*) Load1);

  CellNames[0][0]->Text = '9';
  CellNames[0][5]->Text = '6';
  CellNames[0][7]->Text = '7';
  CellNames[1][1]->Text = '3';
  CellNames[1][3]->Text = '1';
  CellNames[1][8]->Text = '5';
  CellNames[2][2]->Text = '5';
  CellNames[2][6]->Text = '3';
  CellNames[3][1]->Text = '5';
  CellNames[3][3]->Text = '4';
  CellNames[3][5]->Text = '2';
  CellNames[3][8]->Text = '3';
  CellNames[5][0]->Text = '7';
  CellNames[5][3]->Text = '8';
  CellNames[5][5]->Text = '9';
  CellNames[5][7]->Text = '5';
  CellNames[6][2]->Text = '4';
  CellNames[6][6]->Text = '8';
  CellNames[7][0]->Text = '6';
  CellNames[7][5]->Text = '7';
  CellNames[7][7]->Text = '9';
  CellNames[8][1]->Text = '1';
  CellNames[8][3]->Text = '2';
  CellNames[8][8]->Text = '6';
}

//
void __fastcall TSplashForm::Load2Click(TObject *Sender)
{
  ClearClick( (TObject*) Load2);

  CellNames[0][1]->Text = '1';
  CellNames[0][7]->Text = '8';
  CellNames[1][0]->Text = '5';
  CellNames[1][8]->Text = '2';
  CellNames[2][3]->Text = '3';
  CellNames[2][5]->Text = '6';
  CellNames[3][2]->Text = '4';
  CellNames[3][4]->Text = '8';
  CellNames[3][6]->Text = '3';
  CellNames[4][1]->Text = '7';
  CellNames[4][4]->Text = '5';
  CellNames[4][7]->Text = '1';
  CellNames[5][2]->Text = '2';
  CellNames[5][4]->Text = '1';
  CellNames[5][6]->Text = '6';
  CellNames[6][3]->Text = '2';
  CellNames[6][5]->Text = '7';
  CellNames[7][0]->Text = '8';
  CellNames[7][8]->Text = '5';
  CellNames[8][1]->Text = '3';
  CellNames[8][7]->Text = '4';
}

//
void __fastcall TSplashForm::Load3Click(TObject *Sender)
{
  ClearClick( (TObject*) Load3);

  CellNames[0][4]->Text = '6';
  CellNames[0][5]->Text = '9';
  CellNames[1][1]->Text = '8';
  CellNames[1][2]->Text = '2';
  CellNames[1][5]->Text = '7';
  CellNames[2][1]->Text = '5';
  CellNames[2][6]->Text = '3';
  CellNames[3][7]->Text = '2';
  CellNames[3][8]->Text = '8';
  CellNames[4][0]->Text = '7';
  CellNames[4][8]->Text = '5';
  CellNames[5][0]->Text = '4';
  CellNames[5][1]->Text = '6';
  CellNames[6][2]->Text = '3';
  CellNames[6][7]->Text = '7';
  CellNames[7][3]->Text = '4';
  CellNames[7][6]->Text = '6';
  CellNames[7][7]->Text = '9';
  CellNames[8][3]->Text = '5';
  CellNames[8][4]->Text = '2';
}

//
void __fastcall TSplashForm::Load4Click(TObject *Sender)
{
  ClearClick( (TObject*) Load4);

                         //0,0,0, 0,0,0, 0,0,0
  char StartGrid[9][9] = {{0,0,6, 3,0,7, 2,0,0}
                         ,{0,3,0, 0,2,0, 0,7,0}
                         ,{7,0,0, 0,0,0, 0,0,6}

                         ,{6,0,0, 0,0,0, 0,0,8}
                         ,{0,7,0, 0,5,0, 0,1,0}
                         ,{4,0,0, 0,0,0, 0,0,9}

                         ,{8,0,0, 0,0,0, 0,0,1}
                         ,{0,4,0, 0,9,0, 0,5,0}
                         ,{0,0,1, 5,0,8, 3,0,0}};

  for ( char row=0; row<9; row++)
  {
    for ( char col=0; col<9; col++)
    {
      short Entry = StartGrid[row][col];
      if ( Entry != 0 )
      {
        CellNames[row][col]->Text = Entry;
      }
    }
  }
}

//
void __fastcall TSplashForm::SaveClick(TObject *Sender)
{
  // ajt

}

//
void __fastcall TSplashForm::StartClick(TObject *Sender)
{
  bool CellFixed = true;

  Checking = true;

  // Initialise the data arrays
  InitializeSudukoArrays();

  // read the values entered by the user
  ReadSudukoArray();

  // Find solutions
  while ( CellFixed == true )
  {
    // Keep calling each rule until all of them are exhausted
    CellFixed = false;
    CellFixed = Rule1();
    CellFixed |= Rule2();
    CellFixed |= Rule3();
    CellFixed |= Rule4();
  }
  UpdateCheckBoxes();
  UpdateOptionsTable();
  Checking = false;
}
//
void __fastcall TSplashForm::Rule1TotalDblClick(TObject *Sender)
{
  Rule1Total->Text = 0;
}

void __fastcall TSplashForm::Rule2TotalDblClick(TObject *Sender)
{
  Rule2Total->Text = 0;
}

void __fastcall TSplashForm::Rule3TotalDblClick(TObject *Sender)
{
  Rule3Total->Text = 0;
}

void __fastcall TSplashForm::Rule4TotalDblClick(TObject *Sender)
{
  Rule4Total->Text = 0;
}
//
void __fastcall TSplashForm::InitClick(TObject *Sender)
{
  InitializeSudukoArrays();
  ReadSudukoArray();
}

void __fastcall TSplashForm::Rule1ButtonClick(TObject *Sender)
{
  Rule1();
}

void __fastcall TSplashForm::Rule2ButtonClick(TObject *Sender)
{
  Rule2();
}

void __fastcall TSplashForm::Rule3ButtonClick(TObject *Sender)
{
  Rule3();
}

void __fastcall TSplashForm::Rule4ButtonClick(TObject *Sender)
{
  Rule4();
}

void __fastcall TSplashForm::UpdateTableClick(TObject *Sender)
{
  UpdateOptionsTable();
}

//
void __fastcall TSplashForm::InitializeSudukoArrays()
{
  Rule1Total->Text = 0;
  Rule2Total->Text = 0;
  Rule3Total->Text = 0;
  Rule4Total->Text = 0;

  for (short row=0; row<9; row++)
  {
    for (short col=0; col<9; col++)
    {
      // update the cell mask
      CellMasks[row][col] = FullMask;
      CellValues[row][col] = 0;
      CellSolved[row][col] = false;
    }
  }
}

//
void __fastcall TSplashForm::ReadSudukoArray()
{
  // Called to read the cells entered by the user
  // Read all 81 texts into the array
  for (short row=0; row<9; row++)
  {
    for (short col=0; col<9; col++)
    {
      unsigned short Entry = CellNames[row][col]->Text.ToIntDef(0);

      // Limit to valid values
      if ( Entry > 9 )
      {
        Entry = 0;
        CellNames[row][col]->Text = "";
      }

      // Update depending on valid or invalid entry
      if ( Entry == 0 )
      {
        // invalid value
        CellNames[row][col]->Font->Color = clRed;
        CellNames[row][col]->Text = "";
      }
      else
      {
        // user has set a valid entry
        SetSudukoValue(row, col, Entry, clWindowText);
      }
    }
  }
}

//
void __fastcall TSplashForm::SetSudukoValue(short row, short col, short value, TColor color)
{
  short MaskToRemove = FullMask - Masks[value];
  short BaseRow = (row/3) * 3;
  short BaseCol = (col/3) * 3;

  // A single value has been found.
  // Update all the variables.

  // Update the display grid
  CellNames[row][col]->Font->Color = color;
  CellNames[row][col]->Text = IntToStr(value);

  // Update the data arrays
  CellValues[row][col] = value;
  CellSolved[row][col] = true;

  for (short index = 0; index < 9; index++)
  {
    // removed the item from the other cells in the row and col and rest of square
    CellMasks[row][index] &= MaskToRemove;
    CellMasks[index][col] &= MaskToRemove;
    CellMasks[BaseRow + (index/3)][BaseCol + (index%3)] &= MaskToRemove;
  }
  CellMasks[row][col] = 1 << (value-1);
}

//
//---------------------------------------------------------------------------
bool __fastcall TSplashForm::Rule1()
{
  // look for cells that only have one option left
  //
  // e.g. +-------+---+
  //      |123|   |  x|  Cell x can only be a 6 as the other
  //      |   |   | 5 |  members of the row/col/squ use all
  //      |   |   |4  |  the other values.
  //      +---+---+---+
  //      |   |   |  7|  Set cell x to value 6.
  //      |   |   |   |
  //      |   |   |  8|
  //      +---+---+---+
  //      |   |   |   |
  //      |   |   |  9|
  //      |   |   |   |
  //      +---+---+---+

  bool SolutionFound = false;

  for ( short row = 0; row < 9; row++ )
  {
    for ( short col = 0; col < 9; col++ )
    {
      // See if a unique solution is now available. NB Call checks if cell already solved.
      if ( CheckSolution(row, col, CellMasks[row][col], clRed) )
      {
        Rule1Total->Text = Rule1Total->Text.ToIntDef(0) + 1;
        SolutionFound = true;
      }
    }
  }
  return(SolutionFound);
}

//
bool __fastcall TSplashForm::CheckSolution(short row, short col, short Solution, TColor color)
{
  if ( !CellSolved[row][col] )
  {
    // Any cell can only have 1 unique solution
    // Redefine the value of Solution
    switch (Solution)
    {
      case 0:
      {
        // no possible solution
        CellNames[row][col]->Color = clRed;
        Solution = 0;
        break;
      }
      case 1:
      {
        Solution = 1;
        break;
      }
      case 2:
      {
        Solution = 2;
        break;
      }
      case 4:
      {
        Solution = 3;
        break;
      }
      case 8:
      {
        Solution = 4;
        break;
      }
      case 16:
      {
        Solution = 5;
        break;
      }
      case 32:
      {
        Solution = 6;
        break;
      }
      case 64:
      {
        Solution = 7;
        break;
      }
      case 128:
      {
        Solution = 8;
        break;
      }
      case 256:
      {
        Solution = 9;
        break;
      }
      default:
      {
        Solution = 0;
        break;
      }
    }

    if ( Solution != 0 )
    {
      // found unique solution so store with Red text
      SetSudukoValue(row, col, Solution, color);
      return(true);
    }
  }
  return(false);
}
//
bool __fastcall TSplashForm::Rule2()
{
  // look for an option that only occurs once in a row/col/squ
  //
  // e.g. +-------+---+
  //      |   |   | 5x|  Cells x can be lots of values but it is the
  //      | 6 |   |   |  only cell in the square that can be 6.
  //      |   |   | 12|
  //      +---+---+---+  Set cell x to value 6.
  //      |   |   |6  |
  //      |   |   |   |
  //      |   |   |   |
  //      +---+---+---+
  //      |   |   |   |
  //      |   |   |   |
  //      |   |   |   |
  //      +---+---+---+

  bool SolutionFound = false;

  for ( short item = 0; item < 9; item++)
  {
    // check for 1 solution in a row
    SolutionFound |= CheckExclusiveCell(item,TYPE_ROW);
    // check for 1 solution in a col
    SolutionFound |= CheckExclusiveCell(item,TYPE_COL);
    // check for 1 solution in a squ
    SolutionFound |= CheckExclusiveCell(item,TYPE_SQU);
  }
  return(SolutionFound);
}

//
bool __fastcall TSplashForm::CheckExclusiveCell(short Item, short Type)
{
  short OptionsFound = 0;
  short OptionsFoundAgain = 0;
  short Solutions;
  short row, col, squ;
  bool  SolutionFound = false;

  for ( short index = 0; index < 9; index++)
  {
    UpdateIndexes(Item, Type, index, row, col, squ);

    if ( !CellSolved[row][col] )
    {
      short CellMask = CellMasks[row][col];

      // Option found a second time if already found once and is present in this Cell as well
      // CellMask contains the possible options for this cell
      OptionsFoundAgain |= (CellMask & OptionsFound);

      // Option found at least once if set in this cell
      OptionsFound |= CellMask;
    }
  }

  // Load solutions with a bit set for each unique solution in this row
  // There may be more than one unique solution in this row
  // NB All previous solutions will also be found
  Solutions = OptionsFound & (~OptionsFoundAgain);

  if (Solutions != 0)
  {
    // there is at least one solution
    // search all 9 items again to see which cells have a unique solution
    for ( short index = 0; index < 9; index++)
    {
      UpdateIndexes(Item, Type, index, row, col, squ);

      short CellMask = ( Solutions & CellMasks[row][col] );

      if ( CellMask != 0 )
      {
        if (CheckSolution(row, col, CellMask, clLime) )
        {
          Rule2Total->Text = Rule2Total->Text.ToIntDef(0) + 1;
          SolutionFound = true;
        }
      }
    }
  }
  return(SolutionFound);
}



//
bool __fastcall TSplashForm::Rule3()
{
  // If a two options only occurs twice in a row/col/squ and the same two options occur
  // in the same two squares then no other options are possible in the same squares
  // e.g. +-------+---+
  //      |1 9|   |   |  Cells x and y must be 1 or 9. As there are only two cells
  //      |   |19 |   |  with the same two options then no other options are valid
  //      |   |   |x y|  for these cells.
  //      +---+---+---+
  //      |   |   | 1 |  Remove the other options from cells x and y.
  //      |   |   |   |
  //      |   |   |   |
  //      +---+---+---+
  //      |   |   | 9 |
  //      |   |   |   |
  //      |   |   |   |
  //      +---+---+---+

  bool SolutionFound = false;

  for ( short item = 0; item < 9; item++)
  {
    // check for 1 solution in a row
    SolutionFound |= CheckDuplicateCells(item,TYPE_ROW);
    // check for 1 solution in a col
    SolutionFound |= CheckDuplicateCells(item,TYPE_COL);
    // check for 1 solution in a squ
    SolutionFound |= CheckDuplicateCells(item,TYPE_SQU);
  }
  return(SolutionFound);
}

//
bool __fastcall TSplashForm::CheckDuplicateCells(short Item, short Type)
{
  short OptionsFoundOnce = 0;
  short OptionsFoundTwice = 0;
  short OptionsFoundAgain = 0;
  short Solutions;
  short row, col, squ;
  short row2, col2, squ2;
  bool  SolutionFound = false;

  for ( short index = 0; index < 9; index++)
  {
    UpdateIndexes(Item, Type, index, row, col, squ);

    if ( !CellSolved[row][col] )
    {
      short CellMask = CellMasks[row][col];

      // Option found at least once if set in this cell
      // Option found a second time if already found once and if present in this Cell as well
      // CellMask contains the possible options for this cell
      OptionsFoundAgain |= (CellMask & OptionsFoundTwice);
      OptionsFoundTwice |= (CellMask & OptionsFoundOnce);
      OptionsFoundOnce  |=  CellMask;
    }
  }

  // Now check for solutions that only exist in two cells and are shared with another two solutions in the same squares
  Solutions = OptionsFoundTwice & (~OptionsFoundAgain);

  // Now perform a bubble search for two cells with the same two options

  if (Solutions != 0)
  {
    // there is at least one solution
    // search all 9 items again to see which cells have a unique solution
    for ( short index = 0; index < 9; index++)
    {
      UpdateIndexes(Item, Type, index, row, col, squ);

      if (!CellSolved[row][col])
      {
        // Update CellMask with the options that were found twice in the list
        short CellMask = ( Solutions & CellMasks[row][col] );

        if ( NumberOfBits(CellMask) == 2 )
        {
          // Then this is one of the cells with two options
          for ( short index2 = 0; index2 < 9; index2++)
          {
            // search for another cell with the same two options set
            if (index != index2)
            {
              UpdateIndexes(Item, Type, index2, row2, col2, squ2);

              if (!CellSolved[row2][col2])
              {
                short CellMask2 = ( Solutions & CellMasks[row2][col2] );

                if ( ( CellMask & CellMask2) == CellMask)
                {
                  // found a second cell with the same 2 options so these two cells can ONLY be these two values
                  // so remove the other options from these cells
                  if (CellMasks[row][col] != CellMask)
                  {
                    CellMasks[row][col] = CellMask;
                    CellNames[row][col]->Color = clGreen;
                    Rule3Total->Text = Rule3Total->Text.ToIntDef(0) + 1;
                    SolutionFound = true;
                  }
                  if (CellMasks[row2][col2] != CellMask)
                  {
                    CellMasks[row2][col2] = CellMask;
                    CellNames[row2][col2]->Color = clGreen;
                    Rule3Total->Text = Rule3Total->Text.ToIntDef(0) + 1;
                    SolutionFound = true;
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  return(SolutionFound);
}

//
void __fastcall TSplashForm::UpdateIndexes(short Item, short Type, short index, short &row, short &col, short &squ)
{
  switch (Type)
  {
    case TYPE_ROW:
    {
      // check rows
      row = Item;
      col = index;
      squ = (row/3)*3 + col/3;
      break;
    }
    case TYPE_COL:
    {
      // check cols
      row = index;
      col = Item;
      squ = (row/3)*3 + col/3;
      break;
    }
    case TYPE_SQU:
    {
      // check squares
      row = ((Item/3)*3) + index/3;
      col = ((Item%3)*3) + index%3;
      squ = Item;
      break;
    }
    default:
    {
      row = 0;
      col = 0;
      squ = 0;
      CellNames[row][col]->Color = clRed;
      break;
    }
  }
}

//
short __fastcall TSplashForm::NumberOfBits(short Item)
{
  short count = 0;

  for (short index = 0; index < 16; index++)
  {
    count += (Item & 0x01);
    Item /= 2;
  }
  return(count);
}

//
void __fastcall TSplashForm::UpdateCheckBoxes()
{
  CheckBox1->Checked = CheckGroupFinished(0,2);
  CheckBox2->Checked = CheckGroupFinished(1,2);
  CheckBox3->Checked = CheckGroupFinished(2,2);
  CheckBox4->Checked = CheckGroupFinished(3,2);
  CheckBox5->Checked = CheckGroupFinished(4,2);
  CheckBox6->Checked = CheckGroupFinished(5,2);
  CheckBox7->Checked = CheckGroupFinished(6,2);
  CheckBox8->Checked = CheckGroupFinished(7,2);
  CheckBox9->Checked = CheckGroupFinished(8,2);
  CheckBox11->Checked = CheckGroupFinished(0,1);
  CheckBox12->Checked = CheckGroupFinished(1,1);
  CheckBox13->Checked = CheckGroupFinished(2,1);
  CheckBox14->Checked = CheckGroupFinished(3,1);
  CheckBox15->Checked = CheckGroupFinished(4,1);
  CheckBox16->Checked = CheckGroupFinished(5,1);
  CheckBox17->Checked = CheckGroupFinished(6,1);
  CheckBox18->Checked = CheckGroupFinished(7,1);
  CheckBox19->Checked = CheckGroupFinished(8,1);

  CheckBox10->Checked =
     ( CheckBox1->Checked
     &&CheckBox2->Checked
     &&CheckBox3->Checked
     &&CheckBox4->Checked
     &&CheckBox5->Checked
     &&CheckBox6->Checked
     &&CheckBox7->Checked
     &&CheckBox8->Checked
     &&CheckBox9->Checked
     &&CheckBox11->Checked
     &&CheckBox12->Checked
     &&CheckBox13->Checked
     &&CheckBox14->Checked
     &&CheckBox15->Checked
     &&CheckBox16->Checked
     &&CheckBox17->Checked
     &&CheckBox18->Checked
     &&CheckBox19->Checked
     );
}

//
bool __fastcall TSplashForm::CheckGroupFinished(short Item, short Type)
{
  // look for an option that only occurs once in this row/col/squ
  short OptionsFound = 0;
  short OptionsFoundAgain = 0;
  short Solutions;
  short row, col, squ;

  for ( short index = 0; index < 9; index++)
  {
    UpdateIndexes(Item, Type, index, row, col, squ);

    short CellMask = CellMasks[row][col];

    // Option found a second time if already found once and is present in this Cell as well
    // CellMask contains the possible options for this cell
    OptionsFoundAgain |= (CellMask & OptionsFound);

    // Option found at least once if set in this cell
    if ( CellSolved[row][col] )
    {
      OptionsFound |= CellMask;
    }
  }

  // Load solutions with a bit set for each unique solution in this row
  // There may be more than one unique solution in this row
  // NB All previous solutions will also be found
  Solutions = OptionsFound & (~OptionsFoundAgain);

  return(Solutions == FullMask);
}
//
void __fastcall TSplashForm::UpdateOptionsTable()
{
  for (short row=0; row<9; row++)
  {
    for (short col=0; col<9; col++)
    {
      short CellMask = CellMasks[row][col];
      AnsiString OptionText = "";

      if (CellMask & 0x001)
          OptionText += "1";
      if (CellMask & 0x002)
          OptionText += "2";
      if (CellMask & 0x004)
          OptionText += "3";
      if (CellMask & 0x008)
          OptionText += "4";
      if (CellMask & 0x010)
          OptionText += "5";
      if (CellMask & 0x020)
          OptionText += "6";
      if (CellMask & 0x040)
          OptionText += "7";
      if (CellMask & 0x080)
          OptionText += "8";
      if (CellMask & 0x100)
          OptionText+= "9";

      OptionsTable->Cells[col][row] = OptionText;
    }
  }
}

//
bool __fastcall TSplashForm::Rule4()
{
  // If two cells in a row/col/squ are limited to two options and the same two options
  // then the rest of the line can be
  // e.g. +-------+---+
  //      |1 9|   |   |  Cells x and y must be 1 or 9. As there are only two cells
  //      |   |19 |   |  with the same two options then no other options are valid
  //      |   |   |x y|  for these cells.
  //      +---+---+---+
  //      |   |   | 1 |  Remove the other options from cells x and y.
  //      |   |   |   |
  //      |   |   |   |
  //      +---+---+---+
  //      |   |   | 9 |
  //      |   |   |   |
  //      |   |   |   |
  //      +---+---+---+

  bool SolutionFound = false;

  for ( short item = 0; item < 9; item++)
  {
    // check for 1 solution in a row
    SolutionFound |= CheckForTwoOptionsCells(item,1);
    // check for 1 solution in a col
    SolutionFound |= CheckForTwoOptionsCells(item,2);
    // check for 1 solution in a squ
    SolutionFound |= CheckForTwoOptionsCells(item,3);
  }
  return(SolutionFound);
}

//
bool __fastcall TSplashForm::CheckForTwoOptionsCells(short Item, short Type)
{
  short row, col, squ;
  short row2, col2, squ2;
  short row3, col3, squ3;
  bool  SolutionFound = false;

  for ( short index = 0; index < 9; index++)
  {
    UpdateIndexes(Item, Type, index, row, col, squ);

    short CellMask = CellMasks[row][col];

    if ( NumberOfBits(CellMask) == 2 )
    {
      // found a cell with only 2 options
      // now search for another cell with the same two options
      for ( short index2 = (index+1); index2 < 9; index2++)
      {
        UpdateIndexes(Item, Type, index2, row2, col2, squ2);

        short CellMask2 = CellMasks[row2][col2];

        if ( CellMask == CellMask2 )
        {
          // then found another cell with the same 2 unique solutions in the same col/row/squ
          // remove these options from other cells in the same col/row/squ
          for ( short index3 = 0; index3 < 9; index3++)
          {
            UpdateIndexes(Item, Type, index3, row3, col3, squ3);

            if ( (!CellSolved[row3][col3])
                &&(index3 != index)
                &&(index3 != index2)
                &&(CellMasks[row3][col3] & CellMask)
                )
            {
              CellMasks[row3][col3] &= (~CellMask);
              CellNames[row3][col3]->Color = clOlive;
              Rule4Total->Text = Rule4Total->Text.ToIntDef(0) + 1;
              SolutionFound = true;
            }
          }
        }
      }
    }
  }

  return(SolutionFound);
}

