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
    function GetAnchorPoint: TVector3;
    procedure SetAnchorPoint(const Value: TVector3);
    function GetAxis1: TVector3;
    procedure SetAxis1(const Value: TVector3);
    function GetAxis2: TVector3;
    procedure SetAxis2(const Value: TVector3);
    function GetStopBounce1: Single;
    procedure SetStopBounce1(const Value: Single);
    function GetStop1ErrorCorrection: Single;
    procedure SetStop1ErrorCorrection(const Value: Single);
    function GetStop2Bounce: Single;
    procedure SetStop2Bounce(const Value: Single);
    function GetStop2ErrorCorrection: Single;
    procedure SetStop2ErrorCorrection(const Value: Single);
  public
    procedure CreateNode; override;
    class function ClassX3DType: string; override;

    strict private FFdAnchorPoint: TSFVec3f;
    { Internal wrapper for property @link(AnchorPoint). This wrapper API may change, we advise to access simpler @link(AnchorPoint) instead. }
    public property FdAnchorPoint: TSFVec3f read FFdAnchorPoint;
    {  }
    property AnchorPoint: TVector3 read GetAnchorPoint write SetAnchorPoint;

    strict private FFdAxis1: TSFVec3f;
    { Internal wrapper for property @link(Axis1). This wrapper API may change, we advise to access simpler @link(Axis1) instead. }
    public property FdAxis1: TSFVec3f read FFdAxis1;
    {  }
    property Axis1: TVector3 read GetAxis1 write SetAxis1;

    strict private FFdAxis2: TSFVec3f;
    { Internal wrapper for property @link(Axis2). This wrapper API may change, we advise to access simpler @link(Axis2) instead. }
    public property FdAxis2: TSFVec3f read FFdAxis2;
    {  }
    property Axis2: TVector3 read GetAxis2 write SetAxis2;

    strict private FFdStopBounce1: TSFFloat;
    { Internal wrapper for property @link(StopBounce1). This wrapper API may change, we advise to access simpler @link(StopBounce1) instead. }
    public property FdStopBounce1: TSFFloat read FFdStopBounce1;
    {  }
    property StopBounce1: Single read GetStopBounce1 write SetStopBounce1;

    strict private FFdStop1ErrorCorrection: TSFFloat;
    { Internal wrapper for property @link(Stop1ErrorCorrection). This wrapper API may change, we advise to access simpler @link(Stop1ErrorCorrection) instead. }
    public property FdStop1ErrorCorrection: TSFFloat read FFdStop1ErrorCorrection;
    {  }
    property Stop1ErrorCorrection: Single read GetStop1ErrorCorrection write SetStop1ErrorCorrection;

    strict private FFdStop2Bounce: TSFFloat;
    { Internal wrapper for property @link(Stop2Bounce). This wrapper API may change, we advise to access simpler @link(Stop2Bounce) instead. }
    public property FdStop2Bounce: TSFFloat read FFdStop2Bounce;
    {  }
    property Stop2Bounce: Single read GetStop2Bounce write SetStop2Bounce;

    strict private FFdStop2ErrorCorrection: TSFFloat;
    { Internal wrapper for property @link(Stop2ErrorCorrection). This wrapper API may change, we advise to access simpler @link(Stop2ErrorCorrection) instead. }
    public property FdStop2ErrorCorrection: TSFFloat read FFdStop2ErrorCorrection;
    {  }
    property Stop2ErrorCorrection: Single read GetStop2ErrorCorrection write SetStop2ErrorCorrection;

    strict private FEventBody1AnchorPoint: TSFVec3fEvent;
    {  }
    public property EventBody1AnchorPoint: TSFVec3fEvent read FEventBody1AnchorPoint;

    strict private FEventBody1Axis: TSFVec3fEvent;
    {  }
    public property EventBody1Axis: TSFVec3fEvent read FEventBody1Axis;

    strict private FEventBody2AnchorPoint: TSFVec3fEvent;
    {  }
    public property EventBody2AnchorPoint: TSFVec3fEvent read FEventBody2AnchorPoint;

    strict private FEventBody2Axis: TSFVec3fEvent;
    {  }
    public property EventBody2Axis: TSFVec3fEvent read FEventBody2Axis;

{$endif read_interface}

{$ifdef read_implementation}

{ TUniversalJointNode ----------------------------------------------- }

function TUniversalJointNode.GetAnchorPoint: TVector3;
begin
  Result := FdAnchorPoint.Value;
