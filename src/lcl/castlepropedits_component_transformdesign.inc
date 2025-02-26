{%MainUnit castlepropedits.pas}
{
  Copyright 2022-2022 Michalis Kamburelis.

  This file is part of "Castle Game Engine".

  "Castle Game Engine" is free software; see the file COPYING.txt,
  included in this distribution, for details about the copyright.

  "Castle Game Engine" is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  ----------------------------------------------------------------------------
}

type
  { Editor for TCastleTransformDesign. }
  TCastleTransformDesignComponentEditor = class(TCastleTransformComponentEditor)
  public
    function GetVerbCount: Integer; override;
    function GetVerb(Index: Integer): string; override;
    procedure ExecuteVerb(Index: Integer); override;
  end;

function TCastleTransformDesignComponentEditor.GetVerbCount: Integer;
begin
  Result := (inherited GetVerbCount) + 3;
end;

function TCastleTransformDesignComponentEditor.GetVerb(Index: Integer): string;
var
  InheritedCount: Integer;
begin
  InheritedCount := inherited GetVerbCount;
  case Index - InheritedCount of
    0: Result := 'Edit (Copy Here) Referenced Design';
    1: Result := 'Revert To Referenced Design';
    2: Result := 'Open Referenced Design';
    else Result := inherited GetVerb(Index);
  end;
end;

procedure TCastleTransformDesignComponentEditor.ExecuteVerb(Index: Integer);

  procedure Edit(const E: TCastleComponentEditorDesigner; const C: TCastleTransformDesign);
  var
    NewChild: TCastleTransform;
  begin
    if C.URL <> '' then
    begin
      { We don't just remove csTransient from C.FDesign.
        We need to reload it, to set new Owner for it (same as our owner,
        DesignOwner in editor) and make names inside unique in new Owner. }
      NewChild := TransformLoad(C.URL, C.Owner);
      C.Add(NewChild);

      InternalCastleDesignInvalidate := true;

      C.RevertURL := C.URL;
      C.URL := '';
      E.Modified;
    end;
  end;

  procedure Revert(const E: TCastleComponentEditorDesigner; const C: TCastleTransformDesign);
  var
    I: Integer;
  begin
    if C.RevertURL <> '' then
    begin
      for I := C.Count - 1 downto 0 do
        { Note: we don't free csTransient, e.g. do not free editor gizmos.
          This is now checked by FreeComponentRecursively, no need for explicit
          check here, just be aware that some FreeComponentRecursively calls
          will be ignored.

          Note: It is critical to call E.FreeComponentRecursively,
          not just C.Items[I].Free.
          Because otherwise the components inside will be "left hanging":
          they will keep taking names in DesignOwner,
          they will keep being referenced (e.g. if design contained TCastleCamera,
          it can be referenced by some TCastleViewport.Camera outside of this design),
          and they are not part of hierarchy (so they would not be serialized to JSON). }
        E.FreeComponentRecursively(C.Items[I]);

      InternalCastleDesignInvalidate := true;

      C.URL := C.RevertURL;
      E.Modified;
    end;
  end;

  procedure Open(const E: TCastleComponentEditorDesigner; const C: TCastleTransformDesign);
  begin
    if C.URL <> '' then
      E.ProposeOpenDesign(C.URL);
  end;

var
  InheritedCount: Integer;
begin
  InheritedCount := inherited GetVerbCount;
  case Index - InheritedCount of
    0:begin
        if GetDesigner is TCastleComponentEditorDesigner then
          Edit(GetDesigner as TCastleComponentEditorDesigner, Component as TCastleTransformDesign);
      end;
    1:begin
        if GetDesigner is TCastleComponentEditorDesigner then
          Revert(GetDesigner as TCastleComponentEditorDesigner, Component as TCastleTransformDesign);
      end;
    2:begin
        if GetDesigner is TCastleComponentEditorDesigner then
          Open(GetDesigner as TCastleComponentEditorDesigner, Component as TCastleTransformDesign);
      end;
    else inherited ExecuteVerb(Index);
  end;
end;
