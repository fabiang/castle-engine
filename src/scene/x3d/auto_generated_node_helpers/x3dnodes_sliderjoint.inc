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
    function GetAxis: TVector3;
    procedure SetAxis(const Value: TVector3);
    function GetMaxSeparation: Single;
    procedure SetMaxSeparation(const Value: Single);
    function GetMinSeparation: Single;
    procedure SetMinSeparation(const Value: Single);
    function GetStopBounce: Single;
    procedure SetStopBounce(const Value: Single);
    function GetStopErrorCorrection: Single;
    procedure SetStopErrorCorrection(const Value: Single);
  public
    procedure CreateNode; override;
    class function ClassX3DType: string; override;

    strict private FFdAxis: TSFVec3f;
    { Internal wrapper for property @link(Axis). This wrapper API may change, we advise to access simpler @link(Axis) instead. }
    public property FdAxis: TSFVec3f read FFdAxis;
    {  }
    property Axis: TVector3 read GetAxis write SetAxis;

    strict private FFdMaxSeparation: TSFFloat;
    { Internal wrapper for property @link(MaxSeparation). This wrapper API may change, we advise to access simpler @link(MaxSeparation) instead. }
    public property FdMaxSeparation: TSFFloat read FFdMaxSeparation;
    {  }
    property MaxSeparation: Single read GetMaxSeparation write SetMaxSeparation;

    strict private FFdMinSeparation: TSFFloat;
    { Internal wrapper for property @link(MinSeparation). This wrapper API may change, we advise to access simpler @link(MinSeparation) instead. }
    public property FdMinSeparation: TSFFloat read FFdMinSeparation;
    {  }
    property MinSeparation: Single read GetMinSeparation write SetMinSeparation;

    strict private FFdStopBounce: TSFFloat;
    { Internal wrapper for property @link(StopBounce). This wrapper API may change, we advise to access simpler @link(StopBounce) instead. }
    public property FdStopBounce: TSFFloat read FFdStopBounce;
    {  }
    property StopBounce: Single read GetStopBounce write SetStopBounce;

    strict private FFdStopErrorCorrection: TSFFloat;
    { Internal wrapper for property @link(StopErrorCorrection). This wrapper API may change, we advise to access simpler @link(StopErrorCorrection) instead. }
    public property FdStopErrorCorrection: TSFFloat read FFdStopErrorCorrection;
    {  }
    property StopErrorCorrection: Single read GetStopErrorCorrection write SetStopErrorCorrection;

    strict private FEventSeparation: TSFFloatEvent;
    {  }
    public property EventSeparation: TSFFloatEvent read FEventSeparation;

    strict private FEventSeparationRate: TSFFloatEvent;
    {  }
    public property EventSeparationRate: TSFFloatEvent read FEventSeparationRate;

{$endif read_interface}

{$ifdef read_implementation}

{ TSliderJointNode ----------------------------------------------- }

function TSliderJointNode.GetAxis: TVector3;
begin
  Result := FdAxis.Value;
end;

procedure TSliderJointNode.SetAxis(const Value: TVector3);
begin
  FdAxis.Send(Value);
end;

function TSliderJointNode.GetMaxSeparation: Single;
begin
  Result := FdMaxSeparation.Value;
end;

procedure TSliderJointNode.SetMaxSeparation(const Value: Single);
begin
  FdMaxSeparation.Send(Value);
end;

function TSliderJointNode.GetMinSeparation: Single;
begin
  Result := FdMinSeparation.Value;
end;

procedure TSliderJointNode.SetMinSeparation(const Value: Single);
begin
  FdMinSeparation.Send(Value);
end;

function TSliderJointNode.GetStopBounce: Single;
begin
  Result := FdStopBounce.Value;
end;

procedure TSliderJointNode.SetStopBounce(const Value: Single);
begin
  FdStopBounce.Send(Value);
end;

function TSliderJointNode.GetStopErrorCorrection: Single;
begin
  Result := FdStopErrorCorrection.Value;
end;

procedure TSliderJointNode.SetStopErrorCorrection(const Value: Single);
begin
  FdStopErrorCorrection.Send(Value);
end;

class function TSliderJointNode.ClassX3DType: String;
begin
  Result := 'SliderJoint';
end;

procedure TSliderJointNode.CreateNode;
begin
  inherited;

  FFdAxis := TSFVec3f.Create(Self, True, 'axis', Vector3(0, 1, 0));
   FdAxis.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdAxis);

  FFdMaxSeparation := TSFFloat.Create(Self, True, 'maxSeparation', 1);
   FdMaxSeparation.ChangeAlways := chVisibleNonGeometry;
   FdMaxSeparation.MustBeNonnegative := true;
  AddField(FFdMaxSeparation);

  FFdMinSeparation := TSFFloat.Create(Self, True, 'minSeparation', 0);
   FdMinSeparation.ChangeAlways := chVisibleNonGeometry;
   FdMinSeparation.MustBeNonnegative := true;
  AddField(FFdMinSeparation);

  FFdStopBounce := TSFFloat.Create(Self, True, 'stopBounce', 0);
   FdStopBounce.ChangeAlways := chVisibleNonGeometry;
   FdStopBounce.MustBeNonnegative := true;
  AddField(FFdStopBounce);

  FFdStopErrorCorrection := TSFFloat.Create(Self, True, 'stopErrorCorrection', 1);
   FdStopErrorCorrection.ChangeAlways := chVisibleNonGeometry;
   FdStopErrorCorrection.MustBeNonnegative := true;
  AddField(FFdStopErrorCorrection);

  FEventSeparation := TSFFloatEvent.Create(Self, 'separation', false);
  AddEvent(FEventSeparation);

  FEventSeparationRate := TSFFloatEvent.Create(Self, 'separationRate', false);
  AddEvent(FEventSeparationRate);
end;

{$endif read_implementation}
