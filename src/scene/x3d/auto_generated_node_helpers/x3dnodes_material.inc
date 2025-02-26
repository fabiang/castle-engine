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
    function GetAmbientTexture: TAbstractSingleTextureNode;
    procedure SetAmbientTexture(const Value: TAbstractSingleTextureNode);
    function GetAmbientTextureMapping: String;
    procedure SetAmbientTextureMapping(const Value: String);
    function GetDiffuseColor: TCastleColorRGB;
    procedure SetDiffuseColor(const Value: TCastleColorRGB);
    function GetDiffuseTexture: TAbstractSingleTextureNode;
    procedure SetDiffuseTexture(const Value: TAbstractSingleTextureNode);
    function GetDiffuseTextureMapping: String;
    procedure SetDiffuseTextureMapping(const Value: String);
    function GetOcclusionStrength: Single;
    procedure SetOcclusionStrength(const Value: Single);
    function GetOcclusionTexture: TAbstractSingleTextureNode;
    procedure SetOcclusionTexture(const Value: TAbstractSingleTextureNode);
    function GetOcclusionTextureMapping: String;
    procedure SetOcclusionTextureMapping(const Value: String);
    function GetShininess: Single;
    procedure SetShininess(const Value: Single);
    function GetShininessTexture: TAbstractSingleTextureNode;
    procedure SetShininessTexture(const Value: TAbstractSingleTextureNode);
    function GetShininessTextureMapping: String;
    procedure SetShininessTextureMapping(const Value: String);
    function GetSpecularColor: TCastleColorRGB;
    procedure SetSpecularColor(const Value: TCastleColorRGB);
    function GetSpecularTexture: TAbstractSingleTextureNode;
    procedure SetSpecularTexture(const Value: TAbstractSingleTextureNode);
    function GetSpecularTextureMapping: String;
    procedure SetSpecularTextureMapping(const Value: String);
    function GetTransparency: Single;
    procedure SetTransparency(const Value: Single);
{$ifndef CASTLE_SLIM_NODES}
    function GetFogImmune: Boolean;
    procedure SetFogImmune(const Value: Boolean);
{$endif not CASTLE_SLIM_NODES}
    function GetMirror: Single;
    procedure SetMirror(const Value: Single);
{$ifndef CASTLE_SLIM_NODES}
    function GetReflSpecularExp: Single;
    procedure SetReflSpecularExp(const Value: Single);
{$endif not CASTLE_SLIM_NODES}
{$ifndef CASTLE_SLIM_NODES}
    function GetTransSpecularExp: Single;
    procedure SetTransSpecularExp(const Value: Single);
{$endif not CASTLE_SLIM_NODES}
  public
    procedure CreateNode; override;
    class function ClassX3DType: string; override;

    strict private FFdAmbientIntensity: TSFFloat;
    { Internal wrapper for property @link(AmbientIntensity). This wrapper API may change, we advise to access simpler @link(AmbientIntensity) instead. }
    public property FdAmbientIntensity: TSFFloat read FFdAmbientIntensity;
    {  }
    property AmbientIntensity: Single read GetAmbientIntensity write SetAmbientIntensity;

    strict private FFdAmbientTexture: TSFNode;
    { Internal wrapper for property @link(AmbientTexture). This wrapper API may change, we advise to access simpler @link(AmbientTexture) instead. }
    public property FdAmbientTexture: TSFNode read FFdAmbientTexture;
    {  }
    property AmbientTexture: TAbstractSingleTextureNode read GetAmbientTexture write SetAmbientTexture;

    strict private FFdAmbientTextureMapping: TSFString;
    { Internal wrapper for property @link(AmbientTextureMapping). This wrapper API may change, we advise to access simpler @link(AmbientTextureMapping) instead. }
    public property FdAmbientTextureMapping: TSFString read FFdAmbientTextureMapping;
    {  }
    property AmbientTextureMapping: String read GetAmbientTextureMapping write SetAmbientTextureMapping;

    strict private FFdDiffuseColor: TSFColor;
    { Internal wrapper for property @link(DiffuseColor). This wrapper API may change, we advise to access simpler @link(DiffuseColor) instead. }
    public property FdDiffuseColor: TSFColor read FFdDiffuseColor;
    { The primary way to control the color of object with Phong material. The object reflects light sources depending on the angle of the surface with respect to the light source. The more directly the surface faces the light, the more diffuse light reflects. }
    property DiffuseColor: TCastleColorRGB read GetDiffuseColor write SetDiffuseColor;

    strict private FFdDiffuseTexture: TSFNode;
    { Internal wrapper for property @link(DiffuseTexture). This wrapper API may change, we advise to access simpler @link(DiffuseTexture) instead. }
    public property FdDiffuseTexture: TSFNode read FFdDiffuseTexture;
    { The primary texture to control the color of object with Phong material. The RGB channel of this texture is multiplied with @link(DiffuseColor), and alpha channel is multiplied with the opacity (1-@link(Transparency)). }
    property DiffuseTexture: TAbstractSingleTextureNode read GetDiffuseTexture write SetDiffuseTexture;

    strict private FFdDiffuseTextureMapping: TSFString;
    { Internal wrapper for property @link(DiffuseTextureMapping). This wrapper API may change, we advise to access simpler @link(DiffuseTextureMapping) instead. }
    public property FdDiffuseTextureMapping: TSFString read FFdDiffuseTextureMapping;
    {  }
    property DiffuseTextureMapping: String read GetDiffuseTextureMapping write SetDiffuseTextureMapping;

    strict private FFdOcclusionStrength: TSFFloat;
    { Internal wrapper for property @link(OcclusionStrength). This wrapper API may change, we advise to access simpler @link(OcclusionStrength) instead. }
    public property FdOcclusionStrength: TSFFloat read FFdOcclusionStrength;
    {  }
    property OcclusionStrength: Single read GetOcclusionStrength write SetOcclusionStrength;

    strict private FFdOcclusionTexture: TSFNode;
    { Internal wrapper for property @link(OcclusionTexture). This wrapper API may change, we advise to access simpler @link(OcclusionTexture) instead. }
    public property FdOcclusionTexture: TSFNode read FFdOcclusionTexture;
    {  }
    property OcclusionTexture: TAbstractSingleTextureNode read GetOcclusionTexture write SetOcclusionTexture;

    strict private FFdOcclusionTextureMapping: TSFString;
    { Internal wrapper for property @link(OcclusionTextureMapping). This wrapper API may change, we advise to access simpler @link(OcclusionTextureMapping) instead. }
    public property FdOcclusionTextureMapping: TSFString read FFdOcclusionTextureMapping;
    {  }
    property OcclusionTextureMapping: String read GetOcclusionTextureMapping write SetOcclusionTextureMapping;

    strict private FFdShininess: TSFFloat;
    { Internal wrapper for property @link(Shininess). This wrapper API may change, we advise to access simpler @link(Shininess) instead. }
    public property FdShininess: TSFFloat read FFdShininess;
    {  }
    property Shininess: Single read GetShininess write SetShininess;

    strict private FFdShininessTexture: TSFNode;
    { Internal wrapper for property @link(ShininessTexture). This wrapper API may change, we advise to access simpler @link(ShininessTexture) instead. }
    public property FdShininessTexture: TSFNode read FFdShininessTexture;
    {  }
    property ShininessTexture: TAbstractSingleTextureNode read GetShininessTexture write SetShininessTexture;

    strict private FFdShininessTextureMapping: TSFString;
    { Internal wrapper for property @link(ShininessTextureMapping). This wrapper API may change, we advise to access simpler @link(ShininessTextureMapping) instead. }
    public property FdShininessTextureMapping: TSFString read FFdShininessTextureMapping;
    {  }
    property ShininessTextureMapping: String read GetShininessTextureMapping write SetShininessTextureMapping;

    strict private FFdSpecularColor: TSFColor;
    { Internal wrapper for property @link(SpecularColor). This wrapper API may change, we advise to access simpler @link(SpecularColor) instead. }
    public property FdSpecularColor: TSFColor read FFdSpecularColor;
    { Color of specular highlight, on shiny objects. }
    property SpecularColor: TCastleColorRGB read GetSpecularColor write SetSpecularColor;

    strict private FFdSpecularTexture: TSFNode;
    { Internal wrapper for property @link(SpecularTexture). This wrapper API may change, we advise to access simpler @link(SpecularTexture) instead. }
    public property FdSpecularTexture: TSFNode read FFdSpecularTexture;
    {  }
    property SpecularTexture: TAbstractSingleTextureNode read GetSpecularTexture write SetSpecularTexture;

    strict private FFdSpecularTextureMapping: TSFString;
    { Internal wrapper for property @link(SpecularTextureMapping). This wrapper API may change, we advise to access simpler @link(SpecularTextureMapping) instead. }
    public property FdSpecularTextureMapping: TSFString read FFdSpecularTextureMapping;
    {  }
    property SpecularTextureMapping: String read GetSpecularTextureMapping write SetSpecularTextureMapping;

    strict private FFdTransparency: TSFFloat;
    { Internal wrapper for property @link(Transparency). This wrapper API may change, we advise to access simpler @link(Transparency) instead. }
    public property FdTransparency: TSFFloat read FFdTransparency;
    { Setting @name to value > 0 makes the object partially-transparent. Setting it to 1.0 makes it even invisible (but still collidable). If you want to render the object using blending (which is usually the case for partially-transparent) it is recommended to specify it explicitly using @link(TAppearanceNode.AlphaMode). }
    property Transparency: Single read GetTransparency write SetTransparency;

