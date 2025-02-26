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
    function GetAmbientIntensity: Single;
    procedure SetAmbientIntensity(const Value: Single);
    function GetColor: TCastleColorRGB;
    procedure SetColor(const Value: TCastleColorRGB);
    function GetGlobal: Boolean;
    procedure SetGlobal(const Value: Boolean);
    function GetIntensity: Single;
    procedure SetIntensity(const Value: Single);
    function GetIsOn: Boolean;
    procedure SetIsOn(const Value: Boolean);
    function GetShadowVolumes: Boolean;
    procedure SetShadowVolumes(const Value: Boolean);
  public
    procedure CreateNode; override;
    class function ClassX3DType: string; override;

    strict private FFdAmbientIntensity: TSFFloat;
    { Internal wrapper for property @link(AmbientIntensity). This wrapper API may change, we advise to access simpler @link(AmbientIntensity) instead. }
    public property FdAmbientIntensity: TSFFloat read FFdAmbientIntensity;
    {  }
    property AmbientIntensity: Single read GetAmbientIntensity write SetAmbientIntensity;

    strict private FFdColor: TSFColor;
    { Internal wrapper for property @link(Color). This wrapper API may change, we advise to access simpler @link(Color) instead. }
    public property FdColor: TSFColor read FFdColor;
    {  }
    property Color: TCastleColorRGB read GetColor write SetColor;

    strict private FFdGlobal: TSFBool;
    { Internal wrapper for property @link(Global). This wrapper API may change, we advise to access simpler @link(Global) instead. }
    public property FdGlobal: TSFBool read FFdGlobal;
    {  }
    property Global: Boolean read GetGlobal write SetGlobal;

    strict private FFdIntensity: TSFFloat;
    { Internal wrapper for property @link(Intensity). This wrapper API may change, we advise to access simpler @link(Intensity) instead. }
    public property FdIntensity: TSFFloat read FFdIntensity;
    {  }
    property Intensity: Single read GetIntensity write SetIntensity;

    strict private FFdOn: TSFBool;
    { Internal wrapper for property @link(IsOn). This wrapper API may change, we advise to access simpler @link(IsOn) instead. }
    public property FdOn: TSFBool read FFdOn;
    {  }
    property IsOn: Boolean read GetIsOn write SetIsOn;

    strict private FFdEffects: TMFNode;
    { Internal wrapper for property @link(Effects). This wrapper API may change, we advise to access simpler @link(Effects) instead. }
    public property FdEffects: TMFNode read FFdEffects;
    {  }
    procedure SetEffects(const Value: array of TEffectNode);

    strict private FFdShadowVolumes: TSFBool;
    { Internal wrapper for property @link(ShadowVolumes). This wrapper API may change, we advise to access simpler @link(ShadowVolumes) instead. }
    public property FdShadowVolumes: TSFBool read FFdShadowVolumes;
    {  }
    property ShadowVolumes: Boolean read GetShadowVolumes write SetShadowVolumes;

{$endif read_interface}

{$ifdef read_implementation}

{ TAbstractLightNode ----------------------------------------------- }

function TAbstractLightNode.GetAmbientIntensity: Single;
begin
  Result := FdAmbientIntensity.Value;
end;

procedure TAbstractLightNode.SetAmbientIntensity(const Value: Single);
begin
  FdAmbientIntensity.Send(Value);
end;

function TAbstractLightNode.GetColor: TCastleColorRGB;
begin
  Result := FdColor.Value;
end;

procedure TAbstractLightNode.SetColor(const Value: TCastleColorRGB);
begin
  FdColor.Send(Value);
end;

function TAbstractLightNode.GetGlobal: Boolean;
begin
  Result := FdGlobal.Value;
end;

procedure TAbstractLightNode.SetGlobal(const Value: Boolean);
begin
  FdGlobal.Send(Value);
end;

function TAbstractLightNode.GetIntensity: Single;
begin
  Result := FdIntensity.Value;
end;

procedure TAbstractLightNode.SetIntensity(const Value: Single);
begin
  FdIntensity.Send(Value);
end;

function TAbstractLightNode.GetIsOn: Boolean;
begin
  Result := FdOn.Value;
end;

procedure TAbstractLightNode.SetIsOn(const Value: Boolean);
begin
  FdOn.Send(Value);
end;

procedure TAbstractLightNode.SetEffects(const Value: array of TEffectNode);
var
  L: Integer;
  A: array of TX3DNode;
begin
  L := High(Value) + 1;
  SetLength(A, L);
  if L > 0 then
    Move(Value[0], A[0], L * SizeOf(TEffectNode));
  FdEffects.Send(A);
end;

function TAbstractLightNode.GetShadowVolumes: Boolean;
begin
  Result := FdShadowVolumes.Value;
end;

procedure TAbstractLightNode.SetShadowVolumes(const Value: Boolean);
begin
  FdShadowVolumes.Send(Value);
end;

class function TAbstractLightNode.ClassX3DType: String;
begin
  Result := 'X3DLightNode';
end;

procedure TAbstractLightNode.CreateNode;
begin
  inherited;

  FFdAmbientIntensity := TSFFloat.Create(Self, True, 'ambientIntensity', 0);
   FdAmbientIntensity.ChangeAlways := chVisibleNonGeometry;
   FdAmbientIntensity.MustBeNonnegative := true;
  AddField(FFdAmbientIntensity);

  FFdColor := TSFColor.Create(Self, True, 'color', Vector3(1, 1, 1));
   FdColor.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdColor);

  FFdGlobal := TSFBool.Create(Self, True, 'global', false);
   FdGlobal.ChangeAlways := chEverything;
  AddField(FFdGlobal);

  FFdIntensity := TSFFloat.Create(Self, True, 'intensity', 1);
   FdIntensity.ChangeAlways := chVisibleNonGeometry;
   FdIntensity.MustBeNonnegative := true;
  AddField(FFdIntensity);

  FFdOn := TSFBool.Create(Self, True, 'on', true);
   FdOn.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdOn);

  FFdEffects := TMFNode.Create(Self, False, 'effects', [TEffectNode]);
   FdEffects.ChangeAlways := chEverything;
  AddField(FFdEffects);

  FFdShadowVolumes := TSFBool.Create(Self, True, 'shadowVolumes', false);
   FdShadowVolumes.ChangeAlways := chLightForShadowVolumes;
  AddField(FFdShadowVolumes);
end;

{$endif read_implementation}
