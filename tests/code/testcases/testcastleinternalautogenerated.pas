// -*- compile-command: "./test_single_testcase.sh TTestCastleInternalAutoGenerated" -*-
{
  Copyright 2021-2022 Michalis Kamburelis.

  This file is part of "Castle Game Engine".

  "Castle Game Engine" is free software; see the file COPYING.txt,
  included in this distribution, for details about the copyright.

  "Castle Game Engine" is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  ----------------------------------------------------------------------------
}

{ Test CastleInternalAutoGenerated. }
unit TestCastleInternalAutoGenerated;

interface

uses {$ifndef CASTLE_TESTER}FpcUnit, TestUtils, TestRegistry, CastleTestCase
  {$else}CastleTester{$endif};

type
  TTestCastleInternalAutoGenerated = class(TCastleTestCase)
  published
    procedure TestStrToPlatforms;
  end;

implementation

uses CastleUtils, CastleInternalAutoGenerated;

procedure TTestCastleInternalAutoGenerated.TestStrToPlatforms;
begin
  Assert(StrToPlatforms('') = []);
  Assert(StrToPlatforms('all') = AllPlatforms);
  Assert(StrToPlatforms('Desktop') = [cpDesktop]);
  Assert(StrToPlatforms('Android;iOS;Nintendo Switch') = [cpAndroid, cpIOS, cpNintendoSwitch]);
  Assert(StrToPlatforms('ANDROID;IOS;NINTENDO SWITCH') = [cpAndroid, cpIOS, cpNintendoSwitch]); // case ignored
end;

initialization
  RegisterTest(TTestCastleInternalAutoGenerated);
end.