{$ifndef CASTLE_SLIM_NODES}
    strict private FFdFogImmune: TSFBool;
    { Internal wrapper for property @link(FogImmune). This wrapper API may change, we advise to access simpler @link(FogImmune) instead. }
    public property FdFogImmune: TSFBool read FFdFogImmune;
{$endif not CASTLE_SLIM_NODES}
{$ifndef CASTLE_SLIM_NODES}
    {  }
    property FogImmune: Boolean read GetFogImmune write SetFogImmune;
{$endif not CASTLE_SLIM_NODES}

    strict private FFdMirror: TSFFloat;
    { Internal wrapper for property @link(Mirror). This wrapper API may change, we advise to access simpler @link(Mirror) instead. }
    public property FdMirror: TSFFloat read FFdMirror;
    {  }
    property Mirror: Single read GetMirror write SetMirror;

{$ifndef CASTLE_SLIM_NODES}
    strict private FFdReflSpecular: TMFColor;
    { Internal wrapper for property @link(ReflSpecular). This wrapper API may change, we advise to access simpler @link(ReflSpecular) instead. }
    public property FdReflSpecular: TMFColor read FFdReflSpecular;
{$endif not CASTLE_SLIM_NODES}
{$ifndef CASTLE_SLIM_NODES}
    {  }
    procedure SetReflSpecular(const Value: array of TCastleColorRGB); overload;
{$endif not CASTLE_SLIM_NODES}
{$ifndef CASTLE_SLIM_NODES}
    {  }
    procedure SetReflSpecular(const Value: TVector3List); overload;
{$endif not CASTLE_SLIM_NODES}

