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
    function GetCreaseAngle: Single;
    procedure SetCreaseAngle(const Value: Single);
  public
    procedure CreateNode; override;
    class function ClassX3DType: string; override;
    class function ForVRMLVersion(const Version: TX3DVersion): Boolean; override;

    strict private FFdVertexOrdering: TSFEnum;
    { Internal wrapper for property @link(VertexOrdering). This wrapper API may change, we advise to access simpler @link(VertexOrdering) instead. }
    public property FdVertexOrdering: TSFEnum read FFdVertexOrdering;

    strict private FFdShapeType: TSFEnum;
    { Internal wrapper for property @link(ShapeType). This wrapper API may change, we advise to access simpler @link(ShapeType) instead. }
    public property FdShapeType: TSFEnum read FFdShapeType;

    strict private FFdFaceType: TSFEnum;
    { Internal wrapper for property @link(FaceType). This wrapper API may change, we advise to access simpler @link(FaceType) instead. }
    public property FdFaceType: TSFEnum read FFdFaceType;

    strict private FFdCreaseAngle: TSFFloat;
    { Internal wrapper for property @link(CreaseAngle). This wrapper API may change, we advise to access simpler @link(CreaseAngle) instead. }
    public property FdCreaseAngle: TSFFloat read FFdCreaseAngle;
    {  }
    property CreaseAngle: Single read GetCreaseAngle write SetCreaseAngle;

{$endif read_interface}

{$ifdef read_implementation}

{ TShapeHintsNode_1 ----------------------------------------------- }

function TShapeHintsNode_1.GetCreaseAngle: Single;
begin
  Result := FdCreaseAngle.Value;
end;

procedure TShapeHintsNode_1.SetCreaseAngle(const Value: Single);
begin
  FdCreaseAngle.Send(Value);
end;

class function TShapeHintsNode_1.ForVRMLVersion(const Version: TX3DVersion): Boolean;
begin
  Result := Version.Major <= 1; // parse this node only in VRML 1.0 and Inventor files
end;

class function TShapeHintsNode_1.ClassX3DType: String;
begin
  Result := 'ShapeHints';
end;

procedure TShapeHintsNode_1.CreateNode;
begin
  inherited;

  FFdVertexOrdering := TSFEnum.Create(Self, True, 'vertexOrdering', @VertexOrderingNames1, Ord(High(VertexOrderingNames1)) + 1, VERTORDER_UNKNOWN);
   FdVertexOrdering.ChangeAlways := chVisibleVRML1State;
  AddField(FFdVertexOrdering);

  FFdShapeType := TSFEnum.Create(Self, True, 'shapeType', @ShapeTypeNames1, Ord(High(ShapeTypeNames1)) + 1, SHTYPE_UNKNOWN);
   FdShapeType.ChangeAlways := chVisibleVRML1State;
  AddField(FFdShapeType);

  FFdFaceType := TSFEnum.Create(Self, True, 'faceType', @FaceTypeNames1, Ord(High(FaceTypeNames1)) + 1, FACETYPE_CONVEX);
   FdFaceType.ChangeAlways := chVisibleVRML1State;
  AddField(FFdFaceType);

  FFdCreaseAngle := TSFFloat.Create(Self, True, 'creaseAngle', DefaultVRML1CreaseAngle);
   FdCreaseAngle.ChangeAlways := chVisibleVRML1State;
   FdCreaseAngle.Angle := true;
  AddField(FFdCreaseAngle);
end;

{$endif read_implementation}
