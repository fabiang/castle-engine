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
    function GetSpeed: Single;
    procedure SetSpeed(const Value: Single);
    function GetVariation: Single;
    procedure SetVariation(const Value: Single);
    function GetMass: Single;
    procedure SetMass(const Value: Single);
    function GetSurfaceArea: Single;
    procedure SetSurfaceArea(const Value: Single);
  public
    procedure CreateNode; override;
    class function ClassX3DType: string; override;

    strict private FFdSpeed: TSFFloat;
    { Internal wrapper for property @link(Speed). This wrapper API may change, we advise to access simpler @link(Speed) instead. }
    public property FdSpeed: TSFFloat read FFdSpeed;
    {  }
    property Speed: Single read GetSpeed write SetSpeed;

    strict private FFdVariation: TSFFloat;
    { Internal wrapper for property @link(Variation). This wrapper API may change, we advise to access simpler @link(Variation) instead. }
    public property FdVariation: TSFFloat read FFdVariation;
    {  }
    property Variation: Single read GetVariation write SetVariation;

    strict private FFdMass: TSFFloat;
    { Internal wrapper for property @link(Mass). This wrapper API may change, we advise to access simpler @link(Mass) instead. }
    public property FdMass: TSFFloat read FFdMass;
    {  }
    property Mass: Single read GetMass write SetMass;

    strict private FFdSurfaceArea: TSFFloat;
    { Internal wrapper for property @link(SurfaceArea). This wrapper API may change, we advise to access simpler @link(SurfaceArea) instead. }
    public property FdSurfaceArea: TSFFloat read FFdSurfaceArea;
    {  }
    property SurfaceArea: Single read GetSurfaceArea write SetSurfaceArea;

{$endif read_interface}

{$ifdef read_implementation}

{ TAbstractParticleEmitterNode ----------------------------------------------- }

function TAbstractParticleEmitterNode.GetSpeed: Single;
begin
  Result := FdSpeed.Value;
end;

procedure TAbstractParticleEmitterNode.SetSpeed(const Value: Single);
begin
  FdSpeed.Send(Value);
end;

function TAbstractParticleEmitterNode.GetVariation: Single;
begin
  Result := FdVariation.Value;
end;

procedure TAbstractParticleEmitterNode.SetVariation(const Value: Single);
begin
  FdVariation.Send(Value);
end;

function TAbstractParticleEmitterNode.GetMass: Single;
begin
  Result := FdMass.Value;
end;

procedure TAbstractParticleEmitterNode.SetMass(const Value: Single);
begin
  FdMass.Send(Value);
end;

function TAbstractParticleEmitterNode.GetSurfaceArea: Single;
begin
  Result := FdSurfaceArea.Value;
end;

procedure TAbstractParticleEmitterNode.SetSurfaceArea(const Value: Single);
begin
  FdSurfaceArea.Send(Value);
end;

class function TAbstractParticleEmitterNode.ClassX3DType: String;
begin
  Result := 'X3DParticleEmitterNode';
end;

procedure TAbstractParticleEmitterNode.CreateNode;
begin
  inherited;

  FFdSpeed := TSFFloat.Create(Self, True, 'speed', 0);
   FdSpeed.ChangeAlways := chVisibleNonGeometry;
   FdSpeed.MustBeNonnegative := true;
  AddField(FFdSpeed);

  FFdVariation := TSFFloat.Create(Self, True, 'variation', 0.25);
   FdVariation.ChangeAlways := chVisibleNonGeometry;
   FdVariation.MustBeNonnegative := true;
  AddField(FFdVariation);

  FFdMass := TSFFloat.Create(Self, False, 'mass', 0);
   FdMass.ChangeAlways := chVisibleNonGeometry;
   FdMass.MustBeNonnegative := true;
  AddField(FFdMass);

  FFdSurfaceArea := TSFFloat.Create(Self, False, 'surfaceArea', 0);
   FdSurfaceArea.ChangeAlways := chVisibleNonGeometry;
   FdSurfaceArea.MustBeNonnegative := true;
  AddField(FFdSurfaceArea);

  DefaultContainerField := 'emitter';
end;

{$endif read_implementation}
