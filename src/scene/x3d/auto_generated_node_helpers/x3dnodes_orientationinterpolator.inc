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

    strict private FFdKeyValue: TMFRotation;
    { Internal wrapper for property @link(KeyValue). This wrapper API may change, we advise to access simpler @link(KeyValue) instead. }
    public property FdKeyValue: TMFRotation read FFdKeyValue;
    {  }
    procedure SetKeyValue(const Value: array of TVector4); overload;
    {  }
    procedure SetKeyValue(const Value: TVector4List); overload;

    strict private FEventValue_changed: TSFRotationEvent;
    {  }
    public property EventValue_changed: TSFRotationEvent read FEventValue_changed;

{$endif read_interface}

{$ifdef read_implementation}

{ TOrientationInterpolatorNode ----------------------------------------------- }

procedure TOrientationInterpolatorNode.SetKeyValue(const Value: array of TVector4);
begin
  FdKeyValue.Send(Value);
end;

procedure TOrientationInterpolatorNode.SetKeyValue(const Value: TVector4List);
begin
  FdKeyValue.Send(Value);
end;

class function TOrientationInterpolatorNode.ClassX3DType: String;
begin
  Result := 'OrientationInterpolator';
end;

procedure TOrientationInterpolatorNode.CreateNode;
begin
  inherited;

  FFdKeyValue := TMFRotation.Create(Self, True, 'keyValue', []);
   FdKeyValue.ChangeAlways := chNone;
  AddField(FFdKeyValue);

  FEventValue_changed := TSFRotationEvent.Create(Self, 'value_changed', false);
  AddEvent(FEventValue_changed);
end;

{$endif read_implementation}