{$ifndef CASTLE_SLIM_NODES}
    strict private FFdReflDiffuse: TMFColor;
    { Internal wrapper for property @link(ReflDiffuse). This wrapper API may change, we advise to access simpler @link(ReflDiffuse) instead. }
    public property FdReflDiffuse: TMFColor read FFdReflDiffuse;
{$endif not CASTLE_SLIM_NODES}
{$ifndef CASTLE_SLIM_NODES}
    {  }
    procedure SetReflDiffuse(const Value: array of TCastleColorRGB); overload;
{$endif not CASTLE_SLIM_NODES}
{$ifndef CASTLE_SLIM_NODES}
    {  }
    procedure SetReflDiffuse(const Value: TVector3List); overload;
{$endif not CASTLE_SLIM_NODES}

{$ifndef CASTLE_SLIM_NODES}
    strict private FFdTransSpecular: TMFColor;
    { Internal wrapper for property @link(TransSpecular). This wrapper API may change, we advise to access simpler @link(TransSpecular) instead. }
    public property FdTransSpecular: TMFColor read FFdTransSpecular;
{$endif not CASTLE_SLIM_NODES}
{$ifndef CASTLE_SLIM_NODES}
    {  }
    procedure SetTransSpecular(const Value: array of TCastleColorRGB); overload;
{$endif not CASTLE_SLIM_NODES}
{$ifndef CASTLE_SLIM_NODES}
    {  }
    procedure SetTransSpecular(const Value: TVector3List); overload;
{$endif not CASTLE_SLIM_NODES}