end;

procedure TUniversalJointNode.SetAnchorPoint(const Value: TVector3);
begin
  FdAnchorPoint.Send(Value);
end;

function TUniversalJointNode.GetAxis1: TVector3;
begin
  Result := FdAxis1.Value;
end;

procedure TUniversalJointNode.SetAxis1(const Value: TVector3);
begin
  FdAxis1.Send(Value);
end;

function TUniversalJointNode.GetAxis2: TVector3;
begin
  Result := FdAxis2.Value;
end;

procedure TUniversalJointNode.SetAxis2(const Value: TVector3);
begin
  FdAxis2.Send(Value);
end;

function TUniversalJointNode.GetStopBounce1: Single;
begin
  Result := FdStopBounce1.Value;
end;

procedure TUniversalJointNode.SetStopBounce1(const Value: Single);
begin
  FdStopBounce1.Send(Value);
end;

function TUniversalJointNode.GetStop1ErrorCorrection: Single;
begin
  Result := FdStop1ErrorCorrection.Value;
end;

procedure TUniversalJointNode.SetStop1ErrorCorrection(const Value: Single);
begin
  FdStop1ErrorCorrection.Send(Value);
end;

function TUniversalJointNode.GetStop2Bounce: Single;
begin
  Result := FdStop2Bounce.Value;
end;

procedure TUniversalJointNode.SetStop2Bounce(const Value: Single);
begin
  FdStop2Bounce.Send(Value);
end;

function TUniversalJointNode.GetStop2ErrorCorrection: Single;
begin
  Result := FdStop2ErrorCorrection.Value;
end;

procedure TUniversalJointNode.SetStop2ErrorCorrection(const Value: Single);
begin
  FdStop2ErrorCorrection.Send(Value);
end;

class function TUniversalJointNode.ClassX3DType: String;
begin
  Result := 'UniversalJoint';
end;

procedure TUniversalJointNode.CreateNode;
begin
  inherited;

  FFdAnchorPoint := TSFVec3f.Create(Self, True, 'anchorPoint', Vector3(0, 0, 0));
   FdAnchorPoint.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdAnchorPoint);

  FFdAxis1 := TSFVec3f.Create(Self, True, 'axis1', Vector3(0, 0, 0));
   FdAxis1.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdAxis1);

  FFdAxis2 := TSFVec3f.Create(Self, True, 'axis2', Vector3(0, 0, 0));
   FdAxis2.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdAxis2);

  FFdStopBounce1 := TSFFloat.Create(Self, True, 'stopBounce1', 0);
   FdStopBounce1.ChangeAlways := chVisibleNonGeometry;
   FdStopBounce1.MustBeNonnegative := true;
  AddField(FFdStopBounce1);

  FFdStop1ErrorCorrection := TSFFloat.Create(Self, True, 'stop1ErrorCorrection', 0.8);
   FdStop1ErrorCorrection.ChangeAlways := chVisibleNonGeometry;
   FdStop1ErrorCorrection.MustBeNonnegative := true;
  AddField(FFdStop1ErrorCorrection);

  FFdStop2Bounce := TSFFloat.Create(Self, True, 'stop2Bounce', 0);
   FdStop2Bounce.ChangeAlways := chVisibleNonGeometry;
   FdStop2Bounce.MustBeNonnegative := true;
  AddField(FFdStop2Bounce);

  FFdStop2ErrorCorrection := TSFFloat.Create(Self, True, 'stop2ErrorCorrection', 0.8);
   FdStop2ErrorCorrection.ChangeAlways := chVisibleNonGeometry;
   FdStop2ErrorCorrection.MustBeNonnegative := true;
  AddField(FFdStop2ErrorCorrection);

  FEventBody1AnchorPoint := TSFVec3fEvent.Create(Self, 'body1AnchorPoint', false);
  AddEvent(FEventBody1AnchorPoint);

  FEventBody1Axis := TSFVec3fEvent.Create(Self, 'body1Axis', false);
  AddEvent(FEventBody1Axis);

  FEventBody2AnchorPoint := TSFVec3fEvent.Create(Self, 'body2AnchorPoint', false);
  AddEvent(FEventBody2AnchorPoint);

  FEventBody2Axis := TSFVec3fEvent.Create(Self, 'body2Axis', false);
  AddEvent(FEventBody2Axis);
end;

{$endif read_implementation}
