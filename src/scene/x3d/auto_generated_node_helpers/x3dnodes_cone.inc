{ -*- buffer-read-only: t -*-

  Copyright 2015-2022 Michalis Kamburelis.

  This file is part of "Castle Game Engine".

  "Castle Game Engine" is free software; see the file COPYING.txt,
  included in this distribution, for details about the copyright.

  "Castle Game Engine" is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  ----------------------------------------------------------------------------
}

{ Automatically generated node properties.

  Do not edit this file manually!
  To add new properties:
  - add them to the text files in tools/internal/x3d-nodes-to-pascal/nodes-specification/ ,
  - and regenerate include files by running x3d-nodes-to-pascal }

{$ifdef read_interface}

  strict private
    function GetBottom: Boolean;
    procedure SetBottom(const Value: Boolean);
    function GetBottomRadius: Single;
    procedure SetBottomRadius(const Value: Single);
    function GetHeight: Single;
    procedure SetHeight(const Value: Single);
    function GetSide: Boolean;
    procedure SetSide(const Value: Boolean);
    function GetSlices: Integer;
    procedure SetSlices(const Value: Integer);
    function GetStacks: Integer;
    procedure SetStacks(const Value: Integer);
  public
    procedure CreateNode; override;
    class function ClassX3DType: string; override;

    strict private FFdBottom: TSFBool;
    { Internal wrapper for property @link(Bottom). This wrapper API may change, we advise to access simpler @link(Bottom) instead. }
    public property FdBottom: TSFBool read FFdBottom;
    {  }
    property Bottom: Boolean read GetBottom write SetBottom;

    strict private FFdBottomRadius: TSFFloat;
    { Internal wrapper for property @link(BottomRadius). This wrapper API may change, we advise to access simpler @link(BottomRadius) instead. }
    public property FdBottomRadius: TSFFloat read FFdBottomRadius;
    {  }
    property BottomRadius: Single read GetBottomRadius write SetBottomRadius;

    strict private FFdHeight: TSFFloat;
    { Internal wrapper for property @link(Height). This wrapper API may change, we advise to access simpler @link(Height) instead. }
    public property FdHeight: TSFFloat read FFdHeight;
    {  }
    property Height: Single read GetHeight write SetHeight;

    strict private FFdSide: TSFBool;
    { Internal wrapper for property @link(Side). This wrapper API may change, we advise to access simpler @link(Side) instead. }
    public property FdSide: TSFBool read FFdSide;
    {  }
    property Side: Boolean read GetSide write SetSide;

    strict private FFdSolid: TSFBool;
    { Internal wrapper for property @link(Solid). This wrapper API may change, we advise to access simpler @link(Solid) instead. }
    public property FdSolid: TSFBool read FFdSolid;

    strict private FFdTexCoord: TSFNode;
    { Internal wrapper for property @link(TexCoord). This wrapper API may change, we advise to access simpler @link(TexCoord) instead. }
    public property FdTexCoord: TSFNode read FFdTexCoord;

    strict private FFdSlices: TSFInt32;
    { Internal wrapper for property @link(Slices). This wrapper API may change, we advise to access simpler @link(Slices) instead. }
    public property FdSlices: TSFInt32 read FFdSlices;
    {  }
    property Slices: Integer read GetSlices write SetSlices;

    strict private FFdStacks: TSFInt32;
    { Internal wrapper for property @link(Stacks). This wrapper API may change, we advise to access simpler @link(Stacks) instead. }
    public property FdStacks: TSFInt32 read FFdStacks;
    {  }
    property Stacks: Integer read GetStacks write SetStacks;

{$endif read_interface}

{$ifdef read_implementation}

{ TConeNode ----------------------------------------------- }

function TConeNode.GetBottom: Boolean;
begin
  Result := FdBottom.Value;
end;

procedure TConeNode.SetBottom(const Value: Boolean);
begin
  FdBottom.Send(Value);
end;

function TConeNode.GetBottomRadius: Single;
begin
  Result := FdBottomRadius.Value;
end;

procedure TConeNode.SetBottomRadius(const Value: Single);
begin
  FdBottomRadius.Send(Value);
end;

function TConeNode.GetHeight: Single;
begin
  Result := FdHeight.Value;
end;

procedure TConeNode.SetHeight(const Value: Single);
begin
  FdHeight.Send(Value);
end;

function TConeNode.GetSide: Boolean;
begin
  Result := FdSide.Value;
end;

procedure TConeNode.SetSide(const Value: Boolean);
begin
  FdSide.Send(Value);
end;

function TConeNode.GetSlices: Integer;
begin
  Result := FdSlices.Value;
end;

procedure TConeNode.SetSlices(const Value: Integer);
begin
  FdSlices.Send(Value);
end;

function TConeNode.GetStacks: Integer;
begin
  Result := FdStacks.Value;
end;

procedure TConeNode.SetStacks(const Value: Integer);
begin
  FdStacks.Send(Value);
end;

class function TConeNode.ClassX3DType: String;
begin
  Result := 'Cone';
end;

procedure TConeNode.CreateNode;
begin
  inherited;

  FFdBottom := TSFBool.Create(Self, False, 'bottom', true);
   FdBottom.ChangeAlways := chGeometry;
  AddField(FFdBottom);

  FFdBottomRadius := TSFFloat.Create(Self, False, 'bottomRadius', 1);
   FdBottomRadius.ChangeAlways := chGeometry;
   FdBottomRadius.MustBeNonnegative := true;
  AddField(FFdBottomRadius);

  FFdHeight := TSFFloat.Create(Self, False, 'height', 2);
   FdHeight.ChangeAlways := chGeometry;
   FdHeight.MustBeNonnegative := true;
  AddField(FFdHeight);

  FFdSide := TSFBool.Create(Self, False, 'side', true);
   FdSide.ChangeAlways := chGeometry;
  AddField(FFdSide);

  FFdSolid := TSFBool.Create(Self, False, 'solid', true);
   FdSolid.ChangeAlways := chGeometry;
  AddField(FFdSolid);

  FFdTexCoord := TSFNode.Create(Self, True, 'texCoord', [TTextureCoordinateGeneratorNode, TProjectedTextureCoordinateNode, TMultiGeneratedTextureCoordinateNode]);
   FdTexCoord.ChangeAlways := chGeometry;
  AddField(FFdTexCoord);

  FFdSlices := TSFInt32.Create(Self, True, 'slices', -1);
   FdSlices.ChangeAlways := chGeometry;
  AddField(FFdSlices);

  FFdStacks := TSFInt32.Create(Self, True, 'stacks', -1);
   FdStacks.ChangeAlways := chGeometry;
  AddField(FFdStacks);
end;

{$endif read_implementation}
