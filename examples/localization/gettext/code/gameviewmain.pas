{
  Copyright 2019-2022 Michalis Kamburelis.

  This file is part of "Castle Game Engine".

  "Castle Game Engine" is free software; see the file COPYING.txt,
  included in this distribution, for details about the copyright.

  "Castle Game Engine" is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  ----------------------------------------------------------------------------
}

{ Main user interface class.
  This implements the majority of this application functionality. }
unit GameViewMain;

interface

uses Classes, Generics.Collections,
  CastleUIControls, CastleComponentSerialize, CastleControls, CastleTimeUtils,
  X3DNodes, CastleTextureFontData, CastleScene, CastleWindow;

type
  { Main user interface class.
    This implements the majority of this application functionality. }
  TViewMain = class(TCastleView)
  strict private
    Language: string;

    { For animating rotating text. }
    LifeTime: TFloatTime;
    TextTransform: TTransformNode;

    TextNode: TTextNode;

    { Load GetText MO files for new language,
      recreate user interface to show new language (calling InitializeUserInterface). }
    procedure InitializeLanguage(const NewLanguage: string);
    procedure InitializeUserInterface;

    procedure GetFont(const FontStyle: TFontStyleNode; var Font: TTextureFontData);
    procedure ClickButtonMessage(Sender: TObject);
    procedure ClickButtonEnglish(Sender: TObject);
    procedure ClickButtonGerman(Sender: TObject);
    procedure ClickButtonPolish(Sender: TObject);
    procedure ClickButtonRussian(Sender: TObject);
    procedure ClickButtonUkrainian(Sender: TObject);
  public
    constructor Create(AOwner: TComponent); override;
    procedure Start; override;
    { Animate text rotation. }
    procedure Update(const SecondsPassed: Single;
      var HandleInput: boolean); override;
  end;

var
  ViewMain: TViewMain;

implementation

uses SysUtils,
  CastleLog, CastleURIUtils, CastleFonts,
  CastleLocalizationGetText, CastleColors, CastleViewport, CastleSystemLanguage,
  CastleVectors, CastleMessages,
  Font_DejaVuSans;

{ Translatable strings in Pascal code.
  Note that we use English as "translation id".
  But this is optional, you could as well use some internal-only ids. }
resourcestring
  Text3D = 'I am 3D Text';
  MessageText = 'I am a message!';

{ TViewMain ----------------------------------------------------------------- }

constructor TViewMain.Create(AOwner: TComponent);
begin
  inherited;
  DesignUrl := 'castle-data:/gameviewmain.castle-user-interface';
end;

procedure TViewMain.InitializeLanguage(const NewLanguage: string);
begin
  Language := NewLanguage;

  // Translate resourcestrings in code
  CastleTranslateResourceStrings('castle-data:/locale/game.' + Language + '.mo');

  // Translate all future loaded user interface
  TranslateAllDesigns('castle-data:/locale/user_interface.' + Language + '.mo');

  { Reload user interface to show new language, freeing previous UI first.
    This is the simplest way to show translated UI.

    More complicated approaches are possible if neded, e.g. you could
    avoid reloading the existing UI, and translate it using "TranslateDesign(UiRoot)".
    TextNode can also be updated without reloading, by "TextNode.SetString([Text3D])".
    You could also preserve the TCastleEdit contents around it. }
  DesignUrl := '';
  DesignUrl := 'castle-data:/gameviewmain.castle-user-interface';
  InitializeUserInterface;
end;

procedure TViewMain.InitializeUserInterface;

  function BuildScene: TX3DRootNode;
  var
    FontStyle: TFontStyleNode;
    TextShape: TShapeNode;
    Material: TUnlitMaterialNode;
  begin
    FontStyle := TFontStyleNode.Create;
    FontStyle.Justify := fjMiddle;
    FontStyle.JustifyMinor := fjMiddle;

    TextNode := TTextNode.CreateWithTransform(TextShape, TextTransform);
    TextNode.FontStyle := FontStyle;
    TextNode.Solid := false;
    TextNode.SetString([Text3D]);

    Material := TUnlitMaterialNode.Create;
    Material.EmissiveColor := YellowRGB;
    TextShape.Material := Material;

    Result := TX3DRootNode.Create;
    Result.AddChildren(TextTransform);
  end;