{$ifndef CASTLE_SLIM_NODES}
    strict private FFdTransDiffuse: TMFColor;
    { Internal wrapper for property @link(TransDiffuse). This wrapper API may change, we advise to access simpler @link(TransDiffuse) instead. }
    public property FdTransDiffuse: TMFColor read FFdTransDiffuse;
{$endif not CASTLE_SLIM_NODES}
{$ifndef CASTLE_SLIM_NODES}
    {  }
    procedure SetTransDiffuse(const Value: array of TCastleColorRGB); overload;
{$endif not CASTLE_SLIM_NODES}
{$ifndef CASTLE_SLIM_NODES}
    {  }
    procedure SetTransDiffuse(const Value: TVector3List); overload;
{$endif not CASTLE_SLIM_NODES}

{$ifndef CASTLE_SLIM_NODES}
    strict private FFdReflSpecularExp: TSFFloat;
    { Internal wrapper for property @link(ReflSpecularExp). This wrapper API may change, we advise to access simpler @link(ReflSpecularExp) instead. }
    public property FdReflSpecularExp: TSFFloat read FFdReflSpecularExp;
{$endif not CASTLE_SLIM_NODES}
{$ifndef CASTLE_SLIM_NODES}
    {  }
    property ReflSpecularExp: Single read GetReflSpecularExp write SetReflSpecularExp;
{$endif not CASTLE_SLIM_NODES}

{$ifndef CASTLE_SLIM_NODES}
    strict private FFdTransSpecularExp: TSFFloat;
    { Internal wrapper for property @link(TransSpecularExp). This wrapper API may change, we advise to access simpler @link(TransSpecularExp) instead. }
    public property FdTransSpecularExp: TSFFloat read FFdTransSpecularExp;
{$endif not CASTLE_SLIM_NODES}
{$ifndef CASTLE_SLIM_NODES}
    {  }
    property TransSpecularExp: Single read GetTransSpecularExp write SetTransSpecularExp;
{$endif not CASTLE_SLIM_NODES}

{$endif read_interface}

{$ifdef read_implementation}

{ TMaterialNode ----------------------------------------------- }

function TMaterialNode.GetAmbientIntensity: Single;
begin
  Result := FdAmbientIntensity.Value;
end;

procedure TMaterialNode.SetAmbientIntensity(const Value: Single);
begin
  FdAmbientIntensity.Send(Value);
end;

function TMaterialNode.GetAmbientTexture: TAbstractSingleTextureNode;
begin
  if FdAmbientTexture.Value is TAbstractSingleTextureNode then
    Result := TAbstractSingleTextureNode(FdAmbientTexture.Value)
  else
    Result := nil;
end;

procedure TMaterialNode.SetAmbientTexture(const Value: TAbstractSingleTextureNode);
begin
  FdAmbientTexture.Send(Value);
end;

function TMaterialNode.GetAmbientTextureMapping: String;
begin
  Result := FdAmbientTextureMapping.Value;
end;

procedure TMaterialNode.SetAmbientTextureMapping(const Value: String);
begin
  FdAmbientTextureMapping.Send(Value);
end;

function TMaterialNode.GetDiffuseColor: TCastleColorRGB;
begin
  Result := FdDiffuseColor.Value;
end;

procedure TMaterialNode.SetDiffuseColor(const Value: TCastleColorRGB);
begin
  FdDiffuseColor.Send(Value);
end;

function TMaterialNode.GetDiffuseTexture: TAbstractSingleTextureNode;
begin
  if FdDiffuseTexture.Value is TAbstractSingleTextureNode then
    Result := TAbstractSingleTextureNode(FdDiffuseTexture.Value)
  else
    Result := nil;
end;

procedure TMaterialNode.SetDiffuseTexture(const Value: TAbstractSingleTextureNode);
begin
  FdDiffuseTexture.Send(Value);
