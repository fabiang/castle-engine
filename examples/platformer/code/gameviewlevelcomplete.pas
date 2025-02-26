﻿{
  Copyright 2021-2021 Andrzej Kilijański, Michalis Kamburelis.

  This file is part of "Castle Game Engine".

  "Castle Game Engine" is free software; see the file COPYING.txt,
  included in this distribution, for details about the copyright.

  "Castle Game Engine" is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  ----------------------------------------------------------------------------
}

{ View when you win. }
unit GameViewLevelComplete;

interface

uses Classes,
  CastleUIControls, CastleControls;

type
  TViewLevelComplete = class(TCastleView)
  private
    ButtonCredits: TCastleButton;

    procedure ClickCredits(Sender: TObject);
  public
    constructor Create(AOwner: TComponent); override;
    procedure Start; override;

  end;

var
  ViewLevelComplete: TViewLevelComplete;

implementation

uses CastleSoundEngine, GameViewCredits;

constructor TViewLevelComplete.Create(AOwner: TComponent);
begin
  inherited;
  DesignUrl := 'castle-data:/gameviewlevelcomplete.castle-user-interface';
end;

procedure TViewLevelComplete.ClickCredits(Sender: TObject);
begin
  Container.View := ViewCredits;
end;

procedure TViewLevelComplete.Start;
begin
  inherited;

  ButtonCredits := DesignedComponent('ButtonCredits') as TCastleButton;
  ButtonCredits.OnClick := {$ifdef FPC}@{$endif}ClickCredits;

  { Play menu music }
  SoundEngine.LoopingChannel[0].Sound := SoundEngine.SoundFromName('menu_music');
end;

end.