var
  Scene: TCastleScene;
  Viewport: TCastleViewport;
  ButtonSwitchEnglish, ButtonSwitchGerman, ButtonSwitchPolish,
    ButtonSwitchRussian, ButtonSwitchUkrainian: TCastleButton;
  ButtonMessage: TCastleButton;
begin
  Viewport := DesignedComponent('Viewport') as TCastleViewport;
  ButtonSwitchEnglish := DesignedComponent('ButtonSwitchEnglish') as TCastleButton;
  ButtonSwitchGerman := DesignedComponent('ButtonSwitchGerman') as TCastleButton;
  ButtonSwitchPolish := DesignedComponent('ButtonSwitchPolish') as TCastleButton;
  ButtonSwitchRussian := DesignedComponent('ButtonSwitchRussian') as TCastleButton;
  ButtonSwitchUkrainian := DesignedComponent('ButtonSwitchUkrainian') as TCastleButton;
  ButtonMessage := DesignedComponent('ButtonMessage') as TCastleButton;

  { build 3D view }
  Scene := TCastleScene.Create(Application);
  Scene.Load(BuildScene, true);
  Scene.ProcessEvents := true;
  Viewport.Items.Add(Scene);

  { assign callbacks }
  ButtonSwitchEnglish.OnClick := {$ifdef FPC}@{$endif} ClickButtonEnglish;
  ButtonSwitchGerman.OnClick := {$ifdef FPC}@{$endif} ClickButtonGerman;
  ButtonSwitchPolish.OnClick := {$ifdef FPC}@{$endif} ClickButtonPolish;
  ButtonSwitchRussian.OnClick := {$ifdef FPC}@{$endif} ClickButtonRussian;
  ButtonSwitchUkrainian.OnClick := {$ifdef FPC}@{$endif} ClickButtonUkrainian;
  ButtonMessage.OnClick := {$ifdef FPC}@{$endif} ClickButtonMessage;
end;

procedure TViewMain.Start;
begin
  inherited;

  { Make sure the font contains all international characters.
    TFontStyleNode.OnFont is used by TTextNode.
    Everything else uses UIFont (by default). }
  TFontStyleNode.OnFont := {$ifdef FPC}@{$endif} GetFont;
  UIFont := TCastleFont.Create(Self);
  (UIFont as TCastleFont).Load(TextureFont_DejaVuSans_50, false);
  UIFont.Size := 20;

  { initialize language, InitializeLanguage will also intialize UI }
  Language := SystemLanguage;
  { if we don't have a translation file for this language, fallback to English }
  if not URIFileExists('castle-data:/locale/game.' + Language + '.mo') then
    Language := SystemDefaultLanguage;
  InitializeLanguage(Language);
end;

procedure TViewMain.Update(const SecondsPassed: Single;
  var HandleInput: boolean);
begin
  LifeTime += SecondsPassed;
  TextTransform.Rotation := Vector4(0, 1, 0, LifeTime);
end;

procedure TViewMain.GetFont(const FontStyle: TFontStyleNode; var Font: TTextureFontData);
begin
  Font := TextureFont_DejaVuSans_50;
end;

procedure TViewMain.ClickButtonMessage(Sender: TObject);
begin
  MessageOK(Application.MainWindow, MessageText);
end;

procedure TViewMain.ClickButtonEnglish(Sender: TObject);
begin
  InitializeLanguage('en');
end;

procedure TViewMain.ClickButtonGerman(Sender: TObject);
begin
  InitializeLanguage('de');
end;

procedure TViewMain.ClickButtonPolish(Sender: TObject);
begin
  InitializeLanguage('pl');
end;

procedure TViewMain.ClickButtonRussian(Sender: TObject);
begin
  InitializeLanguage('ru');
end;

procedure TViewMain.ClickButtonUkrainian(Sender: TObject);
begin
  InitializeLanguage('ua');
end;

end.