end;

function TMaterialNode.GetDiffuseTextureMapping: String;
begin
  Result := FdDiffuseTextureMapping.Value;
end;

procedure TMaterialNode.SetDiffuseTextureMapping(const Value: String);
begin
  FdDiffuseTextureMapping.Send(Value);
end;

function TMaterialNode.GetOcclusionStrength: Single;
begin
  Result := FdOcclusionStrength.Value;
end;

procedure TMaterialNode.SetOcclusionStrength(const Value: Single);
begin
  FdOcclusionStrength.Send(Value);
end;

function TMaterialNode.GetOcclusionTexture: TAbstractSingleTextureNode;
begin
  if FdOcclusionTexture.Value is TAbstractSingleTextureNode then
    Result := TAbstractSingleTextureNode(FdOcclusionTexture.Value)
  else
    Result := nil;
end;

procedure TMaterialNode.SetOcclusionTexture(const Value: TAbstractSingleTextureNode);
begin
  FdOcclusionTexture.Send(Value);
end;

function TMaterialNode.GetOcclusionTextureMapping: String;
begin
  Result := FdOcclusionTextureMapping.Value;
end;

procedure TMaterialNode.SetOcclusionTextureMapping(const Value: String);
begin
  FdOcclusionTextureMapping.Send(Value);
end;

function TMaterialNode.GetShininess: Single;
begin
  Result := FdShininess.Value;
end;

procedure TMaterialNode.SetShininess(const Value: Single);
begin
  FdShininess.Send(Value);
end;

function TMaterialNode.GetShininessTexture: TAbstractSingleTextureNode;
begin
  if FdShininessTexture.Value is TAbstractSingleTextureNode then
    Result := TAbstractSingleTextureNode(FdShininessTexture.Value)
  else
    Result := nil;
end;

procedure TMaterialNode.SetShininessTexture(const Value: TAbstractSingleTextureNode);
begin
  FdShininessTexture.Send(Value);
end;

function TMaterialNode.GetShininessTextureMapping: String;
begin
  Result := FdShininessTextureMapping.Value;
end;

procedure TMaterialNode.SetShininessTextureMapping(const Value: String);
begin
  FdShininessTextureMapping.Send(Value);
end;

function TMaterialNode.GetSpecularColor: TCastleColorRGB;
begin
  Result := FdSpecularColor.Value;
end;

procedure TMaterialNode.SetSpecularColor(const Value: TCastleColorRGB);
begin
  FdSpecularColor.Send(Value);
end;

function TMaterialNode.GetSpecularTexture: TAbstractSingleTextureNode;
begin
  if FdSpecularTexture.Value is TAbstractSingleTextureNode then
    Result := TAbstractSingleTextureNode(FdSpecularTexture.Value)
  else
    Result := nil;
end;

procedure TMaterialNode.SetSpecularTexture(const Value: TAbstractSingleTextureNode);
begin
  FdSpecularTexture.Send(Value);
end;

function TMaterialNode.GetSpecularTextureMapping: String;
begin
  Result := FdSpecularTextureMapping.Value;
end;

procedure TMaterialNode.SetSpecularTextureMapping(const Value: String);
begin
  FdSpecularTextureMapping.Send(Value);
end;

function TMaterialNode.GetTransparency: Single;
begin
  Result := FdTransparency.Value;
end;

procedure TMaterialNode.SetTransparency(const Value: Single);
begin
  FdTransparency.Send(Value);
end;

{$ifndef CASTLE_SLIM_NODES}
function TMaterialNode.GetFogImmune: Boolean;
begin
  Result := FdFogImmune.Value;
end;

procedure TMaterialNode.SetFogImmune(const Value: Boolean);
begin
  FdFogImmune.Send(Value);
end;

{$endif not CASTLE_SLIM_NODES}
function TMaterialNode.GetMirror: Single;
begin
  Result := FdMirror.Value;
end;

procedure TMaterialNode.SetMirror(const Value: Single);
begin
  FdMirror.Send(Value);
end;

{$ifndef CASTLE_SLIM_NODES}
procedure TMaterialNode.SetReflSpecular(const Value: array of TCastleColorRGB);
begin
  FdReflSpecular.Send(Value);
