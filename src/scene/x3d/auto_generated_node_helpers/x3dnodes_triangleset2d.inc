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

  public
    procedure CreateNode; override;
    class function ClassX3DType: string; override;

    strict private FFdVertices: TMFVec2f;
    { Internal wrapper for property @link(Vertices). This wrapper API may change, we advise to access simpler @link(Vertices) instead. }
    public property FdVertices: TMFVec2f read FFdVertices;
    {  }
    procedure SetVertices(const Value: array of TVector2); overload;
    {  }
    procedure SetVertices(const Value: TVector2List); overload;

    strict private FFdSolid: TSFBool;
    { Internal wrapper for property @link(Solid). This wrapper API may change, we advise to access simpler @link(Solid) instead. }
    public property FdSolid: TSFBool read FFdSolid;

{$endif read_interface}

{$ifdef read_implementation}

{ TTriangleSet2DNode ----------------------------------------------- }

procedure TTriangleSet2DNode.SetVertices(const Value: array of TVector2);
begin
  FdVertices.Send(Value);
end;

procedure TTriangleSet2DNode.SetVertices(const Value: TVector2List);
begin
  FdVertices.Send(Value);
end;

class function TTriangleSet2DNode.ClassX3DType: String;
begin
  Result := 'TriangleSet2D';
end;

procedure TTriangleSet2DNode.CreateNode;
begin
  inherited;

  FFdVertices := TMFVec2f.Create(Self, True, 'vertices', []);
   FdVertices.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdVertices);

  FFdSolid := TSFBool.Create(Self, False, 'solid', false);
   FdSolid.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdSolid);
end;

{$endif read_implementation}
