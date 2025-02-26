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
    function GetAddress: String;
    procedure SetAddress(const Value: String);
    function GetApplicationID: Integer;
    procedure SetApplicationID(const Value: Integer);
    function GetPort: Integer;
    procedure SetPort(const Value: Integer);
    function GetSiteID: Integer;
    procedure SetSiteID(const Value: Integer);
  public
    procedure CreateNode; override;
    class function ClassX3DType: string; override;

    strict private FFdAddress: TSFString;
    { Internal wrapper for property @link(Address). This wrapper API may change, we advise to access simpler @link(Address) instead. }
    public property FdAddress: TSFString read FFdAddress;
    {  }
    property Address: String read GetAddress write SetAddress;

    strict private FFdApplicationID: TSFInt32;
    { Internal wrapper for property @link(ApplicationID). This wrapper API may change, we advise to access simpler @link(ApplicationID) instead. }
    public property FdApplicationID: TSFInt32 read FFdApplicationID;
    {  }
    property ApplicationID: Integer read GetApplicationID write SetApplicationID;

    strict private FFdMapping: TMFNode;
    { Internal wrapper for property @link(Mapping). This wrapper API may change, we advise to access simpler @link(Mapping) instead. }
    public property FdMapping: TMFNode read FFdMapping;
    {  }
    procedure SetMapping(const Value: array of TDISEntityTypeMappingNode);

    strict private FFdPort: TSFInt32;
    { Internal wrapper for property @link(Port). This wrapper API may change, we advise to access simpler @link(Port) instead. }
    public property FdPort: TSFInt32 read FFdPort;
    {  }
    property Port: Integer read GetPort write SetPort;

    strict private FFdSiteID: TSFInt32;
    { Internal wrapper for property @link(SiteID). This wrapper API may change, we advise to access simpler @link(SiteID) instead. }
    public property FdSiteID: TSFInt32 read FFdSiteID;
    {  }
    property SiteID: Integer read GetSiteID write SetSiteID;

    strict private FEventAddedEntities: TMFNodeEvent;
    {  }
    public property EventAddedEntities: TMFNodeEvent read FEventAddedEntities;

    strict private FEventRemovedEntities: TMFNodeEvent;
    {  }
    public property EventRemovedEntities: TMFNodeEvent read FEventRemovedEntities;

{$endif read_interface}

{$ifdef read_implementation}

{ TDISEntityManagerNode ----------------------------------------------- }

function TDISEntityManagerNode.GetAddress: String;
begin
  Result := FdAddress.Value;
end;

procedure TDISEntityManagerNode.SetAddress(const Value: String);
begin
  FdAddress.Send(Value);
end;

function TDISEntityManagerNode.GetApplicationID: Integer;
begin
  Result := FdApplicationID.Value;
end;

procedure TDISEntityManagerNode.SetApplicationID(const Value: Integer);
begin
  FdApplicationID.Send(Value);
end;

procedure TDISEntityManagerNode.SetMapping(const Value: array of TDISEntityTypeMappingNode);
var
  L: Integer;
  A: array of TX3DNode;
begin
  L := High(Value) + 1;
  SetLength(A, L);
  if L > 0 then
    Move(Value[0], A[0], L * SizeOf(TDISEntityTypeMappingNode));
  FdMapping.Send(A);
end;

function TDISEntityManagerNode.GetPort: Integer;
begin
  Result := FdPort.Value;
end;

procedure TDISEntityManagerNode.SetPort(const Value: Integer);
begin
  FdPort.Send(Value);
end;

function TDISEntityManagerNode.GetSiteID: Integer;
begin
  Result := FdSiteID.Value;
end;

procedure TDISEntityManagerNode.SetSiteID(const Value: Integer);
begin
  FdSiteID.Send(Value);
end;

class function TDISEntityManagerNode.ClassX3DType: String;
begin
  Result := 'DISEntityManager';
end;

procedure TDISEntityManagerNode.CreateNode;
begin
  inherited;

  FFdAddress := TSFString.Create(Self, True, 'address', 'localhost');
   FdAddress.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdAddress);

  FFdApplicationID := TSFInt32.Create(Self, True, 'applicationID', 1);
   FdApplicationID.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdApplicationID);

  FFdMapping := TMFNode.Create(Self, True, 'mapping', [TDISEntityTypeMappingNode]);
   FdMapping.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdMapping);

  FFdPort := TSFInt32.Create(Self, True, 'port', 0);
   FdPort.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdPort);

  FFdSiteID := TSFInt32.Create(Self, True, 'siteID', 0);
   FdSiteID.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdSiteID);

  FEventAddedEntities := TMFNodeEvent.Create(Self, 'addedEntities', false);
  AddEvent(FEventAddedEntities);

  FEventRemovedEntities := TMFNodeEvent.Create(Self, 'removedEntities', false);
  AddEvent(FEventRemovedEntities);
end;

{$endif read_implementation}