end;

{$endif not CASTLE_SLIM_NODES}
{$ifndef CASTLE_SLIM_NODES}
procedure TMaterialNode.SetReflSpecular(const Value: TVector3List);
begin
  FdReflSpecular.Send(Value);
end;

{$endif not CASTLE_SLIM_NODES}
{$ifndef CASTLE_SLIM_NODES}
procedure TMaterialNode.SetReflDiffuse(const Value: array of TCastleColorRGB);
begin
  FdReflDiffuse.Send(Value);
end;

{$endif not CASTLE_SLIM_NODES}
{$ifndef CASTLE_SLIM_NODES}
procedure TMaterialNode.SetReflDiffuse(const Value: TVector3List);
begin
  FdReflDiffuse.Send(Value);
end;

{$endif not CASTLE_SLIM_NODES}
{$ifndef CASTLE_SLIM_NODES}
procedure TMaterialNode.SetTransSpecular(const Value: array of TCastleColorRGB);
begin
  FdTransSpecular.Send(Value);
end;

{$endif not CASTLE_SLIM_NODES}
{$ifndef CASTLE_SLIM_NODES}
procedure TMaterialNode.SetTransSpecular(const Value: TVector3List);
begin
  FdTransSpecular.Send(Value);
end;

{$endif not CASTLE_SLIM_NODES}
{$ifndef CASTLE_SLIM_NODES}
procedure TMaterialNode.SetTransDiffuse(const Value: array of TCastleColorRGB);
begin
  FdTransDiffuse.Send(Value);
end;

{$endif not CASTLE_SLIM_NODES}
{$ifndef CASTLE_SLIM_NODES}
procedure TMaterialNode.SetTransDiffuse(const Value: TVector3List);
begin
  FdTransDiffuse.Send(Value);
end;

{$endif not CASTLE_SLIM_NODES}
{$ifndef CASTLE_SLIM_NODES}
function TMaterialNode.GetReflSpecularExp: Single;
begin
  Result := FdReflSpecularExp.Value;
end;

procedure TMaterialNode.SetReflSpecularExp(const Value: Single);
begin
  FdReflSpecularExp.Send(Value);
end;

{$endif not CASTLE_SLIM_NODES}
{$ifndef CASTLE_SLIM_NODES}
function TMaterialNode.GetTransSpecularExp: Single;
begin
  Result := FdTransSpecularExp.Value;
end;

procedure TMaterialNode.SetTransSpecularExp(const Value: Single);
begin
  FdTransSpecularExp.Send(Value);
end;

{$endif not CASTLE_SLIM_NODES}
class function TMaterialNode.ClassX3DType: String;
begin
  Result := 'Material';
end;

