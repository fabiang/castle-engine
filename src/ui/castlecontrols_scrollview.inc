{%MainUnit castlecontrols.pas}
{
  Copyright 2010-2022 Michalis Kamburelis.

  This file is part of "Castle Game Engine".

  "Castle Game Engine" is free software; see the file COPYING.txt,
  included in this distribution, for details about the copyright.

  "Castle Game Engine" is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  ----------------------------------------------------------------------------
}

{$ifdef read_interface}

  { Abstract user interface with a scrollbar.
    In most cases you want to use @link(TCastleScrollView) in your application,
    which is a more comfortable descendant of this class. }
  TCastleScrollViewCustom = class(TCastleUserInterface)
  strict private
    FScroll: Single;
    FScrollbarVisible: Boolean;
    { Rects in screen coordinates (like RenderRect),
      after UI scaling and anchors. }
    ScrollbarFrame, ScrollbarSlider: TFloatRectangle;
    ScrollBarDragging: Boolean;
    FKeyScrollSpeed, FWheelScrollSpeed: Single;
    FScrollBarWidth: Single;
    FEnableDragging: Boolean;
    DragSinceLastUpdate, DragSpeed, TimeSinceDraggingStopped, TimeSinceDraggingStarted: Double;
    ScrollbarActive: Single;
    FTintScrollBarInactive: TCastleColor;
    procedure SetScroll(Value: Single);
    { Stop any movement due to inertial force. }
    procedure ResetInertialForce;
  protected
    FScrollbarLeft: Boolean;

    procedure DoScrollChange; virtual;

    property ScrollbarVisible: Boolean read FScrollbarVisible;

    { How much @link(Scroll) is represented by the height of the scrollbar slider.
      Among other things, this determines how much @link(Scroll) changes
      in response to Page Up and Page Down keys. }
    function GetPageSize: Single; virtual; abstract;

    { How much @link(Scroll) is represented by the height of the entire scrollbar
      (that is, the height of this @link(TCastleScrollViewCustom) instance). }
    function GetCompleteSize: Single; virtual; abstract;
  public
    const
      DefaultKeyScrollSpeed = 200.0;
      DefaultWheelScrollSpeed = 20.0;

    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure RenderOverChildren; override;
    function Press(const Event: TInputPressRelease): boolean; override;
    function Release(const Event: TInputPressRelease): boolean; override;
    function PreviewPress(const Event: TInputPressRelease): boolean; override;
    function Motion(const Event: TInputMotion): boolean; override;
    procedure Update(const SecondsPassed: Single;
      var HandleInput: boolean); override;

    { Color and alpha tint to use when scrollbar is not used.
      May have some alpha, which makes scrollbar "make itself more opaque",
      and thus noticeable, when you start dragging.
      By default it's opaque white, which means that no tint is shown. }
    property TintScrollBarInactive: TCastleColor read FTintScrollBarInactive write FTintScrollBarInactive;

    { Scroll bar width, either from @link(ScrollBarWidth) or
      @link(TCastleTheme.ScrollBarWidth Theme.ScrollBarWidth). }
    function EffectiveScrollBarWidth: Single;

    { Minimum sensible value for @link(Scroll), corresponds to scrollbar slider at the top. }
    function ScrollMin: Single;

    { Maximum sensible value for @link(Scroll), corresponds to scrollbar slider at the bottom. }
    function ScrollMax: Single;
  published
    { Speed of scrolling by arrow keys, in pixels (before UI scaling) per second. }
    property KeyScrollSpeed: Single read FKeyScrollSpeed write FKeyScrollSpeed {$ifdef FPC}default DefaultKeyScrollSpeed{$endif};
    { Speed of scrolling by mouse wheel, in pixels (before UI scaling) per event. }
    property WheelScrollSpeed: Single read FWheelScrollSpeed write FWheelScrollSpeed {$ifdef FPC}default DefaultWheelScrollSpeed{$endif};
    { Width of the scroll bar.
      Value of 0 means to use global default
      in @link(TCastleTheme.ScrollBarWidth Theme.ScrollBarWidth). }
    property ScrollBarWidth: Single read FScrollBarWidth write FScrollBarWidth {$ifdef FPC}default 0{$endif};
    { Position of the scroll bar.
      @definitionList(
        @itemLabel(@false)
        @item(Scroll bar is located on the right side of the ScrollView.)
        @itemLabel(@true)
        @item(Scroll bar is located on the left side of the ScrollView.
          Pay attention, that additional space is not reserved for the scroll bar automatically,
          you have to specify ScrollArea.Translation.X manually,
          e.g. @code(ScrollArea.Translation := Vector2(ScrollBarWidth + Gap, ScrollArea.Translation.Y)).
        )
      ) }
    property ScrollBarLeft: Boolean read FScrollBarLeft write FScrollBarLeft default false;
    { Enable scrolling by dragging @italic(anywhere) in the scroll area.
      This is usually suitable for mobile devices.
      Note that this doesn't affect the dragging directly by the scrollbar,
      which is always enabled. }
    property EnableDragging: Boolean read FEnableDragging write FEnableDragging default false;

    { How much do we scroll.
      Setting it always clamps the value to a sensible range,
      between @link(ScrollMin) and @link(ScrollMax).

      In case of @link(TCastleScrollView),
      setting this moves the @link(TCastleScrollView.ScrollArea) vertical anchor,
      effectively moving the scrolled children.
      As such, it is expressed in unscaled pixels
      (just like @link(TCastleUserInterface.Translation),
      @link(TCastleUserInterface.Height),
      @link(TCastleUserInterface.EffectiveHeight)...).

      In case of @link(TCastleScrollViewManual),
      it can correspond to anything you want.
      You handle @link(TCastleScrollViewManual.OnChange) yourself,
      and interpret this value in whatever way you want. }
    property Scroll: Single read FScroll write SetScroll {$ifdef FPC}default 0{$endif};

  {$define read_interface_class}
  {$I auto_generated_persistent_vectors/tcastlescrollviewcustom_persistent_vectors.inc}
  {$undef read_interface_class}
  end;

  { @exclude Internal class to represent @link(TCastleScrollView.ScrollArea). }
  TInternalCastleScrollArea = class(TCastleUserInterface)
    { Do not store VerticalAnchorXxx properties, they should be only controlled
      using @link(TCastleScrollViewCustom.Scroll).
      Note: we cannot prevent storing (duplicated in this case)
      Translation.Y value. }
    property VerticalAnchorSelf stored false;
    property VerticalAnchorParent stored false;
  end;

  { Container for a user interface children that can be scrolled vertically.
    Add the children (that should be scrolled) to the @link(ScrollArea).
    We automatically show a scrollbar, and handle various scrolling inputs
    to be functional on both desktops and mobile
    (we handle scrolling by keys, mouse wheel, dragging by scrollbar,
    dragging the whole area - see @link(EnableDragging)). }
  TCastleScrollView = class(TCastleScrollViewCustom)
  strict private
    FScrollArea: TInternalCastleScrollArea;
  protected
    function GetPageSize: Single; override;
    function GetCompleteSize: Single; override;
    procedure DoScrollChange; override;
  public
    constructor Create(AOwner: TComponent); override;
  published
    { Scroll view rendering makes sense only when ClipChildren is @true. }
    property ClipChildren default true;

    { Children you add here will be scrolled.
      To have a useful scrolling area:

      @unorderedList(
        @itemSpacing compact
        @item(Add some children to ScrollArea,)
        @item(Set proper size of the ScrollArea (you can set an explicit size,
          or use @link(TCastleUserInterface.AutoSizeToChildren)),)
        @item(Leave the ScrollArea anchors as default: ScrollArea should be
          anchored to the top-left corner of the parent.)
      ) }
    property ScrollArea: TInternalCastleScrollArea read FScrollArea;
  end;

  { Control with a scrollbar.
    This user interface control shows a vertical scrollbar on the right side,
    and allows to operate on it using keyboard, mouse, touch.

    The scrollbar automatically doesn't affect anything
    (hence the name of this class contains the word "manual").
    You need to assign @link(OnChange) event to react to the scrollbar
    dragging to actually do something.
    Usually you also want to adjust @link(PageSize) and @link(CompleteSize).

    If you want to easily scroll a tall user interface contents,
    it is easier to use @link(TCastleScrollView) than this control. }
  TCastleScrollViewManual = class(TCastleScrollViewCustom)
  strict private
    FOnChange: TNotifyEvent;
    FPageSize, FCompleteSize: Single;
    procedure SetPageSize(const AValue: Single);
    procedure SetCompleteSize(const AValue: Single);
  protected
    function GetPageSize: Single; override;
    function GetCompleteSize: Single; override;
    procedure DoScrollChange; override;
  public
    const
      DefaultPageSize = 1;
      DefaultCompleteSize = 10;

    constructor Create(AOwner: TComponent); override;
  published
    { Event sent when @link(Scroll) value was changed, in any way. }
    property OnChange: TNotifyEvent read FOnChange write FOnChange;

    { How much @link(Scroll) is represented by the height of the scrollbar slider.
      Among other things, this determines how much @link(Scroll) changes
      in response to Page Up and Page Down keys. }
    property PageSize: Single read GetPageSize write SetPageSize {$ifdef FPC}default DefaultPageSize{$endif};

    { How much @link(Scroll) is represented by the height of the entire scrollbar
      (that is, the height of this @link(TCastleScrollViewCustom) instance). }
    property CompleteSize: Single read GetCompleteSize write SetCompleteSize {$ifdef FPC}default DefaultCompleteSize{$endif};
  end;

{$endif read_interface}

{$ifdef read_implementation}

{ TCastleScrollViewCustom ---------------------------------------------------------- }

constructor TCastleScrollViewCustom.Create(AOwner: TComponent);
begin
  inherited;

  FKeyScrollSpeed := DefaultKeyScrollSpeed;
  FWheelScrollSpeed := DefaultWheelScrollSpeed;
  FTintScrollBarInactive := White;

  {$define read_implementation_constructor}
  {$I auto_generated_persistent_vectors/tcastlescrollviewcustom_persistent_vectors.inc}
  {$undef read_implementation_constructor}
end;

destructor TCastleScrollViewCustom.Destroy;
begin
  {$define read_implementation_destructor}
  {$I auto_generated_persistent_vectors/tcastlescrollviewcustom_persistent_vectors.inc}
  {$undef read_implementation_destructor}
  inherited;
end;

procedure TCastleScrollViewCustom.RenderOverChildren;
var
  Color: TCastleColor;
begin
  if ScrollBarVisible then
  begin
    Color := Lerp(ScrollbarActive, TintScrollBarInactive, White);
    Theme.Draw(ScrollbarFrame, tiScrollbarFrame, UIScale, Color);
    Theme.Draw(ScrollbarSlider, tiScrollbarSlider, UIScale, Color);
  end;
  inherited;
end;

procedure TCastleScrollViewCustom.DoScrollChange;
begin
end;

procedure TCastleScrollViewCustom.SetScroll(Value: Single);
begin
  ClampVar(Value, ScrollMin, ScrollMax);
  if FScroll <> Value then
  begin
    FScroll := Value;
    DoScrollChange;
  end;
end;

procedure TCastleScrollViewCustom.ResetInertialForce;
begin
  DragSpeed := 0;
  TimeSinceDraggingStopped := 0;
end;

procedure TCastleScrollViewCustom.Update(const SecondsPassed: Single;
  var HandleInput: boolean);

  { Calculate ScrollBarVisible, ScrollbarFrame, ScrollbarFrame }
  procedure UpdateScrollBarVisibleAndRects;
  var
    SR: TFloatRectangle;
  begin
    SR := RenderRect;

    if FScrollbarLeft then
      ScrollbarFrame := SR.LeftPart(EffectiveScrollBarWidth * UIScale)
    else
      ScrollbarFrame := SR.RightPart(EffectiveScrollBarWidth * UIScale);

    ScrollbarSlider := ScrollbarFrame;
    if GetCompleteSize = 0 then
      FScrollBarVisible := false
    else
    begin
      ScrollbarSlider.Height := GetPageSize * SR.Height / GetCompleteSize;
      ScrollbarSlider.Height := Max(
        Theme.MinimumScrollbarSliderHeight * UIScale, ScrollbarSlider.Height);
      // limit ScrollbarSlider.Height to not be taller then this control
      ScrollbarSlider.Height := Min(
        EffectiveHeightForChildren * UIScale, ScrollbarSlider.Height);

      FScrollBarVisible := ScrollbarFrame.Height > ScrollbarSlider.Height + SingleEpsilon;
      { equivalent would be to set
          ScrollBarVisible := GetPageSize < GetCompleteSize;
        But this way makes it clear that MapRange below is valid,
        it will not divide by zero. }
    end;
    if FScrollBarVisible then
    begin
      { above calculation of FScrollBarVisible must guarantee this. }
      Assert(ScrollbarFrame.Height > ScrollbarSlider.Height);
      ScrollbarSlider.Bottom := ScrollbarSlider.Bottom +
        (MapRange(Scroll, ScrollMin, ScrollMax,
          ScrollbarFrame.Height - ScrollbarSlider.Height, 0));
    end else
    begin
      ScrollBarDragging := false;
      Scroll := ScrollMin; // make sure to shift to ScrollMin if scroll suddenly disappears
      ScrollbarActive := 0;
      ResetInertialForce;
    end;
  end;

  procedure HandleKeys;
  begin
    if ScrollBarVisible and HandleInput then
    begin
      if Container.Pressed[ keyArrowUp] or
         Container.Pressed[keyNumpadUp] then
      begin
        Scroll := Scroll - KeyScrollSpeed * SecondsPassed;
        ResetInertialForce;
      end;
      if Container.Pressed[ keyArrowDown] or
         Container.Pressed[keyNumpadDown] then
      begin
        Scroll := Scroll + KeyScrollSpeed * SecondsPassed;
        ResetInertialForce;
      end;
      HandleInput := not ExclusiveEvents;
    end;
  end;

  { Make the illusion of "inertial force" when dragging, by gradually
    decelerating dragging speed once user stops dragging.
    Also updates TimeSinceDraggingStopped. }
  procedure DraggingInertialForce;
  const
    DragDecelerationDuration = 0.5;
  var
    CurrentDragSpeed: Single;
  begin
    if ScrollbarVisible then
    begin
      if buttonLeft in Container.MousePressed then
      begin
        { note that we update DragSpeed even when DragSinceLastUpdate = 0,
          which means user keeps pressing but doesn't drag }
        if not IsZero(SecondsPassed) then
          DragSpeed := DragSinceLastUpdate / SecondsPassed else
          DragSpeed := 0; // whatever sensible value
        TimeSinceDraggingStopped := 0;
      end else
      begin
        TimeSinceDraggingStopped := TimeSinceDraggingStopped + SecondsPassed;
        if (DragSpeed <> 0) and
           (TimeSinceDraggingStopped < DragDecelerationDuration) then
        begin
          CurrentDragSpeed := MapRange(
            TimeSinceDraggingStopped, 0, DragDecelerationDuration,
            DragSpeed, 0);
          Scroll := Scroll + CurrentDragSpeed * SecondsPassed;
          { stop inertial force if you reached the border of scroll }
          if CurrentDragSpeed > 0 then
          begin
            if Scroll = ScrollMax then TimeSinceDraggingStopped := DragDecelerationDuration;
          end else
          begin
            if Scroll = ScrollMin then TimeSinceDraggingStopped := DragDecelerationDuration;
          end;
        end;
      end;
      DragSinceLastUpdate := 0;
    end;
  end;

  { Update ScrollbarActive, TimeSinceDraggingStarted }
  procedure UpdateScrollBarActive;
  const
    AppearTime = 0.5;
    DisappearTime = 0.5;
  var
    NewScrollbarActive: Single;
  begin
    { update TimeSinceDragginStarted }
    if TimeSinceDraggingStopped = 0 then
    begin
      { dragging now }
      TimeSinceDraggingStarted := TimeSinceDraggingStarted + SecondsPassed;
      if TimeSinceDraggingStarted > AppearTime then
        NewScrollbarActive := 1 else
        NewScrollbarActive := TimeSinceDraggingStarted / AppearTime;
    end else
    begin
      { not dragging now }
      TimeSinceDraggingStarted := 0;
      if TimeSinceDraggingStopped > DisappearTime then
        NewScrollbarActive := 0 else
        NewScrollbarActive := 1 - TimeSinceDraggingStopped / DisappearTime;
    end;
    if ScrollbarActive <> NewScrollbarActive then
    begin
      ScrollbarActive := NewScrollbarActive;
      VisibleChange([chRender]);
    end;
  end;

begin
  inherited;
  UpdateScrollBarVisibleAndRects;
  HandleKeys;
  DraggingInertialForce;
  UpdateScrollBarActive;
end;

function TCastleScrollViewCustom.PreviewPress(const Event: TInputPressRelease): boolean;
begin
  Result := inherited;
  if Result then Exit;

  { Process clicks in PreviewPress,
    since we draw ScrollbarFrame in RenderOverChildren.
    So clicking on ScrollbarFrame should be captured, before passing them
    to children (e.g. TCastleButton inside ScrollArea). }

  if ScrollBarVisible and
     Event.IsMouseButton(buttonLeft) and
     ScrollbarFrame.Contains(Event.Position) then
  begin
    if Event.Position[1] < ScrollbarSlider.Bottom then
    begin
      Scroll := Scroll + GetPageSize;
      ResetInertialForce;
    end else
    if Event.Position[1] >= ScrollbarSlider.Top then
    begin
      Scroll := Scroll - GetPageSize;
      ResetInertialForce;
    end else
      ScrollBarDragging := true;
    Exit(ExclusiveEvents);
  end;
end;

function TCastleScrollViewCustom.Press(const Event: TInputPressRelease): boolean;
begin
  Result := inherited;
  if Result then Exit;

  { if not ScrollBarVisible then there is no point in changing Scroll.

    This way we allow TStateDialog (that uses TDialog that uses TCastleScrollViewCustom)
    descendants like TStateDialogKey to handle keys and mouse wheel.
    And this is very good for MessageKey,
    when it's used e.g. to allow user to choose any TKey.
    Otherwise MessageKey would not be able to return
    keyPageDown, keyPageUp, etc. keys. }

  if ScrollBarVisible then
    case Event.EventType of
      itKey:
        case Event.Key of
          keyPageUp, keyNumpadPageUp:
            begin
              Scroll := Scroll - GetPageSize;
              ResetInertialForce;
              Result := ExclusiveEvents;
            end;
          keyPageDown, keyNumpadPageDown:
            begin
              Scroll := Scroll + GetPageSize;
              ResetInertialForce;
              Result := ExclusiveEvents;
            end;
          keyHome, keyNumpadHome:
            begin
              Scroll := ScrollMin;
              ResetInertialForce;
              Result := ExclusiveEvents;
            end;
          keyEnd, keyNumpadEnd:
            begin
              Scroll := ScrollMax;
              ResetInertialForce;
              Result := ExclusiveEvents;
            end;
          else ;
        end;
      itMouseWheel:
        if Event.MouseWheelVertical then
        begin
          Scroll := Scroll - Event.MouseWheelScroll * WheelScrollSpeed;
          ResetInertialForce;
          Result := ExclusiveEvents;
        end;
      else ;
    end;

  { We do not process mouse button clicks (or touches) here
    (not on an entire TCastleScrollViewCustom area -- the code in PreviewPress
    handles clicks inside ScrollbarFrame only).
    We only process dragging (with buttonLeft) inside TCastleScrollViewCustom.Update
    and TCastleScrollViewCustom.Motion.

    But we still have to mark the mouse click as "handled" here.
    Otherwise some control underneath us (like TCastleView with InterceptInput = true,
    like the one used by TStateDialogOK) could handle
    mouse and capture it (the TCastleContainer automatically "captures" the control
    that returns "true" from Press event), and then we would not receive
    TCastleScrollViewCustom.Motion events anymore.

    (Testcase: show MessageOK or TStateDialogOK on mobile (Android, iOS)
    with a long text (to make scrolling relevant).)  }

  if EnableDragging and Event.IsMouseButton(buttonLeft) and ScrollBarVisible then
    Result := ExclusiveEvents;
end;

function TCastleScrollViewCustom.Release(const Event: TInputPressRelease): boolean;
begin
  Result := inherited;
  if Result then Exit;

  if Event.IsMouseButton(buttonLeft) then
  begin
    ScrollBarDragging := false;
    Result := ExclusiveEvents;
  end;
end;

function TCastleScrollViewCustom.Motion(const Event: TInputMotion): boolean;
var
  Drag: Single;
begin
  Result := inherited;
  if Result then Exit;

  if ScrollBarDragging then
  begin
    { In scaled pixels, dragging by ScrollbarFrame.Height equals changing
      Scroll by GetCompleteSize. }
    Scroll := Scroll + GetCompleteSize *
      (Event.OldPosition[1] - Event.Position[1]) / ScrollbarFrame.Height;
    ResetInertialForce;
    Result := ExclusiveEvents;
  end else
  if EnableDragging and (buttonLeft in Event.Pressed) then
  begin
    Drag := ((Event.Position[1] - Event.OldPosition[1]) / UIScale);
    Scroll := Scroll + Drag;
    DragSinceLastUpdate := DragSinceLastUpdate + Drag;
    Result := ExclusiveEvents;
  end;
end;

function TCastleScrollViewCustom.ScrollMin: Single;
begin
  Result := 0;
end;

function TCastleScrollViewCustom.ScrollMax: Single;
begin
  Result := Max(0, GetCompleteSize - GetPageSize);
end;

function TCastleScrollViewCustom.EffectiveScrollBarWidth: Single;
begin
  if ScrollBarWidth = 0 then
    Result := Theme.ScrollBarWidth
  else
    Result := ScrollBarWidth;
end;

{$define read_implementation_methods}
{$I auto_generated_persistent_vectors/tcastlescrollviewcustom_persistent_vectors.inc}
{$undef read_implementation_methods}

{ TCastleScrollView ---------------------------------------------------------- }

constructor TCastleScrollView.Create(AOwner: TComponent);
begin
  inherited;

  FScrollArea := TInternalCastleScrollArea.Create(Self);
  FScrollArea.SetSubComponent(true);
  FScrollArea.Name := 'ScrollArea';
  FScrollArea.Anchor(vpTop);
  InsertFront(FScrollArea);

  ClipChildren := true;
end;

function TCastleScrollView.GetPageSize: Single;
begin
  Result := EffectiveHeightForChildren;
end;

function TCastleScrollView.GetCompleteSize: Single;
begin
  Result := ScrollArea.EffectiveHeight;
end;

procedure TCastleScrollView.DoScrollChange;
begin
  inherited;
  FScrollArea.Anchor(vpTop, Scroll);
end;

{ TCastleScrollViewManual ---------------------------------------------------- }

constructor TCastleScrollViewManual.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FPageSize := DefaultPageSize;
  FCompleteSize := DefaultCompleteSize;
end;

function TCastleScrollViewManual.GetPageSize: Single;
begin
  Result := FPageSize;
end;

procedure TCastleScrollViewManual.SetPageSize(const AValue: Single);
begin
  if FPageSize = AValue then Exit;
  FPageSize := AValue;
  VisibleChange([chRender]);

  // since ScrollMax changed, make sure Scroll is within bounds
  Scroll := Scroll;
end;

function TCastleScrollViewManual.GetCompleteSize: Single;
begin
  Result := FCompleteSize;
end;

procedure TCastleScrollViewManual.DoScrollChange;
begin
  inherited;
  if Assigned(OnChange) then
    OnChange(Self);
end;

procedure TCastleScrollViewManual.SetCompleteSize(const AValue: Single);
begin
  if FCompleteSize = AValue then Exit;
  FCompleteSize := AValue;
  VisibleChange([chRender]);

  // since ScrollMax changed, make sure Scroll is within bounds
  Scroll := Scroll;
end;

{$endif read_implementation}
