{
  Copyright 2020-2022 Michalis Kamburelis.

  This file is part of "Castle Game Engine".

  "Castle Game Engine" is free software; see the file COPYING.txt,
  included in this distribution, for details about the copyright.

  "Castle Game Engine" is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  ----------------------------------------------------------------------------
}
{ Main view, where most of the application logic takes place. }
unit GameViewMain;

interface

uses Classes,
  CastleVectors, CastleComponentSerialize,
  CastleUIControls, CastleControls, CastleKeysMouse, CastleScene, CastleTimeUtils,
  X3DNodes;

type
  { Main view, where most of the application logic takes place. }
  TViewMain = class(TCastleView)
  private
    { Components designed using CGE editor, loaded from gameviewmain.castle-user-interface. }
    LabelFps: TCastleLabel;
    MainScene: TCastleScene;

    Time: TFloatTime;
    TransformBox2: TTransformNode;
    TransformBox3: TTransformNode;
    TransformBox4: TTransformNode;
  public
    constructor Create(AOwner: TComponent); override;
    procedure Start; override;
    procedure Update(const SecondsPassed: Single; var HandleInput: Boolean); override;
  end;

var
  ViewMain: TViewMain;

implementation

uses SysUtils;

{ TViewMain ----------------------------------------------------------------- }

constructor TViewMain.Create(AOwner: TComponent);
begin
  inherited;
  DesignUrl := 'castle-data:/gameviewmain.castle-user-interface';
end;

procedure TViewMain.Start;
begin
  inherited;

  { Find components, by name, that we need to access from code }
  LabelFps := DesignedComponent('LabelFps') as TCastleLabel;
  MainScene := DesignedComponent('MainScene') as TCastleScene;

  TransformBox2 := MainScene.Node(TTransformNode, 'Box2Transform') as TTransformNode;
  TransformBox3 := MainScene.Node(TTransformNode, 'Box3Transform') as TTransformNode;
  TransformBox4 := MainScene.Node(TTransformNode, 'Box4Transform') as TTransformNode;
end;

procedure TViewMain.Update(const SecondsPassed: Single; var HandleInput: Boolean);
begin
  inherited;
  { This virtual method is executed every frame.}
  LabelFps.Caption := 'FPS: ' + Container.Fps.ToString;

  Time := Time + Container.Fps.SecondsPassed;

  { Change rotation angles (4th component of the vector),
    leaving the rotation axis (XYZ components) unchanged. }
  TransformBox2.Rotation := Vector4(TransformBox2.Rotation.XYZ, Time);
  TransformBox3.Rotation := Vector4(TransformBox2.Rotation.XYZ, Time * 2);
  TransformBox4.Rotation := Vector4(TransformBox2.Rotation.XYZ, Time * 4);
end;

end.