procedure TMaterialNode.CreateNode;
begin
  inherited;

  FFdAmbientIntensity := TSFFloat.Create(Self, True, 'ambientIntensity', 0.2);
   FdAmbientIntensity.ChangeAlways := chVisibleNonGeometry;
   FdAmbientIntensity.MustBeNonnegative := true;
  AddField(FFdAmbientIntensity);

  FFdAmbientTexture := TSFNode.Create(Self, True, 'ambientTexture', [TAbstractSingleTextureNode]);
   FdAmbientTexture.ChangeAlways := chEverything;
  AddField(FFdAmbientTexture);

  FFdAmbientTextureMapping := TSFString.Create(Self, True, 'ambientTextureMapping', '');
   FdAmbientTextureMapping.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdAmbientTextureMapping);

  FFdDiffuseColor := TSFColor.Create(Self, True, 'diffuseColor', Vector3(0.8, 0.8, 0.8));
   FdDiffuseColor.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdDiffuseColor);

  FFdDiffuseTexture := TSFNode.Create(Self, True, 'diffuseTexture', [TAbstractSingleTextureNode]);
   FdDiffuseTexture.ChangeAlways := chEverything;
  AddField(FFdDiffuseTexture);

  FFdDiffuseTextureMapping := TSFString.Create(Self, True, 'diffuseTextureMapping', '');
   FdDiffuseTextureMapping.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdDiffuseTextureMapping);

  FFdOcclusionStrength := TSFFloat.Create(Self, True, 'occlusionStrength', 1);
   FdOcclusionStrength.ChangeAlways := chVisibleNonGeometry;
   FdOcclusionStrength.MustBeNonnegative := true;
  AddField(FFdOcclusionStrength);

  FFdOcclusionTexture := TSFNode.Create(Self, True, 'occlusionTexture', [TAbstractSingleTextureNode]);
   FdOcclusionTexture.ChangeAlways := chEverything;
  AddField(FFdOcclusionTexture);

  FFdOcclusionTextureMapping := TSFString.Create(Self, True, 'occlusionTextureMapping', '');
   FdOcclusionTextureMapping.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdOcclusionTextureMapping);

  FFdShininess := TSFFloat.Create(Self, True, 'shininess', 0.2);
   FdShininess.ChangeAlways := chVisibleNonGeometry;
   FdShininess.MustBeNonnegative := true;
  AddField(FFdShininess);

  FFdShininessTexture := TSFNode.Create(Self, True, 'shininessTexture', [TAbstractSingleTextureNode]);
   FdShininessTexture.ChangeAlways := chEverything;
  AddField(FFdShininessTexture);

  FFdShininessTextureMapping := TSFString.Create(Self, True, 'shininessTextureMapping', '');
   FdShininessTextureMapping.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdShininessTextureMapping);

  FFdSpecularColor := TSFColor.Create(Self, True, 'specularColor', Vector3(0, 0, 0));
   FdSpecularColor.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdSpecularColor);

  FFdSpecularTexture := TSFNode.Create(Self, True, 'specularTexture', [TAbstractSingleTextureNode]);
   FdSpecularTexture.ChangeAlways := chEverything;
  AddField(FFdSpecularTexture);

  FFdSpecularTextureMapping := TSFString.Create(Self, True, 'specularTextureMapping', '');
   FdSpecularTextureMapping.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdSpecularTextureMapping);

  FFdTransparency := TSFFloat.Create(Self, True, 'transparency', 0);
   FdTransparency.ChangeAlways := chVisibleNonGeometry;
   FdTransparency.MustBeNonnegative := true;
  AddField(FFdTransparency);

{$ifndef CASTLE_SLIM_NODES}
  FFdFogImmune := TSFBool.Create(Self, True, 'fogImmune', false);
   FdFogImmune.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdFogImmune);
{$endif not CASTLE_SLIM_NODES}

  FFdMirror := TSFFloat.Create(Self, True, 'mirror', 0.0);
   FdMirror.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdMirror);

{$ifndef CASTLE_SLIM_NODES}
  FFdReflSpecular := TMFColor.Create(Self, True, 'reflSpecular', []);
   FdReflSpecular.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdReflSpecular);
{$endif not CASTLE_SLIM_NODES}

{$ifndef CASTLE_SLIM_NODES}
  FFdReflDiffuse := TMFColor.Create(Self, True, 'reflDiffuse', []);
   FdReflDiffuse.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdReflDiffuse);
{$endif not CASTLE_SLIM_NODES}

{$ifndef CASTLE_SLIM_NODES}
  FFdTransSpecular := TMFColor.Create(Self, True, 'transSpecular', []);
   FdTransSpecular.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdTransSpecular);
{$endif not CASTLE_SLIM_NODES}

{$ifndef CASTLE_SLIM_NODES}
  FFdTransDiffuse := TMFColor.Create(Self, True, 'transDiffuse', []);
   FdTransDiffuse.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdTransDiffuse);
{$endif not CASTLE_SLIM_NODES}

{$ifndef CASTLE_SLIM_NODES}
  FFdReflSpecularExp := TSFFloat.Create(Self, True, 'reflSpecularExp', 1000000);
   FdReflSpecularExp.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdReflSpecularExp);
{$endif not CASTLE_SLIM_NODES}

{$ifndef CASTLE_SLIM_NODES}
  FFdTransSpecularExp := TSFFloat.Create(Self, True, 'transSpecularExp', 1000000);
   FdTransSpecularExp.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdTransSpecularExp);
{$endif not CASTLE_SLIM_NODES}

  DefaultContainerField := 'material';
end;

{$endif read_implementation}
