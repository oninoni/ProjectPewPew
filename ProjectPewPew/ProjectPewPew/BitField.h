#pragma once
class BitField
{

public:
    BitField();
    ~BitField();
};

/*
TBitField = class
private
B: array of Byte;
FSize: Integer;
FReverse: Boolean;

function GetBit(I: Integer): Boolean;
function GetByteSize: Integer;
function GetDataPointer: PByte;
procedure SetBit(I: Integer; AValue: Boolean);

procedure CheckRange(I: Integer);

property Bit[I: Integer]: Boolean read GetBit write SetBit; default;
public
constructor Create; overload;
constructor Create(Bits: Integer); overload;
destructor Destroy; override;

procedure SetSize(Bits: Integer);
function Toggle(FBit: Integer): Boolean;
procedure Clear;
procedure Fill;

procedure Invert;
procedure SetBits(ABitField: TBitField);
procedure ClearBits(ABitField: TBitField);

procedure NotFrom(ABitField: TBitField);
procedure OrFrom(ABitField1, ABitField2: TBitField);
procedure AndFrom(ABitField1, ABitField2: TBitField);
procedure XOrFrom(ABitField1, ABitField2: TBitField);

procedure Assign(ABitField: TBitField);

// use for reverse iteration
function Reversed: TBitField;

property Size: Integer read FSize;
property ByteSize: Integer read GetByteSize;
property DataPointer: PByte read GetDataPointer;

function GetEnumerator: TIterator;
end;
*/

